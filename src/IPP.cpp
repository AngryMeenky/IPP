#include "IPP.h"
#include "fft.h"
#include "buffer.h"

#ifdef GDEXTENSION
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/core/class_db.hpp>
#else
#include "core/object/class_db.h"
#include "core/os/memory.h"
#include "core/os/os.h"
#endif


using namespace godot;


static const char *TYPE_TO_STRING[] = {
  "NONE",
  // integers
  "Ipp8u", "Ipp8s", "Ipp16u", "Ipp16s",
  "Ipp32u", "Ipp32s", "Ipp64s",
  // reals
  "Ipp32f", "Ipp64s",
  // complex integers
  "Ipp8sc", "Ipp16sc", "Ipp32sc", "Ipp64sc",
  // complex reals
  "Ipp32fc", "Ipp64fc"
};


const char *ipp::IPP::typeString(Type t) {
  return TYPE_TO_STRING[(0 >= t || t > TYPE_64FC) ? 0 : t];
}


static const char *HINT_TO_STRING[] = {
  "NONE", "Fast", "Accurate"
};


const char *ipp::IPP::hintString(Hint h) {
  return HINT_TO_STRING[(0 >= h || h > HINT_ACC) ? 0 : h];
}


ipp::IppBuffer *ipp::IPP::malloc_8u(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_8U) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_16u(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_16U) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_32u(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_32U) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_8s(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_8S) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_16s(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_16S) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_32s(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_32S) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_64s(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_64S) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_32f(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_32F) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_64f(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_64F) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_8sc(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_8SC) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_16sc(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_16SC) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_32sc(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_32SC) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_64sc(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_64SC) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_32fc(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_32FC) : nullptr;
}


ipp::IppBuffer *ipp::IPP::malloc_64fc(int len) {
  return len > 0 ? new ipp::IppBuffer(len, ipp::IPP::TYPE_64FC) : nullptr;
}


ipp::IPP::Status ipp::IPP::copy_8u(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_8S && st != TYPE_8U) || (dt != TYPE_8S && dt != TYPE_8U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_8u(src->as8u(), dst->as8u(), len));
}


ipp::IPP::Status ipp::IPP::copy_16s(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_16S && st != TYPE_16U) || (dt != TYPE_16S && dt != TYPE_16U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_16s(src->as16s(), dst->as16s(), len));
}


ipp::IPP::Status ipp::IPP::copy_32s(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_32S && st != TYPE_32U) || (dt != TYPE_32S && dt != TYPE_32U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_32s(src->as32s(), dst->as32s(), len));
}


ipp::IPP::Status ipp::IPP::copy_64s(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || dst->getType() != TYPE_64S || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_64s(src->as64s(), dst->as64s(), len));
}


ipp::IPP::Status ipp::IPP::copy_32f(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_32f(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::copy_64f(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_64f(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::copy_16sc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_16sc(src->as16sc(), dst->as16sc(), len));
}


ipp::IPP::Status ipp::IPP::copy_32sc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_32sc(src->as32sc(), dst->as32sc(), len));
}


ipp::IPP::Status ipp::IPP::copy_64sc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64SC || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_64sc(src->as64sc(), dst->as64sc(), len));
}


ipp::IPP::Status ipp::IPP::copy_32fc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_32fc(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::copy_64fc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCopy_64fc(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::move_8u(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_8S && st != TYPE_8U) || (dt != TYPE_8S && dt != TYPE_8U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_8u(src->as8u(), dst->as8u(), len));
}


ipp::IPP::Status ipp::IPP::move_16s(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_16S && st != TYPE_16U) || (dt != TYPE_16S && dt != TYPE_16U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_16s(src->as16s(), dst->as16s(), len));
}


ipp::IPP::Status ipp::IPP::move_32s(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_32S && st != TYPE_32U) || (dt != TYPE_32S && dt != TYPE_32U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32s(src->as32s(), dst->as32s(), len));
}


