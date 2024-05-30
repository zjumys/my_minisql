#include "page/bitmap_page.h"

#include "glog/logging.h"

/**
 * TODO: Student Implement
 */
template <size_t PageSize>
bool BitmapPage<PageSize>::AllocatePage(uint32_t &page_offset) {
  size_t MaxSize = GetMaxSupportedSize();
  if (page_allocated_ == MaxSize) return false;
  if (page_offset == MaxSize || !IsPageFree(page_offset)) {
    uint32_t page_id;
    for (page_id = 0; page_id < MaxSize; ++page_id) {
      if (IsPageFree(page_id)) {
        uint32_t byte_index = page_id / 8;
        uint32_t bit_index = page_id % 8;
        bytes[byte_index] |= (1 << bit_index);
        ++page_allocated_;
        page_offset = page_id;
        return true;
      }
    }
    return false;
  }
  uint32_t byte_index = page_offset / 8;
  uint32_t bit_index = page_offset % 8;
  bytes[byte_index] |= (1 << bit_index);
  ++page_allocated_;
  return true;
}

/**
 * TODO: Student Implement
 */
template <size_t PageSize>
bool BitmapPage<PageSize>::DeAllocatePage(uint32_t page_offset) {
  uint32_t byte_index = page_offset / 8;
  uint32_t bit_index = page_offset % 8;
  uint32_t status;
  if (IsPageFree(page_offset) == true)
    status = 0;
  else
    status = 1;
  if (status == 0) return false;
  bytes[byte_index] ^= (1 << bit_index);
  --page_allocated_;
  return true;
}

/**
 * TODO: Student Implement
 */
template <size_t PageSize>
bool BitmapPage<PageSize>::IsPageFree(uint32_t page_offset) const {
  uint32_t byte_index = page_offset / 8;
  uint32_t bit_index = page_offset % 8;
  return IsPageFreeLow(byte_index, bit_index);
}

template <size_t PageSize>
bool BitmapPage<PageSize>::IsPageFreeLow(uint32_t byte_index, uint8_t bit_index) const {
  char now_byte = bytes[byte_index];
  now_byte = now_byte >> bit_index;
  if (now_byte & 1) return false;
  return true;
}

template class BitmapPage<64>;

template class BitmapPage<128>;

template class BitmapPage<256>;

template class BitmapPage<512>;

template class BitmapPage<1024>;

template class BitmapPage<2048>;

template class BitmapPage<4096>;