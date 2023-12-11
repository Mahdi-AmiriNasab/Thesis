/*
 * File: ChargeAl_types.h
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

#ifndef RTW_HEADER_ChargeAl_types_h_
#define RTW_HEADER_ChargeAl_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SIF_
#define DEFINED_TYPEDEF_FOR_SIF_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CF_Secc_S2_OnReq;
  real32_T CF_Secc_S2Sts;
  real32_T CF_Lock_status;
  real32_T CF_CP_Stat;
  real32_T CF_Lock_Alarm;
  real32_T CR_Secc_IsolationStatus;
  real32_T CR_Evcc_PDStat;
  real32_T CR_Secc_AC_MaxCurrent;
  real32_T CF_Secc_DCAC_ChgMode;
  real32_T CR_Secc_EvseOutVolt;
  real32_T CR_Secc_EVSEMaxPowerLimit;
} SIF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CHM_
#define DEFINED_TYPEDEF_FOR_CHM_

typedef struct {
  real32_T CR_Secc_VersionMinor;
  real32_T CR_Secc_VersionMajorL;
  real32_T CR_Secc_VersionMajorH;
  boolean_T Flag;
  uint16_T Data[8];
} CHM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CRM_
#define DEFINED_TYPEDEF_FOR_CRM_

typedef struct {
  boolean_T Flag;
  real32_T CR_Secc_RecognitionResult;
  uint16_T Data[8];
} CRM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CML_
#define DEFINED_TYPEDEF_FOR_CML_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CR_Secc_EvseMaxVolt_V;
  real32_T CR_Secc_EvseMinVolt_V;
  real32_T CR_Secc_EvseMaxCurr_A;
  real32_T CR_Secc_EvseMinCurr_A;
} CML;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CTS_
#define DEFINED_TYPEDEF_FOR_CTS_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
} CTS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CRO_
#define DEFINED_TYPEDEF_FOR_CRO_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CR_Secc_ContactorOn;
  real32_T CR_IsolationStatus;
} CRO;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CCS_
#define DEFINED_TYPEDEF_FOR_CCS_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CR_Secc_EvseOutVolt;
  real32_T CR_Secc_EvseOutCurrent;
  real32_T CR_Secc_MaxPowerLimit;
  real32_T CF_Secc_EvseSuspended;
  real32_T CR_Secc_IsolationStatus;
  real32_T CR_Secc_EvseMaxCurr_IsUse;
  real32_T CR_Secc_EvseMaxCurr_A;
} CCS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CST_
#define DEFINED_TYPEDEF_FOR_CST_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CF_Secc_Suspended;
  real32_T CF_Secc_ArtificialSuspend;
  real32_T CF_Secc_FaultSpended;
  real32_T CF_Secc_BmsSuspended;
  real32_T CF_Secc_OverTemp;
  real32_T CF_Secc_ConnectorFail;
  real32_T CF_Secc_InternelOverTemp;
  real32_T CF_Secc_RequestReject;
  real32_T CF_Secc_SuddenStop;
  real32_T CF_Secc_OtherFault;
  real32_T CF_Secc_CurrentMismatch;
  real32_T CF_Secc_VoltAbnormal;
  real32_T CR_IsolationStatus;
} CST;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CSD_
#define DEFINED_TYPEDEF_FOR_CSD_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
} CSD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAN_Input_
#define DEFINED_TYPEDEF_FOR_CAN_Input_

typedef struct {
  SIF SIF;
  CHM CHM;
  CRM CRM;
  CML CML;
  CTS CTS;
  CRO CRO;
  CCS CCS;
  CST CST;
  CSD CSD;
} CAN_Input;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_EVState_
#define DEFINED_TYPEDEF_FOR_EVState_

typedef enum {
  EVState_None = 0,                    /* Default value */
  EVState_State_A,
  EVState_State_B1,
  EVState_State_B2,
  EVState_State_C1,
  EVState_State_C2,
  EVState_State_F,
  EVState_UnlockState_F,
  EVState_DefineTheTimeOutValue,
  EVState_State_C3,
  EVState_State_E,
  EVState_UnlockState_E,
  EVState_State_C
} EVState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMS_
#define DEFINED_TYPEDEF_FOR_BMS_

typedef struct {
  real32_T RCT;
  real32_T ChargeCurrentReq;
  real32_T Fake_SOC;
  real32_T SumOfVoltages;
  real32_T ChargeVoltReq;
  real32_T Pack_Current;
  real32_T MaxCellVolt;
  real32_T MinCellTemp;
  real32_T MaxCellTemp;
  real32_T Fault_out_HighTemp;
} BMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BHM_
#define DEFINED_TYPEDEF_FOR_BHM_

typedef struct {
  real32_T CR_Plc_EvPermissibleMaxVolt;
  real32_T CR_Plc_EvmaxCurrent;
  real32_T CF_Plc_Bhm8Bytes;
  real32_T CR_Plc_EvRessSOC;
  real32_T CR_Plc_FullSOC;
  real32_T CR_Plc_BulkSOC;
  boolean_T Flag;
  uint16_T Data[8];
} BHM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BRM_
#define DEFINED_TYPEDEF_FOR_BRM_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  boolean_T CR_Plc_VersionMinor;
  boolean_T CR_Plc_VersionMajorL;
  boolean_T CR_Plc_VersionMajorH;
  boolean_T CR_Plc_BatteryType;
  boolean_T CR_Plc_EvEnergyCapacity;
  boolean_T CR_Plc_EvmaxVolt;
} BRM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BCP_
#define DEFINED_TYPEDEF_FOR_BCP_

