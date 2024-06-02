#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP_C(addProductC_32f, ippsAddProductC_32f, 32F, 32f, 32F, 32f, float)
IPP_OP_C(addProductC_64f, ippsAddProductC_64f, 64F, 64f, 64F, 64f, double)

IPP_OP(addProduct_32f, ippsAddProduct_32f, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(addProduct_64f, ippsAddProduct_64f, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(addProduct_32fc, ippsAddProduct_32fc, 32FC, 32fc, 32FC, 32fc, 32FC, 32fc)
IPP_OP(addProduct_64fc, ippsAddProduct_64fc, 64FC, 64fc, 64FC, 64fc, 64FC, 64fc)

IPP_OP_SFS(addProduct_16s_Sfs, ippsAddProduct_16s_Sfs, 16S, 16s, 16S, 16s, 16S, 16s)
IPP_OP_SFS(addProduct_32s_Sfs, ippsAddProduct_32s_Sfs, 32S, 32s, 32S, 32s, 32S, 32s)
IPP_OP_SFS(addProduct_16s32s_Sfs, ippsAddProduct_16s32s_Sfs, 16S, 16s, 16S, 16s, 32S, 32s)

