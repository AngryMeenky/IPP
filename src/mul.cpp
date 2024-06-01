#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::mulC_32f(const Ref<IppBuffer> &src, float val, const Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_32F || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_32f(src->as32f(), val, dst->as32f(), len));
}


IPP::Status IPP::mulC_64f(const Ref<IppBuffer> &src, double val, const Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_64F || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_64f(src->as64f(), val, dst->as64f(), len));
}


IPP::Status IPP::mulC_32fc(const Ref<IppBuffer> &src, Vector2 v2, const Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_32FC || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsMulC_32fc(src->as32fc(), val, dst->as32fc(), len));
}


IPP::Status IPP::mulC_64fc(const Ref<IppBuffer> &src, Vector2 v2, const Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_64FC || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsMulC_64fc(src->as64fc(), val, dst->as64fc(), len));
}


IPP::Status IPP::mulC_Low_32f16s(const Ref<IppBuffer> &src, float val, const Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_32F || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_Low_32f16s(src->as32f(), val, dst->as16s(), len));
}


IPP::Status IPP::mulC_8u_Sfs(const Ref<IppBuffer> &src, int val, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_8U || dst->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_8u_Sfs(src->as8u(), val, dst->as8u(), len, scale));
}


IPP::Status IPP::mulC_16s_Sfs(const Ref<IppBuffer> &src, int val, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_16S || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_16s_Sfs(src->as16s(), static_cast<Ipp16s>(val), dst->as16s(), len, scale));
}


IPP::Status IPP::mulC_16u_Sfs(const Ref<IppBuffer> &src, int val, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_16U || dst->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_16u_Sfs(src->as16u(), static_cast<Ipp16u>(val), dst->as16u(), len, scale));
}


IPP::Status IPP::mulC_32s_Sfs(const Ref<IppBuffer> &src, int val, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_32S || dst->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_32s_Sfs(src->as32s(), static_cast<Ipp32s>(val), dst->as32s(), len, scale));
}


IPP::Status IPP::mulC_16sc_Sfs(const Ref<IppBuffer> &src, Vector2i v2i, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_16SC || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsMulC_16sc_Sfs(src->as16sc(), val, dst->as16sc(), len, scale));
}


IPP::Status IPP::mulC_32sc_Sfs(const Ref<IppBuffer> &src, Vector2i v2i, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_32SC || dst->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsMulC_32sc_Sfs(src->as32sc(), val, dst->as32sc(), len, scale));
}


IPP::Status IPP::mulC_32f16s_Sfs(const Ref<IppBuffer> &src, float val, const Ref<IppBuffer> &dst, int len, int scale) {
  if(src.is_null() || dst.is_null() || src->getType() != TYPE_32F || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_32f16s_Sfs(src->as32f(), val, dst->as16s(), len, scale));
}


IPP::Status IPP::mulC_16s_I(int val, const Ref<IppBuffer> &buf, int len) {
  if(buf.is_null() || buf->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_16s_I(static_cast<Ipp16s>(val), buf->as16s(), len));
}


IPP::Status IPP::mulC_32f_I(float val, const Ref<IppBuffer> &buf, int len) {
  if(buf.is_null() || buf->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_32f_I(val, buf->as32f(), len));
}


IPP::Status IPP::mulC_64f_I(double val, const Ref<IppBuffer> &buf, int len) {
  if(buf.is_null() || buf->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_64f_I(val, buf->as64f(), len));
}


IPP::Status IPP::mulC_32fc_I(Vector2 v2, const Ref<IppBuffer> &buf, int len) {
  if(buf.is_null() || buf->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32fc val{ static_cast<Ipp32f>(v2.x), static_cast<Ipp32f>(v2.y) };
  return static_cast<Status>(ippsMulC_32fc_I(val, buf->as32fc(), len));
}


IPP::Status IPP::mulC_64fc_I(Vector2 v2, const Ref<IppBuffer> &buf, int len) {
  if(buf.is_null() || buf->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp64fc val{ static_cast<Ipp64f>(v2.x), static_cast<Ipp64f>(v2.y) };
  return static_cast<Status>(ippsMulC_64fc_I(val, buf->as64fc(), len));
}


IPP::Status IPP::mulC_8u_ISfs(int val, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_8U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_8u_ISfs(static_cast<Ipp8u>(val), buf->as8u(), len, scale));
}


IPP::Status IPP::mulC_16u_ISfs(int val, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_16U) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_16u_ISfs(static_cast<Ipp16u>(val), buf->as16u(), len, scale));
}


IPP::Status IPP::mulC_16s_ISfs(int val, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_16s_ISfs(static_cast<Ipp16s>(val), buf->as16s(), len, scale));
}


IPP::Status IPP::mulC_32s_ISfs(int val, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_32S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_32s_ISfs(static_cast<Ipp32s>(val), buf->as32s(), len, scale));
}


IPP::Status IPP::mulC_64f64s_ISfs(double val, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_64f64s_ISfs(val, buf->as64s(), len, scale));
}


IPP::Status IPP::mulC_16sc_ISfs(Vector2i v2i, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp16sc val{ static_cast<Ipp16s>(v2i.x), static_cast<Ipp16s>(v2i.y) };
  return static_cast<Status>(ippsMulC_16sc_ISfs(val, buf->as16sc(), len, scale));
}


IPP::Status IPP::mulC_32sc_ISfs(Vector2i v2i, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_32SC) {
    return STAT_BAD_ARG_ERR;
  }

  Ipp32sc val{ static_cast<Ipp32s>(v2i.x), static_cast<Ipp32s>(v2i.y) };
  return static_cast<Status>(ippsMulC_32sc_ISfs(val, buf->as32sc(), len, scale));
}


IPP::Status IPP::mulC_64s_ISfs(int64_t val, const Ref<IppBuffer> &buf, int len, int scale) {
  if(buf.is_null() || buf->getType() != TYPE_64S) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMulC_64s_ISfs(val, buf->as64s(), len, scale));
}

