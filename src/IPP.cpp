#define IPP_IMPL
#include "IPP.h"
#include "fft.h"
#include "rand.h"
#include "buffer.h"

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


static const char *TYPE_TO_STRING[] = {
  "NONE",
  // integers
  "Ipp8u", "Ipp8s", "Ipp16u", "Ipp16s",
  "Ipp32u", "Ipp32s", "Ipp64u", "Ipp64s",
  // reals
  "Ipp32f", "Ipp64s",
  // complex integers
  "Ipp8sc", "Ipp16sc", "Ipp32sc", "Ipp64sc",
  // complex reals
  "Ipp32fc", "Ipp64fc"
};


const char *IPP::typeString(Type t) {
  return TYPE_TO_STRING[(0 >= t || t > TYPE_64FC) ? 0 : t];
}


static const char *HINT_TO_STRING[] = {
  "NONE", "Fast", "Accurate"
};


const char *IPP::hintString(Hint h) {
  return HINT_TO_STRING[(0 >= h || h > HINT_ACC) ? 0 : h];
}


String IPP::statusString(Status code) {
  return String(ippGetStatusString(static_cast<IppStatus>(code)));
}


Ref<IppRandom> IPP::uniform_init_8u(int low, int high, int64_t seed) {
  return IppRandom::create_random_8u(IppRandom::DIST_UNIFORM, low, high, seed);
}


Ref<IppRandom> IPP::uniform_init_16s(int low, int high, int64_t seed) {
  return IppRandom::create_random_16s(IppRandom::DIST_UNIFORM, low, high, seed);
}


Ref<IppRandom> IPP::uniform_init_32f(float low, float high, int64_t seed) {
  return IppRandom::create_random_32f(IppRandom::DIST_UNIFORM, low, high, seed);
}


Ref<IppRandom> IPP::uniform_init_64f(double low, double high, int64_t seed) {
  return IppRandom::create_random_64f(IppRandom::DIST_UNIFORM, low, high, seed);
}


Ref<IppRandom> IPP::gauss_init_8u(int low, int high, int64_t seed) {
  return IppRandom::create_random_8u(IppRandom::DIST_GAUSSIAN, low, high, seed);
}


Ref<IppRandom> IPP::gauss_init_16s(int low, int high, int64_t seed) {
  return IppRandom::create_random_16s(IppRandom::DIST_GAUSSIAN, low, high, seed);
}


Ref<IppRandom> IPP::gauss_init_32f(float low, float high, int64_t seed) {
  return IppRandom::create_random_32f(IppRandom::DIST_GAUSSIAN, low, high, seed);
}


Ref<IppRandom> IPP::gauss_init_64f(double low, double high, int64_t seed) {
  return IppRandom::create_random_64f(IppRandom::DIST_GAUSSIAN, low, high, seed);
}


Ref<IppFft> IPP::fft_init_C_32f(int order, int flag) {
  return IppFft::createComplex32f(order, flag);
}


Ref<IppFft> IPP::fft_init_C_64f(int order, int flag) {
  return IppFft::createComplex64f(order, flag);
}


Ref<IppFft> IPP::fft_init_C_32fc(int order, int flag) {
  return IppFft::createComplex32fc(order, flag);
}


Ref<IppFft> IPP::fft_init_C_64fc(int order, int flag) {
  return IppFft::createComplex64fc(order, flag);
}


