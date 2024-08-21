/*
 * File: batteryMeasurementFcn5.c
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
#include "batteryMeasurementFcn5.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S5>/Simulink Function - Measurement Function1' */
real_T batteryMeasurementFcn5(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S50>/y1' incorporates:
   *  Inport: '<Root>/current5'
   *  Inport: '<Root>/temp5'
   *  Lookup_n-D: '<S50>/Em Table'
   *  Product: '<S50>/Product'
   *  SignalConversion generated from: '<S50>/x1'
   *  Sum: '<S50>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp5, rtCP_EmTable_bp01Data_d,
                        rtCP_EmTable_bp02Data_m, rtCP_EmTable_tableData_kd,
                        rtCP_EmTable_maxIndex_p, 21UL) - rtu_x1[2] *
          Estimations_U.current5) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
