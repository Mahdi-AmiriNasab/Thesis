/*
 * File: test3.c
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

#include "test3.h"
#include "rtwtypes.h"
#include "test3_private.h"
#include "test3_types.h"
#include "rt_nonfinite.h"
#include "RCTcc.h"
#include <math.h>
#define te_IN_OverDischargeCurrentFault (3U)
#define te_IN_PreCharge_UnderVolt_Fault (3U)
#define test3_IN_BMBFault              (1U)
#define test3_IN_BalActive             (1U)
#define test3_IN_BalActive1            (2U)
#define test3_IN_BalNotActive          (3U)
#define test3_IN_BalancingOFF          (1U)
#define test3_IN_BalancingON           (2U)
#define test3_IN_CAN_VCU_Fault         (2U)
#define test3_IN_CC_Mode               (1U)
#define test3_IN_CV_Mode               (2U)
#define test3_IN_Charginig             (1U)
#define test3_IN_CloseChgrContactors   (1U)
#define test3_IN_CloseInvtrContactors  (1U)
#define test3_IN_CloseNegCntct         (1U)
#define test3_IN_ClosePosCntct         (2U)
#define test3_IN_ClosePreChrgRly       (1U)
#define test3_IN_ClosePreChrgRly_k     (3U)
#define test3_IN_Driving               (2U)
#define test3_IN_FastCharge_Mode       (3U)
#define test3_IN_Fault                 (3U)
#define test3_IN_HighTemperatureFault  (1U)
#define test3_IN_Init_Mode             (4U)
#define test3_IN_InputPowerFault       (3U)
#define test3_IN_LowSOC                (4U)
#define test3_IN_LowTemperatureFault   (2U)
#define test3_IN_MSG_Absent            (1U)
#define test3_IN_MSG_Present           (2U)
#define test3_IN_MemoryFault           (5U)
#define test3_IN_NO_ACTIVE_CHILD_k     (0U)
#define test3_IN_NoCellTempFault       (3U)
#define test3_IN_NoCellVoltFault       (1U)
#define test3_IN_NoCurrLimFault        (1U)
#define test3_IN_NoInputFault          (6U)
#define test3_IN_OpenChgrContactors    (2U)
#define test3_IN_OpenInvtrContactors   (2U)
#define test3_IN_OpenNegCntct          (2U)
#define test3_IN_OpenPosCntct          (3U)
#define test3_IN_OpenPos_NegCntct1     (4U)
#define test3_IN_OpenPreChrgRly        (5U)
#define test3_IN_OpenPreChrgRly_k      (4U)
#define test3_IN_OverChargeCurrentFault (2U)
#define test3_IN_OverVoltageFault      (2U)
#define test3_IN_Personal_Mode         (5U)
#define test3_IN_Personal_Mode1        (6U)
#define test3_IN_PreChargeFaultCheck   (7U)
#define test3_IN_PreCharge_Mode        (8U)
#define test3_IN_Ready                 (6U)
#define test3_IN_SOC_Detect            (9U)
#define test3_IN_STEP1                 (1U)
#define test3_IN_SensorFaut            (7U)
#define test3_IN_ShortCircuitFault     (8U)
#define test3_IN_Standby               (4U)
#define test3_IN_Static_Absent         (1U)
#define test3_IN_Static_present        (2U)
#define test3_IN_UnderVoltageFault     (4U)
#define test3_IN_pre_Absent            (2U)
#define test3_IN_pre_present           (2U)
#define test3_IN_step1                 (1U)
#define test3_IN_step2                 (2U)
#define test3_IN_test                  (1U)
#define test3_IN_test1                 (2U)

/* Block signals (default storage) */
B_test3_T test3_B;

/* Block states (default storage) */
DW_test3_T test3_DW;

/* External inputs (root inport signals with default storage) */
ExtU_test3_T test3_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_test3_T test3_Y;

/* Real-time model */
static RT_MODEL_test3_T test3_M_;
RT_MODEL_test3_T *const test3_M = &test3_M_;

/* Forward declaration for local functions */
static void test3_CC_Mode(void);
static void test3_FastCharge_Mode(void);
static void test3_exit_internal_Charginig(void);
static void test3_Charginig(void);
static void test3_FaultMonitoring(void);
static void test3_ChargerContactorState(void);
static void test3_InverterContactorState(void);
static void test3_Balancing(const real32_T TmpSignalConversionAtSFunctionI[96]);
static void test3_enter_internal_Main(void);
static void test3_Main(const real32_T TmpSignalConversionAtSFunctio_g[16], const
  real32_T TmpSignalConversionAtSFunctionI[96]);
real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1UL] - yL_0d0) * frac + yL_0d0;
}

real32_T look2_iflf_pbinlcpw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], uint32_T prevIndex[], const
  uint32_T maxIndex[], uint32_T stride)
{
  real32_T fractions[2];
  real32_T frac;
  real32_T yL_0d0;
  real32_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0UL]]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0UL];
    iLeft = 0UL;
    iRght = maxIndex[0UL];
    found = 0UL;
    while (found == 0UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1UL;
        bpIdx = ((bpIdx + iLeft) - 1UL) >> 1UL;
      } else if (u0 < bp0[bpIdx + 1UL]) {
        found = 1UL;
      } else {
        iLeft = bpIdx + 1UL;
        bpIdx = ((bpIdx + iRght) + 1UL) >> 1UL;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1UL] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0UL] - 1UL;
    frac = 1.0F;
  }

  prevIndex[0UL] = bpIdx;
  fractions[0UL] = frac;
  bpIndices[0UL] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0UL]) {
    bpIdx = 0UL;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1UL]]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[1UL];
    iLeft = 0UL;
    iRght = maxIndex[1UL];
    found = 0UL;
    while (found == 0UL) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx - 1UL;
        bpIdx = ((bpIdx + iLeft) - 1UL) >> 1UL;
      } else if (u1 < bp1[bpIdx + 1UL]) {
        found = 1UL;
      } else {
        iLeft = bpIdx + 1UL;
        bpIdx = ((bpIdx + iRght) + 1UL) >> 1UL;
      }
    }

    frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1UL] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1UL] - 1UL;
    frac = 1.0F;
  }

  prevIndex[1UL] = bpIdx;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  iLeft = bpIdx * stride + bpIndices[0UL];
  yL_0d0 = table[iLeft];
  yL_0d0 += (table[iLeft + 1UL] - yL_0d0) * fractions[0UL];
  iLeft += stride;
  yL_0d1 = table[iLeft];
  return (((table[iLeft + 1UL] - yL_0d1) * fractions[0UL] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

real32_T look1_iflf_pbinlcpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0UL];
    iLeft = 0UL;
    iRght = maxIndex;
    found = 0UL;
    while (found == 0UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1UL;
        bpIdx = ((bpIdx + iLeft) - 1UL) >> 1UL;
      } else if (u0 < bp0[bpIdx + 1UL]) {
        found = 1UL;
      } else {
        iLeft = bpIdx + 1UL;
        bpIdx = ((bpIdx + iRght) + 1UL) >> 1UL;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1UL] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1UL;
    frac = 1.0F;
  }

  prevIndex[0UL] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1UL] - yL_0d0) * frac + yL_0d0;
}

/*
 * System initialize for atomic system:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *    ...
 */
void test3_MovingAverage_Init(DW_MovingAverage_test3_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *iobj_0;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0L;
  localDW->obj.NumChannels = -1L;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1L;
  localDW->obj.NumChannels = 1L;
  localDW->obj._pobj0.isInitialized = 0L;
  localDW->obj._pobj0.isInitialized = 0L;
  localDW->obj.pStatistic = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
  iobj_0 = localDW->obj.pStatistic;
  if (iobj_0->isInitialized == 1L) {
    iobj_0->pCumSum = 0.0F;
    iobj_0->pCumSumRev[0] = 0.0F;
    iobj_0->pCumSumRev[1] = 0.0F;
    iobj_0->pCumSumRev[2] = 0.0F;
    iobj_0->pCumRevIndex = 1.0F;
    iobj_0->pModValueRev = 0.0F;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
}

/*
 * Output and update for atomic system:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *    ...
 */
void test3_MovingAverage(real32_T rtu_0, B_MovingAverage_test3_T *localB,
  DW_MovingAverage_test3_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real32_T csumrev[3];
  real32_T csum;
  real32_T cumRevIndex;
  real32_T modValueRev;
  real32_T z;

  /* MATLABSystem: '<Root>/Moving Average' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1L) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1L;
    obj->pCumSum = 0.0F;
    obj->pCumSumRev[0] = 0.0F;
    obj->pCumSumRev[1] = 0.0F;
    obj->pCumSumRev[2] = 0.0F;
    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0F;
    obj->pCumSumRev[0] = 0.0F;
    obj->pCumSumRev[1] = 0.0F;
    obj->pCumSumRev[2] = 0.0F;
    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  csumrev[0] = obj->pCumSumRev[0];
  csumrev[1] = obj->pCumSumRev[1];
  csumrev[2] = obj->pCumSumRev[2];
  modValueRev = obj->pModValueRev;
  z = 0.0F;

  /* MATLABSystem: '<Root>/Moving Average' */
  localB->ChargeCurrentLimit = 0.0F;

  /* MATLABSystem: '<Root>/Moving Average' */
  csum += rtu_0;
  if (modValueRev == 0.0F) {
    z = csumrev[(int16_T)cumRevIndex - 1] + csum;
  }

  csumrev[(int16_T)cumRevIndex - 1] = rtu_0;
  if (cumRevIndex != 3.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    csumrev[1] += csumrev[2];
    csumrev[0] += csumrev[1];
  }

  if (modValueRev == 0.0F) {
    /* MATLABSystem: '<Root>/Moving Average' */
    localB->ChargeCurrentLimit = z / 4.0F;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = csumrev[0];
  obj->pCumSumRev[1] = csumrev[1];
  obj->pCumSumRev[2] = csumrev[2];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0F) {
    obj->pModValueRev = modValueRev - 1.0F;
  } else {
    obj->pModValueRev = 0.0F;
  }
}

/*
 * Termination for atomic system:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *    ...
 */
void test3_MovingAverage_Term(DW_MovingAverage_test3_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Moving Average' */
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

  /* End of Terminate for MATLABSystem: '<Root>/Moving Average' */
}

/* Function for Chart: '<S97>/Chart' */
static void test3_CC_Mode(void)
{
  /* Outport: '<Root>/Charge_Complete' */
  test3_Y.Charge_Complete = 0.0;

  /* Inport: '<Root>/StateRequest' incorporates:
   *  Inport: '<Root>/ReqSOC'
   *  Inport: '<Root>/Req_FastCh'
   *  Inport: '<Root>/SOC'
   *  Merge: '<S677>/ Merge '
   *  Outport: '<Root>/ChargeCurrentLimit'
   *  Outport: '<Root>/ChargeModeReq'
   *  Outport: '<Root>/ChargeVoltReq'
   *  Outport: '<Root>/Charge_Complete'
   *  Outport: '<Root>/Fake_SOC'
   *  Outport: '<Root>/MaxCellVolt'
   *  Outport: '<Root>/MinCellVolt'
   *  Outport: '<Root>/SumOfVoltages'
   */
  if ((test3_U.StateRequest != Charging) || (test3_Y.MinCellVolt <= 2.5F)) {
    test3_DW.is_Charginig = test3_IN_Init_Mode;
    test3_Y.ChargeModeReq = Init_Mode;
    test3_B.ChargeCurrentReq = 0.0F;
    test3_Y.ChargeVoltReq = 0.0F;
  } else if ((test3_Y.Fake_SOC >= test3_U.ReqSOC) && ((int16_T)test3_U.ReqSOC <
              100)) {
    test3_DW.durationCounter_1 = 0L;
    test3_DW.is_Charginig = test3_IN_Personal_Mode;
    test3_Y.Charge_Complete = 1.0;
    test3_B.ChargeCurrentReq = 0.0F;
    test3_Y.ChargeModeReq = Personal_Mode;
    test3_Y.ChargeVoltReq = 0.0F;
  } else if ((test3_U.Req_FastCh == 1.0F) && (test3_U.SOC > 20.0F) &&
             (test3_U.SOC <= 72.0F)) {
    test3_DW.is_Charginig = test3_IN_FastCharge_Mode;
    test3_Y.ChargeModeReq = FastCharge_Mode;
  } else if (test3_Y.MaxCellVolt >= 4.2F) {
    test3_DW.is_Charginig = test3_IN_CV_Mode;
    test3_DW.temporalCounter_i2 = 0UL;
    test3_Y.ChargeModeReq = CV_Mode;
    if ((test3_Y.ChargeCurrentLimit >= 30.0F) || rtIsNaNF
        (test3_Y.ChargeCurrentLimit)) {
      test3_B.ChargeCurrentReq = 30.0F;
    } else {
      test3_B.ChargeCurrentReq = test3_Y.ChargeCurrentLimit;
    }
  } else {
    if ((test3_Y.ChargeCurrentLimit >= 30.0F) || rtIsNaNF
        (test3_Y.ChargeCurrentLimit)) {
      test3_B.ChargeCurrentReq = 30.0F;
    } else {
      test3_B.ChargeCurrentReq = test3_Y.ChargeCurrentLimit;
    }

    test3_Y.ChargeVoltReq = (4.2F - test3_Y.MaxCellVolt) * 96.0F + 1.01F *
      test3_Y.SumOfVoltages;
  }

  /* End of Inport: '<Root>/StateRequest' */
}

/* Function for Chart: '<S97>/Chart' */
static void test3_FastCharge_Mode(void)
{
  /* Outport: '<Root>/Charge_Complete' */
  test3_Y.Charge_Complete = 0.0;

  /* Inport: '<Root>/Req_FastCh' incorporates:
   *  Inport: '<Root>/ReqSOC'
   *  Inport: '<Root>/SOC'
   *  Inport: '<Root>/StateRequest'
   *  Outport: '<Root>/Fake_SOC'
   *  Outport: '<Root>/MaxCellVolt'
   *  Outport: '<Root>/MinCellVolt'
   */
  if ((test3_U.Req_FastCh == 0.0F) || (test3_U.SOC > 80.0F)) {
    test3_DW.is_Charginig = test3_IN_CC_Mode;

    /* Outport: '<Root>/ChargeModeReq' */
    test3_Y.ChargeModeReq = CC_Mode;
  } else if ((test3_U.StateRequest != Charging) || (test3_Y.MinCellVolt <= 2.5F))
  {
    test3_DW.is_Charginig = test3_IN_Init_Mode;

    /* Outport: '<Root>/ChargeModeReq' */
    test3_Y.ChargeModeReq = Init_Mode;

    /* Merge: '<S677>/ Merge ' */
    test3_B.ChargeCurrentReq = 0.0F;

    /* Outport: '<Root>/ChargeVoltReq' */
    test3_Y.ChargeVoltReq = 0.0F;
  } else if (test3_Y.MaxCellVolt >= 4.2F) {
    test3_DW.is_Charginig = test3_IN_CV_Mode;
    test3_DW.temporalCounter_i2 = 0UL;

    /* Outport: '<Root>/ChargeModeReq' */
    test3_Y.ChargeModeReq = CV_Mode;

    /* Outport: '<Root>/ChargeCurrentLimit' */
    if ((test3_Y.ChargeCurrentLimit >= 30.0F) || rtIsNaNF
        (test3_Y.ChargeCurrentLimit)) {
      test3_B.ChargeCurrentReq = 30.0F;
    } else {
      test3_B.ChargeCurrentReq = test3_Y.ChargeCurrentLimit;
    }
  } else if ((test3_Y.Fake_SOC >= test3_U.ReqSOC) && ((int16_T)test3_U.ReqSOC <
              100)) {
    test3_DW.durationCounter_1 = 0L;
    test3_DW.is_Charginig = test3_IN_Personal_Mode;

    /* Outport: '<Root>/Charge_Complete' */
    test3_Y.Charge_Complete = 1.0;

    /* Merge: '<S677>/ Merge ' */
    test3_B.ChargeCurrentReq = 0.0F;

    /* Outport: '<Root>/ChargeModeReq' */
    test3_Y.ChargeModeReq = Personal_Mode;

    /* Outport: '<Root>/ChargeVoltReq' */
    test3_Y.ChargeVoltReq = 0.0F;
  } else {
    /* Merge: '<S677>/ Merge ' incorporates:
     *  Outport: '<Root>/ChargeCurrentLimit'
     */
    test3_B.ChargeCurrentReq = test3_Y.ChargeCurrentLimit;

    /* Outport: '<Root>/ChargeVoltReq' incorporates:
     *  Outport: '<Root>/MaxCellVolt'
     *  Outport: '<Root>/SumOfVoltages'
     */
    test3_Y.ChargeVoltReq = (4.2F - test3_Y.MaxCellVolt) * 96.0F + 1.01F *
      test3_Y.SumOfVoltages;
  }

  /* End of Inport: '<Root>/Req_FastCh' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S97>/Chart' */
static void test3_exit_internal_Charginig(void)
{
  test3_DW.is_Charginig = test3_IN_NO_ACTIVE_CHILD_k;
}

/* Function for Chart: '<S97>/Chart' */
static void test3_Charginig(void)
{
  /* Inport: '<Root>/StateRequest' */
  test3_B.i1 = test3_U.StateRequest;
  if ((test3_B.i1 != Charging) && (test3_DW.ChrgCntctState == Init)) {
    test3_exit_internal_Charginig();
    test3_DW.is_MainStateMachine = test3_IN_Standby;

    /* Outport: '<Root>/BMS_State' */
    test3_Y.BMS_State = BMS_Standby;

    /* Merge: '<S677>/ Merge ' */
    test3_B.ChargeCurrentReq = 0.0F;

    /* Outport: '<Root>/ChargeVoltReq' */
    test3_Y.ChargeVoltReq = 0.0F;

    /* Outport: '<Root>/ChargeModeReq' */
    test3_Y.ChargeModeReq = Init_Mode;

    /* Outport: '<Root>/Charge_Complete' */
    test3_Y.Charge_Complete = 0.0;
  } else if (test3_DW.FaultPresent) {
    /* Merge: '<S677>/ Merge ' */
    test3_B.ChargeCurrentReq = 0.0F;
    test3_exit_internal_Charginig();
    test3_DW.is_MainStateMachine = test3_IN_Fault;

    /* Outport: '<Root>/BMS_State' */
    test3_Y.BMS_State = BMS_Fault;

    /* Outport: '<Root>/DischargeCurrentReq' */
    test3_Y.DischargeCurrentReq = 0.0F;

    /* Outport: '<Root>/ChargeVoltReq' */
    test3_Y.ChargeVoltReq = 0.0F;
  } else if (test3_B.i1 == Driving) {
    test3_exit_internal_Charginig();
    test3_DW.is_MainStateMachine = test3_IN_Driving;

    /* Outport: '<Root>/BMS_State' */
    test3_Y.BMS_State = BMS_Driving;
  } else {
    switch (test3_DW.is_Charginig) {
     case test3_IN_CC_Mode:
      test3_CC_Mode();
      break;

     case test3_IN_CV_Mode:
      /* Outport: '<Root>/Charge_Complete' */
      test3_Y.Charge_Complete = 0.0;
      if ((test3_B.ChargeCurrentReq <= 2.8125F) && (test3_DW.temporalCounter_i2 >=
           600UL)) {
        test3_DW.is_Charginig = test3_IN_SOC_Detect;

        /* Outport: '<Root>/Charge_Complete' */
        test3_Y.Charge_Complete = 1.0;

        /* Outport: '<Root>/SOC_New' */
        test3_Y.SOC_New = 100.0;

        /* Outport: '<Root>/MinCellVolt' incorporates:
         *  Inport: '<Root>/ReqSOC'
         *  Merge: '<S677>/ Merge '
         *  Outport: '<Root>/ChargeCurrentLimit'
         *  Outport: '<Root>/ChargeModeReq'
         *  Outport: '<Root>/ChargeVoltReq'
         *  Outport: '<Root>/Charge_Complete'
         *  Outport: '<Root>/Fake_SOC'
         *  Outport: '<Root>/MaxCellVolt'
         *  Outport: '<Root>/SumOfVoltages'
         */
      } else if ((test3_B.i1 != Charging) || (test3_Y.MinCellVolt <= 2.5F) ||
                 (test3_Y.MaxCellVolt >= 4.37F)) {
        test3_DW.is_Charginig = test3_IN_Init_Mode;
        test3_Y.ChargeModeReq = Init_Mode;
        test3_B.ChargeCurrentReq = 0.0F;
        test3_Y.ChargeVoltReq = 0.0F;
      } else if ((test3_Y.MaxCellVolt < 4.12F) && (test3_DW.temporalCounter_i2 >=
                  500UL)) {
        test3_DW.is_Charginig = test3_IN_CC_Mode;
        test3_Y.ChargeModeReq = CC_Mode;
      } else if ((test3_Y.Fake_SOC >= test3_U.ReqSOC) && ((int16_T)
                  test3_U.ReqSOC < 100)) {
        test3_DW.durationCounter_1 = 0L;
        test3_DW.is_Charginig = test3_IN_Personal_Mode;
        test3_Y.Charge_Complete = 1.0;
        test3_B.ChargeCurrentReq = 0.0F;
        test3_Y.ChargeModeReq = Personal_Mode;
        test3_Y.ChargeVoltReq = 0.0F;
      } else {
        test3_B.ChargeCurrentReq -= (test3_Y.MaxCellVolt - 4.2F) * 0.5F;
        if ((!(test3_B.ChargeCurrentReq <= test3_Y.ChargeCurrentLimit)) &&
            (!rtIsNaNF(test3_Y.ChargeCurrentLimit))) {
          test3_B.ChargeCurrentReq = test3_Y.ChargeCurrentLimit;
        }

        if ((test3_B.ChargeCurrentReq >= 30.0F) || rtIsNaNF
            (test3_B.ChargeCurrentReq)) {
          test3_B.ChargeCurrentReq = 30.0F;
        }

        test3_Y.ChargeVoltReq = (4.2F - test3_Y.MaxCellVolt) * 96.0F + 1.01F *
          test3_Y.SumOfVoltages;
      }
      break;

     case test3_IN_FastCharge_Mode:
      test3_FastCharge_Mode();
      break;

     case test3_IN_Init_Mode:
      /* Outport: '<Root>/MaxCellVolt' incorporates:
       *  Inport: '<Root>/ReqSOC'
       *  Outport: '<Root>/ChargeModeReq'
       *  Outport: '<Root>/Charge_Complete'
       *  Outport: '<Root>/DischargeCurrentLimit'
       *  Outport: '<Root>/DischargeCurrentReq'
       *  Outport: '<Root>/Fake_SOC'
       *  Outport: '<Root>/Faults'
       *  Outport: '<Root>/MinCellVolt'
       */
      if ((test3_B.i1 == Charging) && (test3_Y.MaxCellVolt < 4.12F) &&
          (test3_Y.MinCellVolt > 2.5F) && ((test3_Y.Fake_SOC < ((int16_T)
             rt_roundd_snf(0.97 * (real_T)test3_U.ReqSOC) & 255)) || ((int16_T)
            test3_U.ReqSOC >= 100))) {
        test3_DW.is_Charginig = test3_IN_CC_Mode;
        test3_Y.Charge_Complete = 0.0;
        test3_Y.ChargeModeReq = CC_Mode;
      } else if ((test3_B.i1 == Charging) && (test3_Y.MinCellVolt <= 2.5F) &&
                 (!test3_Y.Faults_d.PreChargeFault)) {
        test3_DW.is_Charginig = test3_IN_PreCharge_Mode;
        test3_DW.temporalCounter_i2 = 0UL;
        test3_Y.ChargeModeReq = Pre_Charge_Mode;
        test3_Y.Charge_Complete = 0.0;

        /* Sum: '<S679>/Add1' incorporates:
         *  Constant: '<S679>/Constant'
         *  DiscreteIntegrator: '<S679>/Discrete-Time Integrator'
         *  Gain: '<S679>/KP'
         *  Gain: '<S679>/KP2'
         *  Inport: '<Root>/Pack_Current'
         *  Outport: '<Root>/ChargeModeReq'
         *  Outport: '<Root>/Charge_Complete'
         *  Sum: '<S679>/Add'
         */
        test3_B.ChargeCurrentReq = (2.8125F - (-test3_U.Pack_Current)) * 0.8F +
          test3_DW.DiscreteTimeIntegrator_DSTATE;

        /* Saturate: '<S679>/Saturation' */
        if (test3_B.ChargeCurrentReq > 30.0F) {
          /* Sum: '<S679>/Add1' incorporates:
           *  Merge: '<S677>/ Merge '
           *  SignalConversion generated from: '<S679>/ChargeCurrentReq'
           */
          test3_B.ChargeCurrentReq = 30.0F;
        } else if (test3_B.ChargeCurrentReq < 0.0F) {
          /* Sum: '<S679>/Add1' incorporates:
           *  Merge: '<S677>/ Merge '
           *  SignalConversion generated from: '<S679>/ChargeCurrentReq'
           */
          test3_B.ChargeCurrentReq = 0.0F;
        }

        /* Update for DiscreteIntegrator: '<S679>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S679>/Constant'
         *  Gain: '<S679>/KP2'
         *  Inport: '<Root>/Pack_Current'
         *  Sum: '<S679>/Add'
         */
        test3_DW.DiscreteTimeIntegrator_DSTATE += (2.8125F -
          (-test3_U.Pack_Current)) * 0.01F;
      } else {
        test3_Y.DischargeCurrentReq = test3_Y.DischargeCurrentLimit;
      }
      break;

     case test3_IN_Personal_Mode:
      /* Outport: '<Root>/Charge_Complete' */
      test3_Y.Charge_Complete = 1.0;

      /* Outport: '<Root>/Fake_SOC' incorporates:
       *  Inport: '<Root>/Pack_Current'
       *  Inport: '<Root>/ReqSOC'
       *  Merge: '<S677>/ Merge '
       *  Outport: '<Root>/ChargeModeReq'
       *  Outport: '<Root>/ChargeVoltReq'
       *  Outport: '<Root>/Charge_Complete'
       *  Outport: '<Root>/MinCellVolt'
       */
      if ((test3_Y.Fake_SOC < ((int16_T)rt_roundd_snf(0.98 * (real_T)
             test3_U.ReqSOC) & 255)) || (test3_B.i1 != Charging) ||
          (test3_Y.MinCellVolt <= 2.5F)) {
        test3_DW.is_Charginig = test3_IN_Init_Mode;
        test3_Y.ChargeModeReq = Init_Mode;
        test3_B.ChargeCurrentReq = 0.0F;
        test3_Y.ChargeVoltReq = 0.0F;
      } else {
        if (!(test3_U.Pack_Current >= 2.0F)) {
          test3_DW.durationCounter_1 = 0L;
        }

        if (test3_DW.durationCounter_1 > 400L) {
          test3_DW.is_Charginig = test3_IN_Personal_Mode1;
          test3_DW.temporalCounter_i2 = 0UL;
          test3_Y.Charge_Complete = 0.0;

          /* Sum: '<S679>/Add1' incorporates:
           *  Constant: '<S678>/Constant'
           *  DiscreteIntegrator: '<S678>/Discrete-Time Integrator'
           *  Gain: '<S678>/KP'
           *  Gain: '<S678>/KP2'
           *  Inport: '<Root>/Pack_Current'
           *  Outport: '<Root>/Charge_Complete'
           *  Sum: '<S678>/Add'
           *  Sum: '<S678>/Add1'
           */
          test3_B.ChargeCurrentReq = (0.0F - (-test3_U.Pack_Current)) * 0.8F +
            test3_DW.DiscreteTimeIntegrator_DSTATE_d;

          /* Saturate: '<S678>/Saturation' */
          if (test3_B.ChargeCurrentReq > 30.0F) {
            /* Sum: '<S679>/Add1' incorporates:
             *  Merge: '<S677>/ Merge '
             *  SignalConversion generated from: '<S678>/ChargeCurrentReq'
             */
            test3_B.ChargeCurrentReq = 30.0F;
          } else if (test3_B.ChargeCurrentReq < 0.0F) {
            /* Sum: '<S679>/Add1' incorporates:
             *  Merge: '<S677>/ Merge '
             *  SignalConversion generated from: '<S678>/ChargeCurrentReq'
             */
            test3_B.ChargeCurrentReq = 0.0F;
          }

          /* Update for DiscreteIntegrator: '<S678>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S678>/Constant'
           *  Gain: '<S678>/KP2'
           *  Inport: '<Root>/Pack_Current'
           *  Sum: '<S678>/Add'
           */
          test3_DW.DiscreteTimeIntegrator_DSTATE_d += (0.0F -
            (-test3_U.Pack_Current)) * 0.01F;
        }
      }
      break;

     case test3_IN_Personal_Mode1:
      /* Outport: '<Root>/Charge_Complete' */
      test3_Y.Charge_Complete = 0.0;

      /* Outport: '<Root>/Fake_SOC' incorporates:
       *  Inport: '<Root>/ReqSOC'
       *  Merge: '<S677>/ Merge '
       *  Outport: '<Root>/ChargeModeReq'
       *  Outport: '<Root>/ChargeVoltReq'
       *  Outport: '<Root>/Charge_Complete'
       *  Outport: '<Root>/MaxCellVolt'
       *  Outport: '<Root>/MinCellVolt'
       *  Outport: '<Root>/SumOfVoltages'
       */
      if ((test3_Y.Fake_SOC < ((int16_T)rt_roundd_snf(0.98 * (real_T)
             test3_U.ReqSOC) & 255)) || (test3_B.i1 != Charging) ||
          (test3_Y.MinCellVolt <= 2.5F)) {
        test3_DW.is_Charginig = test3_IN_Init_Mode;
        test3_Y.ChargeModeReq = Init_Mode;
        test3_B.ChargeCurrentReq = 0.0F;
        test3_Y.ChargeVoltReq = 0.0F;
      } else if ((test3_B.ChargeCurrentReq < 2.0F) &&
                 (test3_DW.temporalCounter_i2 >= 400UL)) {
        test3_DW.durationCounter_1 = 0L;
        test3_DW.is_Charginig = test3_IN_Personal_Mode;
        test3_Y.Charge_Complete = 1.0;
        test3_B.ChargeCurrentReq = 0.0F;
        test3_Y.ChargeModeReq = Personal_Mode;
        test3_Y.ChargeVoltReq = 0.0F;
      } else {
        test3_Y.ChargeVoltReq = (4.2F - test3_Y.MaxCellVolt) * 96.0F +
          test3_Y.SumOfVoltages;

        /* Sum: '<S679>/Add1' incorporates:
         *  Constant: '<S678>/Constant'
         *  DiscreteIntegrator: '<S678>/Discrete-Time Integrator'
         *  Gain: '<S678>/KP'
         *  Gain: '<S678>/KP2'
         *  Inport: '<Root>/Pack_Current'
         *  Outport: '<Root>/ChargeVoltReq'
         *  Outport: '<Root>/MaxCellVolt'
         *  Outport: '<Root>/SumOfVoltages'
         *  Sum: '<S678>/Add'
         *  Sum: '<S678>/Add1'
         */
        test3_B.ChargeCurrentReq = (0.0F - (-test3_U.Pack_Current)) * 0.8F +
          test3_DW.DiscreteTimeIntegrator_DSTATE_d;

        /* Saturate: '<S678>/Saturation' */
        if (test3_B.ChargeCurrentReq > 30.0F) {
          /* Sum: '<S679>/Add1' incorporates:
           *  Merge: '<S677>/ Merge '
           *  SignalConversion generated from: '<S678>/ChargeCurrentReq'
           */
          test3_B.ChargeCurrentReq = 30.0F;
        } else if (test3_B.ChargeCurrentReq < 0.0F) {
          /* Sum: '<S679>/Add1' incorporates:
           *  Merge: '<S677>/ Merge '
           *  SignalConversion generated from: '<S678>/ChargeCurrentReq'
           */
          test3_B.ChargeCurrentReq = 0.0F;
        }

        /* Update for DiscreteIntegrator: '<S678>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S678>/Constant'
         *  Gain: '<S678>/KP2'
         *  Inport: '<Root>/Pack_Current'
         *  Sum: '<S678>/Add'
         */
        test3_DW.DiscreteTimeIntegrator_DSTATE_d += (0.0F -
          (-test3_U.Pack_Current)) * 0.01F;
      }
      break;

     case test3_IN_PreChargeFaultCheck:
      break;

     case test3_IN_PreCharge_Mode:
      /* Outport: '<Root>/Charge_Complete' */
      /* Outport: '<Root>/MinCellVolt' */
      test3_Y.Charge_Complete = 0.0;
      if (test3_DW.temporalCounter_i2 >= 30000.0F) {
        test3_DW.is_Charginig = test3_IN_PreChargeFaultCheck;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.PreChargeFault = true;

        /* Merge: '<S677>/ Merge ' */
        test3_B.ChargeCurrentReq = 0.0F;

        /* Outport: '<Root>/ChargeVoltReq' */
        test3_Y.ChargeVoltReq = 0.0F;
      } else if (test3_B.i1 != Charging) {
        test3_DW.is_Charginig = test3_IN_Init_Mode;

        /* Outport: '<Root>/ChargeModeReq' */
        test3_Y.ChargeModeReq = Init_Mode;

        /* Merge: '<S677>/ Merge ' */
        test3_B.ChargeCurrentReq = 0.0F;

        /* Outport: '<Root>/ChargeVoltReq' */
        test3_Y.ChargeVoltReq = 0.0F;
      } else if (test3_Y.MinCellVolt > 2.5F) {
        test3_DW.is_Charginig = test3_IN_CC_Mode;

        /* Outport: '<Root>/ChargeModeReq' */
        test3_Y.ChargeModeReq = CC_Mode;
      } else {
        /* Outport: '<Root>/ChargeVoltReq' incorporates:
         *  Outport: '<Root>/MaxCellVolt'
         *  Outport: '<Root>/SumOfVoltages'
         */
        test3_Y.ChargeVoltReq = (4.2F - test3_Y.MaxCellVolt) * 96.0F +
          test3_Y.SumOfVoltages;

        /* Sum: '<S679>/Add1' incorporates:
         *  Constant: '<S679>/Constant'
         *  DiscreteIntegrator: '<S679>/Discrete-Time Integrator'
         *  Gain: '<S679>/KP'
         *  Gain: '<S679>/KP2'
         *  Inport: '<Root>/Pack_Current'
         *  Sum: '<S679>/Add'
         */
        test3_B.ChargeCurrentReq = (2.8125F - (-test3_U.Pack_Current)) * 0.8F +
          test3_DW.DiscreteTimeIntegrator_DSTATE;

        /* Saturate: '<S679>/Saturation' */
        if (test3_B.ChargeCurrentReq > 30.0F) {
          /* Sum: '<S679>/Add1' incorporates:
           *  Merge: '<S677>/ Merge '
           *  SignalConversion generated from: '<S679>/ChargeCurrentReq'
           */
          test3_B.ChargeCurrentReq = 30.0F;
        } else if (test3_B.ChargeCurrentReq < 0.0F) {
          /* Sum: '<S679>/Add1' incorporates:
           *  Merge: '<S677>/ Merge '
           *  SignalConversion generated from: '<S679>/ChargeCurrentReq'
           */
          test3_B.ChargeCurrentReq = 0.0F;
        }

        /* Update for DiscreteIntegrator: '<S679>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S679>/Constant'
         *  Gain: '<S679>/KP2'
         *  Inport: '<Root>/Pack_Current'
         *  Sum: '<S679>/Add'
         */
        test3_DW.DiscreteTimeIntegrator_DSTATE += (2.8125F -
          (-test3_U.Pack_Current)) * 0.01F;
      }
      break;

     default:
      /* Outport: '<Root>/Charge_Complete' */
      /* case IN_SOC_Detect: */
      test3_Y.Charge_Complete = 1.0;

      /* Outport: '<Root>/SOC_New' */
      test3_Y.SOC_New = 100.0;
      test3_DW.is_Charginig = test3_IN_Init_Mode;

      /* Outport: '<Root>/ChargeModeReq' */
      test3_Y.ChargeModeReq = Init_Mode;

      /* Merge: '<S677>/ Merge ' */
      test3_B.ChargeCurrentReq = 0.0F;

      /* Outport: '<Root>/ChargeVoltReq' */
      test3_Y.ChargeVoltReq = 0.0F;
      break;
    }
  }
}

/* Function for Chart: '<S97>/Chart' */
static void test3_FaultMonitoring(void)
{
  boolean_T e_out;
  switch (test3_DW.is_MonitorFault_In) {
   case test3_IN_BMBFault:
   case test3_IN_CAN_VCU_Fault:
   case test3_IN_LowSOC:
    break;

   case test3_IN_InputPowerFault:
    test3_DW.durationCounter_2 = 0L;
    test3_DW.durationCounter_1_p = 0L;
    test3_DW.is_MonitorFault_In = test3_IN_NoInputFault;
    test3_DW.PreContact = 0.0;
    break;

   case test3_IN_MemoryFault:
    test3_DW.durationCounter_2 = 0L;
    test3_DW.durationCounter_1_p = 0L;
    test3_DW.is_MonitorFault_In = test3_IN_NoInputFault;
    test3_DW.PreContact = 0.0;
    break;

   case test3_IN_NoInputFault:
    /* Inport: '<Root>/ShortCircuitFault' incorporates:
     *  Inport: '<Root>/SOC'
     */
    if (test3_U.ShortCircuitFault == 1.0F) {
      test3_DW.is_MonitorFault_In = test3_IN_ShortCircuitFault;
      test3_DW.PreContact = 1.0;
      test3_DW.FaultPresent = true;

      /* Outport: '<Root>/Faults' */
      test3_Y.Faults_d.ShortCircuitFault = true;
    } else {
      if (!(test3_U.SOC <= 0.0F)) {
        test3_DW.durationCounter_2 = 0L;
      }

      /* Inport: '<Root>/StateRequest' incorporates:
       *  Inport: '<Root>/BMBFault'
       *  Inport: '<Root>/CurrentSensorFault'
       *  Inport: '<Root>/InputPowerFault'
       *  Inport: '<Root>/MemoryFault'
       *  Outport: '<Root>/Faults'
       */
      if ((test3_DW.durationCounter_2 > 200L) && (test3_U.StateRequest ==
           Driving)) {
        test3_DW.is_MonitorFault_In = test3_IN_LowSOC;
        test3_DW.PreContact = 1.0;
        test3_DW.FaultPresent = true;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.LowSOC = true;
      } else if ((test3_U.InputPowerFault == 1.0F) &&
                 (!test3_Y.Faults_d.InputPowerFault)) {
        test3_DW.is_MonitorFault_In = test3_IN_InputPowerFault;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.InputPowerFault = true;
      } else if ((test3_U.MemoryFault == 1.0F) && (!test3_Y.Faults_d.MemoryFault))
      {
        test3_DW.is_MonitorFault_In = test3_IN_MemoryFault;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.MemoryFault = true;
      } else if ((test3_U.CurrentSensorFault == 1.0F) &&
                 (!test3_Y.Faults_d.CurrentSensor)) {
        test3_DW.is_MonitorFault_In = test3_IN_SensorFaut;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.CurrentSensor = true;
      } else {
        if (!(test3_U.BMBFault == 1.0F)) {
          test3_DW.durationCounter_1_p = 0L;
        }

        if (test3_DW.durationCounter_1_p > 200L) {
          test3_DW.is_MonitorFault_In = test3_IN_BMBFault;
          test3_DW.PreContact = 1.0;
          test3_DW.FaultPresent = true;

          /* Outport: '<Root>/Faults' */
          test3_Y.Faults_d.BMBFault = true;
        }
      }
    }

    /* End of Inport: '<Root>/ShortCircuitFault' */
    break;

   case test3_IN_SensorFaut:
    test3_DW.durationCounter_2 = 0L;
    test3_DW.durationCounter_1_p = 0L;
    test3_DW.is_MonitorFault_In = test3_IN_NoInputFault;
    test3_DW.PreContact = 0.0;
    break;

   default:
    /* case IN_ShortCircuitFault: */
    break;
  }

  switch (test3_DW.is_MonitorCurrLim) {
   case test3_IN_NoCurrLimFault:
    /* Inport: '<Root>/Pack_Current' incorporates:
     *  Outport: '<Root>/ChargeCurrentLimit'
     */
    test3_B.f = -(test3_U.Pack_Current / test3_Y.ChargeCurrentLimit);
    if (!(test3_B.f > 1.1)) {
      test3_DW.durationCounter_5 = 0L;
    }

    if (test3_DW.durationCounter_5 > 6000L) {
      e_out = true;
    } else {
      if (!(test3_B.f > 1.5F)) {
        test3_DW.durationCounter_6 = 0L;
      }

      if (test3_DW.durationCounter_6 > 3000L) {
        e_out = true;
      } else {
        if (!(test3_B.f > 2.0F)) {
          test3_DW.durationCounter_7 = 0L;
        }

        if (test3_DW.durationCounter_7 > 1000L) {
          e_out = true;
        } else {
          if (!(test3_B.f > 3.0F)) {
            test3_DW.durationCounter_8 = 0L;
          }

          e_out = (test3_DW.durationCounter_8 > 300L);
        }
      }
    }

    if (e_out) {
      test3_DW.is_MonitorCurrLim = test3_IN_OverChargeCurrentFault;
      test3_DW.PreContact = 1.0;
      test3_DW.FaultPresent = true;

      /* Outport: '<Root>/Faults' */
      test3_Y.Faults_d.OverChargeCurrent = true;
    } else {
      /* Inport: '<Root>/Pack_Current' incorporates:
       *  Outport: '<Root>/DischargeCurrentLimit'
       */
      test3_B.f = test3_U.Pack_Current / test3_Y.DischargeCurrentLimit;
      if (!(test3_B.f > 1.1)) {
        test3_DW.durationCounter_1_k = 0L;
      }

      if (test3_DW.durationCounter_1_k > 6000L) {
        e_out = true;
      } else {
        if (!(test3_B.f > 1.5F)) {
          test3_DW.durationCounter_2_a = 0L;
        }

        if (test3_DW.durationCounter_2_a > 3000L) {
          e_out = true;
        } else {
          if (!(test3_B.f > 2.0F)) {
            test3_DW.durationCounter_3 = 0L;
          }

          if (test3_DW.durationCounter_3 > 1000L) {
            e_out = true;
          } else {
            if (!(test3_B.f > 3.0F)) {
              test3_DW.durationCounter_4 = 0L;
            }

            e_out = (test3_DW.durationCounter_4 > 300L);
          }
        }
      }

      if (e_out) {
        test3_DW.is_MonitorCurrLim = te_IN_OverDischargeCurrentFault;
        test3_DW.FaultPresent = true;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.OverDischargeCurrent = true;
      }
    }
    break;

   case test3_IN_OverChargeCurrentFault:
    break;

   default:
    /* case IN_OverDischargeCurrentFault: */
    break;
  }

  switch (test3_DW.is_MonitorCellVoltage) {
   case test3_IN_NoCellVoltFault:
    /* Outport: '<Root>/MaxCellVolt' */
    /* Outport: '<Root>/MinCellVolt' */
    if (!(test3_Y.MaxCellVolt >= 4.37F)) {
      test3_DW.durationCounter_1_c = 0L;
    }

    /* End of Outport: '<Root>/MaxCellVolt' */
    if (test3_DW.durationCounter_1_c > 250L) {
      test3_DW.is_MonitorCellVoltage = test3_IN_OverVoltageFault;
      test3_DW.PreContact = 1.0;
      test3_DW.FaultPresent = true;

      /* Outport: '<Root>/Faults' */
      test3_Y.Faults_d.OverVolt = true;
    } else {
      if (!(test3_Y.MinCellVolt <= 2.5F)) {
        test3_DW.durationCounter_2_aa = 0L;
      }

      /* Inport: '<Root>/StateRequest' */
      /* Outport: '<Root>/Faults' incorporates:
       *  Outport: '<Root>/MinCellVolt'
       */
      test3_B.i_c = test3_U.StateRequest;
      if ((test3_DW.durationCounter_2_aa > 250L) && (test3_B.i_c == Driving)) {
        test3_DW.is_MonitorCellVoltage = test3_IN_UnderVoltageFault;
        test3_DW.PreContact = 1.0;
        test3_DW.FaultPresent = true;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.UnderVolt = true;
      } else if ((test3_Y.MinCellVolt <= 2.5F) && (test3_B.i_c == Charging) &&
                 test3_Y.Faults_d.PreChargeFault) {
        test3_DW.is_MonitorCellVoltage = te_IN_PreCharge_UnderVolt_Fault;
        test3_DW.PreContact = 1.0;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.UnderVolt = true;
        test3_DW.FaultPresent = true;
      }
    }
    break;

   case test3_IN_OverVoltageFault:
   case te_IN_PreCharge_UnderVolt_Fault:
    break;

   default:
    /* case IN_UnderVoltageFault: */
    break;
  }

  switch (test3_DW.is_MonitorCellTemp) {
   case test3_IN_HighTemperatureFault:
   case test3_IN_LowTemperatureFault:
    break;

   default:
    /* Outport: '<Root>/MaxCellTemp' */
    /* Outport: '<Root>/MinCellTemp' */
    /* case IN_NoCellTempFault: */
    if (!(test3_Y.MaxCellTemp >= 328.15F)) {
      test3_DW.durationCounter_1_p1 = 0L;
    }

    /* End of Outport: '<Root>/MaxCellTemp' */
    if (test3_DW.durationCounter_1_p1 > 300L) {
      test3_DW.is_MonitorCellTemp = test3_IN_HighTemperatureFault;
      test3_DW.PreContact = 1.0;
      test3_DW.FaultPresent = true;

      /* Outport: '<Root>/Faults' */
      test3_Y.Faults_d.HighTemp = true;
    } else {
      if (!(test3_Y.MinCellTemp <= 253.15F)) {
        test3_DW.durationCounter_2_h = 0L;
      }

      if (test3_DW.durationCounter_2_h > 300L) {
        test3_DW.is_MonitorCellTemp = test3_IN_LowTemperatureFault;
        test3_DW.PreContact = 1.0;
        test3_DW.FaultPresent = true;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.LowTemp = true;
      }
    }

    /* End of Outport: '<Root>/MinCellTemp' */
    break;
  }
}

/* Function for Chart: '<S97>/Chart' */
static void test3_ChargerContactorState(void)
{
  if (test3_DW.is_ChargerContactorState == 1U) {
    /* Inport: '<Root>/StateRequest' */
    if ((test3_U.StateRequest == Standby) || test3_DW.FaultPresent) {
      test3_DW.is_CloseChgrContactors = test3_IN_NO_ACTIVE_CHILD_k;
      test3_DW.is_ChargerContactorState = test3_IN_OpenChgrContactors;
      test3_DW.ChrgCntctState = Init;
      test3_DW.is_OpenChgrContactors = test3_IN_Ready;

      /* Merge: '<S677>/ Merge ' */
      test3_B.ChargeCurrentReq = 0.0F;

      /* Outport: '<Root>/DischargeCurrentReq' */
      test3_Y.DischargeCurrentReq = 0.0F;
    } else {
      switch (test3_DW.is_CloseChgrContactors) {
       case test3_IN_CloseNegCntct:
        if ((uint32_T)(test3_DW.temporalCounter_i5 * 10LL) >= 200UL) {
          test3_DW.is_CloseChgrContactors = test3_IN_ClosePreChrgRly_k;
          test3_DW.temporalCounter_i5 = 0UL;
          test3_B.PreChargeRelayChgrCmd = true;
        } else {
          test3_B.NegContactorChgrCmd = true;
        }
        break;

       case test3_IN_ClosePosCntct:
        if ((uint32_T)(test3_DW.temporalCounter_i5 * 10LL) >= 400UL) {
          test3_DW.is_CloseChgrContactors = test3_IN_OpenPreChrgRly_k;
          test3_B.PreChargeRelayChgrCmd = false;
          test3_DW.ChrgCntctState = Close;
        } else {
          test3_B.PosContactorChgrCmd = true;
        }
        break;

       case test3_IN_ClosePreChrgRly_k:
        if (test3_DW.temporalCounter_i5 >= 400UL) {
          test3_DW.is_CloseChgrContactors = test3_IN_ClosePosCntct;
          test3_DW.temporalCounter_i5 = 0UL;
          test3_B.PosContactorChgrCmd = true;
        } else {
          test3_B.PreChargeRelayChgrCmd = true;
        }
        break;

       default:
        /* case IN_OpenPreChrgRly: */
        test3_B.PreChargeRelayChgrCmd = false;
        test3_DW.ChrgCntctState = Close;
        break;
      }
    }

    /* Inport: '<Root>/StateRequest' */
    /* case IN_OpenChgrContactors: */
  } else if ((test3_U.StateRequest == Charging) && (test3_DW.InvtrCntctState ==
              Open) && (!test3_DW.FaultPresent)) {
    test3_DW.is_OpenChgrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_ChargerContactorState = test3_IN_CloseChgrContactors;
    test3_DW.ChrgCntctState = Init;
    test3_DW.is_CloseChgrContactors = test3_IN_CloseNegCntct;
    test3_DW.temporalCounter_i5 = 0UL;
    test3_B.NegContactorChgrCmd = true;
  } else {
    switch (test3_DW.is_OpenChgrContactors) {
     case test3_IN_ClosePreChrgRly:
      if ((uint32_T)(test3_DW.temporalCounter_i5 * 10LL) >= 200UL) {
        test3_DW.is_OpenChgrContactors = test3_IN_OpenPosCntct;
        test3_DW.temporalCounter_i5 = 0UL;
        test3_B.PosContactorChgrCmd = false;
      } else {
        test3_B.PreChargeRelayChgrCmd = true;
      }
      break;

     case test3_IN_OpenNegCntct:
      test3_B.NegContactorChgrCmd = false;
      test3_DW.ChrgCntctState = Open;

      /* Outport: '<Root>/Faults' */
      test3_Y.Faults_d.Charger = false;
      break;

     case test3_IN_OpenPosCntct:
      if ((uint32_T)(test3_DW.temporalCounter_i5 * 10LL) >= 400UL) {
        test3_DW.is_OpenChgrContactors = test3_IN_OpenPreChrgRly;
        test3_DW.temporalCounter_i5 = 0UL;
        test3_B.PreChargeRelayChgrCmd = false;
      } else {
        test3_B.PosContactorChgrCmd = false;
      }
      break;

     case test3_IN_OpenPos_NegCntct1:
      if ((uint32_T)(test3_DW.temporalCounter_i5 * 10LL) >= 200UL) {
        test3_DW.is_OpenChgrContactors = test3_IN_OpenNegCntct;
        test3_B.NegContactorChgrCmd = false;
        test3_DW.ChrgCntctState = Open;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.Charger = false;
      } else {
        test3_B.PosContactorInvtrCmd = false;
        test3_B.NegContactorInvtrCmd = false;
      }
      break;

     case test3_IN_OpenPreChrgRly:
      if ((uint32_T)(test3_DW.temporalCounter_i5 * 10LL) >= 200UL) {
        test3_DW.is_OpenChgrContactors = test3_IN_OpenNegCntct;
        test3_B.NegContactorChgrCmd = false;
        test3_DW.ChrgCntctState = Open;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.Charger = false;
      } else {
        test3_B.PreChargeRelayChgrCmd = false;
      }
      break;

     default:
      /* case IN_Ready: */
      if (test3_DW.PreContact == 1.0) {
        test3_DW.is_OpenChgrContactors = test3_IN_ClosePreChrgRly;
        test3_DW.temporalCounter_i5 = 0UL;
        test3_B.PreChargeRelayChgrCmd = true;
      } else if (test3_DW.PreContact == 0.0) {
        test3_DW.is_OpenChgrContactors = test3_IN_OpenPos_NegCntct1;
        test3_DW.temporalCounter_i5 = 0UL;
        test3_B.PosContactorInvtrCmd = false;
        test3_B.NegContactorInvtrCmd = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S97>/Chart' */
static void test3_InverterContactorState(void)
{
  if (test3_DW.is_InverterContactorState == 1U) {
    /* Inport: '<Root>/StateRequest' */
    if ((test3_U.StateRequest == Standby) || test3_DW.FaultPresent) {
      test3_DW.is_CloseInvtrContactors = test3_IN_NO_ACTIVE_CHILD_k;
      test3_DW.is_InverterContactorState = test3_IN_OpenInvtrContactors;
      test3_DW.InvtrCntctState = Init;
      test3_DW.is_OpenInvtrContactors = test3_IN_Ready;

      /* Merge: '<S677>/ Merge ' */
      test3_B.ChargeCurrentReq = 0.0F;

      /* Outport: '<Root>/DischargeCurrentReq' */
      test3_Y.DischargeCurrentReq = 0.0F;
    } else {
      switch (test3_DW.is_CloseInvtrContactors) {
       case test3_IN_CloseNegCntct:
        if ((uint32_T)(test3_DW.temporalCounter_i3 * 10LL) >= 200UL) {
          test3_DW.is_CloseInvtrContactors = test3_IN_ClosePreChrgRly_k;
          test3_DW.temporalCounter_i3 = 0UL;
          test3_B.PreChargeRelayInvtrCmd = true;
        } else {
          test3_B.NegContactorInvtrCmd = true;
        }
        break;

       case test3_IN_ClosePosCntct:
        if ((uint32_T)(test3_DW.temporalCounter_i3 * 10LL) >= 400UL) {
          test3_DW.is_CloseInvtrContactors = test3_IN_OpenPreChrgRly_k;
          test3_B.PreChargeRelayInvtrCmd = false;
          test3_DW.InvtrCntctState = Close;
        } else {
          test3_B.PosContactorInvtrCmd = true;
        }
        break;

       case test3_IN_ClosePreChrgRly_k:
        if (test3_DW.temporalCounter_i3 >= 400UL) {
          test3_DW.is_CloseInvtrContactors = test3_IN_ClosePosCntct;
          test3_DW.temporalCounter_i3 = 0UL;
          test3_B.PosContactorInvtrCmd = true;
        } else {
          test3_B.PreChargeRelayInvtrCmd = true;
        }
        break;

       default:
        /* case IN_OpenPreChrgRly: */
        test3_B.PreChargeRelayInvtrCmd = false;
        test3_DW.InvtrCntctState = Close;
        break;
      }
    }

    /* Inport: '<Root>/StateRequest' */
    /* case IN_OpenInvtrContactors: */
  } else if ((test3_U.StateRequest == Driving) && (test3_DW.ChrgCntctState ==
              Open) && (!test3_DW.FaultPresent)) {
    test3_DW.is_OpenInvtrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_InverterContactorState = test3_IN_CloseInvtrContactors;
    test3_DW.InvtrCntctState = Init;
    test3_DW.is_CloseInvtrContactors = test3_IN_CloseNegCntct;
    test3_DW.temporalCounter_i3 = 0UL;
    test3_B.NegContactorInvtrCmd = true;
  } else {
    switch (test3_DW.is_OpenInvtrContactors) {
     case test3_IN_ClosePreChrgRly:
      if ((uint32_T)(test3_DW.temporalCounter_i3 * 10LL) >= 200UL) {
        test3_DW.is_OpenInvtrContactors = test3_IN_OpenPosCntct;
        test3_DW.temporalCounter_i3 = 0UL;
        test3_B.PosContactorInvtrCmd = false;
      } else {
        test3_B.PreChargeRelayInvtrCmd = true;
      }
      break;

     case test3_IN_OpenNegCntct:
      test3_B.NegContactorInvtrCmd = false;
      test3_DW.InvtrCntctState = Open;

      /* Outport: '<Root>/Faults' */
      test3_Y.Faults_d.Inverter = false;
      break;

     case test3_IN_OpenPosCntct:
      if ((uint32_T)(test3_DW.temporalCounter_i3 * 10LL) >= 200UL) {
        test3_DW.is_OpenInvtrContactors = test3_IN_OpenPreChrgRly;
        test3_DW.temporalCounter_i3 = 0UL;
        test3_B.PreChargeRelayInvtrCmd = false;
      } else {
        test3_B.PosContactorInvtrCmd = false;
      }
      break;

     case test3_IN_OpenPos_NegCntct1:
      if ((uint32_T)(test3_DW.temporalCounter_i3 * 10LL) >= 200UL) {
        test3_DW.is_OpenInvtrContactors = test3_IN_OpenNegCntct;
        test3_B.NegContactorInvtrCmd = false;
        test3_DW.InvtrCntctState = Open;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.Inverter = false;
      } else {
        test3_B.PosContactorInvtrCmd = false;
        test3_B.NegContactorInvtrCmd = false;
      }
      break;

     case test3_IN_OpenPreChrgRly:
      if ((uint32_T)(test3_DW.temporalCounter_i3 * 10LL) >= 200UL) {
        test3_DW.is_OpenInvtrContactors = test3_IN_OpenNegCntct;
        test3_B.NegContactorInvtrCmd = false;
        test3_DW.InvtrCntctState = Open;

        /* Outport: '<Root>/Faults' */
        test3_Y.Faults_d.Inverter = false;
      } else {
        test3_B.PreChargeRelayInvtrCmd = false;
      }
      break;

     default:
      /* case IN_Ready: */
      if (test3_DW.PreContact == 1.0) {
        test3_DW.is_OpenInvtrContactors = test3_IN_ClosePreChrgRly;
        test3_DW.temporalCounter_i3 = 0UL;
        test3_B.PreChargeRelayInvtrCmd = true;
      } else if (test3_DW.PreContact == 0.0) {
        test3_DW.is_OpenInvtrContactors = test3_IN_OpenPos_NegCntct1;
        test3_DW.temporalCounter_i3 = 0UL;
        test3_B.PosContactorInvtrCmd = false;
        test3_B.NegContactorInvtrCmd = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<S97>/Chart' */
static void test3_Balancing(const real32_T TmpSignalConversionAtSFunctionI[96])
{
  boolean_T exitg1;
  if (test3_DW.is_Balancing == 1U) {
    /* Outport: '<Root>/BMS_State' incorporates:
     *  Inport: '<Root>/Pack_Current'
     *  Inport: '<Root>/SOC'
     *  Outport: '<Root>/BalCmd'
     *  Outport: '<Root>/ChargeModeReq'
     *  Outport: '<Root>/MaxCellVolt'
     *  Outport: '<Root>/MinCellVolt'
     */
    if ((test3_Y.BMS_State == BMS_Charging) && (test3_U.SOC > 60.0F) &&
        (test3_DW.temporalCounter_i4 >= 2000UL) && (test3_DW.DeltaCellVolt >
         0.01F) && ((real32_T)fabs(test3_U.Pack_Current) <= 10.0F) &&
        (test3_Y.ChargeModeReq != FastCharge_Mode)) {
      test3_DW.is_Balancing = test3_IN_BalancingON;
      test3_DW.DeltaCellVolt = test3_Y.MaxCellVolt - test3_Y.MinCellVolt;
      test3_DW.is_BalancingON = test3_IN_BalActive;
      test3_DW.temporalCounter_i4 = 0UL;
      for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
        test3_Y.BalCmd[test3_B.i_cx] = false;
      }
    } else {
      test3_DW.DeltaCellVolt = test3_Y.MaxCellVolt - test3_Y.MinCellVolt;
    }

    /* Outport: '<Root>/BMS_State' incorporates:
     *  Inport: '<Root>/Pack_Current'
     *  Inport: '<Root>/SOC'
     *  Outport: '<Root>/BalCmd'
     *  Outport: '<Root>/ChargeModeReq'
     *  Outport: '<Root>/MaxCellVolt'
     *  Outport: '<Root>/MinCellVolt'
     */
    /* case IN_BalancingON: */
  } else if ((test3_Y.BMS_State != BMS_Charging) || (test3_Y.ChargeModeReq ==
              FastCharge_Mode) || (test3_U.SOC <= 54.0F) || ((real32_T)fabs
              (test3_U.Pack_Current) > 10.0F)) {
    test3_DW.is_BalancingON = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_Balancing = test3_IN_BalancingOFF;
    test3_DW.temporalCounter_i4 = 0UL;
    test3_DW.flgBalCompl = false;
    for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
      test3_B.BalCmd[test3_B.i_cx] = false;
      test3_Y.BalCmd[test3_B.i_cx] = false;
    }

    test3_DW.DeltaCellVolt = test3_Y.MaxCellVolt - test3_Y.MinCellVolt;
  } else {
    test3_DW.DeltaCellVolt = test3_Y.MaxCellVolt - test3_Y.MinCellVolt;
    switch (test3_DW.is_BalancingON) {
     case test3_IN_BalActive:
      if (test3_DW.temporalCounter_i4 >= 40UL) {
        test3_DW.is_BalancingON = test3_IN_BalActive1;
        test3_DW.temporalCounter_i4 = 0UL;
        for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
          test3_Y.BalCmd[test3_B.i_cx] = test3_B.BalCmd[test3_B.i_cx];
        }
      } else if (test3_DW.flgBalCompl) {
        test3_DW.is_BalancingON = test3_IN_BalNotActive;
        test3_DW.temporalCounter_i4 = 0UL;
      } else {
        for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
          test3_B.BalCmd[test3_B.i_cx] =
            (TmpSignalConversionAtSFunctionI[test3_B.i_cx] - test3_Y.MinCellVolt
             > 0.005F);
        }

        test3_DW.flgBalCompl = true;
        test3_B.i_cx = 0;
        exitg1 = false;
        while ((!exitg1) && (test3_B.i_cx < 96)) {
          if (test3_B.BalCmd[test3_B.i_cx]) {
            test3_DW.flgBalCompl = false;
            exitg1 = true;
          } else {
            test3_B.i_cx++;
          }
        }
      }
      break;

     case test3_IN_BalActive1:
      if (test3_DW.temporalCounter_i4 >= 300UL) {
        test3_DW.is_BalancingON = test3_IN_BalActive;
        test3_DW.temporalCounter_i4 = 0UL;
        for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
          test3_Y.BalCmd[test3_B.i_cx] = false;
        }
      } else {
        for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
          test3_Y.BalCmd[test3_B.i_cx] = test3_B.BalCmd[test3_B.i_cx];
        }
      }
      break;

     default:
      /* case IN_BalNotActive: */
      if ((test3_DW.temporalCounter_i4 >= 3000UL) && (test3_DW.DeltaCellVolt >
           0.01F)) {
        test3_DW.is_BalancingON = test3_IN_BalActive;
        test3_DW.temporalCounter_i4 = 0UL;
        for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
          test3_Y.BalCmd[test3_B.i_cx] = false;
        }
      } else if (test3_DW.temporalCounter_i4 >= 6000UL) {
        test3_DW.is_BalancingON = test3_IN_NO_ACTIVE_CHILD_k;
        test3_DW.is_Balancing = test3_IN_BalancingOFF;
        test3_DW.temporalCounter_i4 = 0UL;
        test3_DW.flgBalCompl = false;
        for (test3_B.i_cx = 0; test3_B.i_cx < 96; test3_B.i_cx++) {
          test3_B.BalCmd[test3_B.i_cx] = false;
          test3_Y.BalCmd[test3_B.i_cx] = false;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S97>/Chart' */
static void test3_enter_internal_Main(void)
{
  test3_DW.is_MainStateMachine = test3_IN_Standby;

  /* Outport: '<Root>/BMS_State' */
  test3_Y.BMS_State = BMS_Standby;

  /* Outport: '<Root>/ChargeVoltReq' */
  test3_Y.ChargeVoltReq = 0.0F;

  /* Outport: '<Root>/ChargeModeReq' */
  test3_Y.ChargeModeReq = Init_Mode;

  /* Outport: '<Root>/Charge_Complete' */
  test3_Y.Charge_Complete = 0.0;

  /* Outport: '<Root>/Faults' */
  test3_Y.Faults_d.CurrentSensor = false;
  test3_Y.Faults_d.InputPowerFault = false;
  test3_Y.Faults_d.BMBFault = false;
  test3_Y.Faults_d.ShortCircuitFault = false;
  test3_Y.Faults_d.MemoryFault = false;
  test3_Y.Faults_d.CAN_VCU_Fault = false;
  test3_DW.durationCounter_2 = 0L;
  test3_DW.durationCounter_1_p = 0L;
  test3_DW.is_MonitorFault_In = test3_IN_NoInputFault;
  test3_DW.PreContact = 0.0;

  /* Outport: '<Root>/Faults' */
  test3_Y.Faults_d.OverChargeCurrent = false;
  test3_Y.Faults_d.OverDischargeCurrent = false;
  test3_DW.durationCounter_8 = 0L;
  test3_DW.durationCounter_7 = 0L;
  test3_DW.durationCounter_6 = 0L;
  test3_DW.durationCounter_5 = 0L;
  test3_DW.durationCounter_4 = 0L;
  test3_DW.durationCounter_3 = 0L;
  test3_DW.durationCounter_2_a = 0L;
  test3_DW.durationCounter_1_k = 0L;
  test3_DW.is_MonitorCurrLim = test3_IN_NoCurrLimFault;

  /* Outport: '<Root>/Faults' */
  test3_Y.Faults_d.OverVolt = false;
  test3_Y.Faults_d.UnderVolt = false;
  test3_Y.Faults_d.VoltSensor = false;
  test3_Y.Faults_d.BalEn = false;
  test3_Y.Faults_d.PreChargeFault = false;
  test3_DW.durationCounter_2_aa = 0L;
  test3_DW.durationCounter_1_c = 0L;
  test3_DW.is_MonitorCellVoltage = test3_IN_NoCellVoltFault;
  test3_DW.FaultPresent = false;

  /* Outport: '<Root>/Faults' */
  test3_Y.Faults_d.HighTemp = false;
  test3_Y.Faults_d.LowTemp = false;
  test3_DW.durationCounter_2_h = 0L;
  test3_DW.durationCounter_1_p1 = 0L;
  test3_DW.is_MonitorCellTemp = test3_IN_NoCellTempFault;

  /* Outport: '<Root>/Faults' */
  test3_Y.Faults_d.Charger = false;
  test3_DW.is_ChargerContactorState = test3_IN_OpenChgrContactors;
  test3_DW.ChrgCntctState = Init;
  test3_DW.is_OpenChgrContactors = test3_IN_Ready;

  /* Outport: '<Root>/Faults' */
  test3_Y.Faults_d.Inverter = false;
  test3_DW.is_InverterContactorState = test3_IN_OpenInvtrContactors;
  test3_DW.InvtrCntctState = Init;
  test3_DW.is_OpenInvtrContactors = test3_IN_Ready;

  /* Merge: '<S677>/ Merge ' */
  test3_B.ChargeCurrentReq = 0.0F;

  /* Outport: '<Root>/DischargeCurrentReq' */
  test3_Y.DischargeCurrentReq = 0.0F;
  test3_DW.is_test = test3_IN_test1;
  test3_DW.temporalCounter_i1_h = 0UL;

  /* Outport: '<Root>/led' */
  test3_Y.led = 0.0;
  test3_DW.is_Balancing = test3_IN_BalancingOFF;
  test3_DW.temporalCounter_i4 = 0UL;
  test3_DW.flgBalCompl = false;
  for (test3_B.i_k = 0; test3_B.i_k < 96; test3_B.i_k++) {
    test3_B.BalCmd[test3_B.i_k] = false;

    /* Outport: '<Root>/BalCmd' */
    test3_Y.BalCmd[test3_B.i_k] = false;
  }

  /* Outport: '<Root>/MaxCellVolt' incorporates:
   *  Outport: '<Root>/MinCellVolt'
   */
  test3_DW.DeltaCellVolt = test3_Y.MaxCellVolt - test3_Y.MinCellVolt;
}

/* Function for Chart: '<S97>/Chart' */
static void test3_Main(const real32_T TmpSignalConversionAtSFunctio_g[16], const
  real32_T TmpSignalConversionAtSFunctionI[96])
{
  /* Inport: '<Root>/Reset' */
  if (test3_U.Reset == 1.0F) {
    test3_DW.is_BalancingON = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_CloseInvtrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_CloseChgrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_exit_internal_Charginig();
    test3_enter_internal_Main();
  } else {
    switch (test3_DW.is_MainStateMachine) {
     case test3_IN_Charginig:
      test3_Charginig();
      break;

     case test3_IN_Driving:
      if (test3_DW.FaultPresent) {
        test3_DW.is_MainStateMachine = test3_IN_Fault;

        /* Outport: '<Root>/BMS_State' */
        test3_Y.BMS_State = BMS_Fault;

        /* Merge: '<S677>/ Merge ' */
        test3_B.ChargeCurrentReq = 0.0F;

        /* Outport: '<Root>/DischargeCurrentReq' */
        test3_Y.DischargeCurrentReq = 0.0F;

        /* Outport: '<Root>/ChargeVoltReq' */
        test3_Y.ChargeVoltReq = 0.0F;
      } else {
        /* Inport: '<Root>/StateRequest' */
        test3_B.i_m = test3_U.StateRequest;
        if ((test3_B.i_m != Driving) && (test3_DW.InvtrCntctState == Init)) {
          test3_DW.is_MainStateMachine = test3_IN_Standby;

          /* Outport: '<Root>/BMS_State' */
          test3_Y.BMS_State = BMS_Standby;

          /* Merge: '<S677>/ Merge ' */
          test3_B.ChargeCurrentReq = 0.0F;

          /* Outport: '<Root>/ChargeVoltReq' */
          test3_Y.ChargeVoltReq = 0.0F;

          /* Outport: '<Root>/ChargeModeReq' */
          test3_Y.ChargeModeReq = Init_Mode;

          /* Outport: '<Root>/Charge_Complete' */
          test3_Y.Charge_Complete = 0.0;
        } else if (test3_B.i_m == Charging) {
          test3_DW.is_MainStateMachine = test3_IN_Charginig;

          /* Outport: '<Root>/BMS_State' */
          test3_Y.BMS_State = BMS_Charging;
          test3_DW.is_Charginig = test3_IN_Init_Mode;

          /* Outport: '<Root>/ChargeModeReq' */
          test3_Y.ChargeModeReq = Init_Mode;

          /* Merge: '<S677>/ Merge ' */
          test3_B.ChargeCurrentReq = 0.0F;

          /* Outport: '<Root>/ChargeVoltReq' */
          test3_Y.ChargeVoltReq = 0.0F;
        } else {
          /* Merge: '<S677>/ Merge ' incorporates:
           *  Outport: '<Root>/ChargeCurrentLimit'
           */
          test3_B.ChargeCurrentReq = test3_Y.ChargeCurrentLimit;

          /* Outport: '<Root>/DischargeCurrentReq' incorporates:
           *  Outport: '<Root>/DischargeCurrentLimit'
           */
          test3_Y.DischargeCurrentReq = test3_Y.DischargeCurrentLimit;
        }
      }
      break;

     case test3_IN_Fault:
      /* Outport: '<Root>/BMS_State' */
      test3_Y.BMS_State = BMS_Fault;

      /* Merge: '<S677>/ Merge ' */
      test3_B.ChargeCurrentReq = 0.0F;

      /* Outport: '<Root>/DischargeCurrentReq' */
      test3_Y.DischargeCurrentReq = 0.0F;

      /* Outport: '<Root>/ChargeVoltReq' */
      test3_Y.ChargeVoltReq = 0.0F;
      break;

     default:
      /* Outport: '<Root>/Charge_Complete' */
      /* case IN_Standby: */
      test3_Y.Charge_Complete = 0.0;
      if (test3_DW.FaultPresent) {
        test3_DW.is_MainStateMachine = test3_IN_Fault;

        /* Outport: '<Root>/BMS_State' */
        test3_Y.BMS_State = BMS_Fault;

        /* Merge: '<S677>/ Merge ' */
        test3_B.ChargeCurrentReq = 0.0F;

        /* Outport: '<Root>/DischargeCurrentReq' */
        test3_Y.DischargeCurrentReq = 0.0F;

        /* Outport: '<Root>/ChargeVoltReq' */
        test3_Y.ChargeVoltReq = 0.0F;
      } else {
        /* Inport: '<Root>/StateRequest' */
        test3_B.i_m = test3_U.StateRequest;
        if ((test3_B.i_m == Charging) && (test3_DW.ChrgCntctState == Close)) {
          test3_DW.is_MainStateMachine = test3_IN_Charginig;

          /* Outport: '<Root>/BMS_State' */
          test3_Y.BMS_State = BMS_Charging;
          test3_DW.is_Charginig = test3_IN_Init_Mode;

          /* Outport: '<Root>/ChargeModeReq' */
          test3_Y.ChargeModeReq = Init_Mode;

          /* Merge: '<S677>/ Merge ' */
          test3_B.ChargeCurrentReq = 0.0F;

          /* Outport: '<Root>/ChargeVoltReq' */
          test3_Y.ChargeVoltReq = 0.0F;
        } else if ((test3_B.i_m == Driving) && (test3_DW.InvtrCntctState ==
                    Close)) {
          test3_DW.is_MainStateMachine = test3_IN_Driving;

          /* Outport: '<Root>/BMS_State' */
          test3_Y.BMS_State = BMS_Driving;
        }
      }
      break;
    }

    test3_FaultMonitoring();
    test3_ChargerContactorState();
    test3_InverterContactorState();
    if (test3_DW.is_test == 1U) {
      test3_DW.is_test = test3_IN_test1;
      test3_DW.temporalCounter_i1_h = 0UL;

      /* Outport: '<Root>/led' */
      test3_Y.led = 0.0;
    } else {
      /* Outport: '<Root>/led' */
      /* case IN_test1: */
      test3_Y.led = 0.0;
      if (test3_DW.temporalCounter_i1_h >= 100000UL) {
        test3_DW.is_test = test3_IN_test;

        /* Outport: '<Root>/led' */
        test3_Y.led = 1.0;
      }
    }

    test3_Balancing(TmpSignalConversionAtSFunctionI);
    for (test3_B.i_m = 0; test3_B.i_m < 96; test3_B.i_m++) {
      /* Outport: '<Root>/MaxCellCmd' incorporates:
       *  Outport: '<Root>/MaxCellVolt'
       */
      test3_Y.MaxCellCmd[test3_B.i_m] =
        (TmpSignalConversionAtSFunctionI[test3_B.i_m] - test3_Y.MaxCellVolt >=
         0.0F);

      /* Outport: '<Root>/MinCellCmd' incorporates:
       *  Outport: '<Root>/MinCellVolt'
       */
      test3_Y.MinCellCmd[test3_B.i_m] =
        (TmpSignalConversionAtSFunctionI[test3_B.i_m] - test3_Y.MinCellVolt <=
         0.0F);
    }

    for (test3_B.i_m = 0; test3_B.i_m < 16; test3_B.i_m++) {
      /* Outport: '<Root>/MaxTempCmd' incorporates:
       *  Outport: '<Root>/MaxCellTemp'
       */
      test3_Y.MaxTempCmd[test3_B.i_m] =
        (TmpSignalConversionAtSFunctio_g[test3_B.i_m] - test3_Y.MaxCellTemp >=
         0.0F);

      /* Outport: '<Root>/MinTempCmd' incorporates:
       *  Outport: '<Root>/MinCellTemp'
       */
      test3_Y.MinTempCmd[test3_B.i_m] =
        (TmpSignalConversionAtSFunctio_g[test3_B.i_m] - test3_Y.MinCellTemp <=
         0.0F);
    }
  }

  /* End of Inport: '<Root>/Reset' */
}

/* Model step function */
void test3_step(void)
{
  g_dsp_internal_SlidingWindo_k_T *obj;
  boolean_T rtb_Compare_ar;
  boolean_T rtb_Compare_aw;
  boolean_T rtb_Compare_b4;
  boolean_T rtb_Compare_cm;
  boolean_T rtb_Compare_da;
  boolean_T rtb_Compare_ee;
  boolean_T rtb_Compare_eo;
  boolean_T rtb_Compare_et;
  boolean_T rtb_Compare_euj;
  boolean_T rtb_Compare_gb;
  boolean_T rtb_Compare_gk;
  boolean_T rtb_Compare_gz;
  boolean_T rtb_Compare_is;
  boolean_T rtb_Compare_l0;
  boolean_T rtb_Compare_lu;
  boolean_T rtb_Compare_mpz;
  boolean_T rtb_Compare_ms;
  boolean_T rtb_Compare_ne;
  boolean_T rtb_Compare_pd;

  /* Inport: '<Root>/CellTemperatures' */
  test3_MovingAverage(test3_U.CellTemperatures[0], &test3_B.MovingAverage,
                      &test3_DW.MovingAverage);
  test3_MovingAverage(test3_U.CellTemperatures[1], &test3_B.MovingAverage1,
                      &test3_DW.MovingAverage1);
  test3_MovingAverage(test3_U.CellTemperatures[2], &test3_B.MovingAverage2,
                      &test3_DW.MovingAverage2);
  test3_MovingAverage(test3_U.CellTemperatures[3], &test3_B.MovingAverage3,
                      &test3_DW.MovingAverage3);
  test3_MovingAverage(test3_U.CellTemperatures[4], &test3_B.MovingAverage4,
                      &test3_DW.MovingAverage4);
  test3_MovingAverage(test3_U.CellTemperatures[5], &test3_B.MovingAverage5,
                      &test3_DW.MovingAverage5);
  test3_MovingAverage(test3_U.CellTemperatures[6], &test3_B.MovingAverage6,
                      &test3_DW.MovingAverage6);
  test3_MovingAverage(test3_U.CellTemperatures[7], &test3_B.MovingAverage7,
                      &test3_DW.MovingAverage7);
  test3_MovingAverage(test3_U.CellTemperatures[8], &test3_B.MovingAverage8,
                      &test3_DW.MovingAverage8);
  test3_MovingAverage(test3_U.CellTemperatures[9], &test3_B.MovingAverage9,
                      &test3_DW.MovingAverage9);
  test3_MovingAverage(test3_U.CellTemperatures[10], &test3_B.MovingAverage10,
                      &test3_DW.MovingAverage10);
  test3_MovingAverage(test3_U.CellTemperatures[11], &test3_B.MovingAverage11,
                      &test3_DW.MovingAverage11);
  test3_MovingAverage(test3_U.CellTemperatures[12], &test3_B.MovingAverage12,
                      &test3_DW.MovingAverage12);
  test3_MovingAverage(test3_U.CellTemperatures[13], &test3_B.MovingAverage13,
                      &test3_DW.MovingAverage13);
  test3_MovingAverage(test3_U.CellTemperatures[14], &test3_B.MovingAverage14,
                      &test3_DW.MovingAverage14);
  test3_MovingAverage(test3_U.CellTemperatures[15], &test3_B.MovingAverage15,
                      &test3_DW.MovingAverage15);

  /* MinMax: '<Root>/Min1' incorporates:
   *  MinMax: '<Root>/Max1'
   */
  test3_B.TmpSignalConversionAtSFunctio_g[0] =
    test3_B.MovingAverage.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[1] =
    test3_B.MovingAverage1.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[2] =
    test3_B.MovingAverage2.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[3] =
    test3_B.MovingAverage3.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[4] =
    test3_B.MovingAverage4.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[5] =
    test3_B.MovingAverage5.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[6] =
    test3_B.MovingAverage6.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[7] =
    test3_B.MovingAverage7.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[8] =
    test3_B.MovingAverage8.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[9] =
    test3_B.MovingAverage9.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[10] =
    test3_B.MovingAverage10.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[11] =
    test3_B.MovingAverage11.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[12] =
    test3_B.MovingAverage12.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[13] =
    test3_B.MovingAverage13.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[14] =
    test3_B.MovingAverage14.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[15] =
    test3_B.MovingAverage15.ChargeCurrentLimit;
  test3_Y.MinCellTemp = test3_B.MovingAverage.ChargeCurrentLimit;

  /* MinMax: '<Root>/Max1' incorporates:
   *  MinMax: '<Root>/Min1'
   */
  test3_Y.MaxCellTemp = test3_B.MovingAverage.ChargeCurrentLimit;
  for (test3_B.i = 0; test3_B.i < 15; test3_B.i++) {
    /* MinMax: '<Root>/Min1' incorporates:
     *  MinMax: '<Root>/Max1'
     */
    test3_B.Max = test3_B.TmpSignalConversionAtSFunctio_g[(int32_T)(test3_B.i +
      1)];
    test3_B.Compare = !rtIsNaNF(test3_B.Max);
    if ((!(test3_Y.MinCellTemp <= test3_B.Max)) && test3_B.Compare) {
      test3_Y.MinCellTemp = test3_B.Max;
    }

    /* MinMax: '<Root>/Max1' */
    if ((!(test3_Y.MaxCellTemp >= test3_B.Max)) && test3_B.Compare) {
      test3_Y.MaxCellTemp = test3_B.Max;
    }
  }

  /* RelationalOperator: '<S104>/Compare' incorporates:
   *  Constant: '<S101>/Time constant'
   *  Constant: '<S104>/Constant'
   *  Sum: '<S101>/Sum1'
   */
  test3_B.Compare = ((real32_T)(0.031830988618379068 - test3_B.Probe[0]) <= 0.0F);

  /* DiscreteIntegrator: '<S106>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING != 0U) {
    test3_DW.Integrator_DSTATE = test3_U.CellVoltages[0];
    if (test3_DW.Integrator_DSTATE >= 6.0F) {
      test3_DW.Integrator_DSTATE = 6.0F;
    } else if (test3_DW.Integrator_DSTATE <= 0.0F) {
      test3_DW.Integrator_DSTATE = 0.0F;
    }
  }

  if (test3_B.Compare || (test3_DW.Integrator_PrevResetState != 0)) {
    test3_DW.Integrator_DSTATE = test3_U.CellVoltages[0];
    if (test3_DW.Integrator_DSTATE >= 6.0F) {
      test3_DW.Integrator_DSTATE = 6.0F;
    } else if (test3_DW.Integrator_DSTATE <= 0.0F) {
      test3_DW.Integrator_DSTATE = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE >= 6.0F) {
    test3_DW.Integrator_DSTATE = 6.0F;
  } else if (test3_DW.Integrator_DSTATE <= 0.0F) {
    test3_DW.Integrator_DSTATE = 0.0F;
  }

  /* RelationalOperator: '<S170>/Compare' incorporates:
   *  Constant: '<S167>/Time constant'
   *  Constant: '<S170>/Constant'
   *  Sum: '<S167>/Sum1'
   */
  test3_B.Compare_p = ((real32_T)(0.031830988618379068 - test3_B.Probe_l[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S172>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_p != 0U) {
    test3_DW.Integrator_DSTATE_a = test3_U.CellVoltages[1];
    if (test3_DW.Integrator_DSTATE_a >= 6.0F) {
      test3_DW.Integrator_DSTATE_a = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_a <= 0.0F) {
      test3_DW.Integrator_DSTATE_a = 0.0F;
    }
  }

  if (test3_B.Compare_p || (test3_DW.Integrator_PrevResetState_p != 0)) {
    test3_DW.Integrator_DSTATE_a = test3_U.CellVoltages[1];
    if (test3_DW.Integrator_DSTATE_a >= 6.0F) {
      test3_DW.Integrator_DSTATE_a = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_a <= 0.0F) {
      test3_DW.Integrator_DSTATE_a = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_a >= 6.0F) {
    test3_DW.Integrator_DSTATE_a = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_a <= 0.0F) {
    test3_DW.Integrator_DSTATE_a = 0.0F;
  }

  /* RelationalOperator: '<S236>/Compare' incorporates:
   *  Constant: '<S233>/Time constant'
   *  Constant: '<S236>/Constant'
   *  Sum: '<S233>/Sum1'
   */
  test3_B.Compare_h = ((real32_T)(0.031830988618379068 - test3_B.Probe_i[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S238>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_g != 0U) {
    test3_DW.Integrator_DSTATE_n = test3_U.CellVoltages[2];
    if (test3_DW.Integrator_DSTATE_n >= 6.0F) {
      test3_DW.Integrator_DSTATE_n = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_n <= 0.0F) {
      test3_DW.Integrator_DSTATE_n = 0.0F;
    }
  }

  if (test3_B.Compare_h || (test3_DW.Integrator_PrevResetState_o != 0)) {
    test3_DW.Integrator_DSTATE_n = test3_U.CellVoltages[2];
    if (test3_DW.Integrator_DSTATE_n >= 6.0F) {
      test3_DW.Integrator_DSTATE_n = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_n <= 0.0F) {
      test3_DW.Integrator_DSTATE_n = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_n >= 6.0F) {
    test3_DW.Integrator_DSTATE_n = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_n <= 0.0F) {
    test3_DW.Integrator_DSTATE_n = 0.0F;
  }

  /* RelationalOperator: '<S302>/Compare' incorporates:
   *  Constant: '<S299>/Time constant'
   *  Constant: '<S302>/Constant'
   *  Sum: '<S299>/Sum1'
   */
  test3_B.Compare_o = ((real32_T)(0.031830988618379068 - test3_B.Probe_o[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S304>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_j != 0U) {
    test3_DW.Integrator_DSTATE_b = test3_U.CellVoltages[3];
    if (test3_DW.Integrator_DSTATE_b >= 6.0F) {
      test3_DW.Integrator_DSTATE_b = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_b <= 0.0F) {
      test3_DW.Integrator_DSTATE_b = 0.0F;
    }
  }

  if (test3_B.Compare_o || (test3_DW.Integrator_PrevResetState_e != 0)) {
    test3_DW.Integrator_DSTATE_b = test3_U.CellVoltages[3];
    if (test3_DW.Integrator_DSTATE_b >= 6.0F) {
      test3_DW.Integrator_DSTATE_b = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_b <= 0.0F) {
      test3_DW.Integrator_DSTATE_b = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_b >= 6.0F) {
    test3_DW.Integrator_DSTATE_b = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_b <= 0.0F) {
    test3_DW.Integrator_DSTATE_b = 0.0F;
  }

  /* RelationalOperator: '<S368>/Compare' incorporates:
   *  Constant: '<S365>/Time constant'
   *  Constant: '<S368>/Constant'
   *  Sum: '<S365>/Sum1'
   */
  test3_B.Compare_k = ((real32_T)(0.031830988618379068 - test3_B.Probe_ii[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S370>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_h != 0U) {
    test3_DW.Integrator_DSTATE_g = test3_U.CellVoltages[4];
    if (test3_DW.Integrator_DSTATE_g >= 6.0F) {
      test3_DW.Integrator_DSTATE_g = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_g <= 0.0F) {
      test3_DW.Integrator_DSTATE_g = 0.0F;
    }
  }

  if (test3_B.Compare_k || (test3_DW.Integrator_PrevResetState_oy != 0)) {
    test3_DW.Integrator_DSTATE_g = test3_U.CellVoltages[4];
    if (test3_DW.Integrator_DSTATE_g >= 6.0F) {
      test3_DW.Integrator_DSTATE_g = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_g <= 0.0F) {
      test3_DW.Integrator_DSTATE_g = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_g >= 6.0F) {
    test3_DW.Integrator_DSTATE_g = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_g <= 0.0F) {
    test3_DW.Integrator_DSTATE_g = 0.0F;
  }

  /* RelationalOperator: '<S434>/Compare' incorporates:
   *  Constant: '<S431>/Time constant'
   *  Constant: '<S434>/Constant'
   *  Sum: '<S431>/Sum1'
   */
  test3_B.Compare_i = ((real32_T)(0.031830988618379068 - test3_B.Probe_e[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S436>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_k != 0U) {
    test3_DW.Integrator_DSTATE_i = test3_U.CellVoltages[5];
    if (test3_DW.Integrator_DSTATE_i >= 6.0F) {
      test3_DW.Integrator_DSTATE_i = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_i <= 0.0F) {
      test3_DW.Integrator_DSTATE_i = 0.0F;
    }
  }

  if (test3_B.Compare_i || (test3_DW.Integrator_PrevResetState_c != 0)) {
    test3_DW.Integrator_DSTATE_i = test3_U.CellVoltages[5];
    if (test3_DW.Integrator_DSTATE_i >= 6.0F) {
      test3_DW.Integrator_DSTATE_i = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_i <= 0.0F) {
      test3_DW.Integrator_DSTATE_i = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_i >= 6.0F) {
    test3_DW.Integrator_DSTATE_i = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_i <= 0.0F) {
    test3_DW.Integrator_DSTATE_i = 0.0F;
  }

  /* RelationalOperator: '<S500>/Compare' incorporates:
   *  Constant: '<S497>/Time constant'
   *  Constant: '<S500>/Constant'
   *  Sum: '<S497>/Sum1'
   */
  test3_B.Compare_e = ((real32_T)(0.031830988618379068 - test3_B.Probe_n[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S502>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_o != 0U) {
    test3_DW.Integrator_DSTATE_e = test3_U.CellVoltages[6];
    if (test3_DW.Integrator_DSTATE_e >= 6.0F) {
      test3_DW.Integrator_DSTATE_e = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_e <= 0.0F) {
      test3_DW.Integrator_DSTATE_e = 0.0F;
    }
  }

  if (test3_B.Compare_e || (test3_DW.Integrator_PrevResetState_a != 0)) {
    test3_DW.Integrator_DSTATE_e = test3_U.CellVoltages[6];
    if (test3_DW.Integrator_DSTATE_e >= 6.0F) {
      test3_DW.Integrator_DSTATE_e = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_e <= 0.0F) {
      test3_DW.Integrator_DSTATE_e = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_e >= 6.0F) {
    test3_DW.Integrator_DSTATE_e = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_e <= 0.0F) {
    test3_DW.Integrator_DSTATE_e = 0.0F;
  }

  /* RelationalOperator: '<S566>/Compare' incorporates:
   *  Constant: '<S563>/Time constant'
   *  Constant: '<S566>/Constant'
   *  Sum: '<S563>/Sum1'
   */
  test3_B.Compare_k5 = ((real32_T)(0.031830988618379068 - test3_B.Probe_ng[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S568>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_g2 != 0U) {
    test3_DW.Integrator_DSTATE_id = test3_U.CellVoltages[7];
    if (test3_DW.Integrator_DSTATE_id >= 6.0F) {
      test3_DW.Integrator_DSTATE_id = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_id <= 0.0F) {
      test3_DW.Integrator_DSTATE_id = 0.0F;
    }
  }

  if (test3_B.Compare_k5 || (test3_DW.Integrator_PrevResetState_ch != 0)) {
    test3_DW.Integrator_DSTATE_id = test3_U.CellVoltages[7];
    if (test3_DW.Integrator_DSTATE_id >= 6.0F) {
      test3_DW.Integrator_DSTATE_id = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_id <= 0.0F) {
      test3_DW.Integrator_DSTATE_id = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_id >= 6.0F) {
    test3_DW.Integrator_DSTATE_id = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_id <= 0.0F) {
    test3_DW.Integrator_DSTATE_id = 0.0F;
  }

  /* RelationalOperator: '<S632>/Compare' incorporates:
   *  Constant: '<S629>/Time constant'
   *  Constant: '<S632>/Constant'
   *  Sum: '<S629>/Sum1'
   */
  test3_B.Compare_l = ((real32_T)(0.031830988618379068 - test3_B.Probe_no[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S634>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_d != 0U) {
    test3_DW.Integrator_DSTATE_is = test3_U.CellVoltages[8];
    if (test3_DW.Integrator_DSTATE_is >= 6.0F) {
      test3_DW.Integrator_DSTATE_is = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_is <= 0.0F) {
      test3_DW.Integrator_DSTATE_is = 0.0F;
    }
  }

  if (test3_B.Compare_l || (test3_DW.Integrator_PrevResetState_h != 0)) {
    test3_DW.Integrator_DSTATE_is = test3_U.CellVoltages[8];
    if (test3_DW.Integrator_DSTATE_is >= 6.0F) {
      test3_DW.Integrator_DSTATE_is = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_is <= 0.0F) {
      test3_DW.Integrator_DSTATE_is = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_is >= 6.0F) {
    test3_DW.Integrator_DSTATE_is = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_is <= 0.0F) {
    test3_DW.Integrator_DSTATE_is = 0.0F;
  }

  /* RelationalOperator: '<S110>/Compare' incorporates:
   *  Constant: '<S107>/Time constant'
   *  Constant: '<S110>/Constant'
   *  Sum: '<S107>/Sum1'
   */
  test3_B.Compare_iz = ((real32_T)(0.031830988618379068 - test3_B.Probe_b[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S112>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_pv != 0U) {
    test3_DW.Integrator_DSTATE_j = test3_U.CellVoltages[9];
    if (test3_DW.Integrator_DSTATE_j >= 6.0F) {
      test3_DW.Integrator_DSTATE_j = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_j <= 0.0F) {
      test3_DW.Integrator_DSTATE_j = 0.0F;
    }
  }

  if (test3_B.Compare_iz || (test3_DW.Integrator_PrevResetState_i != 0)) {
    test3_DW.Integrator_DSTATE_j = test3_U.CellVoltages[9];
    if (test3_DW.Integrator_DSTATE_j >= 6.0F) {
      test3_DW.Integrator_DSTATE_j = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_j <= 0.0F) {
      test3_DW.Integrator_DSTATE_j = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_j >= 6.0F) {
    test3_DW.Integrator_DSTATE_j = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_j <= 0.0F) {
    test3_DW.Integrator_DSTATE_j = 0.0F;
  }

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Constant: '<S113>/Time constant'
   *  Constant: '<S116>/Constant'
   *  Sum: '<S113>/Sum1'
   */
  test3_B.Compare_d = ((real32_T)(0.031830988618379068 - test3_B.Probe_j[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_m != 0U) {
    test3_DW.Integrator_DSTATE_j1 = test3_U.CellVoltages[10];
    if (test3_DW.Integrator_DSTATE_j1 >= 6.0F) {
      test3_DW.Integrator_DSTATE_j1 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_j1 <= 0.0F) {
      test3_DW.Integrator_DSTATE_j1 = 0.0F;
    }
  }

  if (test3_B.Compare_d || (test3_DW.Integrator_PrevResetState_iy != 0)) {
    test3_DW.Integrator_DSTATE_j1 = test3_U.CellVoltages[10];
    if (test3_DW.Integrator_DSTATE_j1 >= 6.0F) {
      test3_DW.Integrator_DSTATE_j1 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_j1 <= 0.0F) {
      test3_DW.Integrator_DSTATE_j1 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_j1 >= 6.0F) {
    test3_DW.Integrator_DSTATE_j1 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_j1 <= 0.0F) {
    test3_DW.Integrator_DSTATE_j1 = 0.0F;
  }

  /* RelationalOperator: '<S122>/Compare' incorporates:
   *  Constant: '<S119>/Time constant'
   *  Constant: '<S122>/Constant'
   *  Sum: '<S119>/Sum1'
   */
  test3_B.Compare_a = ((real32_T)(0.031830988618379068 - test3_B.Probe_os[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S124>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_hr != 0U) {
    test3_DW.Integrator_DSTATE_jr = test3_U.CellVoltages[11];
    if (test3_DW.Integrator_DSTATE_jr >= 6.0F) {
      test3_DW.Integrator_DSTATE_jr = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_jr <= 0.0F) {
      test3_DW.Integrator_DSTATE_jr = 0.0F;
    }
  }

  if (test3_B.Compare_a || (test3_DW.Integrator_PrevResetState_g != 0)) {
    test3_DW.Integrator_DSTATE_jr = test3_U.CellVoltages[11];
    if (test3_DW.Integrator_DSTATE_jr >= 6.0F) {
      test3_DW.Integrator_DSTATE_jr = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_jr <= 0.0F) {
      test3_DW.Integrator_DSTATE_jr = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_jr >= 6.0F) {
    test3_DW.Integrator_DSTATE_jr = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_jr <= 0.0F) {
    test3_DW.Integrator_DSTATE_jr = 0.0F;
  }

  /* RelationalOperator: '<S128>/Compare' incorporates:
   *  Constant: '<S125>/Time constant'
   *  Constant: '<S128>/Constant'
   *  Sum: '<S125>/Sum1'
   */
  test3_B.Compare_p3 = ((real32_T)(0.031830988618379068 - test3_B.Probe_m[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S130>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_i != 0U) {
    test3_DW.Integrator_DSTATE_p = test3_U.CellVoltages[12];
    if (test3_DW.Integrator_DSTATE_p >= 6.0F) {
      test3_DW.Integrator_DSTATE_p = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_p <= 0.0F) {
      test3_DW.Integrator_DSTATE_p = 0.0F;
    }
  }

  if (test3_B.Compare_p3 || (test3_DW.Integrator_PrevResetState_f != 0)) {
    test3_DW.Integrator_DSTATE_p = test3_U.CellVoltages[12];
    if (test3_DW.Integrator_DSTATE_p >= 6.0F) {
      test3_DW.Integrator_DSTATE_p = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_p <= 0.0F) {
      test3_DW.Integrator_DSTATE_p = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_p >= 6.0F) {
    test3_DW.Integrator_DSTATE_p = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_p <= 0.0F) {
    test3_DW.Integrator_DSTATE_p = 0.0F;
  }

  /* RelationalOperator: '<S134>/Compare' incorporates:
   *  Constant: '<S131>/Time constant'
   *  Constant: '<S134>/Constant'
   *  Sum: '<S131>/Sum1'
   */
  test3_B.Compare_o1 = ((real32_T)(0.031830988618379068 - test3_B.Probe_c[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S136>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_e != 0U) {
    test3_DW.Integrator_DSTATE_o = test3_U.CellVoltages[13];
    if (test3_DW.Integrator_DSTATE_o >= 6.0F) {
      test3_DW.Integrator_DSTATE_o = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_o <= 0.0F) {
      test3_DW.Integrator_DSTATE_o = 0.0F;
    }
  }

  if (test3_B.Compare_o1 || (test3_DW.Integrator_PrevResetState_fi != 0)) {
    test3_DW.Integrator_DSTATE_o = test3_U.CellVoltages[13];
    if (test3_DW.Integrator_DSTATE_o >= 6.0F) {
      test3_DW.Integrator_DSTATE_o = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_o <= 0.0F) {
      test3_DW.Integrator_DSTATE_o = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_o >= 6.0F) {
    test3_DW.Integrator_DSTATE_o = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_o <= 0.0F) {
    test3_DW.Integrator_DSTATE_o = 0.0F;
  }

  /* RelationalOperator: '<S140>/Compare' incorporates:
   *  Constant: '<S137>/Time constant'
   *  Constant: '<S140>/Constant'
   *  Sum: '<S137>/Sum1'
   */
  test3_B.Compare_ob = ((real32_T)(0.031830988618379068 - test3_B.Probe_lt[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S142>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_df != 0U) {
    test3_DW.Integrator_DSTATE_f = test3_U.CellVoltages[14];
    if (test3_DW.Integrator_DSTATE_f >= 6.0F) {
      test3_DW.Integrator_DSTATE_f = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_f <= 0.0F) {
      test3_DW.Integrator_DSTATE_f = 0.0F;
    }
  }

  if (test3_B.Compare_ob || (test3_DW.Integrator_PrevResetState_fm != 0)) {
    test3_DW.Integrator_DSTATE_f = test3_U.CellVoltages[14];
    if (test3_DW.Integrator_DSTATE_f >= 6.0F) {
      test3_DW.Integrator_DSTATE_f = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_f <= 0.0F) {
      test3_DW.Integrator_DSTATE_f = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_f >= 6.0F) {
    test3_DW.Integrator_DSTATE_f = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_f <= 0.0F) {
    test3_DW.Integrator_DSTATE_f = 0.0F;
  }

  /* RelationalOperator: '<S146>/Compare' incorporates:
   *  Constant: '<S143>/Time constant'
   *  Constant: '<S146>/Constant'
   *  Sum: '<S143>/Sum1'
   */
  test3_B.Compare_n = ((real32_T)(0.031830988618379068 - test3_B.Probe_ik[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S148>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ip != 0U) {
    test3_DW.Integrator_DSTATE_fo = test3_U.CellVoltages[15];
    if (test3_DW.Integrator_DSTATE_fo >= 6.0F) {
      test3_DW.Integrator_DSTATE_fo = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fo <= 0.0F) {
      test3_DW.Integrator_DSTATE_fo = 0.0F;
    }
  }

  if (test3_B.Compare_n || (test3_DW.Integrator_PrevResetState_gh != 0)) {
    test3_DW.Integrator_DSTATE_fo = test3_U.CellVoltages[15];
    if (test3_DW.Integrator_DSTATE_fo >= 6.0F) {
      test3_DW.Integrator_DSTATE_fo = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fo <= 0.0F) {
      test3_DW.Integrator_DSTATE_fo = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_fo >= 6.0F) {
    test3_DW.Integrator_DSTATE_fo = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fo <= 0.0F) {
    test3_DW.Integrator_DSTATE_fo = 0.0F;
  }

  /* RelationalOperator: '<S152>/Compare' incorporates:
   *  Constant: '<S149>/Time constant'
   *  Constant: '<S152>/Constant'
   *  Sum: '<S149>/Sum1'
   */
  test3_B.Compare_ii = ((real32_T)(0.031830988618379068 - test3_B.Probe_ct[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S154>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_a != 0U) {
    test3_DW.Integrator_DSTATE_i1 = test3_U.CellVoltages[16];
    if (test3_DW.Integrator_DSTATE_i1 >= 6.0F) {
      test3_DW.Integrator_DSTATE_i1 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_i1 <= 0.0F) {
      test3_DW.Integrator_DSTATE_i1 = 0.0F;
    }
  }

  if (test3_B.Compare_ii || (test3_DW.Integrator_PrevResetState_b != 0)) {
    test3_DW.Integrator_DSTATE_i1 = test3_U.CellVoltages[16];
    if (test3_DW.Integrator_DSTATE_i1 >= 6.0F) {
      test3_DW.Integrator_DSTATE_i1 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_i1 <= 0.0F) {
      test3_DW.Integrator_DSTATE_i1 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_i1 >= 6.0F) {
    test3_DW.Integrator_DSTATE_i1 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_i1 <= 0.0F) {
    test3_DW.Integrator_DSTATE_i1 = 0.0F;
  }

  /* RelationalOperator: '<S158>/Compare' incorporates:
   *  Constant: '<S155>/Time constant'
   *  Constant: '<S158>/Constant'
   *  Sum: '<S155>/Sum1'
   */
  test3_B.Compare_b = ((real32_T)(0.031830988618379068 - test3_B.Probe_f[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S160>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ic != 0U) {
    test3_DW.Integrator_DSTATE_fj = test3_U.CellVoltages[17];
    if (test3_DW.Integrator_DSTATE_fj >= 6.0F) {
      test3_DW.Integrator_DSTATE_fj = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fj <= 0.0F) {
      test3_DW.Integrator_DSTATE_fj = 0.0F;
    }
  }

  if (test3_B.Compare_b || (test3_DW.Integrator_PrevResetState_bl != 0)) {
    test3_DW.Integrator_DSTATE_fj = test3_U.CellVoltages[17];
    if (test3_DW.Integrator_DSTATE_fj >= 6.0F) {
      test3_DW.Integrator_DSTATE_fj = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fj <= 0.0F) {
      test3_DW.Integrator_DSTATE_fj = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_fj >= 6.0F) {
    test3_DW.Integrator_DSTATE_fj = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fj <= 0.0F) {
    test3_DW.Integrator_DSTATE_fj = 0.0F;
  }

  /* RelationalOperator: '<S164>/Compare' incorporates:
   *  Constant: '<S161>/Time constant'
   *  Constant: '<S164>/Constant'
   *  Sum: '<S161>/Sum1'
   */
  test3_B.Compare_f = ((real32_T)(0.031830988618379068 - test3_B.Probe_fp[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S166>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ab != 0U) {
    test3_DW.Integrator_DSTATE_d = test3_U.CellVoltages[18];
    if (test3_DW.Integrator_DSTATE_d >= 6.0F) {
      test3_DW.Integrator_DSTATE_d = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_d <= 0.0F) {
      test3_DW.Integrator_DSTATE_d = 0.0F;
    }
  }

  if (test3_B.Compare_f || (test3_DW.Integrator_PrevResetState_fie != 0)) {
    test3_DW.Integrator_DSTATE_d = test3_U.CellVoltages[18];
    if (test3_DW.Integrator_DSTATE_d >= 6.0F) {
      test3_DW.Integrator_DSTATE_d = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_d <= 0.0F) {
      test3_DW.Integrator_DSTATE_d = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_d >= 6.0F) {
    test3_DW.Integrator_DSTATE_d = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_d <= 0.0F) {
    test3_DW.Integrator_DSTATE_d = 0.0F;
  }

  /* RelationalOperator: '<S176>/Compare' incorporates:
   *  Constant: '<S173>/Time constant'
   *  Constant: '<S176>/Constant'
   *  Sum: '<S173>/Sum1'
   */
  test3_B.Compare_km = ((real32_T)(0.031830988618379068 - test3_B.Probe_g[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S178>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_oe != 0U) {
    test3_DW.Integrator_DSTATE_g5 = test3_U.CellVoltages[19];
    if (test3_DW.Integrator_DSTATE_g5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_g5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_g5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_g5 = 0.0F;
    }
  }

  if (test3_B.Compare_km || (test3_DW.Integrator_PrevResetState_d != 0)) {
    test3_DW.Integrator_DSTATE_g5 = test3_U.CellVoltages[19];
    if (test3_DW.Integrator_DSTATE_g5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_g5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_g5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_g5 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_g5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_g5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_g5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_g5 = 0.0F;
  }

  /* RelationalOperator: '<S182>/Compare' incorporates:
   *  Constant: '<S179>/Time constant'
   *  Constant: '<S182>/Constant'
   *  Sum: '<S179>/Sum1'
   */
  test3_B.Compare_in = ((real32_T)(0.031830988618379068 - test3_B.Probe_h[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S184>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_op != 0U) {
    test3_DW.Integrator_DSTATE_pf = test3_U.CellVoltages[20];
    if (test3_DW.Integrator_DSTATE_pf >= 6.0F) {
      test3_DW.Integrator_DSTATE_pf = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pf <= 0.0F) {
      test3_DW.Integrator_DSTATE_pf = 0.0F;
    }
  }

  if (test3_B.Compare_in || (test3_DW.Integrator_PrevResetState_k != 0)) {
    test3_DW.Integrator_DSTATE_pf = test3_U.CellVoltages[20];
    if (test3_DW.Integrator_DSTATE_pf >= 6.0F) {
      test3_DW.Integrator_DSTATE_pf = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pf <= 0.0F) {
      test3_DW.Integrator_DSTATE_pf = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_pf >= 6.0F) {
    test3_DW.Integrator_DSTATE_pf = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pf <= 0.0F) {
    test3_DW.Integrator_DSTATE_pf = 0.0F;
  }

  /* RelationalOperator: '<S188>/Compare' incorporates:
   *  Constant: '<S185>/Time constant'
   *  Constant: '<S188>/Constant'
   *  Sum: '<S185>/Sum1'
   */
  test3_B.Compare_lv = ((real32_T)(0.031830988618379068 - test3_B.Probe_o4[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S190>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_hg != 0U) {
    test3_DW.Integrator_DSTATE_c = test3_U.CellVoltages[21];
    if (test3_DW.Integrator_DSTATE_c >= 6.0F) {
      test3_DW.Integrator_DSTATE_c = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_c <= 0.0F) {
      test3_DW.Integrator_DSTATE_c = 0.0F;
    }
  }

  if (test3_B.Compare_lv || (test3_DW.Integrator_PrevResetState_n != 0)) {
    test3_DW.Integrator_DSTATE_c = test3_U.CellVoltages[21];
    if (test3_DW.Integrator_DSTATE_c >= 6.0F) {
      test3_DW.Integrator_DSTATE_c = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_c <= 0.0F) {
      test3_DW.Integrator_DSTATE_c = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_c >= 6.0F) {
    test3_DW.Integrator_DSTATE_c = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_c <= 0.0F) {
    test3_DW.Integrator_DSTATE_c = 0.0F;
  }

  /* RelationalOperator: '<S194>/Compare' incorporates:
   *  Constant: '<S191>/Time constant'
   *  Constant: '<S194>/Constant'
   *  Sum: '<S191>/Sum1'
   */
  test3_B.Compare_ed = ((real32_T)(0.031830988618379068 - test3_B.Probe_fc[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S196>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_l != 0U) {
    test3_DW.Integrator_DSTATE_m = test3_U.CellVoltages[22];
    if (test3_DW.Integrator_DSTATE_m >= 6.0F) {
      test3_DW.Integrator_DSTATE_m = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_m <= 0.0F) {
      test3_DW.Integrator_DSTATE_m = 0.0F;
    }
  }

  if (test3_B.Compare_ed || (test3_DW.Integrator_PrevResetState_fz != 0)) {
    test3_DW.Integrator_DSTATE_m = test3_U.CellVoltages[22];
    if (test3_DW.Integrator_DSTATE_m >= 6.0F) {
      test3_DW.Integrator_DSTATE_m = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_m <= 0.0F) {
      test3_DW.Integrator_DSTATE_m = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_m >= 6.0F) {
    test3_DW.Integrator_DSTATE_m = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_m <= 0.0F) {
    test3_DW.Integrator_DSTATE_m = 0.0F;
  }

  /* RelationalOperator: '<S200>/Compare' incorporates:
   *  Constant: '<S197>/Time constant'
   *  Constant: '<S200>/Constant'
   *  Sum: '<S197>/Sum1'
   */
  test3_B.Compare_el = ((real32_T)(0.031830988618379068 - test3_B.Probe_f1[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S202>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_iw != 0U) {
    test3_DW.Integrator_DSTATE_j2 = test3_U.CellVoltages[23];
    if (test3_DW.Integrator_DSTATE_j2 >= 6.0F) {
      test3_DW.Integrator_DSTATE_j2 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_j2 <= 0.0F) {
      test3_DW.Integrator_DSTATE_j2 = 0.0F;
    }
  }

  if (test3_B.Compare_el || (test3_DW.Integrator_PrevResetState_m != 0)) {
    test3_DW.Integrator_DSTATE_j2 = test3_U.CellVoltages[23];
    if (test3_DW.Integrator_DSTATE_j2 >= 6.0F) {
      test3_DW.Integrator_DSTATE_j2 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_j2 <= 0.0F) {
      test3_DW.Integrator_DSTATE_j2 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_j2 >= 6.0F) {
    test3_DW.Integrator_DSTATE_j2 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_j2 <= 0.0F) {
    test3_DW.Integrator_DSTATE_j2 = 0.0F;
  }

  /* RelationalOperator: '<S206>/Compare' incorporates:
   *  Constant: '<S203>/Time constant'
   *  Constant: '<S206>/Constant'
   *  Sum: '<S203>/Sum1'
   */
  test3_B.Compare_kl = ((real32_T)(0.031830988618379068 - test3_B.Probe_bf[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S208>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ky != 0U) {
    test3_DW.Integrator_DSTATE_iz = test3_U.CellVoltages[24];
    if (test3_DW.Integrator_DSTATE_iz >= 6.0F) {
      test3_DW.Integrator_DSTATE_iz = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_iz <= 0.0F) {
      test3_DW.Integrator_DSTATE_iz = 0.0F;
    }
  }

  if (test3_B.Compare_kl || (test3_DW.Integrator_PrevResetState_hi != 0)) {
    test3_DW.Integrator_DSTATE_iz = test3_U.CellVoltages[24];
    if (test3_DW.Integrator_DSTATE_iz >= 6.0F) {
      test3_DW.Integrator_DSTATE_iz = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_iz <= 0.0F) {
      test3_DW.Integrator_DSTATE_iz = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_iz >= 6.0F) {
    test3_DW.Integrator_DSTATE_iz = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_iz <= 0.0F) {
    test3_DW.Integrator_DSTATE_iz = 0.0F;
  }

  /* RelationalOperator: '<S212>/Compare' incorporates:
   *  Constant: '<S209>/Time constant'
   *  Constant: '<S212>/Constant'
   *  Sum: '<S209>/Sum1'
   */
  test3_B.Compare_kf = ((real32_T)(0.031830988618379068 - test3_B.Probe_gu[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S214>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_b != 0U) {
    test3_DW.Integrator_DSTATE_bh = test3_U.CellVoltages[25];
    if (test3_DW.Integrator_DSTATE_bh >= 6.0F) {
      test3_DW.Integrator_DSTATE_bh = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bh <= 0.0F) {
      test3_DW.Integrator_DSTATE_bh = 0.0F;
    }
  }

  if (test3_B.Compare_kf || (test3_DW.Integrator_PrevResetState_fy != 0)) {
    test3_DW.Integrator_DSTATE_bh = test3_U.CellVoltages[25];
    if (test3_DW.Integrator_DSTATE_bh >= 6.0F) {
      test3_DW.Integrator_DSTATE_bh = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bh <= 0.0F) {
      test3_DW.Integrator_DSTATE_bh = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_bh >= 6.0F) {
    test3_DW.Integrator_DSTATE_bh = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bh <= 0.0F) {
    test3_DW.Integrator_DSTATE_bh = 0.0F;
  }

  /* RelationalOperator: '<S218>/Compare' incorporates:
   *  Constant: '<S215>/Time constant'
   *  Constant: '<S218>/Constant'
   *  Sum: '<S215>/Sum1'
   */
  test3_B.Compare_hy = ((real32_T)(0.031830988618379068 - test3_B.Probe_er[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S220>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_gu != 0U) {
    test3_DW.Integrator_DSTATE_ji = test3_U.CellVoltages[26];
    if (test3_DW.Integrator_DSTATE_ji >= 6.0F) {
      test3_DW.Integrator_DSTATE_ji = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ji <= 0.0F) {
      test3_DW.Integrator_DSTATE_ji = 0.0F;
    }
  }

  if (test3_B.Compare_hy || (test3_DW.Integrator_PrevResetState_ok != 0)) {
    test3_DW.Integrator_DSTATE_ji = test3_U.CellVoltages[26];
    if (test3_DW.Integrator_DSTATE_ji >= 6.0F) {
      test3_DW.Integrator_DSTATE_ji = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ji <= 0.0F) {
      test3_DW.Integrator_DSTATE_ji = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ji >= 6.0F) {
    test3_DW.Integrator_DSTATE_ji = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ji <= 0.0F) {
    test3_DW.Integrator_DSTATE_ji = 0.0F;
  }

  /* RelationalOperator: '<S224>/Compare' incorporates:
   *  Constant: '<S221>/Time constant'
   *  Constant: '<S224>/Constant'
   *  Sum: '<S221>/Sum1'
   */
  test3_B.Compare_oi = ((real32_T)(0.031830988618379068 - test3_B.Probe_hq[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S226>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ao != 0U) {
    test3_DW.Integrator_DSTATE_od = test3_U.CellVoltages[27];
    if (test3_DW.Integrator_DSTATE_od >= 6.0F) {
      test3_DW.Integrator_DSTATE_od = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_od <= 0.0F) {
      test3_DW.Integrator_DSTATE_od = 0.0F;
    }
  }

  if (test3_B.Compare_oi || (test3_DW.Integrator_PrevResetState_j != 0)) {
    test3_DW.Integrator_DSTATE_od = test3_U.CellVoltages[27];
    if (test3_DW.Integrator_DSTATE_od >= 6.0F) {
      test3_DW.Integrator_DSTATE_od = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_od <= 0.0F) {
      test3_DW.Integrator_DSTATE_od = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_od >= 6.0F) {
    test3_DW.Integrator_DSTATE_od = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_od <= 0.0F) {
    test3_DW.Integrator_DSTATE_od = 0.0F;
  }

  /* RelationalOperator: '<S230>/Compare' incorporates:
   *  Constant: '<S227>/Time constant'
   *  Constant: '<S230>/Constant'
   *  Sum: '<S227>/Sum1'
   */
  test3_B.Compare_i1 = ((real32_T)(0.031830988618379068 - test3_B.Probe_md[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S232>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_f != 0U) {
    test3_DW.Integrator_DSTATE_oy = test3_U.CellVoltages[28];
    if (test3_DW.Integrator_DSTATE_oy >= 6.0F) {
      test3_DW.Integrator_DSTATE_oy = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_oy <= 0.0F) {
      test3_DW.Integrator_DSTATE_oy = 0.0F;
    }
  }

  if (test3_B.Compare_i1 || (test3_DW.Integrator_PrevResetState_dh != 0)) {
    test3_DW.Integrator_DSTATE_oy = test3_U.CellVoltages[28];
    if (test3_DW.Integrator_DSTATE_oy >= 6.0F) {
      test3_DW.Integrator_DSTATE_oy = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_oy <= 0.0F) {
      test3_DW.Integrator_DSTATE_oy = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_oy >= 6.0F) {
    test3_DW.Integrator_DSTATE_oy = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_oy <= 0.0F) {
    test3_DW.Integrator_DSTATE_oy = 0.0F;
  }

  /* RelationalOperator: '<S242>/Compare' incorporates:
   *  Constant: '<S239>/Time constant'
   *  Constant: '<S242>/Constant'
   *  Sum: '<S239>/Sum1'
   */
  test3_B.Compare_g = ((real32_T)(0.031830988618379068 - test3_B.Probe_p[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S244>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_c != 0U) {
    test3_DW.Integrator_DSTATE_nc = test3_U.CellVoltages[29];
    if (test3_DW.Integrator_DSTATE_nc >= 6.0F) {
      test3_DW.Integrator_DSTATE_nc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_nc <= 0.0F) {
      test3_DW.Integrator_DSTATE_nc = 0.0F;
    }
  }

  if (test3_B.Compare_g || (test3_DW.Integrator_PrevResetState_ne != 0)) {
    test3_DW.Integrator_DSTATE_nc = test3_U.CellVoltages[29];
    if (test3_DW.Integrator_DSTATE_nc >= 6.0F) {
      test3_DW.Integrator_DSTATE_nc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_nc <= 0.0F) {
      test3_DW.Integrator_DSTATE_nc = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_nc >= 6.0F) {
    test3_DW.Integrator_DSTATE_nc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_nc <= 0.0F) {
    test3_DW.Integrator_DSTATE_nc = 0.0F;
  }

  /* RelationalOperator: '<S248>/Compare' incorporates:
   *  Constant: '<S245>/Time constant'
   *  Constant: '<S248>/Constant'
   *  Sum: '<S245>/Sum1'
   */
  test3_B.Compare_ec = ((real32_T)(0.031830988618379068 - test3_B.Probe_pe[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S250>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_fc != 0U) {
    test3_DW.Integrator_DSTATE_c2 = test3_U.CellVoltages[30];
    if (test3_DW.Integrator_DSTATE_c2 >= 6.0F) {
      test3_DW.Integrator_DSTATE_c2 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_c2 <= 0.0F) {
      test3_DW.Integrator_DSTATE_c2 = 0.0F;
    }
  }

  if (test3_B.Compare_ec || (test3_DW.Integrator_PrevResetState_fl != 0)) {
    test3_DW.Integrator_DSTATE_c2 = test3_U.CellVoltages[30];
    if (test3_DW.Integrator_DSTATE_c2 >= 6.0F) {
      test3_DW.Integrator_DSTATE_c2 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_c2 <= 0.0F) {
      test3_DW.Integrator_DSTATE_c2 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_c2 >= 6.0F) {
    test3_DW.Integrator_DSTATE_c2 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_c2 <= 0.0F) {
    test3_DW.Integrator_DSTATE_c2 = 0.0F;
  }

  /* RelationalOperator: '<S254>/Compare' incorporates:
   *  Constant: '<S251>/Time constant'
   *  Constant: '<S254>/Constant'
   *  Sum: '<S251>/Sum1'
   */
  test3_B.Compare_kh = ((real32_T)(0.031830988618379068 - test3_B.Probe_gb[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S256>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bd != 0U) {
    test3_DW.Integrator_DSTATE_pa = test3_U.CellVoltages[31];
    if (test3_DW.Integrator_DSTATE_pa >= 6.0F) {
      test3_DW.Integrator_DSTATE_pa = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pa <= 0.0F) {
      test3_DW.Integrator_DSTATE_pa = 0.0F;
    }
  }

  if (test3_B.Compare_kh || (test3_DW.Integrator_PrevResetState_ib != 0)) {
    test3_DW.Integrator_DSTATE_pa = test3_U.CellVoltages[31];
    if (test3_DW.Integrator_DSTATE_pa >= 6.0F) {
      test3_DW.Integrator_DSTATE_pa = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pa <= 0.0F) {
      test3_DW.Integrator_DSTATE_pa = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_pa >= 6.0F) {
    test3_DW.Integrator_DSTATE_pa = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pa <= 0.0F) {
    test3_DW.Integrator_DSTATE_pa = 0.0F;
  }

  /* RelationalOperator: '<S260>/Compare' incorporates:
   *  Constant: '<S257>/Time constant'
   *  Constant: '<S260>/Constant'
   *  Sum: '<S257>/Sum1'
   */
  test3_B.Compare_go = ((real32_T)(0.031830988618379068 - test3_B.Probe_gs[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S262>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_n != 0U) {
    test3_DW.Integrator_DSTATE_ez = test3_U.CellVoltages[32];
    if (test3_DW.Integrator_DSTATE_ez >= 6.0F) {
      test3_DW.Integrator_DSTATE_ez = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ez <= 0.0F) {
      test3_DW.Integrator_DSTATE_ez = 0.0F;
    }
  }

  if (test3_B.Compare_go || (test3_DW.Integrator_PrevResetState_dz != 0)) {
    test3_DW.Integrator_DSTATE_ez = test3_U.CellVoltages[32];
    if (test3_DW.Integrator_DSTATE_ez >= 6.0F) {
      test3_DW.Integrator_DSTATE_ez = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ez <= 0.0F) {
      test3_DW.Integrator_DSTATE_ez = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ez >= 6.0F) {
    test3_DW.Integrator_DSTATE_ez = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ez <= 0.0F) {
    test3_DW.Integrator_DSTATE_ez = 0.0F;
  }

  /* RelationalOperator: '<S266>/Compare' incorporates:
   *  Constant: '<S263>/Time constant'
   *  Constant: '<S266>/Constant'
   *  Sum: '<S263>/Sum1'
   */
  test3_B.Compare_hb = ((real32_T)(0.031830988618379068 - test3_B.Probe_p1[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S268>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_aoc != 0U) {
    test3_DW.Integrator_DSTATE_bp = test3_U.CellVoltages[33];
    if (test3_DW.Integrator_DSTATE_bp >= 6.0F) {
      test3_DW.Integrator_DSTATE_bp = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bp <= 0.0F) {
      test3_DW.Integrator_DSTATE_bp = 0.0F;
    }
  }

  if (test3_B.Compare_hb || (test3_DW.Integrator_PrevResetState_l != 0)) {
    test3_DW.Integrator_DSTATE_bp = test3_U.CellVoltages[33];
    if (test3_DW.Integrator_DSTATE_bp >= 6.0F) {
      test3_DW.Integrator_DSTATE_bp = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bp <= 0.0F) {
      test3_DW.Integrator_DSTATE_bp = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_bp >= 6.0F) {
    test3_DW.Integrator_DSTATE_bp = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bp <= 0.0F) {
    test3_DW.Integrator_DSTATE_bp = 0.0F;
  }

  /* RelationalOperator: '<S272>/Compare' incorporates:
   *  Constant: '<S269>/Time constant'
   *  Constant: '<S272>/Constant'
   *  Sum: '<S269>/Sum1'
   */
  test3_B.Compare_d2 = ((real32_T)(0.031830988618379068 - test3_B.Probe_j0[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S274>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kr != 0U) {
    test3_DW.Integrator_DSTATE_h = test3_U.CellVoltages[34];
    if (test3_DW.Integrator_DSTATE_h >= 6.0F) {
      test3_DW.Integrator_DSTATE_h = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_h <= 0.0F) {
      test3_DW.Integrator_DSTATE_h = 0.0F;
    }
  }

  if (test3_B.Compare_d2 || (test3_DW.Integrator_PrevResetState_hm != 0)) {
    test3_DW.Integrator_DSTATE_h = test3_U.CellVoltages[34];
    if (test3_DW.Integrator_DSTATE_h >= 6.0F) {
      test3_DW.Integrator_DSTATE_h = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_h <= 0.0F) {
      test3_DW.Integrator_DSTATE_h = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_h >= 6.0F) {
    test3_DW.Integrator_DSTATE_h = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_h <= 0.0F) {
    test3_DW.Integrator_DSTATE_h = 0.0F;
  }

  /* RelationalOperator: '<S278>/Compare' incorporates:
   *  Constant: '<S275>/Time constant'
   *  Constant: '<S278>/Constant'
   *  Sum: '<S275>/Sum1'
   */
  test3_B.Compare_kfs = ((real32_T)(0.031830988618379068 - test3_B.Probe_ib[0]) <=
    0.0F);

  /* DiscreteIntegrator: '<S280>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_n3 != 0U) {
    test3_DW.Integrator_DSTATE_i4 = test3_U.CellVoltages[35];
    if (test3_DW.Integrator_DSTATE_i4 >= 6.0F) {
      test3_DW.Integrator_DSTATE_i4 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_i4 <= 0.0F) {
      test3_DW.Integrator_DSTATE_i4 = 0.0F;
    }
  }

  if (test3_B.Compare_kfs || (test3_DW.Integrator_PrevResetState_lo != 0)) {
    test3_DW.Integrator_DSTATE_i4 = test3_U.CellVoltages[35];
    if (test3_DW.Integrator_DSTATE_i4 >= 6.0F) {
      test3_DW.Integrator_DSTATE_i4 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_i4 <= 0.0F) {
      test3_DW.Integrator_DSTATE_i4 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_i4 >= 6.0F) {
    test3_DW.Integrator_DSTATE_i4 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_i4 <= 0.0F) {
    test3_DW.Integrator_DSTATE_i4 = 0.0F;
  }

  /* RelationalOperator: '<S284>/Compare' incorporates:
   *  Constant: '<S281>/Time constant'
   *  Constant: '<S284>/Constant'
   *  Sum: '<S281>/Sum1'
   */
  test3_B.Compare_b3 = ((real32_T)(0.031830988618379068 - test3_B.Probe_nm[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S286>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_pe != 0U) {
    test3_DW.Integrator_DSTATE_fp = test3_U.CellVoltages[36];
    if (test3_DW.Integrator_DSTATE_fp >= 6.0F) {
      test3_DW.Integrator_DSTATE_fp = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fp <= 0.0F) {
      test3_DW.Integrator_DSTATE_fp = 0.0F;
    }
  }

  if (test3_B.Compare_b3 || (test3_DW.Integrator_PrevResetState_dk != 0)) {
    test3_DW.Integrator_DSTATE_fp = test3_U.CellVoltages[36];
    if (test3_DW.Integrator_DSTATE_fp >= 6.0F) {
      test3_DW.Integrator_DSTATE_fp = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fp <= 0.0F) {
      test3_DW.Integrator_DSTATE_fp = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_fp >= 6.0F) {
    test3_DW.Integrator_DSTATE_fp = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fp <= 0.0F) {
    test3_DW.Integrator_DSTATE_fp = 0.0F;
  }

  /* RelationalOperator: '<S290>/Compare' incorporates:
   *  Constant: '<S287>/Time constant'
   *  Constant: '<S290>/Constant'
   *  Sum: '<S287>/Sum1'
   */
  test3_B.Compare_kd = ((real32_T)(0.031830988618379068 - test3_B.Probe_hh[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S292>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_gb != 0U) {
    test3_DW.Integrator_DSTATE_hx = test3_U.CellVoltages[37];
    if (test3_DW.Integrator_DSTATE_hx >= 6.0F) {
      test3_DW.Integrator_DSTATE_hx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_hx <= 0.0F) {
      test3_DW.Integrator_DSTATE_hx = 0.0F;
    }
  }

  if (test3_B.Compare_kd || (test3_DW.Integrator_PrevResetState_es != 0)) {
    test3_DW.Integrator_DSTATE_hx = test3_U.CellVoltages[37];
    if (test3_DW.Integrator_DSTATE_hx >= 6.0F) {
      test3_DW.Integrator_DSTATE_hx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_hx <= 0.0F) {
      test3_DW.Integrator_DSTATE_hx = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_hx >= 6.0F) {
    test3_DW.Integrator_DSTATE_hx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_hx <= 0.0F) {
    test3_DW.Integrator_DSTATE_hx = 0.0F;
  }

  /* RelationalOperator: '<S296>/Compare' incorporates:
   *  Constant: '<S293>/Time constant'
   *  Constant: '<S296>/Constant'
   *  Sum: '<S293>/Sum1'
   */
  test3_B.Compare_dh = ((real32_T)(0.031830988618379068 - test3_B.Probe_d[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S298>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_gg != 0U) {
    test3_DW.Integrator_DSTATE_k = test3_U.CellVoltages[38];
    if (test3_DW.Integrator_DSTATE_k >= 6.0F) {
      test3_DW.Integrator_DSTATE_k = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_k <= 0.0F) {
      test3_DW.Integrator_DSTATE_k = 0.0F;
    }
  }

  if (test3_B.Compare_dh || (test3_DW.Integrator_PrevResetState_fu != 0)) {
    test3_DW.Integrator_DSTATE_k = test3_U.CellVoltages[38];
    if (test3_DW.Integrator_DSTATE_k >= 6.0F) {
      test3_DW.Integrator_DSTATE_k = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_k <= 0.0F) {
      test3_DW.Integrator_DSTATE_k = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_k >= 6.0F) {
    test3_DW.Integrator_DSTATE_k = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_k <= 0.0F) {
    test3_DW.Integrator_DSTATE_k = 0.0F;
  }

  /* RelationalOperator: '<S308>/Compare' incorporates:
   *  Constant: '<S305>/Time constant'
   *  Constant: '<S308>/Constant'
   *  Sum: '<S305>/Sum1'
   */
  test3_B.Compare_kv = ((real32_T)(0.031830988618379068 - test3_B.Probe_fv[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S310>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bb != 0U) {
    test3_DW.Integrator_DSTATE_g3 = test3_U.CellVoltages[39];
    if (test3_DW.Integrator_DSTATE_g3 >= 6.0F) {
      test3_DW.Integrator_DSTATE_g3 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_g3 <= 0.0F) {
      test3_DW.Integrator_DSTATE_g3 = 0.0F;
    }
  }

  if (test3_B.Compare_kv || (test3_DW.Integrator_PrevResetState_cv != 0)) {
    test3_DW.Integrator_DSTATE_g3 = test3_U.CellVoltages[39];
    if (test3_DW.Integrator_DSTATE_g3 >= 6.0F) {
      test3_DW.Integrator_DSTATE_g3 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_g3 <= 0.0F) {
      test3_DW.Integrator_DSTATE_g3 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_g3 >= 6.0F) {
    test3_DW.Integrator_DSTATE_g3 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_g3 <= 0.0F) {
    test3_DW.Integrator_DSTATE_g3 = 0.0F;
  }

  /* RelationalOperator: '<S314>/Compare' incorporates:
   *  Constant: '<S311>/Time constant'
   *  Constant: '<S314>/Constant'
   *  Sum: '<S311>/Sum1'
   */
  test3_B.Compare_of = ((real32_T)(0.031830988618379068 - test3_B.Probe_ij[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S316>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_p4 != 0U) {
    test3_DW.Integrator_DSTATE_h4 = test3_U.CellVoltages[40];
    if (test3_DW.Integrator_DSTATE_h4 >= 6.0F) {
      test3_DW.Integrator_DSTATE_h4 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_h4 <= 0.0F) {
      test3_DW.Integrator_DSTATE_h4 = 0.0F;
    }
  }

  if (test3_B.Compare_of || (test3_DW.Integrator_PrevResetState_ke != 0)) {
    test3_DW.Integrator_DSTATE_h4 = test3_U.CellVoltages[40];
    if (test3_DW.Integrator_DSTATE_h4 >= 6.0F) {
      test3_DW.Integrator_DSTATE_h4 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_h4 <= 0.0F) {
      test3_DW.Integrator_DSTATE_h4 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_h4 >= 6.0F) {
    test3_DW.Integrator_DSTATE_h4 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_h4 <= 0.0F) {
    test3_DW.Integrator_DSTATE_h4 = 0.0F;
  }

  /* RelationalOperator: '<S320>/Compare' incorporates:
   *  Constant: '<S317>/Time constant'
   *  Constant: '<S320>/Constant'
   *  Sum: '<S317>/Sum1'
   */
  test3_B.Compare_bn = ((real32_T)(0.031830988618379068 - test3_B.Probe_pk[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S322>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_mv != 0U) {
    test3_DW.Integrator_DSTATE_e5 = test3_U.CellVoltages[41];
    if (test3_DW.Integrator_DSTATE_e5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_e5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_e5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_e5 = 0.0F;
    }
  }

  if (test3_B.Compare_bn || (test3_DW.Integrator_PrevResetState_fa != 0)) {
    test3_DW.Integrator_DSTATE_e5 = test3_U.CellVoltages[41];
    if (test3_DW.Integrator_DSTATE_e5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_e5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_e5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_e5 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_e5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_e5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_e5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_e5 = 0.0F;
  }

  /* RelationalOperator: '<S326>/Compare' incorporates:
   *  Constant: '<S323>/Time constant'
   *  Constant: '<S326>/Constant'
   *  Sum: '<S323>/Sum1'
   */
  test3_B.Compare_ix = ((real32_T)(0.031830988618379068 - test3_B.Probe_a[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S328>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_j1 != 0U) {
    test3_DW.Integrator_DSTATE_oc = test3_U.CellVoltages[42];
    if (test3_DW.Integrator_DSTATE_oc >= 6.0F) {
      test3_DW.Integrator_DSTATE_oc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_oc <= 0.0F) {
      test3_DW.Integrator_DSTATE_oc = 0.0F;
    }
  }

  if (test3_B.Compare_ix || (test3_DW.Integrator_PrevResetState_h4 != 0)) {
    test3_DW.Integrator_DSTATE_oc = test3_U.CellVoltages[42];
    if (test3_DW.Integrator_DSTATE_oc >= 6.0F) {
      test3_DW.Integrator_DSTATE_oc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_oc <= 0.0F) {
      test3_DW.Integrator_DSTATE_oc = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_oc >= 6.0F) {
    test3_DW.Integrator_DSTATE_oc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_oc <= 0.0F) {
    test3_DW.Integrator_DSTATE_oc = 0.0F;
  }

  /* RelationalOperator: '<S332>/Compare' incorporates:
   *  Constant: '<S329>/Time constant'
   *  Constant: '<S332>/Constant'
   *  Sum: '<S329>/Sum1'
   */
  test3_B.Compare_gy = ((real32_T)(0.031830988618379068 - test3_B.Probe_fpu[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S334>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_az != 0U) {
    test3_DW.Integrator_DSTATE_n5 = test3_U.CellVoltages[43];
    if (test3_DW.Integrator_DSTATE_n5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_n5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_n5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_n5 = 0.0F;
    }
  }

  if (test3_B.Compare_gy || (test3_DW.Integrator_PrevResetState_io != 0)) {
    test3_DW.Integrator_DSTATE_n5 = test3_U.CellVoltages[43];
    if (test3_DW.Integrator_DSTATE_n5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_n5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_n5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_n5 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_n5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_n5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_n5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_n5 = 0.0F;
  }

  /* RelationalOperator: '<S338>/Compare' incorporates:
   *  Constant: '<S335>/Time constant'
   *  Constant: '<S338>/Constant'
   *  Sum: '<S335>/Sum1'
   */
  test3_B.Compare_kz = ((real32_T)(0.031830988618379068 - test3_B.Probe_m0[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S340>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bm != 0U) {
    test3_DW.Integrator_DSTATE_do = test3_U.CellVoltages[44];
    if (test3_DW.Integrator_DSTATE_do >= 6.0F) {
      test3_DW.Integrator_DSTATE_do = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_do <= 0.0F) {
      test3_DW.Integrator_DSTATE_do = 0.0F;
    }
  }

  if (test3_B.Compare_kz || (test3_DW.Integrator_PrevResetState_k3 != 0)) {
    test3_DW.Integrator_DSTATE_do = test3_U.CellVoltages[44];
    if (test3_DW.Integrator_DSTATE_do >= 6.0F) {
      test3_DW.Integrator_DSTATE_do = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_do <= 0.0F) {
      test3_DW.Integrator_DSTATE_do = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_do >= 6.0F) {
    test3_DW.Integrator_DSTATE_do = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_do <= 0.0F) {
    test3_DW.Integrator_DSTATE_do = 0.0F;
  }

  /* RelationalOperator: '<S344>/Compare' incorporates:
   *  Constant: '<S341>/Time constant'
   *  Constant: '<S344>/Constant'
   *  Sum: '<S341>/Sum1'
   */
  test3_B.Compare_hi = ((real32_T)(0.031830988618379068 - test3_B.Probe_mt[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S346>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_c0 != 0U) {
    test3_DW.Integrator_DSTATE_ds = test3_U.CellVoltages[45];
    if (test3_DW.Integrator_DSTATE_ds >= 6.0F) {
      test3_DW.Integrator_DSTATE_ds = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ds <= 0.0F) {
      test3_DW.Integrator_DSTATE_ds = 0.0F;
    }
  }

  if (test3_B.Compare_hi || (test3_DW.Integrator_PrevResetState_ed != 0)) {
    test3_DW.Integrator_DSTATE_ds = test3_U.CellVoltages[45];
    if (test3_DW.Integrator_DSTATE_ds >= 6.0F) {
      test3_DW.Integrator_DSTATE_ds = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ds <= 0.0F) {
      test3_DW.Integrator_DSTATE_ds = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ds >= 6.0F) {
    test3_DW.Integrator_DSTATE_ds = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ds <= 0.0F) {
    test3_DW.Integrator_DSTATE_ds = 0.0F;
  }

  /* RelationalOperator: '<S350>/Compare' incorporates:
   *  Constant: '<S347>/Time constant'
   *  Constant: '<S350>/Constant'
   *  Sum: '<S347>/Sum1'
   */
  test3_B.Compare_by = ((real32_T)(0.031830988618379068 - test3_B.Probe_fn[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S352>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_p0 != 0U) {
    test3_DW.Integrator_DSTATE_bv = test3_U.CellVoltages[46];
    if (test3_DW.Integrator_DSTATE_bv >= 6.0F) {
      test3_DW.Integrator_DSTATE_bv = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bv <= 0.0F) {
      test3_DW.Integrator_DSTATE_bv = 0.0F;
    }
  }

  if (test3_B.Compare_by || (test3_DW.Integrator_PrevResetState_on != 0)) {
    test3_DW.Integrator_DSTATE_bv = test3_U.CellVoltages[46];
    if (test3_DW.Integrator_DSTATE_bv >= 6.0F) {
      test3_DW.Integrator_DSTATE_bv = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bv <= 0.0F) {
      test3_DW.Integrator_DSTATE_bv = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_bv >= 6.0F) {
    test3_DW.Integrator_DSTATE_bv = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bv <= 0.0F) {
    test3_DW.Integrator_DSTATE_bv = 0.0F;
  }

  /* RelationalOperator: '<S356>/Compare' incorporates:
   *  Constant: '<S353>/Time constant'
   *  Constant: '<S356>/Constant'
   *  Sum: '<S353>/Sum1'
   */
  test3_B.Compare_pn = ((real32_T)(0.031830988618379068 - test3_B.Probe_op[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S358>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_j3 != 0U) {
    test3_DW.Integrator_DSTATE_o3 = test3_U.CellVoltages[47];
    if (test3_DW.Integrator_DSTATE_o3 >= 6.0F) {
      test3_DW.Integrator_DSTATE_o3 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_o3 <= 0.0F) {
      test3_DW.Integrator_DSTATE_o3 = 0.0F;
    }
  }

  if (test3_B.Compare_pn || (test3_DW.Integrator_PrevResetState_cb != 0)) {
    test3_DW.Integrator_DSTATE_o3 = test3_U.CellVoltages[47];
    if (test3_DW.Integrator_DSTATE_o3 >= 6.0F) {
      test3_DW.Integrator_DSTATE_o3 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_o3 <= 0.0F) {
      test3_DW.Integrator_DSTATE_o3 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_o3 >= 6.0F) {
    test3_DW.Integrator_DSTATE_o3 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_o3 <= 0.0F) {
    test3_DW.Integrator_DSTATE_o3 = 0.0F;
  }

  /* RelationalOperator: '<S362>/Compare' incorporates:
   *  Constant: '<S359>/Time constant'
   *  Constant: '<S362>/Constant'
   *  Sum: '<S359>/Sum1'
   */
  test3_B.Compare_ep = ((real32_T)(0.031830988618379068 - test3_B.Probe_k[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S364>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_hf != 0U) {
    test3_DW.Integrator_DSTATE_fg = test3_U.CellVoltages[48];
    if (test3_DW.Integrator_DSTATE_fg >= 6.0F) {
      test3_DW.Integrator_DSTATE_fg = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fg <= 0.0F) {
      test3_DW.Integrator_DSTATE_fg = 0.0F;
    }
  }

  if (test3_B.Compare_ep || (test3_DW.Integrator_PrevResetState_fj != 0)) {
    test3_DW.Integrator_DSTATE_fg = test3_U.CellVoltages[48];
    if (test3_DW.Integrator_DSTATE_fg >= 6.0F) {
      test3_DW.Integrator_DSTATE_fg = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fg <= 0.0F) {
      test3_DW.Integrator_DSTATE_fg = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_fg >= 6.0F) {
    test3_DW.Integrator_DSTATE_fg = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fg <= 0.0F) {
    test3_DW.Integrator_DSTATE_fg = 0.0F;
  }

  /* RelationalOperator: '<S374>/Compare' incorporates:
   *  Constant: '<S371>/Time constant'
   *  Constant: '<S374>/Constant'
   *  Sum: '<S371>/Sum1'
   */
  test3_B.Compare_ev = ((real32_T)(0.031830988618379068 - test3_B.Probe_ll[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S376>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ms != 0U) {
    test3_DW.Integrator_DSTATE_a4 = test3_U.CellVoltages[49];
    if (test3_DW.Integrator_DSTATE_a4 >= 6.0F) {
      test3_DW.Integrator_DSTATE_a4 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_a4 <= 0.0F) {
      test3_DW.Integrator_DSTATE_a4 = 0.0F;
    }
  }

  if (test3_B.Compare_ev || (test3_DW.Integrator_PrevResetState_kk != 0)) {
    test3_DW.Integrator_DSTATE_a4 = test3_U.CellVoltages[49];
    if (test3_DW.Integrator_DSTATE_a4 >= 6.0F) {
      test3_DW.Integrator_DSTATE_a4 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_a4 <= 0.0F) {
      test3_DW.Integrator_DSTATE_a4 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_a4 >= 6.0F) {
    test3_DW.Integrator_DSTATE_a4 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_a4 <= 0.0F) {
    test3_DW.Integrator_DSTATE_a4 = 0.0F;
  }

  /* RelationalOperator: '<S380>/Compare' incorporates:
   *  Constant: '<S377>/Time constant'
   *  Constant: '<S380>/Constant'
   *  Sum: '<S377>/Sum1'
   */
  test3_B.Compare_bm = ((real32_T)(0.031830988618379068 - test3_B.Probe_dm[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S382>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_me != 0U) {
    test3_DW.Integrator_DSTATE_l = test3_U.CellVoltages[50];
    if (test3_DW.Integrator_DSTATE_l >= 6.0F) {
      test3_DW.Integrator_DSTATE_l = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_l <= 0.0F) {
      test3_DW.Integrator_DSTATE_l = 0.0F;
    }
  }

  if (test3_B.Compare_bm || (test3_DW.Integrator_PrevResetState_ie != 0)) {
    test3_DW.Integrator_DSTATE_l = test3_U.CellVoltages[50];
    if (test3_DW.Integrator_DSTATE_l >= 6.0F) {
      test3_DW.Integrator_DSTATE_l = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_l <= 0.0F) {
      test3_DW.Integrator_DSTATE_l = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_l >= 6.0F) {
    test3_DW.Integrator_DSTATE_l = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_l <= 0.0F) {
    test3_DW.Integrator_DSTATE_l = 0.0F;
  }

  /* RelationalOperator: '<S386>/Compare' incorporates:
   *  Constant: '<S383>/Time constant'
   *  Constant: '<S386>/Constant'
   *  Sum: '<S383>/Sum1'
   */
  test3_B.Compare_io = ((real32_T)(0.031830988618379068 - test3_B.Probe_ba[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S388>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_oq != 0U) {
    test3_DW.Integrator_DSTATE_eo = test3_U.CellVoltages[51];
    if (test3_DW.Integrator_DSTATE_eo >= 6.0F) {
      test3_DW.Integrator_DSTATE_eo = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_eo <= 0.0F) {
      test3_DW.Integrator_DSTATE_eo = 0.0F;
    }
  }

  if (test3_B.Compare_io || (test3_DW.Integrator_PrevResetState_pp != 0)) {
    test3_DW.Integrator_DSTATE_eo = test3_U.CellVoltages[51];
    if (test3_DW.Integrator_DSTATE_eo >= 6.0F) {
      test3_DW.Integrator_DSTATE_eo = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_eo <= 0.0F) {
      test3_DW.Integrator_DSTATE_eo = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_eo >= 6.0F) {
    test3_DW.Integrator_DSTATE_eo = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_eo <= 0.0F) {
    test3_DW.Integrator_DSTATE_eo = 0.0F;
  }

  /* RelationalOperator: '<S392>/Compare' incorporates:
   *  Constant: '<S389>/Time constant'
   *  Constant: '<S392>/Constant'
   *  Sum: '<S389>/Sum1'
   */
  test3_B.Compare_ax = ((real32_T)(0.031830988618379068 - test3_B.Probe_j0k[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S394>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kz != 0U) {
    test3_DW.Integrator_DSTATE_cl = test3_U.CellVoltages[52];
    if (test3_DW.Integrator_DSTATE_cl >= 6.0F) {
      test3_DW.Integrator_DSTATE_cl = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_cl <= 0.0F) {
      test3_DW.Integrator_DSTATE_cl = 0.0F;
    }
  }

  if (test3_B.Compare_ax || (test3_DW.Integrator_PrevResetState_ox != 0)) {
    test3_DW.Integrator_DSTATE_cl = test3_U.CellVoltages[52];
    if (test3_DW.Integrator_DSTATE_cl >= 6.0F) {
      test3_DW.Integrator_DSTATE_cl = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_cl <= 0.0F) {
      test3_DW.Integrator_DSTATE_cl = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_cl >= 6.0F) {
    test3_DW.Integrator_DSTATE_cl = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_cl <= 0.0F) {
    test3_DW.Integrator_DSTATE_cl = 0.0F;
  }

  /* RelationalOperator: '<S398>/Compare' incorporates:
   *  Constant: '<S395>/Time constant'
   *  Constant: '<S398>/Constant'
   *  Sum: '<S395>/Sum1'
   */
  test3_B.Compare_gr = ((real32_T)(0.031830988618379068 - test3_B.Probe_gj[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S400>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_b1 != 0U) {
    test3_DW.Integrator_DSTATE_bs = test3_U.CellVoltages[53];
    if (test3_DW.Integrator_DSTATE_bs >= 6.0F) {
      test3_DW.Integrator_DSTATE_bs = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bs <= 0.0F) {
      test3_DW.Integrator_DSTATE_bs = 0.0F;
    }
  }

  if (test3_B.Compare_gr || (test3_DW.Integrator_PrevResetState_fn != 0)) {
    test3_DW.Integrator_DSTATE_bs = test3_U.CellVoltages[53];
    if (test3_DW.Integrator_DSTATE_bs >= 6.0F) {
      test3_DW.Integrator_DSTATE_bs = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bs <= 0.0F) {
      test3_DW.Integrator_DSTATE_bs = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_bs >= 6.0F) {
    test3_DW.Integrator_DSTATE_bs = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bs <= 0.0F) {
    test3_DW.Integrator_DSTATE_bs = 0.0F;
  }

  /* RelationalOperator: '<S404>/Compare' incorporates:
   *  Constant: '<S401>/Time constant'
   *  Constant: '<S404>/Constant'
   *  Sum: '<S401>/Sum1'
   */
  test3_B.Compare_fw = ((real32_T)(0.031830988618379068 - test3_B.Probe_po[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S406>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_j3b != 0U) {
    test3_DW.Integrator_DSTATE_e2 = test3_U.CellVoltages[54];
    if (test3_DW.Integrator_DSTATE_e2 >= 6.0F) {
      test3_DW.Integrator_DSTATE_e2 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_e2 <= 0.0F) {
      test3_DW.Integrator_DSTATE_e2 = 0.0F;
    }
  }

  if (test3_B.Compare_fw || (test3_DW.Integrator_PrevResetState_mk != 0)) {
    test3_DW.Integrator_DSTATE_e2 = test3_U.CellVoltages[54];
    if (test3_DW.Integrator_DSTATE_e2 >= 6.0F) {
      test3_DW.Integrator_DSTATE_e2 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_e2 <= 0.0F) {
      test3_DW.Integrator_DSTATE_e2 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_e2 >= 6.0F) {
    test3_DW.Integrator_DSTATE_e2 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_e2 <= 0.0F) {
    test3_DW.Integrator_DSTATE_e2 = 0.0F;
  }

  /* RelationalOperator: '<S410>/Compare' incorporates:
   *  Constant: '<S407>/Time constant'
   *  Constant: '<S410>/Constant'
   *  Sum: '<S407>/Sum1'
   */
  test3_B.Compare_j = ((real32_T)(0.031830988618379068 - test3_B.Probe_f2[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S412>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ar != 0U) {
    test3_DW.Integrator_DSTATE_lr = test3_U.CellVoltages[55];
    if (test3_DW.Integrator_DSTATE_lr >= 6.0F) {
      test3_DW.Integrator_DSTATE_lr = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_lr <= 0.0F) {
      test3_DW.Integrator_DSTATE_lr = 0.0F;
    }
  }

  if (test3_B.Compare_j || (test3_DW.Integrator_PrevResetState_m1 != 0)) {
    test3_DW.Integrator_DSTATE_lr = test3_U.CellVoltages[55];
    if (test3_DW.Integrator_DSTATE_lr >= 6.0F) {
      test3_DW.Integrator_DSTATE_lr = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_lr <= 0.0F) {
      test3_DW.Integrator_DSTATE_lr = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_lr >= 6.0F) {
    test3_DW.Integrator_DSTATE_lr = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_lr <= 0.0F) {
    test3_DW.Integrator_DSTATE_lr = 0.0F;
  }

  /* RelationalOperator: '<S416>/Compare' incorporates:
   *  Constant: '<S413>/Time constant'
   *  Constant: '<S416>/Constant'
   *  Sum: '<S413>/Sum1'
   */
  test3_B.Compare_m = ((real32_T)(0.031830988618379068 - test3_B.Probe_iz[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S418>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_abx != 0U) {
    test3_DW.Integrator_DSTATE_gx = test3_U.CellVoltages[56];
    if (test3_DW.Integrator_DSTATE_gx >= 6.0F) {
      test3_DW.Integrator_DSTATE_gx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_gx <= 0.0F) {
      test3_DW.Integrator_DSTATE_gx = 0.0F;
    }
  }

  if (test3_B.Compare_m || (test3_DW.Integrator_PrevResetState_dzx != 0)) {
    test3_DW.Integrator_DSTATE_gx = test3_U.CellVoltages[56];
    if (test3_DW.Integrator_DSTATE_gx >= 6.0F) {
      test3_DW.Integrator_DSTATE_gx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_gx <= 0.0F) {
      test3_DW.Integrator_DSTATE_gx = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_gx >= 6.0F) {
    test3_DW.Integrator_DSTATE_gx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_gx <= 0.0F) {
    test3_DW.Integrator_DSTATE_gx = 0.0F;
  }

  /* RelationalOperator: '<S422>/Compare' incorporates:
   *  Constant: '<S419>/Time constant'
   *  Constant: '<S422>/Constant'
   *  Sum: '<S419>/Sum1'
   */
  test3_B.Compare_ac = ((real32_T)(0.031830988618379068 - test3_B.Probe_lv[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S424>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_cy != 0U) {
    test3_DW.Integrator_DSTATE_nu = test3_U.CellVoltages[57];
    if (test3_DW.Integrator_DSTATE_nu >= 6.0F) {
      test3_DW.Integrator_DSTATE_nu = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_nu <= 0.0F) {
      test3_DW.Integrator_DSTATE_nu = 0.0F;
    }
  }

  if (test3_B.Compare_ac || (test3_DW.Integrator_PrevResetState_m5 != 0)) {
    test3_DW.Integrator_DSTATE_nu = test3_U.CellVoltages[57];
    if (test3_DW.Integrator_DSTATE_nu >= 6.0F) {
      test3_DW.Integrator_DSTATE_nu = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_nu <= 0.0F) {
      test3_DW.Integrator_DSTATE_nu = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_nu >= 6.0F) {
    test3_DW.Integrator_DSTATE_nu = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_nu <= 0.0F) {
    test3_DW.Integrator_DSTATE_nu = 0.0F;
  }

  /* RelationalOperator: '<S428>/Compare' incorporates:
   *  Constant: '<S425>/Time constant'
   *  Constant: '<S428>/Constant'
   *  Sum: '<S425>/Sum1'
   */
  test3_B.Compare_bo = ((real32_T)(0.031830988618379068 - test3_B.Probe_ms[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S430>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_b2 != 0U) {
    test3_DW.Integrator_DSTATE_az = test3_U.CellVoltages[58];
    if (test3_DW.Integrator_DSTATE_az >= 6.0F) {
      test3_DW.Integrator_DSTATE_az = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_az <= 0.0F) {
      test3_DW.Integrator_DSTATE_az = 0.0F;
    }
  }

  if (test3_B.Compare_bo || (test3_DW.Integrator_PrevResetState_nv != 0)) {
    test3_DW.Integrator_DSTATE_az = test3_U.CellVoltages[58];
    if (test3_DW.Integrator_DSTATE_az >= 6.0F) {
      test3_DW.Integrator_DSTATE_az = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_az <= 0.0F) {
      test3_DW.Integrator_DSTATE_az = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_az >= 6.0F) {
    test3_DW.Integrator_DSTATE_az = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_az <= 0.0F) {
    test3_DW.Integrator_DSTATE_az = 0.0F;
  }

  /* RelationalOperator: '<S440>/Compare' incorporates:
   *  Constant: '<S437>/Time constant'
   *  Constant: '<S440>/Constant'
   *  Sum: '<S437>/Sum1'
   */
  test3_B.Compare_ng = ((real32_T)(0.031830988618379068 - test3_B.Probe_it[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S442>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_br != 0U) {
    test3_DW.Integrator_DSTATE_kc = test3_U.CellVoltages[59];
    if (test3_DW.Integrator_DSTATE_kc >= 6.0F) {
      test3_DW.Integrator_DSTATE_kc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_kc <= 0.0F) {
      test3_DW.Integrator_DSTATE_kc = 0.0F;
    }
  }

  if (test3_B.Compare_ng || (test3_DW.Integrator_PrevResetState_bw != 0)) {
    test3_DW.Integrator_DSTATE_kc = test3_U.CellVoltages[59];
    if (test3_DW.Integrator_DSTATE_kc >= 6.0F) {
      test3_DW.Integrator_DSTATE_kc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_kc <= 0.0F) {
      test3_DW.Integrator_DSTATE_kc = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_kc >= 6.0F) {
    test3_DW.Integrator_DSTATE_kc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_kc <= 0.0F) {
    test3_DW.Integrator_DSTATE_kc = 0.0F;
  }

  /* RelationalOperator: '<S446>/Compare' incorporates:
   *  Constant: '<S443>/Time constant'
   *  Constant: '<S446>/Constant'
   *  Sum: '<S443>/Sum1'
   */
  test3_B.Compare_ht = ((real32_T)(0.031830988618379068 - test3_B.Probe_cs[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S448>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_du != 0U) {
    test3_DW.Integrator_DSTATE_mc = test3_U.CellVoltages[60];
    if (test3_DW.Integrator_DSTATE_mc >= 6.0F) {
      test3_DW.Integrator_DSTATE_mc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_mc <= 0.0F) {
      test3_DW.Integrator_DSTATE_mc = 0.0F;
    }
  }

  if (test3_B.Compare_ht || (test3_DW.Integrator_PrevResetState_m3 != 0)) {
    test3_DW.Integrator_DSTATE_mc = test3_U.CellVoltages[60];
    if (test3_DW.Integrator_DSTATE_mc >= 6.0F) {
      test3_DW.Integrator_DSTATE_mc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_mc <= 0.0F) {
      test3_DW.Integrator_DSTATE_mc = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_mc >= 6.0F) {
    test3_DW.Integrator_DSTATE_mc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_mc <= 0.0F) {
    test3_DW.Integrator_DSTATE_mc = 0.0F;
  }

  /* RelationalOperator: '<S452>/Compare' incorporates:
   *  Constant: '<S449>/Time constant'
   *  Constant: '<S452>/Constant'
   *  Sum: '<S449>/Sum1'
   */
  test3_B.Compare_im = ((real32_T)(0.031830988618379068 - test3_B.Probe_pa[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S454>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_c3 != 0U) {
    test3_DW.Integrator_DSTATE_nm = test3_U.CellVoltages[61];
    if (test3_DW.Integrator_DSTATE_nm >= 6.0F) {
      test3_DW.Integrator_DSTATE_nm = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_nm <= 0.0F) {
      test3_DW.Integrator_DSTATE_nm = 0.0F;
    }
  }

  if (test3_B.Compare_im || (test3_DW.Integrator_PrevResetState_ei != 0)) {
    test3_DW.Integrator_DSTATE_nm = test3_U.CellVoltages[61];
    if (test3_DW.Integrator_DSTATE_nm >= 6.0F) {
      test3_DW.Integrator_DSTATE_nm = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_nm <= 0.0F) {
      test3_DW.Integrator_DSTATE_nm = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_nm >= 6.0F) {
    test3_DW.Integrator_DSTATE_nm = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_nm <= 0.0F) {
    test3_DW.Integrator_DSTATE_nm = 0.0F;
  }

  /* RelationalOperator: '<S458>/Compare' incorporates:
   *  Constant: '<S455>/Time constant'
   *  Constant: '<S458>/Constant'
   *  Sum: '<S455>/Sum1'
   */
  test3_B.Compare_hg = ((real32_T)(0.031830988618379068 - test3_B.Probe_oq[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S460>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_lm != 0U) {
    test3_DW.Integrator_DSTATE_po = test3_U.CellVoltages[62];
    if (test3_DW.Integrator_DSTATE_po >= 6.0F) {
      test3_DW.Integrator_DSTATE_po = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_po <= 0.0F) {
      test3_DW.Integrator_DSTATE_po = 0.0F;
    }
  }

  if (test3_B.Compare_hg || (test3_DW.Integrator_PrevResetState_o1 != 0)) {
    test3_DW.Integrator_DSTATE_po = test3_U.CellVoltages[62];
    if (test3_DW.Integrator_DSTATE_po >= 6.0F) {
      test3_DW.Integrator_DSTATE_po = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_po <= 0.0F) {
      test3_DW.Integrator_DSTATE_po = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_po >= 6.0F) {
    test3_DW.Integrator_DSTATE_po = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_po <= 0.0F) {
    test3_DW.Integrator_DSTATE_po = 0.0F;
  }

  /* RelationalOperator: '<S464>/Compare' incorporates:
   *  Constant: '<S461>/Time constant'
   *  Constant: '<S464>/Constant'
   *  Sum: '<S461>/Sum1'
   */
  test3_B.Compare_kj = ((real32_T)(0.031830988618379068 - test3_B.Probe_hl[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S466>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kk != 0U) {
    test3_DW.Integrator_DSTATE_bt = test3_U.CellVoltages[63];
    if (test3_DW.Integrator_DSTATE_bt >= 6.0F) {
      test3_DW.Integrator_DSTATE_bt = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bt <= 0.0F) {
      test3_DW.Integrator_DSTATE_bt = 0.0F;
    }
  }

  if (test3_B.Compare_kj || (test3_DW.Integrator_PrevResetState_gv != 0)) {
    test3_DW.Integrator_DSTATE_bt = test3_U.CellVoltages[63];
    if (test3_DW.Integrator_DSTATE_bt >= 6.0F) {
      test3_DW.Integrator_DSTATE_bt = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_bt <= 0.0F) {
      test3_DW.Integrator_DSTATE_bt = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_bt >= 6.0F) {
    test3_DW.Integrator_DSTATE_bt = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bt <= 0.0F) {
    test3_DW.Integrator_DSTATE_bt = 0.0F;
  }

  /* RelationalOperator: '<S470>/Compare' incorporates:
   *  Constant: '<S467>/Time constant'
   *  Constant: '<S470>/Constant'
   *  Sum: '<S467>/Sum1'
   */
  test3_B.Compare_id = ((real32_T)(0.031830988618379068 - test3_B.Probe_hz[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S472>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_km != 0U) {
    test3_DW.Integrator_DSTATE_jt = test3_U.CellVoltages[64];
    if (test3_DW.Integrator_DSTATE_jt >= 6.0F) {
      test3_DW.Integrator_DSTATE_jt = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_jt <= 0.0F) {
      test3_DW.Integrator_DSTATE_jt = 0.0F;
    }
  }

  if (test3_B.Compare_id || (test3_DW.Integrator_PrevResetState_hf != 0)) {
    test3_DW.Integrator_DSTATE_jt = test3_U.CellVoltages[64];
    if (test3_DW.Integrator_DSTATE_jt >= 6.0F) {
      test3_DW.Integrator_DSTATE_jt = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_jt <= 0.0F) {
      test3_DW.Integrator_DSTATE_jt = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_jt >= 6.0F) {
    test3_DW.Integrator_DSTATE_jt = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_jt <= 0.0F) {
    test3_DW.Integrator_DSTATE_jt = 0.0F;
  }

  /* RelationalOperator: '<S476>/Compare' incorporates:
   *  Constant: '<S473>/Time constant'
   *  Constant: '<S476>/Constant'
   *  Sum: '<S473>/Sum1'
   */
  test3_B.Compare_ff = ((real32_T)(0.031830988618379068 - test3_B.Probe_be[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S478>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_oex != 0U) {
    test3_DW.Integrator_DSTATE_dc = test3_U.CellVoltages[65];
    if (test3_DW.Integrator_DSTATE_dc >= 6.0F) {
      test3_DW.Integrator_DSTATE_dc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_dc <= 0.0F) {
      test3_DW.Integrator_DSTATE_dc = 0.0F;
    }
  }

  if (test3_B.Compare_ff || (test3_DW.Integrator_PrevResetState_gs != 0)) {
    test3_DW.Integrator_DSTATE_dc = test3_U.CellVoltages[65];
    if (test3_DW.Integrator_DSTATE_dc >= 6.0F) {
      test3_DW.Integrator_DSTATE_dc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_dc <= 0.0F) {
      test3_DW.Integrator_DSTATE_dc = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_dc >= 6.0F) {
    test3_DW.Integrator_DSTATE_dc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_dc <= 0.0F) {
    test3_DW.Integrator_DSTATE_dc = 0.0F;
  }

  /* RelationalOperator: '<S482>/Compare' incorporates:
   *  Constant: '<S479>/Time constant'
   *  Constant: '<S482>/Constant'
   *  Sum: '<S479>/Sum1'
   */
  test3_B.Compare_kn = ((real32_T)(0.031830988618379068 - test3_B.Probe_c2[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S484>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kp != 0U) {
    test3_DW.Integrator_DSTATE_pb = test3_U.CellVoltages[66];
    if (test3_DW.Integrator_DSTATE_pb >= 6.0F) {
      test3_DW.Integrator_DSTATE_pb = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pb <= 0.0F) {
      test3_DW.Integrator_DSTATE_pb = 0.0F;
    }
  }

  if (test3_B.Compare_kn || (test3_DW.Integrator_PrevResetState_fyk != 0)) {
    test3_DW.Integrator_DSTATE_pb = test3_U.CellVoltages[66];
    if (test3_DW.Integrator_DSTATE_pb >= 6.0F) {
      test3_DW.Integrator_DSTATE_pb = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pb <= 0.0F) {
      test3_DW.Integrator_DSTATE_pb = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_pb >= 6.0F) {
    test3_DW.Integrator_DSTATE_pb = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pb <= 0.0F) {
    test3_DW.Integrator_DSTATE_pb = 0.0F;
  }

  /* RelationalOperator: '<S488>/Compare' incorporates:
   *  Constant: '<S485>/Time constant'
   *  Constant: '<S488>/Constant'
   *  Sum: '<S485>/Sum1'
   */
  test3_B.Compare_g5 = ((real32_T)(0.031830988618379068 - test3_B.Probe_eq[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S490>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ew != 0U) {
    test3_DW.Integrator_DSTATE_oe = test3_U.CellVoltages[67];
    if (test3_DW.Integrator_DSTATE_oe >= 6.0F) {
      test3_DW.Integrator_DSTATE_oe = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_oe <= 0.0F) {
      test3_DW.Integrator_DSTATE_oe = 0.0F;
    }
  }

  if (test3_B.Compare_g5 || (test3_DW.Integrator_PrevResetState_kl != 0)) {
    test3_DW.Integrator_DSTATE_oe = test3_U.CellVoltages[67];
    if (test3_DW.Integrator_DSTATE_oe >= 6.0F) {
      test3_DW.Integrator_DSTATE_oe = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_oe <= 0.0F) {
      test3_DW.Integrator_DSTATE_oe = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_oe >= 6.0F) {
    test3_DW.Integrator_DSTATE_oe = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_oe <= 0.0F) {
    test3_DW.Integrator_DSTATE_oe = 0.0F;
  }

  /* RelationalOperator: '<S494>/Compare' incorporates:
   *  Constant: '<S491>/Time constant'
   *  Constant: '<S494>/Constant'
   *  Sum: '<S491>/Sum1'
   */
  test3_B.Compare_ou = ((real32_T)(0.031830988618379068 - test3_B.Probe_aj[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S496>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bk != 0U) {
    test3_DW.Integrator_DSTATE_al = test3_U.CellVoltages[68];
    if (test3_DW.Integrator_DSTATE_al >= 6.0F) {
      test3_DW.Integrator_DSTATE_al = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_al <= 0.0F) {
      test3_DW.Integrator_DSTATE_al = 0.0F;
    }
  }

  if (test3_B.Compare_ou || (test3_DW.Integrator_PrevResetState_nk != 0)) {
    test3_DW.Integrator_DSTATE_al = test3_U.CellVoltages[68];
    if (test3_DW.Integrator_DSTATE_al >= 6.0F) {
      test3_DW.Integrator_DSTATE_al = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_al <= 0.0F) {
      test3_DW.Integrator_DSTATE_al = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_al >= 6.0F) {
    test3_DW.Integrator_DSTATE_al = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_al <= 0.0F) {
    test3_DW.Integrator_DSTATE_al = 0.0F;
  }

  /* RelationalOperator: '<S506>/Compare' incorporates:
   *  Constant: '<S503>/Time constant'
   *  Constant: '<S506>/Constant'
   *  Sum: '<S503>/Sum1'
   */
  test3_B.Compare_eq = ((real32_T)(0.031830988618379068 - test3_B.Probe_hs[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S508>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_j31 != 0U) {
    test3_DW.Integrator_DSTATE_cx = test3_U.CellVoltages[69];
    if (test3_DW.Integrator_DSTATE_cx >= 6.0F) {
      test3_DW.Integrator_DSTATE_cx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_cx <= 0.0F) {
      test3_DW.Integrator_DSTATE_cx = 0.0F;
    }
  }

  if (test3_B.Compare_eq || (test3_DW.Integrator_PrevResetState_ln != 0)) {
    test3_DW.Integrator_DSTATE_cx = test3_U.CellVoltages[69];
    if (test3_DW.Integrator_DSTATE_cx >= 6.0F) {
      test3_DW.Integrator_DSTATE_cx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_cx <= 0.0F) {
      test3_DW.Integrator_DSTATE_cx = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_cx >= 6.0F) {
    test3_DW.Integrator_DSTATE_cx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_cx <= 0.0F) {
    test3_DW.Integrator_DSTATE_cx = 0.0F;
  }

  /* RelationalOperator: '<S512>/Compare' incorporates:
   *  Constant: '<S509>/Time constant'
   *  Constant: '<S512>/Constant'
   *  Sum: '<S509>/Sum1'
   */
  test3_B.Compare_l5 = ((real32_T)(0.031830988618379068 - test3_B.Probe_kp[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S514>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_mo != 0U) {
    test3_DW.Integrator_DSTATE_cr = test3_U.CellVoltages[70];
    if (test3_DW.Integrator_DSTATE_cr >= 6.0F) {
      test3_DW.Integrator_DSTATE_cr = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_cr <= 0.0F) {
      test3_DW.Integrator_DSTATE_cr = 0.0F;
    }
  }

  if (test3_B.Compare_l5 || (test3_DW.Integrator_PrevResetState_oe != 0)) {
    test3_DW.Integrator_DSTATE_cr = test3_U.CellVoltages[70];
    if (test3_DW.Integrator_DSTATE_cr >= 6.0F) {
      test3_DW.Integrator_DSTATE_cr = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_cr <= 0.0F) {
      test3_DW.Integrator_DSTATE_cr = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_cr >= 6.0F) {
    test3_DW.Integrator_DSTATE_cr = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_cr <= 0.0F) {
    test3_DW.Integrator_DSTATE_cr = 0.0F;
  }

  /* RelationalOperator: '<S518>/Compare' incorporates:
   *  Constant: '<S515>/Time constant'
   *  Constant: '<S518>/Constant'
   *  Sum: '<S515>/Sum1'
   */
  test3_B.Compare_fs = ((real32_T)(0.031830988618379068 - test3_B.Probe_jn[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S520>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_abf != 0U) {
    test3_DW.Integrator_DSTATE_p3 = test3_U.CellVoltages[71];
    if (test3_DW.Integrator_DSTATE_p3 >= 6.0F) {
      test3_DW.Integrator_DSTATE_p3 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_p3 <= 0.0F) {
      test3_DW.Integrator_DSTATE_p3 = 0.0F;
    }
  }

  if (test3_B.Compare_fs || (test3_DW.Integrator_PrevResetState_hu != 0)) {
    test3_DW.Integrator_DSTATE_p3 = test3_U.CellVoltages[71];
    if (test3_DW.Integrator_DSTATE_p3 >= 6.0F) {
      test3_DW.Integrator_DSTATE_p3 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_p3 <= 0.0F) {
      test3_DW.Integrator_DSTATE_p3 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_p3 >= 6.0F) {
    test3_DW.Integrator_DSTATE_p3 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_p3 <= 0.0F) {
    test3_DW.Integrator_DSTATE_p3 = 0.0F;
  }

  /* RelationalOperator: '<S524>/Compare' incorporates:
   *  Constant: '<S521>/Time constant'
   *  Constant: '<S524>/Constant'
   *  Sum: '<S521>/Sum1'
   */
  test3_B.Compare_c = ((real32_T)(0.031830988618379068 - test3_B.Probe_dh[0]) <=
                       0.0F);

  /* DiscreteIntegrator: '<S526>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ho != 0U) {
    test3_DW.Integrator_DSTATE_kv = test3_U.CellVoltages[72];
    if (test3_DW.Integrator_DSTATE_kv >= 6.0F) {
      test3_DW.Integrator_DSTATE_kv = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_kv <= 0.0F) {
      test3_DW.Integrator_DSTATE_kv = 0.0F;
    }
  }

  if (test3_B.Compare_c || (test3_DW.Integrator_PrevResetState_mr != 0)) {
    test3_DW.Integrator_DSTATE_kv = test3_U.CellVoltages[72];
    if (test3_DW.Integrator_DSTATE_kv >= 6.0F) {
      test3_DW.Integrator_DSTATE_kv = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_kv <= 0.0F) {
      test3_DW.Integrator_DSTATE_kv = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_kv >= 6.0F) {
    test3_DW.Integrator_DSTATE_kv = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_kv <= 0.0F) {
    test3_DW.Integrator_DSTATE_kv = 0.0F;
  }

  /* RelationalOperator: '<S530>/Compare' incorporates:
   *  Constant: '<S527>/Time constant'
   *  Constant: '<S530>/Constant'
   *  Sum: '<S527>/Sum1'
   */
  test3_B.Compare_f3 = ((real32_T)(0.031830988618379068 - test3_B.Probe_bg[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S532>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ph != 0U) {
    test3_DW.Integrator_DSTATE_ed = test3_U.CellVoltages[73];
    if (test3_DW.Integrator_DSTATE_ed >= 6.0F) {
      test3_DW.Integrator_DSTATE_ed = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ed <= 0.0F) {
      test3_DW.Integrator_DSTATE_ed = 0.0F;
    }
  }

  if (test3_B.Compare_f3 || (test3_DW.Integrator_PrevResetState_ec != 0)) {
    test3_DW.Integrator_DSTATE_ed = test3_U.CellVoltages[73];
    if (test3_DW.Integrator_DSTATE_ed >= 6.0F) {
      test3_DW.Integrator_DSTATE_ed = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ed <= 0.0F) {
      test3_DW.Integrator_DSTATE_ed = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ed >= 6.0F) {
    test3_DW.Integrator_DSTATE_ed = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ed <= 0.0F) {
    test3_DW.Integrator_DSTATE_ed = 0.0F;
  }

  /* RelationalOperator: '<S536>/Compare' incorporates:
   *  Constant: '<S533>/Time constant'
   *  Constant: '<S536>/Constant'
   *  Sum: '<S533>/Sum1'
   */
  test3_B.Compare_lf = ((real32_T)(0.031830988618379068 - test3_B.Probe_hb[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S538>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_da != 0U) {
    test3_DW.Integrator_DSTATE_fu = test3_U.CellVoltages[74];
    if (test3_DW.Integrator_DSTATE_fu >= 6.0F) {
      test3_DW.Integrator_DSTATE_fu = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fu <= 0.0F) {
      test3_DW.Integrator_DSTATE_fu = 0.0F;
    }
  }

  if (test3_B.Compare_lf || (test3_DW.Integrator_PrevResetState_bb != 0)) {
    test3_DW.Integrator_DSTATE_fu = test3_U.CellVoltages[74];
    if (test3_DW.Integrator_DSTATE_fu >= 6.0F) {
      test3_DW.Integrator_DSTATE_fu = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fu <= 0.0F) {
      test3_DW.Integrator_DSTATE_fu = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_fu >= 6.0F) {
    test3_DW.Integrator_DSTATE_fu = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fu <= 0.0F) {
    test3_DW.Integrator_DSTATE_fu = 0.0F;
  }

  /* RelationalOperator: '<S542>/Compare' incorporates:
   *  Constant: '<S539>/Time constant'
   *  Constant: '<S542>/Constant'
   *  Sum: '<S539>/Sum1'
   */
  test3_B.Compare_bi = ((real32_T)(0.031830988618379068 - test3_B.Probe_gk[0]) <=
                        0.0F);

  /* DiscreteIntegrator: '<S544>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_cg != 0U) {
    test3_DW.Integrator_DSTATE_he = test3_U.CellVoltages[75];
    if (test3_DW.Integrator_DSTATE_he >= 6.0F) {
      test3_DW.Integrator_DSTATE_he = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_he <= 0.0F) {
      test3_DW.Integrator_DSTATE_he = 0.0F;
    }
  }

  if (test3_B.Compare_bi || (test3_DW.Integrator_PrevResetState_n1 != 0)) {
    test3_DW.Integrator_DSTATE_he = test3_U.CellVoltages[75];
    if (test3_DW.Integrator_DSTATE_he >= 6.0F) {
      test3_DW.Integrator_DSTATE_he = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_he <= 0.0F) {
      test3_DW.Integrator_DSTATE_he = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_he >= 6.0F) {
    test3_DW.Integrator_DSTATE_he = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_he <= 0.0F) {
    test3_DW.Integrator_DSTATE_he = 0.0F;
  }

  /* RelationalOperator: '<S548>/Compare' incorporates:
   *  Constant: '<S545>/Time constant'
   *  Constant: '<S548>/Constant'
   *  Sum: '<S545>/Sum1'
   */
  test3_B.Compare_bnj = ((real32_T)(0.031830988618379068 - test3_B.Probe_ny[0]) <=
    0.0F);

  /* DiscreteIntegrator: '<S550>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_d3 != 0U) {
    test3_DW.Integrator_DSTATE_ot = test3_U.CellVoltages[76];
    if (test3_DW.Integrator_DSTATE_ot >= 6.0F) {
      test3_DW.Integrator_DSTATE_ot = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ot <= 0.0F) {
      test3_DW.Integrator_DSTATE_ot = 0.0F;
    }
  }

  if (test3_B.Compare_bnj || (test3_DW.Integrator_PrevResetState_iw != 0)) {
    test3_DW.Integrator_DSTATE_ot = test3_U.CellVoltages[76];
    if (test3_DW.Integrator_DSTATE_ot >= 6.0F) {
      test3_DW.Integrator_DSTATE_ot = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ot <= 0.0F) {
      test3_DW.Integrator_DSTATE_ot = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ot >= 6.0F) {
    test3_DW.Integrator_DSTATE_ot = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ot <= 0.0F) {
    test3_DW.Integrator_DSTATE_ot = 0.0F;
  }

  /* RelationalOperator: '<S554>/Compare' incorporates:
   *  Constant: '<S551>/Time constant'
   *  Constant: '<S554>/Constant'
   *  Sum: '<S551>/Sum1'
   */
  rtb_Compare_aw = ((real32_T)(0.031830988618379068 - test3_B.Probe_k0[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S556>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_d0 != 0U) {
    test3_DW.Integrator_DSTATE_my = test3_U.CellVoltages[77];
    if (test3_DW.Integrator_DSTATE_my >= 6.0F) {
      test3_DW.Integrator_DSTATE_my = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_my <= 0.0F) {
      test3_DW.Integrator_DSTATE_my = 0.0F;
    }
  }

  if (rtb_Compare_aw || (test3_DW.Integrator_PrevResetState_gg != 0)) {
    test3_DW.Integrator_DSTATE_my = test3_U.CellVoltages[77];
    if (test3_DW.Integrator_DSTATE_my >= 6.0F) {
      test3_DW.Integrator_DSTATE_my = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_my <= 0.0F) {
      test3_DW.Integrator_DSTATE_my = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_my >= 6.0F) {
    test3_DW.Integrator_DSTATE_my = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_my <= 0.0F) {
    test3_DW.Integrator_DSTATE_my = 0.0F;
  }

  /* RelationalOperator: '<S560>/Compare' incorporates:
   *  Constant: '<S557>/Time constant'
   *  Constant: '<S560>/Constant'
   *  Sum: '<S557>/Sum1'
   */
  rtb_Compare_gz = ((real32_T)(0.031830988618379068 - test3_B.Probe_ic[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S562>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_mg != 0U) {
    test3_DW.Integrator_DSTATE_lt = test3_U.CellVoltages[78];
    if (test3_DW.Integrator_DSTATE_lt >= 6.0F) {
      test3_DW.Integrator_DSTATE_lt = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_lt <= 0.0F) {
      test3_DW.Integrator_DSTATE_lt = 0.0F;
    }
  }

  if (rtb_Compare_gz || (test3_DW.Integrator_PrevResetState_lz != 0)) {
    test3_DW.Integrator_DSTATE_lt = test3_U.CellVoltages[78];
    if (test3_DW.Integrator_DSTATE_lt >= 6.0F) {
      test3_DW.Integrator_DSTATE_lt = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_lt <= 0.0F) {
      test3_DW.Integrator_DSTATE_lt = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_lt >= 6.0F) {
    test3_DW.Integrator_DSTATE_lt = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_lt <= 0.0F) {
    test3_DW.Integrator_DSTATE_lt = 0.0F;
  }

  /* RelationalOperator: '<S572>/Compare' incorporates:
   *  Constant: '<S569>/Time constant'
   *  Constant: '<S572>/Constant'
   *  Sum: '<S569>/Sum1'
   */
  rtb_Compare_ms = ((real32_T)(0.031830988618379068 - test3_B.Probe_lg[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S574>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_e3 != 0U) {
    test3_DW.Integrator_DSTATE_pd = test3_U.CellVoltages[79];
    if (test3_DW.Integrator_DSTATE_pd >= 6.0F) {
      test3_DW.Integrator_DSTATE_pd = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pd <= 0.0F) {
      test3_DW.Integrator_DSTATE_pd = 0.0F;
    }
  }

  if (rtb_Compare_ms || (test3_DW.Integrator_PrevResetState_dkv != 0)) {
    test3_DW.Integrator_DSTATE_pd = test3_U.CellVoltages[79];
    if (test3_DW.Integrator_DSTATE_pd >= 6.0F) {
      test3_DW.Integrator_DSTATE_pd = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pd <= 0.0F) {
      test3_DW.Integrator_DSTATE_pd = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_pd >= 6.0F) {
    test3_DW.Integrator_DSTATE_pd = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pd <= 0.0F) {
    test3_DW.Integrator_DSTATE_pd = 0.0F;
  }

  /* RelationalOperator: '<S578>/Compare' incorporates:
   *  Constant: '<S575>/Time constant'
   *  Constant: '<S578>/Constant'
   *  Sum: '<S575>/Sum1'
   */
  rtb_Compare_ar = ((real32_T)(0.031830988618379068 - test3_B.Probe_fh[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S580>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ns != 0U) {
    test3_DW.Integrator_DSTATE_en = test3_U.CellVoltages[80];
    if (test3_DW.Integrator_DSTATE_en >= 6.0F) {
      test3_DW.Integrator_DSTATE_en = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_en <= 0.0F) {
      test3_DW.Integrator_DSTATE_en = 0.0F;
    }
  }

  if (rtb_Compare_ar || (test3_DW.Integrator_PrevResetState_bq != 0)) {
    test3_DW.Integrator_DSTATE_en = test3_U.CellVoltages[80];
    if (test3_DW.Integrator_DSTATE_en >= 6.0F) {
      test3_DW.Integrator_DSTATE_en = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_en <= 0.0F) {
      test3_DW.Integrator_DSTATE_en = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_en >= 6.0F) {
    test3_DW.Integrator_DSTATE_en = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_en <= 0.0F) {
    test3_DW.Integrator_DSTATE_en = 0.0F;
  }

  /* RelationalOperator: '<S584>/Compare' incorporates:
   *  Constant: '<S581>/Time constant'
   *  Constant: '<S584>/Constant'
   *  Sum: '<S581>/Sum1'
   */
  rtb_Compare_euj = ((real32_T)(0.031830988618379068 - test3_B.Probe_eh[0]) <=
                     0.0F);

  /* DiscreteIntegrator: '<S586>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_hp != 0U) {
    test3_DW.Integrator_DSTATE_ix = test3_U.CellVoltages[81];
    if (test3_DW.Integrator_DSTATE_ix >= 6.0F) {
      test3_DW.Integrator_DSTATE_ix = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ix <= 0.0F) {
      test3_DW.Integrator_DSTATE_ix = 0.0F;
    }
  }

  if (rtb_Compare_euj || (test3_DW.Integrator_PrevResetState_pb != 0)) {
    test3_DW.Integrator_DSTATE_ix = test3_U.CellVoltages[81];
    if (test3_DW.Integrator_DSTATE_ix >= 6.0F) {
      test3_DW.Integrator_DSTATE_ix = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ix <= 0.0F) {
      test3_DW.Integrator_DSTATE_ix = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ix >= 6.0F) {
    test3_DW.Integrator_DSTATE_ix = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ix <= 0.0F) {
    test3_DW.Integrator_DSTATE_ix = 0.0F;
  }

  /* RelationalOperator: '<S590>/Compare' incorporates:
   *  Constant: '<S587>/Time constant'
   *  Constant: '<S590>/Constant'
   *  Sum: '<S587>/Sum1'
   */
  rtb_Compare_gk = ((real32_T)(0.031830988618379068 - test3_B.Probe_nl[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S592>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_a0 != 0U) {
    test3_DW.Integrator_DSTATE_hg = test3_U.CellVoltages[82];
    if (test3_DW.Integrator_DSTATE_hg >= 6.0F) {
      test3_DW.Integrator_DSTATE_hg = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_hg <= 0.0F) {
      test3_DW.Integrator_DSTATE_hg = 0.0F;
    }
  }

  if (rtb_Compare_gk || (test3_DW.Integrator_PrevResetState_ew != 0)) {
    test3_DW.Integrator_DSTATE_hg = test3_U.CellVoltages[82];
    if (test3_DW.Integrator_DSTATE_hg >= 6.0F) {
      test3_DW.Integrator_DSTATE_hg = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_hg <= 0.0F) {
      test3_DW.Integrator_DSTATE_hg = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_hg >= 6.0F) {
    test3_DW.Integrator_DSTATE_hg = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_hg <= 0.0F) {
    test3_DW.Integrator_DSTATE_hg = 0.0F;
  }

  /* RelationalOperator: '<S596>/Compare' incorporates:
   *  Constant: '<S593>/Time constant'
   *  Constant: '<S596>/Constant'
   *  Sum: '<S593>/Sum1'
   */
  rtb_Compare_lu = ((real32_T)(0.031830988618379068 - test3_B.Probe_bo[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S598>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bo != 0U) {
    test3_DW.Integrator_DSTATE_fm = test3_U.CellVoltages[83];
    if (test3_DW.Integrator_DSTATE_fm >= 6.0F) {
      test3_DW.Integrator_DSTATE_fm = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fm <= 0.0F) {
      test3_DW.Integrator_DSTATE_fm = 0.0F;
    }
  }

  if (rtb_Compare_lu || (test3_DW.Integrator_PrevResetState_pl != 0)) {
    test3_DW.Integrator_DSTATE_fm = test3_U.CellVoltages[83];
    if (test3_DW.Integrator_DSTATE_fm >= 6.0F) {
      test3_DW.Integrator_DSTATE_fm = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_fm <= 0.0F) {
      test3_DW.Integrator_DSTATE_fm = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_fm >= 6.0F) {
    test3_DW.Integrator_DSTATE_fm = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fm <= 0.0F) {
    test3_DW.Integrator_DSTATE_fm = 0.0F;
  }

  /* RelationalOperator: '<S602>/Compare' incorporates:
   *  Constant: '<S599>/Time constant'
   *  Constant: '<S602>/Constant'
   *  Sum: '<S599>/Sum1'
   */
  rtb_Compare_gb = ((real32_T)(0.031830988618379068 - test3_B.Probe_kb[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S604>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kq != 0U) {
    test3_DW.Integrator_DSTATE_ok = test3_U.CellVoltages[84];
    if (test3_DW.Integrator_DSTATE_ok >= 6.0F) {
      test3_DW.Integrator_DSTATE_ok = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ok <= 0.0F) {
      test3_DW.Integrator_DSTATE_ok = 0.0F;
    }
  }

  if (rtb_Compare_gb || (test3_DW.Integrator_PrevResetState_mu != 0)) {
    test3_DW.Integrator_DSTATE_ok = test3_U.CellVoltages[84];
    if (test3_DW.Integrator_DSTATE_ok >= 6.0F) {
      test3_DW.Integrator_DSTATE_ok = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ok <= 0.0F) {
      test3_DW.Integrator_DSTATE_ok = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ok >= 6.0F) {
    test3_DW.Integrator_DSTATE_ok = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ok <= 0.0F) {
    test3_DW.Integrator_DSTATE_ok = 0.0F;
  }

  /* RelationalOperator: '<S608>/Compare' incorporates:
   *  Constant: '<S605>/Time constant'
   *  Constant: '<S608>/Constant'
   *  Sum: '<S605>/Sum1'
   */
  rtb_Compare_b4 = ((real32_T)(0.031830988618379068 - test3_B.Probe_l3[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S610>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_h2 != 0U) {
    test3_DW.Integrator_DSTATE_ns = test3_U.CellVoltages[85];
    if (test3_DW.Integrator_DSTATE_ns >= 6.0F) {
      test3_DW.Integrator_DSTATE_ns = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ns <= 0.0F) {
      test3_DW.Integrator_DSTATE_ns = 0.0F;
    }
  }

  if (rtb_Compare_b4 || (test3_DW.Integrator_PrevResetState_e4 != 0)) {
    test3_DW.Integrator_DSTATE_ns = test3_U.CellVoltages[85];
    if (test3_DW.Integrator_DSTATE_ns >= 6.0F) {
      test3_DW.Integrator_DSTATE_ns = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ns <= 0.0F) {
      test3_DW.Integrator_DSTATE_ns = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ns >= 6.0F) {
    test3_DW.Integrator_DSTATE_ns = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ns <= 0.0F) {
    test3_DW.Integrator_DSTATE_ns = 0.0F;
  }

  /* RelationalOperator: '<S614>/Compare' incorporates:
   *  Constant: '<S611>/Time constant'
   *  Constant: '<S614>/Constant'
   *  Sum: '<S611>/Sum1'
   */
  rtb_Compare_l0 = ((real32_T)(0.031830988618379068 - test3_B.Probe_j0n[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S616>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kkm != 0U) {
    test3_DW.Integrator_DSTATE_ga = test3_U.CellVoltages[86];
    if (test3_DW.Integrator_DSTATE_ga >= 6.0F) {
      test3_DW.Integrator_DSTATE_ga = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ga <= 0.0F) {
      test3_DW.Integrator_DSTATE_ga = 0.0F;
    }
  }

  if (rtb_Compare_l0 || (test3_DW.Integrator_PrevResetState_jl != 0)) {
    test3_DW.Integrator_DSTATE_ga = test3_U.CellVoltages[86];
    if (test3_DW.Integrator_DSTATE_ga >= 6.0F) {
      test3_DW.Integrator_DSTATE_ga = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_ga <= 0.0F) {
      test3_DW.Integrator_DSTATE_ga = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_ga >= 6.0F) {
    test3_DW.Integrator_DSTATE_ga = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ga <= 0.0F) {
    test3_DW.Integrator_DSTATE_ga = 0.0F;
  }

  /* RelationalOperator: '<S620>/Compare' incorporates:
   *  Constant: '<S617>/Time constant'
   *  Constant: '<S620>/Constant'
   *  Sum: '<S617>/Sum1'
   */
  rtb_Compare_da = ((real32_T)(0.031830988618379068 - test3_B.Probe_pu[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S622>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bz != 0U) {
    test3_DW.Integrator_DSTATE_dsn = test3_U.CellVoltages[87];
    if (test3_DW.Integrator_DSTATE_dsn >= 6.0F) {
      test3_DW.Integrator_DSTATE_dsn = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_dsn <= 0.0F) {
      test3_DW.Integrator_DSTATE_dsn = 0.0F;
    }
  }

  if (rtb_Compare_da || (test3_DW.Integrator_PrevResetState_cx != 0)) {
    test3_DW.Integrator_DSTATE_dsn = test3_U.CellVoltages[87];
    if (test3_DW.Integrator_DSTATE_dsn >= 6.0F) {
      test3_DW.Integrator_DSTATE_dsn = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_dsn <= 0.0F) {
      test3_DW.Integrator_DSTATE_dsn = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_dsn >= 6.0F) {
    test3_DW.Integrator_DSTATE_dsn = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_dsn <= 0.0F) {
    test3_DW.Integrator_DSTATE_dsn = 0.0F;
  }

  /* RelationalOperator: '<S626>/Compare' incorporates:
   *  Constant: '<S623>/Time constant'
   *  Constant: '<S626>/Constant'
   *  Sum: '<S623>/Sum1'
   */
  rtb_Compare_cm = ((real32_T)(0.031830988618379068 - test3_B.Probe_jw[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S628>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_o1 != 0U) {
    test3_DW.Integrator_DSTATE_pc = test3_U.CellVoltages[88];
    if (test3_DW.Integrator_DSTATE_pc >= 6.0F) {
      test3_DW.Integrator_DSTATE_pc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pc <= 0.0F) {
      test3_DW.Integrator_DSTATE_pc = 0.0F;
    }
  }

  if (rtb_Compare_cm || (test3_DW.Integrator_PrevResetState_mm != 0)) {
    test3_DW.Integrator_DSTATE_pc = test3_U.CellVoltages[88];
    if (test3_DW.Integrator_DSTATE_pc >= 6.0F) {
      test3_DW.Integrator_DSTATE_pc = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_pc <= 0.0F) {
      test3_DW.Integrator_DSTATE_pc = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_pc >= 6.0F) {
    test3_DW.Integrator_DSTATE_pc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pc <= 0.0F) {
    test3_DW.Integrator_DSTATE_pc = 0.0F;
  }

  /* RelationalOperator: '<S638>/Compare' incorporates:
   *  Constant: '<S635>/Time constant'
   *  Constant: '<S638>/Constant'
   *  Sum: '<S635>/Sum1'
   */
  rtb_Compare_et = ((real32_T)(0.031830988618379068 - test3_B.Probe_g2[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S640>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_fcd != 0U) {
    test3_DW.Integrator_DSTATE_eg = test3_U.CellVoltages[89];
    if (test3_DW.Integrator_DSTATE_eg >= 6.0F) {
      test3_DW.Integrator_DSTATE_eg = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_eg <= 0.0F) {
      test3_DW.Integrator_DSTATE_eg = 0.0F;
    }
  }

  if (rtb_Compare_et || (test3_DW.Integrator_PrevResetState_pg != 0)) {
    test3_DW.Integrator_DSTATE_eg = test3_U.CellVoltages[89];
    if (test3_DW.Integrator_DSTATE_eg >= 6.0F) {
      test3_DW.Integrator_DSTATE_eg = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_eg <= 0.0F) {
      test3_DW.Integrator_DSTATE_eg = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_eg >= 6.0F) {
    test3_DW.Integrator_DSTATE_eg = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_eg <= 0.0F) {
    test3_DW.Integrator_DSTATE_eg = 0.0F;
  }

  /* RelationalOperator: '<S644>/Compare' incorporates:
   *  Constant: '<S641>/Time constant'
   *  Constant: '<S644>/Constant'
   *  Sum: '<S641>/Sum1'
   */
  rtb_Compare_eo = ((real32_T)(0.031830988618379068 - test3_B.Probe_opc[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S646>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_bp != 0U) {
    test3_DW.Integrator_DSTATE_jx = test3_U.CellVoltages[90];
    if (test3_DW.Integrator_DSTATE_jx >= 6.0F) {
      test3_DW.Integrator_DSTATE_jx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_jx <= 0.0F) {
      test3_DW.Integrator_DSTATE_jx = 0.0F;
    }
  }

  if (rtb_Compare_eo || (test3_DW.Integrator_PrevResetState_md != 0)) {
    test3_DW.Integrator_DSTATE_jx = test3_U.CellVoltages[90];
    if (test3_DW.Integrator_DSTATE_jx >= 6.0F) {
      test3_DW.Integrator_DSTATE_jx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_jx <= 0.0F) {
      test3_DW.Integrator_DSTATE_jx = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_jx >= 6.0F) {
    test3_DW.Integrator_DSTATE_jx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_jx <= 0.0F) {
    test3_DW.Integrator_DSTATE_jx = 0.0F;
  }

  /* RelationalOperator: '<S650>/Compare' incorporates:
   *  Constant: '<S647>/Time constant'
   *  Constant: '<S650>/Constant'
   *  Sum: '<S647>/Sum1'
   */
  rtb_Compare_pd = ((real32_T)(0.031830988618379068 - test3_B.Probe_lf[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S652>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_ad != 0U) {
    test3_DW.Integrator_DSTATE_im = test3_U.CellVoltages[91];
    if (test3_DW.Integrator_DSTATE_im >= 6.0F) {
      test3_DW.Integrator_DSTATE_im = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_im <= 0.0F) {
      test3_DW.Integrator_DSTATE_im = 0.0F;
    }
  }

  if (rtb_Compare_pd || (test3_DW.Integrator_PrevResetState_bf != 0)) {
    test3_DW.Integrator_DSTATE_im = test3_U.CellVoltages[91];
    if (test3_DW.Integrator_DSTATE_im >= 6.0F) {
      test3_DW.Integrator_DSTATE_im = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_im <= 0.0F) {
      test3_DW.Integrator_DSTATE_im = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_im >= 6.0F) {
    test3_DW.Integrator_DSTATE_im = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_im <= 0.0F) {
    test3_DW.Integrator_DSTATE_im = 0.0F;
  }

  /* RelationalOperator: '<S656>/Compare' incorporates:
   *  Constant: '<S653>/Time constant'
   *  Constant: '<S656>/Constant'
   *  Sum: '<S653>/Sum1'
   */
  rtb_Compare_is = ((real32_T)(0.031830988618379068 - test3_B.Probe_m5[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S658>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_kv != 0U) {
    test3_DW.Integrator_DSTATE_hp = test3_U.CellVoltages[92];
    if (test3_DW.Integrator_DSTATE_hp >= 6.0F) {
      test3_DW.Integrator_DSTATE_hp = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_hp <= 0.0F) {
      test3_DW.Integrator_DSTATE_hp = 0.0F;
    }
  }

  if (rtb_Compare_is || (test3_DW.Integrator_PrevResetState_fam != 0)) {
    test3_DW.Integrator_DSTATE_hp = test3_U.CellVoltages[92];
    if (test3_DW.Integrator_DSTATE_hp >= 6.0F) {
      test3_DW.Integrator_DSTATE_hp = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_hp <= 0.0F) {
      test3_DW.Integrator_DSTATE_hp = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_hp >= 6.0F) {
    test3_DW.Integrator_DSTATE_hp = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_hp <= 0.0F) {
    test3_DW.Integrator_DSTATE_hp = 0.0F;
  }

  /* RelationalOperator: '<S662>/Compare' incorporates:
   *  Constant: '<S659>/Time constant'
   *  Constant: '<S662>/Constant'
   *  Sum: '<S659>/Sum1'
   */
  rtb_Compare_ee = ((real32_T)(0.031830988618379068 - test3_B.Probe_da[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S664>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_h20 != 0U) {
    test3_DW.Integrator_DSTATE_aq = test3_U.CellVoltages[93];
    if (test3_DW.Integrator_DSTATE_aq >= 6.0F) {
      test3_DW.Integrator_DSTATE_aq = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_aq <= 0.0F) {
      test3_DW.Integrator_DSTATE_aq = 0.0F;
    }
  }

  if (rtb_Compare_ee || (test3_DW.Integrator_PrevResetState_g2 != 0)) {
    test3_DW.Integrator_DSTATE_aq = test3_U.CellVoltages[93];
    if (test3_DW.Integrator_DSTATE_aq >= 6.0F) {
      test3_DW.Integrator_DSTATE_aq = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_aq <= 0.0F) {
      test3_DW.Integrator_DSTATE_aq = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_aq >= 6.0F) {
    test3_DW.Integrator_DSTATE_aq = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_aq <= 0.0F) {
    test3_DW.Integrator_DSTATE_aq = 0.0F;
  }

  /* RelationalOperator: '<S668>/Compare' incorporates:
   *  Constant: '<S665>/Time constant'
   *  Constant: '<S668>/Constant'
   *  Sum: '<S665>/Sum1'
   */
  rtb_Compare_mpz = ((real32_T)(0.031830988618379068 - test3_B.Probe_he[0]) <=
                     0.0F);

  /* DiscreteIntegrator: '<S670>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_d04 != 0U) {
    test3_DW.Integrator_DSTATE_lx = test3_U.CellVoltages[94];
    if (test3_DW.Integrator_DSTATE_lx >= 6.0F) {
      test3_DW.Integrator_DSTATE_lx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_lx <= 0.0F) {
      test3_DW.Integrator_DSTATE_lx = 0.0F;
    }
  }

  if (rtb_Compare_mpz || (test3_DW.Integrator_PrevResetState_ou != 0)) {
    test3_DW.Integrator_DSTATE_lx = test3_U.CellVoltages[94];
    if (test3_DW.Integrator_DSTATE_lx >= 6.0F) {
      test3_DW.Integrator_DSTATE_lx = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_lx <= 0.0F) {
      test3_DW.Integrator_DSTATE_lx = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_lx >= 6.0F) {
    test3_DW.Integrator_DSTATE_lx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_lx <= 0.0F) {
    test3_DW.Integrator_DSTATE_lx = 0.0F;
  }

  /* RelationalOperator: '<S674>/Compare' incorporates:
   *  Constant: '<S671>/Time constant'
   *  Constant: '<S674>/Constant'
   *  Sum: '<S671>/Sum1'
   */
  rtb_Compare_ne = ((real32_T)(0.031830988618379068 - test3_B.Probe_ak[0]) <=
                    0.0F);

  /* DiscreteIntegrator: '<S676>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   */
  if (test3_DW.Integrator_IC_LOADING_jn != 0U) {
    test3_DW.Integrator_DSTATE_l5 = test3_U.CellVoltages[95];
    if (test3_DW.Integrator_DSTATE_l5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_l5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_l5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_l5 = 0.0F;
    }
  }

  if (rtb_Compare_ne || (test3_DW.Integrator_PrevResetState_k5 != 0)) {
    test3_DW.Integrator_DSTATE_l5 = test3_U.CellVoltages[95];
    if (test3_DW.Integrator_DSTATE_l5 >= 6.0F) {
      test3_DW.Integrator_DSTATE_l5 = 6.0F;
    } else if (test3_DW.Integrator_DSTATE_l5 <= 0.0F) {
      test3_DW.Integrator_DSTATE_l5 = 0.0F;
    }
  }

  if (test3_DW.Integrator_DSTATE_l5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_l5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_l5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_l5 = 0.0F;
  }

  /* MinMax: '<Root>/Min' incorporates:
   *  DiscreteIntegrator: '<S106>/Integrator'
   *  DiscreteIntegrator: '<S112>/Integrator'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  DiscreteIntegrator: '<S124>/Integrator'
   *  DiscreteIntegrator: '<S130>/Integrator'
   *  DiscreteIntegrator: '<S136>/Integrator'
   *  DiscreteIntegrator: '<S142>/Integrator'
   *  DiscreteIntegrator: '<S148>/Integrator'
   *  DiscreteIntegrator: '<S154>/Integrator'
   *  DiscreteIntegrator: '<S160>/Integrator'
   *  DiscreteIntegrator: '<S166>/Integrator'
   *  DiscreteIntegrator: '<S172>/Integrator'
   *  DiscreteIntegrator: '<S178>/Integrator'
   *  DiscreteIntegrator: '<S184>/Integrator'
   *  DiscreteIntegrator: '<S190>/Integrator'
   *  DiscreteIntegrator: '<S196>/Integrator'
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  DiscreteIntegrator: '<S208>/Integrator'
   *  DiscreteIntegrator: '<S214>/Integrator'
   *  DiscreteIntegrator: '<S220>/Integrator'
   *  DiscreteIntegrator: '<S226>/Integrator'
   *  DiscreteIntegrator: '<S232>/Integrator'
   *  DiscreteIntegrator: '<S238>/Integrator'
   *  DiscreteIntegrator: '<S244>/Integrator'
   *  DiscreteIntegrator: '<S250>/Integrator'
   *  DiscreteIntegrator: '<S256>/Integrator'
   *  DiscreteIntegrator: '<S262>/Integrator'
   *  DiscreteIntegrator: '<S268>/Integrator'
   *  DiscreteIntegrator: '<S274>/Integrator'
   *  DiscreteIntegrator: '<S280>/Integrator'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  DiscreteIntegrator: '<S292>/Integrator'
   *  DiscreteIntegrator: '<S298>/Integrator'
   *  DiscreteIntegrator: '<S304>/Integrator'
   *  DiscreteIntegrator: '<S310>/Integrator'
   *  DiscreteIntegrator: '<S316>/Integrator'
   *  DiscreteIntegrator: '<S322>/Integrator'
   *  DiscreteIntegrator: '<S328>/Integrator'
   *  DiscreteIntegrator: '<S334>/Integrator'
   *  DiscreteIntegrator: '<S340>/Integrator'
   *  DiscreteIntegrator: '<S346>/Integrator'
   *  DiscreteIntegrator: '<S352>/Integrator'
   *  DiscreteIntegrator: '<S358>/Integrator'
   *  DiscreteIntegrator: '<S364>/Integrator'
   *  DiscreteIntegrator: '<S370>/Integrator'
   *  DiscreteIntegrator: '<S376>/Integrator'
   *  DiscreteIntegrator: '<S382>/Integrator'
   *  DiscreteIntegrator: '<S388>/Integrator'
   *  DiscreteIntegrator: '<S394>/Integrator'
   *  DiscreteIntegrator: '<S400>/Integrator'
   *  DiscreteIntegrator: '<S406>/Integrator'
   *  DiscreteIntegrator: '<S412>/Integrator'
   *  DiscreteIntegrator: '<S418>/Integrator'
   *  DiscreteIntegrator: '<S424>/Integrator'
   *  DiscreteIntegrator: '<S430>/Integrator'
   *  DiscreteIntegrator: '<S436>/Integrator'
   *  DiscreteIntegrator: '<S442>/Integrator'
   *  DiscreteIntegrator: '<S448>/Integrator'
   *  DiscreteIntegrator: '<S454>/Integrator'
   *  DiscreteIntegrator: '<S460>/Integrator'
   *  DiscreteIntegrator: '<S466>/Integrator'
   *  DiscreteIntegrator: '<S472>/Integrator'
   *  DiscreteIntegrator: '<S478>/Integrator'
   *  DiscreteIntegrator: '<S484>/Integrator'
   *  DiscreteIntegrator: '<S490>/Integrator'
   *  DiscreteIntegrator: '<S496>/Integrator'
   *  DiscreteIntegrator: '<S502>/Integrator'
   *  DiscreteIntegrator: '<S508>/Integrator'
   *  DiscreteIntegrator: '<S514>/Integrator'
   *  DiscreteIntegrator: '<S520>/Integrator'
   *  DiscreteIntegrator: '<S526>/Integrator'
   *  DiscreteIntegrator: '<S532>/Integrator'
   *  DiscreteIntegrator: '<S538>/Integrator'
   *  DiscreteIntegrator: '<S544>/Integrator'
   *  DiscreteIntegrator: '<S550>/Integrator'
   *  DiscreteIntegrator: '<S556>/Integrator'
   *  DiscreteIntegrator: '<S562>/Integrator'
   *  DiscreteIntegrator: '<S568>/Integrator'
   *  DiscreteIntegrator: '<S574>/Integrator'
   *  DiscreteIntegrator: '<S580>/Integrator'
   *  DiscreteIntegrator: '<S586>/Integrator'
   *  DiscreteIntegrator: '<S592>/Integrator'
   *  DiscreteIntegrator: '<S598>/Integrator'
   *  DiscreteIntegrator: '<S604>/Integrator'
   *  DiscreteIntegrator: '<S610>/Integrator'
   *  DiscreteIntegrator: '<S616>/Integrator'
   *  DiscreteIntegrator: '<S622>/Integrator'
   *  DiscreteIntegrator: '<S628>/Integrator'
   *  DiscreteIntegrator: '<S634>/Integrator'
   *  DiscreteIntegrator: '<S640>/Integrator'
   *  DiscreteIntegrator: '<S646>/Integrator'
   *  DiscreteIntegrator: '<S652>/Integrator'
   *  DiscreteIntegrator: '<S658>/Integrator'
   *  DiscreteIntegrator: '<S664>/Integrator'
   *  DiscreteIntegrator: '<S670>/Integrator'
   *  DiscreteIntegrator: '<S676>/Integrator'
   *  MinMax: '<Root>/Max'
   *  Sum: '<Root>/Sum'
   */
  test3_B.TmpSignalConversionAtSFunctionI[0] = test3_DW.Integrator_DSTATE;
  test3_B.TmpSignalConversionAtSFunctionI[1] = test3_DW.Integrator_DSTATE_a;
  test3_B.TmpSignalConversionAtSFunctionI[2] = test3_DW.Integrator_DSTATE_n;
  test3_B.TmpSignalConversionAtSFunctionI[3] = test3_DW.Integrator_DSTATE_b;
  test3_B.TmpSignalConversionAtSFunctionI[4] = test3_DW.Integrator_DSTATE_g;
  test3_B.TmpSignalConversionAtSFunctionI[5] = test3_DW.Integrator_DSTATE_i;
  test3_B.TmpSignalConversionAtSFunctionI[6] = test3_DW.Integrator_DSTATE_e;
  test3_B.TmpSignalConversionAtSFunctionI[7] = test3_DW.Integrator_DSTATE_id;
  test3_B.TmpSignalConversionAtSFunctionI[8] = test3_DW.Integrator_DSTATE_is;
  test3_B.TmpSignalConversionAtSFunctionI[9] = test3_DW.Integrator_DSTATE_j;
  test3_B.TmpSignalConversionAtSFunctionI[10] = test3_DW.Integrator_DSTATE_j1;
  test3_B.TmpSignalConversionAtSFunctionI[11] = test3_DW.Integrator_DSTATE_jr;
  test3_B.TmpSignalConversionAtSFunctionI[12] = test3_DW.Integrator_DSTATE_p;
  test3_B.TmpSignalConversionAtSFunctionI[13] = test3_DW.Integrator_DSTATE_o;
  test3_B.TmpSignalConversionAtSFunctionI[14] = test3_DW.Integrator_DSTATE_f;
  test3_B.TmpSignalConversionAtSFunctionI[15] = test3_DW.Integrator_DSTATE_fo;
  test3_B.TmpSignalConversionAtSFunctionI[16] = test3_DW.Integrator_DSTATE_i1;
  test3_B.TmpSignalConversionAtSFunctionI[17] = test3_DW.Integrator_DSTATE_fj;
  test3_B.TmpSignalConversionAtSFunctionI[18] = test3_DW.Integrator_DSTATE_d;
  test3_B.TmpSignalConversionAtSFunctionI[19] = test3_DW.Integrator_DSTATE_g5;
  test3_B.TmpSignalConversionAtSFunctionI[20] = test3_DW.Integrator_DSTATE_pf;
  test3_B.TmpSignalConversionAtSFunctionI[21] = test3_DW.Integrator_DSTATE_c;
  test3_B.TmpSignalConversionAtSFunctionI[22] = test3_DW.Integrator_DSTATE_m;
  test3_B.TmpSignalConversionAtSFunctionI[23] = test3_DW.Integrator_DSTATE_j2;
  test3_B.TmpSignalConversionAtSFunctionI[24] = test3_DW.Integrator_DSTATE_iz;
  test3_B.TmpSignalConversionAtSFunctionI[25] = test3_DW.Integrator_DSTATE_bh;
  test3_B.TmpSignalConversionAtSFunctionI[26] = test3_DW.Integrator_DSTATE_ji;
  test3_B.TmpSignalConversionAtSFunctionI[27] = test3_DW.Integrator_DSTATE_od;
  test3_B.TmpSignalConversionAtSFunctionI[28] = test3_DW.Integrator_DSTATE_oy;
  test3_B.TmpSignalConversionAtSFunctionI[29] = test3_DW.Integrator_DSTATE_nc;
  test3_B.TmpSignalConversionAtSFunctionI[30] = test3_DW.Integrator_DSTATE_c2;
  test3_B.TmpSignalConversionAtSFunctionI[31] = test3_DW.Integrator_DSTATE_pa;
  test3_B.TmpSignalConversionAtSFunctionI[32] = test3_DW.Integrator_DSTATE_ez;
  test3_B.TmpSignalConversionAtSFunctionI[33] = test3_DW.Integrator_DSTATE_bp;
  test3_B.TmpSignalConversionAtSFunctionI[34] = test3_DW.Integrator_DSTATE_h;
  test3_B.TmpSignalConversionAtSFunctionI[35] = test3_DW.Integrator_DSTATE_i4;
  test3_B.TmpSignalConversionAtSFunctionI[36] = test3_DW.Integrator_DSTATE_fp;
  test3_B.TmpSignalConversionAtSFunctionI[37] = test3_DW.Integrator_DSTATE_hx;
  test3_B.TmpSignalConversionAtSFunctionI[38] = test3_DW.Integrator_DSTATE_k;
  test3_B.TmpSignalConversionAtSFunctionI[39] = test3_DW.Integrator_DSTATE_g3;
  test3_B.TmpSignalConversionAtSFunctionI[40] = test3_DW.Integrator_DSTATE_h4;
  test3_B.TmpSignalConversionAtSFunctionI[41] = test3_DW.Integrator_DSTATE_e5;
  test3_B.TmpSignalConversionAtSFunctionI[42] = test3_DW.Integrator_DSTATE_oc;
  test3_B.TmpSignalConversionAtSFunctionI[43] = test3_DW.Integrator_DSTATE_n5;
  test3_B.TmpSignalConversionAtSFunctionI[44] = test3_DW.Integrator_DSTATE_do;
  test3_B.TmpSignalConversionAtSFunctionI[45] = test3_DW.Integrator_DSTATE_ds;
  test3_B.TmpSignalConversionAtSFunctionI[46] = test3_DW.Integrator_DSTATE_bv;
  test3_B.TmpSignalConversionAtSFunctionI[47] = test3_DW.Integrator_DSTATE_o3;
  test3_B.TmpSignalConversionAtSFunctionI[48] = test3_DW.Integrator_DSTATE_fg;
  test3_B.TmpSignalConversionAtSFunctionI[49] = test3_DW.Integrator_DSTATE_a4;
  test3_B.TmpSignalConversionAtSFunctionI[50] = test3_DW.Integrator_DSTATE_l;
  test3_B.TmpSignalConversionAtSFunctionI[51] = test3_DW.Integrator_DSTATE_eo;
  test3_B.TmpSignalConversionAtSFunctionI[52] = test3_DW.Integrator_DSTATE_cl;
  test3_B.TmpSignalConversionAtSFunctionI[53] = test3_DW.Integrator_DSTATE_bs;
  test3_B.TmpSignalConversionAtSFunctionI[54] = test3_DW.Integrator_DSTATE_e2;
  test3_B.TmpSignalConversionAtSFunctionI[55] = test3_DW.Integrator_DSTATE_lr;
  test3_B.TmpSignalConversionAtSFunctionI[56] = test3_DW.Integrator_DSTATE_gx;
  test3_B.TmpSignalConversionAtSFunctionI[57] = test3_DW.Integrator_DSTATE_nu;
  test3_B.TmpSignalConversionAtSFunctionI[58] = test3_DW.Integrator_DSTATE_az;
  test3_B.TmpSignalConversionAtSFunctionI[59] = test3_DW.Integrator_DSTATE_kc;
  test3_B.TmpSignalConversionAtSFunctionI[60] = test3_DW.Integrator_DSTATE_mc;
  test3_B.TmpSignalConversionAtSFunctionI[61] = test3_DW.Integrator_DSTATE_nm;
  test3_B.TmpSignalConversionAtSFunctionI[62] = test3_DW.Integrator_DSTATE_po;
  test3_B.TmpSignalConversionAtSFunctionI[63] = test3_DW.Integrator_DSTATE_bt;
  test3_B.TmpSignalConversionAtSFunctionI[64] = test3_DW.Integrator_DSTATE_jt;
  test3_B.TmpSignalConversionAtSFunctionI[65] = test3_DW.Integrator_DSTATE_dc;
  test3_B.TmpSignalConversionAtSFunctionI[66] = test3_DW.Integrator_DSTATE_pb;
  test3_B.TmpSignalConversionAtSFunctionI[67] = test3_DW.Integrator_DSTATE_oe;
  test3_B.TmpSignalConversionAtSFunctionI[68] = test3_DW.Integrator_DSTATE_al;
  test3_B.TmpSignalConversionAtSFunctionI[69] = test3_DW.Integrator_DSTATE_cx;
  test3_B.TmpSignalConversionAtSFunctionI[70] = test3_DW.Integrator_DSTATE_cr;
  test3_B.TmpSignalConversionAtSFunctionI[71] = test3_DW.Integrator_DSTATE_p3;
  test3_B.TmpSignalConversionAtSFunctionI[72] = test3_DW.Integrator_DSTATE_kv;
  test3_B.TmpSignalConversionAtSFunctionI[73] = test3_DW.Integrator_DSTATE_ed;
  test3_B.TmpSignalConversionAtSFunctionI[74] = test3_DW.Integrator_DSTATE_fu;
  test3_B.TmpSignalConversionAtSFunctionI[75] = test3_DW.Integrator_DSTATE_he;
  test3_B.TmpSignalConversionAtSFunctionI[76] = test3_DW.Integrator_DSTATE_ot;
  test3_B.TmpSignalConversionAtSFunctionI[77] = test3_DW.Integrator_DSTATE_my;
  test3_B.TmpSignalConversionAtSFunctionI[78] = test3_DW.Integrator_DSTATE_lt;
  test3_B.TmpSignalConversionAtSFunctionI[79] = test3_DW.Integrator_DSTATE_pd;
  test3_B.TmpSignalConversionAtSFunctionI[80] = test3_DW.Integrator_DSTATE_en;
  test3_B.TmpSignalConversionAtSFunctionI[81] = test3_DW.Integrator_DSTATE_ix;
  test3_B.TmpSignalConversionAtSFunctionI[82] = test3_DW.Integrator_DSTATE_hg;
  test3_B.TmpSignalConversionAtSFunctionI[83] = test3_DW.Integrator_DSTATE_fm;
  test3_B.TmpSignalConversionAtSFunctionI[84] = test3_DW.Integrator_DSTATE_ok;
  test3_B.TmpSignalConversionAtSFunctionI[85] = test3_DW.Integrator_DSTATE_ns;
  test3_B.TmpSignalConversionAtSFunctionI[86] = test3_DW.Integrator_DSTATE_ga;
  test3_B.TmpSignalConversionAtSFunctionI[87] = test3_DW.Integrator_DSTATE_dsn;
  test3_B.TmpSignalConversionAtSFunctionI[88] = test3_DW.Integrator_DSTATE_pc;
  test3_B.TmpSignalConversionAtSFunctionI[89] = test3_DW.Integrator_DSTATE_eg;
  test3_B.TmpSignalConversionAtSFunctionI[90] = test3_DW.Integrator_DSTATE_jx;
  test3_B.TmpSignalConversionAtSFunctionI[91] = test3_DW.Integrator_DSTATE_im;
  test3_B.TmpSignalConversionAtSFunctionI[92] = test3_DW.Integrator_DSTATE_hp;
  test3_B.TmpSignalConversionAtSFunctionI[93] = test3_DW.Integrator_DSTATE_aq;
  test3_B.TmpSignalConversionAtSFunctionI[94] = test3_DW.Integrator_DSTATE_lx;
  test3_B.TmpSignalConversionAtSFunctionI[95] = test3_DW.Integrator_DSTATE_l5;
  test3_Y.MinCellVolt = test3_DW.Integrator_DSTATE;

  /* MinMax: '<Root>/Max' incorporates:
   *  DiscreteIntegrator: '<S106>/Integrator'
   */
  test3_Y.MaxCellVolt = test3_DW.Integrator_DSTATE;
  for (test3_B.i = 0; test3_B.i < 95; test3_B.i++) {
    /* MinMax: '<Root>/Min' incorporates:
     *  MinMax: '<Root>/Max'
     */
    test3_B.Max = test3_B.TmpSignalConversionAtSFunctionI[(int32_T)(test3_B.i +
      1)];
    if ((!(test3_Y.MinCellVolt <= test3_B.Max)) && (!rtIsNaNF(test3_B.Max))) {
      test3_Y.MinCellVolt = test3_B.Max;
    }

    /* MinMax: '<Root>/Max' */
    if ((!(test3_Y.MaxCellVolt >= test3_B.Max)) && (!rtIsNaNF(test3_B.Max))) {
      test3_Y.MaxCellVolt = test3_B.Max;
    }
  }

  /* Sum: '<Root>/Sum' */
  test3_Y.SumOfVoltages = -0.0F;
  for (test3_B.i = 0; test3_B.i < 96; test3_B.i++) {
    test3_Y.SumOfVoltages += test3_B.TmpSignalConversionAtSFunctionI[test3_B.i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Current_Limit' */
  /* Lookup_n-D: '<S99>/Rdc' incorporates:
   *  Inport: '<Root>/SOC'
   *  MinMax: '<Root>/Min1'
   *  Outport: '<Root>/MinCellTemp'
   */
  test3_B.Max = look2_iflf_pbinlcpw(test3_U.SOC, test3_Y.MinCellTemp,
    test3_ConstP.Rdc_bp01Data, test3_ConstP.Rdc_bp02Data,
    test3_ConstP.Rdc_tableData, test3_DW.m_bpIndex, test3_ConstP.Rdc_maxIndex,
    11UL);

  /* Product: '<S682>/Divide1' incorporates:
   *  Constant: '<S682>/OverVoltageLimit'
   *  Outport: '<Root>/MaxCellVolt'
   *  Sum: '<S682>/Subtract1'
   */
  test3_B.cumRevIndex = (4.37F - test3_Y.MaxCellVolt) / test3_B.Max;

  /* Lookup_n-D: '<S682>/LowTempDchrgCurrentLim' incorporates:
   *  MinMax: '<Root>/Min1'
   *  Outport: '<Root>/MinCellTemp'
   */
  test3_B.Saturation1 = look1_iflf_binlxpw(test3_Y.MinCellTemp,
    test3_ConstP.pooled12, test3_ConstP.LowTempDchrgCurrentLim_tableDat, 90UL);

  /* MinMax: '<S682>/MinMax2' */
  if ((test3_B.cumRevIndex <= test3_B.Saturation1) || rtIsNaNF
      (test3_B.Saturation1)) {
    test3_B.Saturation1 = test3_B.cumRevIndex;
  }

  /* Lookup_n-D: '<S682>/HighTempChrgCurrentLim' incorporates:
   *  MinMax: '<Root>/Max1'
   *  Outport: '<Root>/MaxCellTemp'
   */
  test3_B.cumRevIndex = look1_iflf_binlxpw(test3_Y.MaxCellTemp,
    test3_ConstP.pooled12, test3_ConstP.HighTempChrgCurrentLim_tableDat, 90UL);

  /* MinMax: '<S682>/MinMax2' */
  if ((test3_B.Saturation1 <= test3_B.cumRevIndex) || rtIsNaNF
      (test3_B.cumRevIndex)) {
    test3_B.cumRevIndex = test3_B.Saturation1;
  }

  /* Product: '<S682>/Divide' incorporates:
   *  Inport: '<Root>/Req_Power'
   *  Outport: '<Root>/SumOfVoltages'
   */
  test3_B.Saturation1 = test3_U.Req_Power / test3_Y.SumOfVoltages;

  /* MinMax: '<S682>/MinMax2' incorporates:
   *  Inport: '<Root>/Req_Current'
   */
  if ((test3_B.cumRevIndex <= test3_B.Saturation1) || rtIsNaNF
      (test3_B.Saturation1)) {
    test3_B.Saturation1 = test3_B.cumRevIndex;
  }

  if ((!(test3_B.Saturation1 <= test3_U.Req_Current)) && (!rtIsNaNF
       (test3_U.Req_Current))) {
    test3_B.Saturation1 = test3_U.Req_Current;
  }

  /* Saturate: '<S99>/Saturation1' */
  if (test3_B.Saturation1 > 180.0F) {
    test3_B.Saturation1 = 180.0F;
  } else if (test3_B.Saturation1 < 0.0F) {
    test3_B.Saturation1 = 0.0F;
  }

  /* End of Saturate: '<S99>/Saturation1' */

  /* MATLABSystem: '<S99>/Moving Average' */
  if (test3_DW.obj.TunablePropsChanged) {
    test3_DW.obj.TunablePropsChanged = false;
  }

  obj = test3_DW.obj.pStatistic;
  if (obj->isInitialized != 1L) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1L;
    obj->pCumSum = 0.0F;
    for (test3_B.i = 0; test3_B.i < 11; test3_B.i++) {
      obj->pCumSumRev[test3_B.i] = 0.0F;
    }

    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0F;
    for (test3_B.i = 0; test3_B.i < 11; test3_B.i++) {
      obj->pCumSumRev[test3_B.i] = 0.0F;
    }

    obj->pCumRevIndex = 1.0F;
    obj->pModValueRev = 0.0F;
  }

  test3_B.cumRevIndex = obj->pCumRevIndex;
  test3_B.csum = obj->pCumSum;
  for (test3_B.i = 0; test3_B.i < 11; test3_B.i++) {
    test3_B.csumrev[test3_B.i] = obj->pCumSumRev[test3_B.i];
  }

  test3_B.modValueRev = obj->pModValueRev;
  test3_B.z = 0.0F;

  /* Outport: '<Root>/ChargeCurrentLimit' incorporates:
   *  MATLABSystem: '<S99>/Moving Average'
   */
  test3_Y.ChargeCurrentLimit = 0.0F;

  /* MATLABSystem: '<S99>/Moving Average' */
  test3_B.csum += test3_B.Saturation1;
  if (test3_B.modValueRev == 0.0F) {
    test3_B.z = test3_B.csumrev[(int16_T)test3_B.cumRevIndex - 1] + test3_B.csum;
  }

  test3_B.csumrev[(int16_T)test3_B.cumRevIndex - 1] = test3_B.Saturation1;
  if (test3_B.cumRevIndex != 11.0F) {
    test3_B.cumRevIndex++;
  } else {
    test3_B.cumRevIndex = 1.0F;
    test3_B.csum = 0.0F;
    for (test3_B.i = 9; test3_B.i >= 0; test3_B.i--) {
      test3_B.csumrev[test3_B.i] += test3_B.csumrev[test3_B.i + 1];
    }
  }

  if (test3_B.modValueRev == 0.0F) {
    /* Outport: '<Root>/ChargeCurrentLimit' */
    test3_Y.ChargeCurrentLimit = test3_B.z / 12.0F;
  }

  obj->pCumSum = test3_B.csum;
  for (test3_B.i = 0; test3_B.i < 11; test3_B.i++) {
    obj->pCumSumRev[test3_B.i] = test3_B.csumrev[test3_B.i];
  }

  obj->pCumRevIndex = test3_B.cumRevIndex;
  if (test3_B.modValueRev > 0.0F) {
    obj->pModValueRev = test3_B.modValueRev - 1.0F;
  } else {
    obj->pModValueRev = 0.0F;
  }

  /* Saturate: '<S99>/Saturation' incorporates:
   *  Inport: '<Root>/SOC'
   *  Lookup_n-D: '<S683>/Rdc1'
   */
  test3_Y.DischargeCurrentLimit = look1_iflf_pbinlcpw(test3_U.SOC,
    test3_ConstP.Rdc1_bp01Data, test3_ConstP.Rdc1_tableData,
    &test3_DW.m_bpIndex_g, 6UL);

  /* Product: '<S683>/Divide' incorporates:
   *  Constant: '<S683>/Constant1'
   *  Outport: '<Root>/MinCellVolt'
   *  Product: '<S683>/Divide1'
   *  Sum: '<S683>/Subtract'
   */
  test3_B.cumRevIndex = (test3_Y.MinCellVolt - 2.5F) /
    (test3_Y.DischargeCurrentLimit * test3_B.Max);

  /* Lookup_n-D: '<S683>/LowTempDchrgCurrentLim' incorporates:
   *  MinMax: '<Root>/Min1'
   *  Outport: '<Root>/MinCellTemp'
   */
  test3_B.Saturation1 = look1_iflf_binlxpw(test3_Y.MinCellTemp,
    test3_ConstP.pooled13, test3_ConstP.LowTempDchrgCurrentLim_tableD_j, 100UL);

  /* MinMax: '<S683>/MinMax2' */
  if ((test3_B.cumRevIndex <= test3_B.Saturation1) || rtIsNaNF
      (test3_B.Saturation1)) {
    test3_B.Saturation1 = test3_B.cumRevIndex;
  }

  /* Saturate: '<S99>/Saturation' incorporates:
   *  Lookup_n-D: '<S683>/HighTempDchrgCurrentLim'
   *  MinMax: '<Root>/Max1'
   *  Outport: '<Root>/MaxCellTemp'
   */
  test3_Y.DischargeCurrentLimit = look1_iflf_binlxpw(test3_Y.MaxCellTemp,
    test3_ConstP.pooled13, test3_ConstP.HighTempDchrgCurrentLim_tableDa, 100UL);

  /* MinMax: '<S683>/MinMax2' */
  if ((test3_B.Saturation1 <= test3_Y.DischargeCurrentLimit) || rtIsNaNF
      (test3_Y.DischargeCurrentLimit)) {
    /* Saturate: '<S99>/Saturation' */
    test3_Y.DischargeCurrentLimit = test3_B.Saturation1;
  }

  /* Saturate: '<S99>/Saturation' */
  if (test3_Y.DischargeCurrentLimit > 420.0F) {
    /* Saturate: '<S99>/Saturation' */
    test3_Y.DischargeCurrentLimit = 420.0F;
  } else if (test3_Y.DischargeCurrentLimit < 0.0F) {
    /* Saturate: '<S99>/Saturation' */
    test3_Y.DischargeCurrentLimit = 0.0F;
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* RateLimiter: '<S99>/Rate Limiter1' incorporates:
   *  Outport: '<Root>/DischargeCurrentLimit'
   */
  test3_B.Max = test3_Y.DischargeCurrentLimit - test3_DW.PrevY;
  if (test3_B.Max > 0.7F) {
    /* Saturate: '<S99>/Saturation' */
    test3_Y.DischargeCurrentLimit = test3_DW.PrevY + 0.7F;
  } else if (test3_B.Max < -3.0F) {
    /* Saturate: '<S99>/Saturation' */
    test3_Y.DischargeCurrentLimit = test3_DW.PrevY + -3.0F;
  }

  test3_DW.PrevY = test3_Y.DischargeCurrentLimit;

  /* End of RateLimiter: '<S99>/Rate Limiter1' */
  /* End of Outputs for SubSystem: '<Root>/Current_Limit' */

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Inport: '<Root>/SOC'
   */
  if (test3_U.SOC > 100.0F) {
    /* Outport: '<Root>/Fake_SOC' */
    test3_Y.Fake_SOC = 100.0F;
  } else if (test3_U.SOC < 0.0F) {
    /* Outport: '<Root>/Fake_SOC' */
    test3_Y.Fake_SOC = 0.0F;
  } else {
    /* Outport: '<Root>/Fake_SOC' */
    test3_Y.Fake_SOC = test3_U.SOC;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/BMS_Function' */
  /* SignalConversion generated from: '<S677>/ SFunction ' incorporates:
   *  Chart: '<S97>/Chart'
   *  DiscreteIntegrator: '<S106>/Integrator'
   *  DiscreteIntegrator: '<S112>/Integrator'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  DiscreteIntegrator: '<S124>/Integrator'
   *  DiscreteIntegrator: '<S130>/Integrator'
   *  DiscreteIntegrator: '<S136>/Integrator'
   *  DiscreteIntegrator: '<S142>/Integrator'
   *  DiscreteIntegrator: '<S148>/Integrator'
   *  DiscreteIntegrator: '<S154>/Integrator'
   *  DiscreteIntegrator: '<S160>/Integrator'
   *  DiscreteIntegrator: '<S166>/Integrator'
   *  DiscreteIntegrator: '<S172>/Integrator'
   *  DiscreteIntegrator: '<S178>/Integrator'
   *  DiscreteIntegrator: '<S184>/Integrator'
   *  DiscreteIntegrator: '<S190>/Integrator'
   *  DiscreteIntegrator: '<S196>/Integrator'
   *  DiscreteIntegrator: '<S202>/Integrator'
   *  DiscreteIntegrator: '<S208>/Integrator'
   *  DiscreteIntegrator: '<S214>/Integrator'
   *  DiscreteIntegrator: '<S220>/Integrator'
   *  DiscreteIntegrator: '<S226>/Integrator'
   *  DiscreteIntegrator: '<S232>/Integrator'
   *  DiscreteIntegrator: '<S238>/Integrator'
   *  DiscreteIntegrator: '<S244>/Integrator'
   *  DiscreteIntegrator: '<S250>/Integrator'
   *  DiscreteIntegrator: '<S256>/Integrator'
   *  DiscreteIntegrator: '<S262>/Integrator'
   *  DiscreteIntegrator: '<S268>/Integrator'
   *  DiscreteIntegrator: '<S274>/Integrator'
   *  DiscreteIntegrator: '<S280>/Integrator'
   *  DiscreteIntegrator: '<S286>/Integrator'
   *  DiscreteIntegrator: '<S292>/Integrator'
   *  DiscreteIntegrator: '<S298>/Integrator'
   *  DiscreteIntegrator: '<S304>/Integrator'
   *  DiscreteIntegrator: '<S310>/Integrator'
   *  DiscreteIntegrator: '<S316>/Integrator'
   *  DiscreteIntegrator: '<S322>/Integrator'
   *  DiscreteIntegrator: '<S328>/Integrator'
   *  DiscreteIntegrator: '<S334>/Integrator'
   *  DiscreteIntegrator: '<S340>/Integrator'
   *  DiscreteIntegrator: '<S346>/Integrator'
   *  DiscreteIntegrator: '<S352>/Integrator'
   *  DiscreteIntegrator: '<S358>/Integrator'
   *  DiscreteIntegrator: '<S364>/Integrator'
   *  DiscreteIntegrator: '<S370>/Integrator'
   *  DiscreteIntegrator: '<S376>/Integrator'
   *  DiscreteIntegrator: '<S382>/Integrator'
   *  DiscreteIntegrator: '<S388>/Integrator'
   *  DiscreteIntegrator: '<S394>/Integrator'
   *  DiscreteIntegrator: '<S400>/Integrator'
   *  DiscreteIntegrator: '<S406>/Integrator'
   *  DiscreteIntegrator: '<S412>/Integrator'
   *  DiscreteIntegrator: '<S418>/Integrator'
   *  DiscreteIntegrator: '<S424>/Integrator'
   *  DiscreteIntegrator: '<S430>/Integrator'
   *  DiscreteIntegrator: '<S436>/Integrator'
   *  DiscreteIntegrator: '<S442>/Integrator'
   *  DiscreteIntegrator: '<S448>/Integrator'
   *  DiscreteIntegrator: '<S454>/Integrator'
   *  DiscreteIntegrator: '<S460>/Integrator'
   *  DiscreteIntegrator: '<S466>/Integrator'
   *  DiscreteIntegrator: '<S472>/Integrator'
   *  DiscreteIntegrator: '<S478>/Integrator'
   *  DiscreteIntegrator: '<S484>/Integrator'
   *  DiscreteIntegrator: '<S490>/Integrator'
   *  DiscreteIntegrator: '<S496>/Integrator'
   *  DiscreteIntegrator: '<S502>/Integrator'
   *  DiscreteIntegrator: '<S508>/Integrator'
   *  DiscreteIntegrator: '<S514>/Integrator'
   *  DiscreteIntegrator: '<S520>/Integrator'
   *  DiscreteIntegrator: '<S526>/Integrator'
   *  DiscreteIntegrator: '<S532>/Integrator'
   *  DiscreteIntegrator: '<S538>/Integrator'
   *  DiscreteIntegrator: '<S544>/Integrator'
   *  DiscreteIntegrator: '<S550>/Integrator'
   *  DiscreteIntegrator: '<S556>/Integrator'
   *  DiscreteIntegrator: '<S562>/Integrator'
   *  DiscreteIntegrator: '<S568>/Integrator'
   *  DiscreteIntegrator: '<S574>/Integrator'
   *  DiscreteIntegrator: '<S580>/Integrator'
   *  DiscreteIntegrator: '<S586>/Integrator'
   *  DiscreteIntegrator: '<S592>/Integrator'
   *  DiscreteIntegrator: '<S598>/Integrator'
   *  DiscreteIntegrator: '<S604>/Integrator'
   *  DiscreteIntegrator: '<S610>/Integrator'
   *  DiscreteIntegrator: '<S616>/Integrator'
   *  DiscreteIntegrator: '<S622>/Integrator'
   *  DiscreteIntegrator: '<S628>/Integrator'
   *  DiscreteIntegrator: '<S634>/Integrator'
   *  DiscreteIntegrator: '<S640>/Integrator'
   *  DiscreteIntegrator: '<S646>/Integrator'
   *  DiscreteIntegrator: '<S652>/Integrator'
   *  DiscreteIntegrator: '<S658>/Integrator'
   *  DiscreteIntegrator: '<S664>/Integrator'
   *  DiscreteIntegrator: '<S670>/Integrator'
   *  DiscreteIntegrator: '<S676>/Integrator'
   */
  test3_B.TmpSignalConversionAtSFunctionI[0] = test3_DW.Integrator_DSTATE;
  test3_B.TmpSignalConversionAtSFunctionI[1] = test3_DW.Integrator_DSTATE_a;
  test3_B.TmpSignalConversionAtSFunctionI[2] = test3_DW.Integrator_DSTATE_n;
  test3_B.TmpSignalConversionAtSFunctionI[3] = test3_DW.Integrator_DSTATE_b;
  test3_B.TmpSignalConversionAtSFunctionI[4] = test3_DW.Integrator_DSTATE_g;
  test3_B.TmpSignalConversionAtSFunctionI[5] = test3_DW.Integrator_DSTATE_i;
  test3_B.TmpSignalConversionAtSFunctionI[6] = test3_DW.Integrator_DSTATE_e;
  test3_B.TmpSignalConversionAtSFunctionI[7] = test3_DW.Integrator_DSTATE_id;
  test3_B.TmpSignalConversionAtSFunctionI[8] = test3_DW.Integrator_DSTATE_is;
  test3_B.TmpSignalConversionAtSFunctionI[9] = test3_DW.Integrator_DSTATE_j;
  test3_B.TmpSignalConversionAtSFunctionI[10] = test3_DW.Integrator_DSTATE_j1;
  test3_B.TmpSignalConversionAtSFunctionI[11] = test3_DW.Integrator_DSTATE_jr;
  test3_B.TmpSignalConversionAtSFunctionI[12] = test3_DW.Integrator_DSTATE_p;
  test3_B.TmpSignalConversionAtSFunctionI[13] = test3_DW.Integrator_DSTATE_o;
  test3_B.TmpSignalConversionAtSFunctionI[14] = test3_DW.Integrator_DSTATE_f;
  test3_B.TmpSignalConversionAtSFunctionI[15] = test3_DW.Integrator_DSTATE_fo;
  test3_B.TmpSignalConversionAtSFunctionI[16] = test3_DW.Integrator_DSTATE_i1;
  test3_B.TmpSignalConversionAtSFunctionI[17] = test3_DW.Integrator_DSTATE_fj;
  test3_B.TmpSignalConversionAtSFunctionI[18] = test3_DW.Integrator_DSTATE_d;
  test3_B.TmpSignalConversionAtSFunctionI[19] = test3_DW.Integrator_DSTATE_g5;
  test3_B.TmpSignalConversionAtSFunctionI[20] = test3_DW.Integrator_DSTATE_pf;
  test3_B.TmpSignalConversionAtSFunctionI[21] = test3_DW.Integrator_DSTATE_c;
  test3_B.TmpSignalConversionAtSFunctionI[22] = test3_DW.Integrator_DSTATE_m;
  test3_B.TmpSignalConversionAtSFunctionI[23] = test3_DW.Integrator_DSTATE_j2;
  test3_B.TmpSignalConversionAtSFunctionI[24] = test3_DW.Integrator_DSTATE_iz;
  test3_B.TmpSignalConversionAtSFunctionI[25] = test3_DW.Integrator_DSTATE_bh;
  test3_B.TmpSignalConversionAtSFunctionI[26] = test3_DW.Integrator_DSTATE_ji;
  test3_B.TmpSignalConversionAtSFunctionI[27] = test3_DW.Integrator_DSTATE_od;
  test3_B.TmpSignalConversionAtSFunctionI[28] = test3_DW.Integrator_DSTATE_oy;
  test3_B.TmpSignalConversionAtSFunctionI[29] = test3_DW.Integrator_DSTATE_nc;
  test3_B.TmpSignalConversionAtSFunctionI[30] = test3_DW.Integrator_DSTATE_c2;
  test3_B.TmpSignalConversionAtSFunctionI[31] = test3_DW.Integrator_DSTATE_pa;
  test3_B.TmpSignalConversionAtSFunctionI[32] = test3_DW.Integrator_DSTATE_ez;
  test3_B.TmpSignalConversionAtSFunctionI[33] = test3_DW.Integrator_DSTATE_bp;
  test3_B.TmpSignalConversionAtSFunctionI[34] = test3_DW.Integrator_DSTATE_h;
  test3_B.TmpSignalConversionAtSFunctionI[35] = test3_DW.Integrator_DSTATE_i4;
  test3_B.TmpSignalConversionAtSFunctionI[36] = test3_DW.Integrator_DSTATE_fp;
  test3_B.TmpSignalConversionAtSFunctionI[37] = test3_DW.Integrator_DSTATE_hx;
  test3_B.TmpSignalConversionAtSFunctionI[38] = test3_DW.Integrator_DSTATE_k;
  test3_B.TmpSignalConversionAtSFunctionI[39] = test3_DW.Integrator_DSTATE_g3;
  test3_B.TmpSignalConversionAtSFunctionI[40] = test3_DW.Integrator_DSTATE_h4;
  test3_B.TmpSignalConversionAtSFunctionI[41] = test3_DW.Integrator_DSTATE_e5;
  test3_B.TmpSignalConversionAtSFunctionI[42] = test3_DW.Integrator_DSTATE_oc;
  test3_B.TmpSignalConversionAtSFunctionI[43] = test3_DW.Integrator_DSTATE_n5;
  test3_B.TmpSignalConversionAtSFunctionI[44] = test3_DW.Integrator_DSTATE_do;
  test3_B.TmpSignalConversionAtSFunctionI[45] = test3_DW.Integrator_DSTATE_ds;
  test3_B.TmpSignalConversionAtSFunctionI[46] = test3_DW.Integrator_DSTATE_bv;
  test3_B.TmpSignalConversionAtSFunctionI[47] = test3_DW.Integrator_DSTATE_o3;
  test3_B.TmpSignalConversionAtSFunctionI[48] = test3_DW.Integrator_DSTATE_fg;
  test3_B.TmpSignalConversionAtSFunctionI[49] = test3_DW.Integrator_DSTATE_a4;
  test3_B.TmpSignalConversionAtSFunctionI[50] = test3_DW.Integrator_DSTATE_l;
  test3_B.TmpSignalConversionAtSFunctionI[51] = test3_DW.Integrator_DSTATE_eo;
  test3_B.TmpSignalConversionAtSFunctionI[52] = test3_DW.Integrator_DSTATE_cl;
  test3_B.TmpSignalConversionAtSFunctionI[53] = test3_DW.Integrator_DSTATE_bs;
  test3_B.TmpSignalConversionAtSFunctionI[54] = test3_DW.Integrator_DSTATE_e2;
  test3_B.TmpSignalConversionAtSFunctionI[55] = test3_DW.Integrator_DSTATE_lr;
  test3_B.TmpSignalConversionAtSFunctionI[56] = test3_DW.Integrator_DSTATE_gx;
  test3_B.TmpSignalConversionAtSFunctionI[57] = test3_DW.Integrator_DSTATE_nu;
  test3_B.TmpSignalConversionAtSFunctionI[58] = test3_DW.Integrator_DSTATE_az;
  test3_B.TmpSignalConversionAtSFunctionI[59] = test3_DW.Integrator_DSTATE_kc;
  test3_B.TmpSignalConversionAtSFunctionI[60] = test3_DW.Integrator_DSTATE_mc;
  test3_B.TmpSignalConversionAtSFunctionI[61] = test3_DW.Integrator_DSTATE_nm;
  test3_B.TmpSignalConversionAtSFunctionI[62] = test3_DW.Integrator_DSTATE_po;
  test3_B.TmpSignalConversionAtSFunctionI[63] = test3_DW.Integrator_DSTATE_bt;
  test3_B.TmpSignalConversionAtSFunctionI[64] = test3_DW.Integrator_DSTATE_jt;
  test3_B.TmpSignalConversionAtSFunctionI[65] = test3_DW.Integrator_DSTATE_dc;
  test3_B.TmpSignalConversionAtSFunctionI[66] = test3_DW.Integrator_DSTATE_pb;
  test3_B.TmpSignalConversionAtSFunctionI[67] = test3_DW.Integrator_DSTATE_oe;
  test3_B.TmpSignalConversionAtSFunctionI[68] = test3_DW.Integrator_DSTATE_al;
  test3_B.TmpSignalConversionAtSFunctionI[69] = test3_DW.Integrator_DSTATE_cx;
  test3_B.TmpSignalConversionAtSFunctionI[70] = test3_DW.Integrator_DSTATE_cr;
  test3_B.TmpSignalConversionAtSFunctionI[71] = test3_DW.Integrator_DSTATE_p3;
  test3_B.TmpSignalConversionAtSFunctionI[72] = test3_DW.Integrator_DSTATE_kv;
  test3_B.TmpSignalConversionAtSFunctionI[73] = test3_DW.Integrator_DSTATE_ed;
  test3_B.TmpSignalConversionAtSFunctionI[74] = test3_DW.Integrator_DSTATE_fu;
  test3_B.TmpSignalConversionAtSFunctionI[75] = test3_DW.Integrator_DSTATE_he;
  test3_B.TmpSignalConversionAtSFunctionI[76] = test3_DW.Integrator_DSTATE_ot;
  test3_B.TmpSignalConversionAtSFunctionI[77] = test3_DW.Integrator_DSTATE_my;
  test3_B.TmpSignalConversionAtSFunctionI[78] = test3_DW.Integrator_DSTATE_lt;
  test3_B.TmpSignalConversionAtSFunctionI[79] = test3_DW.Integrator_DSTATE_pd;
  test3_B.TmpSignalConversionAtSFunctionI[80] = test3_DW.Integrator_DSTATE_en;
  test3_B.TmpSignalConversionAtSFunctionI[81] = test3_DW.Integrator_DSTATE_ix;
  test3_B.TmpSignalConversionAtSFunctionI[82] = test3_DW.Integrator_DSTATE_hg;
  test3_B.TmpSignalConversionAtSFunctionI[83] = test3_DW.Integrator_DSTATE_fm;
  test3_B.TmpSignalConversionAtSFunctionI[84] = test3_DW.Integrator_DSTATE_ok;
  test3_B.TmpSignalConversionAtSFunctionI[85] = test3_DW.Integrator_DSTATE_ns;
  test3_B.TmpSignalConversionAtSFunctionI[86] = test3_DW.Integrator_DSTATE_ga;
  test3_B.TmpSignalConversionAtSFunctionI[87] = test3_DW.Integrator_DSTATE_dsn;
  test3_B.TmpSignalConversionAtSFunctionI[88] = test3_DW.Integrator_DSTATE_pc;
  test3_B.TmpSignalConversionAtSFunctionI[89] = test3_DW.Integrator_DSTATE_eg;
  test3_B.TmpSignalConversionAtSFunctionI[90] = test3_DW.Integrator_DSTATE_jx;
  test3_B.TmpSignalConversionAtSFunctionI[91] = test3_DW.Integrator_DSTATE_im;
  test3_B.TmpSignalConversionAtSFunctionI[92] = test3_DW.Integrator_DSTATE_hp;
  test3_B.TmpSignalConversionAtSFunctionI[93] = test3_DW.Integrator_DSTATE_aq;
  test3_B.TmpSignalConversionAtSFunctionI[94] = test3_DW.Integrator_DSTATE_lx;
  test3_B.TmpSignalConversionAtSFunctionI[95] = test3_DW.Integrator_DSTATE_l5;

  /* SignalConversion generated from: '<S677>/ SFunction ' incorporates:
   *  Chart: '<S97>/Chart'
   */
  test3_B.TmpSignalConversionAtSFunctio_g[0] =
    test3_B.MovingAverage.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[1] =
    test3_B.MovingAverage1.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[2] =
    test3_B.MovingAverage2.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[3] =
    test3_B.MovingAverage3.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[4] =
    test3_B.MovingAverage4.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[5] =
    test3_B.MovingAverage5.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[6] =
    test3_B.MovingAverage6.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[7] =
    test3_B.MovingAverage7.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[8] =
    test3_B.MovingAverage8.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[9] =
    test3_B.MovingAverage9.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[10] =
    test3_B.MovingAverage10.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[11] =
    test3_B.MovingAverage11.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[12] =
    test3_B.MovingAverage12.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[13] =
    test3_B.MovingAverage13.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[14] =
    test3_B.MovingAverage14.ChargeCurrentLimit;
  test3_B.TmpSignalConversionAtSFunctio_g[15] =
    test3_B.MovingAverage15.ChargeCurrentLimit;

  /* Chart: '<S97>/Chart' incorporates:
   *  Inport: '<Root>/BMBFault'
   *  Inport: '<Root>/Pack_Current'
   *  Inport: '<Root>/SOC'
   *  Outport: '<Root>/ChargeCurrentLimit'
   *  Outport: '<Root>/DischargeCurrentLimit'
   *  Outport: '<Root>/MaxCellTemp'
   *  Outport: '<Root>/MaxCellVolt'
   *  Outport: '<Root>/MinCellTemp'
   *  Outport: '<Root>/MinCellVolt'
   */
  if (test3_DW.temporalCounter_i1_h < 131071UL) {
    test3_DW.temporalCounter_i1_h++;
  }

  if (test3_DW.temporalCounter_i2 < MAX_uint32_T) {
    test3_DW.temporalCounter_i2++;
  }

  if (test3_DW.temporalCounter_i3 < MAX_uint32_T) {
    test3_DW.temporalCounter_i3++;
  }

  if (test3_DW.temporalCounter_i4 < 4194303UL) {
    test3_DW.temporalCounter_i4++;
  }

  if (test3_DW.temporalCounter_i5 < MAX_uint32_T) {
    test3_DW.temporalCounter_i5++;
  }

  if (test3_DW.is_active_c2_test3 == 0U) {
    test3_DW.is_active_c2_test3 = 1U;
    test3_enter_internal_Main();
  } else {
    test3_Main(test3_B.TmpSignalConversionAtSFunctio_g,
               test3_B.TmpSignalConversionAtSFunctionI);
  }

  if (test3_U.Pack_Current >= 2.0F) {
    test3_DW.durationCounter_1++;
  } else {
    test3_DW.durationCounter_1 = 0L;
  }

  if (test3_U.BMBFault == 1.0F) {
    test3_DW.durationCounter_1_p++;
  } else {
    test3_DW.durationCounter_1_p = 0L;
  }

  if (test3_U.SOC <= 0.0F) {
    test3_DW.durationCounter_2++;
  } else {
    test3_DW.durationCounter_2 = 0L;
  }

  test3_B.Max = test3_U.Pack_Current / test3_Y.DischargeCurrentLimit;
  if (test3_B.Max > 1.1) {
    test3_DW.durationCounter_1_k++;
  } else {
    test3_DW.durationCounter_1_k = 0L;
  }

  if (test3_B.Max > 1.5F) {
    test3_DW.durationCounter_2_a++;
  } else {
    test3_DW.durationCounter_2_a = 0L;
  }

  if (test3_B.Max > 2.0F) {
    test3_DW.durationCounter_3++;
  } else {
    test3_DW.durationCounter_3 = 0L;
  }

  if (test3_B.Max > 3.0F) {
    test3_DW.durationCounter_4++;
  } else {
    test3_DW.durationCounter_4 = 0L;
  }

  test3_B.Max = -(test3_U.Pack_Current / test3_Y.ChargeCurrentLimit);
  if (test3_B.Max > 1.1) {
    test3_DW.durationCounter_5++;
  } else {
    test3_DW.durationCounter_5 = 0L;
  }

  if (test3_B.Max > 1.5F) {
    test3_DW.durationCounter_6++;
  } else {
    test3_DW.durationCounter_6 = 0L;
  }

  if (test3_B.Max > 2.0F) {
    test3_DW.durationCounter_7++;
  } else {
    test3_DW.durationCounter_7 = 0L;
  }

  if (test3_B.Max > 3.0F) {
    test3_DW.durationCounter_8++;
  } else {
    test3_DW.durationCounter_8 = 0L;
  }

  if (test3_Y.MaxCellVolt >= 4.37F) {
    test3_DW.durationCounter_1_c++;
  } else {
    test3_DW.durationCounter_1_c = 0L;
  }

  if (test3_Y.MinCellVolt <= 2.5F) {
    test3_DW.durationCounter_2_aa++;
  } else {
    test3_DW.durationCounter_2_aa = 0L;
  }

  if (test3_Y.MaxCellTemp >= 328.15F) {
    test3_DW.durationCounter_1_p1++;
  } else {
    test3_DW.durationCounter_1_p1 = 0L;
  }

  if (test3_Y.MinCellTemp <= 253.15F) {
    test3_DW.durationCounter_2_h++;
  } else {
    test3_DW.durationCounter_2_h = 0L;
  }

  /* End of Outputs for SubSystem: '<Root>/BMS_Function' */

  /* Saturate: '<Root>/Saturation1' */
  if (test3_B.ChargeCurrentReq > 180.0F) {
    /* Outport: '<Root>/ChargeCurrentReq' */
    test3_Y.ChargeCurrentReq = 180.0F;
  } else if (test3_B.ChargeCurrentReq < 0.0F) {
    /* Outport: '<Root>/ChargeCurrentReq' */
    test3_Y.ChargeCurrentReq = 0.0F;
  } else {
    /* Outport: '<Root>/ChargeCurrentReq' */
    test3_Y.ChargeCurrentReq = test3_B.ChargeCurrentReq;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Outport: '<Root>/PreChargeRelay' incorporates:
   *  Logic: '<Root>/PreChargeRelay0'
   */
  test3_Y.PreChargeRelay = (test3_B.PreChargeRelayInvtrCmd ||
    test3_B.PreChargeRelayChgrCmd);

  /* Logic: '<Root>/PosContactor0' */
  test3_Y.PosContactor = (test3_B.PosContactorInvtrCmd ||
    test3_B.PosContactorChgrCmd);

  /* Logic: '<Root>/NegContactor0' */
  test3_Y.NegContactor = (test3_B.NegContactorInvtrCmd ||
    test3_B.NegContactorChgrCmd);

  /* Outport: '<Root>/Contactor_State' incorporates:
   *  Logic: '<Root>/AND'
   */
  test3_Y.Contactor_State = (test3_Y.PosContactor && test3_Y.NegContactor);

  /* Outputs for Atomic SubSystem: '<Root>/RCTcc' */
  /* Constant: '<Root>/Ah' incorporates:
   *  Constant: '<Root>/Max_Mileage'
   *  Inport: '<Root>/Pack_Current'
   *  Inport: '<Root>/ReqSOC'
   *  Outport: '<Root>/Add_Mileage_Range'
   *  Outport: '<Root>/Fake_SOC'
   *  Outport: '<Root>/RCT'
   *  Outport: '<Root>/RD'
   *  Outport: '<Root>/RDT'
   *  RateTransition: '<Root>/RT4'
   */
  test3_RCTcc(130U, test3_U.Pack_Current, test3_U.ReqSOC, test3_Y.Fake_SOC,
              test3_Y.Fake_SOC, 330.0F, &test3_Y.RCT, &test3_Y.RD, &test3_Y.RDT,
              &test3_Y.Add_Mileage_Range, &test3_B.Max, &test3_B.Saturation1,
              &test3_B.RCTcc, &test3_DW.RCTcc);

  /* End of Outputs for SubSystem: '<Root>/RCTcc' */

  /* Outputs for Atomic SubSystem: '<Root>/CAN_VCU_Fault' */
  /* Chart: '<S98>/Chart1' incorporates:
   *  Inport: '<Root>/CAN_VCU_Flag'
   *  Inport: '<Root>/CAN_VCU_cnt_rst'
   *  Outport: '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst_Cnt'
   */
  if (test3_DW.temporalCounter_i1 < MAX_uint32_T) {
    test3_DW.temporalCounter_i1++;
  }

  if (test3_DW.is_active_c5_test3 == 0U) {
    test3_DW.is_active_c5_test3 = 1U;
    test3_DW.is_reseting_Counter = test3_IN_step1;
    test3_DW.is_main_Task = test3_IN_MSG_Present;
    test3_DW.temporalCounter_i1 = 0UL;
    test3_B.i = 0;
  } else {
    if (test3_DW.is_reseting_Counter == 1U) {
      if (test3_U.CAN_VCU_cnt_rst == 1U) {
        test3_DW.is_reseting_Counter = test3_IN_step2;

        /* Outport: '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst_Cnt' */
        test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn = 0UL;
      }

      /* case IN_step2: */
    } else if (test3_U.CAN_VCU_cnt_rst == 0U) {
      test3_DW.is_reseting_Counter = test3_IN_step1;
    }

    if (test3_DW.is_main_Task == 1U) {
      if (test3_U.CAN_VCU_Flag == 1U) {
        test3_DW.is_main_Task = test3_IN_MSG_Present;
        test3_DW.temporalCounter_i1 = 0UL;
        test3_B.i = 0;
      } else if (test3_DW.temporalCounter_i1 >= 2UL) {
        test3_DW.temporalCounter_i1 = 0UL;
        test3_B.i = 1;
        test3_B.qY = test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn + /*MW:OvSatOk*/
          1UL;
        if (test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn + 1UL <
            test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn) {
          test3_B.qY = MAX_uint32_T;
        }

        /* Outport: '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst_Cnt' */
        test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn = test3_B.qY;
      } else {
        test3_B.i = 1;
      }

      /* case IN_MSG_Present: */
    } else if (test3_U.CAN_VCU_Flag == 1U) {
      test3_DW.is_main_Task = test3_IN_MSG_Present;
      test3_DW.temporalCounter_i1 = 0UL;
      test3_B.i = 0;
    } else if (test3_DW.temporalCounter_i1 >= 3UL) {
      test3_DW.is_main_Task = test3_IN_MSG_Absent;
      test3_DW.temporalCounter_i1 = 0UL;
      test3_B.i = 1;
      test3_B.qY = test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn + /*MW:OvSatOk*/ 1UL;
      if (test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn + 1UL <
          test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn) {
        test3_B.qY = MAX_uint32_T;
      }

      /* Outport: '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst_Cnt' */
      test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst_Cn = test3_B.qY;
    } else {
      test3_B.i = 0;
    }
  }

  /* End of Chart: '<S98>/Chart1' */

  /* Chart: '<S98>/Chart' */
  if (test3_DW.temporalCounter_i1_j < 63U) {
    test3_DW.temporalCounter_i1_j = (uint16_T)((int16_T)
      test3_DW.temporalCounter_i1_j + 1);
  }

  if (test3_DW.is_active_c4_test3 == 0U) {
    test3_DW.is_active_c4_test3 = 1U;
    test3_DW.is_c4_test3 = test3_IN_Static_present;

    /* Outport: '<Root>/CAN_VCU_Fault_Static_Absent' */
    test3_Y.CAN_VCU_Fault_Static_Absent = 0U;
    test3_DW.is_Static_present = test3_IN_STEP1;
  } else if (test3_DW.is_c4_test3 == 1U) {
    /* Outport: '<Root>/CAN_VCU_Fault_Static_Absent' */
    test3_Y.CAN_VCU_Fault_Static_Absent = 1U;
    if (test3_DW.is_Static_Absent == 1U) {
      if ((uint16_T)test3_B.i == 0U) {
        test3_DW.is_Static_Absent = test3_IN_pre_present;
        test3_DW.temporalCounter_i1_j = 0U;
      }

      /* case IN_pre_present: */
    } else if ((uint16_T)test3_B.i == 1U) {
      test3_DW.is_Static_Absent = test3_IN_STEP1;
    } else if (test3_DW.temporalCounter_i1_j >= 40U) {
      test3_DW.is_Static_Absent = test3_IN_NO_ACTIVE_CHILD_k;
      test3_DW.is_c4_test3 = test3_IN_Static_present;

      /* Outport: '<Root>/CAN_VCU_Fault_Static_Absent' */
      test3_Y.CAN_VCU_Fault_Static_Absent = 0U;
      test3_DW.is_Static_present = test3_IN_STEP1;
    }
  } else {
    /* Outport: '<Root>/CAN_VCU_Fault_Static_Absent' */
    /* case IN_Static_present: */
    test3_Y.CAN_VCU_Fault_Static_Absent = 0U;
    if (test3_DW.is_Static_present == 1U) {
      if ((uint16_T)test3_B.i == 1U) {
        test3_DW.is_Static_present = test3_IN_pre_Absent;
        test3_DW.temporalCounter_i1_j = 0U;
      }

      /* case IN_pre_Absent: */
    } else if ((uint16_T)test3_B.i == 0U) {
      test3_DW.is_Static_present = test3_IN_STEP1;
    } else if (test3_DW.temporalCounter_i1_j >= 40U) {
      test3_DW.is_Static_present = test3_IN_NO_ACTIVE_CHILD_k;
      test3_DW.is_c4_test3 = test3_IN_Static_Absent;

      /* Outport: '<Root>/CAN_VCU_Fault_Static_Absent' */
      test3_Y.CAN_VCU_Fault_Static_Absent = 1U;
      test3_DW.is_Static_Absent = test3_IN_STEP1;
    }
  }

  /* End of Chart: '<S98>/Chart' */
  /* End of Outputs for SubSystem: '<Root>/CAN_VCU_Fault' */

  /* Outport: '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst' */
  test3_Y.CAN_VCU_Fault_MSG_Dynmc_Abst = (uint16_T)test3_B.i;

  /* Outport: '<Root>/DC_Link_Volt' incorporates:
   *  Inport: '<Root>/Pack_Voltage'
   */
  test3_Y.DC_Link_Volt = test3_U.Pack_Voltage;

  /* Outport: '<Root>/PackCurrent' incorporates:
   *  Inport: '<Root>/Pack_Current'
   */
  test3_Y.PackCurrent = test3_U.Pack_Current;

  /* Update for DiscreteIntegrator: '<S106>/Integrator' */
  test3_DW.Integrator_IC_LOADING = 0U;

  /* MinMax: '<S101>/Max' */
  if (test3_B.Probe[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S106>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S101>/Max'
   *  Product: '<S1>/1//T'
   *  Sum: '<S1>/Sum1'
   */
  test3_DW.Integrator_DSTATE += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[0] - test3_DW.Integrator_DSTATE) * 0.01F;
  if (test3_DW.Integrator_DSTATE >= 6.0F) {
    test3_DW.Integrator_DSTATE = 6.0F;
  } else if (test3_DW.Integrator_DSTATE <= 0.0F) {
    test3_DW.Integrator_DSTATE = 0.0F;
  }

  test3_DW.Integrator_PrevResetState = (int16_T)test3_B.Compare;

  /* Update for DiscreteIntegrator: '<S172>/Integrator' */
  test3_DW.Integrator_IC_LOADING_p = 0U;

  /* MinMax: '<S167>/Max' */
  if (test3_B.Probe_l[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_l[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S172>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S167>/Max'
   *  Product: '<S12>/1//T'
   *  Sum: '<S12>/Sum1'
   */
  test3_DW.Integrator_DSTATE_a += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[1] - test3_DW.Integrator_DSTATE_a) * 0.01F;
  if (test3_DW.Integrator_DSTATE_a >= 6.0F) {
    test3_DW.Integrator_DSTATE_a = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_a <= 0.0F) {
    test3_DW.Integrator_DSTATE_a = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_p = (int16_T)test3_B.Compare_p;

  /* Update for DiscreteIntegrator: '<S238>/Integrator' */
  test3_DW.Integrator_IC_LOADING_g = 0U;

  /* MinMax: '<S233>/Max' */
  if (test3_B.Probe_i[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_i[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S238>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S233>/Max'
   *  Product: '<S23>/1//T'
   *  Sum: '<S23>/Sum1'
   */
  test3_DW.Integrator_DSTATE_n += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[2] - test3_DW.Integrator_DSTATE_n) * 0.01F;
  if (test3_DW.Integrator_DSTATE_n >= 6.0F) {
    test3_DW.Integrator_DSTATE_n = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_n <= 0.0F) {
    test3_DW.Integrator_DSTATE_n = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_o = (int16_T)test3_B.Compare_h;

  /* Update for DiscreteIntegrator: '<S304>/Integrator' */
  test3_DW.Integrator_IC_LOADING_j = 0U;

  /* MinMax: '<S299>/Max' */
  if (test3_B.Probe_o[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_o[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S304>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S299>/Max'
   *  Product: '<S34>/1//T'
   *  Sum: '<S34>/Sum1'
   */
  test3_DW.Integrator_DSTATE_b += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[3] - test3_DW.Integrator_DSTATE_b) * 0.01F;
  if (test3_DW.Integrator_DSTATE_b >= 6.0F) {
    test3_DW.Integrator_DSTATE_b = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_b <= 0.0F) {
    test3_DW.Integrator_DSTATE_b = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_e = (int16_T)test3_B.Compare_o;

  /* Update for DiscreteIntegrator: '<S370>/Integrator' */
  test3_DW.Integrator_IC_LOADING_h = 0U;

  /* MinMax: '<S365>/Max' */
  if (test3_B.Probe_ii[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ii[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S370>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S365>/Max'
   *  Product: '<S45>/1//T'
   *  Sum: '<S45>/Sum1'
   */
  test3_DW.Integrator_DSTATE_g += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[4] - test3_DW.Integrator_DSTATE_g) * 0.01F;
  if (test3_DW.Integrator_DSTATE_g >= 6.0F) {
    test3_DW.Integrator_DSTATE_g = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_g <= 0.0F) {
    test3_DW.Integrator_DSTATE_g = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_oy = (int16_T)test3_B.Compare_k;

  /* Update for DiscreteIntegrator: '<S436>/Integrator' */
  test3_DW.Integrator_IC_LOADING_k = 0U;

  /* MinMax: '<S431>/Max' */
  if (test3_B.Probe_e[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_e[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S436>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S431>/Max'
   *  Product: '<S56>/1//T'
   *  Sum: '<S56>/Sum1'
   */
  test3_DW.Integrator_DSTATE_i += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[5] - test3_DW.Integrator_DSTATE_i) * 0.01F;
  if (test3_DW.Integrator_DSTATE_i >= 6.0F) {
    test3_DW.Integrator_DSTATE_i = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_i <= 0.0F) {
    test3_DW.Integrator_DSTATE_i = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_c = (int16_T)test3_B.Compare_i;

  /* Update for DiscreteIntegrator: '<S502>/Integrator' */
  test3_DW.Integrator_IC_LOADING_o = 0U;

  /* MinMax: '<S497>/Max' */
  if (test3_B.Probe_n[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_n[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S502>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S497>/Max'
   *  Product: '<S67>/1//T'
   *  Sum: '<S67>/Sum1'
   */
  test3_DW.Integrator_DSTATE_e += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[6] - test3_DW.Integrator_DSTATE_e) * 0.01F;
  if (test3_DW.Integrator_DSTATE_e >= 6.0F) {
    test3_DW.Integrator_DSTATE_e = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_e <= 0.0F) {
    test3_DW.Integrator_DSTATE_e = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_a = (int16_T)test3_B.Compare_e;

  /* Update for DiscreteIntegrator: '<S568>/Integrator' */
  test3_DW.Integrator_IC_LOADING_g2 = 0U;

  /* MinMax: '<S563>/Max' */
  if (test3_B.Probe_ng[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ng[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S568>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S563>/Max'
   *  Product: '<S78>/1//T'
   *  Sum: '<S78>/Sum1'
   */
  test3_DW.Integrator_DSTATE_id += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[7] - test3_DW.Integrator_DSTATE_id) * 0.01F;
  if (test3_DW.Integrator_DSTATE_id >= 6.0F) {
    test3_DW.Integrator_DSTATE_id = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_id <= 0.0F) {
    test3_DW.Integrator_DSTATE_id = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ch = (int16_T)test3_B.Compare_k5;

  /* Update for DiscreteIntegrator: '<S634>/Integrator' */
  test3_DW.Integrator_IC_LOADING_d = 0U;

  /* MinMax: '<S629>/Max' */
  if (test3_B.Probe_no[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_no[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S634>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S629>/Max'
   *  Product: '<S89>/1//T'
   *  Sum: '<S89>/Sum1'
   */
  test3_DW.Integrator_DSTATE_is += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[8] - test3_DW.Integrator_DSTATE_is) * 0.01F;
  if (test3_DW.Integrator_DSTATE_is >= 6.0F) {
    test3_DW.Integrator_DSTATE_is = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_is <= 0.0F) {
    test3_DW.Integrator_DSTATE_is = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_h = (int16_T)test3_B.Compare_l;

  /* Update for DiscreteIntegrator: '<S112>/Integrator' */
  test3_DW.Integrator_IC_LOADING_pv = 0U;

  /* MinMax: '<S107>/Max' */
  if (test3_B.Probe_b[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_b[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S112>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S107>/Max'
   *  Product: '<S2>/1//T'
   *  Sum: '<S2>/Sum1'
   */
  test3_DW.Integrator_DSTATE_j += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[9] - test3_DW.Integrator_DSTATE_j) * 0.01F;
  if (test3_DW.Integrator_DSTATE_j >= 6.0F) {
    test3_DW.Integrator_DSTATE_j = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_j <= 0.0F) {
    test3_DW.Integrator_DSTATE_j = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_i = (int16_T)test3_B.Compare_iz;

  /* Update for DiscreteIntegrator: '<S118>/Integrator' */
  test3_DW.Integrator_IC_LOADING_m = 0U;

  /* MinMax: '<S113>/Max' */
  if (test3_B.Probe_j[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_j[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S113>/Max'
   *  Product: '<S3>/1//T'
   *  Sum: '<S3>/Sum1'
   */
  test3_DW.Integrator_DSTATE_j1 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[10] - test3_DW.Integrator_DSTATE_j1) * 0.01F;
  if (test3_DW.Integrator_DSTATE_j1 >= 6.0F) {
    test3_DW.Integrator_DSTATE_j1 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_j1 <= 0.0F) {
    test3_DW.Integrator_DSTATE_j1 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_iy = (int16_T)test3_B.Compare_d;

  /* Update for DiscreteIntegrator: '<S124>/Integrator' */
  test3_DW.Integrator_IC_LOADING_hr = 0U;

  /* MinMax: '<S119>/Max' */
  if (test3_B.Probe_os[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_os[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S124>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S119>/Max'
   *  Product: '<S4>/1//T'
   *  Sum: '<S4>/Sum1'
   */
  test3_DW.Integrator_DSTATE_jr += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[11] - test3_DW.Integrator_DSTATE_jr) * 0.01F;
  if (test3_DW.Integrator_DSTATE_jr >= 6.0F) {
    test3_DW.Integrator_DSTATE_jr = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_jr <= 0.0F) {
    test3_DW.Integrator_DSTATE_jr = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_g = (int16_T)test3_B.Compare_a;

  /* Update for DiscreteIntegrator: '<S130>/Integrator' */
  test3_DW.Integrator_IC_LOADING_i = 0U;

  /* MinMax: '<S125>/Max' */
  if (test3_B.Probe_m[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_m[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S130>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S125>/Max'
   *  Product: '<S5>/1//T'
   *  Sum: '<S5>/Sum1'
   */
  test3_DW.Integrator_DSTATE_p += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[12] - test3_DW.Integrator_DSTATE_p) * 0.01F;
  if (test3_DW.Integrator_DSTATE_p >= 6.0F) {
    test3_DW.Integrator_DSTATE_p = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_p <= 0.0F) {
    test3_DW.Integrator_DSTATE_p = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_f = (int16_T)test3_B.Compare_p3;

  /* Update for DiscreteIntegrator: '<S136>/Integrator' */
  test3_DW.Integrator_IC_LOADING_e = 0U;

  /* MinMax: '<S131>/Max' */
  if (test3_B.Probe_c[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_c[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S136>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S131>/Max'
   *  Product: '<S6>/1//T'
   *  Sum: '<S6>/Sum1'
   */
  test3_DW.Integrator_DSTATE_o += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[13] - test3_DW.Integrator_DSTATE_o) * 0.01F;
  if (test3_DW.Integrator_DSTATE_o >= 6.0F) {
    test3_DW.Integrator_DSTATE_o = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_o <= 0.0F) {
    test3_DW.Integrator_DSTATE_o = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fi = (int16_T)test3_B.Compare_o1;

  /* Update for DiscreteIntegrator: '<S142>/Integrator' */
  test3_DW.Integrator_IC_LOADING_df = 0U;

  /* MinMax: '<S137>/Max' */
  if (test3_B.Probe_lt[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_lt[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S142>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S137>/Max'
   *  Product: '<S7>/1//T'
   *  Sum: '<S7>/Sum1'
   */
  test3_DW.Integrator_DSTATE_f += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[14] - test3_DW.Integrator_DSTATE_f) * 0.01F;
  if (test3_DW.Integrator_DSTATE_f >= 6.0F) {
    test3_DW.Integrator_DSTATE_f = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_f <= 0.0F) {
    test3_DW.Integrator_DSTATE_f = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fm = (int16_T)test3_B.Compare_ob;

  /* Update for DiscreteIntegrator: '<S148>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ip = 0U;

  /* MinMax: '<S143>/Max' */
  if (test3_B.Probe_ik[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ik[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S148>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S143>/Max'
   *  Product: '<S8>/1//T'
   *  Sum: '<S8>/Sum1'
   */
  test3_DW.Integrator_DSTATE_fo += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[15] - test3_DW.Integrator_DSTATE_fo) * 0.01F;
  if (test3_DW.Integrator_DSTATE_fo >= 6.0F) {
    test3_DW.Integrator_DSTATE_fo = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fo <= 0.0F) {
    test3_DW.Integrator_DSTATE_fo = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_gh = (int16_T)test3_B.Compare_n;

  /* Update for DiscreteIntegrator: '<S154>/Integrator' */
  test3_DW.Integrator_IC_LOADING_a = 0U;

  /* MinMax: '<S149>/Max' */
  if (test3_B.Probe_ct[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ct[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S149>/Max'
   *  Product: '<S9>/1//T'
   *  Sum: '<S9>/Sum1'
   */
  test3_DW.Integrator_DSTATE_i1 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[16] - test3_DW.Integrator_DSTATE_i1) * 0.01F;
  if (test3_DW.Integrator_DSTATE_i1 >= 6.0F) {
    test3_DW.Integrator_DSTATE_i1 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_i1 <= 0.0F) {
    test3_DW.Integrator_DSTATE_i1 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_b = (int16_T)test3_B.Compare_ii;

  /* Update for DiscreteIntegrator: '<S160>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ic = 0U;

  /* MinMax: '<S155>/Max' */
  if (test3_B.Probe_f[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_f[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S160>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S155>/Max'
   *  Product: '<S10>/1//T'
   *  Sum: '<S10>/Sum1'
   */
  test3_DW.Integrator_DSTATE_fj += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[17] - test3_DW.Integrator_DSTATE_fj) * 0.01F;
  if (test3_DW.Integrator_DSTATE_fj >= 6.0F) {
    test3_DW.Integrator_DSTATE_fj = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fj <= 0.0F) {
    test3_DW.Integrator_DSTATE_fj = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_bl = (int16_T)test3_B.Compare_b;

  /* Update for DiscreteIntegrator: '<S166>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ab = 0U;

  /* MinMax: '<S161>/Max' */
  if (test3_B.Probe_fp[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_fp[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S166>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S161>/Max'
   *  Product: '<S11>/1//T'
   *  Sum: '<S11>/Sum1'
   */
  test3_DW.Integrator_DSTATE_d += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[18] - test3_DW.Integrator_DSTATE_d) * 0.01F;
  if (test3_DW.Integrator_DSTATE_d >= 6.0F) {
    test3_DW.Integrator_DSTATE_d = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_d <= 0.0F) {
    test3_DW.Integrator_DSTATE_d = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fie = (int16_T)test3_B.Compare_f;

  /* Update for DiscreteIntegrator: '<S178>/Integrator' */
  test3_DW.Integrator_IC_LOADING_oe = 0U;

  /* MinMax: '<S173>/Max' */
  if (test3_B.Probe_g[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_g[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S178>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S173>/Max'
   *  Product: '<S13>/1//T'
   *  Sum: '<S13>/Sum1'
   */
  test3_DW.Integrator_DSTATE_g5 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[19] - test3_DW.Integrator_DSTATE_g5) * 0.01F;
  if (test3_DW.Integrator_DSTATE_g5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_g5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_g5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_g5 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_d = (int16_T)test3_B.Compare_km;

  /* Update for DiscreteIntegrator: '<S184>/Integrator' */
  test3_DW.Integrator_IC_LOADING_op = 0U;

  /* MinMax: '<S179>/Max' */
  if (test3_B.Probe_h[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_h[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S184>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S179>/Max'
   *  Product: '<S14>/1//T'
   *  Sum: '<S14>/Sum1'
   */
  test3_DW.Integrator_DSTATE_pf += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[20] - test3_DW.Integrator_DSTATE_pf) * 0.01F;
  if (test3_DW.Integrator_DSTATE_pf >= 6.0F) {
    test3_DW.Integrator_DSTATE_pf = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pf <= 0.0F) {
    test3_DW.Integrator_DSTATE_pf = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_k = (int16_T)test3_B.Compare_in;

  /* Update for DiscreteIntegrator: '<S190>/Integrator' */
  test3_DW.Integrator_IC_LOADING_hg = 0U;

  /* MinMax: '<S185>/Max' */
  if (test3_B.Probe_o4[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_o4[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S190>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S185>/Max'
   *  Product: '<S15>/1//T'
   *  Sum: '<S15>/Sum1'
   */
  test3_DW.Integrator_DSTATE_c += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[21] - test3_DW.Integrator_DSTATE_c) * 0.01F;
  if (test3_DW.Integrator_DSTATE_c >= 6.0F) {
    test3_DW.Integrator_DSTATE_c = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_c <= 0.0F) {
    test3_DW.Integrator_DSTATE_c = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_n = (int16_T)test3_B.Compare_lv;

  /* Update for DiscreteIntegrator: '<S196>/Integrator' */
  test3_DW.Integrator_IC_LOADING_l = 0U;

  /* MinMax: '<S191>/Max' */
  if (test3_B.Probe_fc[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_fc[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S196>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S191>/Max'
   *  Product: '<S16>/1//T'
   *  Sum: '<S16>/Sum1'
   */
  test3_DW.Integrator_DSTATE_m += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[22] - test3_DW.Integrator_DSTATE_m) * 0.01F;
  if (test3_DW.Integrator_DSTATE_m >= 6.0F) {
    test3_DW.Integrator_DSTATE_m = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_m <= 0.0F) {
    test3_DW.Integrator_DSTATE_m = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fz = (int16_T)test3_B.Compare_ed;

  /* Update for DiscreteIntegrator: '<S202>/Integrator' */
  test3_DW.Integrator_IC_LOADING_iw = 0U;

  /* MinMax: '<S197>/Max' */
  if (test3_B.Probe_f1[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_f1[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S202>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S197>/Max'
   *  Product: '<S17>/1//T'
   *  Sum: '<S17>/Sum1'
   */
  test3_DW.Integrator_DSTATE_j2 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[23] - test3_DW.Integrator_DSTATE_j2) * 0.01F;
  if (test3_DW.Integrator_DSTATE_j2 >= 6.0F) {
    test3_DW.Integrator_DSTATE_j2 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_j2 <= 0.0F) {
    test3_DW.Integrator_DSTATE_j2 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_m = (int16_T)test3_B.Compare_el;

  /* Update for DiscreteIntegrator: '<S208>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ky = 0U;

  /* MinMax: '<S203>/Max' */
  if (test3_B.Probe_bf[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_bf[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S208>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S203>/Max'
   *  Product: '<S18>/1//T'
   *  Sum: '<S18>/Sum1'
   */
  test3_DW.Integrator_DSTATE_iz += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[24] - test3_DW.Integrator_DSTATE_iz) * 0.01F;
  if (test3_DW.Integrator_DSTATE_iz >= 6.0F) {
    test3_DW.Integrator_DSTATE_iz = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_iz <= 0.0F) {
    test3_DW.Integrator_DSTATE_iz = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_hi = (int16_T)test3_B.Compare_kl;

  /* Update for DiscreteIntegrator: '<S214>/Integrator' */
  test3_DW.Integrator_IC_LOADING_b = 0U;

  /* MinMax: '<S209>/Max' */
  if (test3_B.Probe_gu[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_gu[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S214>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S209>/Max'
   *  Product: '<S19>/1//T'
   *  Sum: '<S19>/Sum1'
   */
  test3_DW.Integrator_DSTATE_bh += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[25] - test3_DW.Integrator_DSTATE_bh) * 0.01F;
  if (test3_DW.Integrator_DSTATE_bh >= 6.0F) {
    test3_DW.Integrator_DSTATE_bh = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bh <= 0.0F) {
    test3_DW.Integrator_DSTATE_bh = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fy = (int16_T)test3_B.Compare_kf;

  /* Update for DiscreteIntegrator: '<S220>/Integrator' */
  test3_DW.Integrator_IC_LOADING_gu = 0U;

  /* MinMax: '<S215>/Max' */
  if (test3_B.Probe_er[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_er[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S220>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S215>/Max'
   *  Product: '<S20>/1//T'
   *  Sum: '<S20>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ji += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[26] - test3_DW.Integrator_DSTATE_ji) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ji >= 6.0F) {
    test3_DW.Integrator_DSTATE_ji = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ji <= 0.0F) {
    test3_DW.Integrator_DSTATE_ji = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ok = (int16_T)test3_B.Compare_hy;

  /* Update for DiscreteIntegrator: '<S226>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ao = 0U;

  /* MinMax: '<S221>/Max' */
  if (test3_B.Probe_hq[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_hq[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S226>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S221>/Max'
   *  Product: '<S21>/1//T'
   *  Sum: '<S21>/Sum1'
   */
  test3_DW.Integrator_DSTATE_od += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[27] - test3_DW.Integrator_DSTATE_od) * 0.01F;
  if (test3_DW.Integrator_DSTATE_od >= 6.0F) {
    test3_DW.Integrator_DSTATE_od = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_od <= 0.0F) {
    test3_DW.Integrator_DSTATE_od = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_j = (int16_T)test3_B.Compare_oi;

  /* Update for DiscreteIntegrator: '<S232>/Integrator' */
  test3_DW.Integrator_IC_LOADING_f = 0U;

  /* MinMax: '<S227>/Max' */
  if (test3_B.Probe_md[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_md[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S232>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S227>/Max'
   *  Product: '<S22>/1//T'
   *  Sum: '<S22>/Sum1'
   */
  test3_DW.Integrator_DSTATE_oy += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[28] - test3_DW.Integrator_DSTATE_oy) * 0.01F;
  if (test3_DW.Integrator_DSTATE_oy >= 6.0F) {
    test3_DW.Integrator_DSTATE_oy = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_oy <= 0.0F) {
    test3_DW.Integrator_DSTATE_oy = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_dh = (int16_T)test3_B.Compare_i1;

  /* Update for DiscreteIntegrator: '<S244>/Integrator' */
  test3_DW.Integrator_IC_LOADING_c = 0U;

  /* MinMax: '<S239>/Max' */
  if (test3_B.Probe_p[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_p[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S244>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S239>/Max'
   *  Product: '<S24>/1//T'
   *  Sum: '<S24>/Sum1'
   */
  test3_DW.Integrator_DSTATE_nc += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[29] - test3_DW.Integrator_DSTATE_nc) * 0.01F;
  if (test3_DW.Integrator_DSTATE_nc >= 6.0F) {
    test3_DW.Integrator_DSTATE_nc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_nc <= 0.0F) {
    test3_DW.Integrator_DSTATE_nc = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ne = (int16_T)test3_B.Compare_g;

  /* Update for DiscreteIntegrator: '<S250>/Integrator' */
  test3_DW.Integrator_IC_LOADING_fc = 0U;

  /* MinMax: '<S245>/Max' */
  if (test3_B.Probe_pe[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_pe[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S250>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S245>/Max'
   *  Product: '<S25>/1//T'
   *  Sum: '<S25>/Sum1'
   */
  test3_DW.Integrator_DSTATE_c2 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[30] - test3_DW.Integrator_DSTATE_c2) * 0.01F;
  if (test3_DW.Integrator_DSTATE_c2 >= 6.0F) {
    test3_DW.Integrator_DSTATE_c2 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_c2 <= 0.0F) {
    test3_DW.Integrator_DSTATE_c2 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fl = (int16_T)test3_B.Compare_ec;

  /* Update for DiscreteIntegrator: '<S256>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bd = 0U;

  /* MinMax: '<S251>/Max' */
  if (test3_B.Probe_gb[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_gb[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S256>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S251>/Max'
   *  Product: '<S26>/1//T'
   *  Sum: '<S26>/Sum1'
   */
  test3_DW.Integrator_DSTATE_pa += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[31] - test3_DW.Integrator_DSTATE_pa) * 0.01F;
  if (test3_DW.Integrator_DSTATE_pa >= 6.0F) {
    test3_DW.Integrator_DSTATE_pa = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pa <= 0.0F) {
    test3_DW.Integrator_DSTATE_pa = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ib = (int16_T)test3_B.Compare_kh;

  /* Update for DiscreteIntegrator: '<S262>/Integrator' */
  test3_DW.Integrator_IC_LOADING_n = 0U;

  /* MinMax: '<S257>/Max' */
  if (test3_B.Probe_gs[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_gs[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S262>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S257>/Max'
   *  Product: '<S27>/1//T'
   *  Sum: '<S27>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ez += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[32] - test3_DW.Integrator_DSTATE_ez) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ez >= 6.0F) {
    test3_DW.Integrator_DSTATE_ez = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ez <= 0.0F) {
    test3_DW.Integrator_DSTATE_ez = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_dz = (int16_T)test3_B.Compare_go;

  /* Update for DiscreteIntegrator: '<S268>/Integrator' */
  test3_DW.Integrator_IC_LOADING_aoc = 0U;

  /* MinMax: '<S263>/Max' */
  if (test3_B.Probe_p1[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_p1[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S268>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S263>/Max'
   *  Product: '<S28>/1//T'
   *  Sum: '<S28>/Sum1'
   */
  test3_DW.Integrator_DSTATE_bp += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[33] - test3_DW.Integrator_DSTATE_bp) * 0.01F;
  if (test3_DW.Integrator_DSTATE_bp >= 6.0F) {
    test3_DW.Integrator_DSTATE_bp = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bp <= 0.0F) {
    test3_DW.Integrator_DSTATE_bp = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_l = (int16_T)test3_B.Compare_hb;

  /* Update for DiscreteIntegrator: '<S274>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kr = 0U;

  /* MinMax: '<S269>/Max' */
  if (test3_B.Probe_j0[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_j0[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S274>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S269>/Max'
   *  Product: '<S29>/1//T'
   *  Sum: '<S29>/Sum1'
   */
  test3_DW.Integrator_DSTATE_h += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[34] - test3_DW.Integrator_DSTATE_h) * 0.01F;
  if (test3_DW.Integrator_DSTATE_h >= 6.0F) {
    test3_DW.Integrator_DSTATE_h = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_h <= 0.0F) {
    test3_DW.Integrator_DSTATE_h = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_hm = (int16_T)test3_B.Compare_d2;

  /* Update for DiscreteIntegrator: '<S280>/Integrator' */
  test3_DW.Integrator_IC_LOADING_n3 = 0U;

  /* MinMax: '<S275>/Max' */
  if (test3_B.Probe_ib[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ib[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S280>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S275>/Max'
   *  Product: '<S30>/1//T'
   *  Sum: '<S30>/Sum1'
   */
  test3_DW.Integrator_DSTATE_i4 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[35] - test3_DW.Integrator_DSTATE_i4) * 0.01F;
  if (test3_DW.Integrator_DSTATE_i4 >= 6.0F) {
    test3_DW.Integrator_DSTATE_i4 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_i4 <= 0.0F) {
    test3_DW.Integrator_DSTATE_i4 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_lo = (int16_T)test3_B.Compare_kfs;

  /* Update for DiscreteIntegrator: '<S286>/Integrator' */
  test3_DW.Integrator_IC_LOADING_pe = 0U;

  /* MinMax: '<S281>/Max' */
  if (test3_B.Probe_nm[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_nm[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S286>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S281>/Max'
   *  Product: '<S31>/1//T'
   *  Sum: '<S31>/Sum1'
   */
  test3_DW.Integrator_DSTATE_fp += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[36] - test3_DW.Integrator_DSTATE_fp) * 0.01F;
  if (test3_DW.Integrator_DSTATE_fp >= 6.0F) {
    test3_DW.Integrator_DSTATE_fp = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fp <= 0.0F) {
    test3_DW.Integrator_DSTATE_fp = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_dk = (int16_T)test3_B.Compare_b3;

  /* Update for DiscreteIntegrator: '<S292>/Integrator' */
  test3_DW.Integrator_IC_LOADING_gb = 0U;

  /* MinMax: '<S287>/Max' */
  if (test3_B.Probe_hh[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_hh[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S292>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S287>/Max'
   *  Product: '<S32>/1//T'
   *  Sum: '<S32>/Sum1'
   */
  test3_DW.Integrator_DSTATE_hx += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[37] - test3_DW.Integrator_DSTATE_hx) * 0.01F;
  if (test3_DW.Integrator_DSTATE_hx >= 6.0F) {
    test3_DW.Integrator_DSTATE_hx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_hx <= 0.0F) {
    test3_DW.Integrator_DSTATE_hx = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_es = (int16_T)test3_B.Compare_kd;

  /* Update for DiscreteIntegrator: '<S298>/Integrator' */
  test3_DW.Integrator_IC_LOADING_gg = 0U;

  /* MinMax: '<S293>/Max' */
  if (test3_B.Probe_d[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_d[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S298>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S293>/Max'
   *  Product: '<S33>/1//T'
   *  Sum: '<S33>/Sum1'
   */
  test3_DW.Integrator_DSTATE_k += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[38] - test3_DW.Integrator_DSTATE_k) * 0.01F;
  if (test3_DW.Integrator_DSTATE_k >= 6.0F) {
    test3_DW.Integrator_DSTATE_k = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_k <= 0.0F) {
    test3_DW.Integrator_DSTATE_k = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fu = (int16_T)test3_B.Compare_dh;

  /* Update for DiscreteIntegrator: '<S310>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bb = 0U;

  /* MinMax: '<S305>/Max' */
  if (test3_B.Probe_fv[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_fv[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S310>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S305>/Max'
   *  Product: '<S35>/1//T'
   *  Sum: '<S35>/Sum1'
   */
  test3_DW.Integrator_DSTATE_g3 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[39] - test3_DW.Integrator_DSTATE_g3) * 0.01F;
  if (test3_DW.Integrator_DSTATE_g3 >= 6.0F) {
    test3_DW.Integrator_DSTATE_g3 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_g3 <= 0.0F) {
    test3_DW.Integrator_DSTATE_g3 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_cv = (int16_T)test3_B.Compare_kv;

  /* Update for DiscreteIntegrator: '<S316>/Integrator' */
  test3_DW.Integrator_IC_LOADING_p4 = 0U;

  /* MinMax: '<S311>/Max' */
  if (test3_B.Probe_ij[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ij[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S316>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S311>/Max'
   *  Product: '<S36>/1//T'
   *  Sum: '<S36>/Sum1'
   */
  test3_DW.Integrator_DSTATE_h4 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[40] - test3_DW.Integrator_DSTATE_h4) * 0.01F;
  if (test3_DW.Integrator_DSTATE_h4 >= 6.0F) {
    test3_DW.Integrator_DSTATE_h4 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_h4 <= 0.0F) {
    test3_DW.Integrator_DSTATE_h4 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ke = (int16_T)test3_B.Compare_of;

  /* Update for DiscreteIntegrator: '<S322>/Integrator' */
  test3_DW.Integrator_IC_LOADING_mv = 0U;

  /* MinMax: '<S317>/Max' */
  if (test3_B.Probe_pk[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_pk[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S322>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S317>/Max'
   *  Product: '<S37>/1//T'
   *  Sum: '<S37>/Sum1'
   */
  test3_DW.Integrator_DSTATE_e5 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[41] - test3_DW.Integrator_DSTATE_e5) * 0.01F;
  if (test3_DW.Integrator_DSTATE_e5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_e5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_e5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_e5 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fa = (int16_T)test3_B.Compare_bn;

  /* Update for DiscreteIntegrator: '<S328>/Integrator' */
  test3_DW.Integrator_IC_LOADING_j1 = 0U;

  /* MinMax: '<S323>/Max' */
  if (test3_B.Probe_a[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_a[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S328>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S323>/Max'
   *  Product: '<S38>/1//T'
   *  Sum: '<S38>/Sum1'
   */
  test3_DW.Integrator_DSTATE_oc += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[42] - test3_DW.Integrator_DSTATE_oc) * 0.01F;
  if (test3_DW.Integrator_DSTATE_oc >= 6.0F) {
    test3_DW.Integrator_DSTATE_oc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_oc <= 0.0F) {
    test3_DW.Integrator_DSTATE_oc = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_h4 = (int16_T)test3_B.Compare_ix;

  /* Update for DiscreteIntegrator: '<S334>/Integrator' */
  test3_DW.Integrator_IC_LOADING_az = 0U;

  /* MinMax: '<S329>/Max' */
  if (test3_B.Probe_fpu[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_fpu[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S334>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S329>/Max'
   *  Product: '<S39>/1//T'
   *  Sum: '<S39>/Sum1'
   */
  test3_DW.Integrator_DSTATE_n5 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[43] - test3_DW.Integrator_DSTATE_n5) * 0.01F;
  if (test3_DW.Integrator_DSTATE_n5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_n5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_n5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_n5 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_io = (int16_T)test3_B.Compare_gy;

  /* Update for DiscreteIntegrator: '<S340>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bm = 0U;

  /* MinMax: '<S335>/Max' */
  if (test3_B.Probe_m0[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_m0[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S340>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S335>/Max'
   *  Product: '<S40>/1//T'
   *  Sum: '<S40>/Sum1'
   */
  test3_DW.Integrator_DSTATE_do += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[44] - test3_DW.Integrator_DSTATE_do) * 0.01F;
  if (test3_DW.Integrator_DSTATE_do >= 6.0F) {
    test3_DW.Integrator_DSTATE_do = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_do <= 0.0F) {
    test3_DW.Integrator_DSTATE_do = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_k3 = (int16_T)test3_B.Compare_kz;

  /* Update for DiscreteIntegrator: '<S346>/Integrator' */
  test3_DW.Integrator_IC_LOADING_c0 = 0U;

  /* MinMax: '<S341>/Max' */
  if (test3_B.Probe_mt[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_mt[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S346>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S341>/Max'
   *  Product: '<S41>/1//T'
   *  Sum: '<S41>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ds += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[45] - test3_DW.Integrator_DSTATE_ds) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ds >= 6.0F) {
    test3_DW.Integrator_DSTATE_ds = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ds <= 0.0F) {
    test3_DW.Integrator_DSTATE_ds = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ed = (int16_T)test3_B.Compare_hi;

  /* Update for DiscreteIntegrator: '<S352>/Integrator' */
  test3_DW.Integrator_IC_LOADING_p0 = 0U;

  /* MinMax: '<S347>/Max' */
  if (test3_B.Probe_fn[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_fn[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S352>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S347>/Max'
   *  Product: '<S42>/1//T'
   *  Sum: '<S42>/Sum1'
   */
  test3_DW.Integrator_DSTATE_bv += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[46] - test3_DW.Integrator_DSTATE_bv) * 0.01F;
  if (test3_DW.Integrator_DSTATE_bv >= 6.0F) {
    test3_DW.Integrator_DSTATE_bv = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bv <= 0.0F) {
    test3_DW.Integrator_DSTATE_bv = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_on = (int16_T)test3_B.Compare_by;

  /* Update for DiscreteIntegrator: '<S358>/Integrator' */
  test3_DW.Integrator_IC_LOADING_j3 = 0U;

  /* MinMax: '<S353>/Max' */
  if (test3_B.Probe_op[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_op[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S358>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S353>/Max'
   *  Product: '<S43>/1//T'
   *  Sum: '<S43>/Sum1'
   */
  test3_DW.Integrator_DSTATE_o3 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[47] - test3_DW.Integrator_DSTATE_o3) * 0.01F;
  if (test3_DW.Integrator_DSTATE_o3 >= 6.0F) {
    test3_DW.Integrator_DSTATE_o3 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_o3 <= 0.0F) {
    test3_DW.Integrator_DSTATE_o3 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_cb = (int16_T)test3_B.Compare_pn;

  /* Update for DiscreteIntegrator: '<S364>/Integrator' */
  test3_DW.Integrator_IC_LOADING_hf = 0U;

  /* MinMax: '<S359>/Max' */
  if (test3_B.Probe_k[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_k[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S364>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S359>/Max'
   *  Product: '<S44>/1//T'
   *  Sum: '<S44>/Sum1'
   */
  test3_DW.Integrator_DSTATE_fg += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[48] - test3_DW.Integrator_DSTATE_fg) * 0.01F;
  if (test3_DW.Integrator_DSTATE_fg >= 6.0F) {
    test3_DW.Integrator_DSTATE_fg = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fg <= 0.0F) {
    test3_DW.Integrator_DSTATE_fg = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fj = (int16_T)test3_B.Compare_ep;

  /* Update for DiscreteIntegrator: '<S376>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ms = 0U;

  /* MinMax: '<S371>/Max' */
  if (test3_B.Probe_ll[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ll[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S376>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S371>/Max'
   *  Product: '<S46>/1//T'
   *  Sum: '<S46>/Sum1'
   */
  test3_DW.Integrator_DSTATE_a4 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[49] - test3_DW.Integrator_DSTATE_a4) * 0.01F;
  if (test3_DW.Integrator_DSTATE_a4 >= 6.0F) {
    test3_DW.Integrator_DSTATE_a4 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_a4 <= 0.0F) {
    test3_DW.Integrator_DSTATE_a4 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_kk = (int16_T)test3_B.Compare_ev;

  /* Update for DiscreteIntegrator: '<S382>/Integrator' */
  test3_DW.Integrator_IC_LOADING_me = 0U;

  /* MinMax: '<S377>/Max' */
  if (test3_B.Probe_dm[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_dm[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S382>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S377>/Max'
   *  Product: '<S47>/1//T'
   *  Sum: '<S47>/Sum1'
   */
  test3_DW.Integrator_DSTATE_l += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[50] - test3_DW.Integrator_DSTATE_l) * 0.01F;
  if (test3_DW.Integrator_DSTATE_l >= 6.0F) {
    test3_DW.Integrator_DSTATE_l = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_l <= 0.0F) {
    test3_DW.Integrator_DSTATE_l = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ie = (int16_T)test3_B.Compare_bm;

  /* Update for DiscreteIntegrator: '<S388>/Integrator' */
  test3_DW.Integrator_IC_LOADING_oq = 0U;

  /* MinMax: '<S383>/Max' */
  if (test3_B.Probe_ba[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ba[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S388>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S383>/Max'
   *  Product: '<S48>/1//T'
   *  Sum: '<S48>/Sum1'
   */
  test3_DW.Integrator_DSTATE_eo += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[51] - test3_DW.Integrator_DSTATE_eo) * 0.01F;
  if (test3_DW.Integrator_DSTATE_eo >= 6.0F) {
    test3_DW.Integrator_DSTATE_eo = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_eo <= 0.0F) {
    test3_DW.Integrator_DSTATE_eo = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_pp = (int16_T)test3_B.Compare_io;

  /* Update for DiscreteIntegrator: '<S394>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kz = 0U;

  /* MinMax: '<S389>/Max' */
  if (test3_B.Probe_j0k[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_j0k[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S394>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S389>/Max'
   *  Product: '<S49>/1//T'
   *  Sum: '<S49>/Sum1'
   */
  test3_DW.Integrator_DSTATE_cl += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[52] - test3_DW.Integrator_DSTATE_cl) * 0.01F;
  if (test3_DW.Integrator_DSTATE_cl >= 6.0F) {
    test3_DW.Integrator_DSTATE_cl = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_cl <= 0.0F) {
    test3_DW.Integrator_DSTATE_cl = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ox = (int16_T)test3_B.Compare_ax;

  /* Update for DiscreteIntegrator: '<S400>/Integrator' */
  test3_DW.Integrator_IC_LOADING_b1 = 0U;

  /* MinMax: '<S395>/Max' */
  if (test3_B.Probe_gj[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_gj[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S400>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S395>/Max'
   *  Product: '<S50>/1//T'
   *  Sum: '<S50>/Sum1'
   */
  test3_DW.Integrator_DSTATE_bs += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[53] - test3_DW.Integrator_DSTATE_bs) * 0.01F;
  if (test3_DW.Integrator_DSTATE_bs >= 6.0F) {
    test3_DW.Integrator_DSTATE_bs = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bs <= 0.0F) {
    test3_DW.Integrator_DSTATE_bs = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fn = (int16_T)test3_B.Compare_gr;

  /* Update for DiscreteIntegrator: '<S406>/Integrator' */
  test3_DW.Integrator_IC_LOADING_j3b = 0U;

  /* MinMax: '<S401>/Max' */
  if (test3_B.Probe_po[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_po[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S406>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S401>/Max'
   *  Product: '<S51>/1//T'
   *  Sum: '<S51>/Sum1'
   */
  test3_DW.Integrator_DSTATE_e2 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[54] - test3_DW.Integrator_DSTATE_e2) * 0.01F;
  if (test3_DW.Integrator_DSTATE_e2 >= 6.0F) {
    test3_DW.Integrator_DSTATE_e2 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_e2 <= 0.0F) {
    test3_DW.Integrator_DSTATE_e2 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_mk = (int16_T)test3_B.Compare_fw;

  /* Update for DiscreteIntegrator: '<S412>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ar = 0U;

  /* MinMax: '<S407>/Max' */
  if (test3_B.Probe_f2[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_f2[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S412>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S407>/Max'
   *  Product: '<S52>/1//T'
   *  Sum: '<S52>/Sum1'
   */
  test3_DW.Integrator_DSTATE_lr += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[55] - test3_DW.Integrator_DSTATE_lr) * 0.01F;
  if (test3_DW.Integrator_DSTATE_lr >= 6.0F) {
    test3_DW.Integrator_DSTATE_lr = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_lr <= 0.0F) {
    test3_DW.Integrator_DSTATE_lr = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_m1 = (int16_T)test3_B.Compare_j;

  /* Update for DiscreteIntegrator: '<S418>/Integrator' */
  test3_DW.Integrator_IC_LOADING_abx = 0U;

  /* MinMax: '<S413>/Max' */
  if (test3_B.Probe_iz[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_iz[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S418>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S413>/Max'
   *  Product: '<S53>/1//T'
   *  Sum: '<S53>/Sum1'
   */
  test3_DW.Integrator_DSTATE_gx += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[56] - test3_DW.Integrator_DSTATE_gx) * 0.01F;
  if (test3_DW.Integrator_DSTATE_gx >= 6.0F) {
    test3_DW.Integrator_DSTATE_gx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_gx <= 0.0F) {
    test3_DW.Integrator_DSTATE_gx = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_dzx = (int16_T)test3_B.Compare_m;

  /* Update for DiscreteIntegrator: '<S424>/Integrator' */
  test3_DW.Integrator_IC_LOADING_cy = 0U;

  /* MinMax: '<S419>/Max' */
  if (test3_B.Probe_lv[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_lv[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S424>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S419>/Max'
   *  Product: '<S54>/1//T'
   *  Sum: '<S54>/Sum1'
   */
  test3_DW.Integrator_DSTATE_nu += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[57] - test3_DW.Integrator_DSTATE_nu) * 0.01F;
  if (test3_DW.Integrator_DSTATE_nu >= 6.0F) {
    test3_DW.Integrator_DSTATE_nu = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_nu <= 0.0F) {
    test3_DW.Integrator_DSTATE_nu = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_m5 = (int16_T)test3_B.Compare_ac;

  /* Update for DiscreteIntegrator: '<S430>/Integrator' */
  test3_DW.Integrator_IC_LOADING_b2 = 0U;

  /* MinMax: '<S425>/Max' */
  if (test3_B.Probe_ms[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ms[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S430>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S425>/Max'
   *  Product: '<S55>/1//T'
   *  Sum: '<S55>/Sum1'
   */
  test3_DW.Integrator_DSTATE_az += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[58] - test3_DW.Integrator_DSTATE_az) * 0.01F;
  if (test3_DW.Integrator_DSTATE_az >= 6.0F) {
    test3_DW.Integrator_DSTATE_az = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_az <= 0.0F) {
    test3_DW.Integrator_DSTATE_az = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_nv = (int16_T)test3_B.Compare_bo;

  /* Update for DiscreteIntegrator: '<S442>/Integrator' */
  test3_DW.Integrator_IC_LOADING_br = 0U;

  /* MinMax: '<S437>/Max' */
  if (test3_B.Probe_it[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_it[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S442>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S437>/Max'
   *  Product: '<S57>/1//T'
   *  Sum: '<S57>/Sum1'
   */
  test3_DW.Integrator_DSTATE_kc += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[59] - test3_DW.Integrator_DSTATE_kc) * 0.01F;
  if (test3_DW.Integrator_DSTATE_kc >= 6.0F) {
    test3_DW.Integrator_DSTATE_kc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_kc <= 0.0F) {
    test3_DW.Integrator_DSTATE_kc = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_bw = (int16_T)test3_B.Compare_ng;

  /* Update for DiscreteIntegrator: '<S448>/Integrator' */
  test3_DW.Integrator_IC_LOADING_du = 0U;

  /* MinMax: '<S443>/Max' */
  if (test3_B.Probe_cs[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_cs[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S448>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S443>/Max'
   *  Product: '<S58>/1//T'
   *  Sum: '<S58>/Sum1'
   */
  test3_DW.Integrator_DSTATE_mc += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[60] - test3_DW.Integrator_DSTATE_mc) * 0.01F;
  if (test3_DW.Integrator_DSTATE_mc >= 6.0F) {
    test3_DW.Integrator_DSTATE_mc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_mc <= 0.0F) {
    test3_DW.Integrator_DSTATE_mc = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_m3 = (int16_T)test3_B.Compare_ht;

  /* Update for DiscreteIntegrator: '<S454>/Integrator' */
  test3_DW.Integrator_IC_LOADING_c3 = 0U;

  /* MinMax: '<S449>/Max' */
  if (test3_B.Probe_pa[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_pa[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S454>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S449>/Max'
   *  Product: '<S59>/1//T'
   *  Sum: '<S59>/Sum1'
   */
  test3_DW.Integrator_DSTATE_nm += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[61] - test3_DW.Integrator_DSTATE_nm) * 0.01F;
  if (test3_DW.Integrator_DSTATE_nm >= 6.0F) {
    test3_DW.Integrator_DSTATE_nm = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_nm <= 0.0F) {
    test3_DW.Integrator_DSTATE_nm = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ei = (int16_T)test3_B.Compare_im;

  /* Update for DiscreteIntegrator: '<S460>/Integrator' */
  test3_DW.Integrator_IC_LOADING_lm = 0U;

  /* MinMax: '<S455>/Max' */
  if (test3_B.Probe_oq[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_oq[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S460>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S455>/Max'
   *  Product: '<S60>/1//T'
   *  Sum: '<S60>/Sum1'
   */
  test3_DW.Integrator_DSTATE_po += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[62] - test3_DW.Integrator_DSTATE_po) * 0.01F;
  if (test3_DW.Integrator_DSTATE_po >= 6.0F) {
    test3_DW.Integrator_DSTATE_po = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_po <= 0.0F) {
    test3_DW.Integrator_DSTATE_po = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_o1 = (int16_T)test3_B.Compare_hg;

  /* Update for DiscreteIntegrator: '<S466>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kk = 0U;

  /* MinMax: '<S461>/Max' */
  if (test3_B.Probe_hl[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_hl[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S466>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S461>/Max'
   *  Product: '<S61>/1//T'
   *  Sum: '<S61>/Sum1'
   */
  test3_DW.Integrator_DSTATE_bt += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[63] - test3_DW.Integrator_DSTATE_bt) * 0.01F;
  if (test3_DW.Integrator_DSTATE_bt >= 6.0F) {
    test3_DW.Integrator_DSTATE_bt = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_bt <= 0.0F) {
    test3_DW.Integrator_DSTATE_bt = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_gv = (int16_T)test3_B.Compare_kj;

  /* Update for DiscreteIntegrator: '<S472>/Integrator' */
  test3_DW.Integrator_IC_LOADING_km = 0U;

  /* MinMax: '<S467>/Max' */
  if (test3_B.Probe_hz[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_hz[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S472>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S467>/Max'
   *  Product: '<S62>/1//T'
   *  Sum: '<S62>/Sum1'
   */
  test3_DW.Integrator_DSTATE_jt += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[64] - test3_DW.Integrator_DSTATE_jt) * 0.01F;
  if (test3_DW.Integrator_DSTATE_jt >= 6.0F) {
    test3_DW.Integrator_DSTATE_jt = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_jt <= 0.0F) {
    test3_DW.Integrator_DSTATE_jt = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_hf = (int16_T)test3_B.Compare_id;

  /* Update for DiscreteIntegrator: '<S478>/Integrator' */
  test3_DW.Integrator_IC_LOADING_oex = 0U;

  /* MinMax: '<S473>/Max' */
  if (test3_B.Probe_be[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_be[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S478>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S473>/Max'
   *  Product: '<S63>/1//T'
   *  Sum: '<S63>/Sum1'
   */
  test3_DW.Integrator_DSTATE_dc += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[65] - test3_DW.Integrator_DSTATE_dc) * 0.01F;
  if (test3_DW.Integrator_DSTATE_dc >= 6.0F) {
    test3_DW.Integrator_DSTATE_dc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_dc <= 0.0F) {
    test3_DW.Integrator_DSTATE_dc = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_gs = (int16_T)test3_B.Compare_ff;

  /* Update for DiscreteIntegrator: '<S484>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kp = 0U;

  /* MinMax: '<S479>/Max' */
  if (test3_B.Probe_c2[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_c2[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S484>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S479>/Max'
   *  Product: '<S64>/1//T'
   *  Sum: '<S64>/Sum1'
   */
  test3_DW.Integrator_DSTATE_pb += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[66] - test3_DW.Integrator_DSTATE_pb) * 0.01F;
  if (test3_DW.Integrator_DSTATE_pb >= 6.0F) {
    test3_DW.Integrator_DSTATE_pb = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pb <= 0.0F) {
    test3_DW.Integrator_DSTATE_pb = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fyk = (int16_T)test3_B.Compare_kn;

  /* Update for DiscreteIntegrator: '<S490>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ew = 0U;

  /* MinMax: '<S485>/Max' */
  if (test3_B.Probe_eq[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_eq[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S490>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S485>/Max'
   *  Product: '<S65>/1//T'
   *  Sum: '<S65>/Sum1'
   */
  test3_DW.Integrator_DSTATE_oe += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[67] - test3_DW.Integrator_DSTATE_oe) * 0.01F;
  if (test3_DW.Integrator_DSTATE_oe >= 6.0F) {
    test3_DW.Integrator_DSTATE_oe = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_oe <= 0.0F) {
    test3_DW.Integrator_DSTATE_oe = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_kl = (int16_T)test3_B.Compare_g5;

  /* Update for DiscreteIntegrator: '<S496>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bk = 0U;

  /* MinMax: '<S491>/Max' */
  if (test3_B.Probe_aj[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_aj[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S496>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S491>/Max'
   *  Product: '<S66>/1//T'
   *  Sum: '<S66>/Sum1'
   */
  test3_DW.Integrator_DSTATE_al += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[68] - test3_DW.Integrator_DSTATE_al) * 0.01F;
  if (test3_DW.Integrator_DSTATE_al >= 6.0F) {
    test3_DW.Integrator_DSTATE_al = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_al <= 0.0F) {
    test3_DW.Integrator_DSTATE_al = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_nk = (int16_T)test3_B.Compare_ou;

  /* Update for DiscreteIntegrator: '<S508>/Integrator' */
  test3_DW.Integrator_IC_LOADING_j31 = 0U;

  /* MinMax: '<S503>/Max' */
  if (test3_B.Probe_hs[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_hs[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S508>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S503>/Max'
   *  Product: '<S68>/1//T'
   *  Sum: '<S68>/Sum1'
   */
  test3_DW.Integrator_DSTATE_cx += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[69] - test3_DW.Integrator_DSTATE_cx) * 0.01F;
  if (test3_DW.Integrator_DSTATE_cx >= 6.0F) {
    test3_DW.Integrator_DSTATE_cx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_cx <= 0.0F) {
    test3_DW.Integrator_DSTATE_cx = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ln = (int16_T)test3_B.Compare_eq;

  /* Update for DiscreteIntegrator: '<S514>/Integrator' */
  test3_DW.Integrator_IC_LOADING_mo = 0U;

  /* MinMax: '<S509>/Max' */
  if (test3_B.Probe_kp[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_kp[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S514>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S509>/Max'
   *  Product: '<S69>/1//T'
   *  Sum: '<S69>/Sum1'
   */
  test3_DW.Integrator_DSTATE_cr += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[70] - test3_DW.Integrator_DSTATE_cr) * 0.01F;
  if (test3_DW.Integrator_DSTATE_cr >= 6.0F) {
    test3_DW.Integrator_DSTATE_cr = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_cr <= 0.0F) {
    test3_DW.Integrator_DSTATE_cr = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_oe = (int16_T)test3_B.Compare_l5;

  /* Update for DiscreteIntegrator: '<S520>/Integrator' */
  test3_DW.Integrator_IC_LOADING_abf = 0U;

  /* MinMax: '<S515>/Max' */
  if (test3_B.Probe_jn[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_jn[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S520>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S515>/Max'
   *  Product: '<S70>/1//T'
   *  Sum: '<S70>/Sum1'
   */
  test3_DW.Integrator_DSTATE_p3 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[71] - test3_DW.Integrator_DSTATE_p3) * 0.01F;
  if (test3_DW.Integrator_DSTATE_p3 >= 6.0F) {
    test3_DW.Integrator_DSTATE_p3 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_p3 <= 0.0F) {
    test3_DW.Integrator_DSTATE_p3 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_hu = (int16_T)test3_B.Compare_fs;

  /* Update for DiscreteIntegrator: '<S526>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ho = 0U;

  /* MinMax: '<S521>/Max' */
  if (test3_B.Probe_dh[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_dh[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S526>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S521>/Max'
   *  Product: '<S71>/1//T'
   *  Sum: '<S71>/Sum1'
   */
  test3_DW.Integrator_DSTATE_kv += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[72] - test3_DW.Integrator_DSTATE_kv) * 0.01F;
  if (test3_DW.Integrator_DSTATE_kv >= 6.0F) {
    test3_DW.Integrator_DSTATE_kv = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_kv <= 0.0F) {
    test3_DW.Integrator_DSTATE_kv = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_mr = (int16_T)test3_B.Compare_c;

  /* Update for DiscreteIntegrator: '<S532>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ph = 0U;

  /* MinMax: '<S527>/Max' */
  if (test3_B.Probe_bg[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_bg[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S532>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S527>/Max'
   *  Product: '<S72>/1//T'
   *  Sum: '<S72>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ed += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[73] - test3_DW.Integrator_DSTATE_ed) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ed >= 6.0F) {
    test3_DW.Integrator_DSTATE_ed = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ed <= 0.0F) {
    test3_DW.Integrator_DSTATE_ed = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ec = (int16_T)test3_B.Compare_f3;

  /* Update for DiscreteIntegrator: '<S538>/Integrator' */
  test3_DW.Integrator_IC_LOADING_da = 0U;

  /* MinMax: '<S533>/Max' */
  if (test3_B.Probe_hb[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_hb[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S538>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S533>/Max'
   *  Product: '<S73>/1//T'
   *  Sum: '<S73>/Sum1'
   */
  test3_DW.Integrator_DSTATE_fu += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[74] - test3_DW.Integrator_DSTATE_fu) * 0.01F;
  if (test3_DW.Integrator_DSTATE_fu >= 6.0F) {
    test3_DW.Integrator_DSTATE_fu = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fu <= 0.0F) {
    test3_DW.Integrator_DSTATE_fu = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_bb = (int16_T)test3_B.Compare_lf;

  /* Update for DiscreteIntegrator: '<S544>/Integrator' */
  test3_DW.Integrator_IC_LOADING_cg = 0U;

  /* MinMax: '<S539>/Max' */
  if (test3_B.Probe_gk[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_gk[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S544>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S539>/Max'
   *  Product: '<S74>/1//T'
   *  Sum: '<S74>/Sum1'
   */
  test3_DW.Integrator_DSTATE_he += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[75] - test3_DW.Integrator_DSTATE_he) * 0.01F;
  if (test3_DW.Integrator_DSTATE_he >= 6.0F) {
    test3_DW.Integrator_DSTATE_he = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_he <= 0.0F) {
    test3_DW.Integrator_DSTATE_he = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_n1 = (int16_T)test3_B.Compare_bi;

  /* Update for DiscreteIntegrator: '<S550>/Integrator' */
  test3_DW.Integrator_IC_LOADING_d3 = 0U;

  /* MinMax: '<S545>/Max' */
  if (test3_B.Probe_ny[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ny[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S550>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S545>/Max'
   *  Product: '<S75>/1//T'
   *  Sum: '<S75>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ot += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[76] - test3_DW.Integrator_DSTATE_ot) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ot >= 6.0F) {
    test3_DW.Integrator_DSTATE_ot = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ot <= 0.0F) {
    test3_DW.Integrator_DSTATE_ot = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_iw = (int16_T)test3_B.Compare_bnj;

  /* Update for DiscreteIntegrator: '<S556>/Integrator' */
  test3_DW.Integrator_IC_LOADING_d0 = 0U;

  /* MinMax: '<S551>/Max' */
  if (test3_B.Probe_k0[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_k0[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S556>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S551>/Max'
   *  Product: '<S76>/1//T'
   *  Sum: '<S76>/Sum1'
   */
  test3_DW.Integrator_DSTATE_my += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[77] - test3_DW.Integrator_DSTATE_my) * 0.01F;
  if (test3_DW.Integrator_DSTATE_my >= 6.0F) {
    test3_DW.Integrator_DSTATE_my = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_my <= 0.0F) {
    test3_DW.Integrator_DSTATE_my = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_gg = (int16_T)rtb_Compare_aw;

  /* Update for DiscreteIntegrator: '<S562>/Integrator' */
  test3_DW.Integrator_IC_LOADING_mg = 0U;

  /* MinMax: '<S557>/Max' */
  if (test3_B.Probe_ic[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ic[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S562>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S557>/Max'
   *  Product: '<S77>/1//T'
   *  Sum: '<S77>/Sum1'
   */
  test3_DW.Integrator_DSTATE_lt += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[78] - test3_DW.Integrator_DSTATE_lt) * 0.01F;
  if (test3_DW.Integrator_DSTATE_lt >= 6.0F) {
    test3_DW.Integrator_DSTATE_lt = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_lt <= 0.0F) {
    test3_DW.Integrator_DSTATE_lt = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_lz = (int16_T)rtb_Compare_gz;

  /* Update for DiscreteIntegrator: '<S574>/Integrator' */
  test3_DW.Integrator_IC_LOADING_e3 = 0U;

  /* MinMax: '<S569>/Max' */
  if (test3_B.Probe_lg[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_lg[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S574>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S569>/Max'
   *  Product: '<S79>/1//T'
   *  Sum: '<S79>/Sum1'
   */
  test3_DW.Integrator_DSTATE_pd += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[79] - test3_DW.Integrator_DSTATE_pd) * 0.01F;
  if (test3_DW.Integrator_DSTATE_pd >= 6.0F) {
    test3_DW.Integrator_DSTATE_pd = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pd <= 0.0F) {
    test3_DW.Integrator_DSTATE_pd = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_dkv = (int16_T)rtb_Compare_ms;

  /* Update for DiscreteIntegrator: '<S580>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ns = 0U;

  /* MinMax: '<S575>/Max' */
  if (test3_B.Probe_fh[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_fh[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S580>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S575>/Max'
   *  Product: '<S80>/1//T'
   *  Sum: '<S80>/Sum1'
   */
  test3_DW.Integrator_DSTATE_en += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[80] - test3_DW.Integrator_DSTATE_en) * 0.01F;
  if (test3_DW.Integrator_DSTATE_en >= 6.0F) {
    test3_DW.Integrator_DSTATE_en = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_en <= 0.0F) {
    test3_DW.Integrator_DSTATE_en = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_bq = (int16_T)rtb_Compare_ar;

  /* Update for DiscreteIntegrator: '<S586>/Integrator' */
  test3_DW.Integrator_IC_LOADING_hp = 0U;

  /* MinMax: '<S581>/Max' */
  if (test3_B.Probe_eh[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_eh[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S586>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S581>/Max'
   *  Product: '<S81>/1//T'
   *  Sum: '<S81>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ix += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[81] - test3_DW.Integrator_DSTATE_ix) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ix >= 6.0F) {
    test3_DW.Integrator_DSTATE_ix = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ix <= 0.0F) {
    test3_DW.Integrator_DSTATE_ix = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_pb = (int16_T)rtb_Compare_euj;

  /* Update for DiscreteIntegrator: '<S592>/Integrator' */
  test3_DW.Integrator_IC_LOADING_a0 = 0U;

  /* MinMax: '<S587>/Max' */
  if (test3_B.Probe_nl[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_nl[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S592>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S587>/Max'
   *  Product: '<S82>/1//T'
   *  Sum: '<S82>/Sum1'
   */
  test3_DW.Integrator_DSTATE_hg += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[82] - test3_DW.Integrator_DSTATE_hg) * 0.01F;
  if (test3_DW.Integrator_DSTATE_hg >= 6.0F) {
    test3_DW.Integrator_DSTATE_hg = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_hg <= 0.0F) {
    test3_DW.Integrator_DSTATE_hg = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ew = (int16_T)rtb_Compare_gk;

  /* Update for DiscreteIntegrator: '<S598>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bo = 0U;

  /* MinMax: '<S593>/Max' */
  if (test3_B.Probe_bo[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_bo[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S598>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S593>/Max'
   *  Product: '<S83>/1//T'
   *  Sum: '<S83>/Sum1'
   */
  test3_DW.Integrator_DSTATE_fm += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[83] - test3_DW.Integrator_DSTATE_fm) * 0.01F;
  if (test3_DW.Integrator_DSTATE_fm >= 6.0F) {
    test3_DW.Integrator_DSTATE_fm = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_fm <= 0.0F) {
    test3_DW.Integrator_DSTATE_fm = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_pl = (int16_T)rtb_Compare_lu;

  /* Update for DiscreteIntegrator: '<S604>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kq = 0U;

  /* MinMax: '<S599>/Max' */
  if (test3_B.Probe_kb[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_kb[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S604>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S599>/Max'
   *  Product: '<S84>/1//T'
   *  Sum: '<S84>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ok += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[84] - test3_DW.Integrator_DSTATE_ok) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ok >= 6.0F) {
    test3_DW.Integrator_DSTATE_ok = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ok <= 0.0F) {
    test3_DW.Integrator_DSTATE_ok = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_mu = (int16_T)rtb_Compare_gb;

  /* Update for DiscreteIntegrator: '<S610>/Integrator' */
  test3_DW.Integrator_IC_LOADING_h2 = 0U;

  /* MinMax: '<S605>/Max' */
  if (test3_B.Probe_l3[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_l3[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S610>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S605>/Max'
   *  Product: '<S85>/1//T'
   *  Sum: '<S85>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ns += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[85] - test3_DW.Integrator_DSTATE_ns) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ns >= 6.0F) {
    test3_DW.Integrator_DSTATE_ns = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ns <= 0.0F) {
    test3_DW.Integrator_DSTATE_ns = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_e4 = (int16_T)rtb_Compare_b4;

  /* Update for DiscreteIntegrator: '<S616>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kkm = 0U;

  /* MinMax: '<S611>/Max' */
  if (test3_B.Probe_j0n[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_j0n[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S616>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S611>/Max'
   *  Product: '<S86>/1//T'
   *  Sum: '<S86>/Sum1'
   */
  test3_DW.Integrator_DSTATE_ga += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[86] - test3_DW.Integrator_DSTATE_ga) * 0.01F;
  if (test3_DW.Integrator_DSTATE_ga >= 6.0F) {
    test3_DW.Integrator_DSTATE_ga = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_ga <= 0.0F) {
    test3_DW.Integrator_DSTATE_ga = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_jl = (int16_T)rtb_Compare_l0;

  /* Update for DiscreteIntegrator: '<S622>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bz = 0U;

  /* MinMax: '<S617>/Max' */
  if (test3_B.Probe_pu[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_pu[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S622>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S617>/Max'
   *  Product: '<S87>/1//T'
   *  Sum: '<S87>/Sum1'
   */
  test3_DW.Integrator_DSTATE_dsn += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[87] - test3_DW.Integrator_DSTATE_dsn) * 0.01F;
  if (test3_DW.Integrator_DSTATE_dsn >= 6.0F) {
    test3_DW.Integrator_DSTATE_dsn = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_dsn <= 0.0F) {
    test3_DW.Integrator_DSTATE_dsn = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_cx = (int16_T)rtb_Compare_da;

  /* Update for DiscreteIntegrator: '<S628>/Integrator' */
  test3_DW.Integrator_IC_LOADING_o1 = 0U;

  /* MinMax: '<S623>/Max' */
  if (test3_B.Probe_jw[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_jw[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S628>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S623>/Max'
   *  Product: '<S88>/1//T'
   *  Sum: '<S88>/Sum1'
   */
  test3_DW.Integrator_DSTATE_pc += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[88] - test3_DW.Integrator_DSTATE_pc) * 0.01F;
  if (test3_DW.Integrator_DSTATE_pc >= 6.0F) {
    test3_DW.Integrator_DSTATE_pc = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_pc <= 0.0F) {
    test3_DW.Integrator_DSTATE_pc = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_mm = (int16_T)rtb_Compare_cm;

  /* Update for DiscreteIntegrator: '<S640>/Integrator' */
  test3_DW.Integrator_IC_LOADING_fcd = 0U;

  /* MinMax: '<S635>/Max' */
  if (test3_B.Probe_g2[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_g2[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S640>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S635>/Max'
   *  Product: '<S90>/1//T'
   *  Sum: '<S90>/Sum1'
   */
  test3_DW.Integrator_DSTATE_eg += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[89] - test3_DW.Integrator_DSTATE_eg) * 0.01F;
  if (test3_DW.Integrator_DSTATE_eg >= 6.0F) {
    test3_DW.Integrator_DSTATE_eg = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_eg <= 0.0F) {
    test3_DW.Integrator_DSTATE_eg = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_pg = (int16_T)rtb_Compare_et;

  /* Update for DiscreteIntegrator: '<S646>/Integrator' */
  test3_DW.Integrator_IC_LOADING_bp = 0U;

  /* MinMax: '<S641>/Max' */
  if (test3_B.Probe_opc[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_opc[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S646>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S641>/Max'
   *  Product: '<S91>/1//T'
   *  Sum: '<S91>/Sum1'
   */
  test3_DW.Integrator_DSTATE_jx += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[90] - test3_DW.Integrator_DSTATE_jx) * 0.01F;
  if (test3_DW.Integrator_DSTATE_jx >= 6.0F) {
    test3_DW.Integrator_DSTATE_jx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_jx <= 0.0F) {
    test3_DW.Integrator_DSTATE_jx = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_md = (int16_T)rtb_Compare_eo;

  /* Update for DiscreteIntegrator: '<S652>/Integrator' */
  test3_DW.Integrator_IC_LOADING_ad = 0U;

  /* MinMax: '<S647>/Max' */
  if (test3_B.Probe_lf[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_lf[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S652>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S647>/Max'
   *  Product: '<S92>/1//T'
   *  Sum: '<S92>/Sum1'
   */
  test3_DW.Integrator_DSTATE_im += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[91] - test3_DW.Integrator_DSTATE_im) * 0.01F;
  if (test3_DW.Integrator_DSTATE_im >= 6.0F) {
    test3_DW.Integrator_DSTATE_im = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_im <= 0.0F) {
    test3_DW.Integrator_DSTATE_im = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_bf = (int16_T)rtb_Compare_pd;

  /* Update for DiscreteIntegrator: '<S658>/Integrator' */
  test3_DW.Integrator_IC_LOADING_kv = 0U;

  /* MinMax: '<S653>/Max' */
  if (test3_B.Probe_m5[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_m5[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S658>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S653>/Max'
   *  Product: '<S93>/1//T'
   *  Sum: '<S93>/Sum1'
   */
  test3_DW.Integrator_DSTATE_hp += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[92] - test3_DW.Integrator_DSTATE_hp) * 0.01F;
  if (test3_DW.Integrator_DSTATE_hp >= 6.0F) {
    test3_DW.Integrator_DSTATE_hp = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_hp <= 0.0F) {
    test3_DW.Integrator_DSTATE_hp = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_fam = (int16_T)rtb_Compare_is;

  /* Update for DiscreteIntegrator: '<S664>/Integrator' */
  test3_DW.Integrator_IC_LOADING_h20 = 0U;

  /* MinMax: '<S659>/Max' */
  if (test3_B.Probe_da[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_da[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S664>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S659>/Max'
   *  Product: '<S94>/1//T'
   *  Sum: '<S94>/Sum1'
   */
  test3_DW.Integrator_DSTATE_aq += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[93] - test3_DW.Integrator_DSTATE_aq) * 0.01F;
  if (test3_DW.Integrator_DSTATE_aq >= 6.0F) {
    test3_DW.Integrator_DSTATE_aq = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_aq <= 0.0F) {
    test3_DW.Integrator_DSTATE_aq = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_g2 = (int16_T)rtb_Compare_ee;

  /* Update for DiscreteIntegrator: '<S670>/Integrator' */
  test3_DW.Integrator_IC_LOADING_d04 = 0U;

  /* MinMax: '<S665>/Max' */
  if (test3_B.Probe_he[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_he[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S670>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S665>/Max'
   *  Product: '<S95>/1//T'
   *  Sum: '<S95>/Sum1'
   */
  test3_DW.Integrator_DSTATE_lx += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[94] - test3_DW.Integrator_DSTATE_lx) * 0.01F;
  if (test3_DW.Integrator_DSTATE_lx >= 6.0F) {
    test3_DW.Integrator_DSTATE_lx = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_lx <= 0.0F) {
    test3_DW.Integrator_DSTATE_lx = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_ou = (int16_T)rtb_Compare_mpz;

  /* Update for DiscreteIntegrator: '<S676>/Integrator' */
  test3_DW.Integrator_IC_LOADING_jn = 0U;

  /* MinMax: '<S671>/Max' */
  if (test3_B.Probe_ak[0] >= 0.031830988618379068) {
    test3_B.d = test3_B.Probe_ak[0];
  } else {
    test3_B.d = 0.031830988618379068;
  }

  /* Update for DiscreteIntegrator: '<S676>/Integrator' incorporates:
   *  Inport: '<Root>/CellVoltages'
   *  MinMax: '<S671>/Max'
   *  Product: '<S96>/1//T'
   *  Sum: '<S96>/Sum1'
   */
  test3_DW.Integrator_DSTATE_l5 += 1.0F / (real32_T)test3_B.d *
    (test3_U.CellVoltages[95] - test3_DW.Integrator_DSTATE_l5) * 0.01F;
  if (test3_DW.Integrator_DSTATE_l5 >= 6.0F) {
    test3_DW.Integrator_DSTATE_l5 = 6.0F;
  } else if (test3_DW.Integrator_DSTATE_l5 <= 0.0F) {
    test3_DW.Integrator_DSTATE_l5 = 0.0F;
  }

  test3_DW.Integrator_PrevResetState_k5 = (int16_T)rtb_Compare_ne;
}

/* Model initialize function */
void test3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test3_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &test3_B), 0,
                sizeof(B_test3_T));

  /* states (dwork) */
  (void) memset((void *)&test3_DW, 0,
                sizeof(DW_test3_T));

  {
    g_dsp_internal_SlidingWindo_k_T *iobj_0;
    int16_T i;

    /* Start for Probe: '<S101>/Probe' */
    test3_B.Probe[0] = 0.01F;
    test3_B.Probe[1] = 0.0F;

    /* Start for Probe: '<S167>/Probe' */
    test3_B.Probe_l[0] = 0.01F;
    test3_B.Probe_l[1] = 0.0F;

    /* Start for Probe: '<S233>/Probe' */
    test3_B.Probe_i[0] = 0.01F;
    test3_B.Probe_i[1] = 0.0F;

    /* Start for Probe: '<S299>/Probe' */
    test3_B.Probe_o[0] = 0.01F;
    test3_B.Probe_o[1] = 0.0F;

    /* Start for Probe: '<S365>/Probe' */
    test3_B.Probe_ii[0] = 0.01F;
    test3_B.Probe_ii[1] = 0.0F;

    /* Start for Probe: '<S431>/Probe' */
    test3_B.Probe_e[0] = 0.01F;
    test3_B.Probe_e[1] = 0.0F;

    /* Start for Probe: '<S497>/Probe' */
    test3_B.Probe_n[0] = 0.01F;
    test3_B.Probe_n[1] = 0.0F;

    /* Start for Probe: '<S563>/Probe' */
    test3_B.Probe_ng[0] = 0.01F;
    test3_B.Probe_ng[1] = 0.0F;

    /* Start for Probe: '<S629>/Probe' */
    test3_B.Probe_no[0] = 0.01F;
    test3_B.Probe_no[1] = 0.0F;

    /* Start for Probe: '<S107>/Probe' */
    test3_B.Probe_b[0] = 0.01F;
    test3_B.Probe_b[1] = 0.0F;

    /* Start for Probe: '<S113>/Probe' */
    test3_B.Probe_j[0] = 0.01F;
    test3_B.Probe_j[1] = 0.0F;

    /* Start for Probe: '<S119>/Probe' */
    test3_B.Probe_os[0] = 0.01F;
    test3_B.Probe_os[1] = 0.0F;

    /* Start for Probe: '<S125>/Probe' */
    test3_B.Probe_m[0] = 0.01F;
    test3_B.Probe_m[1] = 0.0F;

    /* Start for Probe: '<S131>/Probe' */
    test3_B.Probe_c[0] = 0.01F;
    test3_B.Probe_c[1] = 0.0F;

    /* Start for Probe: '<S137>/Probe' */
    test3_B.Probe_lt[0] = 0.01F;
    test3_B.Probe_lt[1] = 0.0F;

    /* Start for Probe: '<S143>/Probe' */
    test3_B.Probe_ik[0] = 0.01F;
    test3_B.Probe_ik[1] = 0.0F;

    /* Start for Probe: '<S149>/Probe' */
    test3_B.Probe_ct[0] = 0.01F;
    test3_B.Probe_ct[1] = 0.0F;

    /* Start for Probe: '<S155>/Probe' */
    test3_B.Probe_f[0] = 0.01F;
    test3_B.Probe_f[1] = 0.0F;

    /* Start for Probe: '<S161>/Probe' */
    test3_B.Probe_fp[0] = 0.01F;
    test3_B.Probe_fp[1] = 0.0F;

    /* Start for Probe: '<S173>/Probe' */
    test3_B.Probe_g[0] = 0.01F;
    test3_B.Probe_g[1] = 0.0F;

    /* Start for Probe: '<S179>/Probe' */
    test3_B.Probe_h[0] = 0.01F;
    test3_B.Probe_h[1] = 0.0F;

    /* Start for Probe: '<S185>/Probe' */
    test3_B.Probe_o4[0] = 0.01F;
    test3_B.Probe_o4[1] = 0.0F;

    /* Start for Probe: '<S191>/Probe' */
    test3_B.Probe_fc[0] = 0.01F;
    test3_B.Probe_fc[1] = 0.0F;

    /* Start for Probe: '<S197>/Probe' */
    test3_B.Probe_f1[0] = 0.01F;
    test3_B.Probe_f1[1] = 0.0F;

    /* Start for Probe: '<S203>/Probe' */
    test3_B.Probe_bf[0] = 0.01F;
    test3_B.Probe_bf[1] = 0.0F;

    /* Start for Probe: '<S209>/Probe' */
    test3_B.Probe_gu[0] = 0.01F;
    test3_B.Probe_gu[1] = 0.0F;

    /* Start for Probe: '<S215>/Probe' */
    test3_B.Probe_er[0] = 0.01F;
    test3_B.Probe_er[1] = 0.0F;

    /* Start for Probe: '<S221>/Probe' */
    test3_B.Probe_hq[0] = 0.01F;
    test3_B.Probe_hq[1] = 0.0F;

    /* Start for Probe: '<S227>/Probe' */
    test3_B.Probe_md[0] = 0.01F;
    test3_B.Probe_md[1] = 0.0F;

    /* Start for Probe: '<S239>/Probe' */
    test3_B.Probe_p[0] = 0.01F;
    test3_B.Probe_p[1] = 0.0F;

    /* Start for Probe: '<S245>/Probe' */
    test3_B.Probe_pe[0] = 0.01F;
    test3_B.Probe_pe[1] = 0.0F;

    /* Start for Probe: '<S251>/Probe' */
    test3_B.Probe_gb[0] = 0.01F;
    test3_B.Probe_gb[1] = 0.0F;

    /* Start for Probe: '<S257>/Probe' */
    test3_B.Probe_gs[0] = 0.01F;
    test3_B.Probe_gs[1] = 0.0F;

    /* Start for Probe: '<S263>/Probe' */
    test3_B.Probe_p1[0] = 0.01F;
    test3_B.Probe_p1[1] = 0.0F;

    /* Start for Probe: '<S269>/Probe' */
    test3_B.Probe_j0[0] = 0.01F;
    test3_B.Probe_j0[1] = 0.0F;

    /* Start for Probe: '<S275>/Probe' */
    test3_B.Probe_ib[0] = 0.01F;
    test3_B.Probe_ib[1] = 0.0F;

    /* Start for Probe: '<S281>/Probe' */
    test3_B.Probe_nm[0] = 0.01F;
    test3_B.Probe_nm[1] = 0.0F;

    /* Start for Probe: '<S287>/Probe' */
    test3_B.Probe_hh[0] = 0.01F;
    test3_B.Probe_hh[1] = 0.0F;

    /* Start for Probe: '<S293>/Probe' */
    test3_B.Probe_d[0] = 0.01F;
    test3_B.Probe_d[1] = 0.0F;

    /* Start for Probe: '<S305>/Probe' */
    test3_B.Probe_fv[0] = 0.01F;
    test3_B.Probe_fv[1] = 0.0F;

    /* Start for Probe: '<S311>/Probe' */
    test3_B.Probe_ij[0] = 0.01F;
    test3_B.Probe_ij[1] = 0.0F;

    /* Start for Probe: '<S317>/Probe' */
    test3_B.Probe_pk[0] = 0.01F;
    test3_B.Probe_pk[1] = 0.0F;

    /* Start for Probe: '<S323>/Probe' */
    test3_B.Probe_a[0] = 0.01F;
    test3_B.Probe_a[1] = 0.0F;

    /* Start for Probe: '<S329>/Probe' */
    test3_B.Probe_fpu[0] = 0.01F;
    test3_B.Probe_fpu[1] = 0.0F;

    /* Start for Probe: '<S335>/Probe' */
    test3_B.Probe_m0[0] = 0.01F;
    test3_B.Probe_m0[1] = 0.0F;

    /* Start for Probe: '<S341>/Probe' */
    test3_B.Probe_mt[0] = 0.01F;
    test3_B.Probe_mt[1] = 0.0F;

    /* Start for Probe: '<S347>/Probe' */
    test3_B.Probe_fn[0] = 0.01F;
    test3_B.Probe_fn[1] = 0.0F;

    /* Start for Probe: '<S353>/Probe' */
    test3_B.Probe_op[0] = 0.01F;
    test3_B.Probe_op[1] = 0.0F;

    /* Start for Probe: '<S359>/Probe' */
    test3_B.Probe_k[0] = 0.01F;
    test3_B.Probe_k[1] = 0.0F;

    /* Start for Probe: '<S371>/Probe' */
    test3_B.Probe_ll[0] = 0.01F;
    test3_B.Probe_ll[1] = 0.0F;

    /* Start for Probe: '<S377>/Probe' */
    test3_B.Probe_dm[0] = 0.01F;
    test3_B.Probe_dm[1] = 0.0F;

    /* Start for Probe: '<S383>/Probe' */
    test3_B.Probe_ba[0] = 0.01F;
    test3_B.Probe_ba[1] = 0.0F;

    /* Start for Probe: '<S389>/Probe' */
    test3_B.Probe_j0k[0] = 0.01F;
    test3_B.Probe_j0k[1] = 0.0F;

    /* Start for Probe: '<S395>/Probe' */
    test3_B.Probe_gj[0] = 0.01F;
    test3_B.Probe_gj[1] = 0.0F;

    /* Start for Probe: '<S401>/Probe' */
    test3_B.Probe_po[0] = 0.01F;
    test3_B.Probe_po[1] = 0.0F;

    /* Start for Probe: '<S407>/Probe' */
    test3_B.Probe_f2[0] = 0.01F;
    test3_B.Probe_f2[1] = 0.0F;

    /* Start for Probe: '<S413>/Probe' */
    test3_B.Probe_iz[0] = 0.01F;
    test3_B.Probe_iz[1] = 0.0F;

    /* Start for Probe: '<S419>/Probe' */
    test3_B.Probe_lv[0] = 0.01F;
    test3_B.Probe_lv[1] = 0.0F;

    /* Start for Probe: '<S425>/Probe' */
    test3_B.Probe_ms[0] = 0.01F;
    test3_B.Probe_ms[1] = 0.0F;

    /* Start for Probe: '<S437>/Probe' */
    test3_B.Probe_it[0] = 0.01F;
    test3_B.Probe_it[1] = 0.0F;

    /* Start for Probe: '<S443>/Probe' */
    test3_B.Probe_cs[0] = 0.01F;
    test3_B.Probe_cs[1] = 0.0F;

    /* Start for Probe: '<S449>/Probe' */
    test3_B.Probe_pa[0] = 0.01F;
    test3_B.Probe_pa[1] = 0.0F;

    /* Start for Probe: '<S455>/Probe' */
    test3_B.Probe_oq[0] = 0.01F;
    test3_B.Probe_oq[1] = 0.0F;

    /* Start for Probe: '<S461>/Probe' */
    test3_B.Probe_hl[0] = 0.01F;
    test3_B.Probe_hl[1] = 0.0F;

    /* Start for Probe: '<S467>/Probe' */
    test3_B.Probe_hz[0] = 0.01F;
    test3_B.Probe_hz[1] = 0.0F;

    /* Start for Probe: '<S473>/Probe' */
    test3_B.Probe_be[0] = 0.01F;
    test3_B.Probe_be[1] = 0.0F;

    /* Start for Probe: '<S479>/Probe' */
    test3_B.Probe_c2[0] = 0.01F;
    test3_B.Probe_c2[1] = 0.0F;

    /* Start for Probe: '<S485>/Probe' */
    test3_B.Probe_eq[0] = 0.01F;
    test3_B.Probe_eq[1] = 0.0F;

    /* Start for Probe: '<S491>/Probe' */
    test3_B.Probe_aj[0] = 0.01F;
    test3_B.Probe_aj[1] = 0.0F;

    /* Start for Probe: '<S503>/Probe' */
    test3_B.Probe_hs[0] = 0.01F;
    test3_B.Probe_hs[1] = 0.0F;

    /* Start for Probe: '<S509>/Probe' */
    test3_B.Probe_kp[0] = 0.01F;
    test3_B.Probe_kp[1] = 0.0F;

    /* Start for Probe: '<S515>/Probe' */
    test3_B.Probe_jn[0] = 0.01F;
    test3_B.Probe_jn[1] = 0.0F;

    /* Start for Probe: '<S521>/Probe' */
    test3_B.Probe_dh[0] = 0.01F;
    test3_B.Probe_dh[1] = 0.0F;

    /* Start for Probe: '<S527>/Probe' */
    test3_B.Probe_bg[0] = 0.01F;
    test3_B.Probe_bg[1] = 0.0F;

    /* Start for Probe: '<S533>/Probe' */
    test3_B.Probe_hb[0] = 0.01F;
    test3_B.Probe_hb[1] = 0.0F;

    /* Start for Probe: '<S539>/Probe' */
    test3_B.Probe_gk[0] = 0.01F;
    test3_B.Probe_gk[1] = 0.0F;

    /* Start for Probe: '<S545>/Probe' */
    test3_B.Probe_ny[0] = 0.01F;
    test3_B.Probe_ny[1] = 0.0F;

    /* Start for Probe: '<S551>/Probe' */
    test3_B.Probe_k0[0] = 0.01F;
    test3_B.Probe_k0[1] = 0.0F;

    /* Start for Probe: '<S557>/Probe' */
    test3_B.Probe_ic[0] = 0.01F;
    test3_B.Probe_ic[1] = 0.0F;

    /* Start for Probe: '<S569>/Probe' */
    test3_B.Probe_lg[0] = 0.01F;
    test3_B.Probe_lg[1] = 0.0F;

    /* Start for Probe: '<S575>/Probe' */
    test3_B.Probe_fh[0] = 0.01F;
    test3_B.Probe_fh[1] = 0.0F;

    /* Start for Probe: '<S581>/Probe' */
    test3_B.Probe_eh[0] = 0.01F;
    test3_B.Probe_eh[1] = 0.0F;

    /* Start for Probe: '<S587>/Probe' */
    test3_B.Probe_nl[0] = 0.01F;
    test3_B.Probe_nl[1] = 0.0F;

    /* Start for Probe: '<S593>/Probe' */
    test3_B.Probe_bo[0] = 0.01F;
    test3_B.Probe_bo[1] = 0.0F;

    /* Start for Probe: '<S599>/Probe' */
    test3_B.Probe_kb[0] = 0.01F;
    test3_B.Probe_kb[1] = 0.0F;

    /* Start for Probe: '<S605>/Probe' */
    test3_B.Probe_l3[0] = 0.01F;
    test3_B.Probe_l3[1] = 0.0F;

    /* Start for Probe: '<S611>/Probe' */
    test3_B.Probe_j0n[0] = 0.01F;
    test3_B.Probe_j0n[1] = 0.0F;

    /* Start for Probe: '<S617>/Probe' */
    test3_B.Probe_pu[0] = 0.01F;
    test3_B.Probe_pu[1] = 0.0F;

    /* Start for Probe: '<S623>/Probe' */
    test3_B.Probe_jw[0] = 0.01F;
    test3_B.Probe_jw[1] = 0.0F;

    /* Start for Probe: '<S635>/Probe' */
    test3_B.Probe_g2[0] = 0.01F;
    test3_B.Probe_g2[1] = 0.0F;

    /* Start for Probe: '<S641>/Probe' */
    test3_B.Probe_opc[0] = 0.01F;
    test3_B.Probe_opc[1] = 0.0F;

    /* Start for Probe: '<S647>/Probe' */
    test3_B.Probe_lf[0] = 0.01F;
    test3_B.Probe_lf[1] = 0.0F;

    /* Start for Probe: '<S653>/Probe' */
    test3_B.Probe_m5[0] = 0.01F;
    test3_B.Probe_m5[1] = 0.0F;

    /* Start for Probe: '<S659>/Probe' */
    test3_B.Probe_da[0] = 0.01F;
    test3_B.Probe_da[1] = 0.0F;

    /* Start for Probe: '<S665>/Probe' */
    test3_B.Probe_he[0] = 0.01F;
    test3_B.Probe_he[1] = 0.0F;

    /* Start for Probe: '<S671>/Probe' */
    test3_B.Probe_ak[0] = 0.01F;
    test3_B.Probe_ak[1] = 0.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator' */
    test3_DW.Integrator_PrevResetState = 0;
    test3_DW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S172>/Integrator' */
    test3_DW.Integrator_PrevResetState_p = 0;
    test3_DW.Integrator_IC_LOADING_p = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S238>/Integrator' */
    test3_DW.Integrator_PrevResetState_o = 0;
    test3_DW.Integrator_IC_LOADING_g = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S304>/Integrator' */
    test3_DW.Integrator_PrevResetState_e = 0;
    test3_DW.Integrator_IC_LOADING_j = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator' */
    test3_DW.Integrator_PrevResetState_oy = 0;
    test3_DW.Integrator_IC_LOADING_h = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S436>/Integrator' */
    test3_DW.Integrator_PrevResetState_c = 0;
    test3_DW.Integrator_IC_LOADING_k = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator' */
    test3_DW.Integrator_PrevResetState_a = 0;
    test3_DW.Integrator_IC_LOADING_o = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S568>/Integrator' */
    test3_DW.Integrator_PrevResetState_ch = 0;
    test3_DW.Integrator_IC_LOADING_g2 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S634>/Integrator' */
    test3_DW.Integrator_PrevResetState_h = 0;
    test3_DW.Integrator_IC_LOADING_d = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Integrator' */
    test3_DW.Integrator_PrevResetState_i = 0;
    test3_DW.Integrator_IC_LOADING_pv = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S118>/Integrator' */
    test3_DW.Integrator_PrevResetState_iy = 0;
    test3_DW.Integrator_IC_LOADING_m = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
    test3_DW.Integrator_PrevResetState_g = 0;
    test3_DW.Integrator_IC_LOADING_hr = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S130>/Integrator' */
    test3_DW.Integrator_PrevResetState_f = 0;
    test3_DW.Integrator_IC_LOADING_i = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
    test3_DW.Integrator_PrevResetState_fi = 0;
    test3_DW.Integrator_IC_LOADING_e = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
    test3_DW.Integrator_PrevResetState_fm = 0;
    test3_DW.Integrator_IC_LOADING_df = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S148>/Integrator' */
    test3_DW.Integrator_PrevResetState_gh = 0;
    test3_DW.Integrator_IC_LOADING_ip = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
    test3_DW.Integrator_PrevResetState_b = 0;
    test3_DW.Integrator_IC_LOADING_a = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S160>/Integrator' */
    test3_DW.Integrator_PrevResetState_bl = 0;
    test3_DW.Integrator_IC_LOADING_ic = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S166>/Integrator' */
    test3_DW.Integrator_PrevResetState_fie = 0;
    test3_DW.Integrator_IC_LOADING_ab = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S178>/Integrator' */
    test3_DW.Integrator_PrevResetState_d = 0;
    test3_DW.Integrator_IC_LOADING_oe = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S184>/Integrator' */
    test3_DW.Integrator_PrevResetState_k = 0;
    test3_DW.Integrator_IC_LOADING_op = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S190>/Integrator' */
    test3_DW.Integrator_PrevResetState_n = 0;
    test3_DW.Integrator_IC_LOADING_hg = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S196>/Integrator' */
    test3_DW.Integrator_PrevResetState_fz = 0;
    test3_DW.Integrator_IC_LOADING_l = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator' */
    test3_DW.Integrator_PrevResetState_m = 0;
    test3_DW.Integrator_IC_LOADING_iw = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S208>/Integrator' */
    test3_DW.Integrator_PrevResetState_hi = 0;
    test3_DW.Integrator_IC_LOADING_ky = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S214>/Integrator' */
    test3_DW.Integrator_PrevResetState_fy = 0;
    test3_DW.Integrator_IC_LOADING_b = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S220>/Integrator' */
    test3_DW.Integrator_PrevResetState_ok = 0;
    test3_DW.Integrator_IC_LOADING_gu = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S226>/Integrator' */
    test3_DW.Integrator_PrevResetState_j = 0;
    test3_DW.Integrator_IC_LOADING_ao = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S232>/Integrator' */
    test3_DW.Integrator_PrevResetState_dh = 0;
    test3_DW.Integrator_IC_LOADING_f = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S244>/Integrator' */
    test3_DW.Integrator_PrevResetState_ne = 0;
    test3_DW.Integrator_IC_LOADING_c = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S250>/Integrator' */
    test3_DW.Integrator_PrevResetState_fl = 0;
    test3_DW.Integrator_IC_LOADING_fc = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S256>/Integrator' */
    test3_DW.Integrator_PrevResetState_ib = 0;
    test3_DW.Integrator_IC_LOADING_bd = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S262>/Integrator' */
    test3_DW.Integrator_PrevResetState_dz = 0;
    test3_DW.Integrator_IC_LOADING_n = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S268>/Integrator' */
    test3_DW.Integrator_PrevResetState_l = 0;
    test3_DW.Integrator_IC_LOADING_aoc = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S274>/Integrator' */
    test3_DW.Integrator_PrevResetState_hm = 0;
    test3_DW.Integrator_IC_LOADING_kr = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S280>/Integrator' */
    test3_DW.Integrator_PrevResetState_lo = 0;
    test3_DW.Integrator_IC_LOADING_n3 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S286>/Integrator' */
    test3_DW.Integrator_PrevResetState_dk = 0;
    test3_DW.Integrator_IC_LOADING_pe = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S292>/Integrator' */
    test3_DW.Integrator_PrevResetState_es = 0;
    test3_DW.Integrator_IC_LOADING_gb = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator' */
    test3_DW.Integrator_PrevResetState_fu = 0;
    test3_DW.Integrator_IC_LOADING_gg = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S310>/Integrator' */
    test3_DW.Integrator_PrevResetState_cv = 0;
    test3_DW.Integrator_IC_LOADING_bb = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S316>/Integrator' */
    test3_DW.Integrator_PrevResetState_ke = 0;
    test3_DW.Integrator_IC_LOADING_p4 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S322>/Integrator' */
    test3_DW.Integrator_PrevResetState_fa = 0;
    test3_DW.Integrator_IC_LOADING_mv = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S328>/Integrator' */
    test3_DW.Integrator_PrevResetState_h4 = 0;
    test3_DW.Integrator_IC_LOADING_j1 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S334>/Integrator' */
    test3_DW.Integrator_PrevResetState_io = 0;
    test3_DW.Integrator_IC_LOADING_az = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S340>/Integrator' */
    test3_DW.Integrator_PrevResetState_k3 = 0;
    test3_DW.Integrator_IC_LOADING_bm = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S346>/Integrator' */
    test3_DW.Integrator_PrevResetState_ed = 0;
    test3_DW.Integrator_IC_LOADING_c0 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S352>/Integrator' */
    test3_DW.Integrator_PrevResetState_on = 0;
    test3_DW.Integrator_IC_LOADING_p0 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S358>/Integrator' */
    test3_DW.Integrator_PrevResetState_cb = 0;
    test3_DW.Integrator_IC_LOADING_j3 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S364>/Integrator' */
    test3_DW.Integrator_PrevResetState_fj = 0;
    test3_DW.Integrator_IC_LOADING_hf = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator' */
    test3_DW.Integrator_PrevResetState_kk = 0;
    test3_DW.Integrator_IC_LOADING_ms = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
    test3_DW.Integrator_PrevResetState_ie = 0;
    test3_DW.Integrator_IC_LOADING_me = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator' */
    test3_DW.Integrator_PrevResetState_pp = 0;
    test3_DW.Integrator_IC_LOADING_oq = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S394>/Integrator' */
    test3_DW.Integrator_PrevResetState_ox = 0;
    test3_DW.Integrator_IC_LOADING_kz = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S400>/Integrator' */
    test3_DW.Integrator_PrevResetState_fn = 0;
    test3_DW.Integrator_IC_LOADING_b1 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S406>/Integrator' */
    test3_DW.Integrator_PrevResetState_mk = 0;
    test3_DW.Integrator_IC_LOADING_j3b = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator' */
    test3_DW.Integrator_PrevResetState_m1 = 0;
    test3_DW.Integrator_IC_LOADING_ar = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S418>/Integrator' */
    test3_DW.Integrator_PrevResetState_dzx = 0;
    test3_DW.Integrator_IC_LOADING_abx = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S424>/Integrator' */
    test3_DW.Integrator_PrevResetState_m5 = 0;
    test3_DW.Integrator_IC_LOADING_cy = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S430>/Integrator' */
    test3_DW.Integrator_PrevResetState_nv = 0;
    test3_DW.Integrator_IC_LOADING_b2 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S442>/Integrator' */
    test3_DW.Integrator_PrevResetState_bw = 0;
    test3_DW.Integrator_IC_LOADING_br = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S448>/Integrator' */
    test3_DW.Integrator_PrevResetState_m3 = 0;
    test3_DW.Integrator_IC_LOADING_du = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S454>/Integrator' */
    test3_DW.Integrator_PrevResetState_ei = 0;
    test3_DW.Integrator_IC_LOADING_c3 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S460>/Integrator' */
    test3_DW.Integrator_PrevResetState_o1 = 0;
    test3_DW.Integrator_IC_LOADING_lm = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator' */
    test3_DW.Integrator_PrevResetState_gv = 0;
    test3_DW.Integrator_IC_LOADING_kk = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S472>/Integrator' */
    test3_DW.Integrator_PrevResetState_hf = 0;
    test3_DW.Integrator_IC_LOADING_km = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S478>/Integrator' */
    test3_DW.Integrator_PrevResetState_gs = 0;
    test3_DW.Integrator_IC_LOADING_oex = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S484>/Integrator' */
    test3_DW.Integrator_PrevResetState_fyk = 0;
    test3_DW.Integrator_IC_LOADING_kp = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S490>/Integrator' */
    test3_DW.Integrator_PrevResetState_kl = 0;
    test3_DW.Integrator_IC_LOADING_ew = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S496>/Integrator' */
    test3_DW.Integrator_PrevResetState_nk = 0;
    test3_DW.Integrator_IC_LOADING_bk = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S508>/Integrator' */
    test3_DW.Integrator_PrevResetState_ln = 0;
    test3_DW.Integrator_IC_LOADING_j31 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S514>/Integrator' */
    test3_DW.Integrator_PrevResetState_oe = 0;
    test3_DW.Integrator_IC_LOADING_mo = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S520>/Integrator' */
    test3_DW.Integrator_PrevResetState_hu = 0;
    test3_DW.Integrator_IC_LOADING_abf = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S526>/Integrator' */
    test3_DW.Integrator_PrevResetState_mr = 0;
    test3_DW.Integrator_IC_LOADING_ho = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S532>/Integrator' */
    test3_DW.Integrator_PrevResetState_ec = 0;
    test3_DW.Integrator_IC_LOADING_ph = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S538>/Integrator' */
    test3_DW.Integrator_PrevResetState_bb = 0;
    test3_DW.Integrator_IC_LOADING_da = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S544>/Integrator' */
    test3_DW.Integrator_PrevResetState_n1 = 0;
    test3_DW.Integrator_IC_LOADING_cg = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S550>/Integrator' */
    test3_DW.Integrator_PrevResetState_iw = 0;
    test3_DW.Integrator_IC_LOADING_d3 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S556>/Integrator' */
    test3_DW.Integrator_PrevResetState_gg = 0;
    test3_DW.Integrator_IC_LOADING_d0 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S562>/Integrator' */
    test3_DW.Integrator_PrevResetState_lz = 0;
    test3_DW.Integrator_IC_LOADING_mg = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S574>/Integrator' */
    test3_DW.Integrator_PrevResetState_dkv = 0;
    test3_DW.Integrator_IC_LOADING_e3 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S580>/Integrator' */
    test3_DW.Integrator_PrevResetState_bq = 0;
    test3_DW.Integrator_IC_LOADING_ns = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S586>/Integrator' */
    test3_DW.Integrator_PrevResetState_pb = 0;
    test3_DW.Integrator_IC_LOADING_hp = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S592>/Integrator' */
    test3_DW.Integrator_PrevResetState_ew = 0;
    test3_DW.Integrator_IC_LOADING_a0 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S598>/Integrator' */
    test3_DW.Integrator_PrevResetState_pl = 0;
    test3_DW.Integrator_IC_LOADING_bo = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S604>/Integrator' */
    test3_DW.Integrator_PrevResetState_mu = 0;
    test3_DW.Integrator_IC_LOADING_kq = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S610>/Integrator' */
    test3_DW.Integrator_PrevResetState_e4 = 0;
    test3_DW.Integrator_IC_LOADING_h2 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S616>/Integrator' */
    test3_DW.Integrator_PrevResetState_jl = 0;
    test3_DW.Integrator_IC_LOADING_kkm = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S622>/Integrator' */
    test3_DW.Integrator_PrevResetState_cx = 0;
    test3_DW.Integrator_IC_LOADING_bz = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S628>/Integrator' */
    test3_DW.Integrator_PrevResetState_mm = 0;
    test3_DW.Integrator_IC_LOADING_o1 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S640>/Integrator' */
    test3_DW.Integrator_PrevResetState_pg = 0;
    test3_DW.Integrator_IC_LOADING_fcd = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S646>/Integrator' */
    test3_DW.Integrator_PrevResetState_md = 0;
    test3_DW.Integrator_IC_LOADING_bp = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S652>/Integrator' */
    test3_DW.Integrator_PrevResetState_bf = 0;
    test3_DW.Integrator_IC_LOADING_ad = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S658>/Integrator' */
    test3_DW.Integrator_PrevResetState_fam = 0;
    test3_DW.Integrator_IC_LOADING_kv = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S664>/Integrator' */
    test3_DW.Integrator_PrevResetState_g2 = 0;
    test3_DW.Integrator_IC_LOADING_h20 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S670>/Integrator' */
    test3_DW.Integrator_PrevResetState_ou = 0;
    test3_DW.Integrator_IC_LOADING_d04 = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S676>/Integrator' */
    test3_DW.Integrator_PrevResetState_k5 = 0;
    test3_DW.Integrator_IC_LOADING_jn = 1U;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Current_Limit' */
    /* InitializeConditions for RateLimiter: '<S99>/Rate Limiter1' */
    test3_DW.PrevY = 100.0F;

    /* Start for MATLABSystem: '<S99>/Moving Average' */
    test3_DW.obj.matlabCodegenIsDeleted = true;
    test3_DW.obj.isInitialized = 0L;
    test3_DW.obj.NumChannels = -1L;
    test3_DW.obj.matlabCodegenIsDeleted = false;
    test3_DW.obj.isSetupComplete = false;
    test3_DW.obj.isInitialized = 1L;
    test3_DW.obj.NumChannels = 1L;
    iobj_0 = &test3_DW.obj._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;
    test3_DW.obj.pStatistic = iobj_0;
    test3_DW.obj.isSetupComplete = true;
    test3_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S99>/Moving Average' */
    iobj_0 = test3_DW.obj.pStatistic;
    if (iobj_0->isInitialized == 1L) {
      iobj_0->pCumSum = 0.0F;
      for (i = 0; i < 11; i++) {
        iobj_0->pCumSumRev[i] = 0.0F;
      }

      iobj_0->pCumRevIndex = 1.0F;
      iobj_0->pModValueRev = 0.0F;
    }

    /* End of InitializeConditions for MATLABSystem: '<S99>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/Current_Limit' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/BMS_Function' */
    /* SystemInitialize for Chart: '<S97>/Chart' */
    test3_DW.is_Balancing = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_BalancingON = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i4 = 0UL;
    test3_DW.is_ChargerContactorState = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_CloseChgrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_OpenChgrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i5 = 0UL;
    test3_DW.is_MonitorCellTemp = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_MonitorCellVoltage = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_MonitorCurrLim = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_MonitorFault_In = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_InverterContactorState = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_CloseInvtrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_OpenInvtrContactors = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i3 = 0UL;
    test3_DW.is_MainStateMachine = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_Charginig = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i2 = 0UL;
    test3_DW.is_test = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i1_h = 0UL;
    test3_DW.is_active_c2_test3 = 0U;
    test3_DW.FaultPresent = false;
    test3_DW.InvtrCntctState = Open;
    test3_DW.ChrgCntctState = Open;
    test3_DW.DeltaCellVolt = 0.0F;
    test3_DW.flgBalCompl = false;
    test3_DW.PreContact = 0.0;

    /* InitializeConditions for Sum: '<S679>/Add1' incorporates:
     *  Chart: '<S97>/Chart'
     *  Merge: '<S677>/ Merge '
     * */
    test3_B.ChargeCurrentReq = 0.0F;

    /* SystemInitialize for Chart: '<S97>/Chart' incorporates:
     *  Outport: '<Root>/Faults'
     */
    test3_Y.Faults_d.VoltSensor = false;
    test3_Y.Faults_d.OverCurrent = false;
    test3_Y.Faults_d.HighTemp = false;
    test3_Y.Faults_d.LowTemp = false;
    test3_Y.Faults_d.OverVolt = false;
    test3_Y.Faults_d.UnderVolt = false;
    test3_Y.Faults_d.Charger = false;
    test3_Y.Faults_d.Inverter = false;
    test3_Y.Faults_d.PreChargeFault = false;
    test3_Y.Faults_d.OverDischargeCurrent = false;
    test3_Y.Faults_d.OverChargeCurrent = false;
    test3_Y.Faults_d.BalEn = false;
    test3_Y.Faults_d.ShortCircuitFault = false;
    test3_Y.Faults_d.BMBFault = false;
    test3_Y.Faults_d.CurrentSensor = false;
    test3_Y.Faults_d.MemoryFault = false;
    test3_Y.Faults_d.InputPowerFault = false;
    test3_Y.Faults_d.TempSensor = false;
    test3_Y.Faults_d.CAN_VCU_Fault = false;
    test3_Y.Faults_d.LowSOC = false;
    test3_B.PreChargeRelayInvtrCmd = false;
    test3_B.PosContactorInvtrCmd = false;
    test3_B.NegContactorInvtrCmd = false;
    test3_B.PosContactorChgrCmd = false;
    test3_B.PreChargeRelayChgrCmd = false;
    test3_B.NegContactorChgrCmd = false;
    for (i = 0; i < 96; i++) {
      test3_B.BalCmd[i] = false;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/BMS_Function' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/RCTcc' */
    test3_RCTcc_Init(&test3_B.RCTcc, &test3_DW.RCTcc);

    /* End of SystemInitialize for SubSystem: '<Root>/RCTcc' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/CAN_VCU_Fault' */
    /* SystemInitialize for Chart: '<S98>/Chart1' */
    test3_DW.is_main_Task = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i1 = 0UL;
    test3_DW.is_reseting_Counter = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_active_c5_test3 = 0U;

    /* SystemInitialize for Chart: '<S98>/Chart' */
    test3_DW.is_Static_Absent = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.is_Static_present = test3_IN_NO_ACTIVE_CHILD_k;
    test3_DW.temporalCounter_i1_j = 0U;
    test3_DW.is_active_c4_test3 = 0U;
    test3_DW.is_c4_test3 = test3_IN_NO_ACTIVE_CHILD_k;

    /* End of SystemInitialize for SubSystem: '<Root>/CAN_VCU_Fault' */

    /* SystemInitialize for Inport: '<Root>/CellTemperatures' */
    test3_MovingAverage_Init(&test3_DW.MovingAverage);
    test3_MovingAverage_Init(&test3_DW.MovingAverage1);
    test3_MovingAverage_Init(&test3_DW.MovingAverage2);
    test3_MovingAverage_Init(&test3_DW.MovingAverage3);
    test3_MovingAverage_Init(&test3_DW.MovingAverage4);
    test3_MovingAverage_Init(&test3_DW.MovingAverage5);
    test3_MovingAverage_Init(&test3_DW.MovingAverage6);
    test3_MovingAverage_Init(&test3_DW.MovingAverage7);
    test3_MovingAverage_Init(&test3_DW.MovingAverage8);
    test3_MovingAverage_Init(&test3_DW.MovingAverage9);
    test3_MovingAverage_Init(&test3_DW.MovingAverage10);
    test3_MovingAverage_Init(&test3_DW.MovingAverage11);
    test3_MovingAverage_Init(&test3_DW.MovingAverage12);
    test3_MovingAverage_Init(&test3_DW.MovingAverage13);
    test3_MovingAverage_Init(&test3_DW.MovingAverage14);
    test3_MovingAverage_Init(&test3_DW.MovingAverage15);
  }
}

/* Model terminate function */
void test3_terminate(void)
{
  g_dsp_internal_SlidingWindo_k_T *obj;
  test3_MovingAverage_Term(&test3_DW.MovingAverage);
  test3_MovingAverage_Term(&test3_DW.MovingAverage1);
  test3_MovingAverage_Term(&test3_DW.MovingAverage2);
  test3_MovingAverage_Term(&test3_DW.MovingAverage3);
  test3_MovingAverage_Term(&test3_DW.MovingAverage4);
  test3_MovingAverage_Term(&test3_DW.MovingAverage5);
  test3_MovingAverage_Term(&test3_DW.MovingAverage6);
  test3_MovingAverage_Term(&test3_DW.MovingAverage7);
  test3_MovingAverage_Term(&test3_DW.MovingAverage8);
  test3_MovingAverage_Term(&test3_DW.MovingAverage9);
  test3_MovingAverage_Term(&test3_DW.MovingAverage10);
  test3_MovingAverage_Term(&test3_DW.MovingAverage11);
  test3_MovingAverage_Term(&test3_DW.MovingAverage12);
  test3_MovingAverage_Term(&test3_DW.MovingAverage13);
  test3_MovingAverage_Term(&test3_DW.MovingAverage14);
  test3_MovingAverage_Term(&test3_DW.MovingAverage15);

  /* Terminate for Atomic SubSystem: '<Root>/Current_Limit' */
  /* Terminate for MATLABSystem: '<S99>/Moving Average' */
  if (!test3_DW.obj.matlabCodegenIsDeleted) {
    test3_DW.obj.matlabCodegenIsDeleted = true;
    if ((test3_DW.obj.isInitialized == 1L) && test3_DW.obj.isSetupComplete) {
      obj = test3_DW.obj.pStatistic;
      if (obj->isInitialized == 1L) {
        obj->isInitialized = 2L;
      }

      test3_DW.obj.NumChannels = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<S99>/Moving Average' */
  /* End of Terminate for SubSystem: '<Root>/Current_Limit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
