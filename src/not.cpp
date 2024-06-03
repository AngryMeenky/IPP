#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(not_8u, ippsNot_8u, 8U, 8u, 8U, 8u)
IPP_UOP(not_16u, ippsNot_16u, 16U, 16u, 16U, 16u)
IPP_UOP(not_32u, ippsNot_32u, 32U, 32u, 32U, 32u)

IPP_UOP_I(not_8u_I, ippsNot_8u_I, 8U, 8u)
IPP_UOP_I(not_16u_I, ippsNot_16u_I, 16U, 16u)
IPP_UOP_I(not_32u_I, ippsNot_32u_I, 32U, 32u)

