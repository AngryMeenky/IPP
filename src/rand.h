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


class IppRandom: public godot::RefCounted {
  GDCLASS(IppRandom, godot::RefCounted);

  public:
    enum Distribution {
      DIST_NONE,
      DIST_UNIFORM,
      DIST_GAUSSIAN
    };

    IppRandom();
    IppRandom(IPP::Type, Distribution, int, int, unsigned);
    IppRandom(IPP::Type, Distribution, double, double, unsigned);
    ~IppRandom();

    IPP::Type getType();
    Distribution getDistribution();

    bool generate(IppBuffer *, int);
    
  protected:
    operator bool() const { return state != nullptr; }

    godot::String _to_string() const;

    static void _bind_methods();

  private:
    Ipp8u        *state;
    Distribution  dist;
    IPP::Type     type;
    double        lo;
    double        hi;
};


}


VARIANT_ENUM_CAST(ipp::IppRandom::Distribution);

