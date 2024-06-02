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


    enum Round {
      RND_ZERO      = ippRndZero,
      RND_NEAR      = ippRndNear,
      RND_FINANCIAL = ippRndFinancial,
    };


    static const char *roundString(Round);


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


    static godot::String statusString(Status);


    static godot::Ref<IppBuffer> malloc_8u(int);
    static godot::Ref<IppBuffer> malloc_16u(int);
    static godot::Ref<IppBuffer> malloc_32u(int);
    static godot::Ref<IppBuffer> malloc_64u(int);
    static godot::Ref<IppBuffer> malloc_8s(int);
    static godot::Ref<IppBuffer> malloc_16s(int);
    static godot::Ref<IppBuffer> malloc_32s(int);
    static godot::Ref<IppBuffer> malloc_64s(int);
    static godot::Ref<IppBuffer> malloc_32f(int);
    static godot::Ref<IppBuffer> malloc_64f(int);
    static godot::Ref<IppBuffer> malloc_8sc(int);
    static godot::Ref<IppBuffer> malloc_16sc(int);
    static godot::Ref<IppBuffer> malloc_32sc(int);
    static godot::Ref<IppBuffer> malloc_64sc(int);
    static godot::Ref<IppBuffer> malloc_32fc(int);
    static godot::Ref<IppBuffer> malloc_64fc(int);

    static Status copy_8u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_16s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_32s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_64s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_16sc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_32sc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_64sc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status copy_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status move_8u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_16s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_32s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_64s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_16sc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_32sc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_64sc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status move_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status set_8u(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_16s(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_32s(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_64s(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_32f(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_64f(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_16sc(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_32sc(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_64sc(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_32fc(godot::Variant, const godot::Ref<IppBuffer> &, int);
    static Status set_64fc(godot::Variant, const godot::Ref<IppBuffer> &, int);

    static Status zero_8u(const godot::Ref<IppBuffer> &, int);
    static Status zero_16s(const godot::Ref<IppBuffer> &, int);
    static Status zero_32s(const godot::Ref<IppBuffer> &, int);
    static Status zero_64s(const godot::Ref<IppBuffer> &, int);
    static Status zero_32f(const godot::Ref<IppBuffer> &, int);
    static Status zero_64f(const godot::Ref<IppBuffer> &, int);
    static Status zero_16sc(const godot::Ref<IppBuffer> &, int);
    static Status zero_32sc(const godot::Ref<IppBuffer> &, int);
    static Status zero_64sc(const godot::Ref<IppBuffer> &, int);
    static Status zero_32fc(const godot::Ref<IppBuffer> &, int);
    static Status zero_64fc(const godot::Ref<IppBuffer> &, int);

    static Status tone_16s(const godot::Ref<IppBuffer> &, int, int, float, godot::Variant, Hint);
    static Status tone_32f(const godot::Ref<IppBuffer> &, int, float, float, godot::Variant, Hint);
    static Status tone_64f(const godot::Ref<IppBuffer> &, int, double, double, godot::Variant, Hint);
    static Status tone_16sc(const godot::Ref<IppBuffer> &, int, int, float, godot::Variant, Hint);
    static Status tone_32fc(const godot::Ref<IppBuffer> &, int, float, float, godot::Variant, Hint);
    static Status tone_64fc(const godot::Ref<IppBuffer> &, int, double, double, godot::Variant, Hint);

    static Status triangle_16s(const godot::Ref<IppBuffer> &, int, int, float, float, godot::Variant);
    static Status triangle_32f(const godot::Ref<IppBuffer> &, int, float, float, float, godot::Variant);
    static Status triangle_64f(const godot::Ref<IppBuffer> &, int, double, double, double, godot::Variant);
    static Status triangle_16sc(const godot::Ref<IppBuffer> &, int, int, float, float, godot::Variant);
    static Status triangle_32fc(const godot::Ref<IppBuffer> &, int, float, float, float, godot::Variant);
    static Status triangle_64fc(const godot::Ref<IppBuffer> &, int, double, double, double, godot::Variant);

    static godot::Ref<IppRandom> uniform_init_8u(int, int, int64_t);
    static godot::Ref<IppRandom> uniform_init_16s(int, int, int64_t);
    static godot::Ref<IppRandom> uniform_init_32f(float, float, int64_t);
    static godot::Ref<IppRandom> uniform_init_64f(double, double, int64_t);

    static godot::Ref<IppRandom> gauss_init_8u(int, int, int64_t);
    static godot::Ref<IppRandom> gauss_init_16s(int, int, int64_t);
    static godot::Ref<IppRandom> gauss_init_32f(float, float, int64_t);
    static godot::Ref<IppRandom> gauss_init_64f(double, double, int64_t);

    static Status andC_8u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status andC_16u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status andC_32u(const godot::Ref<IppBuffer> &, uint32_t, const godot::Ref<IppBuffer> &, int);
    static Status andC_8u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status andC_16u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status andC_32u_I(uint32_t, const godot::Ref<IppBuffer> &, int);

    static Status and_8u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status and_16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status and_32u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status and_8u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status and_16u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status and_32u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status orC_8u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status orC_16u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status orC_32u(const godot::Ref<IppBuffer> &, uint32_t, const godot::Ref<IppBuffer> &, int);
    static Status orC_8u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status orC_16u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status orC_32u_I(uint32_t, const godot::Ref<IppBuffer> &, int);

    static Status or_8u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status or_16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status or_32u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status or_8u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status or_16u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status or_32u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status xorC_8u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status xorC_16u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status xorC_32u(const godot::Ref<IppBuffer> &, uint32_t, const godot::Ref<IppBuffer> &, int);
    static Status xorC_8u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status xorC_16u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status xorC_32u_I(uint32_t, const godot::Ref<IppBuffer> &, int);

    static Status xor_8u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status xor_16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status xor_32u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status xor_8u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status xor_16u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status xor_32u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status not_8u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status not_16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status not_32u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status not_8u_I(const godot::Ref<IppBuffer> &, int);
    static Status not_16u_I(const godot::Ref<IppBuffer> &, int);
    static Status not_32u_I(const godot::Ref<IppBuffer> &, int);

    static Status l_shiftC_8u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_16s(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_16u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_32s(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_8u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_16u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_16s_I(int, const godot::Ref<IppBuffer> &, int);
    static Status l_shiftC_32s_I(int, const godot::Ref<IppBuffer> &, int);

    static Status r_shiftC_8u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_16s(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_16u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_32s(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_8u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_16u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_16s_I(int, const godot::Ref<IppBuffer> &, int);
    static Status r_shiftC_32s_I(int, const godot::Ref<IppBuffer> &, int);

    static Status addC_32f(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);
    static Status addC_64f(const godot::Ref<IppBuffer> &, double, const godot::Ref<IppBuffer> &, int);
    static Status addC_32fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status addC_64fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status addC_8u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_16u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_16s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_32s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_64s_Sfs(const godot::Ref<IppBuffer> &, int64_t, const godot::Ref<IppBuffer> &, int, int, Round round);
    static Status addC_64u_Sfs(const godot::Ref<IppBuffer> &, uint64_t, const godot::Ref<IppBuffer> &, int, int, Round round);
    static Status addC_16sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_32sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);

    static Status addC_32f_I(float, const godot::Ref<IppBuffer> &, int);
    static Status addC_64f_I(double, const godot::Ref<IppBuffer> &, int);
    static Status addC_32fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status addC_64fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status addC_8u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_16u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_16s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_32s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_16sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status addC_32sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);

    static Status add_16s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_8u16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_32u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_16s32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status add_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_32sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_64s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status add_16s_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_32f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_64f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_32fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_64fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_16s32s_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status add_32u_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status add_8u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_16u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_16s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_32s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_16sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status add_32sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status addProductC_32f(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);
    static Status addProductC_64f(const godot::Ref<IppBuffer> &, double, const godot::Ref<IppBuffer> &, int);

    static Status addProduct_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status addProduct_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status addProduct_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status addProduct_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status addProduct_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status addProduct_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status addProduct_16s32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status mulC_32f(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);
    static Status mulC_64f(const godot::Ref<IppBuffer> &, double, const godot::Ref<IppBuffer> &, int);
    static Status mulC_32fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status mulC_64fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status mulC_low_32f16s(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);

    static Status mulC_8u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_16s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_16u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_32s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_16sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_32sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_32f16s_Sfs(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int, int);

    static Status mulC_16s_I(int, const godot::Ref<IppBuffer> &, int);
    static Status mulC_32f_I(float, const godot::Ref<IppBuffer> &, int);
    static Status mulC_64f_I(double, const godot::Ref<IppBuffer> &, int);
    static Status mulC_32fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status mulC_64fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status mulC_8u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_16u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_16s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_32s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_64f64s_ISfs(double, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_16sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_32sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status mulC_64s_ISfs(int64_t, const godot::Ref<IppBuffer> &, int, int);

    static Status mul_16s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_8u16u(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_32f32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_16s32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status mul_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_32sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_16s32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status mul_16u16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status mul_16s_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_32f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_64f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_32fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_64fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status mul_32f32fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status mul_8u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int len, int scaleFactor);
    static Status mul_16u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int len, int scaleFactor);
    static Status mul_16s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int len, int scaleFactor);
    static Status mul_32s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int len, int scaleFactor);
    static Status mul_16sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int len, int scaleFactor);
    static Status mul_32sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int len, int scaleFactor);

    static Status subC_32f(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);
    static Status subC_64f(const godot::Ref<IppBuffer> &, double, const godot::Ref<IppBuffer> &, int);
    static Status subC_32fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status subC_64fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status subC_8u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_16u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_16s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_32s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_64s_Sfs(const godot::Ref<IppBuffer> &, int64_t, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_64u_Sfs(const godot::Ref<IppBuffer> &, uint64_t, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_16sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_32sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);

    static Status subC_32f_I(float, const godot::Ref<IppBuffer> &, int);
    static Status subC_64f_I(double, const godot::Ref<IppBuffer> &, int);
    static Status subC_32fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status subC_64fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status subC_8u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_16u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_16s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_32s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_16sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);
    static Status subC_32sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);

    static Status subCRev_32f(const godot::Ref<IppBuffer> &, float val, const godot::Ref<IppBuffer> &, int len);
    static Status subCRev_64f(const godot::Ref<IppBuffer> &, double val, const godot::Ref<IppBuffer> &, int len);
    static Status subCRev_32fc(const godot::Ref<IppBuffer> &, godot::Vector2 val, const godot::Ref<IppBuffer> &, int len);
    static Status subCRev_64fc(const godot::Ref<IppBuffer> &, godot::Vector2 val, const godot::Ref<IppBuffer> &, int len);

    static Status subCRev_8u_Sfs(const godot::Ref<IppBuffer> &, int val, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_16u_Sfs(const godot::Ref<IppBuffer> &, int val, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_16s_Sfs(const godot::Ref<IppBuffer> &, int val, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_32s_Sfs(const godot::Ref<IppBuffer> &, int val, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_16sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i val, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_32sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i val, const godot::Ref<IppBuffer> &, int, int);

    static Status subCRev_32f_I(float val, const godot::Ref<IppBuffer> &, int);
    static Status subCRev_64f_I(double val, const godot::Ref<IppBuffer> &, int);
    static Status subCRev_32fc_I(godot::Vector2 val, const godot::Ref<IppBuffer> &, int);
    static Status subCRev_64fc_I(godot::Vector2 val, const godot::Ref<IppBuffer> &, int);

    static Status subCRev_8u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_16u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_16s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_32s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_16sc_ISfs(godot::Vector2i val, const godot::Ref<IppBuffer> &, int, int);
    static Status subCRev_32sc_ISfs(godot::Vector2i val, const godot::Ref<IppBuffer> &, int, int);

    static Status sub_16s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_16s32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status sub_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_32sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status sub_16s_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_32f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_64f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_32fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sub_64fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status sub_8u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_16u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_16s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_32s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_16sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sub_32sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status divC_32f(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);
    static Status divC_64f(const godot::Ref<IppBuffer> &, double, const godot::Ref<IppBuffer> &, int);
    static Status divC_32fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status divC_64fc(const godot::Ref<IppBuffer> &, godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status divC_8u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_16u_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_16s_Sfs(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_16sc_Sfs(const godot::Ref<IppBuffer> &, godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);

    static Status divC_32f_I(float, const godot::Ref<IppBuffer> &, int);
    static Status divC_64f_I(double, const godot::Ref<IppBuffer> &, int);
    static Status divC_32fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);
    static Status divC_64fc_I(godot::Vector2, const godot::Ref<IppBuffer> &, int);

    static Status divC_8u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_16u_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_16s_ISfs(int, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_64s_ISfs(int64_t, const godot::Ref<IppBuffer> &, int, int);
    static Status divC_16sc_ISfs(godot::Vector2i, const godot::Ref<IppBuffer> &, int, int);

    static Status divCRev_16u(const godot::Ref<IppBuffer> &, int, const godot::Ref<IppBuffer> &, int);
    static Status divCRev_32f(const godot::Ref<IppBuffer> &, float, const godot::Ref<IppBuffer> &, int);
    static Status divCRev_16u_I(int, const godot::Ref<IppBuffer> &, int);
    static Status divCRev_32f_I(float, const godot::Ref<IppBuffer> &, int);

    static Status div_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_32s16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status div_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status div_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status div_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status div_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status div_8u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_16u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_16s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_16sc_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status div_32s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status div_32f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status div_64f_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status div_32fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status div_64fc_I(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status div_round_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, Round, int);
    static Status div_round_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, Round, int);
    static Status div_round_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, Round, int);

    static Status div_round_8u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, Round, int);
    static Status div_round_16u_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, Round, int);
    static Status div_round_16s_ISfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, Round, int);

    static Status abs_16s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status abs_32s(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status abs_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status abs_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status abs_16s_I(const godot::Ref<IppBuffer> &, int);
    static Status abs_32s_I(const godot::Ref<IppBuffer> &, int);
    static Status abs_32f_I(const godot::Ref<IppBuffer> &, int);
    static Status abs_64f_I(const godot::Ref<IppBuffer> &, int);

    static Status sqr_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqr_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqr_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqr_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqr_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_32f_I(const godot::Ref<IppBuffer> &, int);
    static Status sqr_64f_I(const godot::Ref<IppBuffer> &, int);
    static Status sqr_32fc_I(const godot::Ref<IppBuffer> &, int);
    static Status sqr_64fc_I(const godot::Ref<IppBuffer> &, int);
    static Status sqr_8u_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_16s_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_16u_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status sqr_16sc_ISfs(const godot::Ref<IppBuffer> &, int, int);

    static Status sqrt_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqrt_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqrt_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqrt_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sqrt_8u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_16u_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_32s16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status sqrt_32f_I(const godot::Ref<IppBuffer> &, int);
    static Status sqrt_64f_I(const godot::Ref<IppBuffer> &, int);
    static Status sqrt_32fc_I(const godot::Ref<IppBuffer> &, int);
    static Status sqrt_64fc_I(const godot::Ref<IppBuffer> &, int);
    static Status sqrt_8u_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_16s_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_16u_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status sqrt_16sc_ISfs(const godot::Ref<IppBuffer> &, int, int);

    static Status cubrt_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cubrt_32s16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);

    static Status exp_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status exp_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status exp_32f_I(const godot::Ref<IppBuffer> &, int len);
    static Status exp_64f_I(const godot::Ref<IppBuffer> &, int len);
    static Status exp_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status exp_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status exp_16s_ISfs(const godot::Ref<IppBuffer> &, int len, int);
    static Status exp_32s_ISfs(const godot::Ref<IppBuffer> &, int len, int);

    static Status ln_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status ln_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status ln_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status ln_32s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int);
    static Status ln_16s_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status ln_32s_ISfs(const godot::Ref<IppBuffer> &, int, int);
    static Status ln_32f_I(const godot::Ref<IppBuffer> &, int);
    static Status ln_64f_I(const godot::Ref<IppBuffer> &, int);

    static Status sumLn_32f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status sumLn_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status sumLn_32f64f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status sumLn_16s32f(const godot::Ref<IppBuffer> &, int, godot::Variant);

    static Status arctan_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status arctan_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status arctan_32f_I(const godot::Ref<IppBuffer> &, int);
    static Status arctan_64f_I(const godot::Ref<IppBuffer> &, int);

    static Status normalize_32f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, float, float);
    static Status normalize_64f(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, double, double);
    static Status normalize_32fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, godot::Vector2, float);
    static Status normalize_64fc(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, godot::Vector2, double);
    static Status normalize_16s_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, int, int, int);
    static Status normalize_16sc_Sfs(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int, godot::Vector2i, int, int);

    static Status normalize_32f_I(const godot::Ref<IppBuffer> &, int, float, float);
    static Status normalize_64f_I(const godot::Ref<IppBuffer> &, int, double, double);
    static Status normalize_32fc_I(const godot::Ref<IppBuffer> &, int, godot::Vector2, float);
    static Status normalize_64fc_I(const godot::Ref<IppBuffer> &, int, godot::Vector2, double);
    static Status normalize_16s_ISfs(const godot::Ref<IppBuffer> &, int, int, int, int);
    static Status normalize_16sc_ISfs(const godot::Ref<IppBuffer> &, int, godot::Vector2i, int, int);

    static Status sum_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, Hint);
    static Status sum_32fc(const godot::Ref<IppBuffer> &, int, godot::Variant, Hint);
    static Status sum_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status sum_64fc(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status sum_16s_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);
    static Status sum_32s_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);
    static Status sum_16s32s_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);
    static Status sum_16sc_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);
    static Status sum_16sc32sc_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);

    static Status max_16s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status max_32s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status max_32f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status max_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);

    static Status maxIndx_16s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status maxIndx_32s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status maxIndx_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status maxIndx_64f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);

    static Status maxAbs_16s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status maxAbs_32s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status maxAbs_32f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status maxAbs_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);

    static Status maxAbsIndx_16s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status maxAbsIndx_32s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status maxAbsIndx_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status maxAbsIndx_64f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);

    static Status min_16s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status min_32s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status min_32f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status min_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);

    static Status minIndx_16s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minIndx_32s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minIndx_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minIndx_64f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);

    static Status minAbs_16s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status minAbs_32s(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status minAbs_32f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status minAbs_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);

    static Status minAbsIndx_16s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minAbsIndx_32s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minAbsIndx_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minAbsIndx_64f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);

    static Status minMax_8u(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);
    static Status minMax_16u(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant);

    static Status minMaxIndx_8u(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);
    static Status minMaxIndx_16u(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);
    static Status minMaxIndx_16s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);
    static Status minMaxIndx_32u(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);
    static Status minMaxIndx_32s(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);
    static Status minMaxIndx_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);
    static Status minMaxIndx_64f(const godot::Ref<IppBuffer> &, int, godot::Variant, godot::Variant, godot::Variant, godot::Variant);

    static Status replaceNAN_32f_I(const godot::Ref<IppBuffer> &, int, float);
    static Status replaceNAN_64f_I(const godot::Ref<IppBuffer> &, int, double);

    static Status mean_32f(const godot::Ref<IppBuffer> &, int, godot::Variant, Hint);
    static Status mean_32fc(const godot::Ref<IppBuffer> &, int, godot::Variant, Hint);
    static Status mean_64f(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status mean_64fc(const godot::Ref<IppBuffer> &, int, godot::Variant);
    static Status mean_16s_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);
    static Status mean_32s_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);
    static Status mean_16sc_Sfs(const godot::Ref<IppBuffer> &, int, godot::Variant, int);

    static Status cos_32f_A11(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_32f_A21(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_32f_A24(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_64f_A26(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_64f_A50(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_64f_A53(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_32fc_A11(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_32fc_A21(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_32fc_A24(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_64fc_A26(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_64fc_A50(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status cos_64fc_A53(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status sin_32f_A11(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_32f_A21(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_32f_A24(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_64f_A26(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_64f_A50(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_64f_A53(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_32fc_A11(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_32fc_A21(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_32fc_A24(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_64fc_A26(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_64fc_A50(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_64fc_A53(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static Status sin_cos_32f_A11(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_cos_32f_A21(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_cos_32f_A24(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_cos_64f_A26(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_cos_64f_A50(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);
    static Status sin_cos_64f_A53(const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, const godot::Ref<IppBuffer> &, int);

    static godot::Ref<IppFft> fft_init_C_32f(int, int);
    static godot::Ref<IppFft> fft_init_C_64f(int, int);
    static godot::Ref<IppFft> fft_init_C_32fc(int, int);
    static godot::Ref<IppFft> fft_init_C_64fc(int, int);

  protected:
    static void _bind_methods();
};


}

VARIANT_ENUM_CAST(ipp::IPP::Hint);
VARIANT_ENUM_CAST(ipp::IPP::Type);
VARIANT_ENUM_CAST(ipp::IPP::Round);
VARIANT_ENUM_CAST(ipp::IPP::Status);


#ifdef IPP_IMPL

#  define IPP_OP_C(_NAME_, _IMPL_, _STYPE_, _SAS_, _DTYPE_, _DAS_, _CTYPE_) \
IPP::Status IPP::_NAME_(const godot::Ref<IppBuffer> &src, _CTYPE_ val, const godot::Ref<IppBuffer> &dst, int len) { \
  if(src.is_null() || src->getType() != TYPE_##_STYPE_ || src->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), val, dst->as##_DAS_(), len)); \
}


#  define IPP_OP_C_I(_NAME_, _IMPL_, _SDTYPE_, _SDAS_, _CTYPE_) \
IPP::Status IPP::_NAME_(_CTYPE_ val, const godot::Ref<IppBuffer> &srcDst, int len) { \
  if(srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(val, srcDst->as##_SDAS_(), len)); \
}


#  define IPP_OP_C_SFS(_NAME_, _IMPL_, _STYPE_, _SAS_, _DTYPE_, _DAS_, _CTYPE_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, _CTYPE_ val, const Ref<IppBuffer> &dst, int len, int scale) { \
  if(src.is_null() || src->getType() != TYPE_##_STYPE_ || src->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), val, dst->as##_DAS_(), len, scale)); \
}


#  define IPP_OP_C_ISFS(_NAME_, _IMPL_, _SDTYPE_, _SDAS_, _CTYPE_) \
IPP::Status IPP::_NAME_(_CTYPE_ val, const Ref<IppBuffer> &srcDst, int len, int scale) { \
  if(srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(val, srcDst->as##_SDAS_(), len, scale)); \
}


#  define IPP_OP_C_SFS_R(_NAME_, _IMPL_, _STYPE_, _SAS_, _DTYPE_, _DAS_, _CTYPE_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, _CTYPE_ val, const Ref<IppBuffer> &dst, int len, int scale, Round round) { \
  if(src.is_null() || src->getType() != TYPE_##_STYPE_ || src->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), val, dst->as##_DAS_(), len, scale, static_cast<IppRoundMode>(round))); \
}


#  define IPP_OP_CV(_NAME_, _IMPL_, _STYPE_, _SAS_, _DTYPE_, _DAS_, _VTYPE_, _VCAST_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, _VTYPE_ vec, const Ref<IppBuffer> &dst, int len) { \
  if(src.is_null() || src->getType() != TYPE_##_STYPE_ || src->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  Ipp##_VCAST_##c val{ static_cast<Ipp##_VCAST_>(vec.x), static_cast<Ipp##_VCAST_>(vec.y) }; \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), val, dst->as##_DAS_(), len)); \
}


#  define IPP_OP_CV_I(_NAME_, _IMPL_, _SDTYPE_, _SDAS_, _VTYPE_, _VCAST_) \
IPP::Status IPP::_NAME_(_VTYPE_ vec, const Ref<IppBuffer> &srcDst, int len) { \
  if(srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  Ipp##_VCAST_##c val{ static_cast<Ipp##_VCAST_>(vec.x), static_cast<Ipp##_VCAST_>(vec.y) }; \
  return static_cast<Status>(_IMPL_(val, srcDst->as##_SDAS_(), len)); \
}


#  define IPP_OP_CV_SFS(_NAME_, _IMPL_, _STYPE_, _SAS_, _DTYPE_, _DAS_, _VTYPE_, _VCAST_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, _VTYPE_ vec, const Ref<IppBuffer> &dst, int len, int scale) { \
  if(src.is_null() || src->getType() != TYPE_##_STYPE_ || src->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  Ipp##_VCAST_##c val{ static_cast<Ipp##_VCAST_>(vec.x), static_cast<Ipp##_VCAST_>(vec.y) }; \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), val, dst->as##_DAS_(), len, scale)); \
}


#  define IPP_OP_CV_ISFS(_NAME_, _IMPL_, _SDTYPE_, _SDAS_, _VTYPE_, _VCAST_) \
IPP::Status IPP::_NAME_(_VTYPE_ vec, const Ref<IppBuffer> &srcDst, int len, int scale) { \
  if(srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  Ipp##_VCAST_##c val{ static_cast<Ipp##_VCAST_>(vec.x), static_cast<Ipp##_VCAST_>(vec.y) }; \
  return static_cast<Status>(_IMPL_(val, srcDst->as##_SDAS_(), len, scale)); \
}


#  define IPP_OP(_NAME_, _IMPL_, _LTYPE_, _LAS_, _RTYPE_, _RAS_, _DTYPE_, _DAS_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const godot::Ref<IppBuffer> &dst, int len) { \
  if(lhs.is_null() || lhs->getType() != TYPE_##_LTYPE_ || lhs->getLength() < len || \
     rhs.is_null() || rhs->getType() != TYPE_##_RTYPE_ || rhs->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(lhs->as##_LAS_(), rhs->as##_RAS_(), dst->as##_DAS_(), len)); \
}


#  define IPP_OP_I(_NAME_, _IMPL_, _STYPE_, _SAS_, _SDTYPE_, _SDAS_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len) { \
  if(src.is_null()    || src->getType()    != TYPE_##_STYPE_  || src->getLength()    < len || \
     srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), srcDst->as##_SDAS_(), len)); \
}


#  define IPP_OP_SFS(_NAME_, _IMPL_, _LTYPE_, _LAS_, _RTYPE_, _RAS_, _DTYPE_, _DAS_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, int scale) { \
  if(lhs.is_null() || lhs->getType() != TYPE_##_LTYPE_ || lhs->getLength() < len || \
     rhs.is_null() || rhs->getType() != TYPE_##_RTYPE_ || rhs->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(lhs->as##_LAS_(), rhs->as##_RAS_(), dst->as##_DAS_(), len, scale)); \
}


#  define IPP_OP_SFS_R(_NAME_, _IMPL_, _LTYPE_, _LAS_, _RTYPE_, _RAS_, _DTYPE_, _DAS_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &lhs, const Ref<IppBuffer> &rhs, const Ref<IppBuffer> &dst, int len, Round round, int scale) { \
  if(lhs.is_null() || lhs->getType() != TYPE_##_LTYPE_ || lhs->getLength() < len || \
     rhs.is_null() || rhs->getType() != TYPE_##_RTYPE_ || rhs->getLength() < len || \
     dst.is_null() || dst->getType() != TYPE_##_DTYPE_ || dst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(lhs->as##_LAS_(), rhs->as##_RAS_(), dst->as##_DAS_(), len, static_cast<IppRoundMode>(round), scale)); \
}


#  define IPP_OP_ISFS(_NAME_, _IMPL_, _STYPE_, _SAS_, _SDTYPE_, _SDAS_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len, int scale) { \
  if(src.is_null()    || src->getType()    != TYPE_##_STYPE_  || src->getLength()    < len || \
     srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), srcDst->as##_SDAS_(), len, scale)); \
}


#  define IPP_OP_ISFS_R(_NAME_, _IMPL_, _STYPE_, _SAS_, _SDTYPE_, _SDAS_) \
IPP::Status IPP::_NAME_(const Ref<IppBuffer> &src, const Ref<IppBuffer> &srcDst, int len, Round round, int scale) { \
  if(src.is_null()    || src->getType()    != TYPE_##_STYPE_  || src->getLength()    < len || \
     srcDst.is_null() || srcDst->getType() != TYPE_##_SDTYPE_ || srcDst->getLength() < len) { \
    return STAT_BAD_ARG_ERR; \
  } \
  return static_cast<Status>(_IMPL_(src->as##_SAS_(), srcDst->as##_SDAS_(), len, static_cast<IppRoundMode>(round), scale)); \
}

#endif


#endif /* IPP_GDEXT_H */

