#ifndef IPP_GDEXT_H
#  define IPP_GDEXT_H


#include "ipp/ipp.h"
#include "ipp/ipps.h"


#ifdef GDEXTENSION
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/core/binder_common.hpp>
#else
#include "core/templates/vector.h"
#include "core/variant/array.h"
#endif


namespace ipp {


class IppBuffer;
class IppRandom;
class IppFft;


class IPP: public godot::Object {
  GDCLASS(IPP, godot::Object);

  public:
    enum Type {
      TYPE_NONE,
      // simple integers
      TYPE_8U, TYPE_8S, TYPE_16U, TYPE_16S, TYPE_32U, TYPE_32S, TYPE_64U, TYPE_64S,
      // simple reals
      TYPE_32F, TYPE_64F,
      // complex integers
      TYPE_8SC, TYPE_16SC, TYPE_32SC, TYPE_64SC,
      // complex reals
      TYPE_32FC, TYPE_64FC,
    };


    static const char *typeString(Type);


    enum Hint {
      HINT_NONE = ippAlgHintNone,
      HINT_FAST = ippAlgHintFast,
      HINT_ACC  = ippAlgHintAccurate,
    };


    static const char *hintString(Hint);


    enum Status {
      STAT_CPU_NOT_SUPPORTED = ippStsCpuNotSupportedErr,
//      STAT_POINT_AT_INIFINTY = ippStsPointAtInfinity,
//      STAT_I18N_UNSOPPORTED = ippStsI18nUnsupportedErr,
//      STAT_I18N_MSG_CATALOG_OPEN_ERR = ippStsI18nMsgCatalogOpenErr,
//      STAT_I18N_MSG_CATALOG_CLOSE_ERR = ippStsI18nMsgCatalogCloseErr,
      STAT_UNKNOWN_STATUS_CODE_ERR = ippStsUnknownStatusCodeErr,
//      STAT_OFB_SIZE_ERR = ippStsOFBSizeErr,
      STAT_LZO_BROKEN_STREAM_ERR = ippStsLzoBrokenStreamErr,
      STAT_ROUND_MODE_NOT_SUPPORTED_ERR = ippStsRoundModeNotSupportedErr,
//      STAT_MAX_LEN_HUFF_CODE_ERR = ippStsMaxLenHuffCodeErr,
//      STAT_CODE_LEN_TABLE_ERR = ippStsCodeLenTableErr,
//      STAT_FREQ_TABLE_ERR = ippStsFreqTableErr,
      STAT_REG_EXP_OPTIONS_ERR = ippStsRegExpOptionsErr,
      STAT_REG_EXP_ERR = ippStsRegExpErr,
      STAT_REG_EXP_MATCH_LIMIT_ERR = ippStsRegExpMatchLimitErr,
      STAT_REG_EXP_QUANTIFIER_ERR = ippStsRegExpQuantifierErr,
      STAT_REG_EXP_GROUPING_ERR = ippStsRegExpGroupingErr,
      STAT_REG_EXP_BACK_REF_ERR = ippStsRegExpBackRefErr,
      STAT_REG_EXP_CHAR_CLASS_ERR = ippStsRegExpChClassErr,
      STAT_REG_EXP_META_CHAR_ERR = ippStsRegExpMetaChErr,
//      STAT_MP3_FRAME_HEADER_ERR = ippStsMP3FrameHeaderErr,
//      STAT_MP3_SIDE_INFO_ERR = ippStsMP3SideInfoErr,
//      STAT_AAC_PRG_NUM_ERR = ippStsAacPrgNumErr,
//      STAT_AAC_SECT_CB_ERR = ippStsAacSectCbErr,
//      STAT_AAC_SF_VAL_ERR = ippStsAacSfValErr,
//      STAT_AAC_COEFF_VAL_ERR = ippStsAacCoefValErr,
//      STAT_AAC_MAX_SF_ERR = ippStsAacMaxSfbErr,
//      STAT_AAC_PRED_SF_ERR = ippStsAacPredSfbErr,
//      STAT_AAC_PLS_DATA_ERR = ippStsAacPlsDataErr,
//      STAT_AAC_GAIN_CTR_ERR = ippStsAacGainCtrErr,
//      STAT_AAC_SECT_ERR = ippStsAacSectErr,
//      STAT_AAC_TNS_NUM_FILT_ERR = ippStsAacTnsNumFiltErr,
//      STAT_AAC_TNS_LEN_ERR = ippStsAacTnsLenErr,
//      STAT_AAC_TNS_ORDER_ERR = ippStsAacTnsOrderErr,
//      STAT_AAC_TNS_COEFF_RES_ERR = ippStsAacTnsCoefResErr,
//      STAT_AAC_TNS_COEFF_ERR = ippStsAacTnsCoefErr,
//      STAT_AAC_TNS_DIRECT_ERR = ippStsAacTnsDirectErr,
//      STAT_AAC_TNS_PROFILE_ERR = ippStsAacTnsProfileErr,
//      STAT_AAC_ERR = ippStsAacErr,
//      STAT_AAC_BIT_OFFSET_ERR = ippStsAacBitOffsetErr,
//      STAT_AAC_ADTS_SYNC_WORD_ERR = ippStsAacAdtsSyncWordErr,
//      STAT_AAC_SAMPLE_RATE_INDEX_ERR = ippStsAacSmplRateIdxErr,
//      STAT_AAC_WIN_LEN_ERR = ippStsAacWinLenErr,
//      STAT_AAC_WIN_GRP_ERR = ippStsAacWinGrpErr,
//      STAT_AAC_WIN_SEQ_ERR = ippStsAacWinSeqErr,
//      STAT_AAC_COM_WIN_ERR = ippStsAacComWinErr,
//      STAT_AAC_STEREO_MASK_ERR = ippStsAacStereoMaskErr,
//      STAT_AAC_CHAN_ERR = ippStsAacChanErr,
//      STAT_AAC_MONO_STEREO_ERR = ippStsAacMonoStereoErr,
//      STAT_AAC_STEREO_LAYER_ERR = ippStsAacStereoLayerErr,
//      STAT_AAC_MONO_LAYER_ERR = ippStsAacMonoLayerErr,
//      STAT_AAC_SCALABLE_ERR = ippStsAacScalableErr,
//      STAT_AAC_OBJ_TYPE_ERR = ippStsAacObjTypeErr,
//      STAT_AAC_WIN_SHAPE_ERR = ippStsAacWinShapeErr,
//      STAT_AAC_PCM_MODE_ERR = ippStsAacPcmModeErr,
//      STAT_VLC_USR_TBL_HEADER_ERR = ippStsVLCUsrTblHeaderErr,
//      STAT_VLC_USR_TBL_UNSUPPORTED_FORMAT_ERR = ippStsVLCUsrTblUnsupportedFmtErr,
//      STAT_VLC_USR_TBL_ESC_ALG_TYPE_ERR = ippStsVLCUsrTblEscAlgTypeErr,
//      STAT_VLC_USR_TBL_ESC_CODE_LENGTH_ERR = ippStsVLCUsrTblEscCodeLengthErr,
//      STAT_VLC_USR_TBL_CODE_LENGTH_ERR = ippStsVLCUsrTblCodeLengthErr,
//      STAT_VLC_INTERNAL_TABLE_ERR = ippStsVLCInternalTblErr,
//      STAT_VLC_INPUT_DATA_ERR = ippStsVLCInputDataErr,
//      STAT_VLC_AAC_ESC_CODE_LENGTH_ERR = ippStsVLCAACEscCodeLengthErr,
//      STAT_INCORRECT_SP_ERR = ippStsIncorrectLSPErr,
//      STAT_NO_ROOT_FOUND_ERR = ippStsNoRootFoundErr,
      STAT_LENGTH_ERR = ippStsLengthErr,
//      STAT_FBANK_FREQ_ERR = ippStsFBankFreqErr,
//      STAT_FBANK_FLAG_ERR = ippStsFBankFlagErr,
//      STAT_FBANK_ERR = ippStsFBankErr,
//      STAT_NEG_OCC_ERR = ippStsNegOccErr,
//      STAT_CDBK_FLAG_ERR = ippStsCdbkFlagErr,
//      STAT_SVD_CNVG_ERR = ippStsSVDCnvgErr,
      STAT_TONE_MAGN_ERR = ippStsToneMagnErr,
      STAT_TONE_FREQ_ERR = ippStsToneFreqErr,
      STAT_TONE_PHASE_ERR = ippStsTonePhaseErr,
      STAT_TRNGL_MAGN_ERR = ippStsTrnglMagnErr,
      STAT_TRNGL_FREQ_ERR = ippStsTrnglFreqErr,
      STAT_TRNGL_PHASE_ERR = ippStsTrnglPhaseErr,
      STAT_TRNGL_ASYM_ERR = ippStsTrnglAsymErr,
      STAT_HUGE_WIN_ERR = ippStsHugeWinErr,
      STAT_JAEHNE_ERR = ippStsJaehneErr,
      STAT_STEP_ERR = ippStsStepErr,
//      STAT_DLY_LINE_INDEX_ERR = ippStsDlyLineIndexErr,
      STAT_STRIDE_ERR = ippStsStrideErr,
      STAT_EPS_VAL_ERR = ippStsEpsValErr,
      STAT_SCALE_RANGE_ERR = ippStsScaleRangeErr,
      STAT_THESHOLD_ERR = ippStsThresholdErr,
      STAT_WT_OFFSET_ERR = ippStsWtOffsetErr,
      STAT_ANCHOR_ERR = ippStsAnchorErr,
      STAT_MASK_SIZE_ERR = ippStsMaskSizeErr,
      STAT_SHIFT_ERR = ippStsShiftErr,
      STAT_SAMPLE_FACTOR_ERR = ippStsSampleFactorErr,
      STAT_SAMPLE_PHASE_ERR = ippStsSamplePhaseErr,
      STAT_FIR_MR_FACTOR_ERR = ippStsFIRMRFactorErr,
      STAT_FIR_MR_PHASE_ERR = ippStsFIRMRPhaseErr,
      STAT_REL_FREQ_ERR = ippStsRelFreqErr,
      STAT_FIR_LEN_ERR = ippStsFIRLenErr,
      STAT_IIR_ORDER_ERR = ippStsIIROrderErr,
      STAT_RESIZE_FACTOR_ERR = ippStsResizeFactorErr,
      STAT_DIV_BY_ZERO_ERR = ippStsDivByZeroErr,
      STAT_INTERPOLATION_ERR = ippStsInterpolationErr,
      STAT_MIRROR_FLIP_ERR = ippStsMirrorFlipErr,
      STAT_MOMENT_00_ZERO_ERR = ippStsMoment00ZeroErr,
      STAT_THRESH_NEG_LEVEL_ERR = ippStsThreshNegLevelErr,
      STAT_CONTEXT_MATCH_ERR = ippStsContextMatchErr,
      STAT_FFT_FLAG_ERR = ippStsFftFlagErr,
      STAT_FFT_ORDER_ERR = ippStsFftOrderErr,
      STAT_MEM_ALLOC_ERR = ippStsMemAllocErr,
      STAT_NULL_PTR_ERR = ippStsNullPtrErr,
      STAT_SIZE_ERR = ippStsSizeErr,
      STAT_BAD_ARG_ERR = ippStsBadArgErr,
      STAT_ERR = ippStsErr,
      STAT_NO_ERR = ippStsNoErr,
      STAT_NO_OPERATION = ippStsNoOperation,
//      STAT_MISALIGNED_BUF = ippStsMisalignedBuf,
      STAT_SQRT_NEG_ARG = ippStsSqrtNegArg,
//      STAT_INV_BY_ZERO = ippStsInvByZero,
      STAT_EVEN_MEDIAN_MASK = ippStsEvenMedianMaskSize,
      STAT_DIV_BY_ZERO = ippStsDivByZero,
      STAT_LN_ZERO_ARG = ippStsLnZeroArg,
      STAT_LN_NEG_ARG = ippStsLnNegArg,
      STAT_NAN_ARG = ippStsNanArg,
//      STAT_RES_FLOOR = ippStsResFloor,
      STAT_OVERFLOW = ippStsOverflow,
//      STAT_ZERO_OCC = ippStsZeroOcc,
      STAT_UNDERFLOW = ippStsUnderflow,
      STAT_SINGULARITY = ippStsSingularity,
      STAT_DOMAIN = ippStsDomain,
//      STAT_NOT_INTEL_CPU = ippStsNotIntelCpu,
      STAT_CPU_MISMATCH = ippStsCpuMismatch,
//      STAT_NOT_IPP_FUNCTION_FOUND = ippStsNotIppFunctionFound,
//      STAT_DLL_NOT_FOUND_BEST_USED = ippStsDllNotFoundBestUsed,
//      STAT_NO_OPERTION_IN_DLL = ippStsNoOperationInDll,
      STAT_OVERMUCH_STRINGS = ippStsOvermuchStrings,
      STAT_OVERLONG_STRING = ippStsOverlongString,
      STAT_SRC_SIZE_LESS_EXPECTED = ippStsSrcSizeLessExpected,
      STAT_DST_SIZE_LESS_EXPECTED = ippStsDstSizeLessExpected,
      STAT_NOT_SUPPORTED_CPU = ippStsNotSupportedCpu,
//      STAT_UNKNOWN_CACHE_SIZE = ippStsUnkhownCacheSize,
      STAT_ALG_TYPE_ERR = ippStsAlgTypeErr
    };

