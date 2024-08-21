/*
 * File: rt_sys_batteryStateFcn1_7.c
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

#include "rtwtypes.h"
#include "rt_sys_batteryStateFcn1_7.h"

/*
 * Output and update for atomic system:
 *    '<S11>/f(x,u)'
 *    '<S21>/f(x,u)'
 *    '<S31>/f(x,u)'
 *    '<S41>/f(x,u)'
 *    '<S51>/f(x,u)'
 *    '<S61>/f(x,u)'
 *    '<S71>/f(x,u)'
 *    '<S81>/f(x,u)'
 *    '<S91>/f(x,u)'
 */
void Estimations_fxu(const real_T rtu_x[3], real_T rtu_C1, real_T rtu_R1, real_T
                     rtu_Cq, real_T rtu_I, real_T rty_xdot[3])
{
  rty_xdot[0] = -rtu_I / (3600.0 * rtu_Cq);
  rty_xdot[1] = -1.0 / (rtu_R1 * rtu_C1) * rtu_x[1] + rtu_I / rtu_C1;
  rty_xdot[2] = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
