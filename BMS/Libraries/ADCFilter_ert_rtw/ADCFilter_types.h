/*
 * File: ADCFilter_types.h
 *
 * Code generated for Simulink model 'ADCFilter'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Feb  7 12:27:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADCFilter_types_h_
#define RTW_HEADER_ADCFilter_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_80AwAGWuE9fVrIKDJpJKoC
#define struct_tag_80AwAGWuE9fVrIKDJpJKoC

struct tag_80AwAGWuE9fVrIKDJpJKoC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[9];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_80AwAGWuE9fVrIKDJpJKoC*/

#ifndef typedef_g_dsp_private_SlidingWindowAv_T
#define typedef_g_dsp_private_SlidingWindowAv_T

typedef struct tag_80AwAGWuE9fVrIKDJpJKoC g_dsp_private_SlidingWindowAv_T;

#endif                               /*typedef_g_dsp_private_SlidingWindowAv_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_ADCFilter_T
#define typedef_cell_wrap_ADCFilter_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_ADCFilter_T;

#endif                                 /*typedef_cell_wrap_ADCFilter_T*/

#ifndef struct_tag_RoFcBL3cgrPNAPUZAtdOnE
#define struct_tag_RoFcBL3cgrPNAPUZAtdOnE

struct tag_RoFcBL3cgrPNAPUZAtdOnE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_ADCFilter_T inputVarSize;
  g_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
  g_dsp_private_SlidingWindowAv_T _pobj0;
};

#endif                                 /*struct_tag_RoFcBL3cgrPNAPUZAtdOnE*/

#ifndef typedef_dsp_simulink_MovingAverage_AD_T
#define typedef_dsp_simulink_MovingAverage_AD_T

typedef struct tag_RoFcBL3cgrPNAPUZAtdOnE dsp_simulink_MovingAverage_AD_T;

#endif                               /*typedef_dsp_simulink_MovingAverage_AD_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_ADCFilter_T RT_MODEL_ADCFilter_T;

#endif                                 /* RTW_HEADER_ADCFilter_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
