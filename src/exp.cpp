#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(exp_32f, ippsExp_32f, 32F, 32f, 32F, 32f)
IPP_UOP(exp_64f, ippsExp_64f, 64F, 64f, 64F, 64f)

IPP_UOP_I(exp_32f_I, ippsExp_32f_I, 32F, 32f)
IPP_UOP_I(exp_64f_I, ippsExp_64f_I, 64F, 64f)

IPP_UOP_SFS(exp_16s_Sfs, ippsExp_16s_Sfs, 16S, 16s, 16S, 16s)
IPP_UOP_SFS(exp_32s_Sfs, ippsExp_32s_Sfs, 32S, 32s, 32S, 32s)

IPP_UOP_ISFS(exp_16s_ISfs, ippsExp_16s_ISfs, 16S, 16s)
IPP_UOP_ISFS(exp_32s_ISfs, ippsExp_32s_ISfs, 32S, 32s)

