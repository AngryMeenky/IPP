#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::zero_8u(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_8S && dst->getType() != TYPE_8U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_8u(dst->as8u(), len));
}


IPP::Status IPP::zero_16s(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_16S && dst->getType() != TYPE_16U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_16s(dst->as16s(), len));
}


IPP::Status IPP::zero_32s(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_32S && dst->getType() != TYPE_32U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32s(dst->as32s(), len));
}


IPP::Status IPP::zero_64s(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || (dst->getType() != TYPE_64S && dst->getType() != TYPE_64U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64s(dst->as64s(), len));
}


IPP::Status IPP::zero_32f(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32f(dst->as32f(), len));
}


IPP::Status IPP::zero_64f(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64f(dst->as64f(), len));
}


IPP::Status IPP::zero_16sc(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_16sc(dst->as16sc(), len));
}


IPP::Status IPP::zero_32sc(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32sc(dst->as32sc(), len));
}


IPP::Status IPP::zero_64sc(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64sc(dst->as64sc(), len));
}


IPP::Status IPP::zero_32fc(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_32fc(dst->as32fc(), len));
}


IPP::Status IPP::zero_64fc(const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsZero_64fc(dst->as64fc(), len));
}

