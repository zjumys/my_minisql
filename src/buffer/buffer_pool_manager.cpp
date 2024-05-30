
#include "buffer/buffer_pool_manager.h"

#include "glog/logging.h"
#include "page/bitmap_page.h"

static const char EMPTY_PAGE_DATA[PAGE_SIZE] = {0};

BufferPoolManager::BufferPoolManager(size_t pool_size, DiskManager *disk_manager)
    : pool_size_(pool_size), disk_manager_(disk_manager) {
  pages_ = new Page[pool_size_];
  replacer_ = new LRUReplacer(pool_size_);
  for (size_t i = 0; i < pool_size_; i++) {
    free_list_.emplace_back(i);
  }
}

BufferPoolManager::~BufferPoolManager() {
  for (auto page : page_table_) {
    FlushPage(page.first);
  }
  delete[] pages_;
  delete replacer_;
}

/**
 * TODO: Student Implement
 */
Page *BufferPoolManager::FetchPage(page_id_t page_id) {
  // 1.     Search the page table for the requested page (P).
  frame_id_t frame_id;
  // 1.1    If P exists, pin it and return it immediately.
  if (page_table_.count(page_id) != 0) {
    frame_id = page_table_[page_id];
    replacer_->Pin(frame_id);
    Page *P = pages_ + frame_id;
    ++(P->pin_count_);
    return P;
  }
  // 1.2    If P does not exist, find a replacement page (R) from either the free list or the replacer.
  //        Note that pages are always found from the free list first.
  else {
    if (free_list_.size() != 0) {
      frame_id = free_list_.front();
      free_list_.pop_front();
    } else {
      bool status = replacer_->Victim(&frame_id);
      if (!status) return NULL;
    }
    Page *R = pages_ + frame_id;
    // 2.     If R is dirty, write it back to the disk.
    if (R->is_dirty_) disk_manager_->WritePage(R->page_id_, R->data_);
    // 3.     Delete R from the page table and insert P.
    page_table_.erase(R->page_id_);
    R->page_id_ = page_id;
    page_table_[R->page_id_] = frame_id;
    // 4.     Update P's metadata, read in the page content from disk, and then return a pointer to P.
    disk_manager_->ReadPage(R->page_id_, R->data_);
    R->is_dirty_ = 0;
    ++R->pin_count_;
    replacer_->Pin(frame_id);
    return R;
  }
}

/**
 * TODO: Student Implement
 */
Page *BufferPoolManager::NewPage(page_id_t &page_id) {
  // 0.   Make sure you call AllocatePage!
  // 1.   If all the pages in the buffer pool are pinned, return nullptr.
  bool flag = false;
  for (size_t i = 0; i < pool_size_; ++i)
    if (pages_[i].pin_count_ == 0) {
      flag = true;
      break;
    }
  if (!flag) return NULL;
  page_id_t new_page_id = AllocatePage();
  // 2.   Pick a victim page P from either the free list or the replacer. Always pick from the free list first.
  frame_id_t frame_id_P;
  if (free_list_.size() != 0) {
    frame_id_P = free_list_.front();
    free_list_.pop_front();
  } else {
    bool status = replacer_->Victim(&frame_id_P);
    if (!status) return NULL;
  }
  Page *P = pages_ + frame_id_P;
  // 3.   Update P's metadata, zero out memory and add P to the page table.
  if (P->is_dirty_) disk_manager_->WritePage(P->page_id_, P->data_);
  page_table_.erase(P->page_id_);
  P->ResetMemory();
  P->page_id_ = new_page_id;
  P->is_dirty_ = 0;
  P->pin_count_ = 1;
  page_table_[P->page_id_] = frame_id_P;
  // 4.   Set the page ID output parameter. Return a pointer to P.
  page_id = new_page_id;
  return P;
}

/**
 * TODO: Student Implement
 */
bool BufferPoolManager::DeletePage(page_id_t page_id) {
  // 0.   Make sure you call DeallocatePage!
  disk_manager_->DeAllocatePage(page_id);
  // 1.   Search the page table for the requested page (P).
  frame_id_t frame_id;
  // 1.   If P does not exist, return true.
  if (page_table_.count(page_id) == 0) return true;
  // 2.   If P exists, but has a non-zero pin-count, return false. Someone is using the page.
  frame_id = page_table_[page_id];
  Page *P = pages_ + frame_id;
  if (P->pin_count_ != 0) return false;
  // 3.   Otherwise, P can be deleted. Remove P from the page table, reset its metadata and return it to the free list.
  page_table_.erase(page_id);
  P->ResetMemory();
  P->is_dirty_ = 0;
  P->page_id_ = INVALID_PAGE_ID;
  P->pin_count_ = 0;
  free_list_.push_back(frame_id);
  return true;
}

/**
 * TODO: Student Implement
 */
bool BufferPoolManager::UnpinPage(page_id_t page_id, bool is_dirty) {
  frame_id_t frame_id;
  if (page_table_.count(page_id) == 0) return true;
  frame_id = page_table_[page_id];
  Page *P = pages_ + frame_id;
  if (is_dirty) P->is_dirty_ = true;
  if (P->pin_count_ == 0) return false;
  --P->pin_count_;
  if (P->pin_count_ == 0) replacer_->Unpin(frame_id);
  return true;
}

/**
 * TODO: Student Implement
 */
bool BufferPoolManager::FlushPage(page_id_t page_id) {
  frame_id_t frame_id;
  if (page_table_.count(page_id) == 0) return false;
  frame_id = page_table_[page_id];
  Page *P = pages_ + frame_id;
  if (!P->is_dirty_) return true;
  P->is_dirty_ = 0;
  disk_manager_->WritePage(P->page_id_, P->data_);
  return true;
}

page_id_t BufferPoolManager::AllocatePage() {
  int next_page_id = disk_manager_->AllocatePage();
  return next_page_id;
}

void BufferPoolManager::DeallocatePage(__attribute__((unused)) page_id_t page_id) {
  disk_manager_->DeAllocatePage(page_id);
}

bool BufferPoolManager::IsPageFree(page_id_t page_id) { return disk_manager_->IsPageFree(page_id); }

// Only used for debug
bool BufferPoolManager::CheckAllUnpinned() {
  bool res = true;
  for (size_t i = 0; i < pool_size_; i++) {
    if (pages_[i].pin_count_ != 0) {
      res = false;
      LOG(ERROR) << "page " << pages_[i].page_id_ << " pin count:" << pages_[i].pin_count_ << endl;
    }
  }
  return res;
}
