/*
 * File: batteryStateFcn1.c
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
#include "batteryStateFcn1.h"
#include "rt_sys_batteryStateFcn1_7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S1>/Simulink Function - State Transition Function1' */
void batteryStateFcn1(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_Add[3];

  /* MATLAB Function: '<S11>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq1'
   *  Inport: '<Root>/current1'
   *  Inport: '<Root>/temp1'
   *  Lookup_n-D: '<S11>/C1 Table'
   *  Lookup_n-D: '<S11>/R1 Table'
   *  SignalConversion generated from: '<S11>/x'
   */
  Estimations_fxu(rtu_x1, look2_binlxpw(rtu_x1[0], Estimations_U.temp1,
    rtCP_C1Table_bp01Data, rtCP_C1Table_bp02Data, rtCP_C1Table_tableData,
    rtCP_C1Table_maxIndex, 21UL), look2_binlxpw(rtu_x1[0], Estimations_U.temp1,
    rtCP_R1Table_bp01Data, rtCP_R1Table_bp02Data, rtCP_R1Table_tableData,
    rtCP_R1Table_maxIndex, 21UL), Estimations_U.Cq1, Estimations_U.current1,
                  rtb_Add);

  /* SignalConversion generated from: '<S11>/xNext' incorporates:
   *  Product: '<S11>/Product'
   *  SignalConversion generated from: '<S11>/x'
   *  Sum: '<S11>/Add'
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
