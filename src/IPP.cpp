#include "IPP.h"
#include "fft.h"
#include "rand.h"
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
  "Ipp32u", "Ipp32s", "Ipp64u", "Ipp64s",
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

  return static_cast<Status>(ippsSet_8u(static_cast<Ipp8u>(var.operator int32_t()), dst->as8u(), len));
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

  return static_cast<Status>(ippsSet_16s(static_cast<Ipp16s>(var.operator int32_t()), dst->as16s(), len));
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


ipp::IPP::Status ipp::IPP::cos_32f_A11(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32f_A11(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::cos_32f_A21(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32f_A21(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::cos_32f_A24(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32f_A24(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::cos_64f_A26(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64f_A26(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::cos_64f_A50(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64f_A50(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::cos_64f_A53(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64f_A53(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::cos_32fc_A11(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32fc_A11(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::cos_32fc_A21(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32fc_A21(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::cos_32fc_A24(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32fc_A24(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::cos_64fc_A26(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64fc_A26(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::cos_64fc_A50(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64fc_A50(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::cos_64fc_A53(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64fc_A53(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_32f_A11(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_32f_A11(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::sin_32f_A21(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_32f_A21(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::sin_32f_A24(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_32f_A24(src->as32f(), dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::sin_64f_A26(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_64f_A26(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::sin_64f_A50(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_64f_A50(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::sin_64f_A53(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_64f_A53(src->as64f(), dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::sin_32fc_A11(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_32fc_A11(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_32fc_A21(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_32fc_A21(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_32fc_A24(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_32fc_A24(src->as32fc(), dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_64fc_A26(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_64fc_A26(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_64fc_A50(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_64fc_A50(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_64fc_A53(const IppBuffer *src, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSin_64fc_A53(src->as64fc(), dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::sin_cos_32f_A11(const IppBuffer *src, IppBuffer *s, IppBuffer *c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_32F || s->getType() != TYPE_32F || c->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_32f_A11(src->as32f(), s->as32f(), c->as32f(), len));
}


ipp::IPP::Status ipp::IPP::sin_cos_32f_A21(const IppBuffer *src, IppBuffer *s, IppBuffer *c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_32F || s->getType() != TYPE_32F || c->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_32f_A21(src->as32f(), s->as32f(), c->as32f(), len));
}


ipp::IPP::Status ipp::IPP::sin_cos_32f_A24(const IppBuffer *src, IppBuffer *s, IppBuffer *c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_32F || s->getType() != TYPE_32F || c->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_32f_A24(src->as32f(), s->as32f(), c->as32f(), len));
}


ipp::IPP::Status ipp::IPP::sin_cos_64f_A26(const IppBuffer *src, IppBuffer *s, IppBuffer *c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_64F || s->getType() != TYPE_64F || c->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_64f_A26(src->as64f(), s->as64f(), c->as64f(), len));
}


ipp::IPP::Status ipp::IPP::sin_cos_64f_A50(const IppBuffer *src, IppBuffer *s, IppBuffer *c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_64F || s->getType() != TYPE_64F || c->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_64f_A50(src->as64f(), s->as64f(), c->as64f(), len));
}


ipp::IPP::Status ipp::IPP::sin_cos_64f_A53(const IppBuffer *src, IppBuffer *s, IppBuffer *c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_64F || s->getType() != TYPE_64F || c->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_64f_A53(src->as64f(), s->as64f(), c->as64f(), len));
}


ipp::IPP::Status ipp::IPP::addC_32f(const IppBuffer *src, float val, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32f(src->as32f(), val, dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::addC_64f(const IppBuffer *src, double val, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64f(src->as64f(), val, dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::addC_32fc(const IppBuffer *src, Vector2 v2, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsAddC_32fc(src->as32fc(), val, dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::addC_64fc(const IppBuffer *src, Vector2 v2, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsAddC_64fc(src->as64fc(), val, dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::addC_8u_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale){
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_8U || dst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_8u_Sfs(src->as8u(), val, dst->as8u(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_16u_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16U || dst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16u_Sfs(src->as16u(), val, dst->as16u(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_16s_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16S || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16s_Sfs(src->as16s(), val, dst->as16s(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_32s_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32S || dst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32s_Sfs(src->as32s(), val, dst->as32s(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_64s_Sfs(const IppBuffer *src, int64_t val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64S || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64s_Sfs(src->as64s(), val, dst->as64s(), len, scale, static_cast<IppRoundMode>(0)));
}


ipp::IPP::Status ipp::IPP::addC_64u_Sfs(const IppBuffer *src, uint64_t val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64U || dst->getType() != TYPE_64U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64u_Sfs(src->as64u(), val, dst->as64u(), len, scale, static_cast<IppRoundMode>(0)));
}


ipp::IPP::Status ipp::IPP::addC_16sc_Sfs(const IppBuffer *src, Vector2i v2i, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsAddC_16sc_Sfs(src->as16sc(), val, dst->as16sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_32sc_Sfs(const IppBuffer *src, Vector2i v2i, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsAddC_32sc_Sfs(src->as32sc(), val, dst->as32sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_32f_I(float val, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32f_I(val, srcDst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::addC_64f_I(double val, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64f_I(val, srcDst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::addC_32fc_I(Vector2 v2, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsAddC_32fc_I(val, srcDst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::addC_64fc_I(Vector2 v2, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsAddC_64fc_I(val, srcDst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::addC_8u_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_8u_ISfs(val, srcDst->as8u(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_16u_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16u_ISfs(val, srcDst->as16u(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_16s_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16s_ISfs(val, srcDst->as16s(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_32s_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32s_ISfs(val, srcDst->as32s(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_16sc_ISfs(Vector2i v2i, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsAddC_16sc_ISfs(val, srcDst->as16sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::addC_32sc_ISfs(Vector2i v2i, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsAddC_32sc_ISfs(val, srcDst->as32sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_32f(const IppBuffer *src, float val, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_32f(src->as32f(), val, dst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::subC_64f(const IppBuffer *src, double val, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_64f(src->as64f(), val, dst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::subC_32fc(const IppBuffer *src, Vector2 v2, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsSubC_32fc(src->as32fc(), val, dst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::subC_64fc(const IppBuffer *src, Vector2 v2, IppBuffer *dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsSubC_64fc(src->as64fc(), val, dst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::subC_8u_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale){
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_8U || dst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_8u_Sfs(src->as8u(), val, dst->as8u(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_16u_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16U || dst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_16u_Sfs(src->as16u(), val, dst->as16u(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_16s_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16S || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_16s_Sfs(src->as16s(), val, dst->as16s(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_32s_Sfs(const IppBuffer *src, int val, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32S || dst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_32s_Sfs(src->as32s(), val, dst->as32s(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_16sc_Sfs(const IppBuffer *src, Vector2i v2i, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsSubC_16sc_Sfs(src->as16sc(), val, dst->as16sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_32sc_Sfs(const IppBuffer *src, Vector2i v2i, IppBuffer *dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsSubC_32sc_Sfs(src->as32sc(), val, dst->as32sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_32f_I(float val, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_32f_I(val, srcDst->as32f(), len));
}


ipp::IPP::Status ipp::IPP::subC_64f_I(double val, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_64f_I(val, srcDst->as64f(), len));
}


ipp::IPP::Status ipp::IPP::subC_32fc_I(Vector2 v2, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsSubC_32fc_I(val, srcDst->as32fc(), len));
}


ipp::IPP::Status ipp::IPP::subC_64fc_I(Vector2 v2, IppBuffer *srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsSubC_64fc_I(val, srcDst->as64fc(), len));
}


ipp::IPP::Status ipp::IPP::subC_8u_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_8u_ISfs(val, srcDst->as8u(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_16u_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_16u_ISfs(val, srcDst->as16u(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_16s_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_16s_ISfs(val, srcDst->as16s(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_32s_ISfs(int val, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSubC_32s_ISfs(val, srcDst->as32s(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_16sc_ISfs(Vector2i v2i, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsSubC_16sc_ISfs(val, srcDst->as16sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::subC_32sc_ISfs(Vector2i v2i, IppBuffer *srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsSubC_32sc_ISfs(val, srcDst->as32sc(), len, scale));
}


ipp::IPP::Status ipp::IPP::sum_32f(const IppBuffer *src, int len, Variant sum, Hint hint) {
  if(src == nullptr || src->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp32f dst = 0;
    auto retVal = ippsSum_32f(src->as32f(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_FLOAT32_ARRAY) {
    Ipp32f dst = 0;
    auto retVal = ippsSum_32f(src->as32f(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator PackedFloat32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_32fc(const IppBuffer *src, int len, Variant sum, Hint hint) {
  if(src == nullptr || src->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp32fc dst{ 0.0f, 0.0f };
    auto retVal = ippsSum_32fc(src->as32fc(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_VECTOR2_ARRAY) {
    Ipp32fc dst{ 0.0f, 0.0f };
    auto retVal = ippsSum_32fc(src->as32fc(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = sum.operator PackedVector2Array(); arr.size() >= 1) {
        arr[0] = result;
      }
      else {
        arr.append(result);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_64f(const IppBuffer *src, int len, Variant sum) {
  if(src == nullptr || src->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp64f dst = 0;
    auto retVal = ippsSum_64f(src->as64f(), len, &dst);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_FLOAT32_ARRAY) {
    Ipp64f dst = 0;
    auto retVal = ippsSum_64f(src->as64f(), len, &dst);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator PackedFloat32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_FLOAT64_ARRAY) {
    Ipp64f dst = 0;
    auto retVal = ippsSum_64f(src->as64f(), len, &dst);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator PackedFloat64Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_64fc(const IppBuffer *src, int len, Variant sum) {
  if(src == nullptr || src->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp64fc dst{ 0.0f, 0.0f };
    auto retVal = ippsSum_64fc(src->as64fc(), len, &dst);

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_VECTOR2_ARRAY) {
    Ipp64fc dst{ 0.0f, 0.0f };
    auto retVal = ippsSum_64fc(src->as64fc(), len, &dst);

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = sum.operator PackedVector2Array(); arr.size() >= 1) {
        arr[0] = result;
      }
      else {
        arr.append(result);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_16s_Sfs(const IppBuffer *src, int len, Variant sum, int scale) {
  if(src == nullptr || src->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp16s dst = 0;
    auto retVal = ippsSum_16s_Sfs(src->as16s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_INT32_ARRAY) {
    Ipp16s dst = 0;
    auto retVal = ippsSum_16s_Sfs(src->as16s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator PackedInt32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_32s_Sfs(const IppBuffer *src, int len, Variant sum, int scale) {
  if(src == nullptr || src->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp32s dst = 0;
    auto retVal = ippsSum_32s_Sfs(src->as32s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_INT32_ARRAY) {
    Ipp32s dst = 0;
    auto retVal = ippsSum_32s_Sfs(src->as32s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator PackedInt32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_16s32s_Sfs(const IppBuffer *src, int len, Variant sum, int scale) {
  if(src == nullptr || src->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp32s dst = 0;
    auto retVal = ippsSum_16s32s_Sfs(src->as16s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_INT32_ARRAY) {
    Ipp32s dst = 0;
    auto retVal = ippsSum_16s32s_Sfs(src->as16s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = sum.operator PackedInt32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_16sc_Sfs(const IppBuffer *src, int len, Variant sum, int scale) {
  if(src == nullptr || src->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp16sc dst{ 0, 0 };
    auto retVal = ippsSum_16sc_Sfs(src->as16sc(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      Vector2i result(dst.re, dst.im);

      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::sum_16sc32sc_Sfs(const IppBuffer *src, int len, Variant sum, int scale) {
  if(src == nullptr || src->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = sum.get_type(); st == Variant::ARRAY) {
    Ipp32sc dst{ 0, 0 };
    auto retVal = ippsSum_16sc32sc_Sfs(src->as16sc(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      Vector2i result(dst.re, dst.im);

      if(auto arr = sum.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_32f(const IppBuffer *src, int len, Variant mean, Hint hint) {
  if(src == nullptr || src->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp32f dst = 0;
    auto retVal = ippsMean_32f(src->as32f(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_FLOAT32_ARRAY) {
    Ipp32f dst = 0;
    auto retVal = ippsMean_32f(src->as32f(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator PackedFloat32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_32fc(const IppBuffer *src, int len, Variant mean, Hint hint) {
  if(src == nullptr || src->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp32fc dst{ 0.0f, 0.0f };
    auto retVal = ippsMean_32fc(src->as32fc(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_VECTOR2_ARRAY) {
    Ipp32fc dst{ 0.0f, 0.0f };
    auto retVal = ippsMean_32fc(src->as32fc(), len, &dst, static_cast<IppHintAlgorithm>(hint));

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = mean.operator PackedVector2Array(); arr.size() >= 1) {
        arr[0] = result;
      }
      else {
        arr.append(result);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_64f(const IppBuffer *src, int len, Variant mean) {
  if(src == nullptr || src->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp64f dst = 0;
    auto retVal = ippsMean_64f(src->as64f(), len, &dst);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_FLOAT32_ARRAY) {
    Ipp64f dst = 0;
    auto retVal = ippsMean_64f(src->as64f(), len, &dst);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator PackedFloat32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_FLOAT64_ARRAY) {
    Ipp64f dst = 0;
    auto retVal = ippsMean_64f(src->as64f(), len, &dst);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator PackedFloat64Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_64fc(const IppBuffer *src, int len, Variant mean) {
  if(src == nullptr || src->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp64fc dst{ 0.0f, 0.0f };
    auto retVal = ippsMean_64fc(src->as64fc(), len, &dst);

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_VECTOR2_ARRAY) {
    Ipp64fc dst{ 0.0f, 0.0f };
    auto retVal = ippsMean_64fc(src->as64fc(), len, &dst);

    if(retVal == ippStsNoErr) {
      Vector2 result(dst.re, dst.im);

      if(auto arr = mean.operator PackedVector2Array(); arr.size() >= 1) {
        arr[0] = result;
      }
      else {
        arr.append(result);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_16s_Sfs(const IppBuffer *src, int len, Variant mean, int scale) {
  if(src == nullptr || src->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp16s dst = 0;
    auto retVal = ippsMean_16s_Sfs(src->as16s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_INT32_ARRAY) {
    Ipp16s dst = 0;
    auto retVal = ippsMean_16s_Sfs(src->as16s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator PackedInt32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_32s_Sfs(const IppBuffer *src, int len, Variant mean, int scale) {
  if(src == nullptr || src->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp32s dst = 0;
    auto retVal = ippsMean_32s_Sfs(src->as32s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(dst);
      }
      else {
        arr.append(Variant(dst));
      }
    }

    return static_cast<Status>(retVal);
  }
  else if(st == Variant::PACKED_INT32_ARRAY) {
    Ipp32s dst = 0;
    auto retVal = ippsMean_32s_Sfs(src->as32s(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      if(auto arr = mean.operator PackedInt32Array(); arr.size() >= 1) {
        arr[0] = dst;
      }
      else {
        arr.append(dst);
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IPP::Status ipp::IPP::mean_16sc_Sfs(const IppBuffer *src, int len, Variant mean, int scale) {
  if(src == nullptr || src->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  if(auto st = mean.get_type(); st == Variant::ARRAY) {
    Ipp16sc dst{ 0, 0 };
    auto retVal = ippsMean_16sc_Sfs(src->as16sc(), len, &dst, scale);

    if(retVal == ippStsNoErr) {
      Vector2i result(dst.re, dst.im);

      if(auto arr = mean.operator Array(); arr.size() >= 1) {
        arr[0] = Variant(result);
      }
      else {
        arr.append(Variant(result));
      }
    }

    return static_cast<Status>(retVal);
  }

  return STAT_BAD_ARG_ERR;
}


ipp::IppRandom *ipp::IPP::uniform_init_8u(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_8U, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::uniform_init_16s(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_16S, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::uniform_init_32f(float low, float high, int64_t seed) {
  return new IppRandom(IPP::TYPE_32F, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::uniform_init_64f(double low, double high, int64_t seed) {
  return new IppRandom(IPP::TYPE_64F, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::gauss_init_8u(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_8U, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::gauss_init_16s(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_16S, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::gauss_init_32f(float low, float high, int64_t seed) {
  return new IppRandom(IPP::TYPE_32F, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


ipp::IppRandom *ipp::IPP::gauss_init_64f(double low, double high, int64_t seed) {
  return new IppRandom(IPP::TYPE_64F, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
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
  
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32f_A11", "src", "dst", "len"), &IPP::cos_32f_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32f_A21", "src", "dst", "len"), &IPP::cos_32f_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32f_A24", "src", "dst", "len"), &IPP::cos_32f_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64f_A26", "src", "dst", "len"), &IPP::cos_64f_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64f_A50", "src", "dst", "len"), &IPP::cos_64f_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64f_A53", "src", "dst", "len"), &IPP::cos_64f_A53);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32fc_A11", "src", "dst", "len"), &IPP::cos_32fc_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32fc_A21", "src", "dst", "len"), &IPP::cos_32fc_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32fc_A24", "src", "dst", "len"), &IPP::cos_32fc_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64fc_A26", "src", "dst", "len"), &IPP::cos_64fc_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64fc_A50", "src", "dst", "len"), &IPP::cos_64fc_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64fc_A53", "src", "dst", "len"), &IPP::cos_64fc_A53);
  
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32f_A11", "src", "dst", "len"), &IPP::sin_32f_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32f_A21", "src", "dst", "len"), &IPP::sin_32f_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32f_A24", "src", "dst", "len"), &IPP::sin_32f_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64f_A26", "src", "dst", "len"), &IPP::sin_64f_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64f_A50", "src", "dst", "len"), &IPP::sin_64f_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64f_A53", "src", "dst", "len"), &IPP::sin_64f_A53);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32fc_A11", "src", "dst", "len"), &IPP::sin_32fc_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32fc_A21", "src", "dst", "len"), &IPP::sin_32fc_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32fc_A24", "src", "dst", "len"), &IPP::sin_32fc_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64fc_A26", "src", "dst", "len"), &IPP::sin_64fc_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64fc_A50", "src", "dst", "len"), &IPP::sin_64fc_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64fc_A53", "src", "dst", "len"), &IPP::sin_64fc_A53);
  
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_32f_A11", "src", "sine", "cosine", "len"), &IPP::sin_cos_32f_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_32f_A21", "src", "sine", "cosine", "len"), &IPP::sin_cos_32f_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_32f_A24", "src", "sine", "cosine", "len"), &IPP::sin_cos_32f_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_64f_A26", "src", "sine", "cosine", "len"), &IPP::sin_cos_64f_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_64f_A50", "src", "sine", "cosine", "len"), &IPP::sin_cos_64f_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_64f_A53", "src", "sine", "cosine", "len"), &IPP::sin_cos_64f_A53);

  ClassDB::bind_static_method("IPP", D_METHOD("addC_32f", "src", "val", "dst", "len"), &IPP::addC_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64f", "src", "val", "dst", "len"), &IPP::addC_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32fc", "src", "val", "dst", "len"), &IPP::addC_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64fc", "src", "val", "dst", "len"), &IPP::addC_64fc);
  
  ClassDB::bind_static_method("IPP", D_METHOD("addC_8u_Sfs", "src", "val", "dst", "len"), &IPP::addC_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16u_Sfs", "src", "val", "dst", "len"), &IPP::addC_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16s_Sfs", "src", "val", "dst", "len"), &IPP::addC_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32s_Sfs", "src", "val", "dst", "len"), &IPP::addC_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64u_Sfs", "src", "val", "dst", "len"), &IPP::addC_64u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64s_Sfs", "src", "val", "dst", "len"), &IPP::addC_64s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16sc_Sfs", "src", "val", "dst", "len"), &IPP::addC_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32sc_Sfs", "src", "val", "dst", "len"), &IPP::addC_32sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("addC_32f_I", "val", "src_dst", "len"), &IPP::addC_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64f_I", "val", "src_dst", "len"), &IPP::addC_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32fc_I", "val", "src_dst", "len"), &IPP::addC_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64fc_I", "val", "src_dst", "len"), &IPP::addC_64fc_I);
  
  ClassDB::bind_static_method("IPP", D_METHOD("addC_8u_ISfs", "val", "src_dst", "len"), &IPP::addC_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16u_ISfs", "val", "src_dst", "len"), &IPP::addC_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16s_ISfs", "val", "src_dst", "len"), &IPP::addC_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32s_ISfs", "val", "src_dst", "len"), &IPP::addC_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16sc_ISfs", "val", "src_dst", "len"), &IPP::addC_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32sc_ISfs", "val", "src_dst", "len"), &IPP::addC_32sc_ISfs);
  
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_8u", "low", "high", "seed"), &IPP::uniform_init_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_16s", "low", "high", "seed"), &IPP::uniform_init_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_32f", "low", "high", "seed"), &IPP::uniform_init_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_64f", "low", "high", "seed"), &IPP::uniform_init_64f);
  
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_8u", "low", "high", "seed"), &IPP::gauss_init_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_16s", "low", "high", "seed"), &IPP::gauss_init_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_32f", "low", "high", "seed"), &IPP::gauss_init_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_64f", "low", "high", "seed"), &IPP::gauss_init_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_32f", "order", "flag"), &IPP::fft_init_C_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_64f", "order", "flag"), &IPP::fft_init_C_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_32fc", "order", "flag"), &IPP::fft_init_C_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_64fc", "order", "flag"), &IPP::fft_init_C_64fc);
  

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

