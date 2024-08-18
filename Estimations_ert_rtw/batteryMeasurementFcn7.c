/*
 * File: batteryMeasurementFcn7.c
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
#include "batteryMeasurementFcn7.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S7>/Simulink Function - Measurement Function1' */
real_T batteryMeasurementFcn7(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S70>/y1' incorporates:
   *  Inport: '<Root>/current7'
   *  Inport: '<Root>/temp7'
   *  Lookup_n-D: '<S70>/Em Table'
   *  Product: '<S70>/Product'
   *  SignalConversion generated from: '<S70>/x1'
   *  Sum: '<S70>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp7, rtCP_EmTable_bp01Data_dx,
                        rtCP_EmTable_bp02Data_kv, rtCP_EmTable_tableData_p,
                        rtCP_EmTable_maxIndex_b, 21UL) - rtu_x1[2] *
          Estimations_U.current7) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
