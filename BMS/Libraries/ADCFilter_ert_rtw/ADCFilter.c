/*
 * File: ADCFilter.c
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

#include "ADCFilter.h"
#include "ADCFilter_private.h"

/* Block signals (default storage) */
B_ADCFilter_T ADCFilter_B;

/* Block states (default storage) */
DW_ADCFilter_T ADCFilter_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ADCFilter_T ADCFilter_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ADCFilter_T ADCFilter_Y;

/* Real-time model */
static RT_MODEL_ADCFilter_T ADCFilter_M_;
RT_MODEL_ADCFilter_T *const ADCFilter_M = &ADCFilter_M_;

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ADCFilter_MovingAverage2_Init(DW_MovingAverage2_ADCFilter_T *localDW)
{
  dsp_simulink_MovingAverage_AD_T *obj;
  g_dsp_private_SlidingWindowAv_T *obj_0;
  int16_T i;

  /* Start for MATLABSystem: '<Root>/Moving Average2' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0L;
  localDW->obj.NumChannels = -1L;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1L;
  localDW->obj.NumChannels = 1L;
  obj->_pobj0.isInitialized = 0L;
  localDW->obj.pStatistic = &obj->_pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Average2' */
  obj_0 = localDW->obj.pStatistic;
  if (obj_0->isInitialized == 1L) {
    obj_0->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj_0->pCumSumRev[i] = 0.0;
    }

    obj_0->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average2' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ADCFilter_MovingAverage2(real_T rtu_0, B_MovingAverage2_ADCFilter_T *localB,
  DW_MovingAverage2_ADCFilter_T *localDW)
{
  g_dsp_private_SlidingWindowAv_T *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T z;
  int16_T i;

  /* MATLABSystem: '<Root>/Moving Average2' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1L) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1L;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  for (i = 0; i < 9; i++) {
    localB->csumrev[i] = obj->pCumSumRev[i];
  }

  csum += rtu_0;
  z = localB->csumrev[(int16_T)cumRevIndex - 1] + csum;
  localB->csumrev[(int16_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 9.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (i = 7; i >= 0; i--) {
      localB->csumrev[i] += localB->csumrev[i + 1];
    }
  }

  obj->pCumSum = csum;
  for (i = 0; i < 9; i++) {
    obj->pCumSumRev[i] = localB->csumrev[i];
  }

  obj->pCumRevIndex = cumRevIndex;

  /* MATLABSystem: '<Root>/Moving Average2' */
  localB->MovingAverage2 = z / 10.0;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void ADCFilter_MovingAverage2_Term(DW_MovingAverage2_ADCFilter_T *localDW)
{
  g_dsp_private_SlidingWindowAv_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Moving Average2' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1L) {
        obj->isInitialized = 2L;
      }

      localDW->obj.NumChannels = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Moving Average2' */
}

/* Model step function */
void ADCFilter_step(void)
{
  /* local block i/o variables */
  real_T rtb_I;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/LowCurrent'
   */
  ADCFilter_Y.lowCurrentFilter = ADCFilter_U.LowCurrent;
  if ((ADCFilter_U.LowCurrent < 0.2) && (ADCFilter_U.LowCurrent > -0.2)) {
    ADCFilter_Y.lowCurrentFilter = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/HighCurrent'
   */
  ADCFilter_Y.highCurrentFilter = ADCFilter_U.HighCurrent;
  if ((ADCFilter_U.HighCurrent < 1.0) && (ADCFilter_U.HighCurrent > -1.0)) {
    ADCFilter_Y.highCurrentFilter = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  if ((ADCFilter_Y.lowCurrentFilter <= 80.0) && (ADCFilter_Y.lowCurrentFilter >=
       -80.0)) {
    rtb_I = ADCFilter_Y.lowCurrentFilter;
  } else {
    rtb_I = ADCFilter_Y.highCurrentFilter;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
  ADCFilter_MovingAverage2(rtb_I, &ADCFilter_B.MovingAverage3,
    &ADCFilter_DW.MovingAverage3);

  /* Outport: '<Root>/Current' */
  ADCFilter_Y.Current = ADCFilter_B.MovingAverage3.MovingAverage2;

  /* Inport: '<Root>/PackVoltage' */
  ADCFilter_MovingAverage2(ADCFilter_U.PackVoltage, &ADCFilter_B.MovingAverage2,
    &ADCFilter_DW.MovingAverage2);

  /* Outport: '<Root>/Voltage' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  ADCFilter_Y.Voltage = ADCFilter_B.MovingAverage2.MovingAverage2;

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  if ((ADCFilter_B.MovingAverage2.MovingAverage2 < 3.0) &&
      (ADCFilter_B.MovingAverage2.MovingAverage2 > -3.0)) {
    /* Outport: '<Root>/Voltage' */
    ADCFilter_Y.Voltage = 0.0;
  }
}

/* Model initialize function */
void ADCFilter_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ADCFilter_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &ADCFilter_B), 0,
                sizeof(B_ADCFilter_T));

  /* states (dwork) */
  (void) memset((void *)&ADCFilter_DW, 0,
                sizeof(DW_ADCFilter_T));
  ADCFilter_MovingAverage2_Init(&ADCFilter_DW.MovingAverage3);

  /* SystemInitialize for Inport: '<Root>/PackVoltage' */
  ADCFilter_MovingAverage2_Init(&ADCFilter_DW.MovingAverage2);
}

/* Model terminate function */
void ADCFilter_terminate(void)
{
  ADCFilter_MovingAverage2_Term(&ADCFilter_DW.MovingAverage3);
  ADCFilter_MovingAverage2_Term(&ADCFilter_DW.MovingAverage2);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
