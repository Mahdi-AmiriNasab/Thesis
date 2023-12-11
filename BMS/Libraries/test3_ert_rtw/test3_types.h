/*
 * File: test3_types.h
 *
 * Code generated for Simulink model 'test3'.
 *
 * Model version                  : 2.300
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon May 15 12:45:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test3_types_h_
#define RTW_HEADER_test3_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_SRE_
#define DEFINED_TYPEDEF_FOR_SRE_

typedef int16_T SRE;

/* enum SRE */
#define Standby                        (0)                       /* Default value */
#define Charging                       (1)
#define Driving                        (2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Contact_
#define DEFINED_TYPEDEF_FOR_Contact_

typedef int16_T Contact;

/* enum Contact */
#define Init                           (0)
#define Open                           (1)                       /* Default value */
#define Close                          (2)
#endif

#ifndef DEFINED_TYPEDEF_FOR_BMS_State_Enum_
#define DEFINED_TYPEDEF_FOR_BMS_State_Enum_

typedef enum {
  BMS_Standby = 0,                     /* Default value */
  BMS_Charging,
  BMS_Driving,
  BMS_Fault
} BMS_State_Enum;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Faults_
#define DEFINED_TYPEDEF_FOR_Faults_

typedef struct {
  boolean_T VoltSensor;
  boolean_T OverCurrent;
  boolean_T HighTemp;
  boolean_T LowTemp;
  boolean_T OverVolt;
  boolean_T UnderVolt;
  boolean_T Charger;
  boolean_T Inverter;
  boolean_T PreChargeFault;
  boolean_T OverDischargeCurrent;
  boolean_T OverChargeCurrent;
  boolean_T BalEn;
  boolean_T ShortCircuitFault;
  boolean_T BMBFault;
  boolean_T CurrentSensor;
  boolean_T MemoryFault;
  boolean_T InputPowerFault;
  boolean_T TempSensor;
  boolean_T CAN_VCU_Fault;
  boolean_T LowSOC;
} Faults;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ChargeCU_ModeReq_
#define DEFINED_TYPEDEF_FOR_ChargeCU_ModeReq_

typedef enum {
  Init_Mode = 0,                       /* Default value */
  CC_Mode,
  CV_Mode,
  Personal_Mode,
  Pre_Charge_Mode,
  FastCharge_Mode
} ChargeCU_ModeReq;

#endif

#ifndef struct_tag_ECRg1ObDlXbVq65I0v9MbH
#define struct_tag_ECRg1ObDlXbVq65I0v9MbH

struct tag_ECRg1ObDlXbVq65I0v9MbH
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[3];
  real32_T pCumRevIndex;
  real32_T pModValueRev;
};

#endif                                 /* struct_tag_ECRg1ObDlXbVq65I0v9MbH */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_ECRg1ObDlXbVq65I0v9MbH g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_test3_T
#define typedef_cell_wrap_test3_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_test3_T;

#endif                                 /* typedef_cell_wrap_test3_T */

#ifndef struct_tag_wJ3WU7O7172nske0bGZpEF
#define struct_tag_wJ3WU7O7172nske0bGZpEF

struct tag_wJ3WU7O7172nske0bGZpEF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_test3_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_wJ3WU7O7172nske0bGZpEF */

#ifndef typedef_dsp_simulink_MovingAverage_te_T
#define typedef_dsp_simulink_MovingAverage_te_T

typedef struct tag_wJ3WU7O7172nske0bGZpEF dsp_simulink_MovingAverage_te_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_te_T */

#ifndef struct_tag_zLuFj3crRZtwleUCAQVyuC
#define struct_tag_zLuFj3crRZtwleUCAQVyuC

struct tag_zLuFj3crRZtwleUCAQVyuC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[11];
  real32_T pCumRevIndex;
  real32_T pModValueRev;
};

#endif                                 /* struct_tag_zLuFj3crRZtwleUCAQVyuC */

#ifndef typedef_g_dsp_internal_SlidingWindo_k_T
#define typedef_g_dsp_internal_SlidingWindo_k_T

typedef struct tag_zLuFj3crRZtwleUCAQVyuC g_dsp_internal_SlidingWindo_k_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindo_k_T */

#ifndef struct_tag_0XX3PBmLm8zjPXbvNLlW6G
#define struct_tag_0XX3PBmLm8zjPXbvNLlW6G

struct tag_0XX3PBmLm8zjPXbvNLlW6G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_test3_T inputVarSize;
  g_dsp_internal_SlidingWindo_k_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindo_k_T _pobj0;
};

#endif                                 /* struct_tag_0XX3PBmLm8zjPXbvNLlW6G */

#ifndef typedef_dsp_simulink_MovingAverage_k_T
#define typedef_dsp_simulink_MovingAverage_k_T

typedef struct tag_0XX3PBmLm8zjPXbvNLlW6G dsp_simulink_MovingAverage_k_T;

#endif                              /* typedef_dsp_simulink_MovingAverage_k_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_test3_T RT_MODEL_test3_T;

#endif                                 /* RTW_HEADER_test3_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
