#include "storage/table_iterator.h"

#include "common/macros.h"
#include "storage/table_heap.h"

/**
 * TODO: Student Implement
 */
TableIterator::TableIterator(TableHeap *table_heap, RowId rid, Txn *txn) : tableheap(table_heap), rid_(rid), txn(txn) {}

TableIterator::TableIterator(const TableIterator &other)
    : tableheap(other.tableheap), rid_(other.rid_), txn(other.txn) {}

TableIterator::~TableIterator() {}

bool TableIterator::operator==(const TableIterator &itr) const {
  if (rid_.GetPageId() != itr.rid_.GetPageId() || rid_.GetSlotNum() != itr.rid_.GetSlotNum()) return false;
  return true;
}

bool TableIterator::operator!=(const TableIterator &itr) const {
  if (rid_.GetPageId() != itr.rid_.GetPageId() || rid_.GetSlotNum() != itr.rid_.GetSlotNum()) return true;
  return false;
}

const Row &TableIterator::operator*() {
  Row *row = new Row(rid_);
  tableheap->GetTuple(row, txn);
  return *row;
}

Row *TableIterator::operator->() {
  Row *row = new Row(rid_);
  tableheap->GetTuple(row, txn);
  return row;
}

TableIterator &TableIterator::operator=(const TableIterator &itr) noexcept {
  if (this != &itr) {
    this->rid_ = itr.rid_;
    this->tableheap = itr.tableheap;
    this->txn = itr.txn;
  }
  return *this;
}

// ++iter
TableIterator &TableIterator::operator++() {
  auto page = reinterpret_cast<TablePage *>(tableheap->buffer_pool_manager_->FetchPage(rid_.GetPageId()));
  ASSERT(page != NULL, "page is invalid");
  bool status = page->GetNextTupleRid(rid_, &rid_);
  tableheap->buffer_pool_manager_->UnpinPage(page->GetPageId(), false);
  if (!status) {  // at the end of this page
    page_id_t next_page_id_ = page->GetNextPageId();
    if (next_page_id_ == INVALID_PAGE_ID) rid_ = INVALID_ROWID;
    auto next_page = reinterpret_cast<TablePage *>(tableheap->buffer_pool_manager_->FetchPage(next_page_id_));
    ASSERT(next_page_id_ != INVALID_PAGE_ID, "Fail to fetch next page!");
    next_page->GetFirstTupleRid(&rid_);
  }
  return *this;
}

// iter++
TableIterator TableIterator::operator++(int) {
  TableIterator tmp(this->tableheap, this->rid_, this->txn);
  ++(*this);
  return TableIterator(tmp.tableheap, tmp.rid_, tmp.txn);
  // return *this;
}
