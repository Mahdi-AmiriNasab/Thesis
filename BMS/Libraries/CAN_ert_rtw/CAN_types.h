/*
 * File: CAN_types.h
 *
 * Code generated for Simulink model 'CAN'.
 *
 * Model version                  : 2.17
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb  7 16:22:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CAN_types_h_
#define RTW_HEADER_CAN_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint16_T Extended;
  uint16_T Length;
  uint16_T Remote;
  uint16_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint16_T Data[8];
} CAN_MESSAGE_BUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CAN_T RT_MODEL_CAN_T;

#endif                                 /* RTW_HEADER_CAN_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
