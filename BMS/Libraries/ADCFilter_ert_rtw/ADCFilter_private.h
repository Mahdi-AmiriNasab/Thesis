/*
 * File: ADCFilter_private.h
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

#ifndef RTW_HEADER_ADCFilter_private_h_
#define RTW_HEADER_ADCFilter_private_h_
#include "rtwtypes.h"
#include "ADCFilter.h"

extern void ADCFilter_MovingAverage2_Init(DW_MovingAverage2_ADCFilter_T *localDW);
extern void ADCFilter_MovingAverage2(real_T rtu_0, B_MovingAverage2_ADCFilter_T *
  localB, DW_MovingAverage2_ADCFilter_T *localDW);
extern void ADCFilter_MovingAverage2_Term(DW_MovingAverage2_ADCFilter_T *localDW);

#endif                                 /* RTW_HEADER_ADCFilter_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
