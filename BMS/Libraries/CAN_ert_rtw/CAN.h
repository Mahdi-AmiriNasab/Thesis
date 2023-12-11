/*
 * File: CAN.h
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

#ifndef RTW_HEADER_CAN_h_
#define RTW_HEADER_CAN_h_
#ifndef CAN_COMMON_INCLUDES_
#define CAN_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* CAN_COMMON_INCLUDES_ */

#include "CAN_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T CANPack_ModeSignalID;          /* '<Root>/CAN Pack' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
  int_T CANPack2_ModeSignalID;         /* '<Root>/CAN Pack2' */
  int_T CANPack3_ModeSignalID;         /* '<Root>/CAN Pack3' */
  int_T CANPack4_ModeSignalID;         /* '<Root>/CAN Pack4' */
  int_T CANPack5_ModeSignalID;         /* '<Root>/CAN Pack5' */
  int_T CANPack6_ModeSignalID;         /* '<Root>/CAN Pack6' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANPack7_ModeSignalID;         /* '<Root>/CAN Pack7' */
  int_T CANPack8_ModeSignalID;         /* '<Root>/CAN Pack8' */
  int_T CANPack9_ModeSignalID;         /* '<Root>/CAN Pack9' */
} DW_CAN_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CAN_MESSAGE_BUS In1;                 /* '<Root>/In1' */
  real_T Max_Cell_Temp;                /* '<Root>/Max_Cell_Temp' */
  real_T Min_Cell_Temp1;               /* '<Root>/Min_Cell_Temp1' */
  real_T Max_Cell_Volt;                /* '<Root>/Max_Cell_Volt' */
  real_T Min_Cell_Volt1;               /* '<Root>/Min_Cell_Volt1' */
  real_T DC_Link_Volt;                 /* '<Root>/DC_Link_Volt' */
  real_T Pack_Current;                 /* '<Root>/Pack_Current' */
  real_T SOC;                          /* '<Root>/SOC' */
  real_T SOH;                          /* '<Root>/SOH' */
  real_T Discharge_Current_Limit;      /* '<Root>/Discharge_Current_Limit' */
  real_T Charge_Current_Limit;         /* '<Root>/Charge_Current_Limit' */
  real_T Charge_Voltage_Limit;         /* '<Root>/Charge_Voltage_Limit' */
  real_T Mileage;                      /* '<Root>/Mileage' */
  real_T Charge_Remaining_Time;        /* '<Root>/Charge_Remaining_Time' */
  boolean_T BMBFault;                  /* '<Root>/BMBFault' */
  boolean_T Bal_En;                    /* '<Root>/Bal_En' */
  boolean_T Charger;                   /* '<Root>/Charger' */
  boolean_T CurrentSensor;             /* '<Root>/CurrentSensor' */
  boolean_T HighTemp;                  /* '<Root>/HighTemp' */
  boolean_T InputPowerFault;           /* '<Root>/InputPowerFault' */
  boolean_T Inverter;                  /* '<Root>/Inverter' */
  boolean_T LowTemp;                   /* '<Root>/LowTemp' */
  boolean_T MemoryFault;               /* '<Root>/MemoryFault' */
  boolean_T OverChargeCurrent;         /* '<Root>/OverChargeCurrent' */
  boolean_T OverCurrent;               /* '<Root>/OverCurrent' */
  boolean_T OverDischargeCurrent;      /* '<Root>/OverDischargeCurrent' */
  boolean_T OverVolt;                  /* '<Root>/OverVolt' */
  boolean_T PreChargeFault;            /* '<Root>/PreChargeFault' */
  boolean_T ShortCircuitFault;         /* '<Root>/ShortCircuitFault' */
  boolean_T TempSensor;                /* '<Root>/TempSensor' */
  boolean_T UnderVoltage;              /* '<Root>/UnderVoltage' */
  boolean_T VoltSensor;                /* '<Root>/VoltSensor' */
  real_T Input_Voltage;                /* '<Root>/Input_Voltage' */
  uint16_T maxVoltageIndex;            /* '<Root>/maxVoltageIndex' */
  boolean_T Communication_Fault;       /* '<Root>/Communication_Fault' */
  real_T Disharge_Remaining_Time;      /* '<Root>/Disharge_Remaining_Time' */
  uint16_T State;                      /* '<Root>/State' */
  uint16_T Contactor_State;            /* '<Root>/Contactor_State' */
  uint16_T BMS_DI;                     /* '<Root>/BMS_DI' */
  uint16_T Charge_Complete;            /* '<Root>/Charge_Complete' */
  uint16_T Bal_Complete;               /* '<Root>/Bal_Complete' */
  uint16_T minVoltageIndex;            /* '<Root>/minVoltageIndex' */
  uint16_T maxTempIndex;               /* '<Root>/maxTempIndex' */
  uint16_T minTempIndex;               /* '<Root>/minTempIndex' */
  uint16_T test1;                      /* '<Root>/test1' */
  uint16_T test2;                      /* '<Root>/test2' */
  uint16_T test3;                      /* '<Root>/test3' */
  uint16_T test4;                      /* '<Root>/test4' */
  real32_T kwh;                        /* '<Root>/kwh' */
  real32_T signal;                     /* '<Root>/signal' */
  real32_T kwh_noFilter;               /* '<Root>/kwh_noFilter' */
  real_T BMBQualityCounter;            /* '<Root>/BMBQualityCounter' */
  real_T balanceCounter;               /* '<Root>/balanceCounter' */
  real_T t1;                           /* '<Root>/t1' */
  real_T t2;                           /* '<Root>/t2' */
  real_T t3;                           /* '<Root>/t3' */
  real_T t4;                           /* '<Root>/t4' */
  real_T t5;                           /* '<Root>/t5' */
  real_T t6;                           /* '<Root>/t6' */
  real_T t7;                           /* '<Root>/t7' */
  real_T t8;                           /* '<Root>/t8' */
  real_T t9;                           /* '<Root>/t9' */
  real_T t10;                          /* '<Root>/t10' */
  real_T t11;                          /* '<Root>/t11' */
  real_T t12;                          /* '<Root>/t12' */
  real_T PackVoltageSensor;            /* '<Root>/PackVoltageSensor' */
  real_T PackVoltageSum;               /* '<Root>/PackVoltageSum' */
} ExtU_CAN_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  CAN_MESSAGE_BUS Measurement1;        /* '<Root>/Measurement1' */
  CAN_MESSAGE_BUS Measurement2;        /* '<Root>/Measurement2' */
  CAN_MESSAGE_BUS Estimation1;         /* '<Root>/Estimation1' */
  CAN_MESSAGE_BUS Estimation2;         /* '<Root>/Estimation2' */
  CAN_MESSAGE_BUS Fault;               /* '<Root>/Fault' */
  CAN_MESSAGE_BUS Diagnosis;           /* '<Root>/Diagnosis' */
  CAN_MESSAGE_BUS Status;              /* '<Root>/Status' */
  uint16_T BMS_State;                  /* '<Root>/BMS_State' */
  uint16_T Fault_Reset;                /* '<Root>/Fault_Reset' */
  uint16_T Charge_Mode;                /* '<Root>/Charge_Mode' */
  uint16_T SOC_Max;                    /* '<Root>/SOC_Max' */
  CAN_MESSAGE_BUS THC1;                /* '<Root>/THC1' */
  CAN_MESSAGE_BUS THC2;                /* '<Root>/THC2' */
  CAN_MESSAGE_BUS THC3;                /* '<Root>/THC3' */
} ExtY_CAN_T;

/* Real-time Model Data Structure */
struct tag_RTM_CAN_T {
  const char_T * volatile errorStatus;
};

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