    static IppBuffer *malloc_8u(int);
    static IppBuffer *malloc_16u(int);
    static IppBuffer *malloc_32u(int);
    static IppBuffer *malloc_8s(int);
    static IppBuffer *malloc_16s(int);
    static IppBuffer *malloc_32s(int);
    static IppBuffer *malloc_64s(int);
    static IppBuffer *malloc_32f(int);
    static IppBuffer *malloc_64f(int);
    static IppBuffer *malloc_8sc(int);
    static IppBuffer *malloc_16sc(int);
    static IppBuffer *malloc_32sc(int);
    static IppBuffer *malloc_64sc(int);
    static IppBuffer *malloc_32fc(int);
    static IppBuffer *malloc_64fc(int);

    static Status copy_8u(const IppBuffer *, IppBuffer *, int);
    static Status copy_16s(const IppBuffer *, IppBuffer *, int);
    static Status copy_32s(const IppBuffer *, IppBuffer *, int);
    static Status copy_64s(const IppBuffer *, IppBuffer *, int);
    static Status copy_32f(const IppBuffer *, IppBuffer *, int);
    static Status copy_64f(const IppBuffer *, IppBuffer *, int);
    static Status copy_16sc(const IppBuffer *, IppBuffer *, int);
    static Status copy_32sc(const IppBuffer *, IppBuffer *, int);
    static Status copy_64sc(const IppBuffer *, IppBuffer *, int);
    static Status copy_32fc(const IppBuffer *, IppBuffer *, int);
    static Status copy_64fc(const IppBuffer *, IppBuffer *, int);

