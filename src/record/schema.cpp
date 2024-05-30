#include "record/schema.h"

/**
 * TODO: Student Implement
 */
uint32_t Schema::SerializeTo(char *buf) const {
  // replace with your code here
  char *buf_tmp = buf;
  uint32_t total_size = 0;
  // magic num
  MACH_WRITE_UINT32(buf_tmp, this->SCHEMA_MAGIC_NUM);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // column nums
  uint32_t column_num = this->GetColumnCount();
  MACH_WRITE_UINT32(buf_tmp, column_num);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // each column
  for (auto it : this->columns_) {
    Column *column = it;
    uint32_t length = column->SerializeTo(buf_tmp);
    buf_tmp += length;
    total_size += length;
  }
  return total_size;
}

uint32_t Schema::GetSerializedSize() const {
  // replace with your code here
  uint32_t total_size = 2 * sizeof(uint32_t);
  for (auto it : this->columns_) {
    Column *column = it;
    uint32_t length = column->GetSerializedSize();
    total_size += length;
  }
  return total_size;
}

uint32_t Schema::DeserializeFrom(char *buf, Schema *&schema) {
  // replace with your code here
  if (schema != NULL) return 0;
  char *buf_tmp = buf;
  uint32_t total_size = 0;
  // magic num
  uint32_t magic_num = MACH_READ_UINT32(buf_tmp);
  if (magic_num == 0) return 0;
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // column nums
  uint32_t column_num = MACH_READ_UINT32(buf_tmp);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // each column
  std::vector<Column *> columns;
  uint32_t column_id;
  for (column_id = 0; column_id < column_num; ++column_id) {
    Column *column_tmp;
    uint32_t length = column_tmp->DeserializeFrom(buf_tmp, column_tmp);
    buf_tmp += length;
    total_size += length;
  }
  schema = new Schema(columns, true);
  return total_size;
}