/*
 * File: CANBMB_types.h
 *
 * Code generated for Simulink model 'CANBMB'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jan 23 14:03:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->PIC18
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CANBMB_types_h_
#define RTW_HEADER_CANBMB_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CANBMB_T RT_MODEL_CANBMB_T;

#endif                                 /* RTW_HEADER_CANBMB_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