void IPP::_bind_methods() {
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_8u", "len"), &IPP::malloc_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_8s", "len"), &IPP::malloc_8s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_16u", "len"), &IPP::malloc_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_16s", "len"), &IPP::malloc_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32u", "len"), &IPP::malloc_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32s", "len"), &IPP::malloc_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64u", "len"), &IPP::malloc_64u);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64s", "len"), &IPP::malloc_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32f", "len"), &IPP::malloc_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64f", "len"), &IPP::malloc_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_8sc", "len"), &IPP::malloc_8sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_16sc", "len"), &IPP::malloc_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32sc", "len"), &IPP::malloc_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64sc", "len"), &IPP::malloc_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_32fc", "len"), &IPP::malloc_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("malloc_64fc", "len"), &IPP::malloc_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("copy_8u", "src", "dst", "len"), &IPP::copy_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_16s", "src", "dst", "len"), &IPP::copy_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32s", "src", "dst", "len"), &IPP::copy_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64s", "src", "dst", "len"), &IPP::copy_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32f", "src", "dst", "len"), &IPP::copy_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64f", "src", "dst", "len"), &IPP::copy_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_16sc", "src", "dst", "len"), &IPP::copy_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32sc", "src", "dst", "len"), &IPP::copy_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64sc", "src", "dst", "len"), &IPP::copy_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_32fc", "src", "dst", "len"), &IPP::copy_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("copy_64fc", "src", "dst", "len"), &IPP::copy_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("move_8u", "src", "dst", "len"), &IPP::move_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("move_16s", "src", "dst", "len"), &IPP::move_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32s", "src", "dst", "len"), &IPP::move_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64s", "src", "dst", "len"), &IPP::move_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32f", "src", "dst", "len"), &IPP::move_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64f", "src", "dst", "len"), &IPP::move_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("move_16sc", "src", "dst", "len"), &IPP::move_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32sc", "src", "dst", "len"), &IPP::move_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64sc", "src", "dst", "len"), &IPP::move_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_32fc", "src", "dst", "len"), &IPP::move_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("move_64fc", "src", "dst", "len"), &IPP::move_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("set_8u", "val", "dst", "len"), &IPP::set_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("set_16s", "val", "dst", "len"), &IPP::set_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32s", "val", "dst", "len"), &IPP::set_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64s", "val", "dst", "len"), &IPP::set_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32f", "val", "dst", "len"), &IPP::set_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64f", "val", "dst", "len"), &IPP::set_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("set_16sc", "val", "dst", "len"), &IPP::set_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32sc", "val", "dst", "len"), &IPP::set_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64sc", "val", "dst", "len"), &IPP::set_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_32fc", "val", "dst", "len"), &IPP::set_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("set_64fc", "val", "dst", "len"), &IPP::set_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("zero_8u", "dst", "len"), &IPP::zero_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_16s", "dst", "len"), &IPP::zero_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32s", "dst", "len"), &IPP::zero_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64s", "dst", "len"), &IPP::zero_64s);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32f", "dst", "len"), &IPP::zero_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64f", "dst", "len"), &IPP::zero_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_16sc", "dst", "len"), &IPP::zero_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32sc", "dst", "len"), &IPP::zero_32sc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64sc", "dst", "len"), &IPP::zero_64sc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_32fc", "dst", "len"), &IPP::zero_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("zero_64fc", "dst", "len"), &IPP::zero_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("andC_8u", "src", "val", "dst", "len"), &IPP::andC_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("andC_16u", "src", "val", "dst", "len"), &IPP::andC_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("andC_32u", "src", "val", "dst", "len"), &IPP::andC_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("andC_8u_I", "val", "src_dst", "len"), &IPP::andC_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("andC_16u_I", "val", "src_dst", "len"), &IPP::andC_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("andC_32u_I", "val", "src_dst", "len"), &IPP::andC_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("and_8u", "lhs", "rhs", "dst", "len"), &IPP::and_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("and_16u", "lhs", "rhs", "dst", "len"), &IPP::and_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("and_32u", "lhs", "rhs", "dst", "len"), &IPP::and_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("and_8u_I", "src", "src_dst", "len"), &IPP::and_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("and_16u_I", "src", "src_dst", "len"), &IPP::and_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("and_32u_I", "src", "src_dst", "len"), &IPP::and_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("orC_8u", "src", "val", "dst", "len"), &IPP::orC_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("orC_16u", "src", "val", "dst", "len"), &IPP::orC_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("orC_32u", "src", "val", "dst", "len"), &IPP::orC_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("orC_8u_I", "val", "src_dst", "len"), &IPP::orC_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("orC_16u_I", "val", "src_dst", "len"), &IPP::orC_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("orC_32u_I", "val", "src_dst", "len"), &IPP::orC_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("or_8u", "lhs", "rhs", "dst", "len"), &IPP::or_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("or_16u", "lhs", "rhs", "dst", "len"), &IPP::or_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("or_32u", "lhs", "rhs", "dst", "len"), &IPP::or_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("or_8u_I", "src", "src_dst", "len"), &IPP::or_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("or_16u_I", "src", "src_dst", "len"), &IPP::or_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("or_32u_I", "src", "src_dst", "len"), &IPP::or_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("xorC_8u", "src", "val", "dst", "len"), &IPP::xorC_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("xorC_16u", "src", "val", "dst", "len"), &IPP::xorC_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("xorC_32u", "src", "val", "dst", "len"), &IPP::xorC_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("xorC_8u_I", "val", "src_dst", "len"), &IPP::xorC_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("xorC_16u_I", "val", "src_dst", "len"), &IPP::xorC_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("xorC_32u_I", "val", "src_dst", "len"), &IPP::xorC_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("xor_8u", "lhs", "rhs", "dst", "len"), &IPP::xor_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("xor_16u", "lhs", "rhs", "dst", "len"), &IPP::xor_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("xor_32u", "lhs", "rhs", "dst", "len"), &IPP::xor_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("xor_8u_I", "src", "src_dst", "len"), &IPP::xor_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("xor_16u_I", "src", "src_dst", "len"), &IPP::xor_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("xor_32u_I", "src", "src_dst", "len"), &IPP::xor_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("not_8u", "src", "dst", "len"), &IPP::not_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("not_16u", "src", "dst", "len"), &IPP::not_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("not_32u", "src", "dst", "len"), &IPP::not_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("not_8u_I", "src_dst", "len"), &IPP::not_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("not_16u_I", "src_dst", "len"), &IPP::not_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("not_32u_I", "src_dst", "len"), &IPP::not_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("l_shiftC_8u", "src", "val", "dst", "len"), &IPP::l_shiftC_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("l_shiftC_16u", "src", "val", "dst", "len"), &IPP::l_shiftC_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("l_shiftC_32s", "src", "val", "dst", "len"), &IPP::l_shiftC_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("l_shiftC_8u_I", "val", "src_dst", "len"), &IPP::l_shiftC_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("l_shiftC_16u_I", "val", "src_dst", "len"), &IPP::l_shiftC_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("l_shiftC_32s_I", "val", "src_dst", "len"), &IPP::l_shiftC_32s_I);

  ClassDB::bind_static_method("IPP", D_METHOD("r_shiftC_8u", "src", "val", "dst", "len"), &IPP::r_shiftC_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("r_shiftC_16u", "src", "val", "dst", "len"), &IPP::r_shiftC_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("r_shiftC_32s", "src", "val", "dst", "len"), &IPP::r_shiftC_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("r_shiftC_8u_I", "val", "src_dst", "len"), &IPP::r_shiftC_8u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("r_shiftC_16u_I", "val", "src_dst", "len"), &IPP::r_shiftC_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("r_shiftC_32s_I", "val", "src_dst", "len"), &IPP::r_shiftC_32s_I);

  ClassDB::bind_static_method("IPP", D_METHOD("tone_16s", "len", "mag", "freq", "phase", "hint"), &IPP::tone_16s, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_32f", "len", "mag", "freq", "phase", "hint"), &IPP::tone_32f, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_64f", "len", "mag", "freq", "phase", "hint"), &IPP::tone_64f, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_16sc", "len", "mag", "freq", "phase", "hint"), &IPP::tone_16sc, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_32fc", "len", "mag", "freq", "phase", "hint"), &IPP::tone_32fc, DEFVAL(HINT_NONE));
  ClassDB::bind_static_method("IPP", D_METHOD("tone_64fc", "len", "mag", "freq", "phase", "hint"), &IPP::tone_64fc, DEFVAL(HINT_NONE));

  ClassDB::bind_static_method("IPP", D_METHOD("triangle_16s", "len", "mag", "freq", "asym", "phase"), &IPP::tone_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_32f", "len", "mag", "freq", "asym", "phase"), &IPP::tone_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_64f", "len", "mag", "freq", "asym", "phase"), &IPP::tone_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_16sc", "len", "mag", "freq", "asym", "phase"), &IPP::tone_16sc);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_32fc", "len", "mag", "freq", "asym", "phase"), &IPP::tone_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("triangle_64fc", "len", "mag", "freq", "asym", "phase"), &IPP::tone_64fc);
  
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32f_A11", "src", "dst", "len"), &IPP::cos_32f_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32f_A21", "src", "dst", "len"), &IPP::cos_32f_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32f_A24", "src", "dst", "len"), &IPP::cos_32f_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64f_A26", "src", "dst", "len"), &IPP::cos_64f_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64f_A50", "src", "dst", "len"), &IPP::cos_64f_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64f_A53", "src", "dst", "len"), &IPP::cos_64f_A53);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32fc_A11", "src", "dst", "len"), &IPP::cos_32fc_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32fc_A21", "src", "dst", "len"), &IPP::cos_32fc_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_32fc_A24", "src", "dst", "len"), &IPP::cos_32fc_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64fc_A26", "src", "dst", "len"), &IPP::cos_64fc_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64fc_A50", "src", "dst", "len"), &IPP::cos_64fc_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("cos_64fc_A53", "src", "dst", "len"), &IPP::cos_64fc_A53);
  
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32f_A11", "src", "dst", "len"), &IPP::sin_32f_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32f_A21", "src", "dst", "len"), &IPP::sin_32f_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32f_A24", "src", "dst", "len"), &IPP::sin_32f_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64f_A26", "src", "dst", "len"), &IPP::sin_64f_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64f_A50", "src", "dst", "len"), &IPP::sin_64f_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64f_A53", "src", "dst", "len"), &IPP::sin_64f_A53);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32fc_A11", "src", "dst", "len"), &IPP::sin_32fc_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32fc_A21", "src", "dst", "len"), &IPP::sin_32fc_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_32fc_A24", "src", "dst", "len"), &IPP::sin_32fc_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64fc_A26", "src", "dst", "len"), &IPP::sin_64fc_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64fc_A50", "src", "dst", "len"), &IPP::sin_64fc_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_64fc_A53", "src", "dst", "len"), &IPP::sin_64fc_A53);
  
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_32f_A11", "src", "sine", "cosine", "len"), &IPP::sin_cos_32f_A11);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_32f_A21", "src", "sine", "cosine", "len"), &IPP::sin_cos_32f_A21);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_32f_A24", "src", "sine", "cosine", "len"), &IPP::sin_cos_32f_A24);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_64f_A26", "src", "sine", "cosine", "len"), &IPP::sin_cos_64f_A26);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_64f_A50", "src", "sine", "cosine", "len"), &IPP::sin_cos_64f_A50);
  ClassDB::bind_static_method("IPP", D_METHOD("sin_cos_64f_A53", "src", "sine", "cosine", "len"), &IPP::sin_cos_64f_A53);

  ClassDB::bind_static_method("IPP", D_METHOD("addC_32f", "src", "val", "dst", "len"), &IPP::addC_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64f", "src", "val", "dst", "len"), &IPP::addC_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32fc", "src", "val", "dst", "len"), &IPP::addC_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64fc", "src", "val", "dst", "len"), &IPP::addC_64fc);
  
  ClassDB::bind_static_method("IPP", D_METHOD("addC_8u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_64u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_64s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::addC_32sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("addC_32f_I", "val", "src_dst", "len"), &IPP::addC_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64f_I", "val", "src_dst", "len"), &IPP::addC_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32fc_I", "val", "src_dst", "len"), &IPP::addC_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_64fc_I", "val", "src_dst", "len"), &IPP::addC_64fc_I);
  
  ClassDB::bind_static_method("IPP", D_METHOD("addC_8u_ISfs", "val", "src_dst", "len", "scale"), &IPP::addC_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16u_ISfs", "val", "src_dst", "len", "scale"), &IPP::addC_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16s_ISfs", "val", "src_dst", "len", "scale"), &IPP::addC_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32s_ISfs", "val", "src_dst", "len", "scale"), &IPP::addC_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_16sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::addC_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addC_32sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::addC_32sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("add_16s", "lhs", "rhs", "dst", "len"), &IPP::add_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32f", "lhs", "rhs", "dst", "len"), &IPP::add_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("add_64f", "lhs", "rhs", "dst", "len"), &IPP::add_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32fc", "lhs", "rhs", "dst", "len"), &IPP::add_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("add_64fc", "lhs", "rhs", "dst", "len"), &IPP::add_64fc);
  ClassDB::bind_static_method("IPP", D_METHOD("add_8u16u", "lhs", "rhs", "dst", "len"), &IPP::add_8u16u);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16u", "lhs", "rhs", "dst", "len"), &IPP::add_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32u", "lhs", "rhs", "dst", "len"), &IPP::add_32u);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16s32f", "lhs", "rhs", "dst", "len"), &IPP::add_16s32f);

  ClassDB::bind_static_method("IPP", D_METHOD("add_8u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_32sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_64s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::add_64s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("add_16s_I", "src", "src_dst", "len"), &IPP::add_16s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32f_I", "src", "src_dst", "len"), &IPP::add_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("add_64f_I", "src", "src_dst", "len"), &IPP::add_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32fc_I", "src", "src_dst", "len"), &IPP::add_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("add_64fc_I", "src", "src_dst", "len"), &IPP::add_64fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16s32s_I", "src", "src_dst", "len"), &IPP::add_16s32s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32u_I", "src", "src_dst", "len"), &IPP::add_32u_I);

  ClassDB::bind_static_method("IPP", D_METHOD("add_8u_ISfs", "src", "src_dst", "len", "scale"), &IPP::add_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16u_ISfs", "src", "src_dst", "len", "scale"), &IPP::add_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16s_ISfs", "src", "src_dst", "len", "scale"), &IPP::add_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32s_ISfs", "src", "src_dst", "len", "scale"), &IPP::add_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_16sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::add_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("add_32sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::add_32sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("addProductC_32f", "src", "val", "dst", "len"), &IPP::addProductC_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("addProductC_64f", "src", "val", "dst", "len"), &IPP::addProductC_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_32f", "lhs", "rhs", "dst", "len"), &IPP::addProduct_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_64f", "lhs", "rhs", "dst", "len"), &IPP::addProduct_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_32fc", "lhs", "rhs", "dst", "len"), &IPP::addProduct_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_64fc", "lhs", "rhs", "dst", "len"), &IPP::addProduct_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::addProduct_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::addProduct_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("addProduct_16s32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::addProduct_16s32s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32f", "src", "val", "dst", "len"), &IPP::mulC_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_64f", "src", "val", "dst", "len"), &IPP::mulC_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32fc", "src", "val", "dst", "len"), &IPP::mulC_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_64fc", "src", "val", "dst", "len"), &IPP::mulC_64fc);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_low_32f16s", "src", "val", "dst", "len"), &IPP::mulC_low_32f16s);

  ClassDB::bind_static_method("IPP", D_METHOD("mulC_8u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_32sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32f16s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::mulC_32f16s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16s_I", "val", "src_dst", "len"), &IPP::mulC_16s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32f_I", "val", "src_dst", "len"), &IPP::mulC_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_64f_I", "val", "src_dst", "len"), &IPP::mulC_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32fc_I", "val", "src_dst", "len"), &IPP::mulC_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_64fc_I", "val", "src_dst", "len"), &IPP::mulC_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("mulC_8u_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16u_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16s_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32s_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_64f64s_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_64f64s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_16sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_32sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_32sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mulC_64s_ISfs", "val", "src_dst", "len", "scale"), &IPP::mulC_64s_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("mul_16s", "lhs", "rhs", "dst", "len"), &IPP::mul_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32f", "lhs", "rhs", "dst", "len"), &IPP::mul_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_64f", "lhs", "rhs", "dst", "len"), &IPP::mul_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32fc", "lhs", "rhs", "dst", "len"), &IPP::mul_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_64fc", "lhs", "rhs", "dst", "len"), &IPP::mul_64fc);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_8u16u", "lhs", "rhs", "dst", "len"), &IPP::mul_8u16u);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32f32fc", "lhs", "rhs", "dst", "len"), &IPP::mul_32f32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16s32f", "lhs", "rhs", "dst", "len"), &IPP::mul_16s32f);

  ClassDB::bind_static_method("IPP", D_METHOD("mul_8u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_32sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16s32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_16s32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16u16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::mul_16u16s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("mul_16s_I", "src", "src_dst", "len"), &IPP::mul_16s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32f_I", "src", "src_dst", "len"), &IPP::mul_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_64f_I", "src", "src_dst", "len"), &IPP::mul_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32fc_I", "src", "src_dst", "len"), &IPP::mul_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_64fc_I", "src", "src_dst", "len"), &IPP::mul_64fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32f32fc_I", "src", "src_dst", "len"), &IPP::mul_32f32fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("mul_8u_ISfs", "src", "src_dst", "len", "scale"), &IPP::mul_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16u_ISfs", "src", "src_dst", "len", "scale"), &IPP::mul_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16s_ISfs", "src", "src_dst", "len", "scale"), &IPP::mul_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32s_ISfs", "src", "src_dst", "len", "scale"), &IPP::mul_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_16sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::mul_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mul_32sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::mul_32sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("subC_32f", "src", "val", "dst", "len"), &IPP::subC_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_64f", "src", "val", "dst", "len"), &IPP::subC_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_32fc", "src", "val", "dst", "len"), &IPP::subC_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_64fc", "src", "val", "dst", "len"), &IPP::subC_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("subC_8u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subC_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_16u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subC_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_16s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subC_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_32s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subC_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_16sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subC_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_32sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subC_32sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("subC_32f_I", "val", "src_dst", "len"), &IPP::subC_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_64f_I", "val", "src_dst", "len"), &IPP::subC_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_32fc_I", "val", "src_dst", "len"), &IPP::subC_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_64fc_I", "val", "src_dst", "len"), &IPP::subC_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("subC_8u_ISfs", "val", "src_dst", "len", "scale"), &IPP::subC_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_16u_ISfs", "val", "src_dst", "len", "scale"), &IPP::subC_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_16s_ISfs", "val", "src_dst", "len", "scale"), &IPP::subC_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_32s_ISfs", "val", "src_dst", "len", "scale"), &IPP::subC_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_16sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::subC_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subC_32sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::subC_32sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32f", "src", "val", "dst", "len"), &IPP::subCRev_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_64f", "src", "val", "dst", "len"), &IPP::subCRev_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32fc", "src", "val", "dst", "len"), &IPP::subCRev_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_64fc", "src", "val", "dst", "len"), &IPP::subCRev_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_8u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subCRev_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_16u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subCRev_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_16s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subCRev_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subCRev_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_16sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subCRev_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::subCRev_32sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32f_I", "val", "src_dst", "len"), &IPP::subCRev_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_64f_I", "val", "src_dst", "len"), &IPP::subCRev_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32fc_I", "val", "src_dst", "len"), &IPP::subCRev_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_64fc_I", "val", "src_dst", "len"), &IPP::subCRev_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_8u_ISfs", "val", "src_dst", "len", "scale"), &IPP::subCRev_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_16u_ISfs", "val", "src_dst", "len", "scale"), &IPP::subCRev_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_16s_ISfs", "val", "src_dst", "len", "scale"), &IPP::subCRev_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32s_ISfs", "val", "src_dst", "len", "scale"), &IPP::subCRev_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_16sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::subCRev_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("subCRev_32sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::subCRev_32sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("sub_16s", "lhs", "rhs", "dst", "len"), &IPP::sub_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32f", "lhs", "rhs", "dst", "len"), &IPP::sub_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_64f", "lhs", "rhs", "dst", "len"), &IPP::sub_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32fc", "lhs", "rhs", "dst", "len"), &IPP::sub_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_64fc", "lhs", "rhs", "dst", "len"), &IPP::sub_64fc);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16s32f", "lhs", "rhs", "dst", "len"), &IPP::sub_16s32f);

  ClassDB::bind_static_method("IPP", D_METHOD("sub_8u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::sub_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::sub_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::sub_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::sub_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::sub_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::sub_32sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("sub_16s_I", "src", "src_dst", "len"), &IPP::sub_16s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32f_I", "src", "src_dst", "len"), &IPP::sub_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_64f_I", "src", "src_dst", "len"), &IPP::sub_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32fc_I", "src", "src_dst", "len"), &IPP::sub_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_64fc_I", "src", "src_dst", "len"), &IPP::sub_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("sub_8u_ISfs", "src", "src_dst", "len", "scale"), &IPP::sub_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16u_ISfs", "src", "src_dst", "len", "scale"), &IPP::sub_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16s_ISfs", "src", "src_dst", "len", "scale"), &IPP::sub_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32s_ISfs", "src", "src_dst", "len", "scale"), &IPP::sub_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_16sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::sub_16sc_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sub_32sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::sub_32sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("divC_32f", "src", "val", "dst", "len"), &IPP::divC_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_64f", "src", "val", "dst", "len"), &IPP::divC_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_32fc", "src", "val", "dst", "len"), &IPP::divC_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_64fc", "src", "val", "dst", "len"), &IPP::divC_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("divC_8u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::divC_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_16u_Sfs", "src", "val", "dst", "len", "scale"), &IPP::divC_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_16s_Sfs", "src", "val", "dst", "len", "scale"), &IPP::divC_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_16sc_Sfs", "src", "val", "dst", "len", "scale"), &IPP::divC_16sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("divC_32f_I", "val", "src_dst", "len"), &IPP::divC_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_64f_I", "val", "src_dst", "len"), &IPP::divC_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_32fc_I", "val", "src_dst", "len"), &IPP::divC_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_64fc_I", "val", "src_dst", "len"), &IPP::divC_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("divC_8u_ISfs", "val", "src_dst", "len", "scale"), &IPP::divC_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_16u_ISfs", "val", "src_dst", "len", "scale"), &IPP::divC_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_16s_ISfs", "val", "src_dst", "len", "scale"), &IPP::divC_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_64s_ISfs", "val", "src_dst", "len", "scale"), &IPP::divC_64s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("divC_16sc_ISfs", "val", "src_dst", "len", "scale"), &IPP::divC_16sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("divCRev_16u", "src", "val", "dst", "len"), &IPP::divCRev_16u);
  ClassDB::bind_static_method("IPP", D_METHOD("divCRev_32f", "src", "val", "dst", "len"), &IPP::divCRev_32f);

  ClassDB::bind_static_method("IPP", D_METHOD("divCRev_16u_I", "val", "src_dst", "len"), &IPP::divCRev_16u_I);
  ClassDB::bind_static_method("IPP", D_METHOD("divCRev_32f_I", "val", "src_dst", "len"), &IPP::divCRev_32f_I);

  ClassDB::bind_static_method("IPP", D_METHOD("div_8u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::div_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_16u_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::div_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::div_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_32s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::div_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_16sc_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::div_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_32s16s_Sfs", "lhs", "rhs", "dst", "len", "scale"), &IPP::div_32s16s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("div_32f", "lhs", "rhs", "dst", "len"), &IPP::div_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("div_64f", "lhs", "rhs", "dst", "len"), &IPP::div_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("div_32fc", "lhs", "rhs", "dst", "len"), &IPP::div_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("div_64fc", "lhs", "rhs", "dst", "len"), &IPP::div_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("div_8u_ISfs", "src", "src_dst", "len", "scale"), &IPP::div_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_16u_ISfs", "src", "src_dst", "len", "scale"), &IPP::div_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_16s_ISfs", "src", "src_dst", "len", "scale"), &IPP::div_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_32s_ISfs", "src", "src_dst", "len", "scale"), &IPP::div_32s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_16sc_ISfs", "src", "src_dst", "len", "scale"), &IPP::div_16sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("div_32f_I", "src", "src_dst", "len"), &IPP::div_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("div_64f_I", "src", "src_dst", "len"), &IPP::div_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("div_32fc_I", "src", "src_dst", "len"), &IPP::div_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("div_64fc_I", "src", "src_dst", "len"), &IPP::div_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("div_round_8u_Sfs", "lhs", "rhs", "dst", "len", "round", "scale"), &IPP::div_round_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_round_16u_Sfs", "lhs", "rhs", "dst", "len", "round", "scale"), &IPP::div_round_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_round_16s_Sfs", "lhs", "rhs", "dst", "len", "round", "scale"), &IPP::div_round_16s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("div_round_8u_ISfs", "src", "src_dst", "len", "round", "scale"), &IPP::div_round_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_round_16u_ISfs", "src", "src_dst", "len", "round", "scale"), &IPP::div_round_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("div_round_16s_ISfs", "src", "src_dst", "len", "round", "scale"), &IPP::div_round_16s_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("abs_16s", "src", "dst", "len"), &IPP::abs_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("abs_32s", "src", "dst", "len"), &IPP::abs_32s);
  ClassDB::bind_static_method("IPP", D_METHOD("abs_32f", "src", "dst", "len"), &IPP::abs_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("abs_64f", "src", "dst", "len"), &IPP::abs_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("abs_16s_I", "src_dst", "len"), &IPP::abs_16s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("abs_32s_I", "src_dst", "len"), &IPP::abs_32s_I);
  ClassDB::bind_static_method("IPP", D_METHOD("abs_32f_I", "src_dst", "len"), &IPP::abs_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("abs_64f_I", "src_dst", "len"), &IPP::abs_64f_I);

  ClassDB::bind_static_method("IPP", D_METHOD("sqr_32f", "src", "dst", "len"), &IPP::sqr_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_64f", "src", "dst", "len"), &IPP::sqr_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_32fc", "src", "dst", "len"), &IPP::sqr_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_64fc", "src", "dst", "len"), &IPP::sqr_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("sqr_8u_Sfs", "src", "dst", "len", "scale"), &IPP::sqr_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_16u_Sfs", "src", "dst", "len", "scale"), &IPP::sqr_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_16s_Sfs", "src", "dst", "len", "scale"), &IPP::sqr_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_16sc_Sfs", "src", "dst", "len", "scale"), &IPP::sqr_16sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("sqr_32f_I", "src_dst", "len"), &IPP::sqr_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_64f_I", "src_dst", "len"), &IPP::sqr_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_32fc_I", "src_dst", "len"), &IPP::sqr_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_64fc_I", "src_dst", "len"), &IPP::sqr_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("sqr_8u_ISfs", "src_dst", "len", "scale"), &IPP::sqr_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_16u_ISfs", "src_dst", "len", "scale"), &IPP::sqr_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_16s_ISfs", "src_dst", "len", "scale"), &IPP::sqr_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqr_16sc_ISfs", "src_dst", "len", "scale"), &IPP::sqr_16sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_32f", "src", "dst", "len"), &IPP::sqrt_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_64f", "src", "dst", "len"), &IPP::sqrt_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_32fc", "src", "dst", "len"), &IPP::sqrt_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_64fc", "src", "dst", "len"), &IPP::sqrt_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_8u_Sfs", "src", "dst", "len", "scale"), &IPP::sqrt_8u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_16u_Sfs", "src", "dst", "len", "scale"), &IPP::sqrt_16u_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_16s_Sfs", "src", "dst", "len", "scale"), &IPP::sqrt_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_16sc_Sfs", "src", "dst", "len", "scale"), &IPP::sqrt_16sc_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_32s16s_Sfs", "src", "dst", "len", "scale"), &IPP::sqrt_32s16s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_32f_I", "src_dst", "len"), &IPP::sqrt_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_64f_I", "src_dst", "len"), &IPP::sqrt_64f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_32fc_I", "src_dst", "len"), &IPP::sqrt_32fc_I);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_64fc_I", "src_dst", "len"), &IPP::sqrt_64fc_I);

  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_8u_ISfs", "src_dst", "len", "scale"), &IPP::sqrt_8u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_16u_ISfs", "src_dst", "len", "scale"), &IPP::sqrt_16u_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_16s_ISfs", "src_dst", "len", "scale"), &IPP::sqrt_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("sqrt_16sc_ISfs", "src_dst", "len", "scale"), &IPP::sqrt_16sc_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("cubrt_32f", "src", "dst", "len"), &IPP::cubrt_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("cubrt_32s16s_Sfs", "src", "dst", "len", "scale"), &IPP::cubrt_32s16s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("exp_32f", "src", "dst", "len"), &IPP::exp_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("exp_64f", "src", "dst", "len"), &IPP::exp_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("exp_32f_I", "src_dst", "len"), &IPP::exp_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("exp_64f_I", "src_dst", "len"), &IPP::exp_64f_I);

  ClassDB::bind_static_method("IPP", D_METHOD("exp_16s_Sfs", "src", "dst", "len", "scale"), &IPP::exp_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("exp_32s_Sfs", "src", "dst", "len", "scale"), &IPP::exp_32s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("exp_16s_ISfs", "src_dst", "len", "scale"), &IPP::exp_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("exp_32s_ISfs", "src_dst", "len", "scale"), &IPP::exp_32s_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("ln_32f", "src", "dst", "len"), &IPP::ln_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("ln_64f", "src", "dst", "len"), &IPP::ln_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("ln_32f_I", "src_dst", "len"), &IPP::ln_32f_I);
  ClassDB::bind_static_method("IPP", D_METHOD("ln_64f_I", "src_dst", "len"), &IPP::ln_64f_I);

  ClassDB::bind_static_method("IPP", D_METHOD("ln_16s_Sfs", "src", "dst", "len", "scale"), &IPP::ln_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("ln_32s_Sfs", "src", "dst", "len", "scale"), &IPP::ln_32s_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("ln_16s_ISfs", "src_dst", "len", "scale"), &IPP::ln_16s_ISfs);
  ClassDB::bind_static_method("IPP", D_METHOD("ln_32s_ISfs", "src_dst", "len", "scale"), &IPP::ln_32s_ISfs);

  ClassDB::bind_static_method("IPP", D_METHOD("mean_32f", "src", "len", "result", "hint"), &IPP::mean_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("mean_64f", "src", "len", "result", "hint"), &IPP::mean_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("mean_32fc", "src", "len", "result"), &IPP::mean_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("mean_64fc", "src", "len", "result"), &IPP::mean_64fc);

  ClassDB::bind_static_method("IPP", D_METHOD("mean_16s_Sfs", "src", "len", "result", "scale"), &IPP::mean_16s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mean_32s_Sfs", "src", "len", "result", "scale"), &IPP::mean_32s_Sfs);
  ClassDB::bind_static_method("IPP", D_METHOD("mean_16sc_Sfs", "src", "len", "result", "scale"), &IPP::mean_16sc_Sfs);

  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_8u", "low", "high", "seed"), &IPP::uniform_init_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_16s", "low", "high", "seed"), &IPP::uniform_init_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_32f", "low", "high", "seed"), &IPP::uniform_init_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("uniform_init_64f", "low", "high", "seed"), &IPP::uniform_init_64f);
  
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_8u", "low", "high", "seed"), &IPP::gauss_init_8u);
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_16s", "low", "high", "seed"), &IPP::gauss_init_16s);
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_32f", "low", "high", "seed"), &IPP::gauss_init_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("gauss_init_64f", "low", "high", "seed"), &IPP::gauss_init_64f);

  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_32f", "order", "flag"), &IPP::fft_init_C_32f);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_64f", "order", "flag"), &IPP::fft_init_C_64f);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_32fc", "order", "flag"), &IPP::fft_init_C_32fc);
  ClassDB::bind_static_method("IPP", D_METHOD("fft_init_C_64fc", "order", "flag"), &IPP::fft_init_C_64fc);
  

  BIND_ENUM_CONSTANT(TYPE_8U);
  BIND_ENUM_CONSTANT(TYPE_8S);
  BIND_ENUM_CONSTANT(TYPE_16U);
  BIND_ENUM_CONSTANT(TYPE_16S);
  BIND_ENUM_CONSTANT(TYPE_32U);
  BIND_ENUM_CONSTANT(TYPE_32S);
  BIND_ENUM_CONSTANT(TYPE_64S);
  BIND_ENUM_CONSTANT(TYPE_32F);
  BIND_ENUM_CONSTANT(TYPE_64F);
  BIND_ENUM_CONSTANT(TYPE_8SC);
  BIND_ENUM_CONSTANT(TYPE_16SC);
  BIND_ENUM_CONSTANT(TYPE_32SC);
  BIND_ENUM_CONSTANT(TYPE_64SC);
  BIND_ENUM_CONSTANT(TYPE_32FC);
  BIND_ENUM_CONSTANT(TYPE_64FC);

  BIND_ENUM_CONSTANT(HINT_NONE);
  BIND_ENUM_CONSTANT(HINT_FAST);
  BIND_ENUM_CONSTANT(HINT_ACC);

  BIND_ENUM_CONSTANT(RND_ZERO);
  BIND_ENUM_CONSTANT(RND_NEAR);
  BIND_ENUM_CONSTANT(RND_FINANCIAL);

  BIND_ENUM_CONSTANT(STAT_CPU_NOT_SUPPORTED);
