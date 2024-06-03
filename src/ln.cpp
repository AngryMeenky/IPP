#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(ln_32f, ippsLn_32f, 32F, 32f, 32F, 32f)
IPP_UOP(ln_64f, ippsLn_64f, 64F, 64f, 64F, 64f)

IPP_UOP_I(ln_32f_I, ippsLn_32f_I, 32F, 32f)
IPP_UOP_I(ln_64f_I, ippsLn_64f_I, 64F, 64f)

IPP_UOP_SFS(ln_16s_Sfs, ippsLn_16s_Sfs, 16S, 16s, 16S, 16s)
IPP_UOP_SFS(ln_32s_Sfs, ippsLn_32s_Sfs, 32S, 32s, 32S, 32s)

IPP_UOP_ISFS(ln_16s_ISfs, ippsLn_16s_ISfs, 16S, 16s)
IPP_UOP_ISFS(ln_32s_ISfs, ippsLn_32s_ISfs, 32S, 32s)

