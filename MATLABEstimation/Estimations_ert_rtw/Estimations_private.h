/*
 * File: Estimations_private.h
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

#ifndef RTW_HEADER_Estimations_private_h_
#define RTW_HEADER_Estimations_private_h_
#include "rtwtypes.h"
#include "Estimations_types.h"
#include "Estimations.h"

extern const real_T rtCP_pooled_l42MQWC3qubd[105];
extern const real_T rtCP_pooled_BbJYiBpMf0uY[21];
extern const real_T rtCP_pooled_qDiJiT4WjAIl[5];
extern const real_T rtCP_pooled_mogppaAQYv8i[105];
extern const real_T rtCP_pooled_OVHpLMSFPeq1[105];
extern const real_T rtCP_pooled_OnbPSZK1pBei[9];
extern const real_T rtCP_pooled_Em3WrKCz53sD[9];
extern const uint32_T rtCP_pooled_5V6edGmokdkO[2];

#define rtCP_EmTable_tableData         rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S10>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data          rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S10>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data          rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S10>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData         rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S11>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data          rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S11>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data          rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S11>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData         rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S11>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data          rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S11>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data          rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S11>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_k       rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S20>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_f        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S20>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_b        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S20>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_j       rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S21>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_d        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S21>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_l        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S21>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_c       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S21>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_n        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S21>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_c        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S21>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_g       rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S30>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_c        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S30>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_o        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S30>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_a       rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S31>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_o        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S31>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_lp       rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S31>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_b       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S31>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_c        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S31>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_l        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S31>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_a       rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S40>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_b        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S40>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_k        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S40>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_ji      rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S41>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_k        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S41>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_m        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S41>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_e       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S41>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_p        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S41>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_d        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S41>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_kd      rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S50>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_d        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S50>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_m        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S50>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_h       rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S51>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_e        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S51>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_d        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S51>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_e0      rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S51>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_g        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S51>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_f        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S51>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_n       rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S60>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_a        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S60>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_m0       rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S60>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_g       rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S61>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_e3       rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S61>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_p        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S61>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_m       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S61>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_l        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S61>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_g        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S61>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_p       rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S70>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_dx       rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S70>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_kv       rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S70>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_k       rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S71>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_j        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S71>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_b        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S71>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_a       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S71>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_a        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S71>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_j        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S71>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_nv      rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S80>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_g        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S80>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_e        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S80>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_k4      rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S81>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_dj       rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S81>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_a        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S81>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_n       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S81>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_b        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S81>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_fn       rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S81>/R1 Table'
                                                                  */
#define rtCP_EmTable_tableData_nm      rtCP_pooled_l42MQWC3qubd  /* Expression: Em_LUT
                                                                  * Referenced by: '<S90>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_fy       rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S90>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data_l        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S90>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData_m       rtCP_pooled_mogppaAQYv8i  /* Expression: C1_LUT
                                                                  * Referenced by: '<S91>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data_i        rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S91>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data_k        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S91>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData_k       rtCP_pooled_OVHpLMSFPeq1  /* Expression: R1_LUT
                                                                  * Referenced by: '<S91>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data_nk       rtCP_pooled_BbJYiBpMf0uY  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S91>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data_m        rtCP_pooled_qDiJiT4WjAIl  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S91>/R1 Table'
                                                                  */
#define rtCP_Q_Value                   rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S12>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_InitialVa rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S12>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_p                 rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S22>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_j rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S22>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_n                 rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S32>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_b rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S32>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_nq                rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S42>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_d rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S42>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_p4                rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S52>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_f rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S52>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_b                 rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S62>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_c rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S62>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_n4                rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S72>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initia_bi rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S72>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_h                 rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S82>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_m rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S82>/DataStoreMemory - P'
                                                                  */
#define rtCP_Q_Value_a                 rtCP_pooled_OnbPSZK1pBei  /* Expression: p.Q
                                                                  * Referenced by: '<S92>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_Initial_h rtCP_pooled_Em3WrKCz53sD /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S92>/DataStoreMemory - P'
                                                                  */
#define rtCP_EmTable_maxIndex          rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex
                                                                  * Referenced by: '<S10>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex          rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex
                                                                  * Referenced by: '<S11>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex          rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex
                                                                  * Referenced by: '<S11>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_a        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_a
                                                                  * Referenced by: '<S20>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_g        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_g
                                                                  * Referenced by: '<S21>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_b        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_b
                                                                  * Referenced by: '<S21>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_ar       rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_ar
                                                                  * Referenced by: '<S30>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_i        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_i
                                                                  * Referenced by: '<S31>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_e        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_e
                                                                  * Referenced by: '<S31>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_n        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_n
                                                                  * Referenced by: '<S40>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_f        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_f
                                                                  * Referenced by: '<S41>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_m        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_m
                                                                  * Referenced by: '<S41>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_p        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_p
                                                                  * Referenced by: '<S50>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_m        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_m
                                                                  * Referenced by: '<S51>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_g        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_g
                                                                  * Referenced by: '<S51>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_j        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_j
                                                                  * Referenced by: '<S60>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_l        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_l
                                                                  * Referenced by: '<S61>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_a        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_a
                                                                  * Referenced by: '<S61>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_b        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_b
                                                                  * Referenced by: '<S70>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_o        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_o
                                                                  * Referenced by: '<S71>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_gp       rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_gp
                                                                  * Referenced by: '<S71>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_bp       rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_bp
                                                                  * Referenced by: '<S80>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_n        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_n
                                                                  * Referenced by: '<S81>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_d        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_d
                                                                  * Referenced by: '<S81>/R1 Table'
                                                                  */
#define rtCP_EmTable_maxIndex_f        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_EmTable_maxIndex_f
                                                                  * Referenced by: '<S90>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex_h        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_C1Table_maxIndex_h
                                                                  * Referenced by: '<S91>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex_i        rtCP_pooled_5V6edGmokdkO  /* Computed Parameter: rtCP_R1Table_maxIndex_i
                                                                  * Referenced by: '<S91>/R1 Table'
                                                                  */

extern void Estimations_Subsystem(boolean_T rtu_uBlockOrdering, real_T rty_x[3],
  real_T rty_P[9], boolean_T *rty_yBlockOrdering, const real_T rtd_P[9], const
  real_T rtd_x[3]);

#endif                                 /* RTW_HEADER_Estimations_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
