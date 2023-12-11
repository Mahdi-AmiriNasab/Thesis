/*
 * File: RCTcc.h
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

#ifndef RTW_HEADER_RCTcc_h_
#define RTW_HEADER_RCTcc_h_
#ifndef test3_COMMON_INCLUDES_
#define test3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* test3_COMMON_INCLUDES_ */

/* Block signals for system '<Root>/RCTcc' */
typedef struct {
  real32_T Probe[2];                   /* '<S686>/Probe' */
  real32_T RD_OUT;                     /* '<S100>/Chart1' */
} B_RCTcc_test3_T;

/* Block states (default storage) for system '<Root>/RCTcc' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S691>/Integrator' */
  real32_T PrevY;                      /* '<S100>/Rate Limiter' */
  real32_T Mileage2;                   /* '<S100>/Chart1' */
  real32_T Mileage1;                   /* '<S100>/Chart1' */
  real32_T SOE1;                       /* '<S100>/Chart1' */
  real32_T RD_OUT1;                    /* '<S100>/Chart1' */
  real32_T RD_OUT2;                    /* '<S100>/Chart1' */
  real32_T RD_OUT3;                    /* '<S100>/Chart1' */
  real32_T Mileage3;                   /* '<S100>/Chart1' */
  int32_T sfEvent;                     /* '<S100>/Chart1' */
  int16_T Integrator_PrevResetState;   /* '<S691>/Integrator' */
  uint16_T Integrator_IC_LOADING;      /* '<S691>/Integrator' */
  uint16_T is_active_c6_test3;         /* '<S100>/Chart1' */
  uint16_T is_Control;                 /* '<S100>/Chart1' */
  uint16_T is_active_Control;          /* '<S100>/Chart1' */
  uint16_T is_Estimate_Mileage;        /* '<S100>/Chart1' */
  uint16_T is_active_Estimate_Mileage; /* '<S100>/Chart1' */
  uint16_T temporalCounter_i1;         /* '<S100>/Chart1' */
} DW_RCTcc_test3_T;

extern void test3_RCTcc_Init(B_RCTcc_test3_T *localB, DW_RCTcc_test3_T *localDW);
extern void test3_RCTcc(uint16_T rtu_Capacity, real32_T rtu_Pack_Current,
  uint16_T rtu_ReqSOC, real32_T rtu_Fake_SOC, real32_T rtu_SOC, real32_T
  rtu_Mileage, real32_T *rty_RCT, real32_T *rty_RD_NEDC_F, real32_T *rty_RDT,
  real32_T *rty_Add_Mileage_Range, real32_T *rty_SOE, real32_T *rty_RD_NEDC_F1,
  B_RCTcc_test3_T *localB, DW_RCTcc_test3_T *localDW);

#endif                                 /* RTW_HEADER_RCTcc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
