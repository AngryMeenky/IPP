#define IPP_IMPL
#include "IPP.h"
#include "buffer.h"


using namespace ipp;
using namespace godot;


IPP_OP(sin_cos_32f_A11, ippsSinCos_32f_A11, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(sin_cos_32f_A21, ippsSinCos_32f_A21, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(sin_cos_32f_A24, ippsSinCos_32f_A24, 32F, 32f, 32F, 32f, 32F, 32f)
IPP_OP(sin_cos_64f_A26, ippsSinCos_64f_A26, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(sin_cos_64f_A50, ippsSinCos_64f_A50, 64F, 64f, 64F, 64f, 64F, 64f)
IPP_OP(sin_cos_64f_A53, ippsSinCos_64f_A53, 64F, 64f, 64F, 64f, 64F, 64f)

