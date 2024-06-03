#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(arctan_32f, ippsArctan_32f, 32F, 32f, 32F, 32f)
IPP_UOP(arctan_64f, ippsArctan_64f, 64F, 64f, 64F, 64f)

IPP_UOP_I(arctan_32f_I, ippsArctan_32f_I, 32F, 32f)
IPP_UOP_I(arctan_64f_I, ippsArctan_64f_I, 64F, 64f)

