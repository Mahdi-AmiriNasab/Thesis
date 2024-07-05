/*
 * File: Estimations_private.h
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 15:23:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Estimations_private_h_
#define RTW_HEADER_Estimations_private_h_
#include "rtwtypes.h"

extern const real_T rtCP_pooled_SCy36WAhMI4U[105];
extern const real_T rtCP_pooled_2jnfhQ065QNq[21];
extern const real_T rtCP_pooled_rPeWEl0uhlTa[5];
extern const real_T rtCP_pooled_jdvt4y9yu4xK[105];
extern const real_T rtCP_pooled_9QtqlsFRacs6[105];
extern const real_T rtCP_pooled_ScD7BH7eelHp[9];
extern const real_T rtCP_pooled_1rKFvHuziWqE[9];
extern const uint32_T rtCP_pooled_VeNY2dNehdHS[2];

#define rtCP_EmTable_tableData         rtCP_pooled_SCy36WAhMI4U  /* Expression: Em_LUT
                                                                  * Referenced by: '<S1>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data          rtCP_pooled_2jnfhQ065QNq  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S1>/Em Table'
                                                                  */
#define rtCP_EmTable_bp02Data          rtCP_pooled_rPeWEl0uhlTa  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S1>/Em Table'
                                                                  */
#define rtCP_C1Table_tableData         rtCP_pooled_jdvt4y9yu4xK  /* Expression: C1_LUT
                                                                  * Referenced by: '<S2>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp01Data          rtCP_pooled_2jnfhQ065QNq  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S2>/C1 Table'
                                                                  */
#define rtCP_C1Table_bp02Data          rtCP_pooled_rPeWEl0uhlTa  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S2>/C1 Table'
                                                                  */
#define rtCP_R1Table_tableData         rtCP_pooled_9QtqlsFRacs6  /* Expression: R1_LUT
                                                                  * Referenced by: '<S2>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp01Data          rtCP_pooled_2jnfhQ065QNq  /* Expression: SOC_LUT
                                                                  * Referenced by: '<S2>/R1 Table'
                                                                  */
#define rtCP_R1Table_bp02Data          rtCP_pooled_rPeWEl0uhlTa  /* Expression: Temperature_LUT
                                                                  * Referenced by: '<S2>/R1 Table'
                                                                  */
#define rtCP_Q_Value                   rtCP_pooled_ScD7BH7eelHp  /* Expression: p.Q
                                                                  * Referenced by: '<S3>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_InitialVa rtCP_pooled_1rKFvHuziWqE /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S3>/DataStoreMemory - P'
                                                                  */
#define rtCP_EmTable_maxIndex          rtCP_pooled_VeNY2dNehdHS  /* Computed Parameter: rtCP_EmTable_maxIndex
                                                                  * Referenced by: '<S1>/Em Table'
                                                                  */
#define rtCP_C1Table_maxIndex          rtCP_pooled_VeNY2dNehdHS  /* Computed Parameter: rtCP_C1Table_maxIndex
                                                                  * Referenced by: '<S2>/C1 Table'
                                                                  */
#define rtCP_R1Table_maxIndex          rtCP_pooled_VeNY2dNehdHS  /* Computed Parameter: rtCP_R1Table_maxIndex
                                                                  * Referenced by: '<S2>/R1 Table'
                                                                  */
#endif                                 /* RTW_HEADER_Estimations_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
