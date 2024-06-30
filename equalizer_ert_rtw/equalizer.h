/*
 * File: equalizer.h
 *
 * Code generated for Simulink model 'equalizer'.
 *
 * Model version                  : 4.42
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun 28 19:12:26 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_equalizer_h_
#define RTW_HEADER_equalizer_h_
#ifndef equalizer_COMMON_INCLUDES_
#define equalizer_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* equalizer_COMMON_INCLUDES_ */

#include "equalizer_types.h"
#include "rt_zcfcn.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Memory3[9];                   /* '<S1>/Memory3' */
  real_T Memory[2];                    /* '<S1>/Memory' */
  real_T Memory1[2];                   /* '<S1>/Memory1' */
  real_T Memory2;                      /* '<S1>/Memory2' */
  real_T Abs;                          /* '<S4>/Abs' */
  real_T Abs1;                         /* '<S4>/Abs1' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T Product;                      /* '<S4>/Product' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T Integrator;                   /* '<S4>/Integrator' */
  real_T destinations_batts[2];        /* '<S1>/equalizer' */
  real_T source_batts[2];              /* '<S1>/equalizer' */
  real_T step_cnt_out;                 /* '<S1>/equalizer' */
  real_T I_tranfer;                    /* '<S1>/equalizer' */
  real_T enable_I_trs;                 /* '<S1>/equalizer' */
  real_T AH_out;                       /* '<S2>/MATLAB Function' */
  boolean_T Memory4;                   /* '<S1>/Memory4' */
  boolean_T comparator;                /* '<S4>/comparator' */
} B_equalizer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory3_PreviousInput[9];     /* '<S1>/Memory3' */
  real_T Memory_PreviousInput[2];      /* '<S1>/Memory' */
  real_T Memory1_PreviousInput[2];     /* '<S1>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T enable;                       /* '<S1>/equalizer' */
  int8_T dir;                          /* '<S1>/equalizer' */
  boolean_T Memory4_PreviousInput;     /* '<S1>/Memory4' */
} DW_equalizer_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} X_equalizer_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
} XDot_equalizer_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
} XDis_equalizer_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S4>/Integrator' */
} PrevZCX_equalizer_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T src_q_cls[2];                 /* '<Root>/src_q_cls' */
  real_T dst_q_cls[2];                 /* '<Root>/dst_q_cls' */
  real_T src_trg_soc_av;               /* '<Root>/src_trg_soc_av' */
  real_T dst_trg_soc_av;               /* '<Root>/dst_trg_soc_av' */
  real_T SOC[9];                       /* '<Root>/SOC' */
  real_T SOC_init[9];                  /* '<Root>/SOC_init' */
  real_T I_meas[9];                    /* '<Root>/I_meas' */
  real_T CAP_mAh;                      /* '<Root>/CAP_mAh' */
} ExtU_equalizer_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int8_T dir;                          /* '<Root>/dir' */
  real_T eq_current;                   /* '<Root>/eq_current' */
  real_T soc_est[9];                   /* '<Root>/soc_est' */
  real_T stop_transfer;                /* '<Root>/stop_transfer' */
  uint8_T sw_pos;                      /* '<Root>/sw_pos' */
  uint8_T sw_neg;                      /* '<Root>/sw_neg' */
} ExtY_equalizer_T;

/* Real-time Model Data Structure */
struct tag_RTM_equalizer_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_equalizer_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_equalizer_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_equalizer_T equalizer_B;

/* Continuous states (default storage) */
extern X_equalizer_T equalizer_X;

/* Disabled states (default storage) */
extern XDis_equalizer_T equalizer_XDis;

/* Block states (default storage) */
extern DW_equalizer_T equalizer_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_equalizer_T equalizer_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_equalizer_T equalizer_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_equalizer_T equalizer_Y;

/* Model entry point functions */
extern void equalizer_initialize(void);
extern void equalizer_step(void);
extern void equalizer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_equalizer_T *const equalizer_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<S1>/Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'equalizer'
 * '<S1>'   : 'equalizer/mcu'
 * '<S2>'   : 'equalizer/mcu/AH_calculation'
 * '<S3>'   : 'equalizer/mcu/battery_selector'
 * '<S4>'   : 'equalizer/mcu/charge_trasfer_controller'
 * '<S5>'   : 'equalizer/mcu/equalizer'
 * '<S6>'   : 'equalizer/mcu/AH_calculation/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_equalizer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
