/*
 * File: ADCFilter.h
 *
 * Code generated for Simulink model 'ADCFilter'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb  7 12:27:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADCFilter_h_
#define RTW_HEADER_ADCFilter_h_
#include <stddef.h>
#include <string.h>
#ifndef ADCFilter_COMMON_INCLUDES_
#define ADCFilter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ADCFilter_COMMON_INCLUDES_ */

#include "ADCFilter_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<Root>/Moving Average2' */
typedef struct {
  real_T csumrev[9];
  real_T MovingAverage2;               /* '<Root>/Moving Average2' */
} B_MovingAverage2_ADCFilter_T;

/* Block states (default storage) for system '<Root>/Moving Average2' */
typedef struct {
  dsp_simulink_MovingAverage_AD_T obj; /* '<Root>/Moving Average2' */
  boolean_T objisempty;                /* '<Root>/Moving Average2' */
} DW_MovingAverage2_ADCFilter_T;

/* Block signals (default storage) */
typedef struct {
  B_MovingAverage2_ADCFilter_T MovingAverage3;/* '<Root>/Moving Average2' */
  B_MovingAverage2_ADCFilter_T MovingAverage2;/* '<Root>/Moving Average2' */
} B_ADCFilter_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_MovingAverage2_ADCFilter_T MovingAverage3;/* '<Root>/Moving Average2' */
  DW_MovingAverage2_ADCFilter_T MovingAverage2;/* '<Root>/Moving Average2' */
} DW_ADCFilter_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T LowCurrent;                   /* '<Root>/LowCurrent' */
  real_T HighCurrent;                  /* '<Root>/HighCurrent' */
  real_T PackVoltage;                  /* '<Root>/PackVoltage' */
} ExtU_ADCFilter_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T lowCurrentFilter;             /* '<Root>/lowCurrentFilter' */
  real_T highCurrentFilter;            /* '<Root>/highCurrentFilter' */
  real_T Current;                      /* '<Root>/Current' */
  real_T Voltage;                      /* '<Root>/Voltage' */
} ExtY_ADCFilter_T;

/* Real-time Model Data Structure */
struct tag_RTM_ADCFilter_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_ADCFilter_T ADCFilter_B;

/* Block states (default storage) */
extern DW_ADCFilter_T ADCFilter_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ADCFilter_T ADCFilter_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ADCFilter_T ADCFilter_Y;

/* Model entry point functions */
extern void ADCFilter_initialize(void);
extern void ADCFilter_step(void);
extern void ADCFilter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADCFilter_T *const ADCFilter_M;

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
 * '<Root>' : 'ADCFilter'
 * '<S1>'   : 'ADCFilter/MATLAB Function'
 * '<S2>'   : 'ADCFilter/MATLAB Function1'
 * '<S3>'   : 'ADCFilter/MATLAB Function2'
 * '<S4>'   : 'ADCFilter/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_ADCFilter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
