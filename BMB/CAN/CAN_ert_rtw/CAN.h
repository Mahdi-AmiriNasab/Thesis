/*
 * File: CAN.h
 *
 * Code generated for Simulink model 'CAN'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 10 13:24:14 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Microchip->PIC18
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CAN_h_
#define RTW_HEADER_CAN_h_
#ifndef CAN_COMMON_INCLUDES_
# define CAN_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* CAN_COMMON_INCLUDES_ */

#include "CAN_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T Divide;                     /* '<Root>/Divide' */
  uint16_T Divide1;                    /* '<Root>/Divide1' */
  uint16_T Divide2;                    /* '<Root>/Divide2' */
  uint16_T Divide3;                    /* '<Root>/Divide3' */
  uint16_T Divide12;                   /* '<Root>/Divide12' */
  uint16_T Divide4;                    /* '<Root>/Divide4' */
  uint16_T Divide5;                    /* '<Root>/Divide5' */
  uint16_T Divide6;                    /* '<Root>/Divide6' */
  uint16_T Divide7;                    /* '<Root>/Divide7' */
  uint16_T Divide13;                   /* '<Root>/Divide13' */
  uint16_T Divide8;                    /* '<Root>/Divide8' */
  uint16_T Divide9;                    /* '<Root>/Divide9' */
  uint16_T Divide10;                   /* '<Root>/Divide10' */
  uint16_T Divide11;                   /* '<Root>/Divide11' */
} B_CAN_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
  int_T CANPack2_ModeSignalID;         /* '<Root>/CAN Pack2' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<Root>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<Root>/CAN Unpack1' */
} DW_CAN_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T v1;                         /* '<Root>/v1' */
  uint16_T v2;                         /* '<Root>/v2' */
  uint16_T v3;                         /* '<Root>/v3' */
  uint16_T v4;                         /* '<Root>/v4' */
  uint16_T v5;                         /* '<Root>/v5' */
  uint16_T v6;                         /* '<Root>/v6' */
  uint16_T v7;                         /* '<Root>/v7' */
  uint16_T v8;                         /* '<Root>/v8' */
  uint16_T v9;                         /* '<Root>/v9' */
  uint16_T v10;                        /* '<Root>/v10' */
  uint16_T v11;                        /* '<Root>/v11' */
  uint16_T v12;                        /* '<Root>/v12' */
  uint16_T t1;                         /* '<Root>/t1' */
  uint16_T t2;                         /* '<Root>/t2' */
  uint16_T counter;                    /* '<Root>/counter' */
  CAN_MESSAGE_BUS balance2;            /* '<Root>/balance2' */
  CAN_MESSAGE_BUS balance1;            /* '<Root>/balance1' */
} ExtU_CAN_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  CAN_MESSAGE_BUS Voltage1;            /* '<Root>/Voltage1' */
  CAN_MESSAGE_BUS Voltage2;            /* '<Root>/Voltage2' */
  CAN_MESSAGE_BUS Voltage3;            /* '<Root>/Voltage3' */
  uint16_T b1;                         /* '<Root>/b1' */
  uint16_T b2;                         /* '<Root>/b2' */
  uint16_T b3;                         /* '<Root>/b3' */
  uint16_T b4;                         /* '<Root>/b4' */
  uint16_T b5;                         /* '<Root>/b5' */
  uint16_T b6;                         /* '<Root>/b6' */
  uint16_T b7;                         /* '<Root>/b7' */
  uint16_T b8;                         /* '<Root>/b8' */
} ExtY_CAN_T;

/* Real-time Model Data Structure */
struct tag_RTM_CAN_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_CAN_T CAN_B;

/* Block states (default storage) */
extern DW_CAN_T CAN_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CAN_T CAN_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CAN_T CAN_Y;

/* Model entry point functions */
extern void CAN_initialize(void);
extern void CAN_step(void);
extern void CAN_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CAN_T *const CAN_M;

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
 * '<Root>' : 'CAN'
 */
#endif                                 /* RTW_HEADER_CAN_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
