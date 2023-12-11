/*
 * File: RCTcc.c
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

#include "RCTcc.h"
#include "rtwtypes.h"
#include "test3.h"
#include "test3_private.h"

/* Named constants for Chart: '<S100>/Chart1' */
#define test3_CALL_EVENT               (-1L)
#define test3_event_DeltaCHSOC         (0L)
#define test3_event_DeltaSOC           (1L)
#define test3_IN_A                     (1U)
#define test3_IN_A1                    (1U)
#define test3_IN_A1_f                  (2U)
#define test3_IN_B                     (3U)
#define test3_IN_B1                    (4U)
#define test3_IN_B2                    (5U)
#define test3_IN_NO_ACTIVE_CHILD       (0U)

/* Forward declaration for local functions */
static void test3_c6_test3(real32_T rtu_SOC, real32_T rtu_Mileage,
  B_RCTcc_test3_T *localB, DW_RCTcc_test3_T *localDW);

/* Function for Chart: '<S100>/Chart1' */
static void test3_c6_test3(real32_T rtu_SOC, real32_T rtu_Mileage,
  B_RCTcc_test3_T *localB, DW_RCTcc_test3_T *localDW)
{
  int32_T c_previousEvent;

  /* Chart: '<S100>/Chart1' incorporates:
   *  Constant: '<S100>/BasedMileage per Watts'
   */
  if (localDW->is_active_c6_test3 == 0U) {
    localDW->is_active_c6_test3 = 1U;
    localDW->is_active_Control = 1U;
    localDW->is_Control = test3_IN_A1;
    localDW->SOE1 = rtu_SOC;
    localDW->is_active_Estimate_Mileage = 1U;
    localB->RD_OUT = 1.0F;
    localDW->RD_OUT1 = 1.0F;
    localDW->RD_OUT2 = 1.0F;
    localDW->RD_OUT3 = 1.0F;
    localDW->is_Estimate_Mileage = test3_IN_A;
    localDW->Mileage1 = rtu_Mileage;
  } else {
    if ((localDW->is_active_Control != 0U) && ((int16_T)localDW->is_Control ==
         (int16_T)test3_IN_A1)) {
      if (rtu_SOC - localDW->SOE1 >= 2.0F) {
        localDW->is_Control = test3_IN_NO_ACTIVE_CHILD;
        c_previousEvent = localDW->sfEvent;
        localDW->sfEvent = test3_event_DeltaCHSOC;
        test3_c6_test3(rtu_SOC, rtu_Mileage, localB, localDW);
        localDW->sfEvent = c_previousEvent;
        if (((int16_T)localDW->is_Control == (int16_T)test3_IN_NO_ACTIVE_CHILD) &&
            (localDW->is_active_Control != 0U)) {
          localDW->is_Control = test3_IN_A1;
          localDW->SOE1 = rtu_SOC;
        }
      } else if (localDW->SOE1 - rtu_SOC >= 1.0F) {
        localDW->is_Control = test3_IN_NO_ACTIVE_CHILD;
        c_previousEvent = localDW->sfEvent;
        localDW->sfEvent = test3_event_DeltaSOC;
        test3_c6_test3(rtu_SOC, rtu_Mileage, localB, localDW);
        localDW->sfEvent = c_previousEvent;
        if (((int16_T)localDW->is_Control == (int16_T)test3_IN_NO_ACTIVE_CHILD) &&
            (localDW->is_active_Control != 0U)) {
          localDW->is_Control = test3_IN_A1;
          localDW->SOE1 = rtu_SOC;
        }
      }
    }

    if (localDW->is_active_Estimate_Mileage != 0U) {
      switch (localDW->is_Estimate_Mileage) {
       case test3_IN_A:
        switch (localDW->sfEvent) {
         case test3_event_DeltaSOC:
          localDW->is_Estimate_Mileage = test3_IN_B;
          localDW->Mileage2 = rtu_Mileage;
          localDW->RD_OUT1 = (localDW->Mileage2 - localDW->Mileage1) / 3.3F;
          localB->RD_OUT = ((localDW->RD_OUT3 + localDW->RD_OUT2) +
                            localDW->RD_OUT1) / 3.0F;
          break;

         case test3_event_DeltaCHSOC:
          localDW->is_Estimate_Mileage = test3_IN_A1_f;
          localB->RD_OUT += 1.0F / (101.0F - rtu_SOC) * (1.0F - localB->RD_OUT);
          break;
        }
        break;

       case test3_IN_A1_f:
        switch (localDW->sfEvent) {
         case test3_event_DeltaSOC:
          localDW->is_Estimate_Mileage = test3_IN_A;
          localDW->Mileage1 = rtu_Mileage;
          break;

         case test3_event_DeltaCHSOC:
          localDW->is_Estimate_Mileage = test3_IN_A1_f;
          localB->RD_OUT += 1.0F / (101.0F - rtu_SOC) * (1.0F - localB->RD_OUT);
          break;
        }
        break;

       case test3_IN_B:
        switch (localDW->sfEvent) {
         case test3_event_DeltaSOC:
          localDW->is_Estimate_Mileage = test3_IN_B1;
          localDW->Mileage3 = rtu_Mileage;
          localDW->RD_OUT2 = (localDW->Mileage3 - localDW->Mileage2) / 3.3F;
          localB->RD_OUT = ((localDW->RD_OUT3 + localDW->RD_OUT2) +
                            localDW->RD_OUT1) / 3.0F;
          break;

         case test3_event_DeltaCHSOC:
          localDW->is_Estimate_Mileage = test3_IN_A1_f;
          localB->RD_OUT += 1.0F / (101.0F - rtu_SOC) * (1.0F - localB->RD_OUT);
          break;
        }
        break;

       case test3_IN_B1:
        switch (localDW->sfEvent) {
         case test3_event_DeltaSOC:
          localDW->is_Estimate_Mileage = test3_IN_B2;
          localDW->temporalCounter_i1 = 0U;
          localDW->RD_OUT3 = (rtu_Mileage - localDW->Mileage3) / 3.3F;
          localB->RD_OUT = ((localDW->RD_OUT3 + localDW->RD_OUT2) +
                            localDW->RD_OUT1) / 3.0F;
          break;

         case test3_event_DeltaCHSOC:
          localDW->is_Estimate_Mileage = test3_IN_A1_f;
          localB->RD_OUT += 1.0F / (101.0F - rtu_SOC) * (1.0F - localB->RD_OUT);
          break;
        }
        break;

       case test3_IN_B2:
        if (localDW->temporalCounter_i1 >= 100U) {
          localDW->is_Estimate_Mileage = test3_IN_A;
          localDW->Mileage1 = rtu_Mileage;
        } else if (localDW->sfEvent == test3_event_DeltaCHSOC) {
          localDW->is_Estimate_Mileage = test3_IN_A1_f;
          localB->RD_OUT += 1.0F / (101.0F - rtu_SOC) * (1.0F - localB->RD_OUT);
        }
        break;
      }
    }
  }

  /* End of Chart: '<S100>/Chart1' */
}

