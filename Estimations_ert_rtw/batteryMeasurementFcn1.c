/*
 * File: batteryMeasurementFcn1.c
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
#include "batteryMeasurementFcn1.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S1>/Simulink Function - Measurement Function1' */
real_T batteryMeasurementFcn1(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S10>/y' incorporates:
   *  Inport: '<Root>/current1'
   *  Inport: '<Root>/temp1'
   *  Lookup_n-D: '<S10>/Em Table'
   *  Product: '<S10>/Product'
   *  SignalConversion generated from: '<S10>/x'
   *  Sum: '<S10>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp1, rtCP_EmTable_bp01Data,
                        rtCP_EmTable_bp02Data, rtCP_EmTable_tableData,
                        rtCP_EmTable_maxIndex, 21UL) - rtu_x1[2] *
          Estimations_U.current1) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
