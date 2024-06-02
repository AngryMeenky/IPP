#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(divC_32f, ippsDivC_32f, 32F, 32f, 32F, 32f, float)
IPP_OP_C(divC_64f, ippsDivC_64f, 64F, 64f, 64F, 64f, double)

IPP_OP_CV(divC_32fc, ippsDivC_32fc, 32FC, 32fc, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV(divC_64fc, ippsDivC_64fc, 64FC, 64fc, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_SFS(divC_8u_Sfs, ippsDivC_8u_Sfs, 8U, 8u, 8U, 8u, int)
IPP_OP_C_SFS(divC_16u_Sfs, ippsDivC_16u_Sfs, 16U, 16u, 16U, 16u, int)
IPP_OP_C_SFS(divC_16s_Sfs, ippsDivC_16s_Sfs, 16S, 16s, 16S, 16s, int)

IPP_OP_CV_SFS(divC_16sc_Sfs, ippsDivC_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, Vector2i, 16s)

IPP_OP_C_I(divC_32f_I, ippsDivC_32f_I, 32F, 32f, float)
IPP_OP_C_I(divC_64f_I, ippsDivC_64f_I, 64F, 64f, double)

IPP_OP_CV_I(divC_32fc_I, ippsDivC_32fc_I, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV_I(divC_64fc_I, ippsDivC_64fc_I, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_ISFS(divC_8u_ISfs, ippsDivC_8u_ISfs, 8U, 8u, int)
IPP_OP_C_ISFS(divC_16u_ISfs, ippsDivC_16u_ISfs, 16U, 16u, int)
IPP_OP_C_ISFS(divC_16s_ISfs, ippsDivC_16s_ISfs, 16S, 16s, int)
IPP_OP_C_ISFS(divC_64s_ISfs, ippsDivC_64s_ISfs, 64S, 64s, int64_t)

IPP_OP_CV_ISFS(divC_16sc_ISfs, ippsDivC_16sc_ISfs, 16SC, 16sc, Vector2i, 16s)

IPP_OP_C(divCRev_16u, ippsDivCRev_16u, 16U, 16u, 16U, 16u, int)
IPP_OP_C(divCRev_32f, ippsDivCRev_32f, 32F, 32f, 32F, 32f, float)

IPP_OP_C_I(divCRev_16u_I, ippsDivCRev_16u_I, 16U, 16u, int)
IPP_OP_C_I(divCRev_32f_I, ippsDivCRev_32f_I, 32F, 32f, float)

IPP_OP(div_32f, ippsDiv_32f, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(div_64f, ippsDiv_64f, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(div_32fc, ippsDiv_32fc, 32FC, 32fc, 32FC, 32fc, 32FC, 32fc)
IPP_OP(div_64fc, ippsDiv_64fc, 64FC, 64fc, 64FC, 64fc, 64FC, 64fc)

IPP_OP_SFS(div_8u_Sfs, ippsDiv_8u_Sfs, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP_SFS(div_16u_Sfs, ippsDiv_16u_Sfs, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP_SFS(div_16s_Sfs, ippsDiv_16s_Sfs, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP_SFS(div_32s_Sfs, ippsDiv_32s_Sfs, 32S, 32s, 32S, 32s, 32S, 32s)
IPP_OP_SFS(div_16sc_Sfs, ippsDiv_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, 16SC, 16sc)
IPP_OP_SFS(div_32s16s_Sfs, ippsDiv_32s16s_Sfs, 16S, 16s, 32S, 32s, 16S, 16s)

IPP_OP_I(div_32f_I, ippsDiv_32f_I, 32F, 32f, 32F, 32f)
IPP_OP_I(div_64f_I, ippsDiv_64f_I, 64F, 64f, 64F, 64f)
IPP_OP_I(div_32fc_I, ippsDiv_32fc_I, 32FC, 32fc, 32FC, 32fc)
IPP_OP_I(div_64fc_I, ippsDiv_64fc_I, 64FC, 64fc, 64FC, 64fc)

IPP_OP_ISFS(div_8u_ISfs, ippsDiv_8u_ISfs, 8U, 8u, 8U, 8u)
IPP_OP_ISFS(div_16u_ISfs, ippsDiv_16u_ISfs, 16U, 16u, 16U, 16u)
IPP_OP_ISFS(div_16s_ISfs, ippsDiv_16s_ISfs, 16S, 16s, 16S, 16s)
IPP_OP_ISFS(div_32s_ISfs, ippsDiv_32s_ISfs, 32S, 32s, 32S, 32s)
IPP_OP_ISFS(div_16sc_ISfs, ippsDiv_16sc_ISfs, 16SC, 16sc, 16SC, 16sc)

IPP_OP_SFS_R(div_round_8u_Sfs, ippsDiv_Round_8u_Sfs, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP_SFS_R(div_round_16u_Sfs, ippsDiv_Round_16u_Sfs, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP_SFS_R(div_round_16s_Sfs, ippsDiv_Round_16s_Sfs, 16S, 16s, 16S, 16s, 16S, 16s)

IPP_OP_ISFS_R(div_round_8u_ISfs, ippsDiv_Round_8u_ISfs, 8U, 8u, 8U, 8u)
IPP_OP_ISFS_R(div_round_16u_ISfs, ippsDiv_Round_16u_ISfs, 16U, 16u, 16U, 16u)
IPP_OP_ISFS_R(div_round_16s_ISfs, ippsDiv_Round_16s_ISfs, 16S, 16s, 16S, 16s)

