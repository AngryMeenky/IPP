#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP_S(copy_8u, ippsCopy_8u, 8, 8u, 8, 8u)
IPP_UOP_S(copy_16s, ippsCopy_16s, 16, 16s, 16, 16s)
IPP_UOP_S(copy_32s, ippsCopy_32s, 32, 32s, 32, 32s)
IPP_UOP_S(copy_64s, ippsCopy_64s, 64, 64s, 64, 64s)

IPP_UOP(copy_32f, ippsCopy_32f, 32F, 32f, 32F, 32f)
IPP_UOP(copy_64f, ippsCopy_64f, 64F, 64f, 64F, 64f)
IPP_UOP(copy_16sc, ippsCopy_16sc, 16SC, 16sc, 16SC, 16sc)
IPP_UOP(copy_32sc, ippsCopy_32sc, 32SC, 32sc, 32SC, 32sc)
IPP_UOP(copy_64sc, ippsCopy_64sc, 64SC, 64sc, 64SC, 64sc)
IPP_UOP(copy_32fc, ippsCopy_32fc, 32FC, 32fc, 32FC, 32fc)
IPP_UOP(copy_64fc, ippsCopy_64fc, 64FC, 64fc, 64FC, 64fc)

