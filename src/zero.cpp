#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP_SI(zero_8u, ippsZero_8u, 8, 8u)
IPP_UOP_SI(zero_16s, ippsZero_16s, 16, 16s)
IPP_UOP_SI(zero_32s, ippsZero_32s, 32, 32s)
IPP_UOP_SI(zero_64s, ippsZero_64s, 64, 64s)

IPP_UOP_I(zero_32f, ippsZero_32f, 32F, 32f)
IPP_UOP_I(zero_64f, ippsZero_64f, 64F, 64f)
IPP_UOP_I(zero_16sc, ippsZero_16sc, 16SC, 16sc)
IPP_UOP_I(zero_32sc, ippsZero_32sc, 32SC, 32sc)
IPP_UOP_I(zero_64sc, ippsZero_64sc, 64SC, 64sc)
IPP_UOP_I(zero_32fc, ippsZero_32fc, 32FC, 32fc)
IPP_UOP_I(zero_64fc, ippsZero_64fc, 64FC, 64fc)

