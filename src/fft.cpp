#include "fft.h"

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


IppFft::IppFft(): IppFft(IPP::TYPE_32FC, 0, NODIV) {}


IppFft::IppFft(IPP::Type t, int o, int flag):
  spec(nullptr),
  buffer(nullptr),
  fftSpec(nullptr),
  order(abs(o)),
  elements(static_cast<int>(pow(2.0, order))),
  type(t) {
  if(order < 1) {
    return; // bail on bad orders
  }

  Ipp8u *init = nullptr;
  int sizeSpec = 0, sizeInit = 0, sizeBuffer = 0;

  // get size of buffers
  switch(t) {
    case IPP::TYPE_32F:
      ippsFFTGetSize_C_32f(order, flag, ippAlgHintNone, &sizeSpec, &sizeInit, &sizeBuffer);
    break;

    case IPP::TYPE_64F:
      ippsFFTGetSize_C_64f(order, flag, ippAlgHintNone, &sizeSpec, &sizeInit, &sizeBuffer);
    break;

    default:
      type = IPP::TYPE_32FC;
      // fallthrough
    case IPP::TYPE_32FC:
      ippsFFTGetSize_C_32fc(order, flag, ippAlgHintNone, &sizeSpec, &sizeInit, &sizeBuffer);
    break;

    case IPP::TYPE_64FC:
      ippsFFTGetSize_C_64fc(order, flag, ippAlgHintNone, &sizeSpec, &sizeInit, &sizeBuffer);
    break;
  }

  // allocate memory for the required buffers
  spec = (Ipp8u*) ippMalloc(sizeSpec);
  buffer = (Ipp8u*) (sizeBuffer > 0 ? ippMalloc(sizeBuffer) : nullptr);
  init = (Ipp8u*) (sizeInit > 0 ? ippMalloc(sizeInit) : nullptr);

  // initialize FFT specification structure
  switch(t) {
    case IPP::TYPE_32F:
      ippsFFTInit_C_32f(
          reinterpret_cast<IppsFFTSpec_C_32f **>(&fftSpec), order, flag, ippAlgHintNone, spec, init
      );
    break;

    case IPP::TYPE_64F:
      ippsFFTInit_C_64f(
          reinterpret_cast<IppsFFTSpec_C_64f **>(&fftSpec), order, flag, ippAlgHintNone, spec, init
      );
    break;

    default:
    case IPP::TYPE_32FC:
      ippsFFTInit_C_32fc(
          reinterpret_cast<IppsFFTSpec_C_32fc **>(&fftSpec), order, flag, ippAlgHintNone, spec, init
      );
    break;

    case IPP::TYPE_64FC:
      ippsFFTInit_C_64fc(
          reinterpret_cast<IppsFFTSpec_C_64fc **>(&fftSpec), order, flag, ippAlgHintNone, spec, init
      );
    break;
  }

  // free initialization buffer
  if(sizeInit > 0) { ippFree(init); }
}


IppFft::~IppFft() {
  if(spec)   { ippFree(spec);   spec   = nullptr; }
  if(buffer) { ippFree(buffer); buffer = nullptr; }
  fftSpec = nullptr;
}


Ref<IppFft> IppFft::createComplex32f(int order, int flag) {
  return new IppFft(IPP::TYPE_32F, order, flag);
}


Ref<IppFft> IppFft::createComplex64f(int order, int flag) {
  return new IppFft(IPP::TYPE_64F, order, flag);
}


Ref<IppFft> IppFft::createComplex32fc(int order, int flag) {
  return new IppFft(IPP::TYPE_32FC, order, flag);
}


Ref<IppFft> IppFft::createComplex64fc(int order, int flag) {
  return new IppFft(IPP::TYPE_64FC, order, flag);
}


bool IppFft::fwd(const Ref<IppBuffer> &src, const Ref<IppBuffer> &dst) {
  if(src.is_null()                || dst.is_null()               ||
     src->getType()   != type     || dst->getType()   != type    ||
     src->getLength() <  elements || dst->getLength() <  elements) {
    return false;
  }

  switch(type) {
    case IPP::TYPE_32F:
    case IPP::TYPE_64F:
      return false;
    break;

    case IPP::TYPE_32FC:
      ippsFFTFwd_CToC_32fc(
          src->as32fc(), dst->as32fc(), reinterpret_cast<IppsFFTSpec_C_32fc *>(fftSpec), buffer
      );
    break;

    case IPP::TYPE_64FC:
      ippsFFTFwd_CToC_64fc(
          src->as64fc(), dst->as64fc(), reinterpret_cast<IppsFFTSpec_C_64fc *>(fftSpec), buffer
      );
    break;
  }

  return true;
}


bool IppFft::inv(const Ref<IppBuffer> &src, const Ref<IppBuffer> &dst) {
  if(src.is_null()                || dst.is_null()               ||
     src->getType()   != type     || dst->getType()   != type    ||
     src->getLength() <  elements || dst->getLength() <  elements) {
    return false;
  }

  switch(type) {
    case IPP::TYPE_32F:
    case IPP::TYPE_64F:
      return false;
    break;

    case IPP::TYPE_32FC:
      ippsFFTInv_CToC_32fc(
          src->as32fc(), dst->as32fc(), reinterpret_cast<IppsFFTSpec_C_32fc *>(fftSpec), buffer
      );
    break;

    case IPP::TYPE_64FC:
      ippsFFTInv_CToC_64fc(
          src->as64fc(), dst->as64fc(), reinterpret_cast<IppsFFTSpec_C_64fc *>(fftSpec), buffer
      );
    break;
  }

  return true;
}