ipp::IPP::Status ipp::IPP::move_64s(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || dst->getType() != TYPE_64S || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64s(src->as64s(), dst->as64s(), len));
}


ipp::IPP::Status ipp::IPP::move_32f(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32f(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::move_64f(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64f(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::move_16sc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_16sc(src->as16sc(), dst->as16sc(), len));
}


ipp::IPP::Status ipp::IPP::move_32sc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32sc(src->as32sc(), dst->as32sc(), len));
}


ipp::IPP::Status ipp::IPP::move_64sc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64SC || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64sc(src->as64sc(), dst->as64sc(), len));
}


ipp::IPP::Status ipp::IPP::move_32fc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32fc(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::move_64fc(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64fc(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::set_8u(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto dt = dst->getType(); dt != TYPE_8S && dt != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_8u(var.operator uint8_t(), dst->as8u(), len));
}


ipp::IPP::Status ipp::IPP::set_16s(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto dt = dst->getType(); dt != TYPE_16S && dt != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_16s(var.operator int16_t(), dst->as16s(), len));
}


ipp::IPP::Status ipp::IPP::set_32s(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto dt = dst->getType(); dt != TYPE_32S && dt != TYPE_32U) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_32s(var.operator int32_t(), dst->as32s(), len));
}


ipp::IPP::Status ipp::IPP::set_64s(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_64s(var.operator int64_t(), dst->as64s(), len));
}


