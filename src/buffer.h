#ifndef IPP_BUFFER_H
#  define IPP_BUFFER_H


#include "IPP.h"
#include "ipp/ipps.h"


#ifdef GDEXTENSION
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#else
#include "core/templates/vector.h"
#include "core/variant/array.h"
#endif


namespace ipp {


class IppBuffer: public godot::RefCounted {
  GDCLASS(IppBuffer, godot::RefCounted);

  public:
    IppBuffer(int = 64, IPP::Type = IPP::TYPE_8U);
    IppBuffer(const godot::PackedByteArray &, IPP::Type = IPP::TYPE_8S);
    IppBuffer(const godot::PackedInt32Array &, IPP::Type = IPP::TYPE_32S);
    IppBuffer(const godot::PackedInt64Array &, IPP::Type = IPP::TYPE_64S);
    IppBuffer(const godot::PackedFloat32Array &, IPP::Type = IPP::TYPE_32F);
    IppBuffer(const godot::PackedFloat64Array &, IPP::Type = IPP::TYPE_64F);
    ~IppBuffer();

    int load(const godot::Ref<godot::FileAccess> &);
    int store(const godot::Ref<godot::FileAccess> &) const;

    int read(const godot::Ref<godot::FileAccess> &, int, int);
    int write(const godot::Ref<godot::FileAccess> &, int, int) const;

    void fill(godot::Variant &);
    void zero();

    IPP::Type getType() const;
    int       getLength() const;

    godot::PackedByteArray    toPackedByteArray() const;
    godot::PackedInt32Array   toPackedInt32Array() const;
    godot::PackedInt64Array   toPackedInt64Array() const;
    godot::PackedFloat32Array toPackedFloat32Array() const;
    godot::PackedFloat64Array toPackedFloat64Array() const;

    bool copyTo(int, int, godot::PackedByteArray &, int) const;
    bool copyTo(int, int, godot::PackedInt32Array &, int) const;
    bool copyTo(int, int, godot::PackedInt64Array &, int) const;
    bool copyTo(int, int, godot::PackedFloat32Array &, int) const;
    bool copyTo(int, int, godot::PackedFloat64Array &, int) const;

    bool copyFrom(const godot::PackedByteArray &, int, int, int);
    bool copyFrom(const godot::PackedInt32Array &, int, int, int);
    bool copyFrom(const godot::PackedInt64Array &, int, int, int);
    bool copyFrom(const godot::PackedFloat32Array &, int, int, int);
    bool copyFrom(const godot::PackedFloat64Array &, int, int, int);

    bool add(const godot::Ref<IppBuffer> &lhs, const godot::Ref<IppBuffer> &rhs, int len, int scale);
    bool sub(const godot::Ref<IppBuffer> &lhs, const godot::Ref<IppBuffer> &rhs, int len, int scale);
    bool mul(const godot::Ref<IppBuffer> &lhs, const godot::Ref<IppBuffer> &rhs, int len, int scale);
    bool div(const godot::Ref<IppBuffer> &lhs, const godot::Ref<IppBuffer> &rhs, int len, int scale);

    bool addC(const godot::Ref<IppBuffer> &lhs, godot::Variant rhs, int len, int scale);
    bool subC(const godot::Ref<IppBuffer> &lhs, godot::Variant rhs, int len, int scale);
    bool mulC(const godot::Ref<IppBuffer> &lhs, godot::Variant rhs, int len, int scale);
    bool divC(const godot::Ref<IppBuffer> &lhs, godot::Variant rhs, int len, int scale);

    bool subCRev(const godot::Ref<IppBuffer> &lhs, godot::Variant rhs, int len, int scale);
    bool divCRev(const godot::Ref<IppBuffer> &lhs, godot::Variant rhs, int len, int scale);

    bool ln(const godot::Ref<IppBuffer> &src, int len, int scale);
    bool exp(const godot::Ref<IppBuffer> &src, int len, int scale);
    bool sqr(const godot::Ref<IppBuffer> &src, int len, int scale);
    bool sqrt(const godot::Ref<IppBuffer> &src, int len, int scale);
    bool abs(const godot::Ref<IppBuffer> &src, int len);