    static Status move_8u(const IppBuffer *, IppBuffer *, int);
    static Status move_16s(const IppBuffer *, IppBuffer *, int);
    static Status move_32s(const IppBuffer *, IppBuffer *, int);
    static Status move_64s(const IppBuffer *, IppBuffer *, int);
    static Status move_32f(const IppBuffer *, IppBuffer *, int);
    static Status move_64f(const IppBuffer *, IppBuffer *, int);
    static Status move_16sc(const IppBuffer *, IppBuffer *, int);
    static Status move_32sc(const IppBuffer *, IppBuffer *, int);
    static Status move_64sc(const IppBuffer *, IppBuffer *, int);
    static Status move_32fc(const IppBuffer *, IppBuffer *, int);
    static Status move_64fc(const IppBuffer *, IppBuffer *, int);

    static Status set_8u(godot::Variant, IppBuffer *, int);
    static Status set_16s(godot::Variant, IppBuffer *, int);
    static Status set_32s(godot::Variant, IppBuffer *, int);
    static Status set_64s(godot::Variant, IppBuffer *, int);
    static Status set_32f(godot::Variant, IppBuffer *, int);
    static Status set_64f(godot::Variant, IppBuffer *, int);
    static Status set_16sc(godot::Variant, IppBuffer *, int);
    static Status set_32sc(godot::Variant, IppBuffer *, int);
    static Status set_64sc(godot::Variant, IppBuffer *, int);
    static Status set_32fc(godot::Variant, IppBuffer *, int);
    static Status set_64fc(godot::Variant, IppBuffer *, int);

