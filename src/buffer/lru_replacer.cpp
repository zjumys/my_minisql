#include "buffer/lru_replacer.h"

LRUReplacer::LRUReplacer(size_t num_pages) { max_size = num_pages; }

LRUReplacer::~LRUReplacer() = default;

/**
 * TODO: Student Implement
 */
bool LRUReplacer::Victim(frame_id_t *frame_id) {
  if (lru_list_.size() == 0) {
    frame_id = NULL;
    return false;
  }
  frame_id_t del = lru_list_.back();
  lru_list_.pop_back();
  *frame_id = del;
  return true;
}

/**
 * TODO: Student Implement
 */
void LRUReplacer::Pin(frame_id_t frame_id) {
  std::list<frame_id_t>::iterator it;
  for (it = lru_list_.begin(); it != lru_list_.end(); ++it)
    if (*it == frame_id) break;
  if (it == lru_list_.end()) return;
  lru_list_.erase(it);
}

/**
 * TODO: Student Implement
 */
void LRUReplacer::Unpin(frame_id_t frame_id) {
  std::list<frame_id_t>::iterator it;
  for (it = lru_list_.begin(); it != lru_list_.end(); ++it)
    if (*it == frame_id) return;
  while (lru_list_.size() >= max_size) lru_list_.pop_back();
  lru_list_.push_front(frame_id);
}

/**
 * TODO: Student Implement
 */
size_t LRUReplacer::Size() { return lru_list_.size(); }