#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(addC_32f, ippsAddC_32f, 32F, 32f, 32F, 32f, float)
IPP_OP_C(addC_64f, ippsAddC_64f, 64F, 64f, 64F, 64f, double)

IPP_OP_CV(addC_32fc, ippsAddC_32fc, 32FC, 32fc, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV(addC_64fc, ippsAddC_64fc, 64FC, 64fc, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_SFS(addC_8u_Sfs, ippsAddC_8u_Sfs, 8U, 8u, 8U, 8u, int)
IPP_OP_C_SFS(addC_16u_Sfs, ippsAddC_16u_Sfs, 16U, 16u, 16U, 16u, int)
IPP_OP_C_SFS(addC_16s_Sfs, ippsAddC_16s_Sfs, 16S, 16s, 16S, 16s, int)
IPP_OP_C_SFS(addC_32s_Sfs, ippsAddC_32s_Sfs, 32S, 32s, 32S, 32s, int)

IPP_OP_C_SFS_R(addC_64s_Sfs, ippsAddC_64s_Sfs, 64S, 64s, 64S, 64s, int64_t)
IPP_OP_C_SFS_R(addC_64u_Sfs, ippsAddC_64u_Sfs, 64U, 64u, 64U, 64u, uint64_t)

IPP_OP_CV_SFS(addC_16sc_Sfs, ippsAddC_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_SFS(addC_32sc_Sfs, ippsAddC_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, Vector2i, 32s)

IPP_OP_C_I(addC_32f_I, ippsAddC_32f_I, 32F, 32f, float)
IPP_OP_C_I(addC_64f_I, ippsAddC_64f_I, 64F, 64f, double)

IPP_OP_CV_I(addC_32fc_I, ippsAddC_32fc_I, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV_I(addC_64fc_I, ippsAddC_64fc_I, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_ISFS(addC_8u_ISfs, ippsAddC_8u_ISfs, 8U, 8u, int)
IPP_OP_C_ISFS(addC_16u_ISfs, ippsAddC_16u_ISfs, 16U, 16u, int)
IPP_OP_C_ISFS(addC_16s_ISfs, ippsAddC_16s_ISfs, 16S, 16s, int)
IPP_OP_C_ISFS(addC_32s_ISfs, ippsAddC_32s_ISfs, 32S, 32s, int)

IPP_OP_CV_ISFS(addC_16sc_ISfs, ippsAddC_16sc_ISfs, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_ISFS(addC_32sc_ISfs, ippsAddC_32sc_ISfs, 32SC, 32sc, Vector2i, 32s)

IPP_OP(add_16s, ippsAdd_16s, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP(add_32f, ippsAdd_32f, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(add_64f, ippsAdd_64f, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(add_32fc, ippsAdd_32fc, 32FC, 32fc, 32FC, 32fc, 32FC, 32fc)
IPP_OP(add_64fc, ippsAdd_64fc, 64FC, 64fc, 64FC, 64fc, 64FC, 64fc)
IPP_OP(add_8u16u, ippsAdd_8u16u, 8U, 8u, 8U, 8u, 16U, 16u)
IPP_OP(add_16u, ippsAdd_16u, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP(add_32u, ippsAdd_32u, 32U, 32u, 32U, 32u, 32U, 32u)
IPP_OP(add_16s32f, ippsAdd_16s32f, 16S, 16s, 16S, 16s, 32F, 32f)

IPP_OP_SFS(add_8u_Sfs, ippsAdd_8u_Sfs, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP_SFS(add_16u_Sfs, ippsAdd_16u_Sfs, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP_SFS(add_16s_Sfs, ippsAdd_16s_Sfs, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP_SFS(add_32s_Sfs, ippsAdd_32s_Sfs, 32S, 32s, 32S, 32s, 32S, 32s)
IPP_OP_SFS(add_16sc_Sfs, ippsAdd_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, 16SC, 16sc)
IPP_OP_SFS(add_32sc_Sfs, ippsAdd_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, 32SC, 32sc)
IPP_OP_SFS(add_64s_Sfs, ippsAdd_64s_Sfs, 64S, 64s, 64S, 64s, 64S, 64s)

IPP_OP_I(add_16s_I, ippsAdd_16s_I, 16S, 16s, 16S, 16s)
IPP_OP_I(add_32f_I, ippsAdd_32f_I, 32F, 32f, 32F, 32f)
IPP_OP_I(add_64f_I, ippsAdd_64f_I, 64F, 64f, 64F, 64f)
IPP_OP_I(add_32fc_I, ippsAdd_32fc_I, 32FC, 32fc, 32FC, 32fc)
IPP_OP_I(add_64fc_I, ippsAdd_64fc_I, 64FC, 64fc, 64FC, 64fc)
IPP_OP_I(add_16s32s_I, ippsAdd_16s32s_I, 16S, 16s, 32S, 32s)
IPP_OP_I(add_32u_I, ippsAdd_32u_I, 32U, 32u, 32U, 32u)

IPP_OP_ISFS(add_8u_ISfs, ippsAdd_8u_ISfs, 8U, 8u, 8U, 8u)
IPP_OP_ISFS(add_16u_ISfs, ippsAdd_16u_ISfs, 16U, 16u, 16U, 16u)
IPP_OP_ISFS(add_16s_ISfs, ippsAdd_16s_ISfs, 16S, 16s, 16S, 16s)
IPP_OP_ISFS(add_32s_ISfs, ippsAdd_32s_ISfs, 32S, 32s, 32S, 32s)
IPP_OP_ISFS(add_16sc_ISfs, ippsAdd_16sc_ISfs, 16SC, 16sc, 16SC, 16sc)
IPP_OP_ISFS(add_32sc_ISfs, ippsAdd_32sc_ISfs, 32SC, 32sc, 32SC, 32sc)