//  BIND_ENUM_CONSTANT(STAT_POINT_AT_INIFINTY);
//  BIND_ENUM_CONSTANT(STAT_I18N_UNSOPPORTED);
//  BIND_ENUM_CONSTANT(STAT_I18N_MSG_CATALOG_OPEN_ERR);
//  BIND_ENUM_CONSTANT(STAT_I18N_MSG_CATALOG_CLOSE_ERR);
  BIND_ENUM_CONSTANT(STAT_UNKNOWN_STATUS_CODE_ERR);
//  BIND_ENUM_CONSTANT(STAT_OFB_SIZE_ERR);
  BIND_ENUM_CONSTANT(STAT_LZO_BROKEN_STREAM_ERR);
  BIND_ENUM_CONSTANT(STAT_ROUND_MODE_NOT_SUPPORTED_ERR);
//  BIND_ENUM_CONSTANT(STAT_MAX_LEN_HUFF_CODE_ERR);
//  BIND_ENUM_CONSTANT(STAT_CODE_LEN_TABLE_ERR);
//  BIND_ENUM_CONSTANT(STAT_FREQ_TABLE_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_OPTIONS_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_MATCH_LIMIT_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_QUANTIFIER_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_GROUPING_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_BACK_REF_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_CHAR_CLASS_ERR);
  BIND_ENUM_CONSTANT(STAT_REG_EXP_META_CHAR_ERR);
