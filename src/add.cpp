#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::addC_32f(const godot::Ref<IppBuffer> &src, float val, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || src->getType() != TYPE_32F || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32F || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32f(src->as32f(), val, dst->as32f(), len));
}


IPP::Status IPP::addC_64f(const godot::Ref<IppBuffer> &src, double val, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || src->getType() != TYPE_64F || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64F || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64f(src->as64f(), val, dst->as64f(), len));
}


IPP::Status IPP::addC_32fc(const godot::Ref<IppBuffer> &src, Vector2 v2, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || src->getType() != TYPE_32FC || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32FC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsAddC_32fc(src->as32fc(), val, dst->as32fc(), len));
}


IPP::Status IPP::addC_64fc(const godot::Ref<IppBuffer> &src, Vector2 v2, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || src->getType() != TYPE_64FC || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64FC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsAddC_64fc(src->as64fc(), val, dst->as64fc(), len));
}


IPP::Status IPP::addC_8u_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale){
  if(src.is_null() || src->getType() != TYPE_8U || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_8U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_8u_Sfs(src->as8u(), val, dst->as8u(), len, scale));
}


IPP::Status IPP::addC_16u_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_16U || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16u_Sfs(src->as16u(), val, dst->as16u(), len, scale));
}


IPP::Status IPP::addC_16s_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_16S || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16s_Sfs(src->as16s(), val, dst->as16s(), len, scale));
}


IPP::Status IPP::addC_32s_Sfs(const godot::Ref<IppBuffer> &src, int val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_32S || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32s_Sfs(src->as32s(), val, dst->as32s(), len, scale));
}


IPP::Status IPP::addC_64s_Sfs(const godot::Ref<IppBuffer> &src, int64_t val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_64S || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64s_Sfs(src->as64s(), val, dst->as64s(), len, scale, static_cast<IppRoundMode>(0)));
}


IPP::Status IPP::addC_64u_Sfs(const godot::Ref<IppBuffer> &src, uint64_t val, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_64U || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64u_Sfs(src->as64u(), val, dst->as64u(), len, scale, static_cast<IppRoundMode>(0)));
}


IPP::Status IPP::addC_16sc_Sfs(const godot::Ref<IppBuffer> &src, Vector2i v2i, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_16SC || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16SC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsAddC_16sc_Sfs(src->as16sc(), val, dst->as16sc(), len, scale));
}


IPP::Status IPP::addC_32sc_Sfs(const godot::Ref<IppBuffer> &src, Vector2i v2i, const godot::Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || src->getType() != TYPE_32SC || src->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32SC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsAddC_32sc_Sfs(src->as32sc(), val, dst->as32sc(), len, scale));
}


IPP::Status IPP::addC_32f_I(float val, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_32F || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32f_I(val, srcDst->as32f(), len));
}


IPP::Status IPP::addC_64f_I(double val, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_64F || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_64f_I(val, srcDst->as64f(), len));
}


IPP::Status IPP::addC_32fc_I(Vector2 v2, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_32FC || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsAddC_32fc_I(val, srcDst->as32fc(), len));
}


IPP::Status IPP::addC_64fc_I(Vector2 v2, const godot::Ref<IppBuffer> &srcDst, int len) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_64FC || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsAddC_64fc_I(val, srcDst->as64fc(), len));
}


IPP::Status IPP::addC_8u_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_8U || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_8u_ISfs(val, srcDst->as8u(), len, scale));
}


IPP::Status IPP::addC_16u_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_16U || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16u_ISfs(val, srcDst->as16u(), len, scale));
}


IPP::Status IPP::addC_16s_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_16S || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_16s_ISfs(val, srcDst->as16s(), len, scale));
}


IPP::Status IPP::addC_32s_ISfs(int val, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_32S || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAddC_32s_ISfs(val, srcDst->as32s(), len, scale));
}


IPP::Status IPP::addC_16sc_ISfs(Vector2i v2i, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_16SC || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsAddC_16sc_ISfs(val, srcDst->as16sc(), len, scale));
}


IPP::Status IPP::addC_32sc_ISfs(Vector2i v2i, const godot::Ref<IppBuffer> &srcDst, int len, int scale) {
  if(srcDst.is_null() || srcDst->getType() != TYPE_32SC || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsAddC_32sc_ISfs(val, srcDst->as32sc(), len, scale));
}


IPP::Status IPP::add_16s(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_16S || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_16S || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16s(lhs->as16s(), rhs->as16s(), dst->as16s(), len));
}


IPP::Status IPP::add_32f(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_32F || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_32F || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32F || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32f(lhs->as32f(), rhs->as32f(), dst->as32f(), len));
}


IPP::Status IPP::add_64f(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_64F || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_64F || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64F || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_64f(lhs->as64f(), rhs->as64f(), dst->as64f(), len));
}



