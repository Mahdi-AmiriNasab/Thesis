/*
 * File: batteryStateFcn5.c
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
#include "batteryStateFcn5.h"
#include "rt_sys_batteryStateFcn1_7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S5>/Simulink Function - State Transition Function1' */
void batteryStateFcn5(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_Add[3];

  /* MATLAB Function: '<S51>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq5'
   *  Inport: '<Root>/current5'
   *  Inport: '<Root>/temp5'
   *  Lookup_n-D: '<S51>/C1 Table'
   *  Lookup_n-D: '<S51>/R1 Table'
   *  SignalConversion generated from: '<S51>/x1'
   */
  Estimations_fxu(rtu_x1, look2_binlxpw(rtu_x1[0], Estimations_U.temp5,
    rtCP_C1Table_bp01Data_e, rtCP_C1Table_bp02Data_d, rtCP_C1Table_tableData_h,
    rtCP_C1Table_maxIndex_m, 21UL), look2_binlxpw(rtu_x1[0], Estimations_U.temp5,
    rtCP_R1Table_bp01Data_g, rtCP_R1Table_bp02Data_f, rtCP_R1Table_tableData_e0,
    rtCP_R1Table_maxIndex_g, 21UL), Estimations_U.Cq5, Estimations_U.current5,
                  rtb_Add);

  /* SignalConversion generated from: '<S51>/x1Next' incorporates:
   *  Product: '<S51>/Product'
   *  SignalConversion generated from: '<S51>/x1'
   *  Sum: '<S51>/Add'
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
