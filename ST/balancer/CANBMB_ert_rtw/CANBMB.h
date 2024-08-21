/*
 * File: CANBMB.h
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

#ifndef RTW_HEADER_CANBMB_h_
#define RTW_HEADER_CANBMB_h_
#ifndef CANBMB_COMMON_INCLUDES_
# define CANBMB_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* CANBMB_COMMON_INCLUDES_ */

#include "CANBMB_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T CANUnpack2_ModeSignalID;       /* '<Root>/CAN Unpack2' */
  int_T CANUnpack2_StatusPortID;       /* '<Root>/CAN Unpack2' */
  int_T CANUnpack3_ModeSignalID;       /* '<Root>/CAN Unpack3' */
  int_T CANUnpack3_StatusPortID;       /* '<Root>/CAN Unpack3' */
  int_T CANUnpack4_ModeSignalID;       /* '<Root>/CAN Unpack4' */
  int_T CANUnpack4_StatusPortID;       /* '<Root>/CAN Unpack4' */
  int_T CANUnpack5_ModeSignalID;       /* '<Root>/CAN Unpack5' */
  int_T CANUnpack5_StatusPortID;       /* '<Root>/CAN Unpack5' */
  int_T CANUnpack7_ModeSignalID;       /* '<Root>/CAN Unpack7' */
  int_T CANUnpack7_StatusPortID;       /* '<Root>/CAN Unpack7' */
  int_T CANUnpack6_ModeSignalID;       /* '<Root>/CAN Unpack6' */
  int_T CANUnpack6_StatusPortID;       /* '<Root>/CAN Unpack6' */
  int_T CANUnpack8_ModeSignalID;       /* '<Root>/CAN Unpack8' */
  int_T CANUnpack8_StatusPortID;       /* '<Root>/CAN Unpack8' */
  int_T CANUnpack10_ModeSignalID;      /* '<Root>/CAN Unpack10' */
  int_T CANUnpack10_StatusPortID;      /* '<Root>/CAN Unpack10' */
  int_T CANUnpack9_ModeSignalID;       /* '<Root>/CAN Unpack9' */
  int_T CANUnpack9_StatusPortID;       /* '<Root>/CAN Unpack9' */
  int_T CANUnpack12_ModeSignalID;      /* '<Root>/CAN Unpack12' */
  int_T CANUnpack12_StatusPortID;      /* '<Root>/CAN Unpack12' */
  int_T CANUnpack11_ModeSignalID;      /* '<Root>/CAN Unpack11' */
  int_T CANUnpack11_StatusPortID;      /* '<Root>/CAN Unpack11' */
  int_T CANUnpack13_ModeSignalID;      /* '<Root>/CAN Unpack13' */
  int_T CANUnpack13_StatusPortID;      /* '<Root>/CAN Unpack13' */
  int_T CANUnpack15_ModeSignalID;      /* '<Root>/CAN Unpack15' */
  int_T CANUnpack15_StatusPortID;      /* '<Root>/CAN Unpack15' */
  int_T CANUnpack14_ModeSignalID;      /* '<Root>/CAN Unpack14' */
  int_T CANUnpack14_StatusPortID;      /* '<Root>/CAN Unpack14' */
  int_T CANUnpack16_ModeSignalID;      /* '<Root>/CAN Unpack16' */
  int_T CANUnpack16_StatusPortID;      /* '<Root>/CAN Unpack16' */
  int_T CANUnpack18_ModeSignalID;      /* '<Root>/CAN Unpack18' */
  int_T CANUnpack18_StatusPortID;      /* '<Root>/CAN Unpack18' */
  int_T CANUnpack17_ModeSignalID;      /* '<Root>/CAN Unpack17' */
  int_T CANUnpack17_StatusPortID;      /* '<Root>/CAN Unpack17' */
  int_T CANUnpack19_ModeSignalID;      /* '<Root>/CAN Unpack19' */
  int_T CANUnpack19_StatusPortID;      /* '<Root>/CAN Unpack19' */
  int_T CANUnpack21_ModeSignalID;      /* '<Root>/CAN Unpack21' */
  int_T CANUnpack21_StatusPortID;      /* '<Root>/CAN Unpack21' */
  int_T CANUnpack20_ModeSignalID;      /* '<Root>/CAN Unpack20' */
  int_T CANUnpack20_StatusPortID;      /* '<Root>/CAN Unpack20' */
  int_T CANUnpack22_ModeSignalID;      /* '<Root>/CAN Unpack22' */
  int_T CANUnpack22_StatusPortID;      /* '<Root>/CAN Unpack22' */
  int_T CANUnpack24_ModeSignalID;      /* '<Root>/CAN Unpack24' */
  int_T CANUnpack24_StatusPortID;      /* '<Root>/CAN Unpack24' */
  int_T CANUnpack23_ModeSignalID;      /* '<Root>/CAN Unpack23' */
  int_T CANUnpack23_StatusPortID;      /* '<Root>/CAN Unpack23' */
  int_T CANUnpack25_ModeSignalID;      /* '<Root>/CAN Unpack25' */
  int_T CANUnpack25_StatusPortID;      /* '<Root>/CAN Unpack25' */
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
} DW_CANBMB_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CAN_MESSAGE_BUS m1_1;                /* '<Root>/m1_1' */
  CAN_MESSAGE_BUS m1_2;                /* '<Root>/m1_2' */
  CAN_MESSAGE_BUS m1_3;                /* '<Root>/m1_3' */
  CAN_MESSAGE_BUS m2_1;                /* '<Root>/m2_1' */
  CAN_MESSAGE_BUS m2_2;                /* '<Root>/m2_2' */
  CAN_MESSAGE_BUS m2_3;                /* '<Root>/m2_3' */
  CAN_MESSAGE_BUS m3_1;                /* '<Root>/m3_1' */
  CAN_MESSAGE_BUS m3_2;                /* '<Root>/m3_2' */
  CAN_MESSAGE_BUS m3_3;                /* '<Root>/m3_3' */
  CAN_MESSAGE_BUS m4_1;                /* '<Root>/m4_1' */
  CAN_MESSAGE_BUS m4_2;                /* '<Root>/m4_2' */
  CAN_MESSAGE_BUS m4_3;                /* '<Root>/m4_3' */
  CAN_MESSAGE_BUS m5_1;                /* '<Root>/m5_1' */
  CAN_MESSAGE_BUS m5_2;                /* '<Root>/m5_2' */
  CAN_MESSAGE_BUS m5_3;                /* '<Root>/m5_3' */
  CAN_MESSAGE_BUS m6_1;                /* '<Root>/m6_1' */
  CAN_MESSAGE_BUS m6_2;                /* '<Root>/m6_2' */
  CAN_MESSAGE_BUS m6_3;                /* '<Root>/m6_3' */
  CAN_MESSAGE_BUS m7_1;                /* '<Root>/m7_1' */
  CAN_MESSAGE_BUS m7_2;                /* '<Root>/m7_2' */
  CAN_MESSAGE_BUS m7_3;                /* '<Root>/m7_3' */
  CAN_MESSAGE_BUS m8_1;                /* '<Root>/m8_1' */
  CAN_MESSAGE_BUS m8_2;                /* '<Root>/m8_2' */
  CAN_MESSAGE_BUS m8_3;                /* '<Root>/m8_3' */
  uint16_T b1;                         /* '<Root>/b1' */
  uint16_T b2;                         /* '<Root>/b2' */
  uint16_T b3;                         /* '<Root>/b3' */
  uint16_T b4;                         /* '<Root>/b4' */
  uint16_T b5;                         /* '<Root>/b5' */
  uint16_T b6;                         /* '<Root>/b6' */
  uint16_T b7;                         /* '<Root>/b7' */
  uint16_T b8;                         /* '<Root>/b8' */
} ExtU_CANBMB_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T v1_1;                       /* '<Root>/v1_1' */
  uint16_T t1_1;                       /* '<Root>/t1_1' */
  uint16_T v1_2;                       /* '<Root>/v1_2' */
  uint16_T v1_3;                       /* '<Root>/v1_3' */
  uint16_T v1_4;                       /* '<Root>/v1_4' */
  uint16_T t1_2;                       /* '<Root>/t1_2' */
  uint16_T counter1;                   /* '<Root>/counter1' */
  uint16_T v1_5;                       /* '<Root>/v1_5' */
  uint16_T v1_6;                       /* '<Root>/v1_6' */
  uint16_T v1_7;                       /* '<Root>/v1_7' */
  uint16_T v1_8;                       /* '<Root>/v1_8' */
  uint16_T v1_9;                       /* '<Root>/v1_9' */
  uint16_T v1_10;                      /* '<Root>/v1_10' */
  uint16_T v1_11;                      /* '<Root>/v1_11' */
  uint16_T v1_12;                      /* '<Root>/v1_12' */
  uint16_T v2_1;                       /* '<Root>/v2_1' */
  uint16_T t2_1;                       /* '<Root>/t2_1' */
  uint16_T counter2;                   /* '<Root>/counter2' */
  uint16_T v2_2;                       /* '<Root>/v2_2' */
  uint16_T v2_3;                       /* '<Root>/v2_3' */
  uint16_T v2_4;                       /* '<Root>/v2_4' */
  uint16_T v2_5;                       /* '<Root>/v2_5' */
  uint16_T t2_2;                       /* '<Root>/t2_2' */
  uint16_T v2_6;                       /* '<Root>/v2_6' */
  uint16_T v2_7;                       /* '<Root>/v2_7' */
  uint16_T v2_8;                       /* '<Root>/v2_8' */
  uint16_T v2_9;                       /* '<Root>/v2_9' */
  uint16_T v2_10;                      /* '<Root>/v2_10' */
  uint16_T v2_11;                      /* '<Root>/v2_11' */
  uint16_T v2_12;                      /* '<Root>/v2_12' */
  uint16_T v3_1;                       /* '<Root>/v3_1' */
  uint16_T t3_1;                       /* '<Root>/t3_1' */
  uint16_T counter3;                   /* '<Root>/counter3' */
  uint16_T v3_2;                       /* '<Root>/v3_2' */
  uint16_T v3_3;                       /* '<Root>/v3_3' */
  uint16_T v3_4;                       /* '<Root>/v3_4' */
  uint16_T v3_5;                       /* '<Root>/v3_5' */
  uint16_T v3_6;                       /* '<Root>/v3_6' */
  uint16_T v3_7;                       /* '<Root>/v3_7' */
  uint16_T v3_8;                       /* '<Root>/v3_8' */
  uint16_T v3_10;                      /* '<Root>/v3_10' */
  uint16_T t3_2;                       /* '<Root>/t3_2' */
  uint16_T v3_9;                       /* '<Root>/v3_9' */
  uint16_T v3_11;                      /* '<Root>/v3_11' */
  uint16_T v3_12;                      /* '<Root>/v3_12' */
  uint16_T v4_1;                       /* '<Root>/v4_1' */
  uint16_T t4_1;                       /* '<Root>/t4_1' */
  uint16_T counter4;                   /* '<Root>/counter4' */
  uint16_T v4_2;                       /* '<Root>/v4_2' */
  uint16_T v4_3;                       /* '<Root>/v4_3' */
  uint16_T v4_4;                       /* '<Root>/v4_4' */
  uint16_T v4_5;                       /* '<Root>/v4_5' */
  uint16_T t4_2;                       /* '<Root>/t4_2' */
  uint16_T v4_6;                       /* '<Root>/v4_6' */
  uint16_T v4_7;                       /* '<Root>/v4_7' */
  uint16_T v4_8;                       /* '<Root>/v4_8' */
  uint16_T v4_9;                       /* '<Root>/v4_9' */
  uint16_T v4_10;                      /* '<Root>/v4_10' */
  uint16_T v4_11;                      /* '<Root>/v4_11' */
  uint16_T v4_12;                      /* '<Root>/v4_12' */
  uint16_T v5_1;                       /* '<Root>/v5_1' */
  uint16_T t5_1;                       /* '<Root>/t5_1' */
  uint16_T counter5;                   /* '<Root>/counter5' */
  uint16_T v5_2;                       /* '<Root>/v5_2' */
  uint16_T v5_3;                       /* '<Root>/v5_3' */
  uint16_T v5_4;                       /* '<Root>/v5_4' */
  uint16_T v5_5;                       /* '<Root>/v5_5' */
  uint16_T v5_6;                       /* '<Root>/v5_6' */
  uint16_T v5_7;                       /* '<Root>/v5_7' */
  uint16_T v5_8;                       /* '<Root>/v5_8' */
  uint16_T t5_2;                       /* '<Root>/t5_2' */
  uint16_T v5_9;                       /* '<Root>/v5_9' */
  uint16_T v5_10;                      /* '<Root>/v5_10' */
  uint16_T v5_11;                      /* '<Root>/v5_11' */
  uint16_T v5_12;                      /* '<Root>/v5_12' */
  uint16_T v6_1;                       /* '<Root>/v6_1' */
  uint16_T t6_1;                       /* '<Root>/t6_1' */
  uint16_T counter6;                   /* '<Root>/counter6' */
  uint16_T v6_2;                       /* '<Root>/v6_2' */
  uint16_T v6_3;                       /* '<Root>/v6_3' */
  uint16_T v6_4;                       /* '<Root>/v6_4' */
  uint16_T v6_5;                       /* '<Root>/v6_5' */
  uint16_T v6_6;                       /* '<Root>/v6_6' */
  uint16_T v6_7;                       /* '<Root>/v6_7' */
  uint16_T v6_8;                       /* '<Root>/v6_8' */
  uint16_T t6_2;                       /* '<Root>/t6_2' */
  uint16_T v6_9;                       /* '<Root>/v6_9' */
  uint16_T v6_10;                      /* '<Root>/v6_10' */
  uint16_T v6_11;                      /* '<Root>/v6_11' */
  uint16_T v6_12;                      /* '<Root>/v6_12' */
  uint16_T v7_1;                       /* '<Root>/v7_1' */
  uint16_T t7_1;                       /* '<Root>/t7_1' */
  uint16_T counter7;                   /* '<Root>/counter7' */
  uint16_T v7_2;                       /* '<Root>/v7_2' */
  uint16_T v7_3;                       /* '<Root>/v7_3' */
  uint16_T v7_4;                       /* '<Root>/v7_4' */
  uint16_T v7_5;                       /* '<Root>/v7_5' */
  uint16_T t7_2;                       /* '<Root>/t7_2' */
  uint16_T v7_6;                       /* '<Root>/v7_6' */
  uint16_T v7_7;                       /* '<Root>/v7_7' */
  uint16_T v7_8;                       /* '<Root>/v7_8' */
  uint16_T v7_9;                       /* '<Root>/v7_9' */
  uint16_T v7_10;                      /* '<Root>/v7_10' */
  uint16_T v7_11;                      /* '<Root>/v7_11' */
  uint16_T v7_12;                      /* '<Root>/v7_12' */
  uint16_T v8_1;                       /* '<Root>/v8_1' */
  uint16_T t8_1;                       /* '<Root>/t8_1' */
  uint16_T counter8;                   /* '<Root>/counter8' */
  uint16_T v8_2;                       /* '<Root>/v8_2' */
  uint16_T v8_3;                       /* '<Root>/v8_3' */
  uint16_T v8_4;                       /* '<Root>/v8_4' */
  uint16_T v8_5;                       /* '<Root>/v8_5' */
  uint16_T v8_6;                       /* '<Root>/v8_6' */
  uint16_T v8_7;                       /* '<Root>/v8_7' */
  uint16_T v8_8;                       /* '<Root>/v8_8' */
  uint16_T t8_2;                       /* '<Root>/t8_2' */
  uint16_T v8_9;                       /* '<Root>/v8_9' */
  uint16_T v8_10;                      /* '<Root>/v8_10' */
  uint16_T v8_11;                      /* '<Root>/v8_11' */
  uint16_T v8_12;                      /* '<Root>/v8_12' */
  CAN_MESSAGE_BUS balaner1;            /* '<Root>/balaner1' */
  CAN_MESSAGE_BUS balaner2;            /* '<Root>/balaner2' */
} ExtY_CANBMB_T;

/* Real-time Model Data Structure */
struct tag_RTM_CANBMB_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_CANBMB_T CANBMB_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CANBMB_T CANBMB_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CANBMB_T CANBMB_Y;

/* Model entry point functions */
extern void CANBMB_initialize(void);
extern void CANBMB_step(void);
extern void CANBMB_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CANBMB_T *const CANBMB_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CANBMB'
 */
#endif                                 /* RTW_HEADER_CANBMB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
