/*
 * File: coloumb_counting.h
 *
 * Code generated for Simulink model 'coloumb_counting'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Feb 23 17:02:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_coloumb_counting_h_
#define RTW_HEADER_coloumb_counting_h_
#ifndef coloumb_counting_COMMON_INCLUDES_
#define coloumb_counting_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* coloumb_counting_COMMON_INCLUDES_ */

#include "coloumb_counting_types.h"

/* Block states (default storage) for system '<Root>/estimator1' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S11>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S11>/Integrator' */
} DW_CoreSubsys_coloumb_countin_T;

/* Block states (default storage) for system '<Root>/estimator1' */
typedef struct {
  DW_CoreSubsys_coloumb_countin_T CoreSubsys;/* '<Root>/estimator1' */
} DW_estimator1_coloumb_countin_T;

/* Block states (default storage) for model 'coloumb_counting' */
typedef struct {
  DW_estimator1_coloumb_countin_T estimator9[1];/* '<Root>/estimator9' */
  DW_estimator1_coloumb_countin_T estimator8[1];/* '<Root>/estimator8' */
  DW_estimator1_coloumb_countin_T estimator7[1];/* '<Root>/estimator7' */
  DW_estimator1_coloumb_countin_T estimator6[1];/* '<Root>/estimator6' */
  DW_estimator1_coloumb_countin_T estimator5[1];/* '<Root>/estimator5' */
  DW_estimator1_coloumb_countin_T estimator4[1];/* '<Root>/estimator4' */
  DW_estimator1_coloumb_countin_T estimator3[1];/* '<Root>/estimator3' */
  DW_estimator1_coloumb_countin_T estimator2[1];/* '<Root>/estimator2' */
  DW_estimator1_coloumb_countin_T estimator1[1];/* '<Root>/estimator1' */
} DW_coloumb_counting_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_coloumb_counting_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_coloumb_counting_f_T rtdw;
  RT_MODEL_coloumb_counting_T rtm;
} MdlrefDW_coloumb_counting_T;

/* Model reference registration function */
extern void coloumb_counting_initialize(const char_T **rt_errorStatus,
  RT_MODEL_coloumb_counting_T *const coloumb_counting_M);
extern void coloumb_countin_estimator1_Init(int16_T NumIters,
  DW_estimator1_coloumb_countin_T localDW[1]);
extern void coloumb_counting_estimator1(int16_T NumIters, const real_T
  *rtu_Current, const real_T *rtu_AH, const real_T *rtu_InitialSOC, real_T
  *rty_SOC, DW_estimator1_coloumb_countin_T localDW[1]);
extern void coloumb_counting_Init(DW_coloumb_counting_f_T *localDW);
extern void coloumb_counting(const real_T rtu_I_meas[9], const real_T
  *rtu_CAP_Ah, const real_T rtu_SOC_init[9], real_T rty_SOC_est[9],
  DW_coloumb_counting_f_T *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'coloumb_counting'
 * '<S1>'   : 'coloumb_counting/estimator1'
 * '<S2>'   : 'coloumb_counting/estimator2'
 * '<S3>'   : 'coloumb_counting/estimator3'
 * '<S4>'   : 'coloumb_counting/estimator4'
 * '<S5>'   : 'coloumb_counting/estimator5'
 * '<S6>'   : 'coloumb_counting/estimator6'
 * '<S7>'   : 'coloumb_counting/estimator7'
 * '<S8>'   : 'coloumb_counting/estimator8'
 * '<S9>'   : 'coloumb_counting/estimator9'
 * '<S10>'  : 'coloumb_counting/estimator1/Integrator'
 * '<S11>'  : 'coloumb_counting/estimator1/Integrator/Discrete'
 * '<S12>'  : 'coloumb_counting/estimator2/Integrator'
 * '<S13>'  : 'coloumb_counting/estimator2/Integrator/Discrete'
 * '<S14>'  : 'coloumb_counting/estimator3/Integrator'
 * '<S15>'  : 'coloumb_counting/estimator3/Integrator/Discrete'
 * '<S16>'  : 'coloumb_counting/estimator4/Integrator'
 * '<S17>'  : 'coloumb_counting/estimator4/Integrator/Discrete'
 * '<S18>'  : 'coloumb_counting/estimator5/Integrator'
 * '<S19>'  : 'coloumb_counting/estimator5/Integrator/Discrete'
 * '<S20>'  : 'coloumb_counting/estimator6/Integrator'
 * '<S21>'  : 'coloumb_counting/estimator6/Integrator/Discrete'
 * '<S22>'  : 'coloumb_counting/estimator7/Integrator'
 * '<S23>'  : 'coloumb_counting/estimator7/Integrator/Discrete'
 * '<S24>'  : 'coloumb_counting/estimator8/Integrator'
 * '<S25>'  : 'coloumb_counting/estimator8/Integrator/Discrete'
 * '<S26>'  : 'coloumb_counting/estimator9/Integrator'
 * '<S27>'  : 'coloumb_counting/estimator9/Integrator/Discrete'
 */
#endif                                 /* RTW_HEADER_coloumb_counting_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
