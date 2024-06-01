#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::sin_cos_32f_A11(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &s, const godot::Ref<IppBuffer> &c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_32F || s->getType() != TYPE_32F || c->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_32f_A11(src->as32f(), s->as32f(), c->as32f(), len));
}


IPP::Status IPP::sin_cos_32f_A21(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &s, const godot::Ref<IppBuffer> &c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_32F || s->getType() != TYPE_32F || c->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_32f_A21(src->as32f(), s->as32f(), c->as32f(), len));
}


IPP::Status IPP::sin_cos_32f_A24(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &s, const godot::Ref<IppBuffer> &c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_32F || s->getType() != TYPE_32F || c->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_32f_A24(src->as32f(), s->as32f(), c->as32f(), len));
}


IPP::Status IPP::sin_cos_64f_A26(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &s, const godot::Ref<IppBuffer> &c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_64F || s->getType() != TYPE_64F || c->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_64f_A26(src->as64f(), s->as64f(), c->as64f(), len));
}


IPP::Status IPP::sin_cos_64f_A50(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &s, const godot::Ref<IppBuffer> &c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_64F || s->getType() != TYPE_64F || c->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_64f_A50(src->as64f(), s->as64f(), c->as64f(), len));
}


IPP::Status IPP::sin_cos_64f_A53(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &s, const godot::Ref<IppBuffer> &c, int len) {
  if(src            == nullptr  || s            == nullptr  || c            == nullptr  ||
     src->getType() != TYPE_64F || s->getType() != TYPE_64F || c->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsSinCos_64f_A53(src->as64f(), s->as64f(), c->as64f(), len));
}

