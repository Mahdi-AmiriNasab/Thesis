/*
 * File: batteryMeasurementFcn1.c
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

#include "batteryMeasurementFcn1.h"

/* Include model header file for global data */
#include "Estimations.h"
#include "Estimations_private.h"
#include "look2_binlxpw.h"

/* Output and update for Simulink Function: '<Root>/Simulink Function - Measurement Function1' */
real_T batteryMeasurementFcn1(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S1>/y' incorporates:
   *  Inport: '<Root>/current'
   *  Inport: '<Root>/temp'
   *  Lookup_n-D: '<S1>/Em Table'
   *  Product: '<S1>/Product'
   *  SignalConversion generated from: '<S1>/x'
   *  Sum: '<S1>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp, rtCP_EmTable_bp01Data,
                        rtCP_EmTable_bp02Data, rtCP_EmTable_tableData,
                        rtCP_EmTable_maxIndex, 21UL) - rtu_x1[2] *
          Estimations_U.current) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
