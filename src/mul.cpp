#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(mulC_32f, ippsMulC_32f, 32F, 32f, 32F, 32f, float)
IPP_OP_C(mulC_64f, ippsMulC_64f, 64F, 64f, 64F, 64f, double)

IPP_OP_CV(mulC_32fc, ippsMulC_32fc, 32FC, 32fc, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV(mulC_64fc, ippsMulC_64fc, 64FC, 64fc, 64FC, 64fc, Vector2, 64f)

IPP_OP_C(mulC_low_32f16s, ippsMulC_Low_32f16s, 32F, 32f, 16S, 16s, float)

IPP_OP_C_SFS(mulC_8u_Sfs, ippsMulC_8u_Sfs, 8U, 8u, 8U, 8u, int)
IPP_OP_C_SFS(mulC_16u_Sfs, ippsMulC_16u_Sfs, 16U, 16u, 16U, 16u, int)
IPP_OP_C_SFS(mulC_16s_Sfs, ippsMulC_16s_Sfs, 16S, 16s, 16S, 16s, int)
IPP_OP_C_SFS(mulC_32s_Sfs, ippsMulC_32s_Sfs, 32S, 32s, 32S, 32s, int)
IPP_OP_C_SFS(mulC_32f16s_Sfs, ippsMulC_32f16s_Sfs, 32F, 32f, 16S, 16s, float)

IPP_OP_CV_SFS(mulC_16sc_Sfs, ippsMulC_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_SFS(mulC_32sc_Sfs, ippsMulC_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, Vector2i, 32s)

IPP_OP_C_I(mulC_16s_I, ippsMulC_16s_I, 16S, 16s, int)
IPP_OP_C_I(mulC_32f_I, ippsMulC_32f_I, 32F, 32f, float)
IPP_OP_C_I(mulC_64f_I, ippsMulC_64f_I, 64F, 64f, double)

IPP_OP_CV_I(mulC_32fc_I, ippsMulC_32fc_I, 32FC, 32fc, Vector2, 32f)
IPP_OP_CV_I(mulC_64fc_I, ippsMulC_64fc_I, 64FC, 64fc, Vector2, 64f)

IPP_OP_C_ISFS(mulC_8u_ISfs, ippsMulC_8u_ISfs, 8U, 8u, int)
IPP_OP_C_ISFS(mulC_16u_ISfs, ippsMulC_16u_ISfs, 16U, 16u, int)
IPP_OP_C_ISFS(mulC_16s_ISfs, ippsMulC_16s_ISfs, 16S, 16s, int)
IPP_OP_C_ISFS(mulC_32s_ISfs, ippsMulC_32s_ISfs, 32S, 32s, int)
IPP_OP_C_ISFS(mulC_64f64s_ISfs, ippsMulC_64f64s_ISfs, 64S, 64s, double)
IPP_OP_C_ISFS(mulC_64s_ISfs, ippsMulC_64s_ISfs, 64S, 64s, int64_t)

IPP_OP_CV_ISFS(mulC_16sc_ISfs, ippsMulC_16sc_ISfs, 16SC, 16sc, Vector2i, 16s)
IPP_OP_CV_ISFS(mulC_32sc_ISfs, ippsMulC_32sc_ISfs, 32SC, 32sc, Vector2i, 32s)

IPP_OP(mul_16s, ippsMul_16s, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP(mul_32f, ippsMul_32f, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(mul_64f, ippsMul_64f, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(mul_32fc, ippsMul_32fc, 32FC, 32fc, 32FC, 32fc, 32FC, 32fc)
IPP_OP(mul_64fc, ippsMul_64fc, 64FC, 64fc, 64FC, 64fc, 64FC, 64fc)
IPP_OP(mul_8u16u, ippsMul_8u16u, 8U, 8u, 8U, 8u, 16U, 16u)
IPP_OP(mul_32f32fc, ippsMul_32f32fc, 32F, 32f, 32FC, 32fc, 32FC, 32fc)
IPP_OP(mul_16s32f, ippsMul_16s32f, 16S, 16s, 16S, 16s, 32F, 32f)

IPP_OP_SFS(mul_8u_Sfs, ippsMul_8u_Sfs, 8U, 8u, 8U, 8u, 8U, 8u)
IPP_OP_SFS(mul_16u_Sfs, ippsMul_16u_Sfs, 16U, 16u, 16U, 16u, 16U, 16u)
IPP_OP_SFS(mul_16s_Sfs, ippsMul_16s_Sfs, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP_SFS(mul_32s_Sfs, ippsMul_32s_Sfs, 32S, 32s, 32S, 32s, 32S, 32s)
IPP_OP_SFS(mul_16sc_Sfs, ippsMul_16sc_Sfs, 16SC, 16sc, 16SC, 16sc, 16SC, 16sc)
IPP_OP_SFS(mul_32sc_Sfs, ippsMul_32sc_Sfs, 32SC, 32sc, 32SC, 32sc, 32SC, 32sc)
IPP_OP_SFS(mul_16s32s_Sfs, ippsMul_16s32s_Sfs, 16S, 16s, 16S, 16s, 32S, 32s)
IPP_OP_SFS(mul_16u16s_Sfs, ippsMul_16u16s_Sfs, 16U, 16u, 16S, 16s, 16S, 16s)

IPP_OP_I(mul_16s_I, ippsMul_16s_I, 16S, 16s, 16S, 16s)
IPP_OP_I(mul_32f_I, ippsMul_32f_I, 32F, 32f, 32F, 32f)
IPP_OP_I(mul_64f_I, ippsMul_64f_I, 64F, 64f, 64F, 64f)
IPP_OP_I(mul_32fc_I, ippsMul_32fc_I, 32FC, 32fc, 32FC, 32fc)
IPP_OP_I(mul_64fc_I, ippsMul_64fc_I, 64FC, 64fc, 64FC, 64fc)
IPP_OP_I(mul_32f32fc_I, ippsMul_32f32fc_I, 32F, 32f, 32FC, 32fc)

IPP_OP_ISFS(mul_8u_ISfs, ippsMul_8u_ISfs, 8U, 8u, 8U, 8u)
IPP_OP_ISFS(mul_16u_ISfs, ippsMul_16u_ISfs, 16U, 16u, 16U, 16u)
IPP_OP_ISFS(mul_16s_ISfs, ippsMul_16s_ISfs, 16S, 16s, 16S, 16s)
IPP_OP_ISFS(mul_32s_ISfs, ippsMul_32s_ISfs, 32S, 32s, 32S, 32s)
IPP_OP_ISFS(mul_16sc_ISfs, ippsMul_16sc_ISfs, 16SC, 16sc, 16SC, 16sc)
IPP_OP_ISFS(mul_32sc_ISfs, ippsMul_32sc_ISfs, 32SC, 32sc, 32SC, 32sc)

