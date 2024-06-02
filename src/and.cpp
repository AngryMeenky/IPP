#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(andC_8u, ippsAndC_8u, 8U, 8u, 8U, 8u, int)
IPP_OP_C(andC_16u, ippsAndC_16u, 16U, 16u, 16U, 16u, int)
IPP_OP_C(andC_32u, ippsAndC_32u, 32U, 32u, 32U, 32u, uint32_t)

IPP_OP_C_I(andC_8u_I, ippsAndC_8u_I, 8U, 8u, int)
IPP_OP_C_I(andC_16u_I, ippsAndC_16u_I, 16U, 16u, int)
IPP_OP_C_I(andC_32u_I, ippsAndC_32u_I, 32U, 32u, uint32_t)

IPP_OP(and_8u, ippsAnd_8u, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP(and_16u, ippsAnd_16u, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP(and_32u, ippsAnd_32u, 32U, 32u, 32U, 32u, 32U, 32u)

IPP_OP_I(and_8u_I, ippsAnd_8u_I, 8U, 8u, 8U, 8u)
IPP_OP_I(and_16u_I, ippsAnd_16u_I, 16U, 16u, 16U, 16u)
IPP_OP_I(and_32u_I, ippsAnd_32u_I, 32U, 32u, 32U, 32u)

