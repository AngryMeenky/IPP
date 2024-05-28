#include "buffer.h"
#include "ipp/ippvm.h"

#include <cstdint>

#ifdef GDEXTENSION
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/core/class_db.hpp>
#else
#include "core/object/class_db.h"
#include "core/os/memory.h"
#include "core/os/os.h"
#endif


using namespace ipp;
using namespace godot;


static std::int64_t TYPE_TO_SIZE[] = {
  0,
  // integers
  sizeof(Ipp8u), sizeof(Ipp8s), sizeof(Ipp16u), sizeof(Ipp16s),
  sizeof(Ipp32u), sizeof(Ipp32s), sizeof(Ipp64u), sizeof(Ipp64s),
  // reals
  sizeof(Ipp32f), sizeof(Ipp64f),
  // complex integers
  sizeof(Ipp8sc), sizeof(Ipp16sc), sizeof(Ipp32sc), sizeof(Ipp64sc), sizeof(Ipp32sc),
  // complex reals
  sizeof(Ipp64fc), sizeof(Ipp32fc)
};


static Ipp8u *allocate_buffer(IPP::Type type, int count) {
  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
      return ippsMalloc_8u(count);
    break;
 
    case IPP::TYPE_16U:
    case IPP::TYPE_16S:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_16u(count));
    break;
 
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_32u(count));
    break;

    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_64s(count));
    break;

    case IPP::TYPE_32F:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_32f(count));
    break;

    case IPP::TYPE_64F:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_64f(count));
    break;

    case IPP::TYPE_8SC:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_8sc(count));
    break;

    case IPP::TYPE_16SC:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_16sc(count));
    break;

    case IPP::TYPE_32SC:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_32sc(count));
    break;

    case IPP::TYPE_64SC:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_64sc(count));
    break;

    case IPP::TYPE_32FC:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_32fc(count));
    break;

    case IPP::TYPE_64FC:
      return reinterpret_cast<Ipp8u *>(ippsMalloc_64fc(count));
    break;

    default:
      // do nothing
    break;
  }

  return nullptr;
}


IppBuffer::IppBuffer(int count, IPP::Type kind):
  ptr(allocate_buffer(kind, count)),
  type(kind),
  len(count) {
  if(!ptr) {
    type = IPP::TYPE_NONE;
    len = 0;
  }
}


IppBuffer::IppBuffer(const PackedByteArray &arr, IPP::Type kind):
  IppBuffer(arr.size(), kind) {
  copyFrom(arr, 0, arr.size(), 0);
}


IppBuffer::IppBuffer(const PackedInt32Array &arr, IPP::Type kind):
  IppBuffer(arr.size(), kind) {
  copyFrom(arr, 0, arr.size(), 0);
}


IppBuffer::IppBuffer(const PackedInt64Array &arr, IPP::Type kind):
  IppBuffer(arr.size(), kind) {
  copyFrom(arr, 0, arr.size(), 0);
}


IppBuffer::IppBuffer(const PackedFloat32Array &arr, IPP::Type kind):
  IppBuffer(arr.size(), kind) {
  copyFrom(arr, 0, arr.size(), 0);
}


IppBuffer::IppBuffer(const PackedFloat64Array &arr, IPP::Type kind):
  IppBuffer(arr.size(), kind) {
  copyFrom(arr, 0, arr.size(), 0);
}


IppBuffer::~IppBuffer() {
  if(ptr) {
    ippsFree(ptr);
    ptr = nullptr;
  }

  type = IPP::TYPE_NONE;
  len = 0;
}


int IppBuffer::load(const FileAccess *file) {
  if(ptr == nullptr || file == nullptr) {
    return -1; // bail on no buffer
  }

  return file->get_buffer(as8u(), len * TYPE_TO_SIZE[type]) / TYPE_TO_SIZE[type];
}


int IppBuffer::store(FileAccess *file) const {
  if(ptr == nullptr || file == nullptr) {
    return -1; // bail on no buffer
  }

  file->store_buffer(as8u(), len * TYPE_TO_SIZE[type]);
  return len;
}


int IppBuffer::read(const FileAccess *file, int offset, int count) {
  if(ptr == nullptr || file == nullptr) {
    return -1; // bail on no buffer
  }

  offset *= TYPE_TO_SIZE[type];
  count *= TYPE_TO_SIZE[type];
  return file->get_buffer(&as8u()[offset], count) / TYPE_TO_SIZE[type];
}


int IppBuffer::write(FileAccess *file, int offset, int count) const {
  if(ptr == nullptr || file == nullptr) {
    return -1; // bail on no buffer
  }

  offset *= TYPE_TO_SIZE[type];
  file->store_buffer(&as8u()[offset], count * TYPE_TO_SIZE[type]);
  return count;
}


