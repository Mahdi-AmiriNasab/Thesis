/*
 * File: batteryMeasurementFcn2.c
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
#include "batteryMeasurementFcn2.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S2>/Simulink Function - Measurement Function2' */
real_T batteryMeasurementFcn2(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S20>/y1' incorporates:
   *  Inport: '<Root>/current2'
   *  Inport: '<Root>/temp2'
   *  Lookup_n-D: '<S20>/Em Table'
   *  Product: '<S20>/Product'
   *  SignalConversion generated from: '<S20>/x1'
   *  Sum: '<S20>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp2, rtCP_EmTable_bp01Data_f,
                        rtCP_EmTable_bp02Data_b, rtCP_EmTable_tableData_k,
                        rtCP_EmTable_maxIndex_a, 21UL) - rtu_x1[2] *
          Estimations_U.current2) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
