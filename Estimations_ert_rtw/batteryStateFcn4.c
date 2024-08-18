/*
 * File: batteryStateFcn4.c
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
#include "batteryStateFcn4.h"
#include "rt_sys_batteryStateFcn1_7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S4>/Simulink Function - State Transition Function1' */
void batteryStateFcn4(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_Add[3];

  /* MATLAB Function: '<S41>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq4'
   *  Inport: '<Root>/current4'
   *  Inport: '<Root>/temp4'
   *  Lookup_n-D: '<S41>/C1 Table'
   *  Lookup_n-D: '<S41>/R1 Table'
   *  SignalConversion generated from: '<S41>/x1'
   */
  Estimations_fxu(rtu_x1, look2_binlxpw(rtu_x1[0], Estimations_U.temp4,
    rtCP_C1Table_bp01Data_k, rtCP_C1Table_bp02Data_m, rtCP_C1Table_tableData_ji,
    rtCP_C1Table_maxIndex_f, 21UL), look2_binlxpw(rtu_x1[0], Estimations_U.temp4,
    rtCP_R1Table_bp01Data_p, rtCP_R1Table_bp02Data_d, rtCP_R1Table_tableData_e,
    rtCP_R1Table_maxIndex_m, 21UL), Estimations_U.Cq4, Estimations_U.current4,
                  rtb_Add);

  /* SignalConversion generated from: '<S41>/x1Next' incorporates:
   *  Product: '<S41>/Product'
   *  SignalConversion generated from: '<S41>/x1'
   *  Sum: '<S41>/Add'
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
