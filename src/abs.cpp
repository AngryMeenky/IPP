#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(abs_16s, ippsAbs_16s, 16S, 16s, 16S, 16s)
IPP_UOP(abs_32s, ippsAbs_32s, 32S, 32s, 32S, 32s)
IPP_UOP(abs_32f, ippsAbs_32f, 32F, 32f, 32F, 32f)
IPP_UOP(abs_64f, ippsAbs_64f, 64F, 64f, 64F, 64f)

IPP_UOP_I(abs_16s_I, ippsAbs_16s_I, 16S, 16s)
IPP_UOP_I(abs_32s_I, ippsAbs_32s_I, 32S, 32s)
IPP_UOP_I(abs_32f_I, ippsAbs_32f_I, 32F, 32f)
IPP_UOP_I(abs_64f_I, ippsAbs_64f_I, 64F, 64f)