//  BIND_ENUM_CONSTANT(STAT_MP3_FRAME_HEADER_ERR);
//  BIND_ENUM_CONSTANT(STAT_MP3_SIDE_INFO_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PRG_NUM_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SECT_CB_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SF_VAL_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_COEFF_VAL_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_MAX_SF_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PRED_SF_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PLS_DATA_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_GAIN_CTR_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SECT_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_NUM_FILT_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_LEN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_ORDER_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_COEFF_RES_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_COEFF_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_DIRECT_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_TNS_PROFILE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_BIT_OFFSET_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_ADTS_SYNC_WORD_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SAMPLE_RATE_INDEX_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_LEN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_GRP_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_SEQ_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_COM_WIN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_STEREO_MASK_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_CHAN_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_MONO_STEREO_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_STEREO_LAYER_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_MONO_LAYER_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_SCALABLE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_OBJ_TYPE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_WIN_SHAPE_ERR);
//  BIND_ENUM_CONSTANT(STAT_AAC_PCM_MODE_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_HEADER_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_UNSUPPORTED_FORMAT_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_ESC_ALG_TYPE_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_ESC_CODE_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_USR_TBL_CODE_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_INTERNAL_TABLE_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_INPUT_DATA_ERR);
//  BIND_ENUM_CONSTANT(STAT_VLC_AAC_ESC_CODE_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_INCORRECT_SP_ERR);
//  BIND_ENUM_CONSTANT(STAT_NO_ROOT_FOUND_ERR);
  BIND_ENUM_CONSTANT(STAT_LENGTH_ERR);
