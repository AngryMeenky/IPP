#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::cos_32f_A11(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32f_A11(src->as32f(), dst->as32f(), len));
}


IPP::Status IPP::cos_32f_A21(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32f_A21(src->as32f(), dst->as32f(), len));
}


IPP::Status IPP::cos_32f_A24(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32f_A24(src->as32f(), dst->as32f(), len));
}


IPP::Status IPP::cos_64f_A26(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64f_A26(src->as64f(), dst->as64f(), len));
}


IPP::Status IPP::cos_64f_A50(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64f_A50(src->as64f(), dst->as64f(), len));
}


IPP::Status IPP::cos_64f_A53(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64f_A53(src->as64f(), dst->as64f(), len));
}


IPP::Status IPP::cos_32fc_A11(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32fc_A11(src->as32fc(), dst->as32fc(), len));
}


IPP::Status IPP::cos_32fc_A21(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32fc_A21(src->as32fc(), dst->as32fc(), len));
}


IPP::Status IPP::cos_32fc_A24(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_32fc_A24(src->as32fc(), dst->as32fc(), len));
}


IPP::Status IPP::cos_64fc_A26(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64fc_A26(src->as64fc(), dst->as64fc(), len));
}


IPP::Status IPP::cos_64fc_A50(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64fc_A50(src->as64fc(), dst->as64fc(), len));
}


IPP::Status IPP::cos_64fc_A53(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsCos_64fc_A53(src->as64fc(), dst->as64fc(), len));
}

