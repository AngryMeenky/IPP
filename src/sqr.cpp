#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(sqr_32f, ippsSqr_32f, 32F, 32f, 32F, 32f)
IPP_UOP(sqr_64f, ippsSqr_64f, 64F, 64f, 64F, 64f)
IPP_UOP(sqr_32fc, ippsSqr_32fc, 32FC, 32fc, 32FC, 32fc)
IPP_UOP(sqr_64fc, ippsSqr_64fc, 64FC, 64fc, 64FC, 64fc)

IPP_UOP_SFS(sqr_8u_Sfs, ippsSqr_8u_Sfs, 8U, 8u, 8U, 8u)
IPP_UOP_SFS(sqr_16u_Sfs, ippsSqr_16u_Sfs, 16U, 16u, 16U, 16u)
IPP_UOP_SFS(sqr_16s_Sfs, ippsSqr_16s_Sfs, 16S, 16s, 16S, 16s)
IPP_UOP_SFS(sqr_16sc_Sfs, ippsSqr_16sc_Sfs, 16SC, 16sc, 16SC, 16sc)

IPP_UOP_I(sqr_32f_I, ippsSqr_32f_I, 32F, 32f)
IPP_UOP_I(sqr_64f_I, ippsSqr_64f_I, 64F, 64f)
IPP_UOP_I(sqr_32fc_I, ippsSqr_32fc_I, 32FC, 32fc)
IPP_UOP_I(sqr_64fc_I, ippsSqr_64fc_I, 64FC, 64fc)

IPP_UOP_ISFS(sqr_8u_ISfs, ippsSqr_8u_ISfs, 8U, 8u)
IPP_UOP_ISFS(sqr_16u_ISfs, ippsSqr_16u_ISfs, 16U, 16u)
IPP_UOP_ISFS(sqr_16s_ISfs, ippsSqr_16s_ISfs, 16S, 16s)
IPP_UOP_ISFS(sqr_16sc_ISfs, ippsSqr_16sc_ISfs, 16SC, 16sc)

