#include "record/row.h"

void Row::Write_To_Bitmap(uint32_t &bitmap, uint32_t id) const {
  bitmap |= (1 << id);
  return;
}

bool Row::Read_From_Bitmap(uint32_t bitmap, uint32_t id) const {
  if ((bitmap >> id) & 1) return true;
  return false;
}

/**
 * TODO: Student Implement
 */
uint32_t Row::SerializeTo(char *buf, Schema *schema) const {
  // ASSERT(schema != nullptr, "Invalid schema before serialize.");
  // ASSERT(schema->GetColumnCount() == fields_.size(), "Fields size do not match schema's column size.");
  // replace with your code here
  uint32_t bitmap = 0;
  uint32_t field_id = 0;
  for (auto it : this->fields_) {
    Field *field = it;
    if (field->IsNull() == false) Write_To_Bitmap(bitmap, field_id);
    ++field_id;
  }
  char *buf_tmp = buf;
  uint32_t total_size = 0;
  std::cout << total_size << std::endl;
  // field nums
  uint32_t field_num = this->fields_.size();
  MACH_WRITE_UINT32(buf_tmp, field_num);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // bitmap
  MACH_WRITE_UINT32(buf_tmp, bitmap);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // each row
  for (auto it : this->fields_) {
    Field *field = it;
    uint32_t length = field->SerializeTo(buf_tmp);
    buf_tmp += length;
    total_size += length;
  }
  return total_size;
}

uint32_t Row::DeserializeFrom(char *buf, Schema *schema) {
  // ASSERT(schema != nullptr, "Invalid schema before serialize.");
  // ASSERT(fields_.empty(), "Non empty field in row.");
  // replace with your code here
  char *buf_tmp = buf;
  uint32_t total_size = 0;
  // field nums
  uint32_t field_num = MACH_READ_UINT32(buf_tmp);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // bitmap
  uint32_t bitmap = MACH_READ_UINT32(buf_tmp);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // each row
  std::vector<Field *> fields;
  uint32_t filed_id;
  for (filed_id = 0; filed_id < field_num; ++filed_id) {
    bool is_null = !Read_From_Bitmap(bitmap, filed_id);
    Field *field_tmp;
    Column *column = schema->GetColumns()[filed_id];
    uint32_t length = field_tmp->DeserializeFrom(buf_tmp, column->GetType(), &field_tmp, is_null);
    fields.push_back(field_tmp);
    buf_tmp += length;
    total_size += length;
  }
  this->fields_ = fields;
  return total_size;
}

uint32_t Row::GetSerializedSize(Schema *schema) const {
  // ASSERT(schema != nullptr, "Invalid schema before serialize.");
  // ASSERT(schema->GetColumnCount() == fields_.size(), "Fields size do not match schema's column size.");
  // replace with your code here
  uint32_t total_size = 2 * sizeof(uint32_t);
  for (auto it : this->fields_) {
    Field *field = it;
    uint32_t length = field->GetSerializedSize();
    total_size += length;
  }
  return total_size;
}

void Row::GetKeyFromRow(const Schema *schema, const Schema *key_schema, Row &key_row) {
  auto columns = key_schema->GetColumns();
  std::vector<Field> fields;
  uint32_t idx;
  for (auto column : columns) {
    schema->GetColumnIndex(column->GetName(), idx);
    fields.emplace_back(*this->GetField(idx));
  }
  key_row = Row(fields);
}
