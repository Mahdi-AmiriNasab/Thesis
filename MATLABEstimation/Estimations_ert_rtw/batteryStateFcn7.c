/*
 * File: batteryStateFcn7.c
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
#include "batteryStateFcn7.h"
#include "rt_sys_batteryStateFcn1_7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S7>/Simulink Function - State Transition Function1' */
void batteryStateFcn7(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_Add[3];

  /* MATLAB Function: '<S71>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq7'
   *  Inport: '<Root>/current7'
   *  Inport: '<Root>/temp7'
   *  Lookup_n-D: '<S71>/C1 Table'
   *  Lookup_n-D: '<S71>/R1 Table'
   *  SignalConversion generated from: '<S71>/x1'
   */
  Estimations_fxu(rtu_x1, look2_binlxpw(rtu_x1[0], Estimations_U.temp7,
    rtCP_C1Table_bp01Data_j, rtCP_C1Table_bp02Data_b, rtCP_C1Table_tableData_k,
    rtCP_C1Table_maxIndex_o, 21UL), look2_binlxpw(rtu_x1[0], Estimations_U.temp7,
    rtCP_R1Table_bp01Data_a, rtCP_R1Table_bp02Data_j, rtCP_R1Table_tableData_a,
    rtCP_R1Table_maxIndex_gp, 21UL), Estimations_U.Cq7, Estimations_U.current7,
                  rtb_Add);

  /* SignalConversion generated from: '<S71>/x1Next' incorporates:
   *  Product: '<S71>/Product'
   *  SignalConversion generated from: '<S71>/x1'
   *  Sum: '<S71>/Add'
   */
  rty_x1Next[0] = rtu_x1[0] + rtb_Add[0];
  rty_x1Next[1] = rtu_x1[1] + rtb_Add[1];
  rty_x1Next[2] = rtu_x1[2] + rtb_Add[2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
