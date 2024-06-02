#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(xorC_8u, ippsXorC_8u, 8U, 8u, 8U, 8u, int)
IPP_OP_C(xorC_16u, ippsXorC_16u, 16U, 16u, 16U, 16u, int)
IPP_OP_C(xorC_32u, ippsXorC_32u, 32U, 32u, 32U, 32u, uint32_t)

IPP_OP_C_I(xorC_8u_I, ippsXorC_8u_I, 8U, 8u, int)
IPP_OP_C_I(xorC_16u_I, ippsXorC_16u_I, 16U, 16u, int)
IPP_OP_C_I(xorC_32u_I, ippsXorC_32u_I, 32U, 32u, uint32_t)

IPP_OP(xor_8u, ippsXor_8u, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP(xor_16u, ippsXor_16u, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP(xor_32u, ippsXor_32u, 32U, 32u, 32U, 32u, 32U, 32u)

IPP_OP_I(xor_8u_I, ippsXor_8u_I, 8U, 8u, 8U, 8u)
IPP_OP_I(xor_16u_I, ippsXor_16u_I, 16U, 16u, 16U, 16u)
IPP_OP_I(xor_32u_I, ippsXor_32u_I, 32U, 32u, 32U, 32u)

