/*
 * File: batteryStateFcn3.c
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
#include "batteryStateFcn3.h"
#include "rt_sys_batteryStateFcn1_7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S3>/Simulink Function - State Transition Function1' */
void batteryStateFcn3(const real_T rtu_x1[3], real_T rty_x1Next[3])
{
  real_T rtb_Add[3];

  /* MATLAB Function: '<S31>/f(x,u)' incorporates:
   *  Inport: '<Root>/Cq3'
   *  Inport: '<Root>/current3'
   *  Inport: '<Root>/temp3'
   *  Lookup_n-D: '<S31>/C1 Table'
   *  Lookup_n-D: '<S31>/R1 Table'
   *  SignalConversion generated from: '<S31>/x1'
   */
  Estimations_fxu(rtu_x1, look2_binlxpw(rtu_x1[0], Estimations_U.temp3,
    rtCP_C1Table_bp01Data_o, rtCP_C1Table_bp02Data_lp, rtCP_C1Table_tableData_a,
    rtCP_C1Table_maxIndex_i, 21UL), look2_binlxpw(rtu_x1[0], Estimations_U.temp3,
    rtCP_R1Table_bp01Data_c, rtCP_R1Table_bp02Data_l, rtCP_R1Table_tableData_b,
    rtCP_R1Table_maxIndex_e, 21UL), Estimations_U.Cq3, Estimations_U.current3,
                  rtb_Add);

  /* SignalConversion generated from: '<S31>/x1Next' incorporates:
   *  Product: '<S31>/Product'
   *  SignalConversion generated from: '<S31>/x1'
   *  Sum: '<S31>/Add'
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
