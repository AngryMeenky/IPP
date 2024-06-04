#pragma once


#include "ipp/ipp.h"
#include "ipp/ipps.h"

#include "IPP.h"
#include "buffer.h"

#ifdef GDEXTENSION
#include <godot_cpp/variant/variant.hpp>
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
    ~IppRandom();

    IPP::Type getType() const;
    Distribution getDistribution() const;
    godot::Variant getRange() const;

    bool generate(const godot::Ref<IppBuffer> &, int);

    static godot::Ref<IppRandom> create_random_8u(Distribution, int, int, int64_t);
    static godot::Ref<IppRandom> create_random_16s(Distribution, int, int, int64_t);

    static godot::Ref<IppRandom> create_random_32f(Distribution, double, double, int64_t);
    static godot::Ref<IppRandom> create_random_64f(Distribution, double, double, int64_t);

  protected:
    operator bool() const { return state != nullptr; }

    godot::String _to_string() const;

    static void _bind_methods();

    bool initialize(IPP::Type, Distribution, int, int, unsigned);
    bool initialize(IPP::Type, Distribution, double, double, unsigned);

  private:
    Ipp8u          *state;
    godot::Variant  range;
    Distribution    dist;
    IPP::Type       type;
};


}


VARIANT_ENUM_CAST(ipp::IppRandom::Distribution);

