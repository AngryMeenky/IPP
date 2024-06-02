#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(orC_8u, ippsOrC_8u, 8U, 8u, 8U, 8u, int)
IPP_OP_C(orC_16u, ippsOrC_16u, 16U, 16u, 16U, 16u, int)
IPP_OP_C(orC_32u, ippsOrC_32u, 32U, 32u, 32U, 32u, uint32_t)

IPP_OP_C_I(orC_8u_I, ippsOrC_8u_I, 8U, 8u, int)
IPP_OP_C_I(orC_16u_I, ippsOrC_16u_I, 16U, 16u, int)
IPP_OP_C_I(orC_32u_I, ippsOrC_32u_I, 32U, 32u, uint32_t)

IPP_OP(or_8u, ippsOr_8u, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP(or_16u, ippsOr_16u, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP(or_32u, ippsOr_32u, 32U, 32u, 32U, 32u, 32U, 32u)

IPP_OP_I(or_8u_I, ippsOr_8u_I, 8U, 8u, 8U, 8u)
IPP_OP_I(or_16u_I, ippsOr_16u_I, 16U, 16u, 16U, 16u)
IPP_OP_I(or_32u_I, ippsOr_32u_I, 32U, 32u, 32U, 32u)