void IppBuffer::fill(Variant &val) {
  if(!ptr) {
    return; // bail on no buffer
  }
 
  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
      ippsSet_8u(static_cast<Ipp8u>(val.operator int32_t()), ptr, len);
    break;
 
    case IPP::TYPE_16U:
    case IPP::TYPE_16S:
      ippsSet_16s(static_cast<Ipp16s>(val.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len);
    break;
 
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
      ippsSet_32s(static_cast<Ipp32s>(val), reinterpret_cast<Ipp32s *>(ptr), len);
    break;

    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
      ippsSet_64s(static_cast<std::uint64_t>(val), reinterpret_cast<Ipp64s *>(ptr), len);
    break;

    case IPP::TYPE_32F:
      ippsSet_32f(static_cast<Ipp32f>(val), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsSet_64f(static_cast<Ipp64f>(val), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_8SC:
      ippsSet_8u(static_cast<Ipp8u>(val.operator int32_t()), ptr, len * sizeof(Ipp8sc));
    break;

    case IPP::TYPE_16SC:
      if(val.get_type() == Variant::VECTOR2I) {
	auto v2 = static_cast<Vector2i>(val);
        Ipp16sc cVal;
	cVal.re = v2.x;
	cVal.im = v2.y;
        ippsSet_16sc(cVal, reinterpret_cast<Ipp16sc *>(ptr), len);
      }
      else {
        ippsSet_16s(static_cast<Ipp16s>(val.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len * 2);
      }
    break;

    case IPP::TYPE_32SC:
      if(val.get_type() == Variant::VECTOR2I) {
	auto v2 = static_cast<Vector2i>(val);
        Ipp32sc cVal;
	cVal.re = v2.x;
	cVal.im = v2.y;
        ippsSet_32sc(cVal, reinterpret_cast<Ipp32sc *>(ptr), len);
      }
      else {
        ippsSet_32s(static_cast<Ipp32s>(val), reinterpret_cast<Ipp32s *>(ptr), len * 2);
      }
    break;

    case IPP::TYPE_64SC:
      if(val.get_type() == Variant::VECTOR2I) {
	auto v2 = static_cast<Vector2i>(val);
        Ipp64sc cVal;
	cVal.re = v2.x;
	cVal.im = v2.y;
        ippsSet_64sc(cVal, reinterpret_cast<Ipp64sc *>(ptr), len);
      }
      else {
        ippsSet_64s(static_cast<std::uint64_t>(val), reinterpret_cast<Ipp64s *>(ptr), len * 2);
      }
    break;

    case IPP::TYPE_32FC:
      if(val.get_type() == Variant::VECTOR2) {
	auto v2 = static_cast<Vector2>(val);
        Ipp32fc cVal;
	cVal.re = v2.x;
	cVal.im = v2.y;
        ippsSet_32fc(cVal, reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        ippsSet_32f(static_cast<Ipp32f>(val), reinterpret_cast<Ipp32f *>(ptr), len * 2);
      }
    break;

    case IPP::TYPE_64FC:
      if(val.get_type() == Variant::VECTOR2) {
	auto v2 = static_cast<Vector2>(val);
        Ipp64fc cVal;
	cVal.re = v2.x;
	cVal.im = v2.y;
        ippsSet_64fc(cVal, reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        ippsSet_64f(static_cast<Ipp64f>(val), reinterpret_cast<Ipp64f *>(ptr), len * 2);
      }
    break;
  }
}


void IppBuffer::zero() {
  if(!ptr) {
    return; // bail on no buffer
  }
 
  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
      ippsZero_8u(ptr, len);
    break;
 
    case IPP::TYPE_16U:
    case IPP::TYPE_16S:
      ippsZero_16s(reinterpret_cast<Ipp16s *>(ptr), len);
    break;
 
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
      ippsZero_32s(reinterpret_cast<Ipp32s *>(ptr), len);
    break;

    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
      ippsZero_64s(reinterpret_cast<Ipp64s *>(ptr), len);
    break;

    case IPP::TYPE_32F:
      ippsZero_32f(reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsZero_64f(reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_8SC:
      ippsZero_8u(ptr, len * sizeof(Ipp8sc));
    break;

    case IPP::TYPE_16SC:
      ippsZero_16sc(reinterpret_cast<Ipp16sc *>(ptr), len);
    break;

    case IPP::TYPE_32SC:
      ippsZero_32sc(reinterpret_cast<Ipp32sc *>(ptr), len);
    break;

    case IPP::TYPE_64SC:
      ippsZero_64sc(reinterpret_cast<Ipp64sc *>(ptr), len);
    break;

    case IPP::TYPE_32FC:
      ippsZero_32fc(reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsZero_64fc(reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }
}


ipp::IPP::Type IppBuffer::getType() const {
  return type;
}


int IppBuffer::getLength() const {
  return len;
}


PackedByteArray IppBuffer::toPackedByteArray() const {
  PackedByteArray result;
  result.resize(len * TYPE_TO_SIZE[type]);

  copyTo(0, len, result, 0);

  return result;
}


PackedInt32Array IppBuffer::toPackedInt32Array() const {
  PackedInt32Array result;
  result.resize((len * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_32S] - 1) / TYPE_TO_SIZE[IPP::TYPE_32S]);

  copyTo(0, len, result, 0);

  return result;
}


PackedInt64Array IppBuffer::toPackedInt64Array() const {
  PackedInt64Array result;
  result.resize((len * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_64S] - 1) / TYPE_TO_SIZE[IPP::TYPE_64S]);

  copyTo(0, len, result, 0);

  return result;
}


PackedFloat32Array IppBuffer::toPackedFloat32Array() const {
  PackedFloat32Array result;
  result.resize((len * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_32F] - 1) / TYPE_TO_SIZE[IPP::TYPE_32F]);

  copyTo(0, len, result, 0);

  return result;
}


PackedFloat64Array IppBuffer::toPackedFloat64Array() const {
  PackedFloat64Array result;
  result.resize((len * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_64F] - 1) / TYPE_TO_SIZE[IPP::TYPE_64F]);

  copyTo(0, len, result, 0);

  return result;
}


bool IppBuffer::copyTo(int base, int count, PackedByteArray &arr, int offset) const {
  if(type == IPP::TYPE_NONE || base < 0 || count <= 0 || (base + count) > len) {
    return false; // validation of source parameters failed
  }

  auto size = TYPE_TO_SIZE[type] * count;
  if((size + offset) > arr.size()) {
    return false; // not enough space in the destination
  }

  memcpy(&arr.ptrw()[offset], &ptr[base * TYPE_TO_SIZE[type]], size);

  return true;
}


bool IppBuffer::copyTo(int base, int count, PackedInt32Array &arr, int offset) const {
  if(type == IPP::TYPE_NONE || base < 0 || count <= 0 || (base + count) > len) {
    return false; // validation of source parameters failed
  }

  auto items = (count * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_32S] - 1) / TYPE_TO_SIZE[IPP::TYPE_32S];
  if((items + offset) > arr.size()) {
    return false; // not enough space in the destination
  }

  memcpy(&arr.ptrw()[offset], &ptr[base * TYPE_TO_SIZE[type]], items * TYPE_TO_SIZE[IPP::TYPE_32S]);

  return true;
}


bool IppBuffer::copyTo(int base, int count, PackedInt64Array &arr, int offset) const {
  if(type == IPP::TYPE_NONE || base < 0 || count <= 0 || (base + count) > len) {
    return false; // validation of source parameters failed
  }

  auto items = (count * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_64S] - 1) / TYPE_TO_SIZE[IPP::TYPE_64S];
  if((items + offset) > arr.size()) {
    return false; // not enough space in the destination
  }

  memcpy(&arr.ptrw()[offset], &ptr[base * TYPE_TO_SIZE[type]], items * TYPE_TO_SIZE[IPP::TYPE_64S]);

  return true;
}


bool IppBuffer::copyTo(int base, int count, PackedFloat32Array &arr, int offset) const {
  if(type == IPP::TYPE_NONE || base < 0 || count <= 0 || (base + count) > len) {
    return false; // validation of source parameters failed
  }

  auto items = (count * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_32F] - 1) / TYPE_TO_SIZE[IPP::TYPE_32F];
  if((items + offset) > arr.size()) {
    return false; // not enough space in the destination
  }

  memcpy(&arr.ptrw()[offset], &ptr[base * TYPE_TO_SIZE[type]], items * TYPE_TO_SIZE[IPP::TYPE_32F]);

  return true;
}


bool IppBuffer::copyTo(int base, int count, PackedFloat64Array &arr, int offset) const {
  if(type == IPP::TYPE_NONE || base < 0 || count <= 0 || (base + count) > len) {
    return false; // validation of source parameters failed
  }

  auto items = (count * TYPE_TO_SIZE[type] + TYPE_TO_SIZE[IPP::TYPE_64F] - 1) / TYPE_TO_SIZE[IPP::TYPE_64F];
  if((items + offset) > arr.size()) {
    return false; // not enough space in the destination
  }

  memcpy(&arr.ptrw()[offset], &ptr[base * TYPE_TO_SIZE[type]], items * TYPE_TO_SIZE[IPP::TYPE_64F]);

  return true;
}


bool IppBuffer::copyFrom(const PackedByteArray &arr, int base, int count, int offset) {
  if(base < 0 || count <= 0 || (base + count) > arr.size()) {
    return false; // validation of source parameters failed
  }

  auto size = (count + TYPE_TO_SIZE[type] - 1) / TYPE_TO_SIZE[type];
  if(type == IPP::TYPE_NONE || (size + offset) > len) {
    return false; // not enough space in the destination
  }

  memcpy(&ptr[offset * TYPE_TO_SIZE[type]], &arr.ptr()[base], count);

  return true;
}


bool IppBuffer::copyFrom(const PackedInt32Array &arr, int base, int count, int offset) {
  if(base < 0 || count <= 0 || (base + count) > arr.size()) {
    return false; // validation of source parameters failed
  }

  auto size = (count * TYPE_TO_SIZE[IPP::TYPE_32S] + TYPE_TO_SIZE[type] - 1) / TYPE_TO_SIZE[type];
  if(type == IPP::TYPE_NONE || (size + offset) > len) {
    return false; // not enough space in the destination
  }

  memcpy(&ptr[offset * TYPE_TO_SIZE[type]], &arr.ptr()[base], count * TYPE_TO_SIZE[IPP::TYPE_32S]);

  return true;
}


bool IppBuffer::copyFrom(const PackedInt64Array &arr, int base, int count, int offset) {
  if(base < 0 || count <= 0 || (base + count) > arr.size()) {
    return false; // validation of source parameters failed
  }

  auto size = (count * TYPE_TO_SIZE[IPP::TYPE_64S] + TYPE_TO_SIZE[type] - 1) / TYPE_TO_SIZE[type];
  if(type == IPP::TYPE_NONE || (size + offset) > len) {
    return false; // not enough space in the destination
  }

  memcpy(&ptr[offset * TYPE_TO_SIZE[type]], &arr.ptr()[base], count * TYPE_TO_SIZE[IPP::TYPE_64S]);

  return true;
}


bool IppBuffer::copyFrom(const PackedFloat32Array &arr, int base, int count, int offset) {
  if(base < 0 || count <= 0 || (base + count) > arr.size()) {
    return false; // validation of source parameters failed
  }

  auto size = (count * TYPE_TO_SIZE[IPP::TYPE_32F] + TYPE_TO_SIZE[type] - 1) / TYPE_TO_SIZE[type];
  if(type == IPP::TYPE_NONE || (size + offset) > len) {
    return false; // not enough space in the destination
  }

  memcpy(&ptr[offset * TYPE_TO_SIZE[type]], &arr.ptr()[base], count * TYPE_TO_SIZE[IPP::TYPE_32F]);

  return true;
}


bool IppBuffer::copyFrom(const PackedFloat64Array &arr, int base, int count, int offset) {
  if(base < 0 || count <= 0 || (base + count) > arr.size()) {
    return false; // validation of source parameters failed
  }

  auto size = (count * TYPE_TO_SIZE[IPP::TYPE_64F] + TYPE_TO_SIZE[type] - 1) / TYPE_TO_SIZE[type];
  if(type == IPP::TYPE_NONE || (size + offset) > len) {
    return false; // not enough space in the destination
  }

  memcpy(&ptr[offset * TYPE_TO_SIZE[type]], &arr.ptr()[base], count * TYPE_TO_SIZE[IPP::TYPE_64F]);

  return true;
}


String IppBuffer::_to_string() const {
  Dictionary bits;
  bits["size"] = getLength();
  bits["type"] = IPP::typeString(getType());
  bits["data"] = reinterpret_cast<std::intptr_t>(ptr);
  return String("[IppBuffer: {_}]").format(bits);
}


bool IppBuffer::copy_to(int base, int count, Variant arr, int offset) {
  switch(arr.get_type()) {
    case Variant::PACKED_BYTE_ARRAY: {
      auto packed = static_cast<PackedByteArray>(arr);
      return copyTo(base, count, packed, offset);
    } break;

    case Variant::PACKED_INT32_ARRAY: {
      auto packed = static_cast<PackedInt32Array>(arr);
      return copyTo(base, count, packed, offset);
    } break;

    case Variant::PACKED_INT64_ARRAY: {
      auto packed = static_cast<PackedInt64Array>(arr);
      return copyTo(base, count, packed, offset);
    } break;

    case Variant::PACKED_FLOAT32_ARRAY: {
      auto packed = static_cast<PackedFloat32Array>(arr);
      return copyTo(base, count, packed, offset);
    } break;

    case Variant::PACKED_FLOAT64_ARRAY: {
      auto packed = static_cast<PackedFloat64Array>(arr);
      return copyTo(base, count, packed, offset);
    } break;

    default:
      // do nothing
    break;
  }

  return false;
}


bool IppBuffer::copy_from(Variant arr, int base, int count, int offset) {
  switch(arr.get_type()) {
    case Variant::PACKED_BYTE_ARRAY:
      return copyFrom(static_cast<PackedByteArray>(arr), base, count, offset);
    break;

    case Variant::PACKED_INT32_ARRAY:
      return copyFrom(static_cast<PackedInt32Array>(arr), base, count, offset);
    break;

    case Variant::PACKED_INT64_ARRAY:
      return copyFrom(static_cast<PackedInt64Array>(arr), base, count, offset);
    break;

    case Variant::PACKED_FLOAT32_ARRAY:
      return copyFrom(static_cast<PackedFloat32Array>(arr), base, count, offset);
    break;

    case Variant::PACKED_FLOAT64_ARRAY:
      return copyFrom(static_cast<PackedFloat64Array>(arr), base, count, offset);
    break;

    default:
      // do nothing
    break;
  }

  return false;
}


bool IppBuffer::add(const IppBuffer *lhs, const IppBuffer *rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len     ||
     lhs              == nullptr || rhs              == nullptr ||
     lhs->getType()   != type    || rhs->getType()   != type    ||
     lhs->getLength() <  len     || rhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
      ippsAdd_8u_Sfs(lhs->as8u(), rhs->as8u(), ptr, len, scale);
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_64U:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      ippsAdd_16u_Sfs(lhs->as16u(), rhs->as16u(), reinterpret_cast<Ipp16u *>(ptr), len, scale);
    break;

    case IPP::TYPE_16S:
      ippsAdd_16s_Sfs(lhs->as16s(), rhs->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32U:
      ippsAdd_32u(lhs->as32u(), rhs->as32u(), reinterpret_cast<Ipp32u *>(ptr), len);
    break;

    case IPP::TYPE_32S:
      ippsAdd_32s_Sfs(lhs->as32s(), rhs->as32s(), reinterpret_cast<Ipp32s *>(ptr), len, scale);
    break;

    case IPP::TYPE_64S:
      ippsAdd_64s_Sfs(lhs->as64s(), rhs->as64s(), reinterpret_cast<Ipp64s *>(ptr), len, scale);
    break;

    case IPP::TYPE_32F:
      ippsAdd_32f(lhs->as32f(), rhs->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsAdd_64f(lhs->as64f(), rhs->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_16SC:
      ippsAdd_16sc_Sfs(lhs->as16sc(), rhs->as16sc(), reinterpret_cast<Ipp16sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32SC:
      ippsAdd_32sc_Sfs(lhs->as32sc(), rhs->as32sc(), reinterpret_cast<Ipp32sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32FC:
      ippsAdd_32fc(lhs->as32fc(), rhs->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsAdd_64fc(lhs->as64fc(), rhs->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }
 
  return true;
}


bool IppBuffer::sub(const IppBuffer *lhs, const IppBuffer *rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len     ||
     lhs              == nullptr || rhs              == nullptr ||
     lhs->getType()   != type    || rhs->getType()   != type    ||
     lhs->getLength() <  len     || rhs->getLength() <  len) {
    return false; // bail on validation fail
  }
 
  switch(type) {
    case IPP::TYPE_8U:
      ippsSub_8u_Sfs(lhs->as8u(), rhs->as8u(), ptr, len, scale);
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      ippsSub_16u_Sfs(lhs->as16u(), rhs->as16u(), reinterpret_cast<Ipp16u *>(ptr), len, scale);
    break;

    case IPP::TYPE_16S:
      ippsSub_16s_Sfs(lhs->as16s(), rhs->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32S:
      ippsSub_32s_Sfs(lhs->as32s(), rhs->as32s(), reinterpret_cast<Ipp32s *>(ptr), len, scale);
    break;

    case IPP::TYPE_32F:
      ippsSub_32f(lhs->as32f(), rhs->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsSub_64f(lhs->as64f(), rhs->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_16SC:
      ippsSub_16sc_Sfs(lhs->as16sc(), rhs->as16sc(), reinterpret_cast<Ipp16sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32SC:
      ippsSub_32sc_Sfs(lhs->as32sc(), rhs->as32sc(), reinterpret_cast<Ipp32sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32FC:
      ippsSub_32fc(lhs->as32fc(), rhs->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsSub_64fc(lhs->as64fc(), rhs->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }

  return true;
}


bool IppBuffer::mul(const IppBuffer *lhs, const IppBuffer *rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len     ||
     lhs              == nullptr || rhs              == nullptr ||
     lhs->getType()   != type    || rhs->getType()   != type    ||
     lhs->getLength() <  len     || rhs->getLength() <  len) {
    return false; // bail on validation fail
  }
 
  switch(type) {
    case IPP::TYPE_8U:
      ippsMul_8u_Sfs(lhs->as8u(), rhs->as8u(), ptr, len, scale);
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      ippsMul_16u_Sfs(lhs->as16u(), rhs->as16u(), reinterpret_cast<Ipp16u *>(ptr), len, scale);
    break;

    case IPP::TYPE_16S:
      ippsMul_16s_Sfs(lhs->as16s(), rhs->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32S:
      ippsMul_32s_Sfs(lhs->as32s(), rhs->as32s(), reinterpret_cast<Ipp32s *>(ptr), len, scale);
    break;

    case IPP::TYPE_32F:
      ippsMul_32f(lhs->as32f(), rhs->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsMul_64f(lhs->as64f(), rhs->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_16SC:
      ippsMul_16sc_Sfs(lhs->as16sc(), rhs->as16sc(), reinterpret_cast<Ipp16sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32SC:
      ippsMul_32sc_Sfs(lhs->as32sc(), rhs->as32sc(), reinterpret_cast<Ipp32sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32FC:
      ippsMul_32fc(lhs->as32fc(), rhs->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsMul_64fc(lhs->as64fc(), rhs->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }

  return true;
}


bool IppBuffer::div(const IppBuffer *lhs, const IppBuffer *rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len     ||
     lhs              == nullptr || rhs              == nullptr ||
     lhs->getType()   != type    || rhs->getType()   != type    ||
     lhs->getLength() <  len     || rhs->getLength() <  len) {
    return false; // bail on validation fail
  }
 
  switch(type) {
    case IPP::TYPE_8U:
      ippsDiv_8u_Sfs(lhs->as8u(), rhs->as8u(), ptr, len, scale);
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      ippsDiv_16u_Sfs(lhs->as16u(), rhs->as16u(), reinterpret_cast<Ipp16u *>(ptr), len, scale);
    break;

    case IPP::TYPE_16S:
      ippsDiv_16s_Sfs(lhs->as16s(), rhs->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32S:
      ippsDiv_32s_Sfs(lhs->as32s(), rhs->as32s(), reinterpret_cast<Ipp32s *>(ptr), len, scale);
    break;

    case IPP::TYPE_32F:
      ippsDiv_32f(lhs->as32f(), rhs->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsDiv_64f(lhs->as64f(), rhs->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_16SC:
      ippsDiv_16sc_Sfs(lhs->as16sc(), rhs->as16sc(), reinterpret_cast<Ipp16sc *>(ptr), len, scale);
    break;

    case IPP::TYPE_32FC:
      ippsDiv_32fc(lhs->as32fc(), rhs->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsDiv_64fc(lhs->as64fc(), rhs->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }

  return true;
}


bool IppBuffer::addC(const IppBuffer *lhs, Variant rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len          ||
     lhs              == nullptr || rhs.get_type()   == Variant::NIL ||
     lhs->getType()   != type    || lhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_8u_Sfs(lhs->as8u(), static_cast<Ipp8u>(rhs.operator int32_t()), ptr, len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_16u_Sfs(lhs->as16u(), static_cast<Ipp16u>(rhs.operator int32_t()), reinterpret_cast<Ipp16u *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_16s_Sfs(lhs->as16s(), static_cast<Ipp16s>(rhs.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;
 
    case IPP::TYPE_32S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_32s_Sfs(lhs->as32s(), static_cast<Ipp32s>(rhs), reinterpret_cast<Ipp32s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_64s_Sfs(lhs->as64s(), rhs.operator int64_t(), reinterpret_cast<Ipp64s *>(ptr), len, scale, ippRndZero);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_32f(lhs->as32f(), static_cast<Ipp32f>(rhs), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsAddC_64f(lhs->as64f(), static_cast<Ipp64f>(rhs), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
        ippsAddC_16sc_Sfs(lhs->as16sc(), val, reinterpret_cast<Ipp16sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp32sc val{ v2i.x, v2i.y };
        ippsAddC_32sc_Sfs(lhs->as32sc(), val, reinterpret_cast<Ipp32sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp32fc val{ v2.x, v2.y };
        ippsAddC_32fc(lhs->as32fc(), val, reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp64fc val{ v2.x, v2.y };
        ippsAddC_64fc(lhs->as64fc(), val, reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;
  }
 
  return true;
}


bool IppBuffer::subC(const IppBuffer *lhs, Variant rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len          ||
     lhs              == nullptr || rhs.get_type()   == Variant::NIL ||
     lhs->getType()   != type    || lhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubC_8u_Sfs(lhs->as8u(), static_cast<Ipp8u>(rhs.operator int32_t()), ptr, len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubC_16u_Sfs(lhs->as16u(), static_cast<Ipp16u>(rhs.operator int32_t()), reinterpret_cast<Ipp16u *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubC_16s_Sfs(lhs->as16s(), static_cast<Ipp16s>(rhs.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;
 
    case IPP::TYPE_32S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubC_32s_Sfs(lhs->as32s(), static_cast<Ipp32s>(rhs), reinterpret_cast<Ipp32s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubC_32f(lhs->as32f(), static_cast<Ipp32f>(rhs), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubC_64f(lhs->as64f(), static_cast<Ipp64f>(rhs), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
        ippsSubC_16sc_Sfs(lhs->as16sc(), val, reinterpret_cast<Ipp16sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp32sc val{ v2i.x, v2i.y };
        ippsSubC_32sc_Sfs(lhs->as32sc(), val, reinterpret_cast<Ipp32sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp32fc val{ v2.x, v2.y };
        ippsSubC_32fc(lhs->as32fc(), val, reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp64fc val{ v2.x, v2.y };
        ippsSubC_64fc(lhs->as64fc(), val, reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;
  }
 
  return true;
}


bool IppBuffer::mulC(const IppBuffer *lhs, Variant rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len          ||
     lhs              == nullptr || rhs.get_type()   == Variant::NIL ||
     lhs->getType()   != type    || lhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsMulC_8u_Sfs(lhs->as8u(), static_cast<Ipp8u>(rhs.operator int32_t()), ptr, len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsMulC_16u_Sfs(lhs->as16u(), static_cast<Ipp16u>(rhs.operator int32_t()), reinterpret_cast<Ipp16u *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsMulC_16s_Sfs(lhs->as16s(), static_cast<Ipp16s>(rhs.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;
 
    case IPP::TYPE_32S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsMulC_32s_Sfs(lhs->as32s(), static_cast<Ipp32s>(rhs), reinterpret_cast<Ipp32s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsMulC_32f(lhs->as32f(), static_cast<Ipp32f>(rhs), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsMulC_64f(lhs->as64f(), static_cast<Ipp64f>(rhs), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
        ippsMulC_16sc_Sfs(lhs->as16sc(), val, reinterpret_cast<Ipp16sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp32sc val{ v2i.x, v2i.y };
        ippsMulC_32sc_Sfs(lhs->as32sc(), val, reinterpret_cast<Ipp32sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp32fc val{ v2.x, v2.y };
        ippsMulC_32fc(lhs->as32fc(), val, reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp64fc val{ v2.x, v2.y };
        ippsMulC_64fc(lhs->as64fc(), val, reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;
  }
 
  return true;
}


bool IppBuffer::divC(const IppBuffer *lhs, Variant rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len          ||
     lhs              == nullptr || rhs.get_type()   == Variant::NIL ||
     lhs->getType()   != type    || lhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivC_8u_Sfs(lhs->as8u(), static_cast<Ipp8u>(rhs.operator int32_t()), ptr, len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivC_16u_Sfs(lhs->as16u(), static_cast<Ipp16u>(rhs.operator int32_t()), reinterpret_cast<Ipp16u *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivC_16s_Sfs(lhs->as16s(), static_cast<Ipp16s>(rhs.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;
 
    case IPP::TYPE_32F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivC_32f(lhs->as32f(), static_cast<Ipp32f>(rhs), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivC_64f(lhs->as64f(), static_cast<Ipp64f>(rhs), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
        ippsDivC_16sc_Sfs(lhs->as16sc(), val, reinterpret_cast<Ipp16sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp32fc val{ v2.x, v2.y };
        ippsDivC_32fc(lhs->as32fc(), val, reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp64fc val{ v2.x, v2.y };
        ippsDivC_64fc(lhs->as64fc(), val, reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;
  }
 
  return true;
}


bool IppBuffer::subCRev(const IppBuffer *lhs, Variant rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len          ||
     lhs              == nullptr || rhs.get_type()   == Variant::NIL ||
     lhs->getType()   != type    || lhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubCRev_8u_Sfs(lhs->as8u(), static_cast<Ipp8u>(rhs.operator int32_t()), ptr, len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubCRev_16u_Sfs(lhs->as16u(), static_cast<Ipp16u>(rhs.operator int32_t()), reinterpret_cast<Ipp16u *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubCRev_16s_Sfs(lhs->as16s(), static_cast<Ipp16s>(rhs.operator int32_t()), reinterpret_cast<Ipp16s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;
 
    case IPP::TYPE_32S:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubCRev_32s_Sfs(lhs->as32s(), static_cast<Ipp32s>(rhs), reinterpret_cast<Ipp32s *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubCRev_32f(lhs->as32f(), static_cast<Ipp32f>(rhs), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsSubCRev_64f(lhs->as64f(), static_cast<Ipp64f>(rhs), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_16SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
        ippsSubCRev_16sc_Sfs(lhs->as16sc(), val, reinterpret_cast<Ipp16sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32SC:
      if(rhs.get_type() == Variant::VECTOR2I) {
        Vector2i v2i = static_cast<Vector2i>(rhs);
        Ipp32sc val{ v2i.x, v2i.y };
        ippsSubCRev_32sc_Sfs(lhs->as32sc(), val, reinterpret_cast<Ipp32sc *>(ptr), len, scale);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp32fc val{ v2.x, v2.y };
        ippsSubCRev_32fc(lhs->as32fc(), val, reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_64FC:
      if(rhs.get_type() == Variant::VECTOR2) {
        Vector2 v2 = static_cast<Vector2>(rhs);
        Ipp64fc val{ v2.x, v2.y };
        ippsSubCRev_64fc(lhs->as64fc(), val, reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        return false;
      }
    break;
  }
 
  return true;
}


bool IppBuffer::divCRev(const IppBuffer *lhs, Variant rhs, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len          ||
     lhs              == nullptr || rhs.get_type()   == Variant::NIL ||
     lhs->getType()   != type    || lhs->getLength() <  len) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_16S:
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_64F:
    case IPP::TYPE_16SC:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
    case IPP::TYPE_32FC:
    case IPP::TYPE_64FC:
      return false;
    break;
 
    case IPP::TYPE_16U:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivCRev_16u(lhs->as16u(), static_cast<Ipp16u>(rhs.operator int32_t()), reinterpret_cast<Ipp16u *>(ptr), len);
      }
      else {
        return false;
      }
    break;

    case IPP::TYPE_32F:
      if(rhs.get_type() == Variant::INT || rhs.get_type() == Variant::FLOAT) {
        ippsDivCRev_32f(lhs->as32f(), static_cast<Ipp32f>(rhs), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        return false;
      }
    break;

  }
 
  return true;
}


bool IppBuffer::ln(const IppBuffer *src, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
    case IPP::TYPE_16U:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_16SC:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
    case IPP::TYPE_32FC:
    case IPP::TYPE_64FC:
      return false;
    break;
 
    case IPP::TYPE_16S:
      ippsLn_16s_Sfs(src->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32S:
      ippsLn_32s_Sfs(src->as32s(), reinterpret_cast<Ipp32s *>(ptr), len, scale);
    break;

    case IPP::TYPE_32F:
      ippsLn_32f(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsLn_64f(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;
  }
 
  return true;
}


bool IppBuffer::exp(const IppBuffer *src, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
    case IPP::TYPE_16U:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64S:
    case IPP::TYPE_16SC:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
    case IPP::TYPE_32FC:
    case IPP::TYPE_64FC:
      return false;
    break;
 
    case IPP::TYPE_16S:
      ippsExp_16s_Sfs(src->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32S:
      ippsExp_32s_Sfs(src->as32s(), reinterpret_cast<Ipp32s *>(ptr), len, scale);
    break;

    case IPP::TYPE_32F:
      ippsExp_32f(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsExp_64f(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;
  }
 
  return true;
}


bool IppBuffer::sqr(const IppBuffer *src, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_16SC:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_8U:
      ippsSqr_8u_Sfs(src->as8u(), reinterpret_cast<Ipp8u *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_16U:
      ippsSqr_16u_Sfs(src->as16u(), reinterpret_cast<Ipp16u *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_16S:
      ippsSqr_16s_Sfs(src->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32F:
      ippsSqr_32f(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsSqr_64f(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_32FC:
      ippsSqr_32fc(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsSqr_64fc(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }
 
  return true;
}


bool IppBuffer::sqrt(const IppBuffer *src, int len, int scale) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8S:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_32S:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_16SC:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
      return false;
    break;
 
    case IPP::TYPE_8U:
      ippsSqrt_8u_Sfs(src->as8u(), reinterpret_cast<Ipp8u *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_16U:
      ippsSqrt_16u_Sfs(src->as16u(), reinterpret_cast<Ipp16u *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_16S:
      ippsSqrt_16s_Sfs(src->as16s(), reinterpret_cast<Ipp16s *>(ptr), len, scale);
    break;
 
    case IPP::TYPE_32F:
      ippsSqrt_32f(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsSqrt_64f(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;

    case IPP::TYPE_32FC:
      ippsSqrt_32fc(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
    break;

    case IPP::TYPE_64FC:
      ippsSqrt_64fc(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
    break;
  }
 
  return true;
}


bool IppBuffer::abs(const IppBuffer *src, int len) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    case IPP::TYPE_8U:
    case IPP::TYPE_8S:
    case IPP::TYPE_16U:
    case IPP::TYPE_8SC:
    case IPP::TYPE_32U:
    case IPP::TYPE_64U:
    case IPP::TYPE_64S:
    case IPP::TYPE_16SC:
    case IPP::TYPE_32SC:
    case IPP::TYPE_64SC:
    case IPP::TYPE_32FC:
    case IPP::TYPE_64FC:
      return false;
    break;
 
    case IPP::TYPE_16S:
      ippsAbs_16s(src->as16s(), reinterpret_cast<Ipp16s *>(ptr), len);
    break;
 
    case IPP::TYPE_32S:
      ippsAbs_32s(src->as32s(), reinterpret_cast<Ipp32s *>(ptr), len);
    break;

    case IPP::TYPE_32F:
      ippsAbs_32f(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
    break;

    case IPP::TYPE_64F:
      ippsAbs_64f(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
    break;
  }
 
  return true;
}


bool IppBuffer::cos(const IppBuffer *src, int len, int hint) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    default:
      return false;
    break;

    case IPP::TYPE_32F:
      if(hint == IPP::HINT_FAST) {
        ippsCos_32f_A11(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsCos_32f_A24(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        ippsCos_32f_A21(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
      }
    break;

    case IPP::TYPE_64F:
      if(hint == IPP::HINT_FAST) {
        ippsCos_64f_A26(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsCos_64f_A50(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        ippsCos_64f_A53(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
      }
    break;

    case IPP::TYPE_32FC:
      if(hint == IPP::HINT_FAST) {
        ippsCos_32fc_A11(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsCos_32fc_A24(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        ippsCos_32fc_A21(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
      }
    break;

    case IPP::TYPE_64FC:
      if(hint == IPP::HINT_FAST) {
        ippsCos_64fc_A26(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsCos_64fc_A53(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        ippsCos_64fc_A50(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
      }
    break;
  }
 
  return true;
}


bool IppBuffer::sin(const IppBuffer *src, int len, int hint) {
  if(ptr              == nullptr || this-> len       <  len ||
     src              == nullptr || src->getLength() <  len ||
     src->getType()   != type) {
    return false; // bail on validation fail
  }

  switch(type) {
    default:
      return false;
    break;

    case IPP::TYPE_32F:
      if(hint == IPP::HINT_FAST) {
        ippsSin_32f_A11(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsSin_32f_A24(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
      }
      else {
        ippsCos_32f_A21(src->as32f(), reinterpret_cast<Ipp32f *>(ptr), len);
      }
    break;

    case IPP::TYPE_64F:
      if(hint == IPP::HINT_FAST) {
        ippsSin_64f_A26(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsSin_64f_A50(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
      }
      else {
        ippsSin_64f_A53(src->as64f(), reinterpret_cast<Ipp64f *>(ptr), len);
      }
    break;

    case IPP::TYPE_32FC:
      if(hint == IPP::HINT_FAST) {
        ippsSin_32fc_A11(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsSin_32fc_A24(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
      }
      else {
        ippsSin_32fc_A21(src->as32fc(), reinterpret_cast<Ipp32fc *>(ptr), len);
      }
    break;

    case IPP::TYPE_64FC:
      if(hint == IPP::HINT_FAST) {
        ippsSin_64fc_A26(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else if(hint == IPP::HINT_ACC) {
        ippsSin_64fc_A53(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
      }
      else {
        ippsSin_64fc_A50(src->as64fc(), reinterpret_cast<Ipp64fc *>(ptr), len);
      }
    break;
  }
 
  return true;
}


Variant IppBuffer::sum(int len, int scale) {
  if(!ptr) {
    return Variant(0); // bail on no buffer
  }

  switch(type) {
    default:
      return Variant(0);
    break;

    case IPP::TYPE_16S: {
      Ipp32s sum;
      ippsSum_16s32s_Sfs(reinterpret_cast<Ipp16s *>(ptr), len, &sum, scale);
      return Variant(sum);
    } break;
 
    case IPP::TYPE_32S: {
      Ipp32s sum;
      ippsSum_32s_Sfs(reinterpret_cast<Ipp32s *>(ptr), len, &sum, scale);
      return Variant(sum);
    } break;

    case IPP::TYPE_32F: {
      Ipp32f sum;
      ippsSum_32f(reinterpret_cast<Ipp32f *>(ptr), len, &sum, static_cast<IppHintAlgorithm>(IPP::HINT_FAST));
      return Variant(sum);
    } break;

    case IPP::TYPE_64F: {
      Ipp64f sum;
      ippsSum_64f(reinterpret_cast<Ipp64f *>(ptr), len, &sum);
      return Variant(sum);
    } break;

    case IPP::TYPE_16SC: {
      Ipp16sc sum;
      ippsSum_16sc_Sfs(reinterpret_cast<Ipp16sc *>(ptr), len, &sum, scale);
      return Variant(Vector2i(sum.re, sum.im));
    } break;

    case IPP::TYPE_32FC: {
      Ipp32fc sum;
      ippsSum_32fc(reinterpret_cast<Ipp32fc *>(ptr), len, &sum, static_cast<IppHintAlgorithm>(IPP::HINT_FAST));
      return Variant(Vector2(sum.re, sum.im));
    } break;

    case IPP::TYPE_64FC: {
      Ipp64fc sum;
      ippsSum_64fc(reinterpret_cast<Ipp64fc *>(ptr), len, &sum);
      return Variant(Vector2(sum.re, sum.im));
    } break;
  }
 
  return Variant(0);
}


Variant IppBuffer::mean(int len, int scale) {
  if(!ptr) {
    return Variant(0); // bail on no buffer
  }
 
  switch(type) {
    default:
      return Variant(0);
    break;

    case IPP::TYPE_16S: {
      Ipp16s mean;
      ippsMean_16s_Sfs(reinterpret_cast<Ipp16s *>(ptr), len, &mean, scale);
      return Variant(mean);
    } break;
 
    case IPP::TYPE_32S: {
      Ipp32s mean;
      ippsMean_32s_Sfs(reinterpret_cast<Ipp32s *>(ptr), len, &mean, scale);
      return Variant(mean);
    } break;

    case IPP::TYPE_32F: {
      Ipp32f mean;
      ippsMean_32f(reinterpret_cast<Ipp32f *>(ptr), len, &mean, static_cast<IppHintAlgorithm>(IPP::HINT_FAST));
      return Variant(mean);
    } break;

    case IPP::TYPE_64F: {
      Ipp64f mean;
      ippsMean_64f(reinterpret_cast<Ipp64f *>(ptr), len, &mean);
      return Variant(mean);
    } break;

    case IPP::TYPE_16SC: {
      Ipp16sc mean;
      ippsMean_16sc_Sfs(reinterpret_cast<Ipp16sc *>(ptr), len, &mean, scale);
      return Variant(Vector2i(mean.re, mean.im));
    } break;

    case IPP::TYPE_32FC: {
      Ipp32fc mean;
      ippsMean_32fc(reinterpret_cast<Ipp32fc *>(ptr), len, &mean, static_cast<IppHintAlgorithm>(IPP::HINT_FAST));
      return Variant(Vector2(mean.re, mean.im));
    } break;

    case IPP::TYPE_64FC: {
      Ipp64fc mean;
      ippsMean_64fc(reinterpret_cast<Ipp64fc *>(ptr), len, &mean);
      return Variant(Vector2(mean.re, mean.im));
    } break;
  }

  return Variant(0);
}


static IppBuffer *create_empty(int count, IPP::Type type) {
  return new IppBuffer(count, type);
}


static IppBuffer *create_byte(const PackedByteArray &arr, IPP::Type type) {
  return new IppBuffer(arr, type);
}


static IppBuffer *create_int32(const PackedInt32Array &arr, IPP::Type type) {
  return new IppBuffer(arr, type);
}


static IppBuffer *create_int64(const PackedInt64Array &arr, IPP::Type type) {
  return new IppBuffer(arr, type);
}


static IppBuffer *create_float32(const PackedFloat32Array &arr, IPP::Type type) {
  return new IppBuffer(arr, type);
}


static IppBuffer *create_float64(const PackedFloat64Array &arr, IPP::Type type) {
  return new IppBuffer(arr, type);
}


void IppBuffer::_bind_methods() {
  ClassDB::bind_static_method("IppBuffer", D_METHOD("create", "count", "kind"), create_empty, DEFVAL(IPP::TYPE_8U));
  ClassDB::bind_static_method("IppBuffer", D_METHOD("create_from_bytes", "array", "kind"), create_byte, DEFVAL(IPP::TYPE_8U));
  ClassDB::bind_static_method("IppBuffer", D_METHOD("create_from_int32s", "array", "kind"), create_int32, DEFVAL(IPP::TYPE_32S));
  ClassDB::bind_static_method("IppBuffer", D_METHOD("create_from_int64s", "array", "kind"), create_int64, DEFVAL(IPP::TYPE_64S));
  ClassDB::bind_static_method("IppBuffer", D_METHOD("create_from_float32s", "array", "kind"), create_float32, DEFVAL(IPP::TYPE_32F));
  ClassDB::bind_static_method("IppBuffer", D_METHOD("create_from_float64s", "array", "kind"), create_float64, DEFVAL(IPP::TYPE_64F));

  ClassDB::bind_method(D_METHOD("load", "file"), &IppBuffer::load);
  ClassDB::bind_method(D_METHOD("store", "file"), &IppBuffer::store);

  ClassDB::bind_method(D_METHOD("read", "file", "offset", "elems"), &IppBuffer::read);
  ClassDB::bind_method(D_METHOD("write", "file", "offset", "elems"), &IppBuffer::write);

  ClassDB::bind_method(D_METHOD("get_type"), &IppBuffer::getType);
  ClassDB::bind_method(D_METHOD("size"), &IppBuffer::getLength);

  ClassDB::bind_method(D_METHOD("to_byte_array"), &IppBuffer::toPackedByteArray);
  ClassDB::bind_method(D_METHOD("to_int32_array"), &IppBuffer::toPackedInt32Array);
  ClassDB::bind_method(D_METHOD("to_int64_array"), &IppBuffer::toPackedInt64Array);
  ClassDB::bind_method(D_METHOD("to_float32_array"), &IppBuffer::toPackedFloat32Array);
  ClassDB::bind_method(D_METHOD("to_float64_array"), &IppBuffer::toPackedFloat64Array);

  ClassDB::bind_method(D_METHOD("copy_to"), &IppBuffer::copy_to, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("copy_from"), &IppBuffer::copy_from, DEFVAL(0));

  ClassDB::bind_method(D_METHOD("add", "lhs", "rhs", "len", "scale"), &IppBuffer::add, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("sub", "lhs", "rhs", "len", "scale"), &IppBuffer::sub, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("mul", "lhs", "rhs", "len", "scale"), &IppBuffer::mul, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("div", "lhs", "rhs", "len", "scale"), &IppBuffer::div, DEFVAL(0));

  ClassDB::bind_method(D_METHOD("addC", "lhs", "val", "len", "scale"), &IppBuffer::addC, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("subC", "lhs", "val", "len", "scale"), &IppBuffer::subC, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("mulC", "lhs", "val", "len", "scale"), &IppBuffer::mulC, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("divC", "lhs", "val", "len", "scale"), &IppBuffer::divC, DEFVAL(0));

  ClassDB::bind_method(D_METHOD("ln", "src", "len", "scale"), &IppBuffer::ln, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("exp", "src", "len", "scale"), &IppBuffer::exp, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("sqr", "src", "len", "scale"), &IppBuffer::sqr, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("sqrt", "src", "len", "scale"), &IppBuffer::sqrt, DEFVAL(0));

  ClassDB::bind_method(D_METHOD("abs", "src", "len"), &IppBuffer::abs);
  ClassDB::bind_method(D_METHOD("cos", "src", "len", "hint"), &IppBuffer::cos, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("sin", "src", "len", "hint"), &IppBuffer::sin, DEFVAL(0));

  ClassDB::bind_method(D_METHOD("sum", "len", "scale"), &IppBuffer::sum, DEFVAL(0));
  ClassDB::bind_method(D_METHOD("mean", "len", "scale"), &IppBuffer::mean, DEFVAL(0));
}

