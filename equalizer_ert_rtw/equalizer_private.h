/*
 * File: equalizer_private.h
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

#ifndef RTW_HEADER_equalizer_private_h_
#define RTW_HEADER_equalizer_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "equalizer_types.h"
#include "equalizer.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void equalizer_demuxn(real_T rtu_u, real_T *rty_s1, real_T *rty_s2,
  real_T *rty_s3, real_T *rty_s4, real_T *rty_s5, real_T *rty_s6, real_T *rty_s7,
  real_T *rty_s8, real_T *rty_s9);

/* private model entry point functions */
extern void equalizer_derivatives(void);

#endif                                 /* RTW_HEADER_equalizer_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
