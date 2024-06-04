#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_UOP(real_16sc, ippsReal_16sc, 16SC, 16sc, 16S, 16s)
IPP_UOP(real_32sc, ippsReal_32fc, 32SC, 32fc, 32S, 32f)
IPP_UOP(real_32fc, ippsReal_32fc, 32FC, 32fc, 32F, 32f)
IPP_UOP(real_64sc, ippsReal_64fc, 64SC, 64fc, 64S, 64f)
IPP_UOP(real_64fc, ippsReal_64fc, 64FC, 64fc, 64F, 64f)

IPP_UOP(imag_16sc, ippsImag_16sc, 16SC, 16sc, 16S, 16s)
IPP_UOP(imag_32sc, ippsImag_32fc, 32SC, 32fc, 32S, 32f)
IPP_UOP(imag_32fc, ippsImag_32fc, 32FC, 32fc, 32F, 32f)
IPP_UOP(imag_64sc, ippsImag_64fc, 64SC, 64fc, 64S, 64f)
IPP_UOP(imag_64fc, ippsImag_64fc, 64FC, 64fc, 64F, 64f)

IPP_OP(realToCplx_16s, ippsRealToCplx_16s, 16S, 16s, 16S, 16s, 16SC, 16sc)
IPP_OP(realToCplx_32s, ippsRealToCplx_32f, 32S, 32f, 32S, 32f, 32SC, 32fc)
IPP_OP(realToCplx_32f, ippsRealToCplx_32f, 32F, 32f, 32F, 32f, 32FC, 32fc)
IPP_OP(realToCplx_64s, ippsRealToCplx_64f, 64S, 64f, 64S, 64f, 64SC, 64fc)
IPP_OP(realToCplx_64f, ippsRealToCplx_64f, 64F, 64f, 64F, 64f, 64FC, 64fc)

IPP_OP(cplxToReal_16sc, ippsCplxToReal_16sc, 16SC, 16sc, 16S, 16s, 16S, 16s)
IPP_OP(cplxToReal_32sc, ippsCplxToReal_32fc, 32SC, 32fc, 32S, 32f, 32S, 32f)
IPP_OP(cplxToReal_32fc, ippsCplxToReal_32fc, 32FC, 32fc, 32F, 32f, 32F, 32f)
IPP_OP(cplxToReal_64sc, ippsCplxToReal_64fc, 64SC, 64fc, 64S, 64f, 64S, 64f)
IPP_OP(cplxToReal_64fc, ippsCplxToReal_64fc, 64FC, 64fc, 64F, 64f, 64F, 64f)