    static Status zero_8u(IppBuffer *, int);
    static Status zero_16s(IppBuffer *, int);
    static Status zero_32s(IppBuffer *, int);
    static Status zero_64s(IppBuffer *, int);
    static Status zero_32f(IppBuffer *, int);
    static Status zero_64f(IppBuffer *, int);
    static Status zero_16sc(IppBuffer *, int);
    static Status zero_32sc(IppBuffer *, int);
    static Status zero_64sc(IppBuffer *, int);
    static Status zero_32fc(IppBuffer *, int);
    static Status zero_64fc(IppBuffer *, int);

    static Status tone_16s(IppBuffer *, int, int, float, godot::Variant, Hint);
    static Status tone_32f(IppBuffer *, int, float, float, godot::Variant, Hint);
    static Status tone_64f(IppBuffer *, int, double, double, godot::Variant, Hint);
    static Status tone_16sc(IppBuffer *, int, int, float, godot::Variant, Hint);
    static Status tone_32fc(IppBuffer *, int, float, float, godot::Variant, Hint);
    static Status tone_64fc(IppBuffer *, int, double, double, godot::Variant, Hint);

    static Status triangle_16s(IppBuffer *, int, int, float, float, godot::Variant);
    static Status triangle_32f(IppBuffer *, int, float, float, float, godot::Variant);
    static Status triangle_64f(IppBuffer *, int, double, double, double, godot::Variant);
    static Status triangle_16sc(IppBuffer *, int, int, float, float, godot::Variant);
    static Status triangle_32fc(IppBuffer *, int, float, float, float, godot::Variant);
    static Status triangle_64fc(IppBuffer *, int, double, double, double, godot::Variant);