//  BIND_ENUM_CONSTANT(STAT_FBANK_FREQ_ERR);
//  BIND_ENUM_CONSTANT(STAT_FBANK_FLAG_ERR);
//  BIND_ENUM_CONSTANT(STAT_FBANK_ERR);
//  BIND_ENUM_CONSTANT(STAT_NEG_OCC_ERR);
//  BIND_ENUM_CONSTANT(STAT_CDBK_FLAG_ERR);
//  BIND_ENUM_CONSTANT(STAT_SVD_CNVG_ERR);
  BIND_ENUM_CONSTANT(STAT_TONE_MAGN_ERR);
  BIND_ENUM_CONSTANT(STAT_TONE_FREQ_ERR);
  BIND_ENUM_CONSTANT(STAT_TONE_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_MAGN_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_FREQ_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_TRNGL_ASYM_ERR);
  BIND_ENUM_CONSTANT(STAT_HUGE_WIN_ERR);
  BIND_ENUM_CONSTANT(STAT_JAEHNE_ERR);
  BIND_ENUM_CONSTANT(STAT_STEP_ERR);
//  BIND_ENUM_CONSTANT(STAT_DLY_LINE_INDEX_ERR);
  BIND_ENUM_CONSTANT(STAT_STRIDE_ERR);
  BIND_ENUM_CONSTANT(STAT_EPS_VAL_ERR);
  BIND_ENUM_CONSTANT(STAT_SCALE_RANGE_ERR);
  BIND_ENUM_CONSTANT(STAT_THESHOLD_ERR);
  BIND_ENUM_CONSTANT(STAT_WT_OFFSET_ERR);
  BIND_ENUM_CONSTANT(STAT_ANCHOR_ERR);
  BIND_ENUM_CONSTANT(STAT_MASK_SIZE_ERR);
  BIND_ENUM_CONSTANT(STAT_SHIFT_ERR);
  BIND_ENUM_CONSTANT(STAT_SAMPLE_FACTOR_ERR);
  BIND_ENUM_CONSTANT(STAT_SAMPLE_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_FIR_MR_FACTOR_ERR);
  BIND_ENUM_CONSTANT(STAT_FIR_MR_PHASE_ERR);
  BIND_ENUM_CONSTANT(STAT_REL_FREQ_ERR);
  BIND_ENUM_CONSTANT(STAT_FIR_LEN_ERR);
  BIND_ENUM_CONSTANT(STAT_IIR_ORDER_ERR);
  BIND_ENUM_CONSTANT(STAT_RESIZE_FACTOR_ERR);
  BIND_ENUM_CONSTANT(STAT_DIV_BY_ZERO_ERR);
  BIND_ENUM_CONSTANT(STAT_INTERPOLATION_ERR);
  BIND_ENUM_CONSTANT(STAT_MIRROR_FLIP_ERR);
  BIND_ENUM_CONSTANT(STAT_MOMENT_00_ZERO_ERR);
  BIND_ENUM_CONSTANT(STAT_THRESH_NEG_LEVEL_ERR);
  BIND_ENUM_CONSTANT(STAT_CONTEXT_MATCH_ERR);
  BIND_ENUM_CONSTANT(STAT_FFT_FLAG_ERR);
  BIND_ENUM_CONSTANT(STAT_FFT_ORDER_ERR);
  BIND_ENUM_CONSTANT(STAT_MEM_ALLOC_ERR);
  BIND_ENUM_CONSTANT(STAT_NULL_PTR_ERR);
  BIND_ENUM_CONSTANT(STAT_SIZE_ERR);
  BIND_ENUM_CONSTANT(STAT_BAD_ARG_ERR);
  BIND_ENUM_CONSTANT(STAT_ERR);
  BIND_ENUM_CONSTANT(STAT_NO_ERR);
  BIND_ENUM_CONSTANT(STAT_NO_OPERATION);
