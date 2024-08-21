/*
 * File: batteryMeasurementFcn8.c
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
#include "batteryMeasurementFcn8.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S8>/Simulink Function - Measurement Function1' */
real_T batteryMeasurementFcn8(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S80>/y1' incorporates:
   *  Inport: '<Root>/current8'
   *  Inport: '<Root>/temp8'
   *  Lookup_n-D: '<S80>/Em Table'
   *  Product: '<S80>/Product'
   *  SignalConversion generated from: '<S80>/x1'
   *  Sum: '<S80>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp8, rtCP_EmTable_bp01Data_g,
                        rtCP_EmTable_bp02Data_e, rtCP_EmTable_tableData_nv,
                        rtCP_EmTable_maxIndex_bp, 21UL) - rtu_x1[2] *
          Estimations_U.current8) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