    static Status cos_32f_A11(const IppBuffer *, IppBuffer *, int);
    static Status cos_32f_A21(const IppBuffer *, IppBuffer *, int);
    static Status cos_32f_A24(const IppBuffer *, IppBuffer *, int);
    static Status cos_64f_A26(const IppBuffer *, IppBuffer *, int);
    static Status cos_64f_A50(const IppBuffer *, IppBuffer *, int);
    static Status cos_64f_A53(const IppBuffer *, IppBuffer *, int);
    static Status cos_32fc_A11(const IppBuffer *, IppBuffer *, int);
    static Status cos_32fc_A21(const IppBuffer *, IppBuffer *, int);
    static Status cos_32fc_A24(const IppBuffer *, IppBuffer *, int);
    static Status cos_64fc_A26(const IppBuffer *, IppBuffer *, int);
    static Status cos_64fc_A50(const IppBuffer *, IppBuffer *, int);
    static Status cos_64fc_A53(const IppBuffer *, IppBuffer *, int);

    static Status sin_32f_A11(const IppBuffer *, IppBuffer *, int);
    static Status sin_32f_A21(const IppBuffer *, IppBuffer *, int);
    static Status sin_32f_A24(const IppBuffer *, IppBuffer *, int);
    static Status sin_64f_A26(const IppBuffer *, IppBuffer *, int);
    static Status sin_64f_A50(const IppBuffer *, IppBuffer *, int);
    static Status sin_64f_A53(const IppBuffer *, IppBuffer *, int);
    static Status sin_32fc_A11(const IppBuffer *, IppBuffer *, int);
    static Status sin_32fc_A21(const IppBuffer *, IppBuffer *, int);
    static Status sin_32fc_A24(const IppBuffer *, IppBuffer *, int);
    static Status sin_64fc_A26(const IppBuffer *, IppBuffer *, int);
    static Status sin_64fc_A50(const IppBuffer *, IppBuffer *, int);
    static Status sin_64fc_A53(const IppBuffer *, IppBuffer *, int);

