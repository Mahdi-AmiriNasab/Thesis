/*
 * File: DC_DC_source_based_matrix_switches1.c
 *
 * Code generated for Simulink model 'DC_DC_source_based_matrix_switches1'.
 *
 * Model version                  : 3.20
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Feb 23 17:03:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DC_DC_source_based_matrix_switches1.h"
#include "rtwtypes.h"
#include "DC_DC_source_based_matrix_switches1_private.h"
#include <math.h>
#include <string.h>
#include "zero_crossing_types.h"
#include "coloumb_counting.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_DC_DC_source_based_matrix_s_T DC_DC_source_based_matrix_swi_B;

/* Block states (default storage) */
DW_DC_DC_source_based_matrix__T DC_DC_source_based_matrix_sw_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_DC_DC_source_based_ma_T DC_DC_source_based_matr_PrevZCX;

/* Real-time model */
static RT_MODEL_DC_DC_source_based_m_T DC_DC_source_based_matrix_sw_M_;
RT_MODEL_DC_DC_source_based_m_T *const DC_DC_source_based_matrix_sw_M =
  &DC_DC_source_based_matrix_sw_M_;
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
  (DC_DC_source_based_matrix_sw_M->Timing.TaskCounters.TID[2])++;
  if ((DC_DC_source_based_matrix_sw_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    DC_DC_source_based_matrix_sw_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Disable for enable system:
 *    '<S189>/NEGATIVE Edge'
 *    '<S197>/NEGATIVE Edge'
 */
void DC_DC_sour_NEGATIVEEdge_Disable(DW_NEGATIVEEdge_DC_DC_source__T *localDW)
{
  localDW->NEGATIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S189>/NEGATIVE Edge'
 *    '<S197>/NEGATIVE Edge'
 */
void DC_DC_source_based_NEGATIVEEdge(real_T rtu_Enable, boolean_T rtu_IN,
  boolean_T rtu_INprevious, boolean_T *rty_OUT, DW_NEGATIVEEdge_DC_DC_source__T *
  localDW)
{
  /* Outputs for Enabled SubSystem: '<S189>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S191>/Enable'
   */
  if (rtu_Enable > 0.0) {
    localDW->NEGATIVEEdge_MODE = true;
  } else if (localDW->NEGATIVEEdge_MODE) {
    DC_DC_sour_NEGATIVEEdge_Disable(localDW);
  }

  if (localDW->NEGATIVEEdge_MODE) {
    /* RelationalOperator: '<S191>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious > (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S189>/NEGATIVE Edge' */
}

/*
 * Disable for enable system:
 *    '<S189>/POSITIVE Edge'
 *    '<S197>/POSITIVE Edge'
 */
void DC_DC_sour_POSITIVEEdge_Disable(DW_POSITIVEEdge_DC_DC_source__T *localDW)
{
  localDW->POSITIVEEdge_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S189>/POSITIVE Edge'
 *    '<S197>/POSITIVE Edge'
 */
void DC_DC_source_based_POSITIVEEdge(real_T rtu_Enable, boolean_T rtu_IN,
  boolean_T rtu_INprevious, boolean_T *rty_OUT, DW_POSITIVEEdge_DC_DC_source__T *
  localDW)
{
  /* Outputs for Enabled SubSystem: '<S189>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S192>/Enable'
   */
  if (rtu_Enable > 0.0) {
    localDW->POSITIVEEdge_MODE = true;
  } else if (localDW->POSITIVEEdge_MODE) {
    DC_DC_sour_POSITIVEEdge_Disable(localDW);
  }

  if (localDW->POSITIVEEdge_MODE) {
    /* RelationalOperator: '<S192>/Relational Operator1' */
    *rty_OUT = ((int16_T)rtu_INprevious < (int16_T)rtu_IN);
  }

  /* End of Outputs for SubSystem: '<S189>/POSITIVE Edge' */
}

/*
 * Output and update for atomic system:
 *    '<S31>/demux n'
 *    '<S31>/demux p'
 */
void DC_DC_source_based_matri_demuxn(real_T rtu_u, real_T *rty_s1, real_T
  *rty_s2, real_T *rty_s3, real_T *rty_s4, real_T *rty_s5, real_T *rty_s6,
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
void DC_DC_source_based_matrix_switches1_step(void)
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion2;
  real_T rtb_DataTypeConversion2_p;
  real_T rtb_DataTypeConversion2_n;
  real_T rtb_DataTypeConversion2_e;
  real_T rtb_DataTypeConversion2_j;
  real_T rtb_DataTypeConversion2_d;
  real_T rtb_DataTypeConversion2_g;
  real_T rtb_DataTypeConversion2_jw;
  real_T rtb_DataTypeConversion2_c;
  real_T rtb_Gain1;
  real_T rtb_R1;
  real_T rtb_Gain1_h;
  real_T rtb_R1_m;
  real_T rtb_Gain1_a;
  real_T rtb_R1_h;
  real_T rtb_Gain1_d;
  real_T rtb_R1_e;
  real_T rtb_Gain1_a3;
  real_T rtb_R1_c;
  real_T rtb_Gain1_i;
  real_T rtb_R1_f;
  real_T rtb_Gain1_o;
  real_T rtb_R1_g;
  real_T rtb_Gain1_av;
  real_T rtb_R1_l;
  real_T rtb_Gain1_g;
  real_T rtb_R1_k;
  real_T rtb_Gain2;
  real_T rtb_Gain2_b;
  real_T rtb_Gain2_f;
  real_T rtb_Gain2_o;
  real_T rtb_Gain2_j;
  real_T rtb_Gain2_m;
  real_T rtb_Gain2_oo;
  real_T rtb_Gain2_i;
  real_T rtb_Gain2_n;
  real_T dst_trg_soc_av_tmp[50];
  real_T RateTransition1_Buffer[9];
  real_T rtb_RateTransition[9];
  real_T rtb_Clock;
  real_T rtb_DataTypeConversion1_h;
  real_T rtb_Fcn6;
  real_T rtb_Fcn6_cy;
  real_T rtb_Fcn6_e;
  real_T rtb_Fcn6_g;
  real_T rtb_Fcn6_m4;
  real_T rtb_Fcn6_o;
  real_T rtb_Gain;
  real_T rtb_Gain_d;
  real_T rtb_Gain_io;
  real_T rtb_MultiportSwitch1_a;
  real_T rtb_SOC_d;
  real_T rtb_SOC_d4;
  real_T rtb_SOC_hx;
  real_T rtb_SOC_i;
  real_T rtb_SOC_l;
  real_T rtb_SOC_m;
  real_T rtb_SOC_ox;
  real_T rtb_SOC_pa;
  int16_T b_k;
  int16_T b_vlen_tmp;
  int16_T c;
  int16_T i;
  boolean_T x[2];
  boolean_T LogicalOperator1;
  boolean_T exitg1;

  /* Gain: '<S35>/R2' incorporates:
   *  Gain: '<S35>/R3'
   *  Memory: '<S35>/it init1'
   */
  rtb_Fcn6_cy = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput;

  /* DiscreteTransferFcn: '<S35>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states;

  /* DataTypeConversion: '<S35>/Data Type Conversion2' incorporates:
   *  Constant: '<S37>/Constant'
   *  DiscreteTransferFcn: '<S35>/Current filter'
   *  RelationalOperator: '<S37>/Compare'
   */
  rtb_DataTypeConversion2 = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S35>/int(i)' incorporates:
   *  Memory: '<S35>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2 > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE = 8189.2799999999806;
  }

  /* Gain: '<S35>/Gain' incorporates:
   *  DiscreteIntegrator: '<S35>/int(i)'
   */
  rtb_Gain = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE;

  /* Switch: '<S42>/Switch2' incorporates:
   *  Constant: '<S35>/Constant9'
   *  Gain: '<S35>/R2'
   *  RelationalOperator: '<S42>/LowerRelop1'
   *  RelationalOperator: '<S42>/UpperRelop'
   *  Switch: '<S42>/Switch'
   */
  if (rtb_Gain > rtb_Fcn6_cy) {
    rtb_MultiportSwitch1_a = rtb_Fcn6_cy;
  } else if (rtb_Gain < 0.0) {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S35>/Constant9'
     */
    rtb_MultiportSwitch1_a = 0.0;
  } else {
    rtb_MultiportSwitch1_a = rtb_Gain;
  }

  /* End of Switch: '<S42>/Switch2' */

  /* Switch: '<S35>/Switch7' incorporates:
   *  Fcn: '<S35>/Fcn9'
   *  Gain: '<S35>/R2'
   *  RelationalOperator: '<S35>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6_cy * 0.96711798839458663 / 0.9999 <=
      rtb_MultiportSwitch1_a) {
    rtb_MultiportSwitch1_a = rtb_Fcn6_cy;
  }

  /* End of Switch: '<S35>/Switch7' */

  /* Switch: '<S43>/Switch2' incorporates:
   *  RelationalOperator: '<S43>/LowerRelop1'
   */
  if (rtb_Gain > rtb_Fcn6_cy) {
    rtb_Gain = rtb_Fcn6_cy;
  } else {
    /* Fcn: '<S35>/Fcn6' */
    rtb_Fcn6_cy = -rtb_Fcn6_cy * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S43>/Switch' incorporates:
     *  RelationalOperator: '<S43>/UpperRelop'
     */
    if (rtb_Gain < rtb_Fcn6_cy) {
      rtb_Gain = rtb_Fcn6_cy;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Saturate: '<S40>/Saturation' incorporates:
   *  MultiPortSwitch: '<S40>/Multiport Switch1'
   */
  if (rtb_MultiportSwitch1_a >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_MultiportSwitch1_a;
  }

  /* Fcn: '<S35>/E_dyn Discharge' incorporates:
   *  Fcn: '<S35>/E_NL'
   *  Memory: '<S35>/it init1'
   */
  rtb_Fcn6_cy = DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput -
    rtb_MultiportSwitch1_a;

  /* Sum: '<S35>/Add3' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S38>/Constant'
   *  DiscreteTransferFcn: '<S35>/Current filter'
   *  Fcn: '<S35>/E_NL'
   *  Fcn: '<S35>/E_dyn Discharge'
   *  Fcn: '<S35>/Fcn5'
   *  Fcn: '<S39>/Charge Li-Ion'
   *  Fcn: '<S40>/Li-Ion'
   *  Memory: '<S35>/it init1'
   *  MultiPortSwitch: '<S39>/Multiport Switch1'
   *  MultiPortSwitch: '<S40>/Multiport Switch1'
   *  Product: '<S39>/Product'
   *  RelationalOperator: '<S38>/Compare'
   *  Saturate: '<S40>/Saturation'
   *  Sum: '<S35>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2 = ((((-rtb_DataTypeConversion2 *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput / rtb_Fcn6_cy +
    -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput / rtb_Fcn6_cy *
    rtb_MultiportSwitch1_a) + -(real_T)(rtb_Clock < 0.0) * 0.012599870353561554 *
    rtb_Clock * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput * 0.1 + rtb_Gain)) +
    exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_MultiportSwitch1_a) + 4.0121283047687868;

  /* Switch: '<S41>/Switch2' incorporates:
   *  Constant: '<S35>/Constant1'
   *  Memory: '<S35>/Memory2'
   *  RelationalOperator: '<S41>/LowerRelop1'
   *  RelationalOperator: '<S41>/UpperRelop'
   *  Switch: '<S41>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2 > 8.0242566095375736) {
    /* Sum: '<S35>/Add3' incorporates:
     *  Switch: '<S41>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2 = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2 <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput) {
    /* Sum: '<S35>/Add3' incorporates:
     *  Memory: '<S35>/Memory2'
     *  Switch: '<S41>/Switch'
     *  Switch: '<S41>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2 =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput;
  }

  /* End of Switch: '<S41>/Switch2' */

  /* Gain: '<S47>/R2' incorporates:
   *  Gain: '<S47>/R3'
   *  Memory: '<S47>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m;

  /* DiscreteTransferFcn: '<S47>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_d;

  /* DataTypeConversion: '<S47>/Data Type Conversion2' incorporates:
   *  Constant: '<S49>/Constant'
   *  DiscreteTransferFcn: '<S47>/Current filter'
   *  RelationalOperator: '<S49>/Compare'
   */
  rtb_DataTypeConversion2_p = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S47>/int(i)' incorporates:
   *  Memory: '<S47>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_o != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_c;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_p > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_m <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_c;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j = 8189.2799999999806;
  }

  /* Gain: '<S47>/Gain' incorporates:
   *  DiscreteIntegrator: '<S47>/int(i)'
   */
  rtb_Fcn6_cy = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j;

  /* Switch: '<S54>/Switch2' incorporates:
   *  Constant: '<S47>/Constant9'
   *  Gain: '<S47>/R2'
   *  RelationalOperator: '<S54>/LowerRelop1'
   *  RelationalOperator: '<S54>/UpperRelop'
   *  Switch: '<S54>/Switch'
   */
  if (rtb_Fcn6_cy > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Fcn6_cy < 0.0) {
    /* Switch: '<S54>/Switch' incorporates:
     *  Constant: '<S47>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Fcn6_cy;
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Switch: '<S47>/Switch7' incorporates:
   *  Fcn: '<S47>/Fcn9'
   *  Gain: '<S47>/R2'
   *  RelationalOperator: '<S47>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Gain = rtb_Fcn6;
  } else {
    rtb_Gain = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S47>/Switch7' */

  /* Switch: '<S55>/Switch2' incorporates:
   *  RelationalOperator: '<S55>/LowerRelop1'
   */
  if (rtb_Fcn6_cy > rtb_Fcn6) {
    rtb_Fcn6_cy = rtb_Fcn6;
  } else {
    /* Fcn: '<S47>/Fcn6' */
    rtb_Fcn6_m4 = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S55>/Switch' incorporates:
     *  RelationalOperator: '<S55>/UpperRelop'
     */
    if (rtb_Fcn6_cy < rtb_Fcn6_m4) {
      rtb_Fcn6_cy = rtb_Fcn6_m4;
    }

    /* End of Switch: '<S55>/Switch' */
  }

  /* End of Switch: '<S55>/Switch2' */

  /* Saturate: '<S52>/Saturation' incorporates:
   *  MultiPortSwitch: '<S52>/Multiport Switch1'
   */
  if (rtb_Gain >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Gain;
  }

  /* Fcn: '<S47>/E_dyn Discharge' incorporates:
   *  Fcn: '<S47>/E_NL'
   *  Memory: '<S47>/it init1'
   */
  rtb_Fcn6_m4 = DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m -
    rtb_Gain;

  /* Sum: '<S47>/Add3' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S50>/Constant'
   *  DiscreteTransferFcn: '<S47>/Current filter'
   *  Fcn: '<S47>/E_NL'
   *  Fcn: '<S47>/E_dyn Discharge'
   *  Fcn: '<S47>/Fcn5'
   *  Fcn: '<S51>/Charge Li-Ion'
   *  Fcn: '<S52>/Li-Ion'
   *  Memory: '<S47>/it init1'
   *  MultiPortSwitch: '<S51>/Multiport Switch1'
   *  MultiPortSwitch: '<S52>/Multiport Switch1'
   *  Product: '<S51>/Product'
   *  RelationalOperator: '<S50>/Compare'
   *  Saturate: '<S52>/Saturation'
   *  Sum: '<S47>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_g = ((((-rtb_DataTypeConversion2_p *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m / rtb_Fcn6_m4 +
    -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m / rtb_Fcn6_m4 *
    rtb_Gain) + -(real_T)(rtb_Clock < 0.0) * 0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m * 0.1 + rtb_Fcn6_cy))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Gain) + 4.0121283047687868;

  /* Switch: '<S53>/Switch2' incorporates:
   *  Constant: '<S47>/Constant1'
   *  Memory: '<S47>/Memory2'
   *  RelationalOperator: '<S53>/LowerRelop1'
   *  RelationalOperator: '<S53>/UpperRelop'
   *  Switch: '<S53>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_g > 8.0242566095375736) {
    /* Sum: '<S47>/Add3' incorporates:
     *  Switch: '<S53>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_g = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_g <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_i) {
    /* Sum: '<S47>/Add3' incorporates:
     *  Memory: '<S47>/Memory2'
     *  Switch: '<S53>/Switch'
     *  Switch: '<S53>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_g =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_i;
  }

  /* End of Switch: '<S53>/Switch2' */

  /* Gain: '<S59>/R2' incorporates:
   *  Gain: '<S59>/R3'
   *  Memory: '<S59>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n;

  /* DiscreteTransferFcn: '<S59>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_f;

  /* DataTypeConversion: '<S59>/Data Type Conversion2' incorporates:
   *  Constant: '<S61>/Constant'
   *  DiscreteTransferFcn: '<S59>/Current filter'
   *  RelationalOperator: '<S61>/Compare'
   */
  rtb_DataTypeConversion2_n = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S59>/int(i)' incorporates:
   *  Memory: '<S59>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_c != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_m;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_n > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_e <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_m;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o = 8189.2799999999806;
  }

  /* Gain: '<S59>/Gain' incorporates:
   *  DiscreteIntegrator: '<S59>/int(i)'
   */
  rtb_Fcn6_m4 = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o;

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S59>/Constant9'
   *  Gain: '<S59>/R2'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  RelationalOperator: '<S66>/UpperRelop'
   *  Switch: '<S66>/Switch'
   */
  if (rtb_Fcn6_m4 > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Fcn6_m4 < 0.0) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S59>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Fcn6_m4;
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Switch: '<S59>/Switch7' incorporates:
   *  Fcn: '<S59>/Fcn9'
   *  Gain: '<S59>/R2'
   *  RelationalOperator: '<S59>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Fcn6_cy = rtb_Fcn6;
  } else {
    rtb_Fcn6_cy = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S59>/Switch7' */

  /* Switch: '<S67>/Switch2' incorporates:
   *  RelationalOperator: '<S67>/LowerRelop1'
   */
  if (rtb_Fcn6_m4 > rtb_Fcn6) {
    rtb_Fcn6_m4 = rtb_Fcn6;
  } else {
    /* Fcn: '<S59>/Fcn6' */
    rtb_Fcn6_o = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S67>/Switch' incorporates:
     *  RelationalOperator: '<S67>/UpperRelop'
     */
    if (rtb_Fcn6_m4 < rtb_Fcn6_o) {
      rtb_Fcn6_m4 = rtb_Fcn6_o;
    }

    /* End of Switch: '<S67>/Switch' */
  }

  /* End of Switch: '<S67>/Switch2' */

  /* Saturate: '<S64>/Saturation' incorporates:
   *  MultiPortSwitch: '<S64>/Multiport Switch1'
   */
  if (rtb_Fcn6_cy >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Fcn6_cy;
  }

  /* Fcn: '<S59>/E_dyn Discharge' incorporates:
   *  Fcn: '<S59>/E_NL'
   *  Memory: '<S59>/it init1'
   */
  rtb_Fcn6_o = DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n -
    rtb_Fcn6_cy;

  /* Sum: '<S59>/Add3' incorporates:
   *  Constant: '<S59>/Constant'
   *  Constant: '<S62>/Constant'
   *  DiscreteTransferFcn: '<S59>/Current filter'
   *  Fcn: '<S59>/E_NL'
   *  Fcn: '<S59>/E_dyn Discharge'
   *  Fcn: '<S59>/Fcn5'
   *  Fcn: '<S63>/Charge Li-Ion'
   *  Fcn: '<S64>/Li-Ion'
   *  Memory: '<S59>/it init1'
   *  MultiPortSwitch: '<S63>/Multiport Switch1'
   *  MultiPortSwitch: '<S64>/Multiport Switch1'
   *  Product: '<S63>/Product'
   *  RelationalOperator: '<S62>/Compare'
   *  Saturate: '<S64>/Saturation'
   *  Sum: '<S59>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_c = ((((-rtb_DataTypeConversion2_n *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n / rtb_Fcn6_o +
    -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n / rtb_Fcn6_o *
    rtb_Fcn6_cy) + -(real_T)(rtb_Clock < 0.0) * 0.012599870353561554 * rtb_Clock
    * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n * 0.1 + rtb_Fcn6_m4))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Fcn6_cy) + 4.0121283047687868;

  /* Switch: '<S65>/Switch2' incorporates:
   *  Constant: '<S59>/Constant1'
   *  Memory: '<S59>/Memory2'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  RelationalOperator: '<S65>/UpperRelop'
   *  Switch: '<S65>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_c > 8.0242566095375736) {
    /* Sum: '<S59>/Add3' incorporates:
     *  Switch: '<S65>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_c = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_c <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ic) {
    /* Sum: '<S59>/Add3' incorporates:
     *  Memory: '<S59>/Memory2'
     *  Switch: '<S65>/Switch'
     *  Switch: '<S65>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_c =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ic;
  }

  /* End of Switch: '<S65>/Switch2' */

  /* Gain: '<S71>/R2' incorporates:
   *  Gain: '<S71>/R3'
   *  Memory: '<S71>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e;

  /* DiscreteTransferFcn: '<S71>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_e;

  /* DataTypeConversion: '<S71>/Data Type Conversion2' incorporates:
   *  Constant: '<S73>/Constant'
   *  DiscreteTransferFcn: '<S71>/Current filter'
   *  RelationalOperator: '<S73>/Compare'
   */
  rtb_DataTypeConversion2_e = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S71>/int(i)' incorporates:
   *  Memory: '<S71>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_b != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_b;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_e > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_p <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_b;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b = 8189.2799999999806;
  }

  /* Gain: '<S71>/Gain' incorporates:
   *  DiscreteIntegrator: '<S71>/int(i)'
   */
  rtb_Fcn6_o = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b;

  /* Switch: '<S78>/Switch2' incorporates:
   *  Constant: '<S71>/Constant9'
   *  Gain: '<S71>/R2'
   *  RelationalOperator: '<S78>/LowerRelop1'
   *  RelationalOperator: '<S78>/UpperRelop'
   *  Switch: '<S78>/Switch'
   */
  if (rtb_Fcn6_o > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Fcn6_o < 0.0) {
    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S71>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Fcn6_o;
  }

  /* End of Switch: '<S78>/Switch2' */

  /* Switch: '<S71>/Switch7' incorporates:
   *  Fcn: '<S71>/Fcn9'
   *  Gain: '<S71>/R2'
   *  RelationalOperator: '<S71>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Fcn6_m4 = rtb_Fcn6;
  } else {
    rtb_Fcn6_m4 = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S71>/Switch7' */

  /* Switch: '<S79>/Switch2' incorporates:
   *  RelationalOperator: '<S79>/LowerRelop1'
   */
  if (rtb_Fcn6_o > rtb_Fcn6) {
    rtb_Fcn6_o = rtb_Fcn6;
  } else {
    /* Fcn: '<S71>/Fcn6' */
    rtb_Fcn6_e = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S79>/Switch' incorporates:
     *  RelationalOperator: '<S79>/UpperRelop'
     */
    if (rtb_Fcn6_o < rtb_Fcn6_e) {
      rtb_Fcn6_o = rtb_Fcn6_e;
    }

    /* End of Switch: '<S79>/Switch' */
  }

  /* End of Switch: '<S79>/Switch2' */

  /* Saturate: '<S76>/Saturation' incorporates:
   *  MultiPortSwitch: '<S76>/Multiport Switch1'
   */
  if (rtb_Fcn6_m4 >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Fcn6_m4;
  }

  /* Fcn: '<S71>/E_dyn Discharge' incorporates:
   *  Fcn: '<S71>/E_NL'
   *  Memory: '<S71>/it init1'
   */
  rtb_Fcn6_e = DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e -
    rtb_Fcn6_m4;

  /* Sum: '<S71>/Add3' incorporates:
   *  Constant: '<S71>/Constant'
   *  Constant: '<S74>/Constant'
   *  DiscreteTransferFcn: '<S71>/Current filter'
   *  Fcn: '<S71>/E_NL'
   *  Fcn: '<S71>/E_dyn Discharge'
   *  Fcn: '<S71>/Fcn5'
   *  Fcn: '<S75>/Charge Li-Ion'
   *  Fcn: '<S76>/Li-Ion'
   *  Memory: '<S71>/it init1'
   *  MultiPortSwitch: '<S75>/Multiport Switch1'
   *  MultiPortSwitch: '<S76>/Multiport Switch1'
   *  Product: '<S75>/Product'
   *  RelationalOperator: '<S74>/Compare'
   *  Saturate: '<S76>/Saturation'
   *  Sum: '<S71>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_g2 = ((((-rtb_DataTypeConversion2_e *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e / rtb_Fcn6_e +
    -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e / rtb_Fcn6_e *
    rtb_Fcn6_m4) + -(real_T)(rtb_Clock < 0.0) * 0.012599870353561554 * rtb_Clock
    * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e * 0.1 + rtb_Fcn6_o))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Fcn6_m4) + 4.0121283047687868;

  /* Switch: '<S77>/Switch2' incorporates:
   *  Constant: '<S71>/Constant1'
   *  Memory: '<S71>/Memory2'
   *  RelationalOperator: '<S77>/LowerRelop1'
   *  RelationalOperator: '<S77>/UpperRelop'
   *  Switch: '<S77>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_g2 > 8.0242566095375736) {
    /* Sum: '<S71>/Add3' incorporates:
     *  Switch: '<S77>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_g2 = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_g2 <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_e) {
    /* Sum: '<S71>/Add3' incorporates:
     *  Memory: '<S71>/Memory2'
     *  Switch: '<S77>/Switch'
     *  Switch: '<S77>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_g2 =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_e;
  }

  /* End of Switch: '<S77>/Switch2' */

  /* Gain: '<S83>/R2' incorporates:
   *  Gain: '<S83>/R3'
   *  Memory: '<S83>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf;

  /* DiscreteTransferFcn: '<S83>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_h;

  /* DataTypeConversion: '<S83>/Data Type Conversion2' incorporates:
   *  Constant: '<S85>/Constant'
   *  DiscreteTransferFcn: '<S83>/Current filter'
   *  RelationalOperator: '<S85>/Compare'
   */
  rtb_DataTypeConversion2_j = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S83>/int(i)' incorporates:
   *  Memory: '<S83>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_f != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_l;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_j > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_l <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_l;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g = 8189.2799999999806;
  }

  /* Gain: '<S83>/Gain' incorporates:
   *  DiscreteIntegrator: '<S83>/int(i)'
   */
  rtb_Fcn6_e = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g;

  /* Switch: '<S90>/Switch2' incorporates:
   *  Constant: '<S83>/Constant9'
   *  Gain: '<S83>/R2'
   *  RelationalOperator: '<S90>/LowerRelop1'
   *  RelationalOperator: '<S90>/UpperRelop'
   *  Switch: '<S90>/Switch'
   */
  if (rtb_Fcn6_e > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Fcn6_e < 0.0) {
    /* Switch: '<S90>/Switch' incorporates:
     *  Constant: '<S83>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Fcn6_e;
  }

  /* End of Switch: '<S90>/Switch2' */

  /* Switch: '<S83>/Switch7' incorporates:
   *  Fcn: '<S83>/Fcn9'
   *  Gain: '<S83>/R2'
   *  RelationalOperator: '<S83>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Fcn6_o = rtb_Fcn6;
  } else {
    rtb_Fcn6_o = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S83>/Switch7' */

  /* Switch: '<S91>/Switch2' incorporates:
   *  RelationalOperator: '<S91>/LowerRelop1'
   */
  if (rtb_Fcn6_e > rtb_Fcn6) {
    rtb_Fcn6_e = rtb_Fcn6;
  } else {
    /* Fcn: '<S83>/Fcn6' */
    rtb_Fcn6_g = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S91>/Switch' incorporates:
     *  RelationalOperator: '<S91>/UpperRelop'
     */
    if (rtb_Fcn6_e < rtb_Fcn6_g) {
      rtb_Fcn6_e = rtb_Fcn6_g;
    }

    /* End of Switch: '<S91>/Switch' */
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Saturate: '<S88>/Saturation' incorporates:
   *  MultiPortSwitch: '<S88>/Multiport Switch1'
   */
  if (rtb_Fcn6_o >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Fcn6_o;
  }

  /* Fcn: '<S83>/E_dyn Discharge' incorporates:
   *  Fcn: '<S83>/E_NL'
   *  Memory: '<S83>/it init1'
   */
  rtb_Fcn6_g = DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf -
    rtb_Fcn6_o;

  /* Sum: '<S83>/Add3' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S86>/Constant'
   *  DiscreteTransferFcn: '<S83>/Current filter'
   *  Fcn: '<S83>/E_NL'
   *  Fcn: '<S83>/E_dyn Discharge'
   *  Fcn: '<S83>/Fcn5'
   *  Fcn: '<S87>/Charge Li-Ion'
   *  Fcn: '<S88>/Li-Ion'
   *  Memory: '<S83>/it init1'
   *  MultiPortSwitch: '<S87>/Multiport Switch1'
   *  MultiPortSwitch: '<S88>/Multiport Switch1'
   *  Product: '<S87>/Product'
   *  RelationalOperator: '<S86>/Compare'
   *  Saturate: '<S88>/Saturation'
   *  Sum: '<S83>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_h = ((((-rtb_DataTypeConversion2_j *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf / rtb_Fcn6_g +
    -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf / rtb_Fcn6_g *
    rtb_Fcn6_o) + -(real_T)(rtb_Clock < 0.0) * 0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf * 0.1 + rtb_Fcn6_e))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Fcn6_o) + 4.0121283047687868;

  /* Switch: '<S89>/Switch2' incorporates:
   *  Constant: '<S83>/Constant1'
   *  Memory: '<S83>/Memory2'
   *  RelationalOperator: '<S89>/LowerRelop1'
   *  RelationalOperator: '<S89>/UpperRelop'
   *  Switch: '<S89>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_h > 8.0242566095375736) {
    /* Sum: '<S83>/Add3' incorporates:
     *  Switch: '<S89>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_h = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_h <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_g) {
    /* Sum: '<S83>/Add3' incorporates:
     *  Memory: '<S83>/Memory2'
     *  Switch: '<S89>/Switch'
     *  Switch: '<S89>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_h =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_g;
  }

  /* End of Switch: '<S89>/Switch2' */

  /* Gain: '<S95>/R2' incorporates:
   *  Gain: '<S95>/R3'
   *  Memory: '<S95>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j;

  /* DiscreteTransferFcn: '<S95>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_c;

  /* DataTypeConversion: '<S95>/Data Type Conversion2' incorporates:
   *  Constant: '<S97>/Constant'
   *  DiscreteTransferFcn: '<S95>/Current filter'
   *  RelationalOperator: '<S97>/Compare'
   */
  rtb_DataTypeConversion2_d = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S95>/int(i)' incorporates:
   *  Memory: '<S95>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_j != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_f;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_d > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_n <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_f;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p = 8189.2799999999806;
  }

  /* Gain: '<S95>/Gain' incorporates:
   *  DiscreteIntegrator: '<S95>/int(i)'
   */
  rtb_Fcn6_g = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p;

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S95>/Constant9'
   *  Gain: '<S95>/R2'
   *  RelationalOperator: '<S102>/LowerRelop1'
   *  RelationalOperator: '<S102>/UpperRelop'
   *  Switch: '<S102>/Switch'
   */
  if (rtb_Fcn6_g > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Fcn6_g < 0.0) {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S95>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Fcn6_g;
  }

  /* End of Switch: '<S102>/Switch2' */

  /* Switch: '<S95>/Switch7' incorporates:
   *  Fcn: '<S95>/Fcn9'
   *  Gain: '<S95>/R2'
   *  RelationalOperator: '<S95>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Fcn6_e = rtb_Fcn6;
  } else {
    rtb_Fcn6_e = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S95>/Switch7' */

  /* Switch: '<S103>/Switch2' incorporates:
   *  RelationalOperator: '<S103>/LowerRelop1'
   */
  if (rtb_Fcn6_g > rtb_Fcn6) {
    rtb_Fcn6_g = rtb_Fcn6;
  } else {
    /* Fcn: '<S95>/Fcn6' */
    rtb_DataTypeConversion1_h = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S103>/Switch' incorporates:
     *  RelationalOperator: '<S103>/UpperRelop'
     */
    if (rtb_Fcn6_g < rtb_DataTypeConversion1_h) {
      rtb_Fcn6_g = rtb_DataTypeConversion1_h;
    }

    /* End of Switch: '<S103>/Switch' */
  }

  /* End of Switch: '<S103>/Switch2' */

  /* Saturate: '<S100>/Saturation' incorporates:
   *  MultiPortSwitch: '<S100>/Multiport Switch1'
   */
  if (rtb_Fcn6_e >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Fcn6_e;
  }

  /* Fcn: '<S95>/E_dyn Discharge' incorporates:
   *  Fcn: '<S95>/E_NL'
   *  Memory: '<S95>/it init1'
   */
  rtb_DataTypeConversion1_h =
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j - rtb_Fcn6_e;

  /* Sum: '<S95>/Add3' incorporates:
   *  Constant: '<S95>/Constant'
   *  Constant: '<S98>/Constant'
   *  DiscreteTransferFcn: '<S95>/Current filter'
   *  Fcn: '<S100>/Li-Ion'
   *  Fcn: '<S95>/E_NL'
   *  Fcn: '<S95>/E_dyn Discharge'
   *  Fcn: '<S95>/Fcn5'
   *  Fcn: '<S99>/Charge Li-Ion'
   *  Memory: '<S95>/it init1'
   *  MultiPortSwitch: '<S100>/Multiport Switch1'
   *  MultiPortSwitch: '<S99>/Multiport Switch1'
   *  Product: '<S99>/Product'
   *  RelationalOperator: '<S98>/Compare'
   *  Saturate: '<S100>/Saturation'
   *  Sum: '<S95>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_n = ((((-rtb_DataTypeConversion2_d *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j /
    rtb_DataTypeConversion1_h + -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j /
    rtb_DataTypeConversion1_h * rtb_Fcn6_e) + -(real_T)(rtb_Clock < 0.0) *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j * 0.1 + rtb_Fcn6_g))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Fcn6_e) + 4.0121283047687868;

  /* Switch: '<S101>/Switch2' incorporates:
   *  Constant: '<S95>/Constant1'
   *  Memory: '<S95>/Memory2'
   *  RelationalOperator: '<S101>/LowerRelop1'
   *  RelationalOperator: '<S101>/UpperRelop'
   *  Switch: '<S101>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_n > 8.0242566095375736) {
    /* Sum: '<S95>/Add3' incorporates:
     *  Switch: '<S101>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_n = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_n <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ix) {
    /* Sum: '<S95>/Add3' incorporates:
     *  Memory: '<S95>/Memory2'
     *  Switch: '<S101>/Switch'
     *  Switch: '<S101>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_n =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ix;
  }

  /* End of Switch: '<S101>/Switch2' */

  /* Gain: '<S107>/R2' incorporates:
   *  Gain: '<S107>/R3'
   *  Memory: '<S107>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d;

  /* DiscreteTransferFcn: '<S107>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_i;

  /* DataTypeConversion: '<S107>/Data Type Conversion2' incorporates:
   *  Constant: '<S109>/Constant'
   *  DiscreteTransferFcn: '<S107>/Current filter'
   *  RelationalOperator: '<S109>/Compare'
   */
  rtb_DataTypeConversion2_g = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S107>/int(i)' incorporates:
   *  Memory: '<S107>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_p != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_k;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_g > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_k <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_k;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e = 8189.2799999999806;
  }

  /* Gain: '<S107>/Gain' incorporates:
   *  DiscreteIntegrator: '<S107>/int(i)'
   */
  rtb_Gain_io = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e;

  /* Switch: '<S114>/Switch2' incorporates:
   *  Constant: '<S107>/Constant9'
   *  Gain: '<S107>/R2'
   *  RelationalOperator: '<S114>/LowerRelop1'
   *  RelationalOperator: '<S114>/UpperRelop'
   *  Switch: '<S114>/Switch'
   */
  if (rtb_Gain_io > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Gain_io < 0.0) {
    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S107>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Gain_io;
  }

  /* End of Switch: '<S114>/Switch2' */

  /* Switch: '<S107>/Switch7' incorporates:
   *  Fcn: '<S107>/Fcn9'
   *  Gain: '<S107>/R2'
   *  RelationalOperator: '<S107>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Fcn6_g = rtb_Fcn6;
  } else {
    rtb_Fcn6_g = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S107>/Switch7' */

  /* Switch: '<S115>/Switch2' incorporates:
   *  RelationalOperator: '<S115>/LowerRelop1'
   */
  if (rtb_Gain_io > rtb_Fcn6) {
    rtb_Gain_io = rtb_Fcn6;
  } else {
    /* Fcn: '<S107>/Fcn6' */
    rtb_DataTypeConversion1_h = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S115>/Switch' incorporates:
     *  RelationalOperator: '<S115>/UpperRelop'
     */
    if (rtb_Gain_io < rtb_DataTypeConversion1_h) {
      rtb_Gain_io = rtb_DataTypeConversion1_h;
    }

    /* End of Switch: '<S115>/Switch' */
  }

  /* End of Switch: '<S115>/Switch2' */

  /* Saturate: '<S112>/Saturation' incorporates:
   *  MultiPortSwitch: '<S112>/Multiport Switch1'
   */
  if (rtb_Fcn6_g >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Fcn6_g;
  }

  /* Fcn: '<S107>/E_dyn Discharge' incorporates:
   *  Fcn: '<S107>/E_NL'
   *  Memory: '<S107>/it init1'
   */
  rtb_DataTypeConversion1_h =
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d - rtb_Fcn6_g;

  /* Sum: '<S107>/Add3' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S110>/Constant'
   *  DiscreteTransferFcn: '<S107>/Current filter'
   *  Fcn: '<S107>/E_NL'
   *  Fcn: '<S107>/E_dyn Discharge'
   *  Fcn: '<S107>/Fcn5'
   *  Fcn: '<S111>/Charge Li-Ion'
   *  Fcn: '<S112>/Li-Ion'
   *  Memory: '<S107>/it init1'
   *  MultiPortSwitch: '<S111>/Multiport Switch1'
   *  MultiPortSwitch: '<S112>/Multiport Switch1'
   *  Product: '<S111>/Product'
   *  RelationalOperator: '<S110>/Compare'
   *  Saturate: '<S112>/Saturation'
   *  Sum: '<S107>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_f = ((((-rtb_DataTypeConversion2_g *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d /
    rtb_DataTypeConversion1_h + -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d /
    rtb_DataTypeConversion1_h * rtb_Fcn6_g) + -(real_T)(rtb_Clock < 0.0) *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d * 0.1 + rtb_Gain_io))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Fcn6_g) + 4.0121283047687868;

  /* Switch: '<S113>/Switch2' incorporates:
   *  Constant: '<S107>/Constant1'
   *  Memory: '<S107>/Memory2'
   *  RelationalOperator: '<S113>/LowerRelop1'
   *  RelationalOperator: '<S113>/UpperRelop'
   *  Switch: '<S113>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_f > 8.0242566095375736) {
    /* Sum: '<S107>/Add3' incorporates:
     *  Switch: '<S113>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_f = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_f <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ey) {
    /* Sum: '<S107>/Add3' incorporates:
     *  Memory: '<S107>/Memory2'
     *  Switch: '<S113>/Switch'
     *  Switch: '<S113>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_f =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ey;
  }

  /* End of Switch: '<S113>/Switch2' */

  /* Gain: '<S119>/R2' incorporates:
   *  Gain: '<S119>/R3'
   *  Memory: '<S119>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g;

  /* DiscreteTransferFcn: '<S119>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_n;

  /* DataTypeConversion: '<S119>/Data Type Conversion2' incorporates:
   *  Constant: '<S121>/Constant'
   *  DiscreteTransferFcn: '<S119>/Current filter'
   *  RelationalOperator: '<S121>/Compare'
   */
  rtb_DataTypeConversion2_jw = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S119>/int(i)' incorporates:
   *  Memory: '<S119>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_o1 != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_g;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_jw > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_o <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_g;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo = 8189.2799999999806;
  }

  /* Gain: '<S119>/Gain' incorporates:
   *  DiscreteIntegrator: '<S119>/int(i)'
   */
  rtb_Gain_d = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo;

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S119>/Constant9'
   *  Gain: '<S119>/R2'
   *  RelationalOperator: '<S126>/LowerRelop1'
   *  RelationalOperator: '<S126>/UpperRelop'
   *  Switch: '<S126>/Switch'
   */
  if (rtb_Gain_d > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Gain_d < 0.0) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S119>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Gain_d;
  }

  /* End of Switch: '<S126>/Switch2' */

  /* Switch: '<S119>/Switch7' incorporates:
   *  Fcn: '<S119>/Fcn9'
   *  Gain: '<S119>/R2'
   *  RelationalOperator: '<S119>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_Gain_io = rtb_Fcn6;
  } else {
    rtb_Gain_io = rtb_DataTypeConversion1_h;
  }

  /* End of Switch: '<S119>/Switch7' */

  /* Switch: '<S127>/Switch2' incorporates:
   *  RelationalOperator: '<S127>/LowerRelop1'
   */
  if (rtb_Gain_d > rtb_Fcn6) {
    rtb_Gain_d = rtb_Fcn6;
  } else {
    /* Fcn: '<S119>/Fcn6' */
    rtb_DataTypeConversion1_h = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S127>/Switch' incorporates:
     *  RelationalOperator: '<S127>/UpperRelop'
     */
    if (rtb_Gain_d < rtb_DataTypeConversion1_h) {
      rtb_Gain_d = rtb_DataTypeConversion1_h;
    }

    /* End of Switch: '<S127>/Switch' */
  }

  /* End of Switch: '<S127>/Switch2' */

  /* Saturate: '<S124>/Saturation' incorporates:
   *  MultiPortSwitch: '<S124>/Multiport Switch1'
   */
  if (rtb_Gain_io >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_Gain_io;
  }

  /* Fcn: '<S119>/E_dyn Discharge' incorporates:
   *  Fcn: '<S119>/E_NL'
   *  Memory: '<S119>/it init1'
   */
  rtb_DataTypeConversion1_h =
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g - rtb_Gain_io;

  /* Sum: '<S119>/Add3' incorporates:
   *  Constant: '<S119>/Constant'
   *  Constant: '<S122>/Constant'
   *  DiscreteTransferFcn: '<S119>/Current filter'
   *  Fcn: '<S119>/E_NL'
   *  Fcn: '<S119>/E_dyn Discharge'
   *  Fcn: '<S119>/Fcn5'
   *  Fcn: '<S123>/Charge Li-Ion'
   *  Fcn: '<S124>/Li-Ion'
   *  Memory: '<S119>/it init1'
   *  MultiPortSwitch: '<S123>/Multiport Switch1'
   *  MultiPortSwitch: '<S124>/Multiport Switch1'
   *  Product: '<S123>/Product'
   *  RelationalOperator: '<S122>/Compare'
   *  Saturate: '<S124>/Saturation'
   *  Sum: '<S119>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_gw = ((((-rtb_DataTypeConversion2_jw *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g /
    rtb_DataTypeConversion1_h + -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g /
    rtb_DataTypeConversion1_h * rtb_Gain_io) + -(real_T)(rtb_Clock < 0.0) *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g * 0.1 + rtb_Gain_d))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_Gain_io) + 4.0121283047687868;

  /* Switch: '<S125>/Switch2' incorporates:
   *  Constant: '<S119>/Constant1'
   *  Memory: '<S119>/Memory2'
   *  RelationalOperator: '<S125>/LowerRelop1'
   *  RelationalOperator: '<S125>/UpperRelop'
   *  Switch: '<S125>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_gw > 8.0242566095375736) {
    /* Sum: '<S119>/Add3' incorporates:
     *  Switch: '<S125>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_gw = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_gw <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ge) {
    /* Sum: '<S119>/Add3' incorporates:
     *  Memory: '<S119>/Memory2'
     *  Switch: '<S125>/Switch'
     *  Switch: '<S125>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_gw =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ge;
  }

  /* End of Switch: '<S125>/Switch2' */

  /* Gain: '<S131>/R2' incorporates:
   *  Gain: '<S131>/R3'
   *  Memory: '<S131>/it init1'
   */
  rtb_Fcn6 = 0.9999 * DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c;

  /* DiscreteTransferFcn: '<S131>/Current filter' */
  rtb_Clock = 9.999500016666385E-5 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_o;

  /* DataTypeConversion: '<S131>/Data Type Conversion2' incorporates:
   *  Constant: '<S133>/Constant'
   *  DiscreteTransferFcn: '<S131>/Current filter'
   *  RelationalOperator: '<S133>/Compare'
   */
  rtb_DataTypeConversion2_c = (rtb_Clock > 0.0);

  /* DiscreteIntegrator: '<S131>/int(i)' incorporates:
   *  Memory: '<S131>/it init'
   */
  if (DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_a != 0) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_cu;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz = 8189.2799999999806;
    }
  }

  if ((rtb_DataTypeConversion2_c > 0.0) &&
      (DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_c <= 0)) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz =
      DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_cu;
    if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz >= 8189.2799999999806) {
      DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz = 8189.2799999999806;
    }
  }

  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz = 8189.2799999999806;
  }

  /* Gain: '<S131>/Gain' incorporates:
   *  DiscreteIntegrator: '<S131>/int(i)'
   */
  rtb_Gain_d = 0.00027777777777777778 *
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz;

  /* Switch: '<S138>/Switch2' incorporates:
   *  Constant: '<S131>/Constant9'
   *  Gain: '<S131>/R2'
   *  RelationalOperator: '<S138>/LowerRelop1'
   *  RelationalOperator: '<S138>/UpperRelop'
   *  Switch: '<S138>/Switch'
   */
  if (rtb_Gain_d > rtb_Fcn6) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  } else if (rtb_Gain_d < 0.0) {
    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S131>/Constant9'
     */
    rtb_DataTypeConversion1_h = 0.0;
  } else {
    rtb_DataTypeConversion1_h = rtb_Gain_d;
  }

  /* End of Switch: '<S138>/Switch2' */

  /* Switch: '<S131>/Switch7' incorporates:
   *  Fcn: '<S131>/Fcn9'
   *  Gain: '<S131>/R2'
   *  RelationalOperator: '<S131>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.96711798839458663 / 0.9999 <=
      rtb_DataTypeConversion1_h) {
    rtb_DataTypeConversion1_h = rtb_Fcn6;
  }

  /* End of Switch: '<S131>/Switch7' */

  /* Switch: '<S139>/Switch2' incorporates:
   *  RelationalOperator: '<S139>/LowerRelop1'
   */
  if (rtb_Gain_d > rtb_Fcn6) {
    rtb_Gain_d = rtb_Fcn6;
  } else {
    /* Fcn: '<S131>/Fcn6' */
    rtb_Fcn6 = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S139>/Switch' incorporates:
     *  RelationalOperator: '<S139>/UpperRelop'
     */
    if (rtb_Gain_d < rtb_Fcn6) {
      rtb_Gain_d = rtb_Fcn6;
    }

    /* End of Switch: '<S139>/Switch' */
  }

  /* End of Switch: '<S139>/Switch2' */

  /* Saturate: '<S136>/Saturation' incorporates:
   *  MultiPortSwitch: '<S136>/Multiport Switch1'
   */
  if (rtb_DataTypeConversion1_h >= 2.2000000000000006) {
    rtb_Fcn6 = 2.2000000000000006;
  } else {
    rtb_Fcn6 = rtb_DataTypeConversion1_h;
  }

  /* Fcn: '<S131>/E_dyn Discharge' incorporates:
   *  Fcn: '<S131>/E_NL'
   *  Memory: '<S131>/it init1'
   */
  rtb_SOC_l = DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c -
    rtb_DataTypeConversion1_h;

  /* Sum: '<S131>/Add3' incorporates:
   *  Constant: '<S131>/Constant'
   *  Constant: '<S134>/Constant'
   *  DiscreteTransferFcn: '<S131>/Current filter'
   *  Fcn: '<S131>/E_NL'
   *  Fcn: '<S131>/E_dyn Discharge'
   *  Fcn: '<S131>/Fcn5'
   *  Fcn: '<S135>/Charge Li-Ion'
   *  Fcn: '<S136>/Li-Ion'
   *  Memory: '<S131>/it init1'
   *  MultiPortSwitch: '<S135>/Multiport Switch1'
   *  MultiPortSwitch: '<S136>/Multiport Switch1'
   *  Product: '<S135>/Product'
   *  RelationalOperator: '<S134>/Compare'
   *  Saturate: '<S136>/Saturation'
   *  Sum: '<S131>/Add2'
   */
  DC_DC_source_based_matrix_swi_B.Switch2_cb = ((((-rtb_DataTypeConversion2_c *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c / rtb_SOC_l +
    -0.012599870353561554 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c / rtb_SOC_l *
    rtb_DataTypeConversion1_h) + -(real_T)(rtb_Clock < 0.0) *
    0.012599870353561554 * rtb_Clock *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c /
    (DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c * 0.1 + rtb_Gain_d))
    + exp(-27.755430410297663 * rtb_Fcn6) * 0.31071106332851506) + -0.0 *
    rtb_DataTypeConversion1_h) + 4.0121283047687868;

  /* Switch: '<S137>/Switch2' incorporates:
   *  Constant: '<S131>/Constant1'
   *  Memory: '<S131>/Memory2'
   *  RelationalOperator: '<S137>/LowerRelop1'
   *  RelationalOperator: '<S137>/UpperRelop'
   *  Switch: '<S137>/Switch'
   */
  if (DC_DC_source_based_matrix_swi_B.Switch2_cb > 8.0242566095375736) {
    /* Sum: '<S131>/Add3' incorporates:
     *  Switch: '<S137>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_cb = 8.0242566095375736;
  } else if (DC_DC_source_based_matrix_swi_B.Switch2_cb <
             DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_d) {
    /* Sum: '<S131>/Add3' incorporates:
     *  Memory: '<S131>/Memory2'
     *  Switch: '<S137>/Switch'
     *  Switch: '<S137>/Switch2'
     */
    DC_DC_source_based_matrix_swi_B.Switch2_cb =
      DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_d;
  }

  /* End of Switch: '<S137>/Switch2' */

  /* Relay: '<S10>/Relay' incorporates:
   *  Switch: '<S10>/Switch'
   */
  DC_DC_source_based_matrix_sw_DW.Relay_Mode =
    ((DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput >= 3.5) ||
     ((!(DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput <= 2.0)) &&
      DC_DC_source_based_matrix_sw_DW.Relay_Mode));

  /* DataTypeConversion: '<S184>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/e'
   */
  DC_DC_source_based_matrix_swi_B.DataTypeConversion1 = true;

  /* Clock: '<S184>/Clock' */
  rtb_Clock = DC_DC_source_based_matrix_sw_M->Timing.t[0];

  /* Outputs for Enabled SubSystem: '<S184>/ON Delay' incorporates:
   *  EnablePort: '<S186>/Enable'
   */
  if (DC_DC_source_based_matri_ConstB.RelationalOperator1) {
    DC_DC_source_based_matrix_sw_DW.ONDelay_MODE = true;

    /* Outputs for Enabled SubSystem: '<S197>/POSITIVE Edge' */
    /* Memory: '<S197>/Memory' */
    DC_DC_source_based_POSITIVEEdge
      (DC_DC_source_based_matri_ConstB.MultiportSwitch[0], true,
       DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_p,
       &DC_DC_source_based_matrix_swi_B.RelationalOperator1,
       &DC_DC_source_based_matrix_sw_DW.POSITIVEEdge_d);

    /* End of Outputs for SubSystem: '<S197>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S197>/NEGATIVE Edge' */
    DC_DC_source_based_NEGATIVEEdge
      (DC_DC_source_based_matri_ConstB.MultiportSwitch[1], true,
       DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_p,
       &DC_DC_source_based_matrix_swi_B.RelationalOperator1_g,
       &DC_DC_source_based_matrix_sw_DW.NEGATIVEEdge_b);

    /* End of Outputs for SubSystem: '<S197>/NEGATIVE Edge' */

    /* Logic: '<S197>/Logical Operator1' */
    LogicalOperator1 = (DC_DC_source_based_matrix_swi_B.RelationalOperator1 ||
                        DC_DC_source_based_matrix_swi_B.RelationalOperator1_g);

    /* Switch: '<S202>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S202>/Switch' */
      DC_DC_source_based_matrix_swi_B.Switch = rtb_Clock;
    } else {
      /* Switch: '<S202>/Switch' incorporates:
       *  Memory: '<S202>/IC=ic'
       */
      DC_DC_source_based_matrix_swi_B.Switch =
        DC_DC_source_based_matrix_sw_DW.ICic_PreviousInput;
    }

    /* End of Switch: '<S202>/Switch' */

    /* Logic: '<S186>/Logical Operator2' incorporates:
     *  Constant: '<S184>/Constant1'
     *  RelationalOperator: '<S186>/Relational Operator'
     *  Sum: '<S186>/Sum'
     */
    DC_DC_source_based_matrix_swi_B.LogicalOperator2 = (rtb_Clock >=
      DC_DC_source_based_matrix_swi_B.Switch + 1.0);

    /* Outputs for Triggered SubSystem: '<S198>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S201>/Trigger'
     */
    DC_DC_source_based_matr_PrevZCX.TriggeredSubsystem_Trig_ZCE =
      LogicalOperator1;

    /* End of Outputs for SubSystem: '<S198>/Triggered Subsystem' */
  } else if (DC_DC_source_based_matrix_sw_DW.ONDelay_MODE) {
    /* Disable for Enabled SubSystem: '<S197>/POSITIVE Edge' */
    if (DC_DC_source_based_matrix_sw_DW.POSITIVEEdge_d.POSITIVEEdge_MODE) {
      DC_DC_sour_POSITIVEEdge_Disable
        (&DC_DC_source_based_matrix_sw_DW.POSITIVEEdge_d);
    }

    /* End of Disable for SubSystem: '<S197>/POSITIVE Edge' */

    /* Disable for Enabled SubSystem: '<S197>/NEGATIVE Edge' */
    if (DC_DC_source_based_matrix_sw_DW.NEGATIVEEdge_b.NEGATIVEEdge_MODE) {
      DC_DC_sour_NEGATIVEEdge_Disable
        (&DC_DC_source_based_matrix_sw_DW.NEGATIVEEdge_b);
    }

    /* End of Disable for SubSystem: '<S197>/NEGATIVE Edge' */
    DC_DC_source_based_matrix_sw_DW.ONDelay_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S184>/ON Delay' */

  /* Outputs for Enabled SubSystem: '<S184>/OFF Delay' incorporates:
   *  EnablePort: '<S185>/Enable'
   */
  if (DC_DC_source_based_matri_ConstB.LogicalOperator2) {
    DC_DC_source_based_matrix_sw_DW.OFFDelay_MODE = true;

    /* Outputs for Enabled SubSystem: '<S189>/POSITIVE Edge' */
    /* Memory: '<S189>/Memory' */
    DC_DC_source_based_POSITIVEEdge
      (DC_DC_source_based_matri_ConstB.MultiportSwitch_e[0], true,
       DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_a,
       &DC_DC_source_based_matrix_swi_B.RelationalOperator1_gk,
       &DC_DC_source_based_matrix_sw_DW.POSITIVEEdge);

    /* End of Outputs for SubSystem: '<S189>/POSITIVE Edge' */

    /* Outputs for Enabled SubSystem: '<S189>/NEGATIVE Edge' */
    DC_DC_source_based_NEGATIVEEdge
      (DC_DC_source_based_matri_ConstB.MultiportSwitch_e[1], true,
       DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_a,
       &DC_DC_source_based_matrix_swi_B.RelationalOperator1_f,
       &DC_DC_source_based_matrix_sw_DW.NEGATIVEEdge);

    /* End of Outputs for SubSystem: '<S189>/NEGATIVE Edge' */

    /* Logic: '<S189>/Logical Operator1' */
    LogicalOperator1 = (DC_DC_source_based_matrix_swi_B.RelationalOperator1_gk ||
                        DC_DC_source_based_matrix_swi_B.RelationalOperator1_f);

    /* Switch: '<S194>/Switch' */
    if (LogicalOperator1) {
      /* Switch: '<S194>/Switch' */
      DC_DC_source_based_matrix_swi_B.Switch_e = rtb_Clock;
    } else {
      /* Switch: '<S194>/Switch' incorporates:
       *  Memory: '<S194>/IC=ic'
       */
      DC_DC_source_based_matrix_swi_B.Switch_e =
        DC_DC_source_based_matrix_sw_DW.ICic_PreviousInput_a;
    }

    /* End of Switch: '<S194>/Switch' */

    /* Logic: '<S185>/Logical Operator2' incorporates:
     *  Logic: '<S185>/Logical Operator1'
     */
    DC_DC_source_based_matrix_swi_B.LogicalOperator2_i = true;

    /* Outputs for Triggered SubSystem: '<S190>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S193>/Trigger'
     */
    DC_DC_source_based_matr_PrevZCX.TriggeredSubsystem_Trig_ZCE_i =
      LogicalOperator1;

    /* End of Outputs for SubSystem: '<S190>/Triggered Subsystem' */
  } else if (DC_DC_source_based_matrix_sw_DW.OFFDelay_MODE) {
    /* Disable for Enabled SubSystem: '<S189>/POSITIVE Edge' */
    if (DC_DC_source_based_matrix_sw_DW.POSITIVEEdge.POSITIVEEdge_MODE) {
      DC_DC_sour_POSITIVEEdge_Disable
        (&DC_DC_source_based_matrix_sw_DW.POSITIVEEdge);
    }

    /* End of Disable for SubSystem: '<S189>/POSITIVE Edge' */

    /* Disable for Enabled SubSystem: '<S189>/NEGATIVE Edge' */
    if (DC_DC_source_based_matrix_sw_DW.NEGATIVEEdge.NEGATIVEEdge_MODE) {
      DC_DC_sour_NEGATIVEEdge_Disable
        (&DC_DC_source_based_matrix_sw_DW.NEGATIVEEdge);
    }

    /* End of Disable for SubSystem: '<S189>/NEGATIVE Edge' */
    DC_DC_source_based_matrix_sw_DW.OFFDelay_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S184>/OFF Delay' */

  /* MATLAB Function: '<S31>/battery_selector' incorporates:
   *  Memory: '<S31>/Memory'
   *  Memory: '<S31>/Memory1'
   */
  rtb_Clock = 0.0;
  rtb_Fcn6 = 0.0;
  if ((DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_f[0] <=
       DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_f[1]) &&
      (DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput_n[0] <=
       DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput_n[1])) {
    rtb_Clock = DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput_n[0];
    rtb_Fcn6 = DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput_n[1];
  }

  /* End of MATLAB Function: '<S31>/battery_selector' */

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  Logic: '<S10>/AND'
   *  Logic: '<S184>/Logical Operator1'
   *  Relay: '<S10>/Relay'
   */
  if (DC_DC_source_based_matrix_sw_DW.Relay_Mode &&
      (DC_DC_source_based_matrix_swi_B.LogicalOperator2 ||
       DC_DC_source_based_matrix_swi_B.LogicalOperator2_i)) {
    DC_DC_source_based_matrix_swi_B.current_left = -0.0;
    if (DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput != 0.0) {
      DC_DC_source_based_matrix_swi_B.current_right = -(-0.0 *
        DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput /
        DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput);
    } else {
      DC_DC_source_based_matrix_swi_B.current_right = 0.0;
    }
  } else {
    DC_DC_source_based_matrix_swi_B.current_left = 0.0;
    DC_DC_source_based_matrix_swi_B.current_right = 0.0;
  }

  /* End of MATLAB Function: '<S10>/MATLAB Function' */

  /* S-Function (sfun_spssw_discc): '<S207>/State-Space' incorporates:
   *  Constant: '<S210>/SwitchCurrents'
   */

  /* S-Function block: <S207>/State-Space */
  {
    real_T accum;

    /* Circuit has switches */
    int_T *switch_status = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS;
    int_T *switch_status_init = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;
    int_T *SwitchChange = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SW_CHG;
    int_T *gState = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.G_STATE;
    real_T *yswitch = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.Y_SWITCH;
    int_T *switchTypes = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_TYPES;
    int_T *idxOutSw = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.IDX_OUT_SW;
    real_T *DxCol = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DX_COL;
    real_T *tmp2 = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.TMP2;
    real_T *uswlast = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.USWLAST;
    int_T newState;
    int_T swChanged = 0;
    int loopsToDo = 20;
    real_T temp;

    /* keep an initial copy of switch_status*/
    memcpy(switch_status_init, switch_status, 18 * sizeof(int_T));
    memcpy(uswlast, &DC_DC_source_based_matrix_swi_B.StateSpace_o1[0], 18*sizeof
           (real_T));
    do {
      if (loopsToDo == 1) {            /* Need to reset some variables: */
        swChanged = 0;

        /* return to the original switch status*/
        {
          int_T i1;
          for (i1=0; i1 < 18; i1++) {
            swChanged = ((SwitchChange[i1] = switch_status_init[i1] -
                          switch_status[i1]) != 0) ? 1 : swChanged;
            switch_status[i1] = switch_status_init[i1];
          }
        }
      } else {
        /*
         * Compute outputs:
         * ---------------
         */
        real_T *Ds = (real_T*)
          DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DS;

        {
          int_T i1;
          real_T *y0 = &DC_DC_source_based_matrix_swi_B.StateSpace_o1[0];
          for (i1=0; i1 < 28; i1++) {
            accum = 0.0;

            {
              int_T i2;
              const real_T *u0 = rtCP_SwitchCurrents_Value;
              for (i2=0; i2 < 18; i2++) {
                accum += *(Ds++) * u0[i2];
              }

              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_g;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_c;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_g2;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_h;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_n;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_f;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_gw;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_cb;
              accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.current_left;
            }

            y0[i1] = accum;
          }
        }

        swChanged = 0;

        {
          int_T i1;
          real_T *y0 = &DC_DC_source_based_matrix_swi_B.StateSpace_o1[0];
          for (i1=0; i1 < 18; i1++) {
            newState = gState[i1] > 0 ? 1 : 0;
            swChanged = ((SwitchChange[i1] = newState - switch_status[i1]) != 0)
              ? 1 : swChanged;
            switch_status[i1] = newState;/* Keep new state */
          }
        }
      }

      /*
       * Compute new As, Bs, Cs and Ds matrixes:
       * --------------------------------------
       */
      if (swChanged) {
        real_T *Ds = (real_T*)
          DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DS;
        real_T a1;

        {
          int_T i1;
          for (i1=0; i1 < 18; i1++) {
            if (SwitchChange[i1] != 0) {
              a1 = 1000.0*SwitchChange[i1];
              temp = 1/(1-Ds[i1*29]*a1);

              {
                int_T i2;
                for (i2=0; i2 < 28; i2++) {
                  DxCol[i2]= Ds[i2 * 28 + i1]*temp*a1;
                }
              }

              DxCol[i1] = temp;

              /* Copy row nSw of Ds into tmp2 and zero it out in Ds */
              memcpy(tmp2, &Ds[i1 * 28], 28 * sizeof(real_T));
              memset(&Ds[i1 * 28], '\0', 28 * sizeof(real_T));

              /* Cs = Cs + DxCol * tmp1, Ds = Ds + DxCol * tmp2 *******************/
              {
                int_T i2;
                for (i2=0; i2 < 28; i2++) {
                  a1 = DxCol[i2];

                  {
                    int_T i3;
                    for (i3=0; i3 < 28; i3++) {
                      Ds[i2 * 28 + i3] += a1 * tmp2[i3];
                    }
                  }
                }
              }
            }
          }
        }
      }                                /* if (swChanged) */
    } while (swChanged > 0 && --loopsToDo > 0);

    if (loopsToDo == 0) {
      real_T *Ds = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DS;

      {
        int_T i1;
        real_T *y0 = &DC_DC_source_based_matrix_swi_B.StateSpace_o1[0];
        for (i1=0; i1 < 28; i1++) {
          accum = 0.0;

          {
            int_T i2;
            const real_T *u0 = rtCP_SwitchCurrents_Value;
            for (i2=0; i2 < 18; i2++) {
              accum += *(Ds++) * u0[i2];
            }

            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_g;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_c;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_g2;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_h;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_n;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_f;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_gw;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.Switch2_cb;
            accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.current_left;
          }

          y0[i1] = accum;
        }
      }
    }

    /* Output new switches states */
    {
      int_T i1;
      real_T *y1 = &DC_DC_source_based_matrix_swi_B.StateSpace_o2[0];
      for (i1=0; i1 < 18; i1++) {
        y1[i1] = (real_T)switch_status[i1];
      }
    }
  }

  /* RateTransition: '<S31>/Rate Transition' */
  if (DC_DC_source_based_matrix_sw_M->Timing.TaskCounters.TID[2] == 0) {
    memcpy(&rtb_RateTransition[0],
           &DC_DC_source_based_matrix_swi_B.StateSpace_o1[19], 9U * sizeof
           (real_T));
  }

  /* End of RateTransition: '<S31>/Rate Transition' */

  /* S-Function (sfun_spssw_discc): '<S208>/State-Space' */

  /* S-Function block: <S208>/State-Space */
  {
    real_T accum;

    /*
     * Compute outputs:
     * ---------------
     */
    real_T *Cs = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.CS;
    real_T *Ds = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.DS;
    accum = 0.0;
    accum += *(Cs++) * DC_DC_source_based_matrix_sw_DW.StateSpace_DSTATE;
    accum += *(Ds++) * DC_DC_source_based_matrix_swi_B.current_right;
    DC_DC_source_based_matrix_swi_B.StateSpace = accum;
  }

  /* Fcn: '<S35>/Fcn1' incorporates:
   *  Gain: '<S35>/R4'
   *  Memory: '<S35>/it init1'
   */
  rtb_Gain_d = (1.0 - rtb_MultiportSwitch1_a / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput)) * 100.0;

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Gain_d > 100.0) {
    rtb_Gain_d = 100.0;
  } else if (rtb_Gain_d < 0.0) {
    rtb_Gain_d = 0.0;
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Fcn: '<S47>/Fcn1' incorporates:
   *  Gain: '<S47>/R4'
   *  Memory: '<S47>/it init1'
   */
  rtb_SOC_l = (1.0 - rtb_Gain / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m)) * 100.0;

  /* Saturate: '<S47>/Saturation' */
  if (rtb_SOC_l > 100.0) {
    rtb_SOC_l = 100.0;
  } else if (rtb_SOC_l < 0.0) {
    rtb_SOC_l = 0.0;
  }

  /* End of Saturate: '<S47>/Saturation' */

  /* Fcn: '<S59>/Fcn1' incorporates:
   *  Gain: '<S59>/R4'
   *  Memory: '<S59>/it init1'
   */
  rtb_SOC_m = (1.0 - rtb_Fcn6_cy / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n)) * 100.0;

  /* Saturate: '<S59>/Saturation' */
  if (rtb_SOC_m > 100.0) {
    rtb_SOC_m = 100.0;
  } else if (rtb_SOC_m < 0.0) {
    rtb_SOC_m = 0.0;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Fcn: '<S71>/Fcn1' incorporates:
   *  Gain: '<S71>/R4'
   *  Memory: '<S71>/it init1'
   */
  rtb_SOC_d4 = (1.0 - rtb_Fcn6_m4 / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e)) * 100.0;

  /* Saturate: '<S71>/Saturation' */
  if (rtb_SOC_d4 > 100.0) {
    rtb_SOC_d4 = 100.0;
  } else if (rtb_SOC_d4 < 0.0) {
    rtb_SOC_d4 = 0.0;
  }

  /* End of Saturate: '<S71>/Saturation' */

  /* Fcn: '<S83>/Fcn1' incorporates:
   *  Gain: '<S83>/R4'
   *  Memory: '<S83>/it init1'
   */
  rtb_SOC_d = (1.0 - rtb_Fcn6_o / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf)) * 100.0;

  /* Saturate: '<S83>/Saturation' */
  if (rtb_SOC_d > 100.0) {
    rtb_SOC_d = 100.0;
  } else if (rtb_SOC_d < 0.0) {
    rtb_SOC_d = 0.0;
  }

  /* End of Saturate: '<S83>/Saturation' */

  /* Fcn: '<S95>/Fcn1' incorporates:
   *  Gain: '<S95>/R4'
   *  Memory: '<S95>/it init1'
   */
  rtb_SOC_ox = (1.0 - rtb_Fcn6_e / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j)) * 100.0;

  /* Saturate: '<S95>/Saturation' */
  if (rtb_SOC_ox > 100.0) {
    rtb_SOC_ox = 100.0;
  } else if (rtb_SOC_ox < 0.0) {
    rtb_SOC_ox = 0.0;
  }

  /* End of Saturate: '<S95>/Saturation' */

  /* Fcn: '<S107>/Fcn1' incorporates:
   *  Gain: '<S107>/R4'
   *  Memory: '<S107>/it init1'
   */
  rtb_SOC_pa = (1.0 - rtb_Fcn6_g / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d)) * 100.0;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_SOC_pa > 100.0) {
    rtb_SOC_pa = 100.0;
  } else if (rtb_SOC_pa < 0.0) {
    rtb_SOC_pa = 0.0;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Fcn: '<S119>/Fcn1' incorporates:
   *  Gain: '<S119>/R4'
   *  Memory: '<S119>/it init1'
   */
  rtb_SOC_i = (1.0 - rtb_Gain_io / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g)) * 100.0;

  /* Saturate: '<S119>/Saturation' */
  if (rtb_SOC_i > 100.0) {
    rtb_SOC_i = 100.0;
  } else if (rtb_SOC_i < 0.0) {
    rtb_SOC_i = 0.0;
  }

  /* End of Saturate: '<S119>/Saturation' */

  /* Fcn: '<S131>/Fcn1' incorporates:
   *  Gain: '<S131>/R4'
   *  Memory: '<S131>/it init1'
   */
  rtb_SOC_hx = (1.0 - rtb_DataTypeConversion1_h / (0.96711798839458663 *
    DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c)) * 100.0;

  /* Saturate: '<S131>/Saturation' */
  if (rtb_SOC_hx > 100.0) {
    rtb_SOC_hx = 100.0;
  } else if (rtb_SOC_hx < 0.0) {
    rtb_SOC_hx = 0.0;
  }

  /* End of Saturate: '<S131>/Saturation' */

  /* RateTransition: '<S31>/Rate Transition1' */
  if (DC_DC_source_based_matrix_sw_M->Timing.TaskCounters.TID[2] == 0) {
    RateTransition1_Buffer[0] = rtb_Gain_d;
    RateTransition1_Buffer[1] = rtb_SOC_l;
    RateTransition1_Buffer[2] = rtb_SOC_m;
    RateTransition1_Buffer[3] = rtb_SOC_d4;
    RateTransition1_Buffer[4] = rtb_SOC_d;
    RateTransition1_Buffer[5] = rtb_SOC_ox;
    RateTransition1_Buffer[6] = rtb_SOC_pa;
    RateTransition1_Buffer[7] = rtb_SOC_i;
    RateTransition1_Buffer[8] = rtb_SOC_hx;

    /* ModelReference: '<S31>/Ah_estimator' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    coloumb_counting(&rtb_RateTransition[0], &rtCP_Constant5_Value,
                     &RateTransition1_Buffer[0],
                     &DC_DC_source_based_matrix_swi_B.Ah_estimator[0],
                     &(DC_DC_source_based_matrix_sw_DW.Ah_estimator_InstanceData.rtdw));
  }

  /* End of RateTransition: '<S31>/Rate Transition1' */

  /* SignalConversion generated from: '<S206>/ SFunction ' incorporates:
   *  MATLAB Function: '<S31>/equalizer'
   */
  rtb_RateTransition[0] = rtb_Gain_d;
  rtb_RateTransition[1] = rtb_SOC_l;
  rtb_RateTransition[2] = rtb_SOC_m;
  rtb_RateTransition[3] = rtb_SOC_d4;
  rtb_RateTransition[4] = rtb_SOC_d;
  rtb_RateTransition[5] = rtb_SOC_ox;
  rtb_RateTransition[6] = rtb_SOC_pa;
  rtb_RateTransition[7] = rtb_SOC_i;
  rtb_RateTransition[8] = rtb_SOC_hx;

  /* MATLAB Function: '<S31>/equalizer' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   */
  DC_DC_source_based_matrix_swi_B.source_batts[0] = 0.0;
  DC_DC_source_based_matrix_swi_B.destinations_batts[0] = 0.0;
  DC_DC_source_based_matrix_swi_B.source_batts[1] = 0.0;
  DC_DC_source_based_matrix_swi_B.destinations_batts[1] = 0.0;
  for (i = 0; i < 50; i++) {
    rtb_Gain_d = rtCP_Constant4_Value_lo[i];
    dst_trg_soc_av_tmp[i] = rtb_Gain_d;
    if (rtb_Gain_d == 0.0) {
      dst_trg_soc_av_tmp[i] = (rtInf);
    }
  }

  rtb_SOC_m = rtCP_Constant_Value_dc[(int16_T)
    DC_DC_source_based_matrix_sw_DW.step_cnt - 1];
  x[0] = (rtb_SOC_m > 0.0);
  rtb_SOC_d4 = rtCP_Constant_Value_dc[(int16_T)
    DC_DC_source_based_matrix_sw_DW.step_cnt + 49];
  x[1] = (rtb_SOC_d4 > 0.0);
  LogicalOperator1 = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    if (!x[i]) {
      LogicalOperator1 = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (LogicalOperator1) {
    DC_DC_source_based_matrix_swi_B.source_batts[0] = rtb_SOC_m;
    rtb_Gain_d = rtCP_Constant1_Value_cx[(int16_T)
      DC_DC_source_based_matrix_sw_DW.step_cnt - 1];
    DC_DC_source_based_matrix_swi_B.destinations_batts[0] = rtb_Gain_d;
    DC_DC_source_based_matrix_swi_B.source_batts[1] = rtb_SOC_d4;
    rtb_SOC_l = rtCP_Constant1_Value_cx[(int16_T)
      DC_DC_source_based_matrix_sw_DW.step_cnt + 49];
    DC_DC_source_based_matrix_swi_B.destinations_batts[1] = rtb_SOC_l;
    if (rtb_SOC_m > rtb_SOC_d4) {
      c = 0;
      i = 0;
    } else {
      c = (int16_T)rtb_SOC_m - 1;
      i = (int16_T)rtb_SOC_d4;
    }

    i -= c;
    if (i == 0) {
      rtb_SOC_m = 0.0;
    } else {
      rtb_SOC_m = rtb_RateTransition[c];
      for (b_k = 2; b_k <= i; b_k++) {
        rtb_SOC_m += rtb_RateTransition[(c + b_k) - 1];
      }
    }

    if (rtb_Gain_d > rtb_SOC_l) {
      c = 0;
      b_k = 0;
    } else {
      c = (int16_T)rtb_Gain_d - 1;
      b_k = (int16_T)rtb_SOC_l;
    }

    b_vlen_tmp = b_k - c;
    if (b_vlen_tmp == 0) {
      rtb_Gain_d = 0.0;
    } else {
      rtb_Gain_d = rtb_RateTransition[c];
      for (b_k = 2; b_k <= b_vlen_tmp; b_k++) {
        rtb_Gain_d += rtb_RateTransition[(c + b_k) - 1];
      }
    }

    if (rtb_SOC_m / (real_T)i <= rtCP_Constant2_Value_p[(int16_T)
        DC_DC_source_based_matrix_sw_DW.step_cnt - 1]) {
      DC_DC_source_based_matrix_sw_DW.step_cnt++;
    } else if (rtb_Gain_d / (real_T)b_vlen_tmp >= dst_trg_soc_av_tmp[(int16_T)
               DC_DC_source_based_matrix_sw_DW.step_cnt - 1]) {
      DC_DC_source_based_matrix_sw_DW.step_cnt++;
    }
  } else {
    /* Stop: '<S31>/Stop Simulation' */
    rtmSetStopRequested(DC_DC_source_based_matrix_sw_M, 1);
  }

  /* Gain: '<S40>/Gain1' incorporates:
   *  Abs: '<S40>/Abs'
   *  Constant: '<S44>/Constant'
   *  DataTypeConversion: '<S40>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Gain: '<S40>/Gain4'
   *  Product: '<S40>/Divide'
   *  RelationalOperator: '<S44>/Compare'
   *  Sum: '<S40>/Add3'
   */
  rtb_Gain1 = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[19] < 0.0)
               * 0.31071106332851506 -
               DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE) *
    fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[19]) *
    0.00770984178063824;

  /* Gain: '<S35>/R1' */
  rtb_R1 = 0.016818181818181815 * DC_DC_source_based_matrix_swi_B.StateSpace_o1
    [19];

  /* Gain: '<S52>/Gain1' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S56>/Constant'
   *  DataTypeConversion: '<S52>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator'
   *  Gain: '<S52>/Gain4'
   *  Product: '<S52>/Divide'
   *  RelationalOperator: '<S56>/Compare'
   *  Sum: '<S52>/Add3'
   */
  rtb_Gain1_h = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[20] <
    0.0) * 0.31071106332851506 -
                 DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_p)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[20]) *
    0.00770984178063824;

  /* Gain: '<S47>/R1' */
  rtb_R1_m = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[20];

  /* Gain: '<S64>/Gain1' incorporates:
   *  Abs: '<S64>/Abs'
   *  Constant: '<S68>/Constant'
   *  DataTypeConversion: '<S64>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   *  Gain: '<S64>/Gain4'
   *  Product: '<S64>/Divide'
   *  RelationalOperator: '<S68>/Compare'
   *  Sum: '<S64>/Add3'
   */
  rtb_Gain1_a = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[21] <
    0.0) * 0.31071106332851506 -
                 DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_h)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[21]) *
    0.00770984178063824;

  /* Gain: '<S59>/R1' */
  rtb_R1_h = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[21];

  /* Gain: '<S76>/Gain1' incorporates:
   *  Abs: '<S76>/Abs'
   *  Constant: '<S80>/Constant'
   *  DataTypeConversion: '<S76>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S76>/Discrete-Time Integrator'
   *  Gain: '<S76>/Gain4'
   *  Product: '<S76>/Divide'
   *  RelationalOperator: '<S80>/Compare'
   *  Sum: '<S76>/Add3'
   */
  rtb_Gain1_d = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[22] <
    0.0) * 0.31071106332851506 -
                 DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_n)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[22]) *
    0.00770984178063824;

  /* Gain: '<S71>/R1' */
  rtb_R1_e = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[22];

  /* Gain: '<S88>/Gain1' incorporates:
   *  Abs: '<S88>/Abs'
   *  Constant: '<S92>/Constant'
   *  DataTypeConversion: '<S88>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S88>/Discrete-Time Integrator'
   *  Gain: '<S88>/Gain4'
   *  Product: '<S88>/Divide'
   *  RelationalOperator: '<S92>/Compare'
   *  Sum: '<S88>/Add3'
   */
  rtb_Gain1_a3 = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[23] <
    0.0) * 0.31071106332851506 -
                  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_l)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[23]) *
    0.00770984178063824;

  /* Gain: '<S83>/R1' */
  rtb_R1_c = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[23];

  /* Gain: '<S100>/Gain1' incorporates:
   *  Abs: '<S100>/Abs'
   *  Constant: '<S104>/Constant'
   *  DataTypeConversion: '<S100>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator'
   *  Gain: '<S100>/Gain4'
   *  Product: '<S100>/Divide'
   *  RelationalOperator: '<S104>/Compare'
   *  Sum: '<S100>/Add3'
   */
  rtb_Gain1_i = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[24] <
    0.0) * 0.31071106332851506 -
                 DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_j)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[24]) *
    0.00770984178063824;

  /* Gain: '<S95>/R1' */
  rtb_R1_f = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[24];

  /* Gain: '<S112>/Gain1' incorporates:
   *  Abs: '<S112>/Abs'
   *  Constant: '<S116>/Constant'
   *  DataTypeConversion: '<S112>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
   *  Gain: '<S112>/Gain4'
   *  Product: '<S112>/Divide'
   *  RelationalOperator: '<S116>/Compare'
   *  Sum: '<S112>/Add3'
   */
  rtb_Gain1_o = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[25] <
    0.0) * 0.31071106332851506 -
                 DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTAT_p1)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[25]) *
    0.00770984178063824;

  /* Gain: '<S107>/R1' */
  rtb_R1_g = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[25];

  /* Gain: '<S124>/Gain1' incorporates:
   *  Abs: '<S124>/Abs'
   *  Constant: '<S128>/Constant'
   *  DataTypeConversion: '<S124>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S124>/Discrete-Time Integrator'
   *  Gain: '<S124>/Gain4'
   *  Product: '<S124>/Divide'
   *  RelationalOperator: '<S128>/Compare'
   *  Sum: '<S124>/Add3'
   */
  rtb_Gain1_av = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[26] <
    0.0) * 0.31071106332851506 -
                  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_g)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[26]) *
    0.00770984178063824;

  /* Gain: '<S119>/R1' */
  rtb_R1_l = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[26];

  /* Gain: '<S136>/Gain1' incorporates:
   *  Abs: '<S136>/Abs'
   *  Constant: '<S140>/Constant'
   *  DataTypeConversion: '<S136>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S136>/Discrete-Time Integrator'
   *  Gain: '<S136>/Gain4'
   *  Product: '<S136>/Divide'
   *  RelationalOperator: '<S140>/Compare'
   *  Sum: '<S136>/Add3'
   */
  rtb_Gain1_g = ((real_T)(DC_DC_source_based_matrix_swi_B.StateSpace_o1[27] <
    0.0) * 0.31071106332851506 -
                 DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTAT_py)
    * fabs(DC_DC_source_based_matrix_swi_B.StateSpace_o1[27]) *
    0.00770984178063824;

  /* Gain: '<S131>/R1' */
  rtb_R1_k = 0.016818181818181815 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[27];

  /* MATLAB Function: '<S31>/demux n' */
  DC_DC_source_based_matri_demuxn(rtb_Fcn6,
    &DC_DC_source_based_matrix_swi_B.s1_c, &DC_DC_source_based_matrix_swi_B.s2_k,
    &DC_DC_source_based_matrix_swi_B.s3_o, &DC_DC_source_based_matrix_swi_B.s4_n,
    &DC_DC_source_based_matrix_swi_B.s5_f, &DC_DC_source_based_matrix_swi_B.s6_m,
    &DC_DC_source_based_matrix_swi_B.s7_b, &DC_DC_source_based_matrix_swi_B.s8_i,
    &DC_DC_source_based_matrix_swi_B.s9_e);

  /* MATLAB Function: '<S31>/demux p' */
  DC_DC_source_based_matri_demuxn(rtb_Clock, &DC_DC_source_based_matrix_swi_B.s1,
    &DC_DC_source_based_matrix_swi_B.s2, &DC_DC_source_based_matrix_swi_B.s3,
    &DC_DC_source_based_matrix_swi_B.s4, &DC_DC_source_based_matrix_swi_B.s5,
    &DC_DC_source_based_matrix_swi_B.s6, &DC_DC_source_based_matrix_swi_B.s7,
    &DC_DC_source_based_matrix_swi_B.s8, &DC_DC_source_based_matrix_swi_B.s9);

  /* Gain: '<S131>/Gain2' */
  rtb_Gain2 = 3600.0 * rtb_DataTypeConversion1_h;

  /* Gain: '<S119>/Gain2' */
  rtb_Gain2_b = 3600.0 * rtb_Gain_io;

  /* Gain: '<S107>/Gain2' */
  rtb_Gain2_f = 3600.0 * rtb_Fcn6_g;

  /* Gain: '<S95>/Gain2' */
  rtb_Gain2_o = 3600.0 * rtb_Fcn6_e;

  /* Gain: '<S83>/Gain2' */
  rtb_Gain2_j = 3600.0 * rtb_Fcn6_o;

  /* Gain: '<S71>/Gain2' */
  rtb_Gain2_m = 3600.0 * rtb_Fcn6_m4;

  /* Gain: '<S59>/Gain2' */
  rtb_Gain2_oo = 3600.0 * rtb_Fcn6_cy;

  /* Gain: '<S47>/Gain2' */
  rtb_Gain2_i = 3600.0 * rtb_Gain;

  /* Gain: '<S35>/Gain2' */
  rtb_Gain2_n = 3600.0 * rtb_MultiportSwitch1_a;

  /* Update for Memory: '<S35>/it init1' incorporates:
   *  Constant: '<S35>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S35>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[19] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states;

  /* Update for Memory: '<S35>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput = rtb_Gain2_n;

  /* Update for DiscreteIntegrator: '<S35>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[19];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2 > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState = 1;
  } else if (rtb_DataTypeConversion2 < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState = -1;
  } else if (rtb_DataTypeConversion2 == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S35>/int(i)' */

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE += 0.001 *
    rtb_Gain1;

  /* Update for Memory: '<S35>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput = rtb_R1;

  /* Update for Memory: '<S47>/it init1' incorporates:
   *  Constant: '<S47>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S47>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_d =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[20] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_d;

  /* Update for Memory: '<S47>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_c = rtb_Gain2_i;

  /* Update for DiscreteIntegrator: '<S47>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_o = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[20];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_j = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_p > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_m = 1;
  } else if (rtb_DataTypeConversion2_p < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_m = -1;
  } else if (rtb_DataTypeConversion2_p == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_m = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_m = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S47>/int(i)' */

  /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_p += 0.001 *
    rtb_Gain1_h;

  /* Update for Memory: '<S47>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_i = rtb_R1_m;

  /* Update for Memory: '<S59>/it init1' incorporates:
   *  Constant: '<S59>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S59>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_f =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[21] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_f;

  /* Update for Memory: '<S59>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_m = rtb_Gain2_oo;

  /* Update for DiscreteIntegrator: '<S59>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_c = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[21];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_o = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_n > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_e = 1;
  } else if (rtb_DataTypeConversion2_n < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_e = -1;
  } else if (rtb_DataTypeConversion2_n == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_e = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S59>/int(i)' */

  /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_h += 0.001 *
    rtb_Gain1_a;

  /* Update for Memory: '<S59>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ic = rtb_R1_h;

  /* Update for Memory: '<S71>/it init1' incorporates:
   *  Constant: '<S71>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S71>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_e =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[22] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_e;

  /* Update for Memory: '<S71>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_b = rtb_Gain2_m;

  /* Update for DiscreteIntegrator: '<S71>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_b = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[22];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_b = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_e > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_p = 1;
  } else if (rtb_DataTypeConversion2_e < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_p = -1;
  } else if (rtb_DataTypeConversion2_e == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_p = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S71>/int(i)' */

  /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_n += 0.001 *
    rtb_Gain1_d;

  /* Update for Memory: '<S71>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_e = rtb_R1_e;

  /* Update for Memory: '<S83>/it init1' incorporates:
   *  Constant: '<S83>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S83>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_h =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[23] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_h;

  /* Update for Memory: '<S83>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_l = rtb_Gain2_j;

  /* Update for DiscreteIntegrator: '<S83>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_f = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[23];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_g = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_j > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_l = 1;
  } else if (rtb_DataTypeConversion2_j < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_l = -1;
  } else if (rtb_DataTypeConversion2_j == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_l = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S83>/int(i)' */

  /* Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_l += 0.001 *
    rtb_Gain1_a3;

  /* Update for Memory: '<S83>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_g = rtb_R1_c;

  /* Update for Memory: '<S95>/it init1' incorporates:
   *  Constant: '<S95>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S95>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_c =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[24] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_c;

  /* Update for Memory: '<S95>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_f = rtb_Gain2_o;

  /* Update for DiscreteIntegrator: '<S95>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_j = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[24];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_p = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_d > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_n = 1;
  } else if (rtb_DataTypeConversion2_d < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_n = -1;
  } else if (rtb_DataTypeConversion2_d == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_n = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_n = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S95>/int(i)' */

  /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_j += 0.001 *
    rtb_Gain1_i;

  /* Update for Memory: '<S95>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ix = rtb_R1_f;

  /* Update for Memory: '<S107>/it init1' incorporates:
   *  Constant: '<S107>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S107>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_i =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[25] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_i;

  /* Update for Memory: '<S107>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_k = rtb_Gain2_f;

  /* Update for DiscreteIntegrator: '<S107>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_p = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[25];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_e = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_g > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_k = 1;
  } else if (rtb_DataTypeConversion2_g < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_k = -1;
  } else if (rtb_DataTypeConversion2_g == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_k = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_k = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S107>/int(i)' */

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTAT_p1 += 0.001 *
    rtb_Gain1_o;

  /* Update for Memory: '<S107>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ey = rtb_R1_g;

  /* Update for Memory: '<S119>/it init1' incorporates:
   *  Constant: '<S119>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S119>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_n =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[26] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_n;

  /* Update for Memory: '<S119>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_g = rtb_Gain2_b;

  /* Update for DiscreteIntegrator: '<S119>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_o1 = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[26];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jo = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_jw > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_o = 1;
  } else if (rtb_DataTypeConversion2_jw < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_o = -1;
  } else if (rtb_DataTypeConversion2_jw == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_o = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_o = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S119>/int(i)' */

  /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_g += 0.001 *
    rtb_Gain1_av;

  /* Update for Memory: '<S119>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_ge = rtb_R1_l;

  /* Update for Memory: '<S131>/it init1' incorporates:
   *  Constant: '<S131>/Constant12'
   */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c = 2.2747999999999946;

  /* Update for DiscreteTransferFcn: '<S131>/Current filter' */
  DC_DC_source_based_matrix_sw_DW.Currentfilter_states_o =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[27] - -0.99990000499983334 *
    DC_DC_source_based_matrix_sw_DW.Currentfilter_states_o;

  /* Update for Memory: '<S131>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_cu = rtb_Gain2;

  /* Update for DiscreteIntegrator: '<S131>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_a = 0U;
  DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz += 0.001 *
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[27];
  if (DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz >= 8189.2799999999806) {
    DC_DC_source_based_matrix_sw_DW.inti_DSTATE_jz = 8189.2799999999806;
  }

  if (rtb_DataTypeConversion2_c > 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_c = 1;
  } else if (rtb_DataTypeConversion2_c < 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_c = -1;
  } else if (rtb_DataTypeConversion2_c == 0.0) {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_c = 0;
  } else {
    DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S131>/int(i)' */

  /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTAT_py += 0.001 *
    rtb_Gain1_g;

  /* Update for Memory: '<S131>/Memory2' */
  DC_DC_source_based_matrix_sw_DW.Memory2_PreviousInput_d = rtb_R1_k;

  /* Update for Memory: '<S10>/Memory1' */
  DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput =
    DC_DC_source_based_matrix_swi_B.StateSpace;

  /* Update for Memory: '<S10>/Memory' */
  DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput =
    DC_DC_source_based_matrix_swi_B.StateSpace_o1[18];

  /* Update for Enabled SubSystem: '<S184>/ON Delay' incorporates:
   *  EnablePort: '<S186>/Enable'
   */
  if (DC_DC_source_based_matrix_sw_DW.ONDelay_MODE) {
    /* Update for Memory: '<S197>/Memory' */
    DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_p =
      DC_DC_source_based_matrix_swi_B.DataTypeConversion1;

    /* Update for Memory: '<S202>/IC=ic' */
    DC_DC_source_based_matrix_sw_DW.ICic_PreviousInput =
      DC_DC_source_based_matrix_swi_B.Switch;
  }

  /* End of Update for SubSystem: '<S184>/ON Delay' */

  /* Update for Enabled SubSystem: '<S184>/OFF Delay' incorporates:
   *  EnablePort: '<S185>/Enable'
   */
  if (DC_DC_source_based_matrix_sw_DW.OFFDelay_MODE) {
    /* Update for Memory: '<S189>/Memory' */
    DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_a =
      DC_DC_source_based_matrix_swi_B.DataTypeConversion1;

    /* Update for Memory: '<S194>/IC=ic' */
    DC_DC_source_based_matrix_sw_DW.ICic_PreviousInput_a =
      DC_DC_source_based_matrix_swi_B.Switch_e;
  }

  /* End of Update for SubSystem: '<S184>/OFF Delay' */

  /* Update for Memory: '<S31>/Memory' */
  DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_f[0] =
    DC_DC_source_based_matrix_swi_B.destinations_batts[0];

  /* Update for Memory: '<S31>/Memory1' */
  DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput_n[0] =
    DC_DC_source_based_matrix_swi_B.source_batts[0];

  /* Update for Memory: '<S31>/Memory' */
  DC_DC_source_based_matrix_sw_DW.Memory_PreviousInput_f[1] =
    DC_DC_source_based_matrix_swi_B.destinations_batts[1];

  /* Update for Memory: '<S31>/Memory1' */
  DC_DC_source_based_matrix_sw_DW.Memory1_PreviousInput_n[1] =
    DC_DC_source_based_matrix_swi_B.source_batts[1];

  /* Update for S-Function (sfun_spssw_discc): '<S207>/State-Space' incorporates:
   *  Constant: '<S210>/SwitchCurrents'
   */
  {
    int_T *gState = (int_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.G_STATE;

    /* Store switch gates values for next step */
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s1_c;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s1;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s2;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s3_o;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s6_m;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s7;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s8;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s9_e;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s8_i;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s9;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s2_k;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s3;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s4;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s5_f;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s4_n;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s5;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s6;
    *(gState++) = (int_T) DC_DC_source_based_matrix_swi_B.s7_b;
  }

  /* Update for S-Function (sfun_spssw_discc): '<S208>/State-Space' */

  /* S-Function block: <S208>/State-Space */
  {
    const real_T *As = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.AS;
    const real_T *Bs = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.BS;
    real_T *xtmp = (real_T*)
      DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.XTMP;
    real_T accum;

    /* Calculate new states... */
    accum = 0.0;
    accum += *(As++) * DC_DC_source_based_matrix_sw_DW.StateSpace_DSTATE;
    accum += *(Bs++) * DC_DC_source_based_matrix_swi_B.current_right;
    xtmp[0] = accum;
    DC_DC_source_based_matrix_sw_DW.StateSpace_DSTATE = xtmp[0];
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  DC_DC_source_based_matrix_sw_M->Timing.t[0] =
    ((time_T)(++DC_DC_source_based_matrix_sw_M->Timing.clockTick0)) *
    DC_DC_source_based_matrix_sw_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    DC_DC_source_based_matrix_sw_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void DC_DC_source_based_matrix_switches1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DC_DC_source_based_matrix_sw_M->solverInfo,
                          &DC_DC_source_based_matrix_sw_M->Timing.simTimeStep);
    rtsiSetTPtr(&DC_DC_source_based_matrix_sw_M->solverInfo, &rtmGetTPtr
                (DC_DC_source_based_matrix_sw_M));
    rtsiSetStepSizePtr(&DC_DC_source_based_matrix_sw_M->solverInfo,
                       &DC_DC_source_based_matrix_sw_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&DC_DC_source_based_matrix_sw_M->solverInfo,
                          (&rtmGetErrorStatus(DC_DC_source_based_matrix_sw_M)));
    rtsiSetRTModelPtr(&DC_DC_source_based_matrix_sw_M->solverInfo,
                      DC_DC_source_based_matrix_sw_M);
  }

  rtsiSetSimTimeStep(&DC_DC_source_based_matrix_sw_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&DC_DC_source_based_matrix_sw_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(DC_DC_source_based_matrix_sw_M,
             &DC_DC_source_based_matrix_sw_M->Timing.tArray[0]);
  DC_DC_source_based_matrix_sw_M->Timing.stepSize0 = 0.001;

  /* Model Initialize function for ModelReference Block: '<S31>/Ah_estimator' */
  coloumb_counting_initialize(rtmGetErrorStatusPointer
    (DC_DC_source_based_matrix_sw_M),
    &(DC_DC_source_based_matrix_sw_DW.Ah_estimator_InstanceData.rtm));

  /* Start for S-Function (sfun_spssw_discc): '<S207>/State-Space' incorporates:
   *  Constant: '<S210>/SwitchCurrents'
   */

  /* S-Function block: <S207>/State-Space */
  {
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DS = (real_T*)calloc(28 *
      28, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DX_COL = (real_T*)calloc(28,
      sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.TMP2 = (real_T*)calloc(28,
      sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS = (int_T*)
      calloc(18, sizeof(int_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SW_CHG = (int_T*)calloc(18,
      sizeof(int_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.G_STATE = (int_T*)calloc(18,
      sizeof(int_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.Y_SWITCH = (real_T*)calloc
      (18, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_TYPES = (int_T*)
      calloc(18, sizeof(int_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.IDX_OUT_SW = (int_T*)calloc
      (18, sizeof(int_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS_INIT = (int_T*)
      calloc(18, sizeof(int_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.USWLAST = (real_T*)calloc
      (18, sizeof(real_T));
  }

  /* Start for S-Function (sfun_spssw_discc): '<S208>/State-Space' */

  /* S-Function block: <S208>/State-Space */
  {
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.AS = (real_T*)calloc(1 *
      1, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.BS = (real_T*)calloc(1 *
      1, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.CS = (real_T*)calloc(1 *
      1, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.DS = (real_T*)calloc(1 *
      1, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.DX_COL = (real_T*)calloc
      (1, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.TMP2 = (real_T*)calloc(1,
      sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.BD_COL = (real_T*)calloc
      (1, sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.TMP1 = (real_T*)calloc(1,
      sizeof(real_T));
    DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.XTMP = (real_T*)calloc(1,
      sizeof(real_T));
  }

  DC_DC_source_based_matr_PrevZCX.TriggeredSubsystem_Trig_ZCE_i = POS_ZCSIG;
  DC_DC_source_based_matr_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<S35>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S35>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput = 2376.0000000000009;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE =
    1.8458835509728717E-9;

  /* InitializeConditions for Memory: '<S47>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_m = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S47>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_c = 950.40000000000009;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_m = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_p =
    0.00015918265728395828;

  /* InitializeConditions for Memory: '<S59>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_n = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S59>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_m = 7128.0000000000018;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_e = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_h =
    6.5147756545784022E-26;

  /* InitializeConditions for Memory: '<S71>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_e = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S71>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_b = 396.0000000000004;

  /* InitializeConditions for DiscreteIntegrator: '<S71>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_p = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S76>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_n =
    0.013223040079965765;

  /* InitializeConditions for Memory: '<S83>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_nf = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S83>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_l = 3801.6000000000004;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_l = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_f = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_l =
    2.1404882553720295E-14;

  /* InitializeConditions for Memory: '<S95>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_j = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S95>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_f = 3960.0000000000009;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_n = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_j =
    6.0548402334728635E-15;

  /* InitializeConditions for Memory: '<S107>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_d = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S107>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_k = 4118.4000000000015;

  /* InitializeConditions for DiscreteIntegrator: '<S107>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_k = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_p = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTAT_p1 =
    1.7127442844347592E-15;

  /* InitializeConditions for Memory: '<S119>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_g = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S119>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_g = 4593.6000000000013;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_o = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_o1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTATE_g =
    3.876698653605782E-17;

  /* InitializeConditions for Memory: '<S131>/it init1' */
  DC_DC_source_based_matrix_sw_DW.itinit1_PreviousInput_c = 2.2747999999999946;

  /* InitializeConditions for Memory: '<S131>/it init' */
  DC_DC_source_based_matrix_sw_DW.itinit_PreviousInput_cu = 1900.8000000000002;

  /* InitializeConditions for DiscreteIntegrator: '<S131>/int(i)' */
  DC_DC_source_based_matrix_sw_DW.inti_PrevResetState_c = 2;
  DC_DC_source_based_matrix_sw_DW.inti_IC_LOADING_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Discrete-Time Integrator' */
  DC_DC_source_based_matrix_sw_DW.DiscreteTimeIntegrator_DSTAT_py =
    8.1552031358442659E-8;

  /* InitializeConditions for S-Function (sfun_spssw_discc): '<S207>/State-Space' incorporates:
   *  Constant: '<S210>/SwitchCurrents'
   */
  {
    int32_T i, j;
    real_T *Ds = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DS;

    /* Copy and transpose D */
    for (i=0; i<28; i++) {
      for (j=0; j<28; j++)
        Ds[i*28 + j] = (rtCP_StateSpace_DS_param[i + j*28]);
    }

    {
      /* Switches work vectors */
      int_T *switch_status = (int_T*)
        DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS;
      int_T *gState = (int_T*)
        DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.G_STATE;
      real_T *yswitch = (real_T*)
        DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.Y_SWITCH;
      int_T *switchTypes = (int_T*)
        DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_TYPES;
      int_T *idxOutSw = (int_T*)
        DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.IDX_OUT_SW;
      int_T *switch_status_init = (int_T*)
        DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;

      /* Initialize work vectors */
      switch_status[0] = 0;
      switch_status_init[0] = 0;
      gState[0] = (int_T) 0.0;
      yswitch[0] = 1/0.001;
      switchTypes[0] = (int_T)1.0;
      idxOutSw[0] = ((int_T)0.0) - 1;
      switch_status[1] = 0;
      switch_status_init[1] = 0;
      gState[1] = (int_T) 0.0;
      yswitch[1] = 1/0.001;
      switchTypes[1] = (int_T)1.0;
      idxOutSw[1] = ((int_T)0.0) - 1;
      switch_status[2] = 0;
      switch_status_init[2] = 0;
      gState[2] = (int_T) 0.0;
      yswitch[2] = 1/0.001;
      switchTypes[2] = (int_T)1.0;
      idxOutSw[2] = ((int_T)0.0) - 1;
      switch_status[3] = 0;
      switch_status_init[3] = 0;
      gState[3] = (int_T) 0.0;
      yswitch[3] = 1/0.001;
      switchTypes[3] = (int_T)1.0;
      idxOutSw[3] = ((int_T)0.0) - 1;
      switch_status[4] = 0;
      switch_status_init[4] = 0;
      gState[4] = (int_T) 0.0;
      yswitch[4] = 1/0.001;
      switchTypes[4] = (int_T)1.0;
      idxOutSw[4] = ((int_T)0.0) - 1;
      switch_status[5] = 0;
      switch_status_init[5] = 0;
      gState[5] = (int_T) 0.0;
      yswitch[5] = 1/0.001;
      switchTypes[5] = (int_T)1.0;
      idxOutSw[5] = ((int_T)0.0) - 1;
      switch_status[6] = 0;
      switch_status_init[6] = 0;
      gState[6] = (int_T) 0.0;
      yswitch[6] = 1/0.001;
      switchTypes[6] = (int_T)1.0;
      idxOutSw[6] = ((int_T)0.0) - 1;
      switch_status[7] = 0;
      switch_status_init[7] = 0;
      gState[7] = (int_T) 0.0;
      yswitch[7] = 1/0.001;
      switchTypes[7] = (int_T)1.0;
      idxOutSw[7] = ((int_T)0.0) - 1;
      switch_status[8] = 0;
      switch_status_init[8] = 0;
      gState[8] = (int_T) 0.0;
      yswitch[8] = 1/0.001;
      switchTypes[8] = (int_T)1.0;
      idxOutSw[8] = ((int_T)0.0) - 1;
      switch_status[9] = 0;
      switch_status_init[9] = 0;
      gState[9] = (int_T) 0.0;
      yswitch[9] = 1/0.001;
      switchTypes[9] = (int_T)1.0;
      idxOutSw[9] = ((int_T)0.0) - 1;
      switch_status[10] = 0;
      switch_status_init[10] = 0;
      gState[10] = (int_T) 0.0;
      yswitch[10] = 1/0.001;
      switchTypes[10] = (int_T)1.0;
      idxOutSw[10] = ((int_T)0.0) - 1;
      switch_status[11] = 0;
      switch_status_init[11] = 0;
      gState[11] = (int_T) 0.0;
      yswitch[11] = 1/0.001;
      switchTypes[11] = (int_T)1.0;
      idxOutSw[11] = ((int_T)0.0) - 1;
      switch_status[12] = 0;
      switch_status_init[12] = 0;
      gState[12] = (int_T) 0.0;
      yswitch[12] = 1/0.001;
      switchTypes[12] = (int_T)1.0;
      idxOutSw[12] = ((int_T)0.0) - 1;
      switch_status[13] = 0;
      switch_status_init[13] = 0;
      gState[13] = (int_T) 0.0;
      yswitch[13] = 1/0.001;
      switchTypes[13] = (int_T)1.0;
      idxOutSw[13] = ((int_T)0.0) - 1;
      switch_status[14] = 0;
      switch_status_init[14] = 0;
      gState[14] = (int_T) 0.0;
      yswitch[14] = 1/0.001;
      switchTypes[14] = (int_T)1.0;
      idxOutSw[14] = ((int_T)0.0) - 1;
      switch_status[15] = 0;
      switch_status_init[15] = 0;
      gState[15] = (int_T) 0.0;
      yswitch[15] = 1/0.001;
      switchTypes[15] = (int_T)1.0;
      idxOutSw[15] = ((int_T)0.0) - 1;
      switch_status[16] = 0;
      switch_status_init[16] = 0;
      gState[16] = (int_T) 0.0;
      yswitch[16] = 1/0.001;
      switchTypes[16] = (int_T)1.0;
      idxOutSw[16] = ((int_T)0.0) - 1;
      switch_status[17] = 0;
      switch_status_init[17] = 0;
      gState[17] = (int_T) 0.0;
      yswitch[17] = 1/0.001;
      switchTypes[17] = (int_T)1.0;
      idxOutSw[17] = ((int_T)0.0) - 1;
    }
  }

  /* InitializeConditions for S-Function (sfun_spssw_discc): '<S208>/State-Space' */
  {
    int32_T i, j;
    real_T *As = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.AS;
    real_T *Bs = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.BS;
    real_T *Cs = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.CS;
    real_T *Ds = (real_T*)DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.DS;
    real_T *X0 = (real_T*)&DC_DC_source_based_matrix_sw_DW.StateSpace_DSTATE;
    for (i = 0; i < 1; i++) {
      X0[i] = 0.0;
    }

    /* Copy and transpose A and B */
    for (i=0; i<1; i++) {
      for (j=0; j<1; j++)
        As[i*1 + j] = 1.0;
      for (j=0; j<1; j++)
        Bs[i*1 + j] = 0.2;
    }

    /* Copy and transpose C */
    for (i=0; i<1; i++) {
      for (j=0; j<1; j++)
        Cs[i*1 + j] = 0.001;
    }

    /* Copy and transpose D */
    for (i=0; i<1; i++) {
      for (j=0; j<1; j++)
        Ds[i*1 + j] = 0.0001;
    }
  }

  /* SystemInitialize for Enabled SubSystem: '<S184>/ON Delay' */
  /* InitializeConditions for Memory: '<S202>/IC=ic' */
  DC_DC_source_based_matrix_sw_DW.ICic_PreviousInput = -1.0E+99;

  /* End of SystemInitialize for SubSystem: '<S184>/ON Delay' */

  /* SystemInitialize for Enabled SubSystem: '<S184>/OFF Delay' */
  /* InitializeConditions for Memory: '<S194>/IC=ic' */
  DC_DC_source_based_matrix_sw_DW.ICic_PreviousInput_a = -1.0E+99;

  /* End of SystemInitialize for SubSystem: '<S184>/OFF Delay' */

  /* SystemInitialize for ModelReference: '<S31>/Ah_estimator' */
  coloumb_counting_Init
    (&(DC_DC_source_based_matrix_sw_DW.Ah_estimator_InstanceData.rtdw));

  /* SystemInitialize for MATLAB Function: '<S31>/equalizer' */
  DC_DC_source_based_matrix_sw_DW.step_cnt = 1.0;
}

/* Model terminate function */
void DC_DC_source_based_matrix_switches1_terminate(void)
{
  /* Terminate for S-Function (sfun_spssw_discc): '<S207>/State-Space' incorporates:
   *  Constant: '<S210>/SwitchCurrents'
   */

  /* S-Function block: <S207>/State-Space */
  {
    /* Free memory */
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DS);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.DX_COL);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.TMP2);

    /*
     * Circuit has switches*/
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.G_STATE);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SW_CHG);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK.SWITCH_STATUS_INIT);
  }

  /* Terminate for S-Function (sfun_spssw_discc): '<S208>/State-Space' */

  /* S-Function block: <S208>/State-Space */
  {
    /* Free memory */
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.AS);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.BS);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.CS);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.DS);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.DX_COL);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.TMP2);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.BD_COL);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.TMP1);
    free(DC_DC_source_based_matrix_sw_DW.StateSpace_PWORK_p.XTMP);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
