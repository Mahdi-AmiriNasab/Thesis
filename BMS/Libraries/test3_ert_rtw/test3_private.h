/*
 * File: test3_private.h
 *
 * Code generated for Simulink model 'test3'.
 *
 * Model version                  : 2.300
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon May 15 12:45:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test3_private_h_
#define RTW_HEADER_test3_private_h_
#include "rtwtypes.h"
#include "test3.h"

extern real_T rt_roundd_snf(real_T u);
extern real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern real32_T look2_iflf_pbinlcpw(real32_T u0, real32_T u1, const real32_T
  bp0[], const real32_T bp1[], const real32_T table[], uint32_T prevIndex[],
  const uint32_T maxIndex[], uint32_T stride);
extern real32_T look1_iflf_pbinlcpw(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T prevIndex[], uint32_T maxIndex);
extern void test3_MovingAverage_Init(DW_MovingAverage_test3_T *localDW);
extern void test3_MovingAverage(real32_T rtu_0, B_MovingAverage_test3_T *localB,
  DW_MovingAverage_test3_T *localDW);
extern void test3_MovingAverage_Term(DW_MovingAverage_test3_T *localDW);

#endif                                 /* RTW_HEADER_test3_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
