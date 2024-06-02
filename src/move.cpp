#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::move_8u(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null()) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_8S && st != TYPE_8U) || (dt != TYPE_8S && dt != TYPE_8U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_8u(src->as8u(), dst->as8u(), len));
}


IPP::Status IPP::move_16s(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null()) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_16S && st != TYPE_16U) || (dt != TYPE_16S && dt != TYPE_16U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_16s(src->as16s(), dst->as16s(), len));
}


IPP::Status IPP::move_32s(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null()) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_32S && st != TYPE_32U) || (dt != TYPE_32S && dt != TYPE_32U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_32s(src->as32s(), dst->as32s(), len));
}


IPP::Status IPP::move_64s(const godot::Ref<IppBuffer> &src, const godot::Ref<IppBuffer> &dst, int len) {
  if(src.is_null() || dst.is_null()) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto st = src->getType(), dt = dst->getType();
          (st != TYPE_64S && st != TYPE_64U) || (dt != TYPE_64S && dt != TYPE_64U)) {
    return STAT_BAD_ARG_ERR;
  }

  return static_cast<Status>(ippsMove_64s(src->as64s(), dst->as64s(), len));
}


IPP_OP_I(move_32f, ippsMove_32f, 32F, 32f, 32F, 32f)
IPP_OP_I(move_64f, ippsMove_64f, 64F, 64f, 64F, 64f)
IPP_OP_I(move_16sc, ippsMove_16sc, 16SC, 16sc, 16SC, 16sc)
IPP_OP_I(move_32sc, ippsMove_32sc, 32SC, 32sc, 32SC, 32sc)
IPP_OP_I(move_64sc, ippsMove_64sc, 64SC, 64sc, 64SC, 64sc)
IPP_OP_I(move_32fc, ippsMove_32fc, 32FC, 32fc, 32FC, 32fc)
IPP_OP_I(move_64fc, ippsMove_64fc, 64FC, 64fc, 64FC, 64fc)

