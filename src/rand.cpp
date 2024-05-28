#include "rand.h"

#ifdef GDEXTENSION
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/core/class_db.hpp>

#else
#include "core/object/class_db.h"
#include "core/os/memory.h"
#include "core/os/os.h"
#endif


using namespace ipp;
using namespace godot;


IppRandom::IppRandom(): IppRandom(IPP::TYPE_32F, DIST_NONE, 0.0, 0.0, 0xFFFFFFFFU) {}


IppRandom::IppRandom(IPP::Type t, Distribution d, int low, int high, unsigned seed):
  state(nullptr),
  dist(d),
  type(t),
  lo(low),
  hi(high) {
  IppStatus result = ippStsErr;

  if(t == IPP::TYPE_8U) {
    if(d == DIST_UNIFORM) {
      int size;
      if((result = ippsRandUniformGetSize_8u(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandUniformInit_8u(reinterpret_cast<IppsRandUniState_8u *>(state), low, high, seed);
	}
      }
    }
    else if(d == DIST_GAUSSIAN) {
      int size;
      if((result = ippsRandGaussGetSize_8u(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandGaussInit_8u(reinterpret_cast<IppsRandGaussState_8u *>(state), low, high, seed);
	}
      }
    }
  }
  else if(t == IPP::TYPE_16S) {
    if(d == DIST_UNIFORM) {
      int size;
      if((result = ippsRandUniformGetSize_16s(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandUniformInit_16s(reinterpret_cast<IppsRandUniState_16s *>(state), low, high, seed);
	}
      }
    }
    else if(d == DIST_GAUSSIAN) {
      int size;
      if((result = ippsRandGaussGetSize_16s(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandGaussInit_16s(reinterpret_cast<IppsRandGaussState_16s *>(state), low, high, seed);
	}
      }
    }
  }

  if(result != ippStsNoErr) {
    if(state != nullptr) {
      ippsFree(state);
      state = nullptr;
    }

    dist = DIST_NONE;
  }
}


IppRandom::IppRandom(IPP::Type t, Distribution d, double low, double high, unsigned seed):
  state(nullptr),
  dist(d),
  type(t),
  lo(low),
  hi(high) {
  IppStatus result = ippStsErr;

  if(t == IPP::TYPE_32F) {
    if(d == DIST_UNIFORM) {
      int size;
      if((result = ippsRandUniformGetSize_32f(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandUniformInit_32f(reinterpret_cast<IppsRandUniState_32f *>(state), low, high, seed);
	}
      }
    }
    else if(d == DIST_GAUSSIAN) {
      int size;
      if((result = ippsRandGaussGetSize_32f(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandGaussInit_32f(reinterpret_cast<IppsRandGaussState_32f *>(state), low, high, seed);
	}
      }
    }
  }
  else if(t == IPP::TYPE_64F) {
    if(d == DIST_UNIFORM) {
      int size;
      if((result = ippsRandUniformGetSize_64f(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandUniformInit_64f(reinterpret_cast<IppsRandUniState_64f *>(state), low, high, seed);
	}
      }
    }
    else if(d == DIST_GAUSSIAN) {
      int size;
      if((result = ippsRandGaussGetSize_64f(&size)) == ippStsNoErr) {
        if((state = ippsMalloc_8u(size)) != nullptr) {
          result = ippsRandGaussInit_64f(reinterpret_cast<IppsRandGaussState_64f *>(state), low, high, seed);
	}
      }
    }
  }

  if(result != ippStsNoErr) {
    if(state != nullptr) {
      ippsFree(state);
      state = nullptr;
    }

    dist = DIST_NONE;
  }
}


IppRandom::~IppRandom() {
  if(state != nullptr) {
    ippsFree(state);
    state = nullptr;
  }
}


IPP::Type IppRandom::getType() {
  return type;
}


IppRandom::Distribution IppRandom::getDistribution() {
  return dist;
}


bool IppRandom::generate(IppBuffer *dst, int len) {
  if(dst == nullptr || dst->getType() != type) {
    return false;
  }

  switch(type) {
    case IPP::TYPE_8U:
      return (dist == DIST_UNIFORM ?
           ippsRandUniform_8u(dst->as8u(), len, reinterpret_cast<IppsRandUniState_8u *>(state)) :
           ippsRandGauss_8u(dst->as8u(), len, reinterpret_cast<IppsRandGaussState_8u *>(state))) == ippStsNoErr;
    break;

    case IPP::TYPE_16S:
      return (dist == DIST_UNIFORM ?
           ippsRandUniform_16s(dst->as16s(), len, reinterpret_cast<IppsRandUniState_16s *>(state)) :
           ippsRandGauss_16s(dst->as16s(), len, reinterpret_cast<IppsRandGaussState_16s *>(state))) == ippStsNoErr;
    break;

    case IPP::TYPE_32F:
      return (dist == DIST_UNIFORM ?
           ippsRandUniform_32f(dst->as32f(), len, reinterpret_cast<IppsRandUniState_32f *>(state)) :
           ippsRandGauss_32f(dst->as32f(), len, reinterpret_cast<IppsRandGaussState_32f *>(state))) == ippStsNoErr;
    break;

    case IPP::TYPE_64F:
      return (dist == DIST_UNIFORM ?
           ippsRandUniform_64f(dst->as64f(), len, reinterpret_cast<IppsRandUniState_64f *>(state)) :
           ippsRandGauss_64f(dst->as64f(), len, reinterpret_cast<IppsRandGaussState_64f *>(state))) == ippStsNoErr;
    break;

    default:
    break;
  }

  return false;
}


static const char *DIST_TO_STRING[] = {
  "NONE", "UNIFORM", "GAUSSIAN"
};


static const char *distString(IppRandom::Distribution dist) {
  if(dist <= IppRandom::DIST_NONE || dist > IppRandom::DIST_GAUSSIAN) {
    return DIST_TO_STRING[0];
  }

  return DIST_TO_STRING[dist];
}


String IppRandom::_to_string() const {
  Dictionary bits;
  bits["low"] = lo;
  bits["high"] = hi;
  bits["type"] = IPP::typeString(type);
  bits["distribution"] = distString(dist);
  return String("[IppRandom: {_}]").format(bits);
}


static IppRandom *createUniform8u(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_8U, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createUniform16s(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_16S, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createUniform32f(double low, double high, int64_t seed) {
  return new IppRandom(IPP::TYPE_32F, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createUniform64f(double low, double high, int64_t seed) {
  return new IppRandom(IPP::TYPE_64F, IppRandom::DIST_UNIFORM, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createGaussian8u(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_8U, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createGaussian16s(int low, int high, int64_t seed) {
  return new IppRandom(IPP::TYPE_16S, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createGaussian32f(double low, double high, int64_t seed) {
  return new IppRandom(IPP::TYPE_32F, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


static IppRandom *createGaussian64f(double low, double high, int64_t seed) {
  return new IppRandom(IPP::TYPE_64F, IppRandom::DIST_GAUSSIAN, low, high, static_cast<unsigned>(seed));
}


void IppRandom::_bind_methods() {
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_uniform_8u", "low", "high", "seed"), &createUniform8u);
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_uniform_16s", "low", "high", "seed"), &createUniform16s);
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_uniform_32f", "low", "high", "seed"), &createUniform32f);
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_uniform_64f", "low", "high", "seed"), &createUniform64f);

  ClassDB::bind_static_method("IppRandom", D_METHOD("create_gaussian_8u", "low", "high", "seed"), &createGaussian8u);
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_gaussian_16s", "low", "high", "seed"), &createGaussian16s);
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_gaussian_32f", "low", "high", "seed"), &createGaussian32f);
  ClassDB::bind_static_method("IppRandom", D_METHOD("create_gaussian_64f", "low", "high", "seed"), &createGaussian64f);

  ClassDB::bind_method(D_METHOD("get_type"), &IppRandom::getType);
  ClassDB::bind_method(D_METHOD("get_distribution"), &IppRandom::getDistribution);
  ClassDB::bind_method(D_METHOD("generate", "dst", "len"), &IppRandom::generate);

  BIND_ENUM_CONSTANT(DIST_NONE);
  BIND_ENUM_CONSTANT(DIST_UNIFORM);
  BIND_ENUM_CONSTANT(DIST_GAUSSIAN);
}