    bool cos(const godot::Ref<IppBuffer> &src, int len, int hint);
    bool sin(const godot::Ref<IppBuffer> &src, int len, int hint);

    godot::Variant sum(int len, int scale);
    godot::Variant mean(int len, int scale);

    // simple integers
    Ipp8u  *as8u()  { return                            ptr;  }
    Ipp8s  *as8s()  { return reinterpret_cast<Ipp8s *>( ptr); }
    Ipp16u *as16u() { return reinterpret_cast<Ipp16u *>(ptr); }
    Ipp16s *as16s() { return reinterpret_cast<Ipp16s *>(ptr); }
    Ipp32u *as32u() { return reinterpret_cast<Ipp32u *>(ptr); }
    Ipp32s *as32s() { return reinterpret_cast<Ipp32s *>(ptr); }
    Ipp64u *as64u() { return reinterpret_cast<Ipp64u *>(ptr); }
    Ipp64s *as64s() { return reinterpret_cast<Ipp64s *>(ptr); }

    const Ipp8u  *as8u()  const { return                            ptr;  }
    const Ipp8s  *as8s()  const { return reinterpret_cast<Ipp8s *>( ptr); }
    const Ipp16u *as16u() const { return reinterpret_cast<Ipp16u *>(ptr); }
    const Ipp16s *as16s() const { return reinterpret_cast<Ipp16s *>(ptr); }
    const Ipp32u *as32u() const { return reinterpret_cast<Ipp32u *>(ptr); }
    const Ipp32s *as32s() const { return reinterpret_cast<Ipp32s *>(ptr); }
    const Ipp64u *as64u() const { return reinterpret_cast<Ipp64u *>(ptr); }
    const Ipp64s *as64s() const { return reinterpret_cast<Ipp64s *>(ptr); }

    // simple reals
    Ipp32f *as32f() { return reinterpret_cast<Ipp32f *>(ptr); }
    Ipp64f *as64f() { return reinterpret_cast<Ipp64f *>(ptr); }

    const Ipp32f *as32f() const { return reinterpret_cast<Ipp32f *>(ptr); }
    const Ipp64f *as64f() const { return reinterpret_cast<Ipp64f *>(ptr); }

    // complex integers
    Ipp8sc  *as8sc()  { return reinterpret_cast<Ipp8sc *>( ptr); }
    Ipp16sc *as16sc() { return reinterpret_cast<Ipp16sc *>(ptr); }
    Ipp32sc *as32sc() { return reinterpret_cast<Ipp32sc *>(ptr); }
    Ipp64sc *as64sc() { return reinterpret_cast<Ipp64sc *>(ptr); }

    const Ipp8sc  *as8sc()  const { return reinterpret_cast<Ipp8sc *>( ptr); }
    const Ipp16sc *as16sc() const { return reinterpret_cast<Ipp16sc *>(ptr); }
    const Ipp32sc *as32sc() const { return reinterpret_cast<Ipp32sc *>(ptr); }
    const Ipp64sc *as64sc() const { return reinterpret_cast<Ipp64sc *>(ptr); }

    // complex reals
    Ipp32fc *as32fc() { return reinterpret_cast<Ipp32fc *>(ptr); }
    Ipp64fc *as64fc() { return reinterpret_cast<Ipp64fc *>(ptr); }

    const Ipp32fc *as32fc() const { return reinterpret_cast<Ipp32fc *>(ptr); }
    const Ipp64fc *as64fc() const { return reinterpret_cast<Ipp64fc *>(ptr); }

  protected:
    godot::String _to_string() const;
    bool copy_to(int, int, godot::Variant, int);
    bool copy_from(godot::Variant, int, int, int);

    static void _bind_methods();

  private:
    Ipp8u     *ptr;
    IPP::Type  type;
    int        len;
};


}



#endif /* IPP_BUFFER_H */

