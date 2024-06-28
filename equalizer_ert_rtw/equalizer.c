/*
 * File: equalizer.c
 *
 * Code generated for Simulink model 'equalizer'.
 *
 * Model version                  : 4.14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 27 00:22:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "equalizer.h"
#include "rtwtypes.h"
#include "equalizer_private.h"
#include <math.h>
#include "zero_crossing_types.h"
#include "coloumb_counting.h"

/* Block signals (default storage) */
B_equalizer_T equalizer_B;

/* Continuous states */
X_equalizer_T equalizer_X;

/* Disabled State Vector */
XDis_equalizer_T equalizer_XDis;

/* Block states (default storage) */
DW_equalizer_T equalizer_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_equalizer_T equalizer_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_equalizer_T equalizer_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_equalizer_T equalizer_Y;

/* Real-time model */
static RT_MODEL_equalizer_T equalizer_M_;
RT_MODEL_equalizer_T *const equalizer_M = &equalizer_M_;
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
  (equalizer_M->Timing.TaskCounters.TID[2])++;
  if ((equalizer_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    equalizer_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  equalizer_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  equalizer_step();
  equalizer_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  equalizer_step();
  equalizer_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S1>/demux n'
 *    '<S1>/demux p'
 */
void equalizer_demuxn(real_T rtu_u, real_T *rty_s1, real_T *rty_s2, real_T
                      *rty_s3, real_T *rty_s4, real_T *rty_s5, real_T *rty_s6,
                      real_T *rty_s7, real_T *rty_s8, real_T *rty_s9)
{
  switch ((int16_T)rtu_u) {
   case 1:
    *rty_s1 = 1.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 2:
    *rty_s1 = 0.0;
    *rty_s2 = 1.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 3:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 1.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 4:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 1.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 5:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 1.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 6:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 1.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 7:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 1.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;

   case 8:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 1.0;
    *rty_s9 = 0.0;
    break;

   case 9:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 1.0;
    break;

   default:
    *rty_s1 = 0.0;
    *rty_s2 = 0.0;
    *rty_s3 = 0.0;
    *rty_s4 = 0.0;
    *rty_s5 = 0.0;
    *rty_s6 = 0.0;
    *rty_s7 = 0.0;
    *rty_s8 = 0.0;
    *rty_s9 = 0.0;
    break;
  }
}

/* Model step function */
void equalizer_step(void)
{
  if (rtmIsMajorTimeStep(equalizer_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&equalizer_M->solverInfo,
                          ((equalizer_M->Timing.clockTick0+1)*
      equalizer_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(equalizer_M)) {
    equalizer_M->Timing.t[0] = rtsiGetT(&equalizer_M->solverInfo);
  }

  {
    real_T AH_coeff;
    real_T destination_batt_number;
    real_T source_batt_number;
    int16_T b_k;
    int16_T eq_current_tmp;
    int16_T i;
    int16_T vlen;
    boolean_T exitg1;
    boolean_T y;
    ZCEventType zcEvent;
    if (rtmIsMajorTimeStep(equalizer_M) &&
        equalizer_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<S1>/Memory' */
      equalizer_B.Memory[0] = equalizer_DW.Memory_PreviousInput[0];

      /* Memory: '<S1>/Memory1' */
      equalizer_B.Memory1[0] = equalizer_DW.Memory1_PreviousInput[0];

      /* Memory: '<S1>/Memory' */
      equalizer_B.Memory[1] = equalizer_DW.Memory_PreviousInput[1];

      /* Memory: '<S1>/Memory1' */
      equalizer_B.Memory1[1] = equalizer_DW.Memory1_PreviousInput[1];
      for (i = 0; i < 9; i++) {
        /* Memory: '<S1>/Memory3' */
        equalizer_B.Memory3[i] = equalizer_DW.Memory3_PreviousInput[i];
      }

      /* Memory: '<S1>/Memory4' */
      equalizer_B.Memory4 = equalizer_DW.Memory4_PreviousInput;

      /* MATLAB Function: '<S1>/equalizer' incorporates:
       *  Inport: '<Root>/SOC'
       *  Inport: '<Root>/dst_q_cls'
       *  Inport: '<Root>/src_q_cls'
       *  Inport: '<Root>/src_trg_soc_av'
       *  Memory: '<S1>/Memory3'
       */
      equalizer_B.I_tranfer = 0.0;
      equalizer_B.transfer_over = 0.0;
      equalizer_B.source_batts[0] = 0.0;
      equalizer_B.destinations_batts[0] = 0.0;
      equalizer_B.source_batts[1] = 0.0;
      equalizer_B.destinations_batts[1] = 0.0;
      y = true;
      eq_current_tmp = 0;
      exitg1 = false;
      while ((!exitg1) && (eq_current_tmp < 2)) {
        if (!(equalizer_U.src_q_cls[eq_current_tmp] > 0.0)) {
          y = false;
          exitg1 = true;
        } else {
          eq_current_tmp++;
        }
      }

      if (y) {
        equalizer_B.source_batts[0] = equalizer_U.src_q_cls[0];
        equalizer_B.destinations_batts[0] = equalizer_U.dst_q_cls[0];
        equalizer_B.source_batts[1] = equalizer_U.src_q_cls[1];
        equalizer_B.destinations_batts[1] = equalizer_U.dst_q_cls[1];
        if ((equalizer_DW.dir == -1.0) && (!equalizer_B.Memory4)) {
          equalizer_B.I_tranfer = equalizer_B.Memory3[(int16_T)
            equalizer_U.src_q_cls[0] - 1];
          equalizer_DW.enable = 1.0;
          equalizer_DW.dir = 0.0;
        }

        if (equalizer_DW.dir == 0.0) {
          equalizer_B.I_tranfer = equalizer_B.Memory3[(int16_T)
            equalizer_U.src_q_cls[0] - 1];
        }

        if ((equalizer_DW.dir == 0.0) && equalizer_B.Memory4 &&
            (equalizer_DW.enable == 1.0)) {
          equalizer_DW.enable = 0.0;
        }

        if ((equalizer_DW.dir == 0.0) && (!equalizer_B.Memory4) &&
            (equalizer_DW.enable == 0.0)) {
          equalizer_B.I_tranfer = equalizer_B.Memory3[(int16_T)
            equalizer_U.dst_q_cls[0] - 1];
          equalizer_DW.enable = 1.0;
          equalizer_DW.dir = 1.0;
        }

        if (equalizer_DW.dir == 1.0) {
          equalizer_B.I_tranfer = equalizer_B.Memory3[(int16_T)
            equalizer_U.dst_q_cls[0] - 1];
        }

        if ((equalizer_DW.dir == 1.0) && equalizer_B.Memory4 &&
            (equalizer_DW.enable == 1.0)) {
          equalizer_DW.enable = 0.0;
        }

        if ((equalizer_DW.dir == 1.0) && (!equalizer_B.Memory4) &&
            (equalizer_DW.enable == 0.0)) {
          equalizer_DW.dir = -1.0;
        }

        if (equalizer_U.src_q_cls[0] > equalizer_U.src_q_cls[1]) {
          eq_current_tmp = 0;
          i = 0;
        } else {
          eq_current_tmp = (int16_T)equalizer_U.src_q_cls[0] - 1;
          i = (int16_T)equalizer_U.src_q_cls[1];
        }

        i -= eq_current_tmp;
        vlen = i;
        if (i == 0) {
          AH_coeff = 0.0;
        } else {
          AH_coeff = equalizer_U.SOC[eq_current_tmp];
          for (b_k = 2; b_k <= vlen; b_k++) {
            AH_coeff += equalizer_U.SOC[eq_current_tmp + 1];
          }
        }

        if (equalizer_U.dst_q_cls[0] > equalizer_U.dst_q_cls[1]) {
          vlen = 0;
          b_k = 0;
        } else {
          vlen = (int16_T)equalizer_U.dst_q_cls[0] - 1;
          b_k = (int16_T)equalizer_U.dst_q_cls[1];
        }

        eq_current_tmp = b_k - vlen;
        if (eq_current_tmp == 0) {
          source_batt_number = 0.0;
        } else {
          source_batt_number = equalizer_U.SOC[vlen];
          for (b_k = 2; b_k <= eq_current_tmp; b_k++) {
            source_batt_number += equalizer_U.SOC[vlen + 1];
          }
        }

        if (((AH_coeff / (real_T)i <= equalizer_U.src_trg_soc_av) ||
             (source_batt_number / (real_T)eq_current_tmp >=
              equalizer_U.dst_trg_soc_av)) && (equalizer_DW.dir == -1.0)) {
          equalizer_B.transfer_over = 1.0;
        }
      } else {
        equalizer_DW.dir = -1.0;
        equalizer_B.transfer_over = 1.0;
        equalizer_DW.enable = 0.0;
      }

      /* Outport: '<Root>/dir' incorporates:
       *  MATLAB Function: '<S1>/equalizer'
       */
      equalizer_Y.dir = equalizer_DW.dir;

      /* MATLAB Function: '<S1>/equalizer' */
      equalizer_B.enable_I_trs = equalizer_DW.enable;

      /* MATLAB Function: '<S1>/battery_selector' */
      equalizer_B.sw_pos = 0.0;
      equalizer_B.sw_neg = 0.0;

      /* Outport: '<Root>/eq_current' incorporates:
       *  MATLAB Function: '<S1>/battery_selector'
       */
      equalizer_Y.eq_current = 0.0;

      /* MATLAB Function: '<S1>/battery_selector' incorporates:
       *  Memory: '<S1>/Memory'
       *  Memory: '<S1>/Memory1'
       *  Outport: '<Root>/dir'
       */
      eq_current_tmp = 0;
      if ((equalizer_B.Memory[0] <= equalizer_B.Memory[1]) &&
          (equalizer_B.Memory1[0] <= equalizer_B.Memory1[1])) {
        if (equalizer_Y.dir == 0.0) {
          equalizer_B.sw_pos = equalizer_B.Memory1[0];
          equalizer_B.sw_neg = equalizer_B.Memory1[1];
          eq_current_tmp = 2;
        } else if (equalizer_Y.dir == 1.0) {
          equalizer_B.sw_pos = equalizer_B.Memory[0];
          equalizer_B.sw_neg = equalizer_B.Memory[1];
          eq_current_tmp = 2;
        }

        /* Outport: '<Root>/eq_current' incorporates:
         *  Outport: '<Root>/dir'
         */
        equalizer_Y.eq_current = eq_current_tmp;
      }

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
      equalizer_demuxn(equalizer_B.sw_pos, &equalizer_Y.g1p, &equalizer_Y.g2p,
                       &equalizer_Y.g3p, &equalizer_Y.g4p, &equalizer_Y.g5p,
                       &equalizer_Y.g6p, &equalizer_Y.g7p, &equalizer_Y.g8p,
                       &equalizer_Y.g9p);

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
      equalizer_demuxn(equalizer_B.sw_neg, &equalizer_Y.g1n, &equalizer_Y.g2n,
                       &equalizer_Y.g3n, &equalizer_Y.g4n, &equalizer_Y.g5n,
                       &equalizer_Y.g6n, &equalizer_Y.g7n, &equalizer_Y.g8n,
                       &equalizer_Y.g9n);
    }

    if (rtmIsMajorTimeStep(equalizer_M) &&
        equalizer_M->Timing.TaskCounters.TID[2] == 0) {
      /* Gain: '<Root>/Gain' incorporates:
       *  Inport: '<Root>/CAP_mAh'
       */
      equalizer_B.Gain = 0.001 * equalizer_U.CAP_mAh;

      /* ModelReference: '<S1>/Ah_estimator' incorporates:
       *  Inport: '<Root>/I_meas'
       *  Inport: '<Root>/SOC_init'
       */
      coloumb_counting(&equalizer_U.I_meas[0], &equalizer_B.Gain,
                       &equalizer_U.SOC_init[0], &equalizer_B.Ah_estimator[0],
                       &(equalizer_DW.Ah_estimator_InstanceData.rtb),
                       &(equalizer_DW.Ah_estimator_InstanceData.rtdw));

      /* Outport: '<Root>/soc_est' incorporates:
       *  ModelReference: '<S1>/Ah_estimator'
       */
      for (i = 0; i < 9; i++) {
        equalizer_Y.soc_est[i] = equalizer_B.Ah_estimator[i];
      }

      /* End of Outport: '<Root>/soc_est' */
    }

    if (rtmIsMajorTimeStep(equalizer_M) &&
        equalizer_M->Timing.TaskCounters.TID[1] == 0) {
      /* Outputs for Enabled SubSystem: '<S1>/AH_calculation' incorporates:
       *  EnablePort: '<S2>/Enable'
       */
      if (equalizer_B.enable_I_trs > 0.0) {
        /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
         *  Memory: '<S1>/Memory'
         *  Memory: '<S1>/Memory1'
         *  Outport: '<Root>/dir'
         */
        AH_coeff = 1.0;
        source_batt_number = (equalizer_B.Memory1[1] - equalizer_B.Memory1[0]) +
          1.0;
        destination_batt_number = (equalizer_B.Memory[1] - equalizer_B.Memory[0])
          + 1.0;
        if (source_batt_number > destination_batt_number) {
          if (equalizer_Y.dir == 0.0) {
            AH_coeff = destination_batt_number / source_batt_number;
          }
        } else if ((source_batt_number < destination_batt_number) &&
                   (equalizer_Y.dir == 1.0)) {
          AH_coeff = source_batt_number / destination_batt_number;
        }

        equalizer_B.AH_out = 0.001 * AH_coeff;

        /* End of MATLAB Function: '<S2>/MATLAB Function' */
      }

      /* End of Outputs for SubSystem: '<S1>/AH_calculation' */

      /* Memory: '<S1>/Memory2' */
      equalizer_B.Memory2 = equalizer_DW.Memory2_PreviousInput;

      /* Abs: '<S4>/Abs' */
      equalizer_B.Abs = fabs(equalizer_B.Memory2);

      /* Abs: '<S4>/Abs1' */
      equalizer_B.Abs1 = fabs(equalizer_B.AH_out);

      /* Saturate: '<S4>/Saturation' */
      AH_coeff = equalizer_B.enable_I_trs;
      if (AH_coeff > 1.0) {
        /* Saturate: '<S4>/Saturation' */
        equalizer_B.Saturation = 1.0;
      } else if (AH_coeff < 0.0) {
        /* Saturate: '<S4>/Saturation' */
        equalizer_B.Saturation = 0.0;
      } else {
        /* Saturate: '<S4>/Saturation' */
        equalizer_B.Saturation = AH_coeff;
      }

      /* End of Saturate: '<S4>/Saturation' */

      /* Product: '<S4>/Product' */
      equalizer_B.Product = equalizer_B.Abs * equalizer_B.Saturation;

      /* Gain: '<S4>/Gain' */
      equalizer_B.Gain_h = 0.00027777777777777778 * equalizer_B.Product;
    }

    /* Integrator: '<S4>/Integrator' */
    if (rtsiIsModeUpdateTimeStep(&equalizer_M->solverInfo)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &equalizer_PrevZCX.Integrator_Reset_ZCE,
                         (equalizer_B.Saturation));
      y = (zcEvent != NO_ZCEVENT);

      /* evaluate zero-crossings */
      if (y) {
        equalizer_X.Integrator_CSTATE = 0.0;
      }
    }

    /* Integrator: '<S4>/Integrator' */
    equalizer_B.Integrator = equalizer_X.Integrator_CSTATE;

    /* RelationalOperator: '<S4>/comparator' */
    equalizer_B.comparator = (equalizer_B.Integrator >= equalizer_B.Abs1);
  }

  if (rtmIsMajorTimeStep(equalizer_M)) {
    int16_T i;
    if (rtmIsMajorTimeStep(equalizer_M) &&
        equalizer_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Memory: '<S1>/Memory' */
      equalizer_DW.Memory_PreviousInput[0] = equalizer_B.destinations_batts[0];

      /* Update for Memory: '<S1>/Memory1' */
      equalizer_DW.Memory1_PreviousInput[0] = equalizer_B.source_batts[0];

      /* Update for Memory: '<S1>/Memory' */
      equalizer_DW.Memory_PreviousInput[1] = equalizer_B.destinations_batts[1];

      /* Update for Memory: '<S1>/Memory1' */
      equalizer_DW.Memory1_PreviousInput[1] = equalizer_B.source_batts[1];

      /* Update for Memory: '<S1>/Memory3' incorporates:
       *  Inport: '<Root>/I_meas'
       */
      for (i = 0; i < 9; i++) {
        equalizer_DW.Memory3_PreviousInput[i] = equalizer_U.I_meas[i];
      }

      /* End of Update for Memory: '<S1>/Memory3' */

      /* Update for Memory: '<S1>/Memory4' */
      equalizer_DW.Memory4_PreviousInput = equalizer_B.comparator;

      /* Update for Memory: '<S1>/Memory2' */
      equalizer_DW.Memory2_PreviousInput = equalizer_B.I_tranfer;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(equalizer_M)) {
    rt_ertODEUpdateContinuousStates(&equalizer_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++equalizer_M->Timing.clockTick0;
    equalizer_M->Timing.t[0] = rtsiGetSolverStopTime(&equalizer_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      equalizer_M->Timing.clockTick1++;
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void equalizer_derivatives(void)
{
  XDot_equalizer_T *_rtXdot;
  _rtXdot = ((XDot_equalizer_T *) equalizer_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = equalizer_B.Gain_h;
}

/* Model initialize function */
void equalizer_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&equalizer_M->solverInfo,
                          &equalizer_M->Timing.simTimeStep);
    rtsiSetTPtr(&equalizer_M->solverInfo, &rtmGetTPtr(equalizer_M));
    rtsiSetStepSizePtr(&equalizer_M->solverInfo, &equalizer_M->Timing.stepSize0);
    rtsiSetdXPtr(&equalizer_M->solverInfo, &equalizer_M->derivs);
    rtsiSetContStatesPtr(&equalizer_M->solverInfo, (real_T **)
                         &equalizer_M->contStates);
    rtsiSetNumContStatesPtr(&equalizer_M->solverInfo,
      &equalizer_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&equalizer_M->solverInfo,
      &equalizer_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&equalizer_M->solverInfo,
      &equalizer_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&equalizer_M->solverInfo,
      &equalizer_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&equalizer_M->solverInfo, (boolean_T**)
      &equalizer_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&equalizer_M->solverInfo, (&rtmGetErrorStatus
      (equalizer_M)));
    rtsiSetRTModelPtr(&equalizer_M->solverInfo, equalizer_M);
  }

  rtsiSetSimTimeStep(&equalizer_M->solverInfo, MAJOR_TIME_STEP);
  equalizer_M->intgData.y = equalizer_M->odeY;
  equalizer_M->intgData.f[0] = equalizer_M->odeF[0];
  equalizer_M->intgData.f[1] = equalizer_M->odeF[1];
  equalizer_M->intgData.f[2] = equalizer_M->odeF[2];
  equalizer_M->contStates = ((X_equalizer_T *) &equalizer_X);
  equalizer_M->contStateDisabled = ((XDis_equalizer_T *) &equalizer_XDis);
  equalizer_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&equalizer_M->solverInfo, (void *)&equalizer_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&equalizer_M->solverInfo, false);
  rtsiSetSolverName(&equalizer_M->solverInfo,"ode3");
  rtmSetTPtr(equalizer_M, &equalizer_M->Timing.tArray[0]);
  equalizer_M->Timing.stepSize0 = 0.001;

  /* Model Initialize function for ModelReference Block: '<S1>/Ah_estimator' */
  coloumb_counting_initialize(rtmGetErrorStatusPointer(equalizer_M),
    &(equalizer_DW.Ah_estimator_InstanceData.rtm));
  equalizer_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  equalizer_X.Integrator_CSTATE = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/equalizer' */
  equalizer_DW.dir = -1.0;

  /* SystemInitialize for ModelReference: '<S1>/Ah_estimator' */
  coloumb_counting_Init(&(equalizer_DW.Ah_estimator_InstanceData.rtdw));
}

/* Model terminate function */
void equalizer_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
