/*
 * File: mcu.h
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

#ifndef RTW_HEADER_mcu_h_
#define RTW_HEADER_mcu_h_
#ifndef mcu_COMMON_INCLUDES_
#define mcu_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* mcu_COMMON_INCLUDES_ */

#include "mcu_types.h"
#include "coloumb_counting.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
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

/* Block signals (default storage) */
typedef struct {
  real_T Memory[2];                    /* '<S1>/Memory' */
  real_T Memory1[2];                   /* '<S1>/Memory1' */
  real_T RateTransition[9];            /* '<S1>/Rate Transition' */
  real_T RateTransition1[9];           /* '<S1>/Rate Transition1' */
  real_T Ah_estimator[9];              /* '<S1>/Ah_estimator' */
  real_T destinations_batts[2];        /* '<S1>/equalizer' */
  real_T source_batts[2];              /* '<S1>/equalizer' */
  real_T step_cnt_out;                 /* '<S1>/equalizer' */
  real_T stop_simulation;              /* '<S1>/equalizer' */
  real_T sw_pos;                       /* '<S1>/battery_selector' */
  real_T sw_neg;                       /* '<S1>/battery_selector' */
} B_mcu_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput[2];      /* '<S1>/Memory' */
  real_T Memory1_PreviousInput[2];     /* '<S1>/Memory1' */
  real_T RateTransition_Buffer[9];     /* '<S1>/Rate Transition' */
  real_T RateTransition1_Buffer[9];    /* '<S1>/Rate Transition1' */
  real_T step_cnt;                     /* '<S1>/equalizer' */
  MdlrefDW_coloumb_counting_T Ah_estimator_InstanceData;/* '<S1>/Ah_estimator' */
} DW_mcu_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T src_q_cls[100];               /* '<Root>/src_q_cls' */
  real_T dst_q_cls[100];               /* '<Root>/dst_q_cls' */
  real_T src_trg_soc_av[50];           /* '<Root>/src_trg_soc_av' */
  real_T dst_trg_soc_av[50];           /* '<Root>/dst_trg_soc_av' */
  real_T SOC[9];                       /* '<Root>/SOC' */
  real_T CAP_Ah;                       /* '<Root>/CAP_Ah' */
  real_T SOC_c[9];                     /* '<Root>/SOC_init' */
  real_T current[9];                   /* '<Root>/I_meas' */
  real_T voltage;                      /* '<Root>/V_batt' */
} ExtU_mcu_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T g1p;                          /* '<Root>/g1p' */
  real_T g2p;                          /* '<Root>/g2p' */
  real_T g3p;                          /* '<Root>/g3p' */
  real_T g4p;                          /* '<Root>/g4p' */
  real_T g5p;                          /* '<Root>/g5p' */
  real_T g6p;                          /* '<Root>/g6p' */
  real_T g7p;                          /* '<Root>/g7p' */
  real_T g8p;                          /* '<Root>/g8p' */
  real_T g9p;                          /* '<Root>/g9p' */
  real_T g1n;                          /* '<Root>/g1n' */
  real_T g2n;                          /* '<Root>/g2n' */
  real_T g3n;                          /* '<Root>/g3n' */
  real_T g4n;                          /* '<Root>/g4n' */
  real_T g5n;                          /* '<Root>/g5n' */
  real_T g6n;                          /* '<Root>/g6n' */
  real_T g7n;                          /* '<Root>/g7n' */
  real_T g8n;                          /* '<Root>/g8n' */
  real_T g9n;                          /* '<Root>/g9n' */
  real_T eq_current;                   /* '<Root>/eq_current' */
} ExtY_mcu_T;

/* Real-time Model Data Structure */
struct tag_RTM_mcu_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[2];
    } TaskCounters;

    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_mcu_T mcu_B;

/* Block states (default storage) */
extern DW_mcu_T mcu_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_mcu_T mcu_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_mcu_T mcu_Y;

/* Model entry point functions */
extern void mcu_initialize(void);
extern void mcu_step(void);
extern void mcu_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcu_T *const mcu_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('DC_DC_source_based_matrix_switches1/mcu')    - opens subsystem DC_DC_source_based_matrix_switches1/mcu
 * hilite_system('DC_DC_source_based_matrix_switches1/mcu/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DC_DC_source_based_matrix_switches1'
 * '<S1>'   : 'DC_DC_source_based_matrix_switches1/mcu'
 * '<S2>'   : 'DC_DC_source_based_matrix_switches1/mcu/battery_selector'
 * '<S3>'   : 'DC_DC_source_based_matrix_switches1/mcu/demux n'
 * '<S4>'   : 'DC_DC_source_based_matrix_switches1/mcu/demux p'
 * '<S5>'   : 'DC_DC_source_based_matrix_switches1/mcu/equalizer'
 */
#endif                                 /* RTW_HEADER_mcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
