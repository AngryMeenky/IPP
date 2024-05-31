#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP::Status IPP::triangle_16s(const godot::Ref<IppBuffer> &dst, int len, int mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_16S) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_16s(dst->as16s(), len, static_cast<Ipp16s>(mag), freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_16s(dst->as16s(), len, static_cast<Ipp16s>(mag), freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


IPP::Status IPP::triangle_32f(const godot::Ref<IppBuffer> &dst, int len, float mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_32F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_32f(dst->as32f(), len, mag, freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_32f(dst->as32f(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


IPP::Status IPP::triangle_64f(const godot::Ref<IppBuffer> &dst, int len, double mag, double freq, double asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_64F) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = static_cast<double>(arr[0].operator float());
      auto retVal = ippsTriangle_64f(dst->as64f(), len, mag, freq, asym, &phi);
      arr[0] = Variant(static_cast<float>(phi));
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      auto phi = static_cast<double>(arr[0]);
      auto retVal = ippsTriangle_64f(dst->as64f(), len, mag, freq, asym, &phi);
      arr[0] = static_cast<float>(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT64_ARRAY) {
    auto arr = phase.operator PackedFloat64Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_64f(dst->as64f(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


IPP::Status IPP::triangle_16sc(const godot::Ref<IppBuffer> &dst, int len, int mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_16SC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_16sc(dst->as16sc(), len, mag, freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_16sc(dst->as16sc(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


IPP::Status IPP::triangle_32fc(const godot::Ref<IppBuffer> &dst, int len, float mag, float freq, float asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_32FC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = arr[0].operator float();
      auto retVal = ippsTriangle_32fc(dst->as32fc(), len, mag, freq, asym, &phi);
      arr[0] = Variant(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_32fc(dst->as32fc(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}


IPP::Status IPP::triangle_64fc(const godot::Ref<IppBuffer> &dst, int len, double mag, double freq, double asym, Variant phase) {
  if(dst == nullptr || dst->getType() != TYPE_64FC) {
    return STAT_BAD_ARG_ERR;
  }
  else if(auto type = phase.get_type(); type == Variant::ARRAY) {
    auto arr = phase.operator Array();
    if(arr.size() >= 1 && arr[0].get_type() == Variant::FLOAT) {
      auto phi = static_cast<double>(arr[0].operator float());
      auto retVal = ippsTriangle_64fc(dst->as64fc(), len, mag, freq, asym, &phi);
      arr[0] = Variant(static_cast<float>(phi));
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT32_ARRAY) {
    auto arr = phase.operator PackedFloat32Array();
    if(arr.size() >= 1) {
      auto phi = static_cast<double>(arr[0]);
      auto retVal = ippsTriangle_64fc(dst->as64fc(), len, mag, freq, asym, &phi);
      arr[0] = static_cast<float>(phi);
      return static_cast<Status>(retVal);
    }
  }
  else if(type != Variant::PACKED_FLOAT64_ARRAY) {
    auto arr = phase.operator PackedFloat64Array();
    if(arr.size() >= 1) {
      return static_cast<Status>(ippsTriangle_64fc(dst->as64fc(), len, mag, freq, asym, &arr[0]));
    }
  }

  return STAT_BAD_ARG_ERR;
}