/* System initialize for atomic system: '<Root>/RCTcc' */
void test3_RCTcc_Init(B_RCTcc_test3_T *localB, DW_RCTcc_test3_T *localDW)
{
  /* Start for Probe: '<S686>/Probe' */
  localB->Probe[0] = 0.01F;
  localB->Probe[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S691>/Integrator' */
  localDW->Integrator_PrevResetState = 0;
  localDW->Integrator_IC_LOADING = 1U;

  /* InitializeConditions for RateLimiter: '<S100>/Rate Limiter' */
  localDW->PrevY = 0.0F;

  /* SystemInitialize for Chart: '<S100>/Chart1' */
  localDW->sfEvent = test3_CALL_EVENT;
  localDW->is_active_Control = 0U;
  localDW->is_Control = test3_IN_NO_ACTIVE_CHILD;
  localDW->is_active_Estimate_Mileage = 0U;
  localDW->is_Estimate_Mileage = test3_IN_NO_ACTIVE_CHILD;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c6_test3 = 0U;
  localDW->Mileage2 = 0.0F;
  localDW->Mileage1 = 0.0F;
  localDW->SOE1 = 0.0F;
  localDW->RD_OUT1 = 0.0F;
  localDW->RD_OUT2 = 0.0F;
  localDW->RD_OUT3 = 0.0F;
  localDW->Mileage3 = 0.0F;
  localB->RD_OUT = 0.0F;
}

/* Output and update for atomic system: '<Root>/RCTcc' */
void test3_RCTcc(uint16_T rtu_Capacity, real32_T rtu_Pack_Current, uint16_T
                 rtu_ReqSOC, real32_T rtu_Fake_SOC, real32_T rtu_SOC, real32_T
                 rtu_Mileage, real32_T *rty_RCT, real32_T *rty_RD_NEDC_F,
                 real32_T *rty_RDT, real32_T *rty_Add_Mileage_Range, real32_T
                 *rty_SOE, real32_T *rty_RD_NEDC_F1, B_RCTcc_test3_T *localB,
                 DW_RCTcc_test3_T *localDW)
{
  real32_T rtb_Add1;
  real32_T rtb_AvoidDividebyZero_ez;
  boolean_T rtb_Compare_m4;

  /* MinMax: '<S686>/Max' */
  if (localB->Probe[0] >= 0.15915494309189535) {
    *rty_RDT = localB->Probe[0];
  } else {
    *rty_RDT = 0.159154937F;
  }

  /* End of MinMax: '<S686>/Max' */

  /* Fcn: '<S686>/Avoid Divide by Zero' */
  rtb_AvoidDividebyZero_ez = (real32_T)(*rty_RDT == 0.0F) * 2.22044605e-16F +
    *rty_RDT;

  /* Sum: '<S686>/Sum1' incorporates:
   *  Constant: '<S686>/Time constant'
   */
  *rty_RDT = (real32_T)(0.15915494309189535 - localB->Probe[0]);

  /* RelationalOperator: '<S689>/Compare' incorporates:
   *  Constant: '<S689>/Constant'
   */
  rtb_Compare_m4 = (*rty_RDT <= 0.0F);

  /* DiscreteIntegrator: '<S691>/Integrator' */
  if (localDW->Integrator_IC_LOADING != 0U) {
    localDW->Integrator_DSTATE = rtu_Pack_Current;
    if (localDW->Integrator_DSTATE >= 500.0F) {
      localDW->Integrator_DSTATE = 500.0F;
    } else if (localDW->Integrator_DSTATE <= -500.0F) {
      localDW->Integrator_DSTATE = -500.0F;
    }
  }

  if (rtb_Compare_m4 || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = rtu_Pack_Current;
    if (localDW->Integrator_DSTATE >= 500.0F) {
      localDW->Integrator_DSTATE = 500.0F;
    } else if (localDW->Integrator_DSTATE <= -500.0F) {
      localDW->Integrator_DSTATE = -500.0F;
    }
  }

  if (localDW->Integrator_DSTATE >= 500.0F) {
    localDW->Integrator_DSTATE = 500.0F;
  } else if (localDW->Integrator_DSTATE <= -500.0F) {
    localDW->Integrator_DSTATE = -500.0F;
  }

  /* Gain: '<S100>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S691>/Integrator'
   */
  *rty_RDT = -localDW->Integrator_DSTATE;

  /* Product: '<S100>/Divide1' */
  *rty_RCT = (real32_T)rtu_Capacity / *rty_RDT;

  /* Sum: '<S100>/Add' */
  *rty_RDT = (real32_T)rtu_ReqSOC - rtu_Fake_SOC;

  /* Saturate: '<S100>/Saturation2' */
  if (*rty_RDT > 100.0F) {
    *rty_RDT = 100.0F;
  } else if (*rty_RDT < 0.0F) {
    *rty_RDT = 0.0F;
  }

  /* End of Saturate: '<S100>/Saturation2' */

  /* Gain: '<S100>/Gain' incorporates:
   *  Product: '<S100>/Divide2'
   */
  *rty_RCT = *rty_RDT * *rty_RCT * 0.6F;

  /* Saturate: '<S100>/Saturation' */
  if (*rty_RCT > 100000.0F) {
    *rty_RCT = 100000.0F;
  } else if (*rty_RCT < 0.0F) {
    *rty_RCT = 0.0F;
  }

  /* End of Saturate: '<S100>/Saturation' */

  /* Product: '<S100>/Divide3' incorporates:
   *  DiscreteIntegrator: '<S691>/Integrator'
   */
  *rty_RDT = (real32_T)rtu_Capacity / localDW->Integrator_DSTATE;

  /* Gain: '<S100>/Gain1' incorporates:
   *  Product: '<S100>/Divide4'
   */
  *rty_RDT = rtu_SOC * *rty_RDT * 0.6F;

  /* Saturate: '<S100>/Saturation1' */
  if (*rty_RDT > 100000.0F) {
    *rty_RDT = 100000.0F;
  } else if (*rty_RDT < 0.0F) {
    *rty_RDT = 0.0F;
  }

  /* End of Saturate: '<S100>/Saturation1' */

  /* Product: '<S100>/Divide5' incorporates:
   *  DiscreteIntegrator: '<S691>/Integrator'
   */
  *rty_Add_Mileage_Range = localDW->Integrator_DSTATE * rtu_Mileage / (real32_T)
    rtu_Capacity;

  /* RateLimiter: '<S100>/Rate Limiter' */
  rtb_Add1 = *rty_Add_Mileage_Range - localDW->PrevY;
  if (rtb_Add1 > 1.0F) {
    *rty_Add_Mileage_Range = localDW->PrevY + 1.0F;
  } else if (rtb_Add1 < 0.0F) {
    *rty_Add_Mileage_Range = localDW->PrevY;
  }

  localDW->PrevY = *rty_Add_Mileage_Range;

  /* End of RateLimiter: '<S100>/Rate Limiter' */

  /* Lookup_n-D: '<S100>/1-D Lookup Table3' */
  *rty_RD_NEDC_F = look1_iflf_binlxpw(rtu_SOC,
    test3_ConstP.uDLookupTable3_bp01Data, test3_ConstP.uDLookupTable3_tableData,
    20UL);

  /* Gain: '<S100>/Gain4' */
  *rty_SOE = 2567.04F * *rty_RD_NEDC_F;

  /* Gain: '<S100>/NEDC_F' */
  *rty_RD_NEDC_F = 3.3F * rtu_SOC;

  /* Gain: '<S100>/NEDC_F3' */
  rtb_Add1 = 0.5F * *rty_RD_NEDC_F;

  /* Chart: '<S100>/Chart1' */
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1 = (uint16_T)((int16_T)
      localDW->temporalCounter_i1 + 1);
  }

  localDW->sfEvent = test3_CALL_EVENT;
  test3_c6_test3(rtu_SOC, rtu_Mileage, localB, localDW);

  /* End of Chart: '<S100>/Chart1' */

  /* Sum: '<S100>/Add1' incorporates:
   *  Product: '<S100>/Divide6'
   */
  rtb_Add1 += rtb_Add1 * localB->RD_OUT;

  /* Saturate: '<S100>/Saturation3' */
  if (rtb_Add1 > 600.0F) {
    *rty_RD_NEDC_F1 = 600.0F;
  } else if (rtb_Add1 < 0.0F) {
    *rty_RD_NEDC_F1 = 0.0F;
  } else {
    *rty_RD_NEDC_F1 = rtb_Add1;
  }

  /* End of Saturate: '<S100>/Saturation3' */

  /* Update for DiscreteIntegrator: '<S691>/Integrator' incorporates:
   *  Product: '<S684>/1//T'
   *  Sum: '<S684>/Sum1'
   */
  localDW->Integrator_IC_LOADING = 0U;
  localDW->Integrator_DSTATE += 1.0F / rtb_AvoidDividebyZero_ez *
    (rtu_Pack_Current - localDW->Integrator_DSTATE) * 0.01F;
  if (localDW->Integrator_DSTATE >= 500.0F) {
    localDW->Integrator_DSTATE = 500.0F;
  } else if (localDW->Integrator_DSTATE <= -500.0F) {
    localDW->Integrator_DSTATE = -500.0F;
  }

  localDW->Integrator_PrevResetState = (int16_T)rtb_Compare_m4;

  /* End of Update for DiscreteIntegrator: '<S691>/Integrator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
