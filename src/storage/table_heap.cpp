#include "storage/table_heap.h"

/**
 * TODO: Student Implement
 */
bool TableHeap::InsertTuple(Row &row, Txn *txn) {
  // std::cout << "InsertTuple Entered" << std::endl;
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(first_page_id_));
  while (page != NULL) {
    if (page->InsertTuple(row, schema_, txn, lock_manager_, log_manager_)) {
      buffer_pool_manager_->UnpinPage(page->GetPageId(), true);
      // std::cout << "InsertTuple succedded" << std::endl;
      return true;
    }
    page_id_t next_page_id = page->GetNextPageId();
    if (next_page_id == INVALID_PAGE_ID) {  // create new page
      auto new_page = reinterpret_cast<TablePage *>(buffer_pool_manager_->NewPage(next_page_id));
      if (new_page == NULL) {
        buffer_pool_manager_->UnpinPage(page->GetPageId(), false);
        return false;
      }
      new_page->Init(next_page_id, page->GetTablePageId(), log_manager_, txn);
      page->SetNextPageId(next_page_id);
      buffer_pool_manager_->UnpinPage(page->GetPageId(), true);
      page = new_page;
    } else {
      buffer_pool_manager_->UnpinPage(page->GetPageId(), false);
      page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(next_page_id));
    }
  }
  // std::cout << "InsertTuple succedded" << std::endl;
  return false;
}

bool TableHeap::MarkDelete(const RowId &rid, Txn *txn) {
  // Find the page which contains the tuple.
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(rid.GetPageId()));
  // If the page could not be found, then abort the recovery.
  if (page == nullptr) {
    return false;
  }
  // Otherwise, mark the tuple as deleted.
  page->WLatch();
  page->MarkDelete(rid, txn, lock_manager_, log_manager_);
  page->WUnlatch();
  buffer_pool_manager_->UnpinPage(page->GetTablePageId(), true);
  return true;
}

/**
 * TODO: Student Implement
 */
bool TableHeap::UpdateTuple(Row &row, const RowId &rid, Txn *txn) {
  std::cout << "UpdateTuple Entered" << std::endl;
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(rid.GetPageId()));
  ASSERT(page != NULL, "The rid doesn't exist!");
  Row old_row(rid);
  page->GetTuple(&old_row, schema_, txn, lock_manager_);
  int status = page->UpdateTuple(row, &old_row, schema_, txn, lock_manager_, log_manager_);
  buffer_pool_manager_->UnpinPage(page->GetPageId(), status > 0);
  std::cout << "UpdateTuple succedded" << std::endl;
  return status > 0;
}

/**
 * TODO: Student Implement
 */
void TableHeap::ApplyDelete(const RowId &rid, Txn *txn) {
  // Step1: Find the page which contains the tuple.
  // Step2: Delete the tuple from the page.
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(rid.GetPageId()));
  ASSERT(page != NULL, "The rid doesn't exist!");
  page->ApplyDelete(rid, txn, log_manager_);
  buffer_pool_manager_->UnpinPage(page->GetTablePageId(), true);
}

void TableHeap::RollbackDelete(const RowId &rid, Txn *txn) {
  // Find the page which contains the tuple.
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(rid.GetPageId()));
  assert(page != nullptr);
  // Rollback to delete.
  page->WLatch();
  page->RollbackDelete(rid, txn, log_manager_);
  page->WUnlatch();
  buffer_pool_manager_->UnpinPage(page->GetTablePageId(), true);
}

/**
 * TODO: Student Implement
 */
bool TableHeap::GetTuple(Row *row, Txn *txn) {
  // std::cout << "GetTuple Entered" << std::endl;
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(row->GetRowId().GetPageId()));
  ASSERT(page != NULL, "The row doesn't exist!");
  // std::cout << row->GetRowId().GetPageId() << std::endl;
  bool status = page->GetTuple(row, schema_, txn, lock_manager_);
  buffer_pool_manager_->UnpinPage(page->GetTablePageId(), false);
  return status;
}

void TableHeap::DeleteTable(page_id_t page_id) {
  if (page_id != INVALID_PAGE_ID) {
    auto temp_table_page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(page_id));  // 删除table_heap
    if (temp_table_page->GetNextPageId() != INVALID_PAGE_ID) DeleteTable(temp_table_page->GetNextPageId());
    buffer_pool_manager_->UnpinPage(page_id, false);
    buffer_pool_manager_->DeletePage(page_id);
  } else {
    DeleteTable(first_page_id_);
  }
}

/**
 * TODO: Student Implement
 */
TableIterator TableHeap::Begin(Txn *txn) {
  auto page = reinterpret_cast<TablePage *>(buffer_pool_manager_->FetchPage(this->first_page_id_));
  RowId first_rid_;
  bool status = page->GetFirstTupleRid(&first_rid_);
  if (status == false) first_rid_ = INVALID_ROWID;
  buffer_pool_manager_->UnpinPage(page->GetPageId(), false);
  return TableIterator(this, first_rid_, NULL);
}

/**
 * TODO: Student Implement
 */
TableIterator TableHeap::End() { return TableIterator(this, INVALID_ROWID, NULL); }
