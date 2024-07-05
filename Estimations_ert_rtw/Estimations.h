/*
 * File: Estimations.h
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 15:23:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Estimations_h_
#define RTW_HEADER_Estimations_h_
#include <math.h>
#ifndef Estimations_COMMON_INCLUDES_
#define Estimations_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Estimations_COMMON_INCLUDES_ */

#include "Estimations_types.h"

/* Child system includes */
#include "batteryMeasurementFcn1_private.h"
#include "batteryMeasurementFcn1.h"
#include "batteryStateFcn1_private.h"
#include "batteryStateFcn1.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T P[9];                         /* '<S3>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S3>/DataStoreMemory - x' */
} DW_Estimations_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T MeasuredCurrent;              /* '<Root>/Measured Current' */
  real_T In2;                          /* '<Root>/In2' */
  real_T current;                      /* '<Root>/current' */
  real_T temp;                         /* '<Root>/temp' */
  real_T voltage;                      /* '<Root>/voltage' */
  real_T Cq;                           /* '<Root>/Cq' */
} ExtU_Estimations_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T cc;                           /* '<Root>/cc' */
  real_T SOC;                          /* '<Root>/SOC' */
  real_T R0;                           /* '<Root>/R0' */
  real_T R1_filter;                    /* '<Root>/R1_filter' */
} ExtY_Estimations_T;

/* Real-time Model Data Structure */
struct tag_RTM_Estimations_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Estimations_T Estimations_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Estimations_T Estimations_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Estimations_T Estimations_Y;

/* Model entry point functions */
extern void Estimations_initialize(void);
extern void Estimations_step(void);
extern void Estimations_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Estimations_T *const Estimations_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Divide1' : Unused code path elimination
 * Block '<Root>/Scope40' : Unused code path elimination
 * Block '<Root>/Scope42' : Unused code path elimination
 * Block '<S5>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S6>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S3>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S3>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope11' : Unused code path elimination
 * Block '<Root>/Scope13' : Unused code path elimination
 * Block '<Root>/Scope17' : Unused code path elimination
 * Block '<Root>/Scope18' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope20' : Unused code path elimination
 * Block '<Root>/Scope22' : Unused code path elimination
 * Block '<Root>/Scope23' : Unused code path elimination
 * Block '<Root>/Scope24' : Unused code path elimination
 * Block '<Root>/Scope25' : Unused code path elimination
 * Block '<Root>/Scope26' : Unused code path elimination
 * Block '<Root>/Scope27' : Unused code path elimination
 * Block '<Root>/Scope28' : Unused code path elimination
 * Block '<Root>/Scope29' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope30' : Unused code path elimination
 * Block '<Root>/Scope31' : Unused code path elimination
 * Block '<Root>/Scope32' : Unused code path elimination
 * Block '<Root>/Scope33' : Unused code path elimination
 * Block '<Root>/Scope34' : Unused code path elimination
 * Block '<Root>/Scope35' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
 * Block '<Root>/Current1' : Eliminated since input and output rates are identical
 * Block '<Root>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S3>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S3>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<Root>/Voltage1' : Eliminated since input and output rates are identical
 */

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
 * '<Root>' : 'Estimations'
 * '<S1>'   : 'Estimations/Simulink Function - Measurement Function1'
 * '<S2>'   : 'Estimations/Simulink Function - State Transition Function1'
 * '<S3>'   : 'Estimations/Unscented Kalman Filter1'
 * '<S4>'   : 'Estimations/Simulink Function - State Transition Function1/f(x,u)'
 * '<S5>'   : 'Estimations/Unscented Kalman Filter1/Correct1'
 * '<S6>'   : 'Estimations/Unscented Kalman Filter1/Predict'
 * '<S7>'   : 'Estimations/Unscented Kalman Filter1/Subsystem'
 * '<S8>'   : 'Estimations/Unscented Kalman Filter1/Correct1/Correct'
 * '<S9>'   : 'Estimations/Unscented Kalman Filter1/Predict/Predict'
 * '<S10>'  : 'Estimations/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Estimations_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