IPP::Status IPP::add_32fc(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_32FC || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_32FC || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32FC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32fc(lhs->as32fc(), rhs->as32fc(), dst->as32fc(), len));
}


IPP::Status IPP::add_64fc(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_64FC || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_64FC || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64FC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_64fc(lhs->as64fc(), rhs->as64fc(), dst->as64fc(), len));
}


IPP::Status IPP::add_8u16u(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_8U  || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_8U  || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_8u16u(lhs->as8u(), rhs->as8u(), dst->as16u(), len));
}


IPP::Status IPP::add_16u(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_16U || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_16U || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16u(lhs->as16u(), rhs->as16u(), dst->as16u(), len));
}


IPP::Status IPP::add_32u(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_32U || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_32U || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32u(lhs->as32u(), rhs->as32u(), dst->as32u(), len));
}


IPP::Status IPP::add_16s32f(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len) {
  if(lhs.is_null() || lhs->getType() != TYPE_16U || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_16U || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32F || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16s32f(lhs->as16s(), rhs->as16s(), dst->as32f(), len));
}


IPP::Status IPP::add_8u_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_8U || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_8U || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_8U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_8u_Sfs(lhs->as8u(), rhs->as8u(), dst->as8u(), len, scale));
}


IPP::Status IPP::add_16u_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_16U || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_16U || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16U || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16u_Sfs(lhs->as16u(), rhs->as16u(), dst->as16u(), len, scale));
}


IPP::Status IPP::add_16s_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_16S || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_16S || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16s_Sfs(lhs->as16s(), rhs->as16s(), dst->as16s(), len, scale));
}


IPP::Status IPP::add_32s_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_32S || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_32S || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32s_Sfs(lhs->as32s(), rhs->as32s(), dst->as32s(), len, scale));
}


IPP::Status IPP::add_16sc_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_16SC || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_16SC || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_16SC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16sc_Sfs(lhs->as16sc(), rhs->as16sc(), dst->as16sc(), len, scale));
}


IPP::Status IPP::add_32sc_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_32SC || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_32SC || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_32SC || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32sc_Sfs(lhs->as32sc(), rhs->as32sc(), dst->as32sc(), len, scale));
}


IPP::Status IPP::add_64s_Sfs(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) {
  if(lhs.is_null() || lhs->getType() != TYPE_64S || lhs->getLength() < len ||
     rhs.is_null() || rhs->getType() != TYPE_64S || rhs->getLength() < len ||
     dst.is_null() || dst->getType() != TYPE_64S || dst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_64s_Sfs(lhs->as64s(), rhs->as64s(), dst->as64s(), len, scale));
}


IPP::Status IPP::add_16s_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_16S || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_16S || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16s_I(src->as16s(), srcDst->as16s(), len));
}


IPP::Status IPP::add_32f_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_32F || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_32F || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32f_I(src->as32f(), srcDst->as32f(), len));
}


IPP::Status IPP::add_64f_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_64F || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_64F || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_64f_I(src->as64f(), srcDst->as64f(), len));
}


IPP::Status IPP::add_32fc_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_32FC || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_32FC || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32fc_I(src->as32fc(), srcDst->as32fc(), len));
}


IPP::Status IPP::add_64fc_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_64FC || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_64FC || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_64fc_I(src->as64fc(), srcDst->as64fc(), len));
}


IPP::Status IPP::add_16s32s_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_16S || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_32S || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16s32s_I(src->as16s(), srcDst->as32s(), len));
}


IPP::Status IPP::add_32u_I(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) {
  if(src.is_null()    || src->getType()    != TYPE_32U || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_32U || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32u_I(src->as32u(), srcDst->as32u(), len));
}


IPP::Status IPP::add_8u_ISfs(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len, int scale) {
  if(src.is_null()    || src->getType()    != TYPE_8U || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_8U || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_8u_ISfs(src->as8u(), srcDst->as8u(), len, scale));
}


IPP::Status IPP::add_16u_ISfs(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len, int scale) {
  if(src.is_null()    || src->getType()    != TYPE_16U || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_16U || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16u_ISfs(src->as16u(), srcDst->as16u(), len, scale));
}


IPP::Status IPP::add_16s_ISfs(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len, int scale) {
  if(src.is_null()    || src->getType()    != TYPE_16S || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_16S || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_16s_ISfs(src->as16s(), srcDst->as16s(), len, scale));
}


IPP::Status IPP::add_32s_ISfs(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len, int scale) {
  if(src.is_null()    || src->getType()    != TYPE_32S || src->getLength()    < len ||
     srcDst.is_null() || srcDst->getType() != TYPE_32S || srcDst->getLength() < len) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsAdd_32s_ISfs(src->as32s(), srcDst->as32s(), len, scale));
}

