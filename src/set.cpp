#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::set_8u(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
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


IPP::Status IPP::set_16s(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
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


IPP::Status IPP::set_32s(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
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


IPP::Status IPP::set_64s(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_64s(var.operator int64_t(), dst->as64s(), len));
}


IPP::Status IPP::set_32f(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_32f(var.operator float(), dst->as32f(), len));
}


IPP::Status IPP::set_64f(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() == Variant::NIL || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = var.get_type(); type != Variant::INT && type != Variant::FLOAT) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSet_64f(var.operator double(), dst->as64f(), len));
}


IPP::Status IPP::set_16sc(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2I || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2i = var.operator Vector2i();
  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsSet_16sc(val, dst->as16sc(), len));
}


IPP::Status IPP::set_32sc(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2I || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2i = var.operator Vector2i();
  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsSet_32sc(val, dst->as32sc(), len));
}


IPP::Status IPP::set_64sc(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2I || dst->getType() != TYPE_64SC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2i = var.operator Vector2i();
  Ipp64sc val{ static_cast<Ipp64s>(v2i.x), static_cast<Ipp64s>(v2i.y) };
  return static_cast<Status>(ippsSet_64sc(val, dst->as64sc(), len));
}


IPP::Status IPP::set_32fc(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2 || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2 = var.operator Vector2();
  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsSet_32fc(val, dst->as32fc(), len));
}


IPP::Status IPP::set_64fc(Variant var, const godot::Ref<IppBuffer> &dst, int len) {
  if(dst == nullptr || var.get_type() != Variant::VECTOR2 || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  auto v2 = var.operator Vector2();
  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsSet_64fc(val, dst->as64fc(), len));
}

