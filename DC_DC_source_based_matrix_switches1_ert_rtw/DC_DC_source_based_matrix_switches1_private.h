/*
 * File: DC_DC_source_based_matrix_switches1_private.h
 *
 * Code generated for Simulink model 'DC_DC_source_based_matrix_switches1'.
 *
 * Model version                  : 3.20
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Feb 23 17:03:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DC_DC_source_based_matrix_switches1_private_h_
#define RTW_HEADER_DC_DC_source_based_matrix_switches1_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "DC_DC_source_based_matrix_switches1.h"
#include "DC_DC_source_based_matrix_switches1_types.h"
#include <math.h>
#include <stdlib.h>

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef CodeFormat
#define CodeFormat                     S-Function
#else
#undef CodeFormat
#define CodeFormat                     S-Function
#endif

#ifndef S_FUNCTION_NAME
#define S_FUNCTION_NAME                simulink_only_sfcn
#else
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME                simulink_only_sfcn
#endif

#ifndef S_FUNCTION_LEVEL
#define S_FUNCTION_LEVEL               2
#else
#undef S_FUNCTION_LEVEL
#define S_FUNCTION_LEVEL               2
#endif

#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        NULL
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES
#ifndef _RTW_COMMON_DEFINES_
#define _RTW_COMMON_DEFINES_
#endif
#endif

extern const real_T rtCP_pooled_iKooAVYkcFiH[18];
extern const real_T rtCP_pooled_41JgcckNty8j[100];
extern const real_T rtCP_pooled_rNoVleUndEEE[100];
extern const real_T rtCP_pooled_4CDCIpjdnAvj[50];
extern const real_T rtCP_pooled_ifJFQahyw0B2[50];
extern const real_T rtCP_pooled_Y48G8lj18RLC;
extern const real_T rtCP_pooled_sWEQwtCaJMW6[784];

#define rtCP_SwitchCurrents_Value      rtCP_pooled_iKooAVYkcFiH  /* Expression: zeros(18,1)
                                                                  * Referenced by: '<S210>/SwitchCurrents'
                                                                  */
#define rtCP_Constant_Value_dc         rtCP_pooled_41JgcckNty8j  /* Expression: src_q_cls
                                                                  * Referenced by: '<Root>/Constant'
                                                                  */
#define rtCP_Constant1_Value_cx        rtCP_pooled_rNoVleUndEEE  /* Expression: dst_q_cls
                                                                  * Referenced by: '<Root>/Constant1'
                                                                  */
#define rtCP_Constant2_Value_p         rtCP_pooled_4CDCIpjdnAvj  /* Expression: src_trg_soc_av
                                                                  * Referenced by: '<Root>/Constant2'
                                                                  */
#define rtCP_Constant4_Value_lo        rtCP_pooled_ifJFQahyw0B2  /* Expression: dst_trg_soc_av
                                                                  * Referenced by: '<Root>/Constant4'
                                                                  */
#define rtCP_Constant5_Value           rtCP_pooled_Y48G8lj18RLC  /* Expression: cell_cap_Ah
                                                                  * Referenced by: '<Root>/Constant5'
                                                                  */
#define rtCP_StateSpace_DS_param       rtCP_pooled_sWEQwtCaJMW6  /* Expression: S.D
                                                                  * Referenced by: '<S207>/State-Space'
                                                                  */

extern void DC_DC_sour_NEGATIVEEdge_Disable(DW_NEGATIVEEdge_DC_DC_source__T
  *localDW);
extern void DC_DC_source_based_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN,
  boolean_T rtu_INprevious, boolean_T *rty_OUT, DW_NEGATIVEEdge_DC_DC_source__T *
  localDW);
extern void DC_DC_sour_POSITIVEEdge_Disable(DW_POSITIVEEdge_DC_DC_source__T
  *localDW);
extern void DC_DC_source_based_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN,
  boolean_T rtu_INprevious, boolean_T *rty_OUT, DW_POSITIVEEdge_DC_DC_source__T *
  localDW);
extern void DC_DC_source_based_matri_demuxn(real_T rtu_u, real_T *rty_s1, real_T
  *rty_s2, real_T *rty_s3, real_T *rty_s4, real_T *rty_s5, real_T *rty_s6,
  real_T *rty_s7, real_T *rty_s8, real_T *rty_s9);

#endif           /* RTW_HEADER_DC_DC_source_based_matrix_switches1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
