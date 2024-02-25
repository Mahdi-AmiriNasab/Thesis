/*
 * File: DC_DC_source_based_matrix_switches1.h
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

#ifndef RTW_HEADER_DC_DC_source_based_matrix_switches1_h_
#define RTW_HEADER_DC_DC_source_based_matrix_switches1_h_
#ifndef DC_DC_source_based_matrix_switches1_COMMON_INCLUDES_
#define DC_DC_source_based_matrix_switches1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                /* DC_DC_source_based_matrix_switches1_COMMON_INCLUDES_ */

#include "DC_DC_source_based_matrix_switches1_types.h"
#include "coloumb_counting.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "zero_crossing_types.h"

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

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<S189>/NEGATIVE Edge' */
typedef struct {
  boolean_T NEGATIVEEdge_MODE;         /* '<S189>/NEGATIVE Edge' */
} DW_NEGATIVEEdge_DC_DC_source__T;

/* Block states (default storage) for system '<S189>/POSITIVE Edge' */
typedef struct {
  boolean_T POSITIVEEdge_MODE;         /* '<S189>/POSITIVE Edge' */
} DW_POSITIVEEdge_DC_DC_source__T;

/* Block signals (default storage) */
typedef struct {
  real_T Switch2;                      /* '<S41>/Switch2' */
  real_T Switch2_g;                    /* '<S53>/Switch2' */
  real_T Switch2_c;                    /* '<S65>/Switch2' */
  real_T Switch2_g2;                   /* '<S77>/Switch2' */
  real_T Switch2_h;                    /* '<S89>/Switch2' */
  real_T Switch2_n;                    /* '<S101>/Switch2' */
  real_T Switch2_f;                    /* '<S113>/Switch2' */
  real_T Switch2_gw;                   /* '<S125>/Switch2' */
  real_T Switch2_cb;                   /* '<S137>/Switch2' */
  real_T StateSpace_o1[28];            /* '<S207>/State-Space' */
  real_T StateSpace_o2[18];            /* '<S207>/State-Space' */
  real_T StateSpace;                   /* '<S208>/State-Space' */
  real_T Ah_estimator[9];              /* '<S31>/Ah_estimator' */
  real_T destinations_batts[2];        /* '<S31>/equalizer' */
  real_T source_batts[2];              /* '<S31>/equalizer' */
  real_T s1;                           /* '<S31>/demux p' */
  real_T s2;                           /* '<S31>/demux p' */
  real_T s3;                           /* '<S31>/demux p' */
  real_T s4;                           /* '<S31>/demux p' */
  real_T s5;                           /* '<S31>/demux p' */
  real_T s6;                           /* '<S31>/demux p' */
  real_T s7;                           /* '<S31>/demux p' */
  real_T s8;                           /* '<S31>/demux p' */
  real_T s9;                           /* '<S31>/demux p' */
  real_T s1_c;                         /* '<S31>/demux n' */
  real_T s2_k;                         /* '<S31>/demux n' */
  real_T s3_o;                         /* '<S31>/demux n' */
  real_T s4_n;                         /* '<S31>/demux n' */
  real_T s5_f;                         /* '<S31>/demux n' */
  real_T s6_m;                         /* '<S31>/demux n' */
  real_T s7_b;                         /* '<S31>/demux n' */
  real_T s8_i;                         /* '<S31>/demux n' */
  real_T s9_e;                         /* '<S31>/demux n' */
  real_T Switch;                       /* '<S202>/Switch' */
  real_T Switch_e;                     /* '<S194>/Switch' */
  real_T current_left;                 /* '<S10>/MATLAB Function' */
  real_T current_right;                /* '<S10>/MATLAB Function' */
  boolean_T DataTypeConversion1;       /* '<S184>/Data Type Conversion1' */
  boolean_T LogicalOperator2;          /* '<S186>/Logical Operator2' */
  boolean_T RelationalOperator1;       /* '<S200>/Relational Operator1' */
  boolean_T RelationalOperator1_g;     /* '<S199>/Relational Operator1' */
  boolean_T LogicalOperator2_i;        /* '<S185>/Logical Operator2' */
  boolean_T RelationalOperator1_gk;    /* '<S192>/Relational Operator1' */
  boolean_T RelationalOperator1_f;     /* '<S191>/Relational Operator1' */
} B_DC_DC_source_based_matrix_s_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Currentfilter_states;         /* '<S35>/Current filter' */
  real_T inti_DSTATE;                  /* '<S35>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S40>/Discrete-Time Integrator' */
  real_T Currentfilter_states_d;       /* '<S47>/Current filter' */
  real_T inti_DSTATE_j;                /* '<S47>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S52>/Discrete-Time Integrator' */
  real_T Currentfilter_states_f;       /* '<S59>/Current filter' */
  real_T inti_DSTATE_o;                /* '<S59>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S64>/Discrete-Time Integrator' */
  real_T Currentfilter_states_e;       /* '<S71>/Current filter' */
  real_T inti_DSTATE_b;                /* '<S71>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S76>/Discrete-Time Integrator' */
  real_T Currentfilter_states_h;       /* '<S83>/Current filter' */
  real_T inti_DSTATE_g;                /* '<S83>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S88>/Discrete-Time Integrator' */
  real_T Currentfilter_states_c;       /* '<S95>/Current filter' */
  real_T inti_DSTATE_p;                /* '<S95>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S100>/Discrete-Time Integrator' */
  real_T Currentfilter_states_i;       /* '<S107>/Current filter' */
  real_T inti_DSTATE_e;                /* '<S107>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTAT_p1;/* '<S112>/Discrete-Time Integrator' */
  real_T Currentfilter_states_n;       /* '<S119>/Current filter' */
  real_T inti_DSTATE_jo;               /* '<S119>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S124>/Discrete-Time Integrator' */
  real_T Currentfilter_states_o;       /* '<S131>/Current filter' */
  real_T inti_DSTATE_jz;               /* '<S131>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTAT_py;/* '<S136>/Discrete-Time Integrator' */
  real_T StateSpace_DSTATE;            /* '<S208>/State-Space' */
  real_T itinit1_PreviousInput;        /* '<S35>/it init1' */
  real_T itinit_PreviousInput;         /* '<S35>/it init' */
  real_T Memory2_PreviousInput;        /* '<S35>/Memory2' */
  real_T itinit1_PreviousInput_m;      /* '<S47>/it init1' */
  real_T itinit_PreviousInput_c;       /* '<S47>/it init' */
  real_T Memory2_PreviousInput_i;      /* '<S47>/Memory2' */
  real_T itinit1_PreviousInput_n;      /* '<S59>/it init1' */
  real_T itinit_PreviousInput_m;       /* '<S59>/it init' */
  real_T Memory2_PreviousInput_ic;     /* '<S59>/Memory2' */
  real_T itinit1_PreviousInput_e;      /* '<S71>/it init1' */
  real_T itinit_PreviousInput_b;       /* '<S71>/it init' */
  real_T Memory2_PreviousInput_e;      /* '<S71>/Memory2' */
  real_T itinit1_PreviousInput_nf;     /* '<S83>/it init1' */
  real_T itinit_PreviousInput_l;       /* '<S83>/it init' */
  real_T Memory2_PreviousInput_g;      /* '<S83>/Memory2' */
  real_T itinit1_PreviousInput_j;      /* '<S95>/it init1' */
  real_T itinit_PreviousInput_f;       /* '<S95>/it init' */
  real_T Memory2_PreviousInput_ix;     /* '<S95>/Memory2' */
  real_T itinit1_PreviousInput_d;      /* '<S107>/it init1' */
  real_T itinit_PreviousInput_k;       /* '<S107>/it init' */
  real_T Memory2_PreviousInput_ey;     /* '<S107>/Memory2' */
  real_T itinit1_PreviousInput_g;      /* '<S119>/it init1' */
  real_T itinit_PreviousInput_g;       /* '<S119>/it init' */
  real_T Memory2_PreviousInput_ge;     /* '<S119>/Memory2' */
  real_T itinit1_PreviousInput_c;      /* '<S131>/it init1' */
  real_T itinit_PreviousInput_cu;      /* '<S131>/it init' */
  real_T Memory2_PreviousInput_d;      /* '<S131>/Memory2' */
  real_T Memory1_PreviousInput;        /* '<S10>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S10>/Memory' */
  real_T Memory_PreviousInput_f[2];    /* '<S31>/Memory' */
  real_T Memory1_PreviousInput_n[2];   /* '<S31>/Memory1' */
  real_T step_cnt;                     /* '<S31>/equalizer' */
  real_T ICic_PreviousInput;           /* '<S202>/IC=ic' */
  real_T ICic_PreviousInput_a;         /* '<S194>/IC=ic' */
  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *G_STATE;
    void *USWLAST;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
    void *SWITCH_TOPO_SAVED_IDX;
    void *SWITCH_MAP;
  } StateSpace_PWORK;                  /* '<S207>/State-Space' */

  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *G_STATE;
    void *USWLAST;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
    void *SWITCH_TOPO_SAVED_IDX;
    void *SWITCH_MAP;
  } StateSpace_PWORK_p;                /* '<S208>/State-Space' */

  int_T StateSpace_IWORK[11];          /* '<S207>/State-Space' */
  int_T StateSpace_IWORK_k[11];        /* '<S208>/State-Space' */
  int8_T inti_PrevResetState;          /* '<S35>/int(i)' */
  int8_T inti_PrevResetState_m;        /* '<S47>/int(i)' */
  int8_T inti_PrevResetState_e;        /* '<S59>/int(i)' */
  int8_T inti_PrevResetState_p;        /* '<S71>/int(i)' */
  int8_T inti_PrevResetState_l;        /* '<S83>/int(i)' */
  int8_T inti_PrevResetState_n;        /* '<S95>/int(i)' */
  int8_T inti_PrevResetState_k;        /* '<S107>/int(i)' */
  int8_T inti_PrevResetState_o;        /* '<S119>/int(i)' */
  int8_T inti_PrevResetState_c;        /* '<S131>/int(i)' */
  uint8_T inti_IC_LOADING;             /* '<S35>/int(i)' */
  uint8_T inti_IC_LOADING_o;           /* '<S47>/int(i)' */
  uint8_T inti_IC_LOADING_c;           /* '<S59>/int(i)' */
  uint8_T inti_IC_LOADING_b;           /* '<S71>/int(i)' */
  uint8_T inti_IC_LOADING_f;           /* '<S83>/int(i)' */
  uint8_T inti_IC_LOADING_j;           /* '<S95>/int(i)' */
  uint8_T inti_IC_LOADING_p;           /* '<S107>/int(i)' */
  uint8_T inti_IC_LOADING_o1;          /* '<S119>/int(i)' */
  uint8_T inti_IC_LOADING_a;           /* '<S131>/int(i)' */
  boolean_T Relay_Mode;                /* '<S10>/Relay' */
  boolean_T Memory_PreviousInput_p;    /* '<S197>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S189>/Memory' */
  boolean_T ONDelay_MODE;              /* '<S184>/ON Delay' */
  boolean_T OFFDelay_MODE;             /* '<S184>/OFF Delay' */
  MdlrefDW_coloumb_counting_T Ah_estimator_InstanceData;/* '<S31>/Ah_estimator' */
  DW_POSITIVEEdge_DC_DC_source__T POSITIVEEdge_d;/* '<S197>/POSITIVE Edge' */
  DW_NEGATIVEEdge_DC_DC_source__T NEGATIVEEdge_b;/* '<S197>/NEGATIVE Edge' */
  DW_POSITIVEEdge_DC_DC_source__T POSITIVEEdge;/* '<S189>/POSITIVE Edge' */
  DW_NEGATIVEEdge_DC_DC_source__T NEGATIVEEdge;/* '<S189>/NEGATIVE Edge' */
} DW_DC_DC_source_based_matrix__T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S198>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_i;/* '<S190>/Triggered Subsystem' */
} PrevZCX_DC_DC_source_based_ma_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S197>/Multiport Switch' */
  const real_T MultiportSwitch_e[2];   /* '<S189>/Multiport Switch' */
  const boolean_T RelationalOperator1; /* '<S184>/Relational Operator1' */
  const boolean_T LogicalOperator2;    /* '<S184>/Logical Operator2' */
} ConstB_DC_DC_source_based_mat_T;

