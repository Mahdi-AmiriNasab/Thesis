/*
 * File: mcu.c
 *
 * Code generated for Simulink model 'mcu'.
 *
 * Model version                  : 3.20
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Feb 23 17:51:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcu.h"
#include "rtwtypes.h"
#include "mcu_private.h"
#include "coloumb_counting.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_mcu_T mcu_B;

/* Block states (default storage) */
DW_mcu_T mcu_DW;

/* External inputs (root inport signals with default storage) */
ExtU_mcu_T mcu_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_mcu_T mcu_Y;

/* Real-time model */
static RT_MODEL_mcu_T mcu_M_;
RT_MODEL_mcu_T *const mcu_M = &mcu_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcu_M->Timing.TaskCounters.TID[1])++;
  if ((mcu_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    mcu_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S1>/demux n'
 *    '<S1>/demux p'
 */
void mcu_demuxn(real_T rtu_u, real_T *rty_s1, real_T *rty_s2, real_T *rty_s3,
                real_T *rty_s4, real_T *rty_s5, real_T *rty_s6, real_T *rty_s7,
                real_T *rty_s8, real_T *rty_s9)
{
  /* :  switch(u) */
  switch ((int16_T)rtu_u) {
   case 1:
    /* :  case 1 */
    /* :  s1 = 1; */
    *rty_s1 = 1.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 2:
    /* :  case 2 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 1; */
    *rty_s2 = 1.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 3:
    /* :  case 3 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 1; */
    *rty_s3 = 1.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 4:
    /* :  case 4 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 1; */
    *rty_s4 = 1.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 5:
    /* :  case 5 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 1; */
    *rty_s5 = 1.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 6:
    /* :  case 6 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 1; */
    *rty_s6 = 1.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 7:
    /* :  case 7 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 1; */
    *rty_s7 = 1.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 8:
    /* :  case 8 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 1; */
    *rty_s8 = 1.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;

   case 9:
    /* :  case 9 */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 1; */
    *rty_s9 = 1.0;
    break;

   default:
    /* :  otherwise */
    /* :  s1 = 0; */
    *rty_s1 = 0.0;

    /* :  s2 = 0; */
    *rty_s2 = 0.0;

    /* :  s3 = 0; */
    *rty_s3 = 0.0;

    /* :  s4 = 0; */
    *rty_s4 = 0.0;

    /* :  s5 = 0; */
    *rty_s5 = 0.0;

    /* :  s6 = 0; */
    *rty_s6 = 0.0;

    /* :  s7 = 0; */
    *rty_s7 = 0.0;

    /* :  s8 = 0; */
    *rty_s8 = 0.0;

    /* :  s9 = 0; */
    *rty_s9 = 0.0;
    break;
  }
}

/* Model step function */
void mcu_step(void)
{
  real_T dst_trg_soc_av_tmp[50];
  real_T RateTransition_Buffer;
  real_T c_y;
  int16_T b_k;
  int16_T eq_current_tmp;
  int16_T i;
  int16_T vlen;
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T y;

  /* Memory: '<S1>/Memory' */
  mcu_B.Memory[0] = mcu_DW.Memory_PreviousInput[0];

  /* Memory: '<S1>/Memory1' */
  mcu_B.Memory1[0] = mcu_DW.Memory1_PreviousInput[0];

  /* Memory: '<S1>/Memory' */
  mcu_B.Memory[1] = mcu_DW.Memory_PreviousInput[1];

  /* Memory: '<S1>/Memory1' */
  mcu_B.Memory1[1] = mcu_DW.Memory1_PreviousInput[1];

  /* MATLAB Function: '<S1>/battery_selector' */
  /* :  sw_pos = 0; */
  mcu_B.sw_pos = 0.0;

  /* :  sw_neg = 0; */
  mcu_B.sw_neg = 0.0;

  /* Outport: '<Root>/eq_current' incorporates:
   *  MATLAB Function: '<S1>/battery_selector'
   */
  /* :  eq_current = 0; */
  mcu_Y.eq_current = 0.0;

  /* MATLAB Function: '<S1>/battery_selector' incorporates:
   *  Memory: '<S1>/Memory'
   *  Memory: '<S1>/Memory1'
   */
  /* :  eq_current_tmp = 0; */
  /* :  if ( batts_to_charge(1, 1) <= batts_to_charge(1, 2) && ... */
  /* :       batts_to_discharge(1, 1) <= batts_to_discharge(1, 2)) */
  if ((mcu_B.Memory[0] <= mcu_B.Memory[1]) && (mcu_B.Memory1[0] <=
       mcu_B.Memory1[1])) {
    /* :  if(direction == 0) */
    /* :  sw_pos = batts_to_discharge(1, 1); */
    mcu_B.sw_pos = mcu_B.Memory1[0];

    /* :  sw_neg = batts_to_discharge(1, 2); */
    mcu_B.sw_neg = mcu_B.Memory1[1];

    /* :  eq_current_tmp = 4; */
    /* :  if(V_batt < 2) */
    /* :  eq_current = 0; */
  }

  /* MATLAB Function: '<S1>/demux n' incorporates:
   *  Outport: '<Root>/g1n'
   *  Outport: '<Root>/g2n'
   *  Outport: '<Root>/g3n'
   *  Outport: '<Root>/g4n'
   *  Outport: '<Root>/g5n'
   *  Outport: '<Root>/g6n'
   *  Outport: '<Root>/g7n'
   *  Outport: '<Root>/g8n'
   *  Outport: '<Root>/g9n'
   */
  mcu_demuxn(mcu_B.sw_neg, &mcu_Y.g1n, &mcu_Y.g2n, &mcu_Y.g3n, &mcu_Y.g4n,
             &mcu_Y.g5n, &mcu_Y.g6n, &mcu_Y.g7n, &mcu_Y.g8n, &mcu_Y.g9n);

  /* MATLAB Function: '<S1>/demux p' incorporates:
   *  Outport: '<Root>/g1p'
   *  Outport: '<Root>/g2p'
   *  Outport: '<Root>/g3p'
   *  Outport: '<Root>/g4p'
   *  Outport: '<Root>/g5p'
   *  Outport: '<Root>/g6p'
   *  Outport: '<Root>/g7p'
   *  Outport: '<Root>/g8p'
   *  Outport: '<Root>/g9p'
   */
  mcu_demuxn(mcu_B.sw_pos, &mcu_Y.g1p, &mcu_Y.g2p, &mcu_Y.g3p, &mcu_Y.g4p,
             &mcu_Y.g5p, &mcu_Y.g6p, &mcu_Y.g7p, &mcu_Y.g8p, &mcu_Y.g9p);

  /* RateTransition: '<S1>/Rate Transition' */
  if (mcu_M->Timing.TaskCounters.TID[1] == 0) {
    for (i = 0; i < 9; i++) {
      RateTransition_Buffer = mcu_U.current[i];
      mcu_DW.RateTransition_Buffer[i] = RateTransition_Buffer;

      /* RateTransition: '<S1>/Rate Transition' incorporates:
       *  Inport: '<Root>/I_meas'
       */
      mcu_B.RateTransition[i] = RateTransition_Buffer;

      /* RateTransition: '<S1>/Rate Transition1' incorporates:
       *  Inport: '<Root>/SOC_init'
       */
      RateTransition_Buffer = mcu_U.SOC_c[i];
      mcu_DW.RateTransition1_Buffer[i] = RateTransition_Buffer;

      /* RateTransition: '<S1>/Rate Transition1' */
      mcu_B.RateTransition1[i] = RateTransition_Buffer;
    }

    /* ModelReference: '<S1>/Ah_estimator' incorporates:
     *  Inport: '<Root>/CAP_Ah'
     *  Inport: '<Root>/I_meas'
     */
    coloumb_counting(&mcu_B.RateTransition[0], &mcu_U.CAP_Ah,
                     &mcu_B.RateTransition1[0], &mcu_B.Ah_estimator[0],
                     &(mcu_DW.Ah_estimator_InstanceData.rtdw));
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* MATLAB Function: '<S1>/equalizer' incorporates:
   *  Inport: '<Root>/SOC'
   *  Inport: '<Root>/dst_q_cls'
   *  Inport: '<Root>/dst_trg_soc_av'
   *  Inport: '<Root>/src_q_cls'
   *  Inport: '<Root>/src_trg_soc_av'
   */
  /* :  stop_simulation  = 0; */
  mcu_B.stop_simulation = 0.0;

  /* :  source_batts = [0 0]; */
  /* :  destinations_batts = [0 0]; */
  mcu_B.source_batts[0] = 0.0;
  mcu_B.destinations_batts[0] = 0.0;
  mcu_B.source_batts[1] = 0.0;
  mcu_B.destinations_batts[1] = 0.0;

  /* :  dst_trg_soc_av_tmp = dst_trg_soc_av; */
  /* :  src_trg_soc_av_tmp = src_trg_soc_av; */
  /* :  dst_trg_soc_av_tmp(dst_trg_soc_av == 0) = Inf; */
  for (i = 0; i < 50; i++) {
    RateTransition_Buffer = mcu_U.dst_trg_soc_av[i];
    dst_trg_soc_av_tmp[i] = RateTransition_Buffer;
    if (RateTransition_Buffer == 0.0) {
      dst_trg_soc_av_tmp[i] = (rtInf);
    }
  }

  /* :  step = length(src_q_cls); */
  /* :  if isempty(step_cnt) */
  /* :  soc = SOC'; */
  /* :  if src_q_cls(step_cnt, :) > 0 */
  i = (int16_T)mcu_DW.step_cnt;
  x[0] = (mcu_U.src_q_cls[i - 1] > 0.0);
  x[1] = (mcu_U.src_q_cls[i + 49] > 0.0);
  y = true;
  eq_current_tmp = 0;
  exitg1 = false;
  while ((!exitg1) && (eq_current_tmp < 2)) {
    if (!x[eq_current_tmp]) {
      y = false;
      exitg1 = true;
    } else {
      eq_current_tmp++;
    }
  }

  if (y) {
    /* :  source_batts = src_q_cls(step_cnt, :); */
    i = (int16_T)mcu_DW.step_cnt;

    /* :  destinations_batts = dst_q_cls(step_cnt, :); */
    vlen = (int16_T)mcu_DW.step_cnt;
    mcu_B.source_batts[0] = mcu_U.src_q_cls[i - 1];
    mcu_B.destinations_batts[0] = mcu_U.dst_q_cls[vlen - 1];
    mcu_B.source_batts[1] = mcu_U.src_q_cls[i + 49];
    mcu_B.destinations_batts[1] = mcu_U.dst_q_cls[vlen + 49];

    /* :  sm = mean(soc(src_q_cls(step_cnt, 1):src_q_cls(step_cnt, 2))); */
    if (mcu_U.src_q_cls[(int16_T)mcu_DW.step_cnt - 1] > mcu_U.src_q_cls[(int16_T)
        mcu_DW.step_cnt + 49]) {
      eq_current_tmp = 0;
      i = 0;
    } else {
      eq_current_tmp = (int16_T)mcu_U.src_q_cls[(int16_T)mcu_DW.step_cnt - 1] -
        1;
      i = (int16_T)mcu_U.src_q_cls[(int16_T)mcu_DW.step_cnt + 49];
    }

    i -= eq_current_tmp;
    vlen = i;
    if (i == 0) {
      RateTransition_Buffer = 0.0;
    } else {
      RateTransition_Buffer = mcu_U.SOC[eq_current_tmp];
      for (b_k = 2; b_k <= vlen; b_k++) {
        RateTransition_Buffer += mcu_U.SOC[(eq_current_tmp + b_k) - 1];
      }
    }

    /* :  dm = mean(soc(dst_q_cls(step_cnt, 1):dst_q_cls(step_cnt, 2))); */
    if (mcu_U.dst_q_cls[(int16_T)mcu_DW.step_cnt - 1] > mcu_U.dst_q_cls[(int16_T)
        mcu_DW.step_cnt + 49]) {
      vlen = 0;
      b_k = 0;
    } else {
      vlen = (int16_T)mcu_U.dst_q_cls[(int16_T)mcu_DW.step_cnt - 1] - 1;
      b_k = (int16_T)mcu_U.dst_q_cls[(int16_T)mcu_DW.step_cnt + 49];
    }

    eq_current_tmp = b_k - vlen;
    if (eq_current_tmp == 0) {
      c_y = 0.0;
    } else {
      c_y = mcu_U.SOC[vlen];
      for (b_k = 2; b_k <= eq_current_tmp; b_k++) {
        c_y += mcu_U.SOC[(vlen + b_k) - 1];
      }
    }

    /* :  if(sm <= src_trg_soc_av_tmp(step_cnt) || dm >= dst_trg_soc_av_tmp(step_cnt)) */
    if (RateTransition_Buffer / (real_T)i <= mcu_U.src_trg_soc_av[(int16_T)
        mcu_DW.step_cnt - 1]) {
      /* :  step_cnt = step_cnt + 1; */
      mcu_DW.step_cnt++;
    } else if (c_y / (real_T)eq_current_tmp >= dst_trg_soc_av_tmp[(int16_T)
               mcu_DW.step_cnt - 1]) {
      /* :  step_cnt = step_cnt + 1; */
      mcu_DW.step_cnt++;
    }
  } else {
    /* :  else */
    /* :  stop_simulation  = 1; */
    mcu_B.stop_simulation = 1.0;
  }

  /* :  step_cnt_out = step_cnt; */
  mcu_B.step_cnt_out = mcu_DW.step_cnt;

  /* End of MATLAB Function: '<S1>/equalizer' */

  /* Stop: '<S1>/Stop Simulation' */
  if (mcu_B.stop_simulation != 0.0) {
    rtmSetStopRequested(mcu_M, 1);
  }

  /* End of Stop: '<S1>/Stop Simulation' */

  /* Update for Memory: '<S1>/Memory' */
  mcu_DW.Memory_PreviousInput[0] = mcu_B.destinations_batts[0];

  /* Update for Memory: '<S1>/Memory1' */
  mcu_DW.Memory1_PreviousInput[0] = mcu_B.source_batts[0];

  /* Update for Memory: '<S1>/Memory' */
  mcu_DW.Memory_PreviousInput[1] = mcu_B.destinations_batts[1];

  /* Update for Memory: '<S1>/Memory1' */
  mcu_DW.Memory1_PreviousInput[1] = mcu_B.source_batts[1];
  rate_scheduler();
}

/* Model initialize function */
void mcu_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Model Initialize function for ModelReference Block: '<S1>/Ah_estimator' */
  coloumb_counting_initialize(rtmGetErrorStatusPointer(mcu_M),
    &(mcu_DW.Ah_estimator_InstanceData.rtm));

  /* SystemInitialize for ModelReference: '<S1>/Ah_estimator' */
  coloumb_counting_Init(&(mcu_DW.Ah_estimator_InstanceData.rtdw));

  /* SystemInitialize for MATLAB Function: '<S1>/equalizer' */
  /* :  step_cnt = 1; */
  mcu_DW.step_cnt = 1.0;

  /* :  assert(1, 'Simulation terminated because x >= 10') */
}

/* Model terminate function */
void mcu_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
