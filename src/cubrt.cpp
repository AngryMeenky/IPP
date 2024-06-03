#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(cubrt_32f, ippsCubrt_32f, 32F, 32f, 32F, 32f)
IPP_UOP_SFS(cubrt_32s16s_Sfs, ippsCubrt_32s16s_Sfs, 32S, 32s, 16S, 16s)

