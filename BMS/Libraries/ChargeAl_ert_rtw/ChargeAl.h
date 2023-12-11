/*
 * File: ChargeAl.h
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

#ifndef RTW_HEADER_ChargeAl_h_
#define RTW_HEADER_ChargeAl_h_
#ifndef ChargeAl_COMMON_INCLUDES_
#define ChargeAl_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#endif                                 /* ChargeAl_COMMON_INCLUDES_ */

#include "ChargeAl_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S6>/Subsystem' */
typedef struct {
  int_T BHMPack_ModeSignalID;          /* '<S10>/BHM Pack' */
} DW_Subsystem_ChargeAl_T;

/* Block states (default storage) for system '<S6>/Subsystem2' */
typedef struct {
  int_T CANPack9_ModeSignalID;         /* '<S13>/CAN Pack9' */
} DW_Subsystem2_ChargeAl_T;

/* Block signals (default storage) */
typedef struct {
  real_T EVReady;                      /* '<S7>/SAE J1772 DC Chargng (EV)' */
  real_T ConnLock;                     /* '<S7>/SAE J1772 DC Chargng (EV)' */
  real_T MaxCurr;                      /* '<S7>/SAE J1772 DC Chargng (EV)' */
  real32_T ProxVolt;                   /* '<S8>/SensorsEV' */
  EVState EVState_i;                   /* '<S7>/SAE J1772 DC Chargng (EV)' */
  boolean_T InfoHLC;                   /* '<S9>/ISO 15118 HLC (EVCC)' */
  boolean_T PwrCmdBMS;                 /* '<S9>/ISO 15118 HLC (EVCC)' */
} B_ChargeAl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay4_2_DSTATE;          /* '<S7>/Unit Delay4' */
  real_T UnitDelay4_1_DSTATE;          /* '<S7>/Unit Delay4' */
  real_T EnHLC1;                       /* '<S7>/SAE J1772 DC Chargng (EV)' */
  real32_T V2G_EVCC_Msg_Timeout_PreChargeR;/* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T exitPortIndex;              /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T exitPortIndex_a;            /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T exitPortIndex_p;            /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T exitPortIndex_l;            /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T exitPortIndex_i;            /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T temporalCounter_i1;         /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint32_T temporalCounter_i1_h;       /* '<S7>/SAE J1772 DC Chargng (EV)' */
  uint32_T durationCounter_1;          /* '<S7>/SAE J1772 DC Chargng (EV)' */
  uint32_T durationCounter_1_d;        /* '<S7>/SAE J1772 DC Chargng (EV)' */
  uint16_T temporalCounter_i2;         /* '<S9>/ISO 15118 HLC (EVCC)' */
  boolean_T UnitDelay1_DSTATE;         /* '<S9>/Unit Delay1' */
  uint16_T is_active_c3_ChargeAl;      /* '<S4>/Chart' */
  uint16_T temporalCounter_i1_l;       /* '<S4>/Chart' */
  uint16_T is_active_c11_ChargeAl;     /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_c11_ChargeAl;            /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_error_handling;          /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_loop_Charge_control;     /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_seq_Communication_Setup; /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_seq_End_of_charging_process;/* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_seq_Target_Setting_and_Charg;/* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T temporalCounter_i3;         /* '<S9>/ISO 15118 HLC (EVCC)' */
  uint16_T is_active_c6_ChargeAl;      /* '<S7>/SAE J1772 DC Chargng (EV)' */
  DW_Subsystem2_ChargeAl_T Subsystem2; /* '<S6>/Subsystem2' */
  DW_Subsystem_ChargeAl_T Subsystem;   /* '<S6>/Subsystem' */
} DW_ChargeAl_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T BattSoc;              /* '<S5>/Gain' */
  const boolean_T ChargingComplete;    /* '<S5>/Less Than' */
} ConstB_ChargeAl_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: 5000
   * Referenced by: '<S10>/Constant2'
   */
  real_T Constant2_Value;
} ConstP_ChargeAl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CAN_Input CAN_Input_d;               /* '<Root>/CAN_Input' */
} ExtU_ChargeAl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ContCmd;                      /* '<Root>/ContCmd' */
  real_T ConnLock1;                    /* '<Root>/ConnLock1' */
  real32_T ChargerBattCurrent;         /* '<Root>/ChargerBattCurrent' */
  CAN_MESSAGE_BUS BHM_l;               /* '<Root>/BHM' */
  CAN_MESSAGE_BUS BRM_k;               /* '<Root>/BRM' */
  CAN_Output CAN_Output_p;             /* '<Root>/CAN_Output' */
  State_ModeType State_Mode;           /* '<Root>/State_Mode' */
  real_T Second;                       /* '<Root>/Second' */
} ExtY_ChargeAl_T;

/* Real-time Model Data Structure */
struct tag_RTM_ChargeAl_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_ChargeAl_T ChargeAl_B;

/* Block states (default storage) */
extern DW_ChargeAl_T ChargeAl_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ChargeAl_T ChargeAl_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ChargeAl_T ChargeAl_Y;
extern const ConstB_ChargeAl_T ChargeAl_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_ChargeAl_T ChargeAl_ConstP;