typedef struct {
  real32_T CR_Plc_MaxVoltSingleBattery;
  real32_T CR_Plc_EvmaxCurrent;
  real32_T CR_Plc_EvNormialEnergy;
  real32_T CR_Plc_EvmaxVolt;
  real32_T CR_Plc_EvAvailableTemp;
  real32_T CR_Plc_EvRessSOC;
  real32_T CR_Plc_EvCurrentVolt;
  boolean_T Flag;
  uint16_T Data[8];
} BCP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BRO_
#define DEFINED_TYPEDEF_FOR_BRO_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CF_Plc_PowerDeliveryStart;
} BRO;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BCS_
#define DEFINED_TYPEDEF_FOR_BCS_

typedef struct {
  real32_T CR_Plc_SensingVolt;
  real32_T CR_Plc_SensingCurrent;
  real32_T CR_Plc_HighestVoltSingle;
  real32_T CR_Plc_EvRessSOC;
  real32_T CR_Plc_FullSOCRemainedTime;
  boolean_T Flag;
  uint16_T Data[8];
} BCS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BSM_
#define DEFINED_TYPEDEF_FOR_BSM_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CR_Plc_SernumSinglePower;
  real32_T CR_Plc_HighestTemp;
  real32_T CR_Plc_SernumHighTemp;
  real32_T CR_Plc_LowestTemp;
  real32_T CR_Plc_SernumLowTemp;
  real32_T CF_Plc_OverlowVolSinglePowe;
  real32_T CF_Plc_OverlowSocBat;
  real32_T CF_Plc_OverCurr;
  real32_T CF_Plc_ExcexxTemp;
  real32_T CF_Plc_InsulState;
  real32_T CF_Plc_ConnectionState;
  real32_T CF_Plc_EvReady;
} BSM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BST_
#define DEFINED_TYPEDEF_FOR_BST_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CF_Plc_ReachSoC;
  real32_T CF_Plc_ReachTotalVolt;
  real32_T CF_Plc_ReachSingleVolt;
  real32_T CF_Plc_ChargerSuspend;
  real32_T CF_Plc_InstationFault;
  real32_T CF_Plc_ConnectorHighTemp;
  real32_T CF_Plc_BmsOverTemp;
  real32_T CF_Plc_ConnectorFault;
  real32_T CF_Plc_BatOverTemp;
  real32_T CF_Plc_HighVoltRelay;
  real32_T CF_Plc_ErrCheckPoint2;
  real32_T CF_Plc_OtherFault;
  real32_T CF_Plc_CurrOver;
  real32_T CF_Plc_AbnormalVolt;
} BST;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BSD_
#define DEFINED_TYPEDEF_FOR_BSD_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  real32_T CR_Plc_SuspendSoc;
  real32_T CR_MinVoltSinglePower;
  real32_T CR_MaxVoltSinglePower;
  real32_T CR_MinTempPower;
  real32_T CR_MaxTempPower;
} BSD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BCL_
#define DEFINED_TYPEDEF_FOR_BCL_

typedef struct {
  real32_T CR_Plc_EvTargetVolt;
  real32_T CR_Plc_EvTargetCurrent;
  real32_T CR_Plc_ChargingMode;
  boolean_T Flag;
  uint16_T Data[8];
} BCL;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BEM_
#define DEFINED_TYPEDEF_FOR_BEM_

typedef struct {
  boolean_T Flag;
  uint16_T Data[8];
  uint16_T CF_Plc_CRM00Timeout;
  uint16_T CF_Plc_CRMAATimeout;
  uint16_T CF_Plc_CTS_CMLTimeout;
  uint16_T CF_Plc_CROAALTimeout;
  uint16_T CF_Plc_CCSTimeout;
  uint16_T CF_Plc_CSTTimeout;
  uint16_T CF_Plc_CSDTimeout;
} BEM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAN_Output_
#define DEFINED_TYPEDEF_FOR_CAN_Output_

typedef struct {
  BHM BHM;
  BRM BRM;
  BCP BCP;
  BRO BRO;
  BCS BCS;
  BSM BSM;
  BST BST;
  BSD BSD;
  BCL BCL;
  BEM BEM;
} CAN_Output;

#endif

#ifndef DEFINED_TYPEDEF_FOR_State_ModeType_
#define DEFINED_TYPEDEF_FOR_State_ModeType_

typedef enum {
  State_ModeType_None = 0,             /* Default value */
  State_ModeType_Start_Communication,
  State_ModeType_initialize,
  State_ModeType_BHM_BMSHelloMessage,
  State_ModeType_BRM_establish_TLS_Session1,
  State_ModeType_Stop_Communication,
  State_ModeType_Error_Timeout,
  State_ModeType_ErrorBEM,
  State_ModeType_BRO_PowerDelivery_ON,
  State_ModeType_BCS_BCL_Loop_Charge_control_and_Rescheduling,
  State_ModeType_BCS_BSM_BCL_ChargeLoop,
  State_ModeType_BST_NormalShutdownBy_EVSE,
  State_ModeType_BST_PowerDelivery_OFF_ShutdownByEVInCaseOfFullCharging,
  State_ModeType_BST_BSD_OpenContactor,
  State_ModeType_BST_EmergencyShutdownByCharger__SECC,
  State_ModeType_Welding_detection,
  State_ModeType_End_charging,
  State_ModeType_Charging_complete,
  State_ModeType_BCP_ChargeParameter_Discovery,
  State_ModeType_Loop_CableCheck,
  State_ModeType_BRO_Loop_PreCharge
} State_ModeType;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ChargeAl_T RT_MODEL_ChargeAl_T;

#endif                                 /* RTW_HEADER_ChargeAl_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
