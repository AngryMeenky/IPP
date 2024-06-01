#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::addC_32f(const godot::Ref<IppBuffer> &src, float val, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32f(src->as32f(), val, dst->as32f(), len));
}


IPP::Status IPP::addC_64f(const godot::Ref<IppBuffer> &src, double val, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64f(src->as64f(), val, dst->as64f(), len));
}


IPP::Status IPP::addC_32fc(const godot::Ref<IppBuffer> &src, Vector2 v2, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsAddC_32fc(src->as32fc(), val, dst->as32fc(), len));
}


IPP::Status IPP::addC_64fc(const godot::Ref<IppBuffer> &src, Vector2 v2, const godot::Ref<IppBuffer> &dst, int len) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsAddC_64fc(src->as64fc(), val, dst->as64fc(), len));
}


IPP::Status IPP::addC_8u_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale){
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_8U || dst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_8u_Sfs(src->as8u(), val, dst->as8u(), len, scale));
}


IPP::Status IPP::addC_16u_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16U || dst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16u_Sfs(src->as16u(), val, dst->as16u(), len, scale));
}


IPP::Status IPP::addC_16s_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16S || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16s_Sfs(src->as16s(), val, dst->as16s(), len, scale));
}


IPP::Status IPP::addC_32s_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32S || dst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32s_Sfs(src->as32s(), val, dst->as32s(), len, scale));
}


IPP::Status IPP::addC_64s_Sfs(const godot::Ref<IppBuffer> &src, int64_t val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64S || dst->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64s_Sfs(src->as64s(), val, dst->as64s(), len, scale, static_cast<IppRoundMode>(0)));
}


IPP::Status IPP::addC_64u_Sfs(const godot::Ref<IppBuffer> &src, uint64_t val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_64U || dst->getType() != TYPE_64U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64u_Sfs(src->as64u(), val, dst->as64u(), len, scale, static_cast<IppRoundMode>(0)));
}


IPP::Status IPP::addC_16sc_Sfs(const godot::Ref<IppBuffer> &src, Vector2i v2i, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsAddC_16sc_Sfs(src->as16sc(), val, dst->as16sc(), len, scale));
}


IPP::Status IPP::addC_32sc_Sfs(const godot::Ref<IppBuffer> &src, Vector2i v2i, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src == nullptr || dst == nullptr || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsAddC_32sc_Sfs(src->as32sc(), val, dst->as32sc(), len, scale));
}


IPP::Status IPP::addC_32f_I(float val, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32f_I(val, srcDst->as32f(), len));
}


IPP::Status IPP::addC_64f_I(double val, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64f_I(val, srcDst->as64f(), len));
}


IPP::Status IPP::addC_32fc_I(Vector2 v2, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsAddC_32fc_I(val, srcDst->as32fc(), len));
}


IPP::Status IPP::addC_64fc_I(Vector2 v2, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsAddC_64fc_I(val, srcDst->as64fc(), len));
}


IPP::Status IPP::addC_8u_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_8u_ISfs(val, srcDst->as8u(), len, scale));
}


IPP::Status IPP::addC_16u_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16u_ISfs(val, srcDst->as16u(), len, scale));
}


IPP::Status IPP::addC_16s_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16s_ISfs(val, srcDst->as16s(), len, scale));
}


IPP::Status IPP::addC_32s_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32s_ISfs(val, srcDst->as32s(), len, scale));
}


IPP::Status IPP::addC_16sc_ISfs(Vector2i v2i, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsAddC_16sc_ISfs(val, srcDst->as16sc(), len, scale));
}


IPP::Status IPP::addC_32sc_ISfs(Vector2i v2i, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst == nullptr || srcDst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsAddC_32sc_ISfs(val, srcDst->as32sc(), len, scale));
}

