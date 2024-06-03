#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(sqrt_32f, ippsSqrt_32f, 32F, 32f, 32F, 32f)
IPP_UOP(sqrt_64f, ippsSqrt_64f, 64F, 64f, 64F, 64f)
IPP_UOP(sqrt_32fc, ippsSqrt_32fc, 32FC, 32fc, 32FC, 32fc)
IPP_UOP(sqrt_64fc, ippsSqrt_64fc, 64FC, 64fc, 64FC, 64fc)

IPP_UOP_SFS(sqrt_8u_Sfs, ippsSqrt_8u_Sfs, 8U, 8u, 8U, 8u)
IPP_UOP_SFS(sqrt_16u_Sfs, ippsSqrt_16u_Sfs, 16U, 16u, 16U, 16u)
IPP_UOP_SFS(sqrt_16s_Sfs, ippsSqrt_16s_Sfs, 16S, 16s, 16S, 16s)
IPP_UOP_SFS(sqrt_16sc_Sfs, ippsSqrt_16sc_Sfs, 16SC, 16sc, 16SC, 16sc)
IPP_UOP_SFS(sqrt_32s16s_Sfs, ippsSqrt_32s16s_Sfs, 32S, 32s, 16S, 16s)

IPP_UOP_I(sqrt_32f_I, ippsSqrt_32f_I, 32F, 32f)
IPP_UOP_I(sqrt_64f_I, ippsSqrt_64f_I, 64F, 64f)
IPP_UOP_I(sqrt_32fc_I, ippsSqrt_32fc_I, 32FC, 32fc)
IPP_UOP_I(sqrt_64fc_I, ippsSqrt_64fc_I, 64FC, 64fc)

IPP_UOP_ISFS(sqrt_8u_ISfs, ippsSqrt_8u_ISfs, 8U, 8u)
IPP_UOP_ISFS(sqrt_16u_ISfs, ippsSqrt_16u_ISfs, 16U, 16u)
IPP_UOP_ISFS(sqrt_16s_ISfs, ippsSqrt_16s_ISfs, 16S, 16s)
IPP_UOP_ISFS(sqrt_16sc_ISfs, ippsSqrt_16sc_ISfs, 16SC, 16sc)