/* Real-time Model Data Structure */
struct tag_RTM_DC_DC_source_based_ma_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint32_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block signals (default storage) */
extern B_DC_DC_source_based_matrix_s_T DC_DC_source_based_matrix_swi_B;

/* Block states (default storage) */
extern DW_DC_DC_source_based_matrix__T DC_DC_source_based_matrix_sw_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_DC_DC_source_based_ma_T DC_DC_source_based_matr_PrevZCX;
extern const ConstB_DC_DC_source_based_mat_T DC_DC_source_based_matri_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void DC_DC_source_based_matrix_switches1_initialize(void);
extern void DC_DC_source_based_matrix_switches1_step(void);
extern void DC_DC_source_based_matrix_switches1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DC_DC_source_based_m_T *const DC_DC_source_based_matrix_sw_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S35>/Add' : Unused code path elimination
 * Block '<S35>/R' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Propagation' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Ta' : Unused code path elimination
 * Block '<S47>/Add' : Unused code path elimination
 * Block '<S47>/R' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Propagation' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Ta' : Unused code path elimination
 * Block '<S59>/Add' : Unused code path elimination
 * Block '<S59>/R' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Ta' : Unused code path elimination
 * Block '<S71>/Add' : Unused code path elimination
 * Block '<S71>/R' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Propagation' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Propagation' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Ta' : Unused code path elimination
 * Block '<S83>/Add' : Unused code path elimination
 * Block '<S83>/R' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Propagation' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Propagation' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Ta' : Unused code path elimination
 * Block '<S95>/Add' : Unused code path elimination
 * Block '<S95>/R' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Propagation' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Propagation' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Ta' : Unused code path elimination
 * Block '<S107>/Add' : Unused code path elimination
 * Block '<S107>/R' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Propagation' : Unused code path elimination
 * Block '<S114>/Data Type Duplicate' : Unused code path elimination
 * Block '<S114>/Data Type Propagation' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Ta' : Unused code path elimination
 * Block '<S119>/Add' : Unused code path elimination
 * Block '<S119>/R' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Propagation' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Propagation' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Ta' : Unused code path elimination
 * Block '<S131>/Add' : Unused code path elimination
 * Block '<S131>/R' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Data Type Propagation' : Unused code path elimination
 * Block '<S138>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Data Type Propagation' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/Ta' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<S10>/Display1' : Unused code path elimination
 * Block '<S10>/Display2' : Unused code path elimination
 * Block '<S10>/Display3' : Unused code path elimination
 * Block '<S10>/Display4' : Unused code path elimination
 * Block '<S10>/Product' : Unused code path elimination
 * Block '<S10>/Product1' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<S148>/0 1' : Unused code path elimination
 * Block '<S148>/1//Rsw' : Unused code path elimination
 * Block '<S148>/Switch' : Unused code path elimination
 * Block '<S150>/0 1' : Unused code path elimination
 * Block '<S150>/1//Rsw' : Unused code path elimination
 * Block '<S150>/Switch' : Unused code path elimination
 * Block '<S152>/0 1' : Unused code path elimination
 * Block '<S152>/1//Rsw' : Unused code path elimination
 * Block '<S152>/Switch' : Unused code path elimination
 * Block '<S154>/0 1' : Unused code path elimination
 * Block '<S154>/1//Rsw' : Unused code path elimination
 * Block '<S154>/Switch' : Unused code path elimination
 * Block '<S156>/0 1' : Unused code path elimination
 * Block '<S156>/1//Rsw' : Unused code path elimination
 * Block '<S156>/Switch' : Unused code path elimination
 * Block '<S158>/0 1' : Unused code path elimination
 * Block '<S158>/1//Rsw' : Unused code path elimination
 * Block '<S158>/Switch' : Unused code path elimination
 * Block '<S160>/0 1' : Unused code path elimination
 * Block '<S160>/1//Rsw' : Unused code path elimination
 * Block '<S160>/Switch' : Unused code path elimination
 * Block '<S162>/0 1' : Unused code path elimination
 * Block '<S162>/1//Rsw' : Unused code path elimination
 * Block '<S162>/Switch' : Unused code path elimination
 * Block '<S164>/0 1' : Unused code path elimination
 * Block '<S164>/1//Rsw' : Unused code path elimination
 * Block '<S164>/Switch' : Unused code path elimination
 * Block '<S166>/0 1' : Unused code path elimination
 * Block '<S166>/1//Rsw' : Unused code path elimination
 * Block '<S166>/Switch' : Unused code path elimination
 * Block '<S168>/0 1' : Unused code path elimination
 * Block '<S168>/1//Rsw' : Unused code path elimination
 * Block '<S168>/Switch' : Unused code path elimination
 * Block '<S170>/0 1' : Unused code path elimination
 * Block '<S170>/1//Rsw' : Unused code path elimination
 * Block '<S170>/Switch' : Unused code path elimination
 * Block '<S172>/0 1' : Unused code path elimination
 * Block '<S172>/1//Rsw' : Unused code path elimination
 * Block '<S172>/Switch' : Unused code path elimination
 * Block '<S174>/0 1' : Unused code path elimination
 * Block '<S174>/1//Rsw' : Unused code path elimination
 * Block '<S174>/Switch' : Unused code path elimination
 * Block '<S176>/0 1' : Unused code path elimination
 * Block '<S176>/1//Rsw' : Unused code path elimination
 * Block '<S176>/Switch' : Unused code path elimination
 * Block '<S178>/0 1' : Unused code path elimination
 * Block '<S178>/1//Rsw' : Unused code path elimination
 * Block '<S178>/Switch' : Unused code path elimination
 * Block '<S180>/0 1' : Unused code path elimination
 * Block '<S180>/1//Rsw' : Unused code path elimination
 * Block '<S180>/Switch' : Unused code path elimination
 * Block '<S182>/0 1' : Unused code path elimination
 * Block '<S182>/1//Rsw' : Unused code path elimination
 * Block '<S182>/Switch' : Unused code path elimination
 * Block '<Root>/MinMax' : Unused code path elimination
 * Block '<Root>/MinMax1' : Unused code path elimination
 * Block '<S190>/Constant' : Unused code path elimination
 * Block '<S190>/Relational Operator' : Unused code path elimination
 * Block '<S190>/Sum' : Unused code path elimination
 * Block '<S198>/Constant' : Unused code path elimination
 * Block '<S198>/Relational Operator' : Unused code path elimination
 * Block '<S198>/Sum' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Subtract' : Unused code path elimination
 * Block '<S31>/Display' : Unused code path elimination
 * Block '<S34>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S46>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S58>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S70>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S82>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S94>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S106>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S118>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S130>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S144>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S145>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S148>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S152>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S154>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S156>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S158>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S162>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S164>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S166>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S168>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S170>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S172>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S174>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S176>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S178>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S180>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S182>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S189>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S194>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S197>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S202>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'DC_DC_source_based_matrix_switches1'
 * '<S1>'   : 'DC_DC_source_based_matrix_switches1/B1'
 * '<S2>'   : 'DC_DC_source_based_matrix_switches1/B2'
 * '<S3>'   : 'DC_DC_source_based_matrix_switches1/B3'
 * '<S4>'   : 'DC_DC_source_based_matrix_switches1/B4'
 * '<S5>'   : 'DC_DC_source_based_matrix_switches1/B5'
 * '<S6>'   : 'DC_DC_source_based_matrix_switches1/B6'
 * '<S7>'   : 'DC_DC_source_based_matrix_switches1/B7'
 * '<S8>'   : 'DC_DC_source_based_matrix_switches1/B8'
 * '<S9>'   : 'DC_DC_source_based_matrix_switches1/B9'
 * '<S10>'  : 'DC_DC_source_based_matrix_switches1/DC-DC converter'
 * '<S11>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch'
 * '<S12>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch1'
 * '<S13>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch10'
 * '<S14>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch11'
 * '<S15>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch12'
 * '<S16>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch13'
 * '<S17>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch14'
 * '<S18>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch15'
 * '<S19>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch16'
 * '<S20>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch17'
 * '<S21>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch2'
 * '<S22>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch3'
 * '<S23>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch4'
 * '<S24>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch5'
 * '<S25>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch6'
 * '<S26>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch7'
 * '<S27>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch8'
 * '<S28>'  : 'DC_DC_source_based_matrix_switches1/Ideal Switch9'
 * '<S29>'  : 'DC_DC_source_based_matrix_switches1/On Delay'
 * '<S30>'  : 'DC_DC_source_based_matrix_switches1/Subsystem'
 * '<S31>'  : 'DC_DC_source_based_matrix_switches1/mcu'
 * '<S32>'  : 'DC_DC_source_based_matrix_switches1/powergui'
 * '<S33>'  : 'DC_DC_source_based_matrix_switches1/B1/Controlled Voltage Source'
 * '<S34>'  : 'DC_DC_source_based_matrix_switches1/B1/Current Measurement'
 * '<S35>'  : 'DC_DC_source_based_matrix_switches1/B1/Model'
 * '<S36>'  : 'DC_DC_source_based_matrix_switches1/B1/Current Measurement/Model'
 * '<S37>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Compare To Zero'
 * '<S38>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Compare To Zero2'
 * '<S39>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/E_dyn Charge'
 * '<S40>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Exp'
 * '<S41>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Saturation Dynamic'
 * '<S42>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Saturation Dynamic1'
 * '<S43>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Saturation Dynamic2'
 * '<S44>'  : 'DC_DC_source_based_matrix_switches1/B1/Model/Exp/Compare To Zero2'
 * '<S45>'  : 'DC_DC_source_based_matrix_switches1/B2/Controlled Voltage Source'
 * '<S46>'  : 'DC_DC_source_based_matrix_switches1/B2/Current Measurement'
 * '<S47>'  : 'DC_DC_source_based_matrix_switches1/B2/Model'
 * '<S48>'  : 'DC_DC_source_based_matrix_switches1/B2/Current Measurement/Model'
 * '<S49>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Compare To Zero'
 * '<S50>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Compare To Zero2'
 * '<S51>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/E_dyn Charge'
 * '<S52>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Exp'
 * '<S53>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Saturation Dynamic'
 * '<S54>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Saturation Dynamic1'
 * '<S55>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Saturation Dynamic2'
 * '<S56>'  : 'DC_DC_source_based_matrix_switches1/B2/Model/Exp/Compare To Zero2'
 * '<S57>'  : 'DC_DC_source_based_matrix_switches1/B3/Controlled Voltage Source'
 * '<S58>'  : 'DC_DC_source_based_matrix_switches1/B3/Current Measurement'
 * '<S59>'  : 'DC_DC_source_based_matrix_switches1/B3/Model'
 * '<S60>'  : 'DC_DC_source_based_matrix_switches1/B3/Current Measurement/Model'
 * '<S61>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Compare To Zero'
 * '<S62>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Compare To Zero2'
 * '<S63>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/E_dyn Charge'
 * '<S64>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Exp'
 * '<S65>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Saturation Dynamic'
 * '<S66>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Saturation Dynamic1'
 * '<S67>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Saturation Dynamic2'
 * '<S68>'  : 'DC_DC_source_based_matrix_switches1/B3/Model/Exp/Compare To Zero2'
 * '<S69>'  : 'DC_DC_source_based_matrix_switches1/B4/Controlled Voltage Source'
 * '<S70>'  : 'DC_DC_source_based_matrix_switches1/B4/Current Measurement'
 * '<S71>'  : 'DC_DC_source_based_matrix_switches1/B4/Model'
 * '<S72>'  : 'DC_DC_source_based_matrix_switches1/B4/Current Measurement/Model'
 * '<S73>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Compare To Zero'
 * '<S74>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Compare To Zero2'
 * '<S75>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/E_dyn Charge'
 * '<S76>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Exp'
 * '<S77>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Saturation Dynamic'
 * '<S78>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Saturation Dynamic1'
 * '<S79>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Saturation Dynamic2'
 * '<S80>'  : 'DC_DC_source_based_matrix_switches1/B4/Model/Exp/Compare To Zero2'
 * '<S81>'  : 'DC_DC_source_based_matrix_switches1/B5/Controlled Voltage Source'
 * '<S82>'  : 'DC_DC_source_based_matrix_switches1/B5/Current Measurement'
 * '<S83>'  : 'DC_DC_source_based_matrix_switches1/B5/Model'
 * '<S84>'  : 'DC_DC_source_based_matrix_switches1/B5/Current Measurement/Model'
 * '<S85>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Compare To Zero'
 * '<S86>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Compare To Zero2'
 * '<S87>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/E_dyn Charge'
 * '<S88>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Exp'
 * '<S89>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Saturation Dynamic'
 * '<S90>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Saturation Dynamic1'
 * '<S91>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Saturation Dynamic2'
 * '<S92>'  : 'DC_DC_source_based_matrix_switches1/B5/Model/Exp/Compare To Zero2'
 * '<S93>'  : 'DC_DC_source_based_matrix_switches1/B6/Controlled Voltage Source'
 * '<S94>'  : 'DC_DC_source_based_matrix_switches1/B6/Current Measurement'
 * '<S95>'  : 'DC_DC_source_based_matrix_switches1/B6/Model'
 * '<S96>'  : 'DC_DC_source_based_matrix_switches1/B6/Current Measurement/Model'
 * '<S97>'  : 'DC_DC_source_based_matrix_switches1/B6/Model/Compare To Zero'
 * '<S98>'  : 'DC_DC_source_based_matrix_switches1/B6/Model/Compare To Zero2'
 * '<S99>'  : 'DC_DC_source_based_matrix_switches1/B6/Model/E_dyn Charge'
 * '<S100>' : 'DC_DC_source_based_matrix_switches1/B6/Model/Exp'
 * '<S101>' : 'DC_DC_source_based_matrix_switches1/B6/Model/Saturation Dynamic'
 * '<S102>' : 'DC_DC_source_based_matrix_switches1/B6/Model/Saturation Dynamic1'
 * '<S103>' : 'DC_DC_source_based_matrix_switches1/B6/Model/Saturation Dynamic2'
 * '<S104>' : 'DC_DC_source_based_matrix_switches1/B6/Model/Exp/Compare To Zero2'
 * '<S105>' : 'DC_DC_source_based_matrix_switches1/B7/Controlled Voltage Source'
 * '<S106>' : 'DC_DC_source_based_matrix_switches1/B7/Current Measurement'
 * '<S107>' : 'DC_DC_source_based_matrix_switches1/B7/Model'
 * '<S108>' : 'DC_DC_source_based_matrix_switches1/B7/Current Measurement/Model'
 * '<S109>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Compare To Zero'
 * '<S110>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Compare To Zero2'
 * '<S111>' : 'DC_DC_source_based_matrix_switches1/B7/Model/E_dyn Charge'
 * '<S112>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Exp'
 * '<S113>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Saturation Dynamic'
 * '<S114>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Saturation Dynamic1'
 * '<S115>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Saturation Dynamic2'
 * '<S116>' : 'DC_DC_source_based_matrix_switches1/B7/Model/Exp/Compare To Zero2'
 * '<S117>' : 'DC_DC_source_based_matrix_switches1/B8/Controlled Voltage Source'
 * '<S118>' : 'DC_DC_source_based_matrix_switches1/B8/Current Measurement'
 * '<S119>' : 'DC_DC_source_based_matrix_switches1/B8/Model'
 * '<S120>' : 'DC_DC_source_based_matrix_switches1/B8/Current Measurement/Model'
 * '<S121>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Compare To Zero'
 * '<S122>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Compare To Zero2'
 * '<S123>' : 'DC_DC_source_based_matrix_switches1/B8/Model/E_dyn Charge'
 * '<S124>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Exp'
 * '<S125>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Saturation Dynamic'
 * '<S126>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Saturation Dynamic1'
 * '<S127>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Saturation Dynamic2'
 * '<S128>' : 'DC_DC_source_based_matrix_switches1/B8/Model/Exp/Compare To Zero2'
 * '<S129>' : 'DC_DC_source_based_matrix_switches1/B9/Controlled Voltage Source'
 * '<S130>' : 'DC_DC_source_based_matrix_switches1/B9/Current Measurement'
 * '<S131>' : 'DC_DC_source_based_matrix_switches1/B9/Model'
 * '<S132>' : 'DC_DC_source_based_matrix_switches1/B9/Current Measurement/Model'
 * '<S133>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Compare To Zero'
 * '<S134>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Compare To Zero2'
 * '<S135>' : 'DC_DC_source_based_matrix_switches1/B9/Model/E_dyn Charge'
 * '<S136>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Exp'
 * '<S137>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Saturation Dynamic'
 * '<S138>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Saturation Dynamic1'
 * '<S139>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Saturation Dynamic2'
 * '<S140>' : 'DC_DC_source_based_matrix_switches1/B9/Model/Exp/Compare To Zero2'
 * '<S141>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/Controlled Current Source'
 * '<S142>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/Controlled Current Source1'
 * '<S143>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/MATLAB Function'
 * '<S144>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/Voltage Measurement1'
 * '<S145>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/Voltage Measurement2'
 * '<S146>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/Voltage Measurement1/Model'
 * '<S147>' : 'DC_DC_source_based_matrix_switches1/DC-DC converter/Voltage Measurement2/Model'
 * '<S148>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch/Model'
 * '<S149>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch/Model/Measurement list'
 * '<S150>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch1/Model'
 * '<S151>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch1/Model/Measurement list'
 * '<S152>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch10/Model'
 * '<S153>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch10/Model/Measurement list'
 * '<S154>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch11/Model'
 * '<S155>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch11/Model/Measurement list'
 * '<S156>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch12/Model'
 * '<S157>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch12/Model/Measurement list'
 * '<S158>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch13/Model'
 * '<S159>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch13/Model/Measurement list'
 * '<S160>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch14/Model'
 * '<S161>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch14/Model/Measurement list'
 * '<S162>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch15/Model'
 * '<S163>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch15/Model/Measurement list'
 * '<S164>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch16/Model'
 * '<S165>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch16/Model/Measurement list'
 * '<S166>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch17/Model'
 * '<S167>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch17/Model/Measurement list'
 * '<S168>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch2/Model'
 * '<S169>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch2/Model/Measurement list'
 * '<S170>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch3/Model'
 * '<S171>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch3/Model/Measurement list'
 * '<S172>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch4/Model'
 * '<S173>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch4/Model/Measurement list'
 * '<S174>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch5/Model'
 * '<S175>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch5/Model/Measurement list'
 * '<S176>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch6/Model'
 * '<S177>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch6/Model/Measurement list'
 * '<S178>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch7/Model'
 * '<S179>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch7/Model/Measurement list'
 * '<S180>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch8/Model'
 * '<S181>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch8/Model/Measurement list'
 * '<S182>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch9/Model'
 * '<S183>' : 'DC_DC_source_based_matrix_switches1/Ideal Switch9/Model/Measurement list'
 * '<S184>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model'
 * '<S185>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay'
 * '<S186>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay'
 * '<S187>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Edge Detector'
 * '<S188>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Sample and Hold'
 * '<S189>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Edge Detector/Model'
 * '<S190>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator'
 * '<S191>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S192>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S193>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S194>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/OFF Delay/Sample and Hold/Model'
 * '<S195>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Edge Detector'
 * '<S196>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Sample and Hold'
 * '<S197>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Edge Detector/Model'
 * '<S198>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator'
 * '<S199>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Edge Detector/Model/NEGATIVE Edge'
 * '<S200>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Edge Detector/Model/POSITIVE Edge'
 * '<S201>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Edge Detector/Model/Internal dirac generator/Triggered Subsystem'
 * '<S202>' : 'DC_DC_source_based_matrix_switches1/On Delay/Model/ON Delay/Sample and Hold/Model'
 * '<S203>' : 'DC_DC_source_based_matrix_switches1/mcu/battery_selector'
 * '<S204>' : 'DC_DC_source_based_matrix_switches1/mcu/demux n'
 * '<S205>' : 'DC_DC_source_based_matrix_switches1/mcu/demux p'
 * '<S206>' : 'DC_DC_source_based_matrix_switches1/mcu/equalizer'
 * '<S207>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel1'
 * '<S208>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel2'
 * '<S209>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel1/Gates'
 * '<S210>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel1/Sources'
 * '<S211>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel1/Status'
 * '<S212>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel1/Yout'
 * '<S213>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel2/Sources'
 * '<S214>' : 'DC_DC_source_based_matrix_switches1/powergui/EquivalentModel2/Yout'
 */
#endif                   /* RTW_HEADER_DC_DC_source_based_matrix_switches1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