/* Model entry point functions */
extern void ChargeAl_initialize(void);
extern void ChargeAl_step(void);
extern void ChargeAl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ChargeAl_T *const ChargeAl_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ConnLock' : Unused code path elimination
 * Block '<S5>/Abs' : Unused code path elimination
 * Block '<S5>/ChrgModeSoc' : Unused code path elimination
 * Block '<S5>/ChrgVoltMax' : Unused code path elimination
 * Block '<S5>/Display' : Unused code path elimination
 * Block '<S5>/Display1' : Unused code path elimination
 * Block '<S5>/Display2' : Unused code path elimination
 * Block '<S5>/Display3' : Unused code path elimination
 * Block '<S5>/Display4' : Unused code path elimination
 * Block '<S5>/FloatChrg' : Unused code path elimination
 * Block '<S5>/Less Than1' : Unused code path elimination
 * Block '<S5>/Min' : Unused code path elimination
 * Block '<S5>/OR' : Unused code path elimination
 * Block '<S5>/Relay' : Unused code path elimination
 * Block '<S5>/Sum' : Unused code path elimination
 * Block '<S5>/Switch' : Unused code path elimination
 * Block '<S11>/CAN Pack1' : Unused code path elimination
 * Block '<S11>/CAN Unpack' : Unused code path elimination
 * Block '<S11>/Data Type Conversion1' : Unused code path elimination
 * Block '<S12>/CAN Pack2' : Unused code path elimination
 * Block '<S12>/CAN Unpack1' : Unused code path elimination
 * Block '<S12>/Data Type Conversion2' : Unused code path elimination
 * Block '<S15>/Display' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display3' : Unused code path elimination
 * Block '<S9>/Display' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Second1gh' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<Root>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch10' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch11' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch3' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch4' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch7' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch8' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch9' : Eliminated due to constant selection input
 * Block '<Root>/AC charging' : Unused code path elimination
 * Block '<Root>/CANFaultTimeout' : Unused code path elimination
 * Block '<Root>/EV not ready' : Unused code path elimination
 * Block '<Root>/EVSE not ready' : Unused code path elimination
 * Block '<Root>/Emergency Stop' : Unused code path elimination
 * Block '<Root>/Latch held open' : Unused code path elimination
 * Block '<Root>/StopButton' : Unused code path elimination
 * Block '<Root>/Unplugged' : Unused code path elimination
 * Block '<Root>/Utility Power OFF' : Unused code path elimination
 */

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
 * '<Root>' : 'ChargeAl'
 * '<S1>'   : 'ChargeAl/Controllers'
 * '<S2>'   : 'ChargeAl/Subsystem'
 * '<S3>'   : 'ChargeAl/Subsystem1'
 * '<S4>'   : 'ChargeAl/Subsystem2'
 * '<S5>'   : 'ChargeAl/Controllers/BMS Charge Module'
 * '<S6>'   : 'ChargeAl/Controllers/CAN'
 * '<S7>'   : 'ChargeAl/Controllers/Charge Control Module'
 * '<S8>'   : 'ChargeAl/Controllers/Charge Coupler and Sensors'
 * '<S9>'   : 'ChargeAl/Controllers/EVCC(Electric Vehicle Communication Controller)'
 * '<S10>'  : 'ChargeAl/Controllers/CAN/Subsystem'
 * '<S11>'  : 'ChargeAl/Controllers/CAN/Subsystem11'
 * '<S12>'  : 'ChargeAl/Controllers/CAN/Subsystem12'
 * '<S13>'  : 'ChargeAl/Controllers/CAN/Subsystem2'
 * '<S14>'  : 'ChargeAl/Controllers/Charge Control Module/SAE J1772 DC Chargng (EV)'
 * '<S15>'  : 'ChargeAl/Controllers/Charge Control Module/SAE J1772 DC Chargng (EV)/pwm_update'
 * '<S16>'  : 'ChargeAl/Controllers/Charge Control Module/SAE J1772 DC Chargng (EV)/pwm_update/Compare To Constant'
 * '<S17>'  : 'ChargeAl/Controllers/Charge Control Module/SAE J1772 DC Chargng (EV)/pwm_update/Compare To Constant1'
 * '<S18>'  : 'ChargeAl/Controllers/Charge Control Module/SAE J1772 DC Chargng (EV)/pwm_update/Compare To Constant2'
 * '<S19>'  : 'ChargeAl/Controllers/Charge Coupler and Sensors/DC Connector Lock'
 * '<S20>'  : 'ChargeAl/Controllers/Charge Coupler and Sensors/SensorsEV'
 * '<S21>'  : 'ChargeAl/Controllers/EVCC(Electric Vehicle Communication Controller)/BMS Current'
 * '<S22>'  : 'ChargeAl/Controllers/EVCC(Electric Vehicle Communication Controller)/ISO 15118 HLC (EVCC)'
 * '<S23>'  : 'ChargeAl/Subsystem2/Chart'
 */
#endif                                 /* RTW_HEADER_ChargeAl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
