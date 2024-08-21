/*
 * File: batteryStateFcn6.c
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
#include "batteryStateFcn6.h"
#include "rt_sys_batteryStateFcn1_7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S6>/Simulink Function - State Transition Function1' */
void batteryStateFcn6(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_Add[3];

  /* MATLAB Function: '<S61>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq6'
   *  Inport: '<Root>/current6'
   *  Inport: '<Root>/temp6'
   *  Lookup_n-D: '<S61>/C1 Table'
   *  Lookup_n-D: '<S61>/R1 Table'
   *  SignalConversion generated from: '<S61>/x1'
   */
  Estimations_fxu(rtu_x1, look2_binlxpw(rtu_x1[0], Estimations_U.temp6,
    rtCP_C1Table_bp01Data_e3, rtCP_C1Table_bp02Data_p, rtCP_C1Table_tableData_g,
    rtCP_C1Table_maxIndex_l, 21UL), look2_binlxpw(rtu_x1[0], Estimations_U.temp6,
    rtCP_R1Table_bp01Data_l, rtCP_R1Table_bp02Data_g, rtCP_R1Table_tableData_m,
    rtCP_R1Table_maxIndex_a, 21UL), Estimations_U.Cq6, Estimations_U.current6,
                  rtb_Add);

  /* SignalConversion generated from: '<S61>/x1Next' incorporates:
   *  Product: '<S61>/Product'
   *  SignalConversion generated from: '<S61>/x1'
   *  Sum: '<S61>/Add'
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