    static Status sin_cos_32f_A11(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_32f_A21(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_32f_A24(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_64f_A26(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_64f_A50(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_64f_A53(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_32fc_A11(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_32fc_A21(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_32fc_A24(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_64fc_A26(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_64fc_A50(const IppBuffer *, IppBuffer *, IppBuffer *, int);
    static Status sin_cos_64fc_A53(const IppBuffer *, IppBuffer *, IppBuffer *, int);

    static Status addC_32f(const IppBuffer *, float, IppBuffer *, int);
    static Status addC_64f(const IppBuffer *, double, IppBuffer *, int);
    static Status addC_32fc(const IppBuffer *, godot::Vector2, IppBuffer *, int);
    static Status addC_64fc(const IppBuffer *, godot::Vector2, IppBuffer *, int);

    static Status addC_8u_Sfs(const IppBuffer *, int, IppBuffer *, int, int);
    static Status addC_16u_Sfs(const IppBuffer *, int, IppBuffer *, int, int);
    static Status addC_16s_Sfs(const IppBuffer *, int, IppBuffer *, int, int);
    static Status addC_32s_Sfs(const IppBuffer *, int, IppBuffer *, int, int);
    static Status addC_64s_Sfs(const IppBuffer *, int64_t, IppBuffer *, int, int);
    static Status addC_64u_Sfs(const IppBuffer *, uint64_t, IppBuffer *, int, int);
    static Status addC_16sc_Sfs(const IppBuffer *, godot::Vector2i, IppBuffer *, int, int);
    static Status addC_32sc_Sfs(const IppBuffer *, godot::Vector2i, IppBuffer *, int, int);

    static Status addC_32f_I(float, IppBuffer *, int);
    static Status addC_64f_I(double, IppBuffer *, int);
    static Status addC_32fc_I(godot::Vector2, IppBuffer *, int);
    static Status addC_64fc_I(godot::Vector2, IppBuffer *, int);

    static Status addC_8u_ISfs(int, IppBuffer *, int, int);
    static Status addC_16u_ISfs(int, IppBuffer *, int, int);
    static Status addC_16s_ISfs(int, IppBuffer *, int, int);
    static Status addC_32s_ISfs(int, IppBuffer *, int, int);
    static Status addC_16sc_ISfs(godot::Vector2i, IppBuffer *, int, int);
    static Status addC_32sc_ISfs(godot::Vector2i, IppBuffer *, int, int);

    static IppRandom *uniform_init_8u(int, int, int64_t);
    static IppRandom *uniform_init_16s(int, int, int64_t);
    static IppRandom *uniform_init_32f(float, float, int64_t);
    static IppRandom *uniform_init_32f(double, double, int64_t);

    static IppRandom *gauss_init_8u(int, int, int64_t);
    static IppRandom *gauss_init_16s(int, int, int64_t);
    static IppRandom *gauss_init_32f(float, float, int64_t);
    static IppRandom *gauss_init_32f(double, double, int64_t);

    static IppFft *fft_init_C_32f(int, int);
    static IppFft *fft_init_C_64f(int, int);
    static IppFft *fft_init_C_32fc(int, int);
    static IppFft *fft_init_C_64fc(int, int);

  protected:
    static void _bind_methods();

};


}

VARIANT_ENUM_CAST(ipp::IPP::Hint);
VARIANT_ENUM_CAST(ipp::IPP::Type);
VARIANT_ENUM_CAST(ipp::IPP::Status);



#endif /* IPP_GDEXT_H */

