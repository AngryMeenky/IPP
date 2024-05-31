#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::move_8u(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_8S && st != TYPE_8U) || (dt != TYPE_8S && dt != TYPE_8U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_8u(src->as8u(), dst->as8u(), len));
}


IPP::Status IPP::move_16s(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_16S && st != TYPE_16U) || (dt != TYPE_16S && dt != TYPE_16U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_16s(src->as16s(), dst->as16s(), len));
}


IPP::Status IPP::move_32s(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_32S && st != TYPE_32U) || (dt != TYPE_32S && dt != TYPE_32U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32s(src->as32s(), dst->as32s(), len));
}


IPP::Status IPP::move_64s(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || dst->getType() != TYPE_64S || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64s(src->as64s(), dst->as64s(), len));
}


IPP::Status IPP::move_32f(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32f(src->as32f(), dst->as32f(), len));
}


IPP::Status IPP::move_64f(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64f(src->as64f(), dst->as64f(), len));
}


IPP::Status IPP::move_16sc(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_16sc(src->as16sc(), dst->as16sc(), len));
}


IPP::Status IPP::move_32sc(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32sc(src->as32sc(), dst->as32sc(), len));
}


IPP::Status IPP::move_64sc(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64SC || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64sc(src->as64sc(), dst->as64sc(), len));
}


IPP::Status IPP::move_32fc(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32fc(src->as32fc(), dst->as32fc(), len));
}


IPP::Status IPP::move_64fc(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64fc(src->as64fc(), dst->as64fc(), len));
}

