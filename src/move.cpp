#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP_S(move_8u, ippsMove_8u, 8, 8u, 8, 8u)
IPP_UOP_S(move_16s, ippsMove_16s, 16, 16s, 16, 16s)
IPP_UOP_S(move_32s, ippsMove_32s, 32, 32s, 32, 32s)
IPP_UOP_S(move_64s, ippsMove_64s, 64, 64s, 64, 64s)

IPP_UOP(move_32f, ippsMove_32f, 32F, 32f, 32F, 32f)
IPP_UOP(move_64f, ippsMove_64f, 64F, 64f, 64F, 64f)
IPP_UOP(move_16sc, ippsMove_16sc, 16SC, 16sc, 16SC, 16sc)
IPP_UOP(move_32sc, ippsMove_32sc, 32SC, 32sc, 32SC, 32sc)
IPP_UOP(move_64sc, ippsMove_64sc, 64SC, 64sc, 64SC, 64sc)
IPP_UOP(move_32fc, ippsMove_32fc, 32FC, 32fc, 32FC, 32fc)
IPP_UOP(move_64fc, ippsMove_64fc, 64FC, 64fc, 64FC, 64fc)

