/*
 * File: ChargeAl_private.h
 *
 * Code generated for Simulink model 'ChargeAl'.
 *
 * Model version                  : 3.44
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Mon Sep 11 10:40:27 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ChargeAl_private_h_
#define RTW_HEADER_ChargeAl_private_h_
#include "rtwtypes.h"
#include "ChargeAl_types.h"
#include "ChargeAl.h"

extern void ChargeAl_pwm_update(real_T rtu_DutyCycle, real32_T *rty_I_max);
extern void ChargeAl_Subsystem(CAN_MESSAGE_BUS *rty_BHM);
extern void ChargeAl_Subsystem2(uint16_T rtu_CR_Plc_VersionMinor, uint16_T
  rtu_CR_Plc_VersionMajorH, uint16_T rtu_CR_Plc_BatteryType, uint16_T
  rtu_CR_Plc_EvEnergyCapacity, uint16_T rtu_CR_Plc_VersionMajorL, uint16_T
  rtu_CR_Plc_EvmaxVolt, CAN_MESSAGE_BUS *rty_BRM);

#endif                                 /* RTW_HEADER_ChargeAl_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
