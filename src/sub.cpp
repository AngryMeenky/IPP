#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(subC_32f, ippsSubC_32f, 32F, 32f, 32F, 32f, float)
IPP_OP_C(subC_64f, ippsSubC_64f, 64F, 64f, 64F, 64f, double)

IPP_OP_CV(subC_32fc, ippsSubC_32fc, 32FC, 32fc, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV(subC_64fc, ippsSubC_64fc, 64FC, 64fc, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_SFS(subC_8u_Sfs, ippsSubC_8u_Sfs, 8U, 8u, 8U, 8u, int)
IPP_OP_C_SFS(subC_16u_Sfs, ippsSubC_16u_Sfs, 16U, 16u, 16U, 16u, int)
IPP_OP_C_SFS(subC_16s_Sfs, ippsSubC_16s_Sfs, 16S, 16s, 16S, 16s, int)
IPP_OP_C_SFS(subC_32s_Sfs, ippsSubC_32s_Sfs, 32S, 32s, 32S, 32s, int)

IPP_OP_CV_SFS(subC_16sc_Sfs, ippsSubC_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_SFS(subC_32sc_Sfs, ippsSubC_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, Vector2i, 32s)

IPP_OP_C_I(subC_32f_I, ippsSubC_32f_I, 32F, 32f, float)
IPP_OP_C_I(subC_64f_I, ippsSubC_64f_I, 64F, 64f, double)

IPP_OP_CV_I(subC_32fc_I, ippsSubC_32fc_I, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV_I(subC_64fc_I, ippsSubC_64fc_I, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_ISFS(subC_8u_ISfs, ippsSubC_8u_ISfs, 8U, 8u, int)
IPP_OP_C_ISFS(subC_16u_ISfs, ippsSubC_16u_ISfs, 16U, 16u, int)
IPP_OP_C_ISFS(subC_16s_ISfs, ippsSubC_16s_ISfs, 16S, 16s, int)
IPP_OP_C_ISFS(subC_32s_ISfs, ippsSubC_32s_ISfs, 32S, 32s, int)

IPP_OP_CV_ISFS(subC_16sc_ISfs, ippsSubC_16sc_ISfs, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_ISFS(subC_32sc_ISfs, ippsSubC_32sc_ISfs, 32SC, 32sc, Vector2i, 32s)

IPP_OP_C(subCRev_32f, ippsSubCRev_32f, 32F, 32f, 32F, 32f, float)
IPP_OP_C(subCRev_64f, ippsSubCRev_64f, 64F, 64f, 64F, 64f, double)

IPP_OP_CV(subCRev_32fc, ippsSubCRev_32fc, 32FC, 32fc, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV(subCRev_64fc, ippsSubCRev_64fc, 64FC, 64fc, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_SFS(subCRev_8u_Sfs, ippsSubCRev_8u_Sfs, 8U, 8u, 8U, 8u, int)
IPP_OP_C_SFS(subCRev_16u_Sfs, ippsSubCRev_16u_Sfs, 16U, 16u, 16U, 16u, int)
IPP_OP_C_SFS(subCRev_16s_Sfs, ippsSubCRev_16s_Sfs, 16S, 16s, 16S, 16s, int)
IPP_OP_C_SFS(subCRev_32s_Sfs, ippsSubCRev_32s_Sfs, 32S, 32s, 32S, 32s, int)

IPP_OP_CV_SFS(subCRev_16sc_Sfs, ippsSubCRev_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_SFS(subCRev_32sc_Sfs, ippsSubCRev_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, Vector2i, 32s)

IPP_OP_C_I(subCRev_32f_I, ippsSubCRev_32f_I, 32F, 32f, float)
IPP_OP_C_I(subCRev_64f_I, ippsSubCRev_64f_I, 64F, 64f, double)

IPP_OP_CV_I(subCRev_32fc_I, ippsSubCRev_32fc_I, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV_I(subCRev_64fc_I, ippsSubCRev_64fc_I, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_ISFS(subCRev_8u_ISfs, ippsSubCRev_8u_ISfs, 8U, 8u, int)
IPP_OP_C_ISFS(subCRev_16u_ISfs, ippsSubCRev_16u_ISfs, 16U, 16u, int)
IPP_OP_C_ISFS(subCRev_16s_ISfs, ippsSubCRev_16s_ISfs, 16S, 16s, int)
IPP_OP_C_ISFS(subCRev_32s_ISfs, ippsSubCRev_32s_ISfs, 32S, 32s, int)

IPP_OP_CV_ISFS(subCRev_16sc_ISfs, ippsSubCRev_16sc_ISfs, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_ISFS(subCRev_32sc_ISfs, ippsSubCRev_32sc_ISfs, 32SC, 32sc, Vector2i, 32s)

IPP_OP(sub_16s, ippsSub_16s, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP(sub_32f, ippsSub_32f, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(sub_64f, ippsSub_64f, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(sub_32fc, ippsSub_32fc, 32FC, 32fc, 32FC, 32fc, 32FC, 32fc)
IPP_OP(sub_64fc, ippsSub_64fc, 64FC, 64fc, 64FC, 64fc, 64FC, 64fc)
IPP_OP(sub_16s32f, ippsSub_16s32f, 16S, 16s, 16S, 16s, 32F, 32f)

IPP_OP_SFS(sub_8u_Sfs, ippsSub_8u_Sfs, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP_SFS(sub_16u_Sfs, ippsSub_16u_Sfs, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP_SFS(sub_16s_Sfs, ippsSub_16s_Sfs, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP_SFS(sub_32s_Sfs, ippsSub_32s_Sfs, 32S, 32s, 32S, 32s, 32S, 32s)
IPP_OP_SFS(sub_16sc_Sfs, ippsSub_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, 16SC, 16sc)
IPP_OP_SFS(sub_32sc_Sfs, ippsSub_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, 32SC, 32sc)

IPP_OP_I(sub_16s_I, ippsSub_16s_I, 16S, 16s, 16S, 16s)
IPP_OP_I(sub_32f_I, ippsSub_32f_I, 32F, 32f, 32F, 32f)
IPP_OP_I(sub_64f_I, ippsSub_64f_I, 64F, 64f, 64F, 64f)
IPP_OP_I(sub_32fc_I, ippsSub_32fc_I, 32FC, 32fc, 32FC, 32fc)
IPP_OP_I(sub_64fc_I, ippsSub_64fc_I, 64FC, 64fc, 64FC, 64fc)

IPP_OP_ISFS(sub_8u_ISfs, ippsSub_8u_ISfs, 8U, 8u, 8U, 8u)
IPP_OP_ISFS(sub_16u_ISfs, ippsSub_16u_ISfs, 16U, 16u, 16U, 16u)
IPP_OP_ISFS(sub_16s_ISfs, ippsSub_16s_ISfs, 16S, 16s, 16S, 16s)
IPP_OP_ISFS(sub_32s_ISfs, ippsSub_32s_ISfs, 32S, 32s, 32S, 32s)
IPP_OP_ISFS(sub_16sc_ISfs, ippsSub_16sc_ISfs, 16SC, 16sc, 16SC, 16sc)
IPP_OP_ISFS(sub_32sc_ISfs, ippsSub_32sc_ISfs, 32SC, 32sc, 32SC, 32sc)