//  BIND_ENUM_CONSTANT(STAT_MISALIGNED_BUF);
  BIND_ENUM_CONSTANT(STAT_SQRT_NEG_ARG);
//  BIND_ENUM_CONSTANT(STAT_INV_BY_ZERO);
  BIND_ENUM_CONSTANT(STAT_EVEN_MEDIAN_MASK);
  BIND_ENUM_CONSTANT(STAT_DIV_BY_ZERO);
  BIND_ENUM_CONSTANT(STAT_LN_ZERO_ARG);
  BIND_ENUM_CONSTANT(STAT_LN_NEG_ARG);
  BIND_ENUM_CONSTANT(STAT_NAN_ARG);
//  BIND_ENUM_CONSTANT(STAT_RES_FLOOR);
  BIND_ENUM_CONSTANT(STAT_OVERFLOW);
//  BIND_ENUM_CONSTANT(STAT_ZERO_OCC);
  BIND_ENUM_CONSTANT(STAT_UNDERFLOW);
  BIND_ENUM_CONSTANT(STAT_SINGULARITY);
  BIND_ENUM_CONSTANT(STAT_DOMAIN);
//  BIND_ENUM_CONSTANT(STAT_NOT_INTEL_CPU);
  BIND_ENUM_CONSTANT(STAT_CPU_MISMATCH);
//  BIND_ENUM_CONSTANT(STAT_NOT_IPP_FUNCTION_FOUND);
//  BIND_ENUM_CONSTANT(STAT_DLL_NOT_FOUND_BEST_USED);
//  BIND_ENUM_CONSTANT(STAT_NO_OPERTION_IN_DLL);
  BIND_ENUM_CONSTANT(STAT_OVERMUCH_STRINGS);
  BIND_ENUM_CONSTANT(STAT_OVERLONG_STRING);
  BIND_ENUM_CONSTANT(STAT_SRC_SIZE_LESS_EXPECTED);
  BIND_ENUM_CONSTANT(STAT_DST_SIZE_LESS_EXPECTED);
  BIND_ENUM_CONSTANT(STAT_NOT_SUPPORTED_CPU);
//  BIND_ENUM_CONSTANT(STAT_UNKNOWN_CACHE_SIZE);
  BIND_ENUM_CONSTANT(STAT_ALG_TYPE_ERR);
}