bool IppFft::fwdSplit(const Ref<IppBuffer> &sre, const Ref<IppBuffer> &sim, const Ref<IppBuffer> &dre, const Ref<IppBuffer> &dim) {
  if(sre.is_null()                || sim.is_null()                ||
     dre.is_null()                || dim.is_null()                ||
     sre->getType()   != type     || sim->getType()   != type     ||
     sre->getLength() <  elements || sim->getLength() <  elements ||
     dre->getType()   != type     || dim->getType()   != type     ||
     dre->getLength() <  elements || dim->getLength() <  elements) {
    return false;
  }

  switch(type) {
    case IPP::TYPE_32F:
      ippsFFTFwd_CToC_32f(
          sre->as32f(), sim->as32f(), dre->as32f(), dim->as32f(),
	  reinterpret_cast<IppsFFTSpec_C_32f *>(fftSpec), buffer
      );
    break;

    case IPP::TYPE_64F:
      ippsFFTFwd_CToC_64f(
          sre->as64f(), sim->as64f(), dre->as64f(), dim->as64f(),
	  reinterpret_cast<IppsFFTSpec_C_64f *>(fftSpec), buffer
      );
    break;

    case IPP::TYPE_32FC:
    case IPP::TYPE_64FC:
      return false;
    break;
  }

  return true;
}


bool IppFft::invSplit(const Ref<IppBuffer> &sre, const Ref<IppBuffer> &sim, const Ref<IppBuffer> &dre, const Ref<IppBuffer> &dim) {
  if(sre.is_null()                || sim.is_null()                ||
     dre.is_null()                || dim.is_null()                ||
     sre->getType()   != type     || sim->getType()   != type     ||
     sre->getLength() <  elements || sim->getLength() <  elements ||
     dre->getType()   != type     || dim->getType()   != type     ||
     dre->getLength() <  elements || dim->getLength() <  elements) {
    return false;
  }

  switch(type) {
    case IPP::TYPE_32F:
      ippsFFTInv_CToC_32f(
          sre->as32f(), sim->as32f(), dre->as32f(), dim->as32f(),
	  reinterpret_cast<IppsFFTSpec_C_32f *>(fftSpec), buffer
      );
    break;

    case IPP::TYPE_64F:
      ippsFFTInv_CToC_64f(
          sre->as64f(), sim->as64f(), dre->as64f(), dim->as64f(),
	  reinterpret_cast<IppsFFTSpec_C_64f *>(fftSpec), buffer
      );
    break;

    case IPP::TYPE_32FC:
    case IPP::TYPE_64FC:
      return false;
    break;
  }

  return true;
}


IPP::Type IppFft::getType() {
  return type;
}


int IppFft::getOrder() {
  return order;
}


int IppFft::getSize() {
  return elements;
}


String IppFft::_to_string() const {
  Dictionary bits;
  bits["order"] = order;
  bits["elements"] = elements;
  bits["type"] = IPP::typeString(type);
  return String("[IppFft: {_}]").format(bits);

}


void IppFft::_bind_methods() {
  ClassDB::bind_static_method("IppFft", D_METHOD("create_complex_32f", "order", "flags"), &IppFft::createComplex32f, DEFVAL(NODIV));
  ClassDB::bind_static_method("IppFft", D_METHOD("create_complex_64f", "order", "flags"), &IppFft::createComplex64f, DEFVAL(NODIV));
  ClassDB::bind_static_method("IppFft", D_METHOD("create_complex_32fc", "order", "flags"), &IppFft::createComplex32fc, DEFVAL(NODIV));
  ClassDB::bind_static_method("IppFft", D_METHOD("create_complex_64fc", "order", "flags"), &IppFft::createComplex64fc, DEFVAL(NODIV));

  ClassDB::bind_method(D_METHOD("get_type"), &IppFft::getType);
  ClassDB::bind_method(D_METHOD("get_order"), &IppFft::getOrder);
  ClassDB::bind_method(D_METHOD("get_size"), &IppFft::getSize);

  ClassDB::bind_method(D_METHOD("forward", "src", "dst"), &IppFft::fwd);
  ClassDB::bind_method(D_METHOD("inverse", "src", "dst"), &IppFft::inv);
  
  ClassDB::bind_method(D_METHOD("split_forward", "srcRe", "srcIm", "dstRe", "dstIm"), &IppFft::fwdSplit);
  ClassDB::bind_method(D_METHOD("split_inverse", "srcRe", "srcIm", "dstRe", "dstIm"), &IppFft::invSplit);

  BIND_ENUM_CONSTANT(DIV_FWD_BY_N);
  BIND_ENUM_CONSTANT(DIV_INV_BY_N);
  BIND_ENUM_CONSTANT(DIV_BY_SQRT_N);
  BIND_ENUM_CONSTANT(NODIV);
}

