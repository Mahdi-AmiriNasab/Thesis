/*
 * File: batteryMeasurementFcn9.c
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
#include "batteryMeasurementFcn9.h"
#include "Estimations.h"
#include "look2_binlxpw.h"
#include "Estimations_private.h"

/* Output and update for Simulink Function: '<S9>/Simulink Function - Measurement Function1' */
real_T batteryMeasurementFcn9(const real_T rtu_x1[3])
{
  /* SignalConversion generated from: '<S90>/y1' incorporates:
   *  Inport: '<Root>/current9'
   *  Inport: '<Root>/temp9'
   *  Lookup_n-D: '<S90>/Em Table'
   *  Product: '<S90>/Product'
   *  SignalConversion generated from: '<S90>/x1'
   *  Sum: '<S90>/Add1'
   */
  return (look2_binlxpw(rtu_x1[0], Estimations_U.temp9, rtCP_EmTable_bp01Data_fy,
                        rtCP_EmTable_bp02Data_l, rtCP_EmTable_tableData_nm,
                        rtCP_EmTable_maxIndex_f, 21UL) - rtu_x1[2] *
          Estimations_U.current9) - rtu_x1[1];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
