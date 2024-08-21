/*
 * File: Estimations.h
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.6
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:23:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Estimations_h_
#define RTW_HEADER_Estimations_h_
#ifndef Estimations_COMMON_INCLUDES_
#define Estimations_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Estimations_COMMON_INCLUDES_ */

#include "Estimations_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "batteryStateFcn9.h"
#include "batteryMeasurementFcn9.h"
#include "batteryStateFcn7.h"
#include "batteryStateFcn6.h"
#include "batteryMeasurementFcn6.h"
#include "batteryStateFcn5.h"
#include "batteryStateFcn8.h"
#include "batteryMeasurementFcn5.h"
#include "batteryStateFcn4.h"
#include "batteryMeasurementFcn4.h"
#include "batteryStateFcn3.h"
#include "batteryMeasurementFcn7.h"
#include "batteryMeasurementFcn2.h"
#include "batteryStateFcn1.h"
#include "batteryMeasurementFcn8.h"
#include "batteryStateFcn2.h"
#include "batteryMeasurementFcn3.h"
#include "batteryMeasurementFcn1.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T P[9];                         /* '<S12>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S12>/DataStoreMemory - x' */
  real_T P_e[9];                       /* '<S22>/DataStoreMemory - P' */
  real_T x_a[3];                       /* '<S22>/DataStoreMemory - x' */
  real_T P_i[9];                       /* '<S32>/DataStoreMemory - P' */
  real_T x_av[3];                      /* '<S32>/DataStoreMemory - x' */
  real_T P_p[9];                       /* '<S42>/DataStoreMemory - P' */
  real_T x_n[3];                       /* '<S42>/DataStoreMemory - x' */
  real_T P_in[9];                      /* '<S52>/DataStoreMemory - P' */
  real_T x_d[3];                       /* '<S52>/DataStoreMemory - x' */
  real_T P_k[9];                       /* '<S62>/DataStoreMemory - P' */
  real_T x_m[3];                       /* '<S62>/DataStoreMemory - x' */
  real_T P_in1[9];                     /* '<S72>/DataStoreMemory - P' */
  real_T x_j[3];                       /* '<S72>/DataStoreMemory - x' */
  real_T P_j[9];                       /* '<S82>/DataStoreMemory - P' */
  real_T x_e[3];                       /* '<S82>/DataStoreMemory - x' */
  real_T P_d[9];                       /* '<S92>/DataStoreMemory - P' */
  real_T x_l[3];                       /* '<S92>/DataStoreMemory - x' */
} DW_Estimations_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T current1;                     /* '<Root>/current1' */
  real_T temp1;                        /* '<Root>/temp1' */
  real_T voltage1;                     /* '<Root>/voltage1' */
  real_T Cq1;                          /* '<Root>/Cq1' */
  real_T current2;                     /* '<Root>/current2' */
  real_T temp2;                        /* '<Root>/temp2' */
  real_T voltage2;                     /* '<Root>/voltage2' */
  real_T Cq2;                          /* '<Root>/Cq2' */
  real_T current3;                     /* '<Root>/current3' */
  real_T temp3;                        /* '<Root>/temp3' */
  real_T voltage3;                     /* '<Root>/voltage3' */
  real_T Cq3;                          /* '<Root>/Cq3' */
  real_T current4;                     /* '<Root>/current4' */
  real_T temp4;                        /* '<Root>/temp4' */
  real_T voltage4;                     /* '<Root>/voltage4' */
  real_T Cq4;                          /* '<Root>/Cq4' */
  real_T current5;                     /* '<Root>/current5' */
  real_T temp5;                        /* '<Root>/temp5' */
  real_T voltage5;                     /* '<Root>/voltage5' */
  real_T Cq5;                          /* '<Root>/Cq5' */
  real_T current6;                     /* '<Root>/current6' */
  real_T temp6;                        /* '<Root>/temp6' */
  real_T voltage6;                     /* '<Root>/voltage6' */
  real_T Cq6;                          /* '<Root>/Cq6' */
  real_T current7;                     /* '<Root>/current7' */
  real_T temp7;                        /* '<Root>/temp7' */
  real_T voltage7;                     /* '<Root>/voltage7' */
  real_T Cq7;                          /* '<Root>/Cq7' */
  real_T current8;                     /* '<Root>/current8' */
  real_T temp8;                        /* '<Root>/temp8' */
  real_T voltage8;                     /* '<Root>/voltage8' */
  real_T Cq8;                          /* '<Root>/Cq8' */
  real_T current9;                     /* '<Root>/current9' */
  real_T temp9;                        /* '<Root>/temp9' */
  real_T voltage9;                     /* '<Root>/voltage9' */
  real_T Cq9;                          /* '<Root>/Cq9' */
} ExtU_Estimations_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SOC1;                         /* '<Root>/SOC1' */
  real_T SOC2;                         /* '<Root>/SOC2' */
  real_T SOC3;                         /* '<Root>/SOC3' */
  real_T SOC4;                         /* '<Root>/SOC4' */
  real_T SOC5;                         /* '<Root>/SOC5' */
  real_T SOC6;                         /* '<Root>/SOC6' */
  real_T SOC7;                         /* '<Root>/SOC7' */
  real_T SOC8;                         /* '<Root>/SOC8' */
  real_T SOC9;                         /* '<Root>/SOC9' */
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
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S1>/Divide1' : Unused code path elimination
 * Block '<S1>/Scope40' : Unused code path elimination
 * Block '<S1>/Scope42' : Unused code path elimination
 * Block '<S14>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S15>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S12>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S12>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Divide1' : Unused code path elimination
 * Block '<S2>/Scope40' : Unused code path elimination
 * Block '<S2>/Scope42' : Unused code path elimination
 * Block '<S24>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S25>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S22>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S22>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/Divide1' : Unused code path elimination
 * Block '<S3>/Scope40' : Unused code path elimination
 * Block '<S3>/Scope42' : Unused code path elimination
 * Block '<S34>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S35>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S32>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S32>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S4>/Divide1' : Unused code path elimination
 * Block '<S4>/Scope40' : Unused code path elimination
 * Block '<S4>/Scope42' : Unused code path elimination
 * Block '<S44>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S45>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S42>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S42>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S5>/Constant1' : Unused code path elimination
 * Block '<S5>/Divide1' : Unused code path elimination
 * Block '<S5>/Scope40' : Unused code path elimination
 * Block '<S5>/Scope42' : Unused code path elimination
 * Block '<S54>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S55>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S52>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S52>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S6>/Constant1' : Unused code path elimination
 * Block '<S6>/Divide1' : Unused code path elimination
 * Block '<S6>/Scope40' : Unused code path elimination
 * Block '<S6>/Scope42' : Unused code path elimination
 * Block '<S64>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S65>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S62>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S62>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S7>/Constant1' : Unused code path elimination
 * Block '<S7>/Divide1' : Unused code path elimination
 * Block '<S7>/Scope40' : Unused code path elimination
 * Block '<S7>/Scope42' : Unused code path elimination
 * Block '<S74>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S75>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S72>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S72>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S8>/Constant1' : Unused code path elimination
 * Block '<S8>/Divide1' : Unused code path elimination
 * Block '<S8>/Scope40' : Unused code path elimination
 * Block '<S8>/Scope42' : Unused code path elimination
 * Block '<S84>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S85>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S82>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S82>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S9>/Constant1' : Unused code path elimination
 * Block '<S9>/Divide1' : Unused code path elimination
 * Block '<S9>/Scope40' : Unused code path elimination
 * Block '<S9>/Scope42' : Unused code path elimination
 * Block '<S94>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S95>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S92>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S92>/checkStateTransitionFcnSignals' : Unused code path elimination
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
 * Block '<S1>/Current1' : Eliminated since input and output rates are identical
 * Block '<S1>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S12>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S12>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S1>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S2>/Current1' : Eliminated since input and output rates are identical
 * Block '<S2>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S22>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S22>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S22>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S22>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S22>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S22>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S2>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S3>/Current1' : Eliminated since input and output rates are identical
 * Block '<S3>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S32>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S32>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S32>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S32>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S32>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S32>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S3>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S4>/Current1' : Eliminated since input and output rates are identical
 * Block '<S4>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S42>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S42>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S42>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S42>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S42>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S42>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S4>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S5>/Current1' : Eliminated since input and output rates are identical
 * Block '<S5>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S52>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S52>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S52>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S52>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S52>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S52>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S5>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S6>/Current1' : Eliminated since input and output rates are identical
 * Block '<S6>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S62>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S62>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S62>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S62>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S62>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S62>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S6>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S7>/Current1' : Eliminated since input and output rates are identical
 * Block '<S7>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S72>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S72>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S72>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S72>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S72>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S72>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S7>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S8>/Current1' : Eliminated since input and output rates are identical
 * Block '<S8>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S82>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S82>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S82>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S82>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S82>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S82>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S8>/Voltage1' : Eliminated since input and output rates are identical
 * Block '<S9>/Current1' : Eliminated since input and output rates are identical
 * Block '<S9>/Tem1' : Eliminated since input and output rates are identical
 * Block '<S92>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S92>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S92>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S92>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S92>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S92>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S9>/Voltage1' : Eliminated since input and output rates are identical
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
 * '<S1>'   : 'Estimations/Subsystem1'
 * '<S2>'   : 'Estimations/Subsystem2'
 * '<S3>'   : 'Estimations/Subsystem3'
 * '<S4>'   : 'Estimations/Subsystem4'
 * '<S5>'   : 'Estimations/Subsystem5'
 * '<S6>'   : 'Estimations/Subsystem6'
 * '<S7>'   : 'Estimations/Subsystem7'
 * '<S8>'   : 'Estimations/Subsystem8'
 * '<S9>'   : 'Estimations/Subsystem9'
 * '<S10>'  : 'Estimations/Subsystem1/Simulink Function - Measurement Function1'
 * '<S11>'  : 'Estimations/Subsystem1/Simulink Function - State Transition Function1'
 * '<S12>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1'
 * '<S13>'  : 'Estimations/Subsystem1/Simulink Function - State Transition Function1/f(x,u)'
 * '<S14>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1/Correct1'
 * '<S15>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1/Predict'
 * '<S16>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1/Subsystem'
 * '<S17>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1/Correct1/Correct'
 * '<S18>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1/Predict/Predict'
 * '<S19>'  : 'Estimations/Subsystem1/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S20>'  : 'Estimations/Subsystem2/Simulink Function - Measurement Function2'
 * '<S21>'  : 'Estimations/Subsystem2/Simulink Function - State Transition Function2'
 * '<S22>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1'
 * '<S23>'  : 'Estimations/Subsystem2/Simulink Function - State Transition Function2/f(x,u)'
 * '<S24>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1/Correct1'
 * '<S25>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1/Predict'
 * '<S26>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1/Subsystem'
 * '<S27>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1/Correct1/Correct'
 * '<S28>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1/Predict/Predict'
 * '<S29>'  : 'Estimations/Subsystem2/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S30>'  : 'Estimations/Subsystem3/Simulink Function - Measurement Function1'
 * '<S31>'  : 'Estimations/Subsystem3/Simulink Function - State Transition Function1'
 * '<S32>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1'
 * '<S33>'  : 'Estimations/Subsystem3/Simulink Function - State Transition Function1/f(x,u)'
 * '<S34>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1/Correct1'
 * '<S35>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1/Predict'
 * '<S36>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1/Subsystem'
 * '<S37>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1/Correct1/Correct'
 * '<S38>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1/Predict/Predict'
 * '<S39>'  : 'Estimations/Subsystem3/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S40>'  : 'Estimations/Subsystem4/Simulink Function - Measurement Function1'
 * '<S41>'  : 'Estimations/Subsystem4/Simulink Function - State Transition Function1'
 * '<S42>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1'
 * '<S43>'  : 'Estimations/Subsystem4/Simulink Function - State Transition Function1/f(x,u)'
 * '<S44>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1/Correct1'
 * '<S45>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1/Predict'
 * '<S46>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1/Subsystem'
 * '<S47>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1/Correct1/Correct'
 * '<S48>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1/Predict/Predict'
 * '<S49>'  : 'Estimations/Subsystem4/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S50>'  : 'Estimations/Subsystem5/Simulink Function - Measurement Function1'
 * '<S51>'  : 'Estimations/Subsystem5/Simulink Function - State Transition Function1'
 * '<S52>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1'
 * '<S53>'  : 'Estimations/Subsystem5/Simulink Function - State Transition Function1/f(x,u)'
 * '<S54>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1/Correct1'
 * '<S55>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1/Predict'
 * '<S56>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1/Subsystem'
 * '<S57>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1/Correct1/Correct'
 * '<S58>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1/Predict/Predict'
 * '<S59>'  : 'Estimations/Subsystem5/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S60>'  : 'Estimations/Subsystem6/Simulink Function - Measurement Function1'
 * '<S61>'  : 'Estimations/Subsystem6/Simulink Function - State Transition Function1'
 * '<S62>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1'
 * '<S63>'  : 'Estimations/Subsystem6/Simulink Function - State Transition Function1/f(x,u)'
 * '<S64>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1/Correct1'
 * '<S65>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1/Predict'
 * '<S66>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1/Subsystem'
 * '<S67>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1/Correct1/Correct'
 * '<S68>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1/Predict/Predict'
 * '<S69>'  : 'Estimations/Subsystem6/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S70>'  : 'Estimations/Subsystem7/Simulink Function - Measurement Function1'
 * '<S71>'  : 'Estimations/Subsystem7/Simulink Function - State Transition Function1'
 * '<S72>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1'
 * '<S73>'  : 'Estimations/Subsystem7/Simulink Function - State Transition Function1/f(x,u)'
 * '<S74>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1/Correct1'
 * '<S75>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1/Predict'
 * '<S76>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1/Subsystem'
 * '<S77>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1/Correct1/Correct'
 * '<S78>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1/Predict/Predict'
 * '<S79>'  : 'Estimations/Subsystem7/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S80>'  : 'Estimations/Subsystem8/Simulink Function - Measurement Function1'
 * '<S81>'  : 'Estimations/Subsystem8/Simulink Function - State Transition Function1'
 * '<S82>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1'
 * '<S83>'  : 'Estimations/Subsystem8/Simulink Function - State Transition Function1/f(x,u)'
 * '<S84>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1/Correct1'
 * '<S85>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1/Predict'
 * '<S86>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1/Subsystem'
 * '<S87>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1/Correct1/Correct'
 * '<S88>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1/Predict/Predict'
 * '<S89>'  : 'Estimations/Subsystem8/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 * '<S90>'  : 'Estimations/Subsystem9/Simulink Function - Measurement Function1'
 * '<S91>'  : 'Estimations/Subsystem9/Simulink Function - State Transition Function1'
 * '<S92>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1'
 * '<S93>'  : 'Estimations/Subsystem9/Simulink Function - State Transition Function1/f(x,u)'
 * '<S94>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1/Correct1'
 * '<S95>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1/Predict'
 * '<S96>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1/Subsystem'
 * '<S97>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1/Correct1/Correct'
 * '<S98>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1/Predict/Predict'
 * '<S99>'  : 'Estimations/Subsystem9/Unscented Kalman Filter1/Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Estimations_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
