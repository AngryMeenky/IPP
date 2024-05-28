#pragma once


#include "ipp/ipp.h"
#include "ipp/ipps.h"

#include "IPP.h"
#include "buffer.h"

#ifdef GDEXTENSION
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#else
#include "core/templates/vector.h"
#include "core/variant/array.h"
#endif


namespace ipp {


class IppFft: public godot::RefCounted {
  GDCLASS(IppFft, godot::RefCounted);

  public:
    enum Flags {
      DIV_FWD_BY_N  = IPP_FFT_DIV_FWD_BY_N,
      DIV_INV_BY_N  = IPP_FFT_DIV_INV_BY_N,
      DIV_BY_SQRT_N = IPP_FFT_DIV_BY_SQRTN,
      NODIV         = IPP_FFT_NODIV_BY_ANY
    };

    static IppFft *createComplex32f(int order, int flag = NODIV);
    static IppFft *createComplex64f(int order, int flag = NODIV);
    static IppFft *createComplex32fc(int order, int flag = NODIV);
    static IppFft *createComplex64fc(int order, int flag = NODIV);

    IppFft();
    IppFft(IPP::Type, int, int);
    ~IppFft();

    bool fwd(const IppBuffer *, IppBuffer *);
    bool inv(const IppBuffer *, IppBuffer *);

    bool fwdSplit(const IppBuffer *, const IppBuffer *, IppBuffer *, IppBuffer *);
    bool invSplit(const IppBuffer *, const IppBuffer *, IppBuffer *, IppBuffer *);

    IPP::Type getType();
    int getOrder();
    int getSize();

  protected:
    operator bool() const { return fftSpec != nullptr; }

    godot::String _to_string() const;

    static void _bind_methods();

  private:
    Ipp8u     *spec;
    Ipp8u     *buffer;
    void      *fftSpec;
    int        order;
    int        elements;
    IPP::Type  type;
};


}


VARIANT_ENUM_CAST(ipp::IppFft::Flags);
