#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::mean_32f(const godot::Ref<IppBuffer> &src, int len, Variant mean, Hint hint) {
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


IPP::Status IPP::mean_32fc(const godot::Ref<IppBuffer> &src, int len, Variant mean, Hint hint) {
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


IPP::Status IPP::mean_64f(const godot::Ref<IppBuffer> &src, int len, Variant mean) {
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


IPP::Status IPP::mean_64fc(const godot::Ref<IppBuffer> &src, int len, Variant mean) {
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


IPP::Status IPP::mean_16s_Sfs(const godot::Ref<IppBuffer> &src, int len, Variant mean, int scale) {
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


IPP::Status IPP::mean_32s_Sfs(const godot::Ref<IppBuffer> &src, int len, Variant mean, int scale) {
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


IPP::Status IPP::mean_16sc_Sfs(const godot::Ref<IppBuffer> &src, int len, Variant mean, int scale) {
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

