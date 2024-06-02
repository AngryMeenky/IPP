
#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(l_shiftC_8u, ippsLShiftC_8u, 8U, 8u, 8U, 8u, int)
IPP_OP_C(l_shiftC_16s, ippsLShiftC_16s, 16S, 16s, 16S, 16s, int)
IPP_OP_C(l_shiftC_16u, ippsLShiftC_16u, 16S, 16u, 16S, 16u, int)
IPP_OP_C(l_shiftC_32s, ippsLShiftC_32s, 32S, 32s, 32S, 32s, int)

IPP_OP_C_I(l_shiftC_8u_I, ippsLShiftC_8u_I, 8U, 8u, int)
IPP_OP_C_I(l_shiftC_16s_I, ippsLShiftC_16s_I, 16S, 16s, int)
IPP_OP_C_I(l_shiftC_16u_I, ippsLShiftC_16u_I, 16S, 16u, int)
IPP_OP_C_I(l_shiftC_32s_I, ippsLShiftC_32s_I, 32S, 32s, int)

IPP_OP_C(r_shiftC_8u, ippsRShiftC_8u, 8U, 8u, 8U, 8u, int)
IPP_OP_C(r_shiftC_16s, ippsRShiftC_16s, 16S, 16s, 16S, 16s, int)
IPP_OP_C(r_shiftC_16u, ippsRShiftC_16u, 16S, 16u, 16S, 16u, int)
IPP_OP_C(r_shiftC_32s, ippsRShiftC_32s, 32S, 32s, 32S, 32s, int)

IPP_OP_C_I(r_shiftC_8u_I, ippsRShiftC_8u_I, 8U, 8u, int)
IPP_OP_C_I(r_shiftC_16s_I, ippsRShiftC_16s_I, 16S, 16s, int)
IPP_OP_C_I(r_shiftC_16u_I, ippsRShiftC_16u_I, 16S, 16u, int)
IPP_OP_C_I(r_shiftC_32s_I, ippsRShiftC_32s_I, 32S, 32s, int)

