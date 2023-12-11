/*
 * File: batteryStateFcn1.c
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

#include "batteryStateFcn1.h"

/* Include model header file for global data */
#include "Estimations.h"
#include "Estimations_private.h"
#include "look2_binlxpw.h"

/* Output and update for Simulink Function: '<Root>/Simulink Function - State Transition Function1' */
void batteryStateFcn1(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_C1Table;

  /* Lookup_n-D: '<S2>/C1 Table' incorporates:
   *  Inport: '<Root>/temp'
   *  SignalConversion generated from: '<S2>/x'
   */
  rtb_C1Table = look2_binlxpw(rtu_x1[0], Estimations_U.temp,
    rtCP_C1Table_bp01Data, rtCP_C1Table_bp02Data, rtCP_C1Table_tableData,
    rtCP_C1Table_maxIndex, 21UL);

  /* MATLAB Function: '<S2>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq'
   *  Inport: '<Root>/current'
   *  Inport: '<Root>/temp'
   *  Lookup_n-D: '<S2>/R1 Table'
   *  SignalConversion generated from: '<S2>/x'
   */
  rty_x1Next[0] = -Estimations_U.current / (3600.0 * Estimations_U.Cq);
  rty_x1Next[1] = -1.0 / (look2_binlxpw(rtu_x1[0], Estimations_U.temp,
    rtCP_R1Table_bp01Data, rtCP_R1Table_bp02Data, rtCP_R1Table_tableData,
    rtCP_R1Table_maxIndex, 21UL) * rtb_C1Table) * rtu_x1[1] +
    Estimations_U.current / rtb_C1Table;
  rty_x1Next[2] = 0.0;

  /* SignalConversion generated from: '<S2>/xNext' incorporates:
   *  Product: '<S2>/Product'
   *  SignalConversion generated from: '<S2>/x'
   *  Sum: '<S2>/Add'
   */
  rty_x1Next[0] += rtu_x1[0];
  rty_x1Next[1] += rtu_x1[1];
  rty_x1Next[2] += rtu_x1[2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
