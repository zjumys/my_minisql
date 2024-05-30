#include "record/column.h"

#include "glog/logging.h"

Column::Column(std::string column_name, TypeId type, uint32_t index, bool nullable, bool unique)
    : name_(std::move(column_name)), type_(type), table_ind_(index), nullable_(nullable), unique_(unique) {
  ASSERT(type != TypeId::kTypeChar, "Wrong constructor for CHAR type.");
  switch (type) {
    case TypeId::kTypeInt:
      len_ = sizeof(int32_t);
      break;
    case TypeId::kTypeFloat:
      len_ = sizeof(float_t);
      break;
    default:
      ASSERT(false, "Unsupported column type.");
  }
}

Column::Column(std::string column_name, TypeId type, uint32_t length, uint32_t index, bool nullable, bool unique)
    : name_(std::move(column_name)),
      type_(type),
      len_(length),
      table_ind_(index),
      nullable_(nullable),
      unique_(unique) {
  ASSERT(type == TypeId::kTypeChar, "Wrong constructor for non-VARCHAR type.");
}

Column::Column(const Column *other)
    : name_(other->name_),
      type_(other->type_),
      len_(other->len_),
      table_ind_(other->table_ind_),
      nullable_(other->nullable_),
      unique_(other->unique_) {}

/**
 * TODO: Student Implement
 */
uint32_t Column::SerializeTo(char *buf) const {
  // replace with your code here
  char *buf_tmp = buf;
  uint32_t total_size = 0;
  // magic num
  MACH_WRITE_UINT32(buf_tmp, this->COLUMN_MAGIC_NUM);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // name_length
  uint32_t name_length = this->name_.length();
  MACH_WRITE_UINT32(buf_tmp, name_length);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // name
  MACH_WRITE_STRING(buf_tmp, this->name_);
  buf_tmp += name_length;
  total_size += name_length;
  // type_
  MACH_WRITE_TO(TypeId, buf_tmp, this->type_);
  buf_tmp += sizeof(TypeId);
  total_size += sizeof(TypeId);
  // len_
  MACH_WRITE_UINT32(buf_tmp, this->len_);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // table_ind_
  MACH_WRITE_UINT32(buf_tmp, this->table_ind_);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // nullable_
  MACH_WRITE_TO(bool, buf_tmp, this->nullable_);
  buf_tmp += sizeof(bool);
  total_size += sizeof(bool);
  // unique_
  MACH_WRITE_TO(bool, buf_tmp, this->unique_);
  buf_tmp += sizeof(bool);
  total_size += sizeof(bool);
  return total_size;
}

/**
 * TODO: Student Implement
 */
uint32_t Column::GetSerializedSize() const {
  // replace with your code here
  uint32_t total_size;
  total_size = 4 * sizeof(uint32_t) + this->name_.length() + sizeof(TypeId) + 2 * sizeof(bool);
  return total_size;
}

/**
 * TODO: Student Implement
 */
uint32_t Column::DeserializeFrom(char *buf, Column *&column) {
  // replace with your code here
  char *buf_tmp = buf;
  uint32_t total_size = 0;
  // magic num
  uint32_t magic_num = MACH_READ_UINT32(buf_tmp);
  if (magic_num == 0) return 0;
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // name_length
  uint32_t name_length = MACH_READ_UINT32(buf_tmp);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // name
  char tmp_name[100];
  memset(tmp_name, 0, sizeof(tmp_name));
  memcpy(tmp_name, buf_tmp, name_length);
  std::string name(tmp_name);
  buf_tmp += name_length;
  total_size += name_length;
  // type_
  TypeId type = MACH_READ_FROM(TypeId, buf_tmp);
  buf_tmp += sizeof(TypeId);
  total_size += sizeof(TypeId);
  // len_
  uint32_t len = MACH_READ_UINT32(buf_tmp);
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // table_ind_
  uint32_t table_ind = MACH_READ_UINT32(buf_tmp);  // 表里面列的标号
  buf_tmp += sizeof(uint32_t);
  total_size += sizeof(uint32_t);
  // nullable_
  bool nullable = MACH_READ_FROM(bool, buf_tmp);  // 是否允许为空
  buf_tmp += sizeof(bool);
  total_size += sizeof(bool);
  // unique_
  bool unique = MACH_READ_FROM(bool, buf_tmp);  // 是否唯一
  total_size += sizeof(bool);
  if (type == TypeId::kTypeChar)
    column = new Column(name, type, name_length, table_ind, nullable, unique);
  else
    column = new Column(name, type, table_ind, nullable, unique);
  return total_size;
}