ipp::IPP::Status ipp::IPP::set_32f(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_32f(var.operator float(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::set_64f(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_64f(var.operator double(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::set_16sc(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2I || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2i = var.operator Vector2i();
  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsSet_16sc(val, dst->as16sc(), len));
}


ipp::IPP::Status ipp::IPP::set_32sc(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2I || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2i = var.operator Vector2i();
  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsSet_32sc(val, dst->as32sc(), len));
}


ipp::IPP::Status ipp::IPP::set_64sc(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2I || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2i = var.operator Vector2i();
  Ipp64sc val{ static_cast<Ipp64s>(v2i.x), static_cast<Ipp64s>(v2i.y) };
  return static_cast<Status>(ippsSet_64sc(val, dst->as64sc(), len));
}


ipp::IPP::Status ipp::IPP::set_32fc(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2 || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2 = var.operator Vector2();
  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsSet_32fc(val, dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::set_64fc(Variant var, IppBuffer *dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2 || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2 = var.operator Vector2();
  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsSet_64fc(val, dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::zero_8u(IppBuffer *dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_8S && dst->getType() != TYPE_8U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_8u(dst->as8u(), len));
}


ipp::IPP::Status ipp::IPP::zero_16s(IppBuffer *dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_16S && dst->getType() != TYPE_16U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_16s(dst->as16s(), len));
}


ipp::IPP::Status ipp::IPP::zero_32s(IppBuffer *dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_32S && dst->getType() != TYPE_32U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32s(dst->as32s(), len));
}


ipp::IPP::Status ipp::IPP::zero_64s(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64s(dst->as64s(), len));
}


ipp::IPP::Status ipp::IPP::zero_32f(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32f(dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::zero_64f(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64f(dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::zero_16sc(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_16sc(dst->as16sc(), len));
}


ipp::IPP::Status ipp::IPP::zero_32sc(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32sc(dst->as32sc(), len));
}


ipp::IPP::Status ipp::IPP::zero_64sc(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64sc(dst->as64sc(), len));
}


ipp::IPP::Status ipp::IPP::zero_32fc(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32fc(dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::zero_64fc(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64fc(dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::tone_16s(IppBuffer *dst, int len, int mag, float freq, Variant phase, Hint hint) {
  if(dst == nullptr || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTone_16s(dst->as16s(), len, static_cast<Ipp16s>(mag), freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTone_16s(dst->as16s(), len, static_cast<Ipp16s>(mag), freq, &arr[0], static_cast<IppHintAlgorithm>(hint)));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::tone_32f(IppBuffer *dst, int len, float mag, float freq, Variant phase, Hint hint) {
  if(dst == nullptr || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTone_32f(dst->as32f(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTone_32f(dst->as32f(), len, mag, freq, &arr[0], static_cast<IppHintAlgorithm>(hint)));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::tone_64f(IppBuffer *dst, int len, double mag, double freq, Variant phase, Hint hint) {
  if(dst == nullptr || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = static_cast<double>(arr[0].operator float());
      auto retVal = ippsTone_64f(dst->as64f(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = Variant(static_cast<float>(phi));
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      auto phi = static_cast<double>(arr[0]);
      auto retVal = ippsTone_64f(dst->as64f(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = static_cast<float>(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT64_ARRAY) {
    auto arr = phase.operator PackedFloat64Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTone_64f(dst->as64f(), len, mag, freq, &arr[0], static_cast<IppHintAlgorithm>(hint)));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::tone_16sc(IppBuffer *dst, int len, int mag, float freq, Variant phase, Hint hint) {
  if(dst == nullptr || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTone_16sc(dst->as16sc(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTone_16sc(dst->as16sc(), len, mag, freq, &arr[0], static_cast<IppHintAlgorithm>(hint)));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::tone_32fc(IppBuffer *dst, int len, float mag, float freq, Variant phase, Hint hint) {
  if(dst == nullptr || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTone_32fc(dst->as32fc(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTone_32fc(dst->as32fc(), len, mag, freq, &arr[0], static_cast<IppHintAlgorithm>(hint)));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::tone_64fc(IppBuffer *dst, int len, double mag, double freq, Variant phase, Hint hint) {
  if(dst == nullptr || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = static_cast<double>(arr[0].operator float());
      auto retVal = ippsTone_64fc(dst->as64fc(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = Variant(static_cast<float>(phi));
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      auto phi = static_cast<double>(arr[0]);
      auto retVal = ippsTone_64fc(dst->as64fc(), len, mag, freq, &phi, static_cast<IppHintAlgorithm>(hint));
      arr[0] = static_cast<float>(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT64_ARRAY) {
    auto arr = phase.operator PackedFloat64Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTone_64fc(dst->as64fc(), len, mag, freq, &arr[0], static_cast<IppHintAlgorithm>(hint)));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::triangle_16s(IppBuffer *dst, int len, int mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_16s(dst->as16s(), len, static_cast<Ipp16s>(mag), freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_16s(dst->as16s(), len, static_cast<Ipp16s>(mag), freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::triangle_32f(IppBuffer *dst, int len, float mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_32f(dst->as32f(), len, mag, freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_32f(dst->as32f(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::triangle_64f(IppBuffer *dst, int len, double mag, double freq, double asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = static_cast<double>(arr[0].operator float());
      auto retVal = ippsTriangle_64f(dst->as64f(), len, mag, freq, asym, &phi);
      arr[0] = Variant(static_cast<float>(phi));
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      auto phi = static_cast<double>(arr[0]);
      auto retVal = ippsTriangle_64f(dst->as64f(), len, mag, freq, asym, &phi);
      arr[0] = static_cast<float>(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT64_ARRAY) {
    auto arr = phase.operator PackedFloat64Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_64f(dst->as64f(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::triangle_16sc(IppBuffer *dst, int len, int mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_16sc(dst->as16sc(), len, mag, freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_16sc(dst->as16sc(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::triangle_32fc(IppBuffer *dst, int len, float mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_32fc(dst->as32fc(), len, mag, freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_32fc(dst->as32fc(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::triangle_64fc(IppBuffer *dst, int len, double mag, double freq, double asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = static_cast<double>(arr[0].operator float());
      auto retVal = ippsTriangle_64fc(dst->as64fc(), len, mag, freq, asym, &phi);
      arr[0] = Variant(static_cast<float>(phi));
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      auto phi = static_cast<double>(arr[0]);
      auto retVal = ippsTriangle_64fc(dst->as64fc(), len, mag, freq, asym, &phi);
      arr[0] = static_cast<float>(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT64_ARRAY) {
    auto arr = phase.operator PackedFloat64Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_64fc(dst->as64fc(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IppFft *ipp::IPP::fft_init_C_32f(int order, int flag) {
  return order >= 2 ? new IppFft(IPP::TYPE_32F, order, flag) : nullptr;
}


ipp::IppFft *ipp::IPP::fft_init_C_64f(int order, int flag) {
  return order >= 2 ? new IppFft(IPP::TYPE_64F, order, flag) : nullptr;
}


ipp::IppFft *ipp::IPP::fft_init_C_32fc(int order, int flag) {
  return order >= 2 ? new IppFft(IPP::TYPE_32FC, order, flag) : nullptr;
}


ipp::IppFft *ipp::IPP::fft_init_C_64fc(int order, int flag) {
  return order >= 2 ? new IppFft(IPP::TYPE_64FC, order, flag) : nullptr;
}


void ipp::IPP::_bind_methods() {
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_8u", "len"), &IPP::malloc_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_8s", "len"), &IPP::malloc_8s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_16u", "len"), &IPP::malloc_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_16s", "len"), &IPP::malloc_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32u", "len"), &IPP::malloc_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32s", "len"), &IPP::malloc_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64s", "len"), &IPP::malloc_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32f", "len"), &IPP::malloc_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64f", "len"), &IPP::malloc_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_8sc", "len"), &IPP::malloc_8sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_16sc", "len"), &IPP::malloc_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32sc", "len"), &IPP::malloc_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64sc", "len"), &IPP::malloc_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32fc", "len"), &IPP::malloc_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64fc", "len"), &IPP::malloc_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("copy_8u", "src", "dst", "len"), &IPP::copy_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_16s", "src", "dst", "len"), &IPP::copy_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32s", "src", "dst", "len"), &IPP::copy_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64s", "src", "dst", "len"), &IPP::copy_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32f", "src", "dst", "len"), &IPP::copy_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64f", "src", "dst", "len"), &IPP::copy_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_16sc", "src", "dst", "len"), &IPP::copy_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32sc", "src", "dst", "len"), &IPP::copy_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64sc", "src", "dst", "len"), &IPP::copy_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32fc", "src", "dst", "len"), &IPP::copy_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64fc", "src", "dst", "len"), &IPP::copy_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("move_8u", "src", "dst", "len"), &IPP::move_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("move_16s", "src", "dst", "len"), &IPP::move_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32s", "src", "dst", "len"), &IPP::move_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64s", "src", "dst", "len"), &IPP::move_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32f", "src", "dst", "len"), &IPP::move_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64f", "src", "dst", "len"), &IPP::move_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("move_16sc", "src", "dst", "len"), &IPP::move_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32sc", "src", "dst", "len"), &IPP::move_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64sc", "src", "dst", "len"), &IPP::move_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32fc", "src", "dst", "len"), &IPP::move_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64fc", "src", "dst", "len"), &IPP::move_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("set_8u", "val", "dst", "len"), &IPP::set_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("set_16s", "val", "dst", "len"), &IPP::set_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32s", "val", "dst", "len"), &IPP::set_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64s", "val", "dst", "len"), &IPP::set_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32f", "val", "dst", "len"), &IPP::set_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64f", "val", "dst", "len"), &IPP::set_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("set_16sc", "val", "dst", "len"), &IPP::set_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32sc", "val", "dst", "len"), &IPP::set_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64sc", "val", "dst", "len"), &IPP::set_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32fc", "val", "dst", "len"), &IPP::set_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64fc", "val", "dst", "len"), &IPP::set_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("zero_8u", "dst", "len"), &IPP::zero_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_16s", "dst", "len"), &IPP::zero_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32s", "dst", "len"), &IPP::zero_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64s", "dst", "len"), &IPP::zero_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32f", "dst", "len"), &IPP::zero_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64f", "dst", "len"), &IPP::zero_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_16sc", "dst", "len"), &IPP::zero_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32sc", "dst", "len"), &IPP::zero_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64sc", "dst", "len"), &IPP::zero_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32fc", "dst", "len"), &IPP::zero_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64fc", "dst", "len"), &IPP::zero_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("tone_16s", "len", "mag", "freq", "phase", "hint"), &IPP::tone_16s, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_32f", "len", "mag", "freq", "phase", "hint"), &IPP::tone_32f, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_64f", "len", "mag", "freq", "phase", "hint"), &IPP::tone_64f, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_16sc", "len", "mag", "freq", "phase", "hint"), &IPP::tone_16sc, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_32fc", "len", "mag", "freq", "phase", "hint"), &IPP::tone_32fc, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_64fc", "len", "mag", "freq", "phase", "hint"), &IPP::tone_64fc, DEFVAL(HINT_NONE));

  ClassDB::bind_static_method("IPP", D_METHOD("triangle_16s", "len", "mag", "freq", "asym", "phase"), &IPP::tone_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_32f", "len", "mag", "freq", "asym", "phase"), &IPP::tone_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_64f", "len", "mag", "freq", "asym", "phase"), &IPP::tone_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_16sc", "len", "mag", "freq", "asym", "phase"), &IPP::tone_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_32fc", "len", "mag", "freq", "asym", "phase"), &IPP::tone_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_64fc", "len", "mag", "freq", "asym", "phase"), &IPP::tone_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_32f", "len"), &IPP::fft_init_C_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_64f", "len"), &IPP::fft_init_C_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_32fc", "len"), &IPP::fft_init_C_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_64fc", "len"), &IPP::fft_init_C_64fc);

  BIND_ENUM_CONSTANT(TYPE_8U);
  BIND_ENUM_CONSTANT(TYPE_8S);
  BIND_ENUM_CONSTANT(TYPE_16U);
  BIND_ENUM_CONSTANT(TYPE_16S);
  BIND_ENUM_CONSTANT(TYPE_32U);
  BIND_ENUM_CONSTANT(TYPE_32S);
  BIND_ENUM_CONSTANT(TYPE_64S);
  BIND_ENUM_CONSTANT(TYPE_32F);
  BIND_ENUM_CONSTANT(TYPE_64F);
  BIND_ENUM_CONSTANT(TYPE_8SC);
  BIND_ENUM_CONSTANT(TYPE_16SC);
  BIND_ENUM_CONSTANT(TYPE_32SC);
  BIND_ENUM_CONSTANT(TYPE_64SC);
  BIND_ENUM_CONSTANT(TYPE_32FC);
  BIND_ENUM_CONSTANT(TYPE_64FC);

  BIND_ENUM_CONSTANT(HINT_NONE);
  BIND_ENUM_CONSTANT(HINT_FAST);
  BIND_ENUM_CONSTANT(HINT_ACC);

  BIND_ENUM_CONSTANT(STAT_CPU_NOT_SUPPORTED);
//  BIND_ENUM_CONSTANT(STAT_POINT_AT_INIFINTY);
//  BIND_ENUM_CONSTANT(STAT_I18N_UNSOPPORTED);
//  BIND_ENUM_CONSTANT(STAT_I18N_MSG_CATALOG_OPEN_ERR);
//  BIND_ENUM_CONSTANT(STAT_I18N_MSG_CATALOG_CLOSE_ERR);
  BIND_ENUM_CONSTANT(STAT_UNKNOWN_STATUS_CODE_ERR);
//  BIND_ENUM_CONSTANT(STAT_OFB_SIZE_ERR);
  BIND_ENUM_CONSTANT(STAT_LZO_BROKEN_STREAM_ERR);
  BIND_ENUM_CONSTANT(STAT_ROUND_MODE_NOT_SUPPORTED_ERR);
//  BIND_ENUM_CONSTANT(STAT_MAX_LEN_HUFF_CODE_ERR);
//  BIND_ENUM_CONSTANT(STAT_CODE_LEN_TABLE_ERR);
//  BIND_ENUM_CONSTANT(STAT_FREQ_TABLE_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_OPTIONS_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_MATCH_LIMIT_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_QUANTIFIER_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_GROUPING_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_BACK_REF_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_CHAR_CLASS_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_META_CHAR_ERR);
//  BIND_ENUM_CONSTANT(STAT_MP3_FRAME_HEADER_ERR);
//  BIND_ENUM_CONSTANT(STAT_MP3_SIDE_INFO_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PRG_NUM_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SECT_CB_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SF_VAL_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_COEFF_VAL_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_MAX_SF_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PRED_SF_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PLS_DATA_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_GAIN_CTR_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SECT_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_NUM_FILT_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_LEN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_ORDER_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_COEFF_RES_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_COEFF_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_DIRECT_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_PROFILE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_BIT_OFFSET_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_ADTS_SYNC_WORD_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SAMPLE_RATE_INDEX_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_LEN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_GRP_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_SEQ_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_COM_WIN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_STEREO_MASK_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_CHAN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_MONO_STEREO_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_STEREO_LAYER_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_MONO_LAYER_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SCALABLE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_OBJ_TYPE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_SHAPE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PCM_MODE_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_HEADER_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_UNSUPPORTED_FORMAT_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_ESC_ALG_TYPE_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_ESC_CODE_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_CODE_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_INTERNAL_TABLE_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_INPUT_DATA_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_AAC_ESC_CODE_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_INCORRECT_SP_ERR);
//  BIND_ENUM_CONSTANT(STAT_NO_ROOT_FOUND_ERR);
  BIND_ENUM_CONSTANT(STAT_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_FBANK_FREQ_ERR);
//  BIND_ENUM_CONSTANT(STAT_FBANK_FLAG_ERR);
//  BIND_ENUM_CONSTANT(STAT_FBANK_ERR);
//  BIND_ENUM_CONSTANT(STAT_NEG_OCC_ERR);
//  BIND_ENUM_CONSTANT(STAT_CDBK_FLAG_ERR);
//  BIND_ENUM_CONSTANT(STAT_SVD_CNVG_ERR);
  BIND_ENUM_CONSTANT(STAT_TONE_MAGN_ERR);
  BIND_ENUM_CONSTANT(STAT_TONE_FREQ_ERR);
  BIND_ENUM_CONSTANT(STAT_TONE_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_MAGN_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_FREQ_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_ASYM_ERR);
  BIND_ENUM_CONSTANT(STAT_HUGE_WIN_ERR);
  BIND_ENUM_CONSTANT(STAT_JAEHNE_ERR);
  BIND_ENUM_CONSTANT(STAT_STEP_ERR);
//  BIND_ENUM_CONSTANT(STAT_DLY_LINE_INDEX_ERR);
  BIND_ENUM_CONSTANT(STAT_STRIDE_ERR);
  BIND_ENUM_CONSTANT(STAT_EPS_VAL_ERR);
  BIND_ENUM_CONSTANT(STAT_SCALE_RANGE_ERR);
  BIND_ENUM_CONSTANT(STAT_THESHOLD_ERR);
  BIND_ENUM_CONSTANT(STAT_WT_OFFSET_ERR);
  BIND_ENUM_CONSTANT(STAT_ANCHOR_ERR);
  BIND_ENUM_CONSTANT(STAT_MASK_SIZE_ERR);
  BIND_ENUM_CONSTANT(STAT_SHIFT_ERR);
  BIND_ENUM_CONSTANT(STAT_SAMPLE_FACTOR_ERR);
  BIND_ENUM_CONSTANT(STAT_SAMPLE_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_FIR_MR_FACTOR_ERR);
  BIND_ENUM_CONSTANT(STAT_FIR_MR_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_REL_FREQ_ERR);
  BIND_ENUM_CONSTANT(STAT_FIR_LEN_ERR);
  BIND_ENUM_CONSTANT(STAT_IIR_ORDER_ERR);
  BIND_ENUM_CONSTANT(STAT_RESIZE_FACTOR_ERR);
  BIND_ENUM_CONSTANT(STAT_DIV_BY_ZERO_ERR);
  BIND_ENUM_CONSTANT(STAT_INTERPOLATION_ERR);
  BIND_ENUM_CONSTANT(STAT_MIRROR_FLIP_ERR);
  BIND_ENUM_CONSTANT(STAT_MOMENT_00_ZERO_ERR);
  BIND_ENUM_CONSTANT(STAT_THRESH_NEG_LEVEL_ERR);
  BIND_ENUM_CONSTANT(STAT_CONTEXT_MATCH_ERR);
  BIND_ENUM_CONSTANT(STAT_FFT_FLAG_ERR);
  BIND_ENUM_CONSTANT(STAT_FFT_ORDER_ERR);
  BIND_ENUM_CONSTANT(STAT_MEM_ALLOC_ERR);
  BIND_ENUM_CONSTANT(STAT_NULL_PTR_ERR);
  BIND_ENUM_CONSTANT(STAT_SIZE_ERR);
  BIND_ENUM_CONSTANT(STAT_BAD_ARG_ERR);
  BIND_ENUM_CONSTANT(STAT_ERR);
  BIND_ENUM_CONSTANT(STAT_NO_ERR);
  BIND_ENUM_CONSTANT(STAT_NO_OPERATION);
//  BIND_ENUM_CONSTANT(STAT_MISALIGNED_BUF);
  BIND_ENUM_CONSTANT(STAT_SQRT_NEG_ARG);
//  BIND_ENUM_CONSTANT(STAT_INV_BY_ZERO);
  BIND_ENUM_CONSTANT(STAT_EVEN_MEDIAN_MASK);
  BIND_ENUM_CONSTANT(STAT_DIV_BY_ZERO);
  BIND_ENUM_CONSTANT(STAT_LN_ZERO_ARG);
  BIND_ENUM_CONSTANT(STAT_LN_NEG_ARG);
  BIND_ENUM_CONSTANT(STAT_NAN_ARG);
//  BIND_ENUM_CONSTANT(STAT_RES_FLOOR);
  BIND_ENUM_CONSTANT(STAT_OVERFLOW);
//  BIND_ENUM_CONSTANT(STAT_ZERO_OCC);
  BIND_ENUM_CONSTANT(STAT_UNDERFLOW);
  BIND_ENUM_CONSTANT(STAT_SINGULARITY);
  BIND_ENUM_CONSTANT(STAT_DOMAIN);
//  BIND_ENUM_CONSTANT(STAT_NOT_INTEL_CPU);
  BIND_ENUM_CONSTANT(STAT_CPU_MISMATCH);
//  BIND_ENUM_CONSTANT(STAT_NOT_IPP_FUNCTION_FOUND);
//  BIND_ENUM_CONSTANT(STAT_DLL_NOT_FOUND_BEST_USED);
//  BIND_ENUM_CONSTANT(STAT_NO_OPERTION_IN_DLL);
  BIND_ENUM_CONSTANT(STAT_OVERMUCH_STRINGS);
  BIND_ENUM_CONSTANT(STAT_OVERLONG_STRING);
  BIND_ENUM_CONSTANT(STAT_SRC_SIZE_LESS_EXPECTED);
  BIND_ENUM_CONSTANT(STAT_DST_SIZE_LESS_EXPECTED);
  BIND_ENUM_CONSTANT(STAT_NOT_SUPPORTED_CPU);
//  BIND_ENUM_CONSTANT(STAT_UNKNOWN_CACHE_SIZE);
  BIND_ENUM_CONSTANT(STAT_ALG_TYPE_ERR);
}

