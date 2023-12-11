/*
 * File: test3.h
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

#ifndef RTW_HEADER_test3_h_
#define RTW_HEADER_test3_h_
#ifndef test3_COMMON_INCLUDES_
#define test3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* test3_COMMON_INCLUDES_ */

#include "test3_types.h"
#include "RCTcc.h"
#include <stddef.h>
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<Root>/Moving Average' */
typedef struct {
  real32_T ChargeCurrentLimit;         /* '<Root>/Moving Average' */
} B_MovingAverage_test3_T;

/* Block states (default storage) for system '<Root>/Moving Average' */
typedef struct {
  dsp_simulink_MovingAverage_te_T obj; /* '<Root>/Moving Average' */
  boolean_T objisempty;                /* '<Root>/Moving Average' */
} DW_MovingAverage_test3_T;

/* Block signals (default storage) */
typedef struct {
  real32_T TmpSignalConversionAtSFunctionI[96];
  boolean_T BalCmd[96];                /* '<S97>/Chart' */
  real32_T TmpSignalConversionAtSFunctio_g[16];
  real32_T csumrev[11];
  real_T d;
  real32_T Probe[2];                   /* '<S101>/Probe' */
  real32_T Probe_l[2];                 /* '<S167>/Probe' */
  real32_T Probe_i[2];                 /* '<S233>/Probe' */
  real32_T Probe_o[2];                 /* '<S299>/Probe' */
  real32_T Probe_ii[2];                /* '<S365>/Probe' */
  real32_T Probe_e[2];                 /* '<S431>/Probe' */
  real32_T Probe_n[2];                 /* '<S497>/Probe' */
  real32_T Probe_ng[2];                /* '<S563>/Probe' */
  real32_T Probe_no[2];                /* '<S629>/Probe' */
  real32_T Probe_b[2];                 /* '<S107>/Probe' */
  real32_T Probe_j[2];                 /* '<S113>/Probe' */
  real32_T Probe_os[2];                /* '<S119>/Probe' */
  real32_T Probe_m[2];                 /* '<S125>/Probe' */
  real32_T Probe_c[2];                 /* '<S131>/Probe' */
  real32_T Probe_lt[2];                /* '<S137>/Probe' */
  real32_T Probe_ik[2];                /* '<S143>/Probe' */
  real32_T Probe_ct[2];                /* '<S149>/Probe' */
  real32_T Probe_f[2];                 /* '<S155>/Probe' */
  real32_T Probe_fp[2];                /* '<S161>/Probe' */
  real32_T Probe_g[2];                 /* '<S173>/Probe' */
  real32_T Probe_h[2];                 /* '<S179>/Probe' */
  real32_T Probe_o4[2];                /* '<S185>/Probe' */
  real32_T Probe_fc[2];                /* '<S191>/Probe' */
  real32_T Probe_f1[2];                /* '<S197>/Probe' */
  real32_T Probe_bf[2];                /* '<S203>/Probe' */
  real32_T Probe_gu[2];                /* '<S209>/Probe' */
  real32_T Probe_er[2];                /* '<S215>/Probe' */
  real32_T Probe_hq[2];                /* '<S221>/Probe' */
  real32_T Probe_md[2];                /* '<S227>/Probe' */
  real32_T Probe_p[2];                 /* '<S239>/Probe' */
  real32_T Probe_pe[2];                /* '<S245>/Probe' */
  real32_T Probe_gb[2];                /* '<S251>/Probe' */
  real32_T Probe_gs[2];                /* '<S257>/Probe' */
  real32_T Probe_p1[2];                /* '<S263>/Probe' */
  real32_T Probe_j0[2];                /* '<S269>/Probe' */
  real32_T Probe_ib[2];                /* '<S275>/Probe' */
  real32_T Probe_nm[2];                /* '<S281>/Probe' */
  real32_T Probe_hh[2];                /* '<S287>/Probe' */
  real32_T Probe_d[2];                 /* '<S293>/Probe' */
  real32_T Probe_fv[2];                /* '<S305>/Probe' */
  real32_T Probe_ij[2];                /* '<S311>/Probe' */
  real32_T Probe_pk[2];                /* '<S317>/Probe' */
  real32_T Probe_a[2];                 /* '<S323>/Probe' */
  real32_T Probe_fpu[2];               /* '<S329>/Probe' */
  real32_T Probe_m0[2];                /* '<S335>/Probe' */
  real32_T Probe_mt[2];                /* '<S341>/Probe' */
  real32_T Probe_fn[2];                /* '<S347>/Probe' */
  real32_T Probe_op[2];                /* '<S353>/Probe' */
  real32_T Probe_k[2];                 /* '<S359>/Probe' */
  real32_T Probe_ll[2];                /* '<S371>/Probe' */
  real32_T Probe_dm[2];                /* '<S377>/Probe' */
  real32_T Probe_ba[2];                /* '<S383>/Probe' */
  real32_T Probe_j0k[2];               /* '<S389>/Probe' */
  real32_T Probe_gj[2];                /* '<S395>/Probe' */
  real32_T Probe_po[2];                /* '<S401>/Probe' */
  real32_T Probe_f2[2];                /* '<S407>/Probe' */
  real32_T Probe_iz[2];                /* '<S413>/Probe' */
  real32_T Probe_lv[2];                /* '<S419>/Probe' */
  real32_T Probe_ms[2];                /* '<S425>/Probe' */
  real32_T Probe_it[2];                /* '<S437>/Probe' */
  real32_T Probe_cs[2];                /* '<S443>/Probe' */
  real32_T Probe_pa[2];                /* '<S449>/Probe' */
  real32_T Probe_oq[2];                /* '<S455>/Probe' */
  real32_T Probe_hl[2];                /* '<S461>/Probe' */
  real32_T Probe_hz[2];                /* '<S467>/Probe' */
  real32_T Probe_be[2];                /* '<S473>/Probe' */
  real32_T Probe_c2[2];                /* '<S479>/Probe' */
  real32_T Probe_eq[2];                /* '<S485>/Probe' */
  real32_T Probe_aj[2];                /* '<S491>/Probe' */
  real32_T Probe_hs[2];                /* '<S503>/Probe' */
  real32_T Probe_kp[2];                /* '<S509>/Probe' */
  real32_T Probe_jn[2];                /* '<S515>/Probe' */
  real32_T Probe_dh[2];                /* '<S521>/Probe' */
  real32_T Probe_bg[2];                /* '<S527>/Probe' */
  real32_T Probe_hb[2];                /* '<S533>/Probe' */
  real32_T Probe_gk[2];                /* '<S539>/Probe' */
  real32_T Probe_ny[2];                /* '<S545>/Probe' */
  real32_T Probe_k0[2];                /* '<S551>/Probe' */
  real32_T Probe_ic[2];                /* '<S557>/Probe' */
  real32_T Probe_lg[2];                /* '<S569>/Probe' */
  real32_T Probe_fh[2];                /* '<S575>/Probe' */
  real32_T Probe_eh[2];                /* '<S581>/Probe' */
  real32_T Probe_nl[2];                /* '<S587>/Probe' */
  real32_T Probe_bo[2];                /* '<S593>/Probe' */
  real32_T Probe_kb[2];                /* '<S599>/Probe' */
  real32_T Probe_l3[2];                /* '<S605>/Probe' */
  real32_T Probe_j0n[2];               /* '<S611>/Probe' */
  real32_T Probe_pu[2];                /* '<S617>/Probe' */
  real32_T Probe_jw[2];                /* '<S623>/Probe' */
  real32_T Probe_g2[2];                /* '<S635>/Probe' */
  real32_T Probe_opc[2];               /* '<S641>/Probe' */
  real32_T Probe_lf[2];                /* '<S647>/Probe' */
  real32_T Probe_m5[2];                /* '<S653>/Probe' */
  real32_T Probe_da[2];                /* '<S659>/Probe' */
  real32_T Probe_he[2];                /* '<S665>/Probe' */
  real32_T Probe_ak[2];                /* '<S671>/Probe' */
  real32_T ChargeCurrentReq;           /* '<S97>/Chart' */
  real32_T cumRevIndex;
  real32_T csum;
  real32_T modValueRev;
  real32_T z;
  real32_T Max;                        /* '<S101>/Max' */
  real32_T Saturation1;                /* '<S99>/Saturation1' */
  real32_T f;
  uint32_T qY;
  int16_T i;
  int16_T i_m;
  int16_T i_c;
  int16_T i_k;
  int16_T i_cx;
  int16_T i1;
  boolean_T PreChargeRelayInvtrCmd;    /* '<S97>/Chart' */
  boolean_T PosContactorInvtrCmd;      /* '<S97>/Chart' */
  boolean_T NegContactorInvtrCmd;      /* '<S97>/Chart' */
  boolean_T PosContactorChgrCmd;       /* '<S97>/Chart' */
  boolean_T PreChargeRelayChgrCmd;     /* '<S97>/Chart' */
  boolean_T NegContactorChgrCmd;       /* '<S97>/Chart' */
  boolean_T Compare;                   /* '<S104>/Compare' */
  boolean_T Compare_p;                 /* '<S170>/Compare' */
  boolean_T Compare_h;                 /* '<S236>/Compare' */
  boolean_T Compare_o;                 /* '<S302>/Compare' */
  boolean_T Compare_k;                 /* '<S368>/Compare' */
  boolean_T Compare_i;                 /* '<S434>/Compare' */
  boolean_T Compare_e;                 /* '<S500>/Compare' */
  boolean_T Compare_k5;                /* '<S566>/Compare' */
  boolean_T Compare_l;                 /* '<S632>/Compare' */
  boolean_T Compare_iz;                /* '<S110>/Compare' */
  boolean_T Compare_d;                 /* '<S116>/Compare' */
  boolean_T Compare_a;                 /* '<S122>/Compare' */
  boolean_T Compare_p3;                /* '<S128>/Compare' */
  boolean_T Compare_o1;                /* '<S134>/Compare' */
  boolean_T Compare_ob;                /* '<S140>/Compare' */
  boolean_T Compare_n;                 /* '<S146>/Compare' */
  boolean_T Compare_ii;                /* '<S152>/Compare' */
  boolean_T Compare_b;                 /* '<S158>/Compare' */
  boolean_T Compare_f;                 /* '<S164>/Compare' */
  boolean_T Compare_km;                /* '<S176>/Compare' */
  boolean_T Compare_in;                /* '<S182>/Compare' */
  boolean_T Compare_lv;                /* '<S188>/Compare' */
  boolean_T Compare_ed;                /* '<S194>/Compare' */
  boolean_T Compare_el;                /* '<S200>/Compare' */
  boolean_T Compare_kl;                /* '<S206>/Compare' */
  boolean_T Compare_kf;                /* '<S212>/Compare' */
  boolean_T Compare_hy;                /* '<S218>/Compare' */
  boolean_T Compare_oi;                /* '<S224>/Compare' */
  boolean_T Compare_i1;                /* '<S230>/Compare' */
  boolean_T Compare_g;                 /* '<S242>/Compare' */
  boolean_T Compare_ec;                /* '<S248>/Compare' */
  boolean_T Compare_kh;                /* '<S254>/Compare' */
  boolean_T Compare_go;                /* '<S260>/Compare' */
  boolean_T Compare_hb;                /* '<S266>/Compare' */
  boolean_T Compare_d2;                /* '<S272>/Compare' */
  boolean_T Compare_kfs;               /* '<S278>/Compare' */
  boolean_T Compare_b3;                /* '<S284>/Compare' */
  boolean_T Compare_kd;                /* '<S290>/Compare' */
  boolean_T Compare_dh;                /* '<S296>/Compare' */
  boolean_T Compare_kv;                /* '<S308>/Compare' */
  boolean_T Compare_of;                /* '<S314>/Compare' */
  boolean_T Compare_bn;                /* '<S320>/Compare' */
  boolean_T Compare_ix;                /* '<S326>/Compare' */
  boolean_T Compare_gy;                /* '<S332>/Compare' */
  boolean_T Compare_kz;                /* '<S338>/Compare' */
  boolean_T Compare_hi;                /* '<S344>/Compare' */
  boolean_T Compare_by;                /* '<S350>/Compare' */
  boolean_T Compare_pn;                /* '<S356>/Compare' */
  boolean_T Compare_ep;                /* '<S362>/Compare' */
  boolean_T Compare_ev;                /* '<S374>/Compare' */
  boolean_T Compare_bm;                /* '<S380>/Compare' */
  boolean_T Compare_io;                /* '<S386>/Compare' */
  boolean_T Compare_ax;                /* '<S392>/Compare' */
  boolean_T Compare_gr;                /* '<S398>/Compare' */
  boolean_T Compare_fw;                /* '<S404>/Compare' */
  boolean_T Compare_j;                 /* '<S410>/Compare' */
  boolean_T Compare_m;                 /* '<S416>/Compare' */
  boolean_T Compare_ac;                /* '<S422>/Compare' */
  boolean_T Compare_bo;                /* '<S428>/Compare' */
  boolean_T Compare_ng;                /* '<S440>/Compare' */
  boolean_T Compare_ht;                /* '<S446>/Compare' */
  boolean_T Compare_im;                /* '<S452>/Compare' */
  boolean_T Compare_hg;                /* '<S458>/Compare' */
  boolean_T Compare_kj;                /* '<S464>/Compare' */
  boolean_T Compare_id;                /* '<S470>/Compare' */
  boolean_T Compare_ff;                /* '<S476>/Compare' */
  boolean_T Compare_kn;                /* '<S482>/Compare' */
  boolean_T Compare_g5;                /* '<S488>/Compare' */
  boolean_T Compare_ou;                /* '<S494>/Compare' */
  boolean_T Compare_eq;                /* '<S506>/Compare' */
  boolean_T Compare_l5;                /* '<S512>/Compare' */
  boolean_T Compare_fs;                /* '<S518>/Compare' */
  boolean_T Compare_c;                 /* '<S524>/Compare' */
  boolean_T Compare_f3;                /* '<S530>/Compare' */
  boolean_T Compare_lf;                /* '<S536>/Compare' */
  boolean_T Compare_bi;                /* '<S542>/Compare' */
  boolean_T Compare_bnj;               /* '<S548>/Compare' */
  B_RCTcc_test3_T RCTcc;               /* '<Root>/RCTcc' */
  B_MovingAverage_test3_T MovingAverage9;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage8;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage7;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage6;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage5;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage4;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage3;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage2;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage15;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage14;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage13;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage12;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage11;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage10;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage1;/* '<Root>/Moving Average' */
  B_MovingAverage_test3_T MovingAverage;/* '<Root>/Moving Average' */
} B_test3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_k_T obj;  /* '<S99>/Moving Average' */
  real_T PreContact;                   /* '<S97>/Chart' */
  real32_T Integrator_DSTATE;          /* '<S106>/Integrator' */
  real32_T Integrator_DSTATE_a;        /* '<S172>/Integrator' */
  real32_T Integrator_DSTATE_n;        /* '<S238>/Integrator' */
  real32_T Integrator_DSTATE_b;        /* '<S304>/Integrator' */
  real32_T Integrator_DSTATE_g;        /* '<S370>/Integrator' */
  real32_T Integrator_DSTATE_i;        /* '<S436>/Integrator' */
  real32_T Integrator_DSTATE_e;        /* '<S502>/Integrator' */
  real32_T Integrator_DSTATE_id;       /* '<S568>/Integrator' */
  real32_T Integrator_DSTATE_is;       /* '<S634>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S112>/Integrator' */
  real32_T Integrator_DSTATE_j1;       /* '<S118>/Integrator' */
  real32_T Integrator_DSTATE_jr;       /* '<S124>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S130>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S136>/Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S142>/Integrator' */
  real32_T Integrator_DSTATE_fo;       /* '<S148>/Integrator' */
  real32_T Integrator_DSTATE_i1;       /* '<S154>/Integrator' */
  real32_T Integrator_DSTATE_fj;       /* '<S160>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S166>/Integrator' */
  real32_T Integrator_DSTATE_g5;       /* '<S178>/Integrator' */
  real32_T Integrator_DSTATE_pf;       /* '<S184>/Integrator' */
  real32_T Integrator_DSTATE_c;        /* '<S190>/Integrator' */
  real32_T Integrator_DSTATE_m;        /* '<S196>/Integrator' */
  real32_T Integrator_DSTATE_j2;       /* '<S202>/Integrator' */
  real32_T Integrator_DSTATE_iz;       /* '<S208>/Integrator' */
  real32_T Integrator_DSTATE_bh;       /* '<S214>/Integrator' */
  real32_T Integrator_DSTATE_ji;       /* '<S220>/Integrator' */
  real32_T Integrator_DSTATE_od;       /* '<S226>/Integrator' */
  real32_T Integrator_DSTATE_oy;       /* '<S232>/Integrator' */
  real32_T Integrator_DSTATE_nc;       /* '<S244>/Integrator' */
  real32_T Integrator_DSTATE_c2;       /* '<S250>/Integrator' */
  real32_T Integrator_DSTATE_pa;       /* '<S256>/Integrator' */
  real32_T Integrator_DSTATE_ez;       /* '<S262>/Integrator' */
  real32_T Integrator_DSTATE_bp;       /* '<S268>/Integrator' */
  real32_T Integrator_DSTATE_h;        /* '<S274>/Integrator' */
  real32_T Integrator_DSTATE_i4;       /* '<S280>/Integrator' */
  real32_T Integrator_DSTATE_fp;       /* '<S286>/Integrator' */
  real32_T Integrator_DSTATE_hx;       /* '<S292>/Integrator' */
  real32_T Integrator_DSTATE_k;        /* '<S298>/Integrator' */
  real32_T Integrator_DSTATE_g3;       /* '<S310>/Integrator' */
  real32_T Integrator_DSTATE_h4;       /* '<S316>/Integrator' */
  real32_T Integrator_DSTATE_e5;       /* '<S322>/Integrator' */
  real32_T Integrator_DSTATE_oc;       /* '<S328>/Integrator' */
  real32_T Integrator_DSTATE_n5;       /* '<S334>/Integrator' */
  real32_T Integrator_DSTATE_do;       /* '<S340>/Integrator' */
  real32_T Integrator_DSTATE_ds;       /* '<S346>/Integrator' */
  real32_T Integrator_DSTATE_bv;       /* '<S352>/Integrator' */
  real32_T Integrator_DSTATE_o3;       /* '<S358>/Integrator' */
  real32_T Integrator_DSTATE_fg;       /* '<S364>/Integrator' */
  real32_T Integrator_DSTATE_a4;       /* '<S376>/Integrator' */
  real32_T Integrator_DSTATE_l;        /* '<S382>/Integrator' */
  real32_T Integrator_DSTATE_eo;       /* '<S388>/Integrator' */
  real32_T Integrator_DSTATE_cl;       /* '<S394>/Integrator' */
  real32_T Integrator_DSTATE_bs;       /* '<S400>/Integrator' */
  real32_T Integrator_DSTATE_e2;       /* '<S406>/Integrator' */
  real32_T Integrator_DSTATE_lr;       /* '<S412>/Integrator' */
  real32_T Integrator_DSTATE_gx;       /* '<S418>/Integrator' */
  real32_T Integrator_DSTATE_nu;       /* '<S424>/Integrator' */
  real32_T Integrator_DSTATE_az;       /* '<S430>/Integrator' */
  real32_T Integrator_DSTATE_kc;       /* '<S442>/Integrator' */
  real32_T Integrator_DSTATE_mc;       /* '<S448>/Integrator' */
  real32_T Integrator_DSTATE_nm;       /* '<S454>/Integrator' */
  real32_T Integrator_DSTATE_po;       /* '<S460>/Integrator' */
  real32_T Integrator_DSTATE_bt;       /* '<S466>/Integrator' */
  real32_T Integrator_DSTATE_jt;       /* '<S472>/Integrator' */
  real32_T Integrator_DSTATE_dc;       /* '<S478>/Integrator' */
  real32_T Integrator_DSTATE_pb;       /* '<S484>/Integrator' */
  real32_T Integrator_DSTATE_oe;       /* '<S490>/Integrator' */
  real32_T Integrator_DSTATE_al;       /* '<S496>/Integrator' */
  real32_T Integrator_DSTATE_cx;       /* '<S508>/Integrator' */
  real32_T Integrator_DSTATE_cr;       /* '<S514>/Integrator' */
  real32_T Integrator_DSTATE_p3;       /* '<S520>/Integrator' */
  real32_T Integrator_DSTATE_kv;       /* '<S526>/Integrator' */
  real32_T Integrator_DSTATE_ed;       /* '<S532>/Integrator' */
  real32_T Integrator_DSTATE_fu;       /* '<S538>/Integrator' */
  real32_T Integrator_DSTATE_he;       /* '<S544>/Integrator' */
  real32_T Integrator_DSTATE_ot;       /* '<S550>/Integrator' */
  real32_T Integrator_DSTATE_my;       /* '<S556>/Integrator' */
  real32_T Integrator_DSTATE_lt;       /* '<S562>/Integrator' */
  real32_T Integrator_DSTATE_pd;       /* '<S574>/Integrator' */
  real32_T Integrator_DSTATE_en;       /* '<S580>/Integrator' */
  real32_T Integrator_DSTATE_ix;       /* '<S586>/Integrator' */
  real32_T Integrator_DSTATE_hg;       /* '<S592>/Integrator' */
  real32_T Integrator_DSTATE_fm;       /* '<S598>/Integrator' */
  real32_T Integrator_DSTATE_ok;       /* '<S604>/Integrator' */
  real32_T Integrator_DSTATE_ns;       /* '<S610>/Integrator' */
  real32_T Integrator_DSTATE_ga;       /* '<S616>/Integrator' */
  real32_T Integrator_DSTATE_dsn;      /* '<S622>/Integrator' */
  real32_T Integrator_DSTATE_pc;       /* '<S628>/Integrator' */
  real32_T Integrator_DSTATE_eg;       /* '<S640>/Integrator' */
  real32_T Integrator_DSTATE_jx;       /* '<S646>/Integrator' */
  real32_T Integrator_DSTATE_im;       /* '<S652>/Integrator' */
  real32_T Integrator_DSTATE_hp;       /* '<S658>/Integrator' */
  real32_T Integrator_DSTATE_aq;       /* '<S664>/Integrator' */
  real32_T Integrator_DSTATE_lx;       /* '<S670>/Integrator' */
  real32_T Integrator_DSTATE_l5;       /* '<S676>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S679>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S678>/Discrete-Time Integrator' */
  real32_T PrevY;                      /* '<S99>/Rate Limiter1' */
  real32_T DeltaCellVolt;              /* '<S97>/Chart' */
  int32_T durationCounter_1;           /* '<S97>/Chart' */
  int32_T durationCounter_1_p;         /* '<S97>/Chart' */
  int32_T durationCounter_2;           /* '<S97>/Chart' */
  int32_T durationCounter_1_k;         /* '<S97>/Chart' */
  int32_T durationCounter_2_a;         /* '<S97>/Chart' */
  int32_T durationCounter_3;           /* '<S97>/Chart' */
  int32_T durationCounter_4;           /* '<S97>/Chart' */
  int32_T durationCounter_5;           /* '<S97>/Chart' */
  int32_T durationCounter_6;           /* '<S97>/Chart' */
  int32_T durationCounter_7;           /* '<S97>/Chart' */
  int32_T durationCounter_8;           /* '<S97>/Chart' */
  int32_T durationCounter_1_c;         /* '<S97>/Chart' */
  int32_T durationCounter_2_aa;        /* '<S97>/Chart' */
  int32_T durationCounter_1_p1;        /* '<S97>/Chart' */
  int32_T durationCounter_2_h;         /* '<S97>/Chart' */
  uint32_T m_bpIndex[2];               /* '<S99>/Rdc' */
  uint32_T m_bpIndex_g;                /* '<S683>/Rdc1' */
  uint32_T temporalCounter_i1;         /* '<S98>/Chart1' */
  uint32_T temporalCounter_i1_h;       /* '<S97>/Chart' */
  uint32_T temporalCounter_i2;         /* '<S97>/Chart' */
  uint32_T temporalCounter_i3;         /* '<S97>/Chart' */
  uint32_T temporalCounter_i4;         /* '<S97>/Chart' */
  uint32_T temporalCounter_i5;         /* '<S97>/Chart' */
  int16_T Integrator_PrevResetState;   /* '<S106>/Integrator' */
  int16_T Integrator_PrevResetState_p; /* '<S172>/Integrator' */
  int16_T Integrator_PrevResetState_o; /* '<S238>/Integrator' */
  int16_T Integrator_PrevResetState_e; /* '<S304>/Integrator' */
  int16_T Integrator_PrevResetState_oy;/* '<S370>/Integrator' */
  int16_T Integrator_PrevResetState_c; /* '<S436>/Integrator' */
  int16_T Integrator_PrevResetState_a; /* '<S502>/Integrator' */
  int16_T Integrator_PrevResetState_ch;/* '<S568>/Integrator' */
  int16_T Integrator_PrevResetState_h; /* '<S634>/Integrator' */
  int16_T Integrator_PrevResetState_i; /* '<S112>/Integrator' */
  int16_T Integrator_PrevResetState_iy;/* '<S118>/Integrator' */
  int16_T Integrator_PrevResetState_g; /* '<S124>/Integrator' */
  int16_T Integrator_PrevResetState_f; /* '<S130>/Integrator' */
  int16_T Integrator_PrevResetState_fi;/* '<S136>/Integrator' */
  int16_T Integrator_PrevResetState_fm;/* '<S142>/Integrator' */
  int16_T Integrator_PrevResetState_gh;/* '<S148>/Integrator' */
  int16_T Integrator_PrevResetState_b; /* '<S154>/Integrator' */
  int16_T Integrator_PrevResetState_bl;/* '<S160>/Integrator' */
  int16_T Integrator_PrevResetState_fie;/* '<S166>/Integrator' */
  int16_T Integrator_PrevResetState_d; /* '<S178>/Integrator' */
  int16_T Integrator_PrevResetState_k; /* '<S184>/Integrator' */
  int16_T Integrator_PrevResetState_n; /* '<S190>/Integrator' */
  int16_T Integrator_PrevResetState_fz;/* '<S196>/Integrator' */
  int16_T Integrator_PrevResetState_m; /* '<S202>/Integrator' */
  int16_T Integrator_PrevResetState_hi;/* '<S208>/Integrator' */
  int16_T Integrator_PrevResetState_fy;/* '<S214>/Integrator' */
  int16_T Integrator_PrevResetState_ok;/* '<S220>/Integrator' */
  int16_T Integrator_PrevResetState_j; /* '<S226>/Integrator' */
  int16_T Integrator_PrevResetState_dh;/* '<S232>/Integrator' */
  int16_T Integrator_PrevResetState_ne;/* '<S244>/Integrator' */
  int16_T Integrator_PrevResetState_fl;/* '<S250>/Integrator' */
  int16_T Integrator_PrevResetState_ib;/* '<S256>/Integrator' */
  int16_T Integrator_PrevResetState_dz;/* '<S262>/Integrator' */
  int16_T Integrator_PrevResetState_l; /* '<S268>/Integrator' */
  int16_T Integrator_PrevResetState_hm;/* '<S274>/Integrator' */
  int16_T Integrator_PrevResetState_lo;/* '<S280>/Integrator' */
  int16_T Integrator_PrevResetState_dk;/* '<S286>/Integrator' */
  int16_T Integrator_PrevResetState_es;/* '<S292>/Integrator' */
  int16_T Integrator_PrevResetState_fu;/* '<S298>/Integrator' */
  int16_T Integrator_PrevResetState_cv;/* '<S310>/Integrator' */
  int16_T Integrator_PrevResetState_ke;/* '<S316>/Integrator' */
  int16_T Integrator_PrevResetState_fa;/* '<S322>/Integrator' */
  int16_T Integrator_PrevResetState_h4;/* '<S328>/Integrator' */
  int16_T Integrator_PrevResetState_io;/* '<S334>/Integrator' */
  int16_T Integrator_PrevResetState_k3;/* '<S340>/Integrator' */
  int16_T Integrator_PrevResetState_ed;/* '<S346>/Integrator' */
  int16_T Integrator_PrevResetState_on;/* '<S352>/Integrator' */
  int16_T Integrator_PrevResetState_cb;/* '<S358>/Integrator' */
  int16_T Integrator_PrevResetState_fj;/* '<S364>/Integrator' */
  int16_T Integrator_PrevResetState_kk;/* '<S376>/Integrator' */
  int16_T Integrator_PrevResetState_ie;/* '<S382>/Integrator' */
  int16_T Integrator_PrevResetState_pp;/* '<S388>/Integrator' */
  int16_T Integrator_PrevResetState_ox;/* '<S394>/Integrator' */
  int16_T Integrator_PrevResetState_fn;/* '<S400>/Integrator' */
  int16_T Integrator_PrevResetState_mk;/* '<S406>/Integrator' */
  int16_T Integrator_PrevResetState_m1;/* '<S412>/Integrator' */
  int16_T Integrator_PrevResetState_dzx;/* '<S418>/Integrator' */
  int16_T Integrator_PrevResetState_m5;/* '<S424>/Integrator' */
  int16_T Integrator_PrevResetState_nv;/* '<S430>/Integrator' */
  int16_T Integrator_PrevResetState_bw;/* '<S442>/Integrator' */
  int16_T Integrator_PrevResetState_m3;/* '<S448>/Integrator' */
  int16_T Integrator_PrevResetState_ei;/* '<S454>/Integrator' */
  int16_T Integrator_PrevResetState_o1;/* '<S460>/Integrator' */
  int16_T Integrator_PrevResetState_gv;/* '<S466>/Integrator' */
  int16_T Integrator_PrevResetState_hf;/* '<S472>/Integrator' */
  int16_T Integrator_PrevResetState_gs;/* '<S478>/Integrator' */
  int16_T Integrator_PrevResetState_fyk;/* '<S484>/Integrator' */
  int16_T Integrator_PrevResetState_kl;/* '<S490>/Integrator' */
  int16_T Integrator_PrevResetState_nk;/* '<S496>/Integrator' */
  int16_T Integrator_PrevResetState_ln;/* '<S508>/Integrator' */
  int16_T Integrator_PrevResetState_oe;/* '<S514>/Integrator' */
  int16_T Integrator_PrevResetState_hu;/* '<S520>/Integrator' */
  int16_T Integrator_PrevResetState_mr;/* '<S526>/Integrator' */
  int16_T Integrator_PrevResetState_ec;/* '<S532>/Integrator' */
  int16_T Integrator_PrevResetState_bb;/* '<S538>/Integrator' */
  int16_T Integrator_PrevResetState_n1;/* '<S544>/Integrator' */
  int16_T Integrator_PrevResetState_iw;/* '<S550>/Integrator' */
  int16_T Integrator_PrevResetState_gg;/* '<S556>/Integrator' */
  int16_T Integrator_PrevResetState_lz;/* '<S562>/Integrator' */
  int16_T Integrator_PrevResetState_dkv;/* '<S574>/Integrator' */
  int16_T Integrator_PrevResetState_bq;/* '<S580>/Integrator' */
  int16_T Integrator_PrevResetState_pb;/* '<S586>/Integrator' */
  int16_T Integrator_PrevResetState_ew;/* '<S592>/Integrator' */
  int16_T Integrator_PrevResetState_pl;/* '<S598>/Integrator' */
  int16_T Integrator_PrevResetState_mu;/* '<S604>/Integrator' */
  int16_T Integrator_PrevResetState_e4;/* '<S610>/Integrator' */
  int16_T Integrator_PrevResetState_jl;/* '<S616>/Integrator' */
  int16_T Integrator_PrevResetState_cx;/* '<S622>/Integrator' */
  int16_T Integrator_PrevResetState_mm;/* '<S628>/Integrator' */
  int16_T Integrator_PrevResetState_pg;/* '<S640>/Integrator' */
  int16_T Integrator_PrevResetState_md;/* '<S646>/Integrator' */
  int16_T Integrator_PrevResetState_bf;/* '<S652>/Integrator' */
  int16_T Integrator_PrevResetState_fam;/* '<S658>/Integrator' */
  int16_T Integrator_PrevResetState_g2;/* '<S664>/Integrator' */
  int16_T Integrator_PrevResetState_ou;/* '<S670>/Integrator' */
  int16_T Integrator_PrevResetState_k5;/* '<S676>/Integrator' */
  uint16_T Integrator_IC_LOADING;      /* '<S106>/Integrator' */
  uint16_T Integrator_IC_LOADING_p;    /* '<S172>/Integrator' */
  uint16_T Integrator_IC_LOADING_g;    /* '<S238>/Integrator' */
  uint16_T Integrator_IC_LOADING_j;    /* '<S304>/Integrator' */
  uint16_T Integrator_IC_LOADING_h;    /* '<S370>/Integrator' */
  uint16_T Integrator_IC_LOADING_k;    /* '<S436>/Integrator' */
  uint16_T Integrator_IC_LOADING_o;    /* '<S502>/Integrator' */
  uint16_T Integrator_IC_LOADING_g2;   /* '<S568>/Integrator' */
  uint16_T Integrator_IC_LOADING_d;    /* '<S634>/Integrator' */
  uint16_T Integrator_IC_LOADING_pv;   /* '<S112>/Integrator' */
  uint16_T Integrator_IC_LOADING_m;    /* '<S118>/Integrator' */
  uint16_T Integrator_IC_LOADING_hr;   /* '<S124>/Integrator' */
  uint16_T Integrator_IC_LOADING_i;    /* '<S130>/Integrator' */
  uint16_T Integrator_IC_LOADING_e;    /* '<S136>/Integrator' */
  uint16_T Integrator_IC_LOADING_df;   /* '<S142>/Integrator' */
  uint16_T Integrator_IC_LOADING_ip;   /* '<S148>/Integrator' */
  uint16_T Integrator_IC_LOADING_a;    /* '<S154>/Integrator' */
  uint16_T Integrator_IC_LOADING_ic;   /* '<S160>/Integrator' */
  uint16_T Integrator_IC_LOADING_ab;   /* '<S166>/Integrator' */
  uint16_T Integrator_IC_LOADING_oe;   /* '<S178>/Integrator' */
  uint16_T Integrator_IC_LOADING_op;   /* '<S184>/Integrator' */
  uint16_T Integrator_IC_LOADING_hg;   /* '<S190>/Integrator' */
  uint16_T Integrator_IC_LOADING_l;    /* '<S196>/Integrator' */
  uint16_T Integrator_IC_LOADING_iw;   /* '<S202>/Integrator' */
  uint16_T Integrator_IC_LOADING_ky;   /* '<S208>/Integrator' */
  uint16_T Integrator_IC_LOADING_b;    /* '<S214>/Integrator' */
  uint16_T Integrator_IC_LOADING_gu;   /* '<S220>/Integrator' */
  uint16_T Integrator_IC_LOADING_ao;   /* '<S226>/Integrator' */
  uint16_T Integrator_IC_LOADING_f;    /* '<S232>/Integrator' */
  uint16_T Integrator_IC_LOADING_c;    /* '<S244>/Integrator' */
  uint16_T Integrator_IC_LOADING_fc;   /* '<S250>/Integrator' */
  uint16_T Integrator_IC_LOADING_bd;   /* '<S256>/Integrator' */
  uint16_T Integrator_IC_LOADING_n;    /* '<S262>/Integrator' */
  uint16_T Integrator_IC_LOADING_aoc;  /* '<S268>/Integrator' */
  uint16_T Integrator_IC_LOADING_kr;   /* '<S274>/Integrator' */
  uint16_T Integrator_IC_LOADING_n3;   /* '<S280>/Integrator' */
  uint16_T Integrator_IC_LOADING_pe;   /* '<S286>/Integrator' */
  uint16_T Integrator_IC_LOADING_gb;   /* '<S292>/Integrator' */
  uint16_T Integrator_IC_LOADING_gg;   /* '<S298>/Integrator' */
  uint16_T Integrator_IC_LOADING_bb;   /* '<S310>/Integrator' */
  uint16_T Integrator_IC_LOADING_p4;   /* '<S316>/Integrator' */
  uint16_T Integrator_IC_LOADING_mv;   /* '<S322>/Integrator' */
  uint16_T Integrator_IC_LOADING_j1;   /* '<S328>/Integrator' */
  uint16_T Integrator_IC_LOADING_az;   /* '<S334>/Integrator' */
  uint16_T Integrator_IC_LOADING_bm;   /* '<S340>/Integrator' */
  uint16_T Integrator_IC_LOADING_c0;   /* '<S346>/Integrator' */
  uint16_T Integrator_IC_LOADING_p0;   /* '<S352>/Integrator' */
  uint16_T Integrator_IC_LOADING_j3;   /* '<S358>/Integrator' */
  uint16_T Integrator_IC_LOADING_hf;   /* '<S364>/Integrator' */
  uint16_T Integrator_IC_LOADING_ms;   /* '<S376>/Integrator' */
  uint16_T Integrator_IC_LOADING_me;   /* '<S382>/Integrator' */
  uint16_T Integrator_IC_LOADING_oq;   /* '<S388>/Integrator' */
  uint16_T Integrator_IC_LOADING_kz;   /* '<S394>/Integrator' */
  uint16_T Integrator_IC_LOADING_b1;   /* '<S400>/Integrator' */
  uint16_T Integrator_IC_LOADING_j3b;  /* '<S406>/Integrator' */
  uint16_T Integrator_IC_LOADING_ar;   /* '<S412>/Integrator' */
  uint16_T Integrator_IC_LOADING_abx;  /* '<S418>/Integrator' */
  uint16_T Integrator_IC_LOADING_cy;   /* '<S424>/Integrator' */
  uint16_T Integrator_IC_LOADING_b2;   /* '<S430>/Integrator' */
  uint16_T Integrator_IC_LOADING_br;   /* '<S442>/Integrator' */
  uint16_T Integrator_IC_LOADING_du;   /* '<S448>/Integrator' */
  uint16_T Integrator_IC_LOADING_c3;   /* '<S454>/Integrator' */
  uint16_T Integrator_IC_LOADING_lm;   /* '<S460>/Integrator' */
  uint16_T Integrator_IC_LOADING_kk;   /* '<S466>/Integrator' */
  uint16_T Integrator_IC_LOADING_km;   /* '<S472>/Integrator' */
  uint16_T Integrator_IC_LOADING_oex;  /* '<S478>/Integrator' */
  uint16_T Integrator_IC_LOADING_kp;   /* '<S484>/Integrator' */
  uint16_T Integrator_IC_LOADING_ew;   /* '<S490>/Integrator' */
  uint16_T Integrator_IC_LOADING_bk;   /* '<S496>/Integrator' */
  uint16_T Integrator_IC_LOADING_j31;  /* '<S508>/Integrator' */
  uint16_T Integrator_IC_LOADING_mo;   /* '<S514>/Integrator' */
  uint16_T Integrator_IC_LOADING_abf;  /* '<S520>/Integrator' */
  uint16_T Integrator_IC_LOADING_ho;   /* '<S526>/Integrator' */
  uint16_T Integrator_IC_LOADING_ph;   /* '<S532>/Integrator' */
  uint16_T Integrator_IC_LOADING_da;   /* '<S538>/Integrator' */
  uint16_T Integrator_IC_LOADING_cg;   /* '<S544>/Integrator' */
  uint16_T Integrator_IC_LOADING_d3;   /* '<S550>/Integrator' */
  uint16_T Integrator_IC_LOADING_d0;   /* '<S556>/Integrator' */
  uint16_T Integrator_IC_LOADING_mg;   /* '<S562>/Integrator' */
  uint16_T Integrator_IC_LOADING_e3;   /* '<S574>/Integrator' */
  uint16_T Integrator_IC_LOADING_ns;   /* '<S580>/Integrator' */
  uint16_T Integrator_IC_LOADING_hp;   /* '<S586>/Integrator' */
  uint16_T Integrator_IC_LOADING_a0;   /* '<S592>/Integrator' */
  uint16_T Integrator_IC_LOADING_bo;   /* '<S598>/Integrator' */
  uint16_T Integrator_IC_LOADING_kq;   /* '<S604>/Integrator' */
  uint16_T Integrator_IC_LOADING_h2;   /* '<S610>/Integrator' */
  uint16_T Integrator_IC_LOADING_kkm;  /* '<S616>/Integrator' */
  uint16_T Integrator_IC_LOADING_bz;   /* '<S622>/Integrator' */
  uint16_T Integrator_IC_LOADING_o1;   /* '<S628>/Integrator' */
  uint16_T Integrator_IC_LOADING_fcd;  /* '<S640>/Integrator' */
  uint16_T Integrator_IC_LOADING_bp;   /* '<S646>/Integrator' */
  uint16_T Integrator_IC_LOADING_ad;   /* '<S652>/Integrator' */
  uint16_T Integrator_IC_LOADING_kv;   /* '<S658>/Integrator' */
  uint16_T Integrator_IC_LOADING_h20;  /* '<S664>/Integrator' */
  uint16_T Integrator_IC_LOADING_d04;  /* '<S670>/Integrator' */
  uint16_T Integrator_IC_LOADING_jn;   /* '<S676>/Integrator' */
  uint16_T is_active_c5_test3;         /* '<S98>/Chart1' */
  uint16_T is_reseting_Counter;        /* '<S98>/Chart1' */
  uint16_T is_main_Task;               /* '<S98>/Chart1' */
  uint16_T is_active_c4_test3;         /* '<S98>/Chart' */
  uint16_T is_c4_test3;                /* '<S98>/Chart' */
  uint16_T is_Static_present;          /* '<S98>/Chart' */
  uint16_T is_Static_Absent;           /* '<S98>/Chart' */
  uint16_T temporalCounter_i1_j;       /* '<S98>/Chart' */
  uint16_T is_active_c2_test3;         /* '<S97>/Chart' */
  uint16_T is_test;                    /* '<S97>/Chart' */
  uint16_T is_MainStateMachine;        /* '<S97>/Chart' */
  uint16_T is_Charginig;               /* '<S97>/Chart' */
  uint16_T is_MonitorFault_In;         /* '<S97>/Chart' */
  uint16_T is_MonitorCurrLim;          /* '<S97>/Chart' */
  uint16_T is_MonitorCellVoltage;      /* '<S97>/Chart' */
  uint16_T is_MonitorCellTemp;         /* '<S97>/Chart' */
  uint16_T is_InverterContactorState;  /* '<S97>/Chart' */
  uint16_T is_OpenInvtrContactors;     /* '<S97>/Chart' */
  uint16_T is_CloseInvtrContactors;    /* '<S97>/Chart' */
  uint16_T is_Balancing;               /* '<S97>/Chart' */
  uint16_T is_BalancingON;             /* '<S97>/Chart' */
  uint16_T is_ChargerContactorState;   /* '<S97>/Chart' */
  uint16_T is_OpenChgrContactors;      /* '<S97>/Chart' */
  uint16_T is_CloseChgrContactors;     /* '<S97>/Chart' */
  boolean_T FaultPresent;              /* '<S97>/Chart' */
  boolean_T flgBalCompl;               /* '<S97>/Chart' */
  Contact InvtrCntctState;             /* '<S97>/Chart' */
  Contact ChrgCntctState;              /* '<S97>/Chart' */
  DW_RCTcc_test3_T RCTcc;              /* '<Root>/RCTcc' */
  DW_MovingAverage_test3_T MovingAverage9;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage8;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage7;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage6;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage5;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage4;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage3;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage2;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage15;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage14;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage13;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage12;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage11;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage10;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage1;/* '<Root>/Moving Average' */
  DW_MovingAverage_test3_T MovingAverage;/* '<Root>/Moving Average' */
} DW_test3_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Rdc_tableData
   * Referenced by: '<S99>/Rdc'
   */
  real32_T Rdc_tableData[77];

  /* Computed Parameter: Rdc_bp01Data
   * Referenced by: '<S99>/Rdc'
   */
  real32_T Rdc_bp01Data[11];

  /* Computed Parameter: Rdc_bp02Data
   * Referenced by: '<S99>/Rdc'
   */
  real32_T Rdc_bp02Data[7];

  /* Computed Parameter: HighTempChrgCurrentLim_tableDat
   * Referenced by: '<S682>/HighTempChrgCurrentLim'
   */
  real32_T HighTempChrgCurrentLim_tableDat[91];

  /* Pooled Parameter (Expression: 273.15+[-30:1:60])
   * Referenced by:
   *   '<S682>/HighTempChrgCurrentLim'
   *   '<S682>/LowTempDchrgCurrentLim'
   */
  real32_T pooled12[91];

  /* Computed Parameter: LowTempDchrgCurrentLim_tableDat
   * Referenced by: '<S682>/LowTempDchrgCurrentLim'
   */
  real32_T LowTempDchrgCurrentLim_tableDat[91];

  /* Computed Parameter: Rdc1_tableData
   * Referenced by: '<S683>/Rdc1'
   */
  real32_T Rdc1_tableData[7];

  /* Computed Parameter: Rdc1_bp01Data
   * Referenced by: '<S683>/Rdc1'
   */
  real32_T Rdc1_bp01Data[7];

  /* Computed Parameter: HighTempDchrgCurrentLim_tableDa
   * Referenced by: '<S683>/HighTempDchrgCurrentLim'
   */
  real32_T HighTempDchrgCurrentLim_tableDa[101];

  /* Pooled Parameter (Expression: 273.15+[-30:1:70])
   * Referenced by:
   *   '<S683>/HighTempDchrgCurrentLim'
   *   '<S683>/LowTempDchrgCurrentLim'
   */
  real32_T pooled13[101];

  /* Computed Parameter: LowTempDchrgCurrentLim_tableD_j
   * Referenced by: '<S683>/LowTempDchrgCurrentLim'
   */
  real32_T LowTempDchrgCurrentLim_tableD_j[101];

  /* Computed Parameter: uDLookupTable3_tableData
   * Referenced by: '<S100>/1-D Lookup Table3'
   */
  real32_T uDLookupTable3_tableData[21];

  /* Computed Parameter: uDLookupTable3_bp01Data
   * Referenced by: '<S100>/1-D Lookup Table3'
   */
  real32_T uDLookupTable3_bp01Data[21];

  /* Computed Parameter: Rdc_maxIndex
   * Referenced by: '<S99>/Rdc'
   */
  uint32_T Rdc_maxIndex[2];
} ConstP_test3_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T BMBFault;                   /* '<Root>/BMBFault' */
  real32_T CurrentSensorFault;         /* '<Root>/CurrentSensorFault' */
  real32_T InputPowerFault;            /* '<Root>/InputPowerFault' */
  real32_T MemoryFault;                /* '<Root>/MemoryFault' */
  real32_T ShortCircuitFault;          /* '<Root>/ShortCircuitFault' */
  real32_T Reset;                      /* '<Root>/Reset' */
  real32_T Vout_Invtr;                 /* '<Root>/Vout_Invtr' */
  real32_T Vout_Chgr;                  /* '<Root>/Vout_Chgr' */
  real32_T Pack_Current;               /* '<Root>/Pack_Current' */
  real32_T Pack_Voltage;               /* '<Root>/Pack_Voltage' */
  real32_T Req_FastCh;                 /* '<Root>/Req_FastCh' */
  uint16_T ReqSOC;                     /* '<Root>/ReqSOC' */
  real32_T SOC;                        /* '<Root>/SOC' */
  SRE StateRequest;                    /* '<Root>/StateRequest' */
  real32_T CellVoltages[96];           /* '<Root>/CellVoltages' */
  real32_T CellTemperatures[16];       /* '<Root>/CellTemperatures' */
  real32_T Req_Power;                  /* '<Root>/Req_Power' */
  real32_T Req_Current;                /* '<Root>/Req_Current' */
  uint16_T CAN_VCU_Flag;               /* '<Root>/CAN_VCU_Flag' */
  uint16_T CAN_VCU_cnt_rst;            /* '<Root>/CAN_VCU_cnt_rst' */
} ExtU_test3_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Faults Faults_d;                     /* '<Root>/Faults' */
  real32_T DischargeCurrentLimit;      /* '<Root>/DischargeCurrentLimit' */
  real32_T ChargeCurrentLimit;         /* '<Root>/ChargeCurrentLimit' */
  BMS_State_Enum BMS_State;            /* '<Root>/BMS_State' */
  ChargeCU_ModeReq ChargeModeReq;      /* '<Root>/ChargeModeReq' */
  real32_T ChargeCurrentReq;           /* '<Root>/ChargeCurrentReq' */
  real32_T ChargeVoltReq;              /* '<Root>/ChargeVoltReq' */
  boolean_T PreChargeRelay;            /* '<Root>/PreChargeRelay' */
  boolean_T PosContactor;              /* '<Root>/PosContactor' */
  boolean_T NegContactor;              /* '<Root>/NegContactor' */
  real32_T RCT;                        /* '<Root>/RCT' */
  real32_T RD;                         /* '<Root>/RD' */
  boolean_T BalCmd[96];                /* '<Root>/BalCmd' */
  real_T led;                          /* '<Root>/led' */
  real32_T RDT;                        /* '<Root>/RDT' */
  real32_T MaxCellVolt;                /* '<Root>/MaxCellVolt' */
  real32_T MinCellVolt;                /* '<Root>/MinCellVolt' */
  real32_T MaxCellTemp;                /* '<Root>/MaxCellTemp' */
  real32_T MinCellTemp;                /* '<Root>/MinCellTemp' */
  real32_T DC_Link_Volt;               /* '<Root>/DC_Link_Volt' */
  real32_T PackCurrent;                /* '<Root>/PackCurrent' */
  boolean_T Contactor_State;           /* '<Root>/Contactor_State' */
  real_T Charge_Complete;              /* '<Root>/Charge_Complete' */
  real_T SOC_New;                      /* '<Root>/SOC_New' */
  real32_T SumOfVoltages;              /* '<Root>/SumOfVoltages' */
  real32_T Fake_SOC;                   /* '<Root>/Fake_SOC' */
  uint16_T CAN_VCU_Fault_Static_Absent;
                                      /* '<Root>/CAN_VCU_Fault_Static_Absent' */
  uint16_T CAN_VCU_Fault_MSG_Dynmc_Abst;
                                     /* '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst' */
  uint32_T CAN_VCU_Fault_MSG_Dynmc_Abst_Cn;
                                 /* '<Root>/CAN_VCU_Fault_MSG_Dynmc_Abst_Cnt' */
  real32_T Add_Mileage_Range;          /* '<Root>/Add_Mileage_Range' */
  boolean_T MaxCellCmd[96];            /* '<Root>/MaxCellCmd' */
  boolean_T MinCellCmd[96];            /* '<Root>/MinCellCmd' */
  boolean_T MaxTempCmd[16];            /* '<Root>/MaxTempCmd' */
  boolean_T MinTempCmd[16];            /* '<Root>/MinTempCmd' */
  real32_T DischargeCurrentReq;        /* '<Root>/DischargeCurrentReq' */
} ExtY_test3_T;

/* Real-time Model Data Structure */
struct tag_RTM_test3_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_test3_T test3_B;

/* Block states (default storage) */
extern DW_test3_T test3_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_test3_T test3_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_test3_T test3_Y;

/* Constant parameters (default storage) */
extern const ConstP_test3_T test3_ConstP;

/* Model entry point functions */
extern void test3_initialize(void);
extern void test3_step(void);
extern void test3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test3_T *const test3_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S678>/Display' : Unused code path elimination
 * Block '<S678>/Display2' : Unused code path elimination
 * Block '<S678>/Display3' : Unused code path elimination
 * Block '<S678>/Display4' : Unused code path elimination
 * Block '<S678>/Display5' : Unused code path elimination
 * Block '<S678>/Scope' : Unused code path elimination
 * Block '<S678>/Scope2' : Unused code path elimination
 * Block '<S679>/Display' : Unused code path elimination
 * Block '<S679>/Display1' : Unused code path elimination
 * Block '<S679>/Display2' : Unused code path elimination
 * Block '<S679>/Display3' : Unused code path elimination
 * Block '<S679>/Display4' : Unused code path elimination
 * Block '<S679>/Display5' : Unused code path elimination
 * Block '<S679>/Display6' : Unused code path elimination
 * Block '<S679>/Scope' : Unused code path elimination
 * Block '<S679>/Scope2' : Unused code path elimination
 * Block '<S683>/Add' : Unused code path elimination
 * Block '<S683>/Display' : Unused code path elimination
 * Block '<S683>/Display1' : Unused code path elimination
 * Block '<S683>/Display2' : Unused code path elimination
 * Block '<S683>/Display3' : Unused code path elimination
 * Block '<S683>/Gain' : Unused code path elimination
 * Block '<S683>/Gain1' : Unused code path elimination
 * Block '<S99>/Display' : Unused code path elimination
 * Block '<S99>/Display1' : Unused code path elimination
 * Block '<S99>/Display2' : Unused code path elimination
 * Block '<S99>/Rac' : Unused code path elimination
 * Block '<S100>/Display' : Unused code path elimination
 * Block '<S100>/Display1' : Unused code path elimination
 * Block '<S100>/Display18' : Unused code path elimination
 * Block '<S100>/Display2' : Unused code path elimination
 * Block '<S100>/Display3' : Unused code path elimination
 * Block '<S100>/Display4' : Unused code path elimination
 * Block '<S100>/Display6' : Unused code path elimination
 * Block '<S100>/NEDC_F1' : Unused code path elimination
 * Block '<S100>/Scope16' : Unused code path elimination
 * Block '<S100>/Scope17' : Unused code path elimination
 * Block '<S100>/Scope3' : Unused code path elimination
 * Block '<S106>/Saturation' : Eliminated Saturate block
 * Block '<S1>/K' : Eliminated nontunable gain of 1
 * Block '<S112>/Saturation' : Eliminated Saturate block
 * Block '<S2>/K' : Eliminated nontunable gain of 1
 * Block '<S118>/Saturation' : Eliminated Saturate block
 * Block '<S3>/K' : Eliminated nontunable gain of 1
 * Block '<S124>/Saturation' : Eliminated Saturate block
 * Block '<S4>/K' : Eliminated nontunable gain of 1
 * Block '<S130>/Saturation' : Eliminated Saturate block
 * Block '<S5>/K' : Eliminated nontunable gain of 1
 * Block '<S136>/Saturation' : Eliminated Saturate block
 * Block '<S6>/K' : Eliminated nontunable gain of 1
 * Block '<S142>/Saturation' : Eliminated Saturate block
 * Block '<S7>/K' : Eliminated nontunable gain of 1
 * Block '<S148>/Saturation' : Eliminated Saturate block
 * Block '<S8>/K' : Eliminated nontunable gain of 1
 * Block '<S154>/Saturation' : Eliminated Saturate block
 * Block '<S9>/K' : Eliminated nontunable gain of 1
 * Block '<S160>/Saturation' : Eliminated Saturate block
 * Block '<S10>/K' : Eliminated nontunable gain of 1
 * Block '<S166>/Saturation' : Eliminated Saturate block
 * Block '<S11>/K' : Eliminated nontunable gain of 1
 * Block '<S172>/Saturation' : Eliminated Saturate block
 * Block '<S12>/K' : Eliminated nontunable gain of 1
 * Block '<S178>/Saturation' : Eliminated Saturate block
 * Block '<S13>/K' : Eliminated nontunable gain of 1
 * Block '<S184>/Saturation' : Eliminated Saturate block
 * Block '<S14>/K' : Eliminated nontunable gain of 1
 * Block '<S190>/Saturation' : Eliminated Saturate block
 * Block '<S15>/K' : Eliminated nontunable gain of 1
 * Block '<S196>/Saturation' : Eliminated Saturate block
 * Block '<S16>/K' : Eliminated nontunable gain of 1
 * Block '<S202>/Saturation' : Eliminated Saturate block
 * Block '<S17>/K' : Eliminated nontunable gain of 1
 * Block '<S208>/Saturation' : Eliminated Saturate block
 * Block '<S18>/K' : Eliminated nontunable gain of 1
 * Block '<S214>/Saturation' : Eliminated Saturate block
 * Block '<S19>/K' : Eliminated nontunable gain of 1
 * Block '<S220>/Saturation' : Eliminated Saturate block
 * Block '<S20>/K' : Eliminated nontunable gain of 1
 * Block '<S226>/Saturation' : Eliminated Saturate block
 * Block '<S21>/K' : Eliminated nontunable gain of 1
 * Block '<S232>/Saturation' : Eliminated Saturate block
 * Block '<S22>/K' : Eliminated nontunable gain of 1
 * Block '<S238>/Saturation' : Eliminated Saturate block
 * Block '<S23>/K' : Eliminated nontunable gain of 1
 * Block '<S244>/Saturation' : Eliminated Saturate block
 * Block '<S24>/K' : Eliminated nontunable gain of 1
 * Block '<S250>/Saturation' : Eliminated Saturate block
 * Block '<S25>/K' : Eliminated nontunable gain of 1
 * Block '<S256>/Saturation' : Eliminated Saturate block
 * Block '<S26>/K' : Eliminated nontunable gain of 1
 * Block '<S262>/Saturation' : Eliminated Saturate block
 * Block '<S27>/K' : Eliminated nontunable gain of 1
 * Block '<S268>/Saturation' : Eliminated Saturate block
 * Block '<S28>/K' : Eliminated nontunable gain of 1
 * Block '<S274>/Saturation' : Eliminated Saturate block
 * Block '<S29>/K' : Eliminated nontunable gain of 1
 * Block '<S280>/Saturation' : Eliminated Saturate block
 * Block '<S30>/K' : Eliminated nontunable gain of 1
 * Block '<S286>/Saturation' : Eliminated Saturate block
 * Block '<S31>/K' : Eliminated nontunable gain of 1
 * Block '<S292>/Saturation' : Eliminated Saturate block
 * Block '<S32>/K' : Eliminated nontunable gain of 1
 * Block '<S298>/Saturation' : Eliminated Saturate block
 * Block '<S33>/K' : Eliminated nontunable gain of 1
 * Block '<S304>/Saturation' : Eliminated Saturate block
 * Block '<S34>/K' : Eliminated nontunable gain of 1
 * Block '<S310>/Saturation' : Eliminated Saturate block
 * Block '<S35>/K' : Eliminated nontunable gain of 1
 * Block '<S316>/Saturation' : Eliminated Saturate block
 * Block '<S36>/K' : Eliminated nontunable gain of 1
 * Block '<S322>/Saturation' : Eliminated Saturate block
 * Block '<S37>/K' : Eliminated nontunable gain of 1
 * Block '<S328>/Saturation' : Eliminated Saturate block
 * Block '<S38>/K' : Eliminated nontunable gain of 1
 * Block '<S334>/Saturation' : Eliminated Saturate block
 * Block '<S39>/K' : Eliminated nontunable gain of 1
 * Block '<S340>/Saturation' : Eliminated Saturate block
 * Block '<S40>/K' : Eliminated nontunable gain of 1
 * Block '<S346>/Saturation' : Eliminated Saturate block
 * Block '<S41>/K' : Eliminated nontunable gain of 1
 * Block '<S352>/Saturation' : Eliminated Saturate block
 * Block '<S42>/K' : Eliminated nontunable gain of 1
 * Block '<S358>/Saturation' : Eliminated Saturate block
 * Block '<S43>/K' : Eliminated nontunable gain of 1
 * Block '<S364>/Saturation' : Eliminated Saturate block
 * Block '<S44>/K' : Eliminated nontunable gain of 1
 * Block '<S370>/Saturation' : Eliminated Saturate block
 * Block '<S45>/K' : Eliminated nontunable gain of 1
 * Block '<S376>/Saturation' : Eliminated Saturate block
 * Block '<S46>/K' : Eliminated nontunable gain of 1
 * Block '<S382>/Saturation' : Eliminated Saturate block
 * Block '<S47>/K' : Eliminated nontunable gain of 1
 * Block '<S388>/Saturation' : Eliminated Saturate block
 * Block '<S48>/K' : Eliminated nontunable gain of 1
 * Block '<S394>/Saturation' : Eliminated Saturate block
 * Block '<S49>/K' : Eliminated nontunable gain of 1
 * Block '<S400>/Saturation' : Eliminated Saturate block
 * Block '<S50>/K' : Eliminated nontunable gain of 1
 * Block '<S406>/Saturation' : Eliminated Saturate block
 * Block '<S51>/K' : Eliminated nontunable gain of 1
 * Block '<S412>/Saturation' : Eliminated Saturate block
 * Block '<S52>/K' : Eliminated nontunable gain of 1
 * Block '<S418>/Saturation' : Eliminated Saturate block
 * Block '<S53>/K' : Eliminated nontunable gain of 1
 * Block '<S424>/Saturation' : Eliminated Saturate block
 * Block '<S54>/K' : Eliminated nontunable gain of 1
 * Block '<S430>/Saturation' : Eliminated Saturate block
 * Block '<S55>/K' : Eliminated nontunable gain of 1
 * Block '<S436>/Saturation' : Eliminated Saturate block
 * Block '<S56>/K' : Eliminated nontunable gain of 1
 * Block '<S442>/Saturation' : Eliminated Saturate block
 * Block '<S57>/K' : Eliminated nontunable gain of 1
 * Block '<S448>/Saturation' : Eliminated Saturate block
 * Block '<S58>/K' : Eliminated nontunable gain of 1
 * Block '<S454>/Saturation' : Eliminated Saturate block
 * Block '<S59>/K' : Eliminated nontunable gain of 1
 * Block '<S460>/Saturation' : Eliminated Saturate block
 * Block '<S60>/K' : Eliminated nontunable gain of 1
 * Block '<S466>/Saturation' : Eliminated Saturate block
 * Block '<S61>/K' : Eliminated nontunable gain of 1
 * Block '<S472>/Saturation' : Eliminated Saturate block
 * Block '<S62>/K' : Eliminated nontunable gain of 1
 * Block '<S478>/Saturation' : Eliminated Saturate block
 * Block '<S63>/K' : Eliminated nontunable gain of 1
 * Block '<S484>/Saturation' : Eliminated Saturate block
 * Block '<S64>/K' : Eliminated nontunable gain of 1
 * Block '<S490>/Saturation' : Eliminated Saturate block
 * Block '<S65>/K' : Eliminated nontunable gain of 1
 * Block '<S496>/Saturation' : Eliminated Saturate block
 * Block '<S66>/K' : Eliminated nontunable gain of 1
 * Block '<S502>/Saturation' : Eliminated Saturate block
 * Block '<S67>/K' : Eliminated nontunable gain of 1
 * Block '<S508>/Saturation' : Eliminated Saturate block
 * Block '<S68>/K' : Eliminated nontunable gain of 1
 * Block '<S514>/Saturation' : Eliminated Saturate block
 * Block '<S69>/K' : Eliminated nontunable gain of 1
 * Block '<S520>/Saturation' : Eliminated Saturate block
 * Block '<S70>/K' : Eliminated nontunable gain of 1
 * Block '<S526>/Saturation' : Eliminated Saturate block
 * Block '<S71>/K' : Eliminated nontunable gain of 1
 * Block '<S532>/Saturation' : Eliminated Saturate block
 * Block '<S72>/K' : Eliminated nontunable gain of 1
 * Block '<S538>/Saturation' : Eliminated Saturate block
 * Block '<S73>/K' : Eliminated nontunable gain of 1
 * Block '<S544>/Saturation' : Eliminated Saturate block
 * Block '<S74>/K' : Eliminated nontunable gain of 1
 * Block '<S550>/Saturation' : Eliminated Saturate block
 * Block '<S75>/K' : Eliminated nontunable gain of 1
 * Block '<S556>/Saturation' : Eliminated Saturate block
 * Block '<S76>/K' : Eliminated nontunable gain of 1
 * Block '<S562>/Saturation' : Eliminated Saturate block
 * Block '<S77>/K' : Eliminated nontunable gain of 1
 * Block '<S568>/Saturation' : Eliminated Saturate block
 * Block '<S78>/K' : Eliminated nontunable gain of 1
 * Block '<S574>/Saturation' : Eliminated Saturate block
 * Block '<S79>/K' : Eliminated nontunable gain of 1
 * Block '<S580>/Saturation' : Eliminated Saturate block
 * Block '<S80>/K' : Eliminated nontunable gain of 1
 * Block '<S586>/Saturation' : Eliminated Saturate block
 * Block '<S81>/K' : Eliminated nontunable gain of 1
 * Block '<S592>/Saturation' : Eliminated Saturate block
 * Block '<S82>/K' : Eliminated nontunable gain of 1
 * Block '<S598>/Saturation' : Eliminated Saturate block
 * Block '<S83>/K' : Eliminated nontunable gain of 1
 * Block '<S604>/Saturation' : Eliminated Saturate block
 * Block '<S84>/K' : Eliminated nontunable gain of 1
 * Block '<S610>/Saturation' : Eliminated Saturate block
 * Block '<S85>/K' : Eliminated nontunable gain of 1
 * Block '<S616>/Saturation' : Eliminated Saturate block
 * Block '<S86>/K' : Eliminated nontunable gain of 1
 * Block '<S622>/Saturation' : Eliminated Saturate block
 * Block '<S87>/K' : Eliminated nontunable gain of 1
 * Block '<S628>/Saturation' : Eliminated Saturate block
 * Block '<S88>/K' : Eliminated nontunable gain of 1
 * Block '<S634>/Saturation' : Eliminated Saturate block
 * Block '<S89>/K' : Eliminated nontunable gain of 1
 * Block '<S640>/Saturation' : Eliminated Saturate block
 * Block '<S90>/K' : Eliminated nontunable gain of 1
 * Block '<S646>/Saturation' : Eliminated Saturate block
 * Block '<S91>/K' : Eliminated nontunable gain of 1
 * Block '<S652>/Saturation' : Eliminated Saturate block
 * Block '<S92>/K' : Eliminated nontunable gain of 1
 * Block '<S658>/Saturation' : Eliminated Saturate block
 * Block '<S93>/K' : Eliminated nontunable gain of 1
 * Block '<S664>/Saturation' : Eliminated Saturate block
 * Block '<S94>/K' : Eliminated nontunable gain of 1
 * Block '<S670>/Saturation' : Eliminated Saturate block
 * Block '<S95>/K' : Eliminated nontunable gain of 1
 * Block '<S676>/Saturation' : Eliminated Saturate block
 * Block '<S96>/K' : Eliminated nontunable gain of 1
 * Block '<S678>/KI' : Eliminated nontunable gain of 1
 * Block '<S679>/KI' : Eliminated nontunable gain of 1
 * Block '<S691>/Saturation' : Eliminated Saturate block
 * Block '<S684>/K' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'test3'
 * '<S1>'   : 'test3/1'
 * '<S2>'   : 'test3/10'
 * '<S3>'   : 'test3/11'
 * '<S4>'   : 'test3/12'
 * '<S5>'   : 'test3/13'
 * '<S6>'   : 'test3/14'
 * '<S7>'   : 'test3/15'
 * '<S8>'   : 'test3/16'
 * '<S9>'   : 'test3/17'
 * '<S10>'  : 'test3/18'
 * '<S11>'  : 'test3/19'
 * '<S12>'  : 'test3/2'
 * '<S13>'  : 'test3/20'
 * '<S14>'  : 'test3/21'
 * '<S15>'  : 'test3/22'
 * '<S16>'  : 'test3/23'
 * '<S17>'  : 'test3/24'
 * '<S18>'  : 'test3/25'
 * '<S19>'  : 'test3/26'
 * '<S20>'  : 'test3/27'
 * '<S21>'  : 'test3/28'
 * '<S22>'  : 'test3/29'
 * '<S23>'  : 'test3/3'
 * '<S24>'  : 'test3/30'
 * '<S25>'  : 'test3/31'
 * '<S26>'  : 'test3/32'
 * '<S27>'  : 'test3/33'
 * '<S28>'  : 'test3/34'
 * '<S29>'  : 'test3/35'
 * '<S30>'  : 'test3/36'
 * '<S31>'  : 'test3/37'
 * '<S32>'  : 'test3/38'
 * '<S33>'  : 'test3/39'
 * '<S34>'  : 'test3/4'
 * '<S35>'  : 'test3/40'
 * '<S36>'  : 'test3/41'
 * '<S37>'  : 'test3/42'
 * '<S38>'  : 'test3/43'
 * '<S39>'  : 'test3/44'
 * '<S40>'  : 'test3/45'
 * '<S41>'  : 'test3/46'
 * '<S42>'  : 'test3/47'
 * '<S43>'  : 'test3/48'
 * '<S44>'  : 'test3/49'
 * '<S45>'  : 'test3/5'
 * '<S46>'  : 'test3/50'
 * '<S47>'  : 'test3/51'
 * '<S48>'  : 'test3/52'
 * '<S49>'  : 'test3/53'
 * '<S50>'  : 'test3/54'
 * '<S51>'  : 'test3/55'
 * '<S52>'  : 'test3/56'
 * '<S53>'  : 'test3/57'
 * '<S54>'  : 'test3/58'
 * '<S55>'  : 'test3/59'
 * '<S56>'  : 'test3/6'
 * '<S57>'  : 'test3/60'
 * '<S58>'  : 'test3/61'
 * '<S59>'  : 'test3/62'
 * '<S60>'  : 'test3/63'
 * '<S61>'  : 'test3/64'
 * '<S62>'  : 'test3/65'
 * '<S63>'  : 'test3/66'
 * '<S64>'  : 'test3/67'
 * '<S65>'  : 'test3/68'
 * '<S66>'  : 'test3/69'
 * '<S67>'  : 'test3/7'
 * '<S68>'  : 'test3/70'
 * '<S69>'  : 'test3/71'
 * '<S70>'  : 'test3/72'
 * '<S71>'  : 'test3/73'
 * '<S72>'  : 'test3/74'
 * '<S73>'  : 'test3/75'
 * '<S74>'  : 'test3/76'
 * '<S75>'  : 'test3/77'
 * '<S76>'  : 'test3/78'
 * '<S77>'  : 'test3/79'
 * '<S78>'  : 'test3/8'
 * '<S79>'  : 'test3/80'
 * '<S80>'  : 'test3/81'
 * '<S81>'  : 'test3/82'
 * '<S82>'  : 'test3/83'
 * '<S83>'  : 'test3/84'
 * '<S84>'  : 'test3/85'
 * '<S85>'  : 'test3/86'
 * '<S86>'  : 'test3/87'
 * '<S87>'  : 'test3/88'
 * '<S88>'  : 'test3/89'
 * '<S89>'  : 'test3/9'
 * '<S90>'  : 'test3/90'
 * '<S91>'  : 'test3/91'
 * '<S92>'  : 'test3/92'
 * '<S93>'  : 'test3/93'
 * '<S94>'  : 'test3/94'
 * '<S95>'  : 'test3/95'
 * '<S96>'  : 'test3/96'
 * '<S97>'  : 'test3/BMS_Function'
 * '<S98>'  : 'test3/CAN_VCU_Fault'
 * '<S99>'  : 'test3/Current_Limit'
 * '<S100>' : 'test3/RCTcc'
 * '<S101>' : 'test3/1/Enable//disable time constant'
 * '<S102>' : 'test3/1/Initialization'
 * '<S103>' : 'test3/1/Integrator (Discrete or Continuous)'
 * '<S104>' : 'test3/1/Enable//disable time constant/Compare To Zero'
 * '<S105>' : 'test3/1/Initialization/Init_u'
 * '<S106>' : 'test3/1/Integrator (Discrete or Continuous)/Discrete'
 * '<S107>' : 'test3/10/Enable//disable time constant'
 * '<S108>' : 'test3/10/Initialization'
 * '<S109>' : 'test3/10/Integrator (Discrete or Continuous)'
 * '<S110>' : 'test3/10/Enable//disable time constant/Compare To Zero'
 * '<S111>' : 'test3/10/Initialization/Init_u'
 * '<S112>' : 'test3/10/Integrator (Discrete or Continuous)/Discrete'
 * '<S113>' : 'test3/11/Enable//disable time constant'
 * '<S114>' : 'test3/11/Initialization'
 * '<S115>' : 'test3/11/Integrator (Discrete or Continuous)'
 * '<S116>' : 'test3/11/Enable//disable time constant/Compare To Zero'
 * '<S117>' : 'test3/11/Initialization/Init_u'
 * '<S118>' : 'test3/11/Integrator (Discrete or Continuous)/Discrete'
 * '<S119>' : 'test3/12/Enable//disable time constant'
 * '<S120>' : 'test3/12/Initialization'
 * '<S121>' : 'test3/12/Integrator (Discrete or Continuous)'
 * '<S122>' : 'test3/12/Enable//disable time constant/Compare To Zero'
 * '<S123>' : 'test3/12/Initialization/Init_u'
 * '<S124>' : 'test3/12/Integrator (Discrete or Continuous)/Discrete'
 * '<S125>' : 'test3/13/Enable//disable time constant'
 * '<S126>' : 'test3/13/Initialization'
 * '<S127>' : 'test3/13/Integrator (Discrete or Continuous)'
 * '<S128>' : 'test3/13/Enable//disable time constant/Compare To Zero'
 * '<S129>' : 'test3/13/Initialization/Init_u'
 * '<S130>' : 'test3/13/Integrator (Discrete or Continuous)/Discrete'
 * '<S131>' : 'test3/14/Enable//disable time constant'
 * '<S132>' : 'test3/14/Initialization'
 * '<S133>' : 'test3/14/Integrator (Discrete or Continuous)'
 * '<S134>' : 'test3/14/Enable//disable time constant/Compare To Zero'
 * '<S135>' : 'test3/14/Initialization/Init_u'
 * '<S136>' : 'test3/14/Integrator (Discrete or Continuous)/Discrete'
 * '<S137>' : 'test3/15/Enable//disable time constant'
 * '<S138>' : 'test3/15/Initialization'
 * '<S139>' : 'test3/15/Integrator (Discrete or Continuous)'
 * '<S140>' : 'test3/15/Enable//disable time constant/Compare To Zero'
 * '<S141>' : 'test3/15/Initialization/Init_u'
 * '<S142>' : 'test3/15/Integrator (Discrete or Continuous)/Discrete'
 * '<S143>' : 'test3/16/Enable//disable time constant'
 * '<S144>' : 'test3/16/Initialization'
 * '<S145>' : 'test3/16/Integrator (Discrete or Continuous)'
 * '<S146>' : 'test3/16/Enable//disable time constant/Compare To Zero'
 * '<S147>' : 'test3/16/Initialization/Init_u'
 * '<S148>' : 'test3/16/Integrator (Discrete or Continuous)/Discrete'
 * '<S149>' : 'test3/17/Enable//disable time constant'
 * '<S150>' : 'test3/17/Initialization'
 * '<S151>' : 'test3/17/Integrator (Discrete or Continuous)'
 * '<S152>' : 'test3/17/Enable//disable time constant/Compare To Zero'
 * '<S153>' : 'test3/17/Initialization/Init_u'
 * '<S154>' : 'test3/17/Integrator (Discrete or Continuous)/Discrete'
 * '<S155>' : 'test3/18/Enable//disable time constant'
 * '<S156>' : 'test3/18/Initialization'
 * '<S157>' : 'test3/18/Integrator (Discrete or Continuous)'
 * '<S158>' : 'test3/18/Enable//disable time constant/Compare To Zero'
 * '<S159>' : 'test3/18/Initialization/Init_u'
 * '<S160>' : 'test3/18/Integrator (Discrete or Continuous)/Discrete'
 * '<S161>' : 'test3/19/Enable//disable time constant'
 * '<S162>' : 'test3/19/Initialization'
 * '<S163>' : 'test3/19/Integrator (Discrete or Continuous)'
 * '<S164>' : 'test3/19/Enable//disable time constant/Compare To Zero'
 * '<S165>' : 'test3/19/Initialization/Init_u'
 * '<S166>' : 'test3/19/Integrator (Discrete or Continuous)/Discrete'
 * '<S167>' : 'test3/2/Enable//disable time constant'
 * '<S168>' : 'test3/2/Initialization'
 * '<S169>' : 'test3/2/Integrator (Discrete or Continuous)'
 * '<S170>' : 'test3/2/Enable//disable time constant/Compare To Zero'
 * '<S171>' : 'test3/2/Initialization/Init_u'
 * '<S172>' : 'test3/2/Integrator (Discrete or Continuous)/Discrete'
 * '<S173>' : 'test3/20/Enable//disable time constant'
 * '<S174>' : 'test3/20/Initialization'
 * '<S175>' : 'test3/20/Integrator (Discrete or Continuous)'
 * '<S176>' : 'test3/20/Enable//disable time constant/Compare To Zero'
 * '<S177>' : 'test3/20/Initialization/Init_u'
 * '<S178>' : 'test3/20/Integrator (Discrete or Continuous)/Discrete'
 * '<S179>' : 'test3/21/Enable//disable time constant'
 * '<S180>' : 'test3/21/Initialization'
 * '<S181>' : 'test3/21/Integrator (Discrete or Continuous)'
 * '<S182>' : 'test3/21/Enable//disable time constant/Compare To Zero'
 * '<S183>' : 'test3/21/Initialization/Init_u'
 * '<S184>' : 'test3/21/Integrator (Discrete or Continuous)/Discrete'
 * '<S185>' : 'test3/22/Enable//disable time constant'
 * '<S186>' : 'test3/22/Initialization'
 * '<S187>' : 'test3/22/Integrator (Discrete or Continuous)'
 * '<S188>' : 'test3/22/Enable//disable time constant/Compare To Zero'
 * '<S189>' : 'test3/22/Initialization/Init_u'
 * '<S190>' : 'test3/22/Integrator (Discrete or Continuous)/Discrete'
 * '<S191>' : 'test3/23/Enable//disable time constant'
 * '<S192>' : 'test3/23/Initialization'
 * '<S193>' : 'test3/23/Integrator (Discrete or Continuous)'
 * '<S194>' : 'test3/23/Enable//disable time constant/Compare To Zero'
 * '<S195>' : 'test3/23/Initialization/Init_u'
 * '<S196>' : 'test3/23/Integrator (Discrete or Continuous)/Discrete'
 * '<S197>' : 'test3/24/Enable//disable time constant'
 * '<S198>' : 'test3/24/Initialization'
 * '<S199>' : 'test3/24/Integrator (Discrete or Continuous)'
 * '<S200>' : 'test3/24/Enable//disable time constant/Compare To Zero'
 * '<S201>' : 'test3/24/Initialization/Init_u'
 * '<S202>' : 'test3/24/Integrator (Discrete or Continuous)/Discrete'
 * '<S203>' : 'test3/25/Enable//disable time constant'
 * '<S204>' : 'test3/25/Initialization'
 * '<S205>' : 'test3/25/Integrator (Discrete or Continuous)'
 * '<S206>' : 'test3/25/Enable//disable time constant/Compare To Zero'
 * '<S207>' : 'test3/25/Initialization/Init_u'
 * '<S208>' : 'test3/25/Integrator (Discrete or Continuous)/Discrete'
 * '<S209>' : 'test3/26/Enable//disable time constant'
 * '<S210>' : 'test3/26/Initialization'
 * '<S211>' : 'test3/26/Integrator (Discrete or Continuous)'
 * '<S212>' : 'test3/26/Enable//disable time constant/Compare To Zero'
 * '<S213>' : 'test3/26/Initialization/Init_u'
 * '<S214>' : 'test3/26/Integrator (Discrete or Continuous)/Discrete'
 * '<S215>' : 'test3/27/Enable//disable time constant'
 * '<S216>' : 'test3/27/Initialization'
 * '<S217>' : 'test3/27/Integrator (Discrete or Continuous)'
 * '<S218>' : 'test3/27/Enable//disable time constant/Compare To Zero'
 * '<S219>' : 'test3/27/Initialization/Init_u'
 * '<S220>' : 'test3/27/Integrator (Discrete or Continuous)/Discrete'
 * '<S221>' : 'test3/28/Enable//disable time constant'
 * '<S222>' : 'test3/28/Initialization'
 * '<S223>' : 'test3/28/Integrator (Discrete or Continuous)'
 * '<S224>' : 'test3/28/Enable//disable time constant/Compare To Zero'
 * '<S225>' : 'test3/28/Initialization/Init_u'
 * '<S226>' : 'test3/28/Integrator (Discrete or Continuous)/Discrete'
 * '<S227>' : 'test3/29/Enable//disable time constant'
 * '<S228>' : 'test3/29/Initialization'
 * '<S229>' : 'test3/29/Integrator (Discrete or Continuous)'
 * '<S230>' : 'test3/29/Enable//disable time constant/Compare To Zero'
 * '<S231>' : 'test3/29/Initialization/Init_u'
 * '<S232>' : 'test3/29/Integrator (Discrete or Continuous)/Discrete'
 * '<S233>' : 'test3/3/Enable//disable time constant'
 * '<S234>' : 'test3/3/Initialization'
 * '<S235>' : 'test3/3/Integrator (Discrete or Continuous)'
 * '<S236>' : 'test3/3/Enable//disable time constant/Compare To Zero'
 * '<S237>' : 'test3/3/Initialization/Init_u'
 * '<S238>' : 'test3/3/Integrator (Discrete or Continuous)/Discrete'
 * '<S239>' : 'test3/30/Enable//disable time constant'
 * '<S240>' : 'test3/30/Initialization'
 * '<S241>' : 'test3/30/Integrator (Discrete or Continuous)'
 * '<S242>' : 'test3/30/Enable//disable time constant/Compare To Zero'
 * '<S243>' : 'test3/30/Initialization/Init_u'
 * '<S244>' : 'test3/30/Integrator (Discrete or Continuous)/Discrete'
 * '<S245>' : 'test3/31/Enable//disable time constant'
 * '<S246>' : 'test3/31/Initialization'
 * '<S247>' : 'test3/31/Integrator (Discrete or Continuous)'
 * '<S248>' : 'test3/31/Enable//disable time constant/Compare To Zero'
 * '<S249>' : 'test3/31/Initialization/Init_u'
 * '<S250>' : 'test3/31/Integrator (Discrete or Continuous)/Discrete'
 * '<S251>' : 'test3/32/Enable//disable time constant'
 * '<S252>' : 'test3/32/Initialization'
 * '<S253>' : 'test3/32/Integrator (Discrete or Continuous)'
 * '<S254>' : 'test3/32/Enable//disable time constant/Compare To Zero'
 * '<S255>' : 'test3/32/Initialization/Init_u'
 * '<S256>' : 'test3/32/Integrator (Discrete or Continuous)/Discrete'
 * '<S257>' : 'test3/33/Enable//disable time constant'
 * '<S258>' : 'test3/33/Initialization'
 * '<S259>' : 'test3/33/Integrator (Discrete or Continuous)'
 * '<S260>' : 'test3/33/Enable//disable time constant/Compare To Zero'
 * '<S261>' : 'test3/33/Initialization/Init_u'
 * '<S262>' : 'test3/33/Integrator (Discrete or Continuous)/Discrete'
 * '<S263>' : 'test3/34/Enable//disable time constant'
 * '<S264>' : 'test3/34/Initialization'
 * '<S265>' : 'test3/34/Integrator (Discrete or Continuous)'
 * '<S266>' : 'test3/34/Enable//disable time constant/Compare To Zero'
 * '<S267>' : 'test3/34/Initialization/Init_u'
 * '<S268>' : 'test3/34/Integrator (Discrete or Continuous)/Discrete'
 * '<S269>' : 'test3/35/Enable//disable time constant'
 * '<S270>' : 'test3/35/Initialization'
 * '<S271>' : 'test3/35/Integrator (Discrete or Continuous)'
 * '<S272>' : 'test3/35/Enable//disable time constant/Compare To Zero'
 * '<S273>' : 'test3/35/Initialization/Init_u'
 * '<S274>' : 'test3/35/Integrator (Discrete or Continuous)/Discrete'
 * '<S275>' : 'test3/36/Enable//disable time constant'
 * '<S276>' : 'test3/36/Initialization'
 * '<S277>' : 'test3/36/Integrator (Discrete or Continuous)'
 * '<S278>' : 'test3/36/Enable//disable time constant/Compare To Zero'
 * '<S279>' : 'test3/36/Initialization/Init_u'
 * '<S280>' : 'test3/36/Integrator (Discrete or Continuous)/Discrete'
 * '<S281>' : 'test3/37/Enable//disable time constant'
 * '<S282>' : 'test3/37/Initialization'
 * '<S283>' : 'test3/37/Integrator (Discrete or Continuous)'
 * '<S284>' : 'test3/37/Enable//disable time constant/Compare To Zero'
 * '<S285>' : 'test3/37/Initialization/Init_u'
 * '<S286>' : 'test3/37/Integrator (Discrete or Continuous)/Discrete'
 * '<S287>' : 'test3/38/Enable//disable time constant'
 * '<S288>' : 'test3/38/Initialization'
 * '<S289>' : 'test3/38/Integrator (Discrete or Continuous)'
 * '<S290>' : 'test3/38/Enable//disable time constant/Compare To Zero'
 * '<S291>' : 'test3/38/Initialization/Init_u'
 * '<S292>' : 'test3/38/Integrator (Discrete or Continuous)/Discrete'
 * '<S293>' : 'test3/39/Enable//disable time constant'
 * '<S294>' : 'test3/39/Initialization'
 * '<S295>' : 'test3/39/Integrator (Discrete or Continuous)'
 * '<S296>' : 'test3/39/Enable//disable time constant/Compare To Zero'
 * '<S297>' : 'test3/39/Initialization/Init_u'
 * '<S298>' : 'test3/39/Integrator (Discrete or Continuous)/Discrete'
 * '<S299>' : 'test3/4/Enable//disable time constant'
 * '<S300>' : 'test3/4/Initialization'
 * '<S301>' : 'test3/4/Integrator (Discrete or Continuous)'
 * '<S302>' : 'test3/4/Enable//disable time constant/Compare To Zero'
 * '<S303>' : 'test3/4/Initialization/Init_u'
 * '<S304>' : 'test3/4/Integrator (Discrete or Continuous)/Discrete'
 * '<S305>' : 'test3/40/Enable//disable time constant'
 * '<S306>' : 'test3/40/Initialization'
 * '<S307>' : 'test3/40/Integrator (Discrete or Continuous)'
 * '<S308>' : 'test3/40/Enable//disable time constant/Compare To Zero'
 * '<S309>' : 'test3/40/Initialization/Init_u'
 * '<S310>' : 'test3/40/Integrator (Discrete or Continuous)/Discrete'
 * '<S311>' : 'test3/41/Enable//disable time constant'
 * '<S312>' : 'test3/41/Initialization'
 * '<S313>' : 'test3/41/Integrator (Discrete or Continuous)'
 * '<S314>' : 'test3/41/Enable//disable time constant/Compare To Zero'
 * '<S315>' : 'test3/41/Initialization/Init_u'
 * '<S316>' : 'test3/41/Integrator (Discrete or Continuous)/Discrete'
 * '<S317>' : 'test3/42/Enable//disable time constant'
 * '<S318>' : 'test3/42/Initialization'
 * '<S319>' : 'test3/42/Integrator (Discrete or Continuous)'
 * '<S320>' : 'test3/42/Enable//disable time constant/Compare To Zero'
 * '<S321>' : 'test3/42/Initialization/Init_u'
 * '<S322>' : 'test3/42/Integrator (Discrete or Continuous)/Discrete'
 * '<S323>' : 'test3/43/Enable//disable time constant'
 * '<S324>' : 'test3/43/Initialization'
 * '<S325>' : 'test3/43/Integrator (Discrete or Continuous)'
 * '<S326>' : 'test3/43/Enable//disable time constant/Compare To Zero'
 * '<S327>' : 'test3/43/Initialization/Init_u'
 * '<S328>' : 'test3/43/Integrator (Discrete or Continuous)/Discrete'
 * '<S329>' : 'test3/44/Enable//disable time constant'
 * '<S330>' : 'test3/44/Initialization'
 * '<S331>' : 'test3/44/Integrator (Discrete or Continuous)'
 * '<S332>' : 'test3/44/Enable//disable time constant/Compare To Zero'
 * '<S333>' : 'test3/44/Initialization/Init_u'
 * '<S334>' : 'test3/44/Integrator (Discrete or Continuous)/Discrete'
 * '<S335>' : 'test3/45/Enable//disable time constant'
 * '<S336>' : 'test3/45/Initialization'
 * '<S337>' : 'test3/45/Integrator (Discrete or Continuous)'
 * '<S338>' : 'test3/45/Enable//disable time constant/Compare To Zero'
 * '<S339>' : 'test3/45/Initialization/Init_u'
 * '<S340>' : 'test3/45/Integrator (Discrete or Continuous)/Discrete'
 * '<S341>' : 'test3/46/Enable//disable time constant'
 * '<S342>' : 'test3/46/Initialization'
 * '<S343>' : 'test3/46/Integrator (Discrete or Continuous)'
 * '<S344>' : 'test3/46/Enable//disable time constant/Compare To Zero'
 * '<S345>' : 'test3/46/Initialization/Init_u'
 * '<S346>' : 'test3/46/Integrator (Discrete or Continuous)/Discrete'
 * '<S347>' : 'test3/47/Enable//disable time constant'
 * '<S348>' : 'test3/47/Initialization'
 * '<S349>' : 'test3/47/Integrator (Discrete or Continuous)'
 * '<S350>' : 'test3/47/Enable//disable time constant/Compare To Zero'
 * '<S351>' : 'test3/47/Initialization/Init_u'
 * '<S352>' : 'test3/47/Integrator (Discrete or Continuous)/Discrete'
 * '<S353>' : 'test3/48/Enable//disable time constant'
 * '<S354>' : 'test3/48/Initialization'
 * '<S355>' : 'test3/48/Integrator (Discrete or Continuous)'
 * '<S356>' : 'test3/48/Enable//disable time constant/Compare To Zero'
 * '<S357>' : 'test3/48/Initialization/Init_u'
 * '<S358>' : 'test3/48/Integrator (Discrete or Continuous)/Discrete'
 * '<S359>' : 'test3/49/Enable//disable time constant'
 * '<S360>' : 'test3/49/Initialization'
 * '<S361>' : 'test3/49/Integrator (Discrete or Continuous)'
 * '<S362>' : 'test3/49/Enable//disable time constant/Compare To Zero'
 * '<S363>' : 'test3/49/Initialization/Init_u'
 * '<S364>' : 'test3/49/Integrator (Discrete or Continuous)/Discrete'
 * '<S365>' : 'test3/5/Enable//disable time constant'
 * '<S366>' : 'test3/5/Initialization'
 * '<S367>' : 'test3/5/Integrator (Discrete or Continuous)'
 * '<S368>' : 'test3/5/Enable//disable time constant/Compare To Zero'
 * '<S369>' : 'test3/5/Initialization/Init_u'
 * '<S370>' : 'test3/5/Integrator (Discrete or Continuous)/Discrete'
 * '<S371>' : 'test3/50/Enable//disable time constant'
 * '<S372>' : 'test3/50/Initialization'
 * '<S373>' : 'test3/50/Integrator (Discrete or Continuous)'
 * '<S374>' : 'test3/50/Enable//disable time constant/Compare To Zero'
 * '<S375>' : 'test3/50/Initialization/Init_u'
 * '<S376>' : 'test3/50/Integrator (Discrete or Continuous)/Discrete'
 * '<S377>' : 'test3/51/Enable//disable time constant'
 * '<S378>' : 'test3/51/Initialization'
 * '<S379>' : 'test3/51/Integrator (Discrete or Continuous)'
 * '<S380>' : 'test3/51/Enable//disable time constant/Compare To Zero'
 * '<S381>' : 'test3/51/Initialization/Init_u'
 * '<S382>' : 'test3/51/Integrator (Discrete or Continuous)/Discrete'
 * '<S383>' : 'test3/52/Enable//disable time constant'
 * '<S384>' : 'test3/52/Initialization'
 * '<S385>' : 'test3/52/Integrator (Discrete or Continuous)'
 * '<S386>' : 'test3/52/Enable//disable time constant/Compare To Zero'
 * '<S387>' : 'test3/52/Initialization/Init_u'
 * '<S388>' : 'test3/52/Integrator (Discrete or Continuous)/Discrete'
 * '<S389>' : 'test3/53/Enable//disable time constant'
 * '<S390>' : 'test3/53/Initialization'
 * '<S391>' : 'test3/53/Integrator (Discrete or Continuous)'
 * '<S392>' : 'test3/53/Enable//disable time constant/Compare To Zero'
 * '<S393>' : 'test3/53/Initialization/Init_u'
 * '<S394>' : 'test3/53/Integrator (Discrete or Continuous)/Discrete'
 * '<S395>' : 'test3/54/Enable//disable time constant'
 * '<S396>' : 'test3/54/Initialization'
 * '<S397>' : 'test3/54/Integrator (Discrete or Continuous)'
 * '<S398>' : 'test3/54/Enable//disable time constant/Compare To Zero'
 * '<S399>' : 'test3/54/Initialization/Init_u'
 * '<S400>' : 'test3/54/Integrator (Discrete or Continuous)/Discrete'
 * '<S401>' : 'test3/55/Enable//disable time constant'
 * '<S402>' : 'test3/55/Initialization'
 * '<S403>' : 'test3/55/Integrator (Discrete or Continuous)'
 * '<S404>' : 'test3/55/Enable//disable time constant/Compare To Zero'
 * '<S405>' : 'test3/55/Initialization/Init_u'
 * '<S406>' : 'test3/55/Integrator (Discrete or Continuous)/Discrete'
 * '<S407>' : 'test3/56/Enable//disable time constant'
 * '<S408>' : 'test3/56/Initialization'
 * '<S409>' : 'test3/56/Integrator (Discrete or Continuous)'
 * '<S410>' : 'test3/56/Enable//disable time constant/Compare To Zero'
 * '<S411>' : 'test3/56/Initialization/Init_u'
 * '<S412>' : 'test3/56/Integrator (Discrete or Continuous)/Discrete'
 * '<S413>' : 'test3/57/Enable//disable time constant'
 * '<S414>' : 'test3/57/Initialization'
 * '<S415>' : 'test3/57/Integrator (Discrete or Continuous)'
 * '<S416>' : 'test3/57/Enable//disable time constant/Compare To Zero'
 * '<S417>' : 'test3/57/Initialization/Init_u'
 * '<S418>' : 'test3/57/Integrator (Discrete or Continuous)/Discrete'
 * '<S419>' : 'test3/58/Enable//disable time constant'
 * '<S420>' : 'test3/58/Initialization'
 * '<S421>' : 'test3/58/Integrator (Discrete or Continuous)'
 * '<S422>' : 'test3/58/Enable//disable time constant/Compare To Zero'
 * '<S423>' : 'test3/58/Initialization/Init_u'
 * '<S424>' : 'test3/58/Integrator (Discrete or Continuous)/Discrete'
 * '<S425>' : 'test3/59/Enable//disable time constant'
 * '<S426>' : 'test3/59/Initialization'
 * '<S427>' : 'test3/59/Integrator (Discrete or Continuous)'
 * '<S428>' : 'test3/59/Enable//disable time constant/Compare To Zero'
 * '<S429>' : 'test3/59/Initialization/Init_u'
 * '<S430>' : 'test3/59/Integrator (Discrete or Continuous)/Discrete'
 * '<S431>' : 'test3/6/Enable//disable time constant'
 * '<S432>' : 'test3/6/Initialization'
 * '<S433>' : 'test3/6/Integrator (Discrete or Continuous)'
 * '<S434>' : 'test3/6/Enable//disable time constant/Compare To Zero'
 * '<S435>' : 'test3/6/Initialization/Init_u'
 * '<S436>' : 'test3/6/Integrator (Discrete or Continuous)/Discrete'
 * '<S437>' : 'test3/60/Enable//disable time constant'
 * '<S438>' : 'test3/60/Initialization'
 * '<S439>' : 'test3/60/Integrator (Discrete or Continuous)'
 * '<S440>' : 'test3/60/Enable//disable time constant/Compare To Zero'
 * '<S441>' : 'test3/60/Initialization/Init_u'
 * '<S442>' : 'test3/60/Integrator (Discrete or Continuous)/Discrete'
 * '<S443>' : 'test3/61/Enable//disable time constant'
 * '<S444>' : 'test3/61/Initialization'
 * '<S445>' : 'test3/61/Integrator (Discrete or Continuous)'
 * '<S446>' : 'test3/61/Enable//disable time constant/Compare To Zero'
 * '<S447>' : 'test3/61/Initialization/Init_u'
 * '<S448>' : 'test3/61/Integrator (Discrete or Continuous)/Discrete'
 * '<S449>' : 'test3/62/Enable//disable time constant'
 * '<S450>' : 'test3/62/Initialization'
 * '<S451>' : 'test3/62/Integrator (Discrete or Continuous)'
 * '<S452>' : 'test3/62/Enable//disable time constant/Compare To Zero'
 * '<S453>' : 'test3/62/Initialization/Init_u'
 * '<S454>' : 'test3/62/Integrator (Discrete or Continuous)/Discrete'
 * '<S455>' : 'test3/63/Enable//disable time constant'
 * '<S456>' : 'test3/63/Initialization'
 * '<S457>' : 'test3/63/Integrator (Discrete or Continuous)'
 * '<S458>' : 'test3/63/Enable//disable time constant/Compare To Zero'
 * '<S459>' : 'test3/63/Initialization/Init_u'
 * '<S460>' : 'test3/63/Integrator (Discrete or Continuous)/Discrete'
 * '<S461>' : 'test3/64/Enable//disable time constant'
 * '<S462>' : 'test3/64/Initialization'
 * '<S463>' : 'test3/64/Integrator (Discrete or Continuous)'
 * '<S464>' : 'test3/64/Enable//disable time constant/Compare To Zero'
 * '<S465>' : 'test3/64/Initialization/Init_u'
 * '<S466>' : 'test3/64/Integrator (Discrete or Continuous)/Discrete'
 * '<S467>' : 'test3/65/Enable//disable time constant'
 * '<S468>' : 'test3/65/Initialization'
 * '<S469>' : 'test3/65/Integrator (Discrete or Continuous)'
 * '<S470>' : 'test3/65/Enable//disable time constant/Compare To Zero'
 * '<S471>' : 'test3/65/Initialization/Init_u'
 * '<S472>' : 'test3/65/Integrator (Discrete or Continuous)/Discrete'
 * '<S473>' : 'test3/66/Enable//disable time constant'
 * '<S474>' : 'test3/66/Initialization'
 * '<S475>' : 'test3/66/Integrator (Discrete or Continuous)'
 * '<S476>' : 'test3/66/Enable//disable time constant/Compare To Zero'
 * '<S477>' : 'test3/66/Initialization/Init_u'
 * '<S478>' : 'test3/66/Integrator (Discrete or Continuous)/Discrete'
 * '<S479>' : 'test3/67/Enable//disable time constant'
 * '<S480>' : 'test3/67/Initialization'
 * '<S481>' : 'test3/67/Integrator (Discrete or Continuous)'
 * '<S482>' : 'test3/67/Enable//disable time constant/Compare To Zero'
 * '<S483>' : 'test3/67/Initialization/Init_u'
 * '<S484>' : 'test3/67/Integrator (Discrete or Continuous)/Discrete'
 * '<S485>' : 'test3/68/Enable//disable time constant'
 * '<S486>' : 'test3/68/Initialization'
 * '<S487>' : 'test3/68/Integrator (Discrete or Continuous)'
 * '<S488>' : 'test3/68/Enable//disable time constant/Compare To Zero'
 * '<S489>' : 'test3/68/Initialization/Init_u'
 * '<S490>' : 'test3/68/Integrator (Discrete or Continuous)/Discrete'
 * '<S491>' : 'test3/69/Enable//disable time constant'
 * '<S492>' : 'test3/69/Initialization'
 * '<S493>' : 'test3/69/Integrator (Discrete or Continuous)'
 * '<S494>' : 'test3/69/Enable//disable time constant/Compare To Zero'
 * '<S495>' : 'test3/69/Initialization/Init_u'
 * '<S496>' : 'test3/69/Integrator (Discrete or Continuous)/Discrete'
 * '<S497>' : 'test3/7/Enable//disable time constant'
 * '<S498>' : 'test3/7/Initialization'
 * '<S499>' : 'test3/7/Integrator (Discrete or Continuous)'
 * '<S500>' : 'test3/7/Enable//disable time constant/Compare To Zero'
 * '<S501>' : 'test3/7/Initialization/Init_u'
 * '<S502>' : 'test3/7/Integrator (Discrete or Continuous)/Discrete'
 * '<S503>' : 'test3/70/Enable//disable time constant'
 * '<S504>' : 'test3/70/Initialization'
 * '<S505>' : 'test3/70/Integrator (Discrete or Continuous)'
 * '<S506>' : 'test3/70/Enable//disable time constant/Compare To Zero'
 * '<S507>' : 'test3/70/Initialization/Init_u'
 * '<S508>' : 'test3/70/Integrator (Discrete or Continuous)/Discrete'
 * '<S509>' : 'test3/71/Enable//disable time constant'
 * '<S510>' : 'test3/71/Initialization'
 * '<S511>' : 'test3/71/Integrator (Discrete or Continuous)'
 * '<S512>' : 'test3/71/Enable//disable time constant/Compare To Zero'
 * '<S513>' : 'test3/71/Initialization/Init_u'
 * '<S514>' : 'test3/71/Integrator (Discrete or Continuous)/Discrete'
 * '<S515>' : 'test3/72/Enable//disable time constant'
 * '<S516>' : 'test3/72/Initialization'
 * '<S517>' : 'test3/72/Integrator (Discrete or Continuous)'
 * '<S518>' : 'test3/72/Enable//disable time constant/Compare To Zero'
 * '<S519>' : 'test3/72/Initialization/Init_u'
 * '<S520>' : 'test3/72/Integrator (Discrete or Continuous)/Discrete'
 * '<S521>' : 'test3/73/Enable//disable time constant'
 * '<S522>' : 'test3/73/Initialization'
 * '<S523>' : 'test3/73/Integrator (Discrete or Continuous)'
 * '<S524>' : 'test3/73/Enable//disable time constant/Compare To Zero'
 * '<S525>' : 'test3/73/Initialization/Init_u'
 * '<S526>' : 'test3/73/Integrator (Discrete or Continuous)/Discrete'
 * '<S527>' : 'test3/74/Enable//disable time constant'
 * '<S528>' : 'test3/74/Initialization'
 * '<S529>' : 'test3/74/Integrator (Discrete or Continuous)'
 * '<S530>' : 'test3/74/Enable//disable time constant/Compare To Zero'
 * '<S531>' : 'test3/74/Initialization/Init_u'
 * '<S532>' : 'test3/74/Integrator (Discrete or Continuous)/Discrete'
 * '<S533>' : 'test3/75/Enable//disable time constant'
 * '<S534>' : 'test3/75/Initialization'
 * '<S535>' : 'test3/75/Integrator (Discrete or Continuous)'
 * '<S536>' : 'test3/75/Enable//disable time constant/Compare To Zero'
 * '<S537>' : 'test3/75/Initialization/Init_u'
 * '<S538>' : 'test3/75/Integrator (Discrete or Continuous)/Discrete'
 * '<S539>' : 'test3/76/Enable//disable time constant'
 * '<S540>' : 'test3/76/Initialization'
 * '<S541>' : 'test3/76/Integrator (Discrete or Continuous)'
 * '<S542>' : 'test3/76/Enable//disable time constant/Compare To Zero'
 * '<S543>' : 'test3/76/Initialization/Init_u'
 * '<S544>' : 'test3/76/Integrator (Discrete or Continuous)/Discrete'
 * '<S545>' : 'test3/77/Enable//disable time constant'
 * '<S546>' : 'test3/77/Initialization'
 * '<S547>' : 'test3/77/Integrator (Discrete or Continuous)'
 * '<S548>' : 'test3/77/Enable//disable time constant/Compare To Zero'
 * '<S549>' : 'test3/77/Initialization/Init_u'
 * '<S550>' : 'test3/77/Integrator (Discrete or Continuous)/Discrete'
 * '<S551>' : 'test3/78/Enable//disable time constant'
 * '<S552>' : 'test3/78/Initialization'
 * '<S553>' : 'test3/78/Integrator (Discrete or Continuous)'
 * '<S554>' : 'test3/78/Enable//disable time constant/Compare To Zero'
 * '<S555>' : 'test3/78/Initialization/Init_u'
 * '<S556>' : 'test3/78/Integrator (Discrete or Continuous)/Discrete'
 * '<S557>' : 'test3/79/Enable//disable time constant'
 * '<S558>' : 'test3/79/Initialization'
 * '<S559>' : 'test3/79/Integrator (Discrete or Continuous)'
 * '<S560>' : 'test3/79/Enable//disable time constant/Compare To Zero'
 * '<S561>' : 'test3/79/Initialization/Init_u'
 * '<S562>' : 'test3/79/Integrator (Discrete or Continuous)/Discrete'
 * '<S563>' : 'test3/8/Enable//disable time constant'
 * '<S564>' : 'test3/8/Initialization'
 * '<S565>' : 'test3/8/Integrator (Discrete or Continuous)'
 * '<S566>' : 'test3/8/Enable//disable time constant/Compare To Zero'
 * '<S567>' : 'test3/8/Initialization/Init_u'
 * '<S568>' : 'test3/8/Integrator (Discrete or Continuous)/Discrete'
 * '<S569>' : 'test3/80/Enable//disable time constant'
 * '<S570>' : 'test3/80/Initialization'
 * '<S571>' : 'test3/80/Integrator (Discrete or Continuous)'
 * '<S572>' : 'test3/80/Enable//disable time constant/Compare To Zero'
 * '<S573>' : 'test3/80/Initialization/Init_u'
 * '<S574>' : 'test3/80/Integrator (Discrete or Continuous)/Discrete'
 * '<S575>' : 'test3/81/Enable//disable time constant'
 * '<S576>' : 'test3/81/Initialization'
 * '<S577>' : 'test3/81/Integrator (Discrete or Continuous)'
 * '<S578>' : 'test3/81/Enable//disable time constant/Compare To Zero'
 * '<S579>' : 'test3/81/Initialization/Init_u'
 * '<S580>' : 'test3/81/Integrator (Discrete or Continuous)/Discrete'
 * '<S581>' : 'test3/82/Enable//disable time constant'
 * '<S582>' : 'test3/82/Initialization'
 * '<S583>' : 'test3/82/Integrator (Discrete or Continuous)'
 * '<S584>' : 'test3/82/Enable//disable time constant/Compare To Zero'
 * '<S585>' : 'test3/82/Initialization/Init_u'
 * '<S586>' : 'test3/82/Integrator (Discrete or Continuous)/Discrete'
 * '<S587>' : 'test3/83/Enable//disable time constant'
 * '<S588>' : 'test3/83/Initialization'
 * '<S589>' : 'test3/83/Integrator (Discrete or Continuous)'
 * '<S590>' : 'test3/83/Enable//disable time constant/Compare To Zero'
 * '<S591>' : 'test3/83/Initialization/Init_u'
 * '<S592>' : 'test3/83/Integrator (Discrete or Continuous)/Discrete'
 * '<S593>' : 'test3/84/Enable//disable time constant'
 * '<S594>' : 'test3/84/Initialization'
 * '<S595>' : 'test3/84/Integrator (Discrete or Continuous)'
 * '<S596>' : 'test3/84/Enable//disable time constant/Compare To Zero'
 * '<S597>' : 'test3/84/Initialization/Init_u'
 * '<S598>' : 'test3/84/Integrator (Discrete or Continuous)/Discrete'
 * '<S599>' : 'test3/85/Enable//disable time constant'
 * '<S600>' : 'test3/85/Initialization'
 * '<S601>' : 'test3/85/Integrator (Discrete or Continuous)'
 * '<S602>' : 'test3/85/Enable//disable time constant/Compare To Zero'
 * '<S603>' : 'test3/85/Initialization/Init_u'
 * '<S604>' : 'test3/85/Integrator (Discrete or Continuous)/Discrete'
 * '<S605>' : 'test3/86/Enable//disable time constant'
 * '<S606>' : 'test3/86/Initialization'
 * '<S607>' : 'test3/86/Integrator (Discrete or Continuous)'
 * '<S608>' : 'test3/86/Enable//disable time constant/Compare To Zero'
 * '<S609>' : 'test3/86/Initialization/Init_u'
 * '<S610>' : 'test3/86/Integrator (Discrete or Continuous)/Discrete'
 * '<S611>' : 'test3/87/Enable//disable time constant'
 * '<S612>' : 'test3/87/Initialization'
 * '<S613>' : 'test3/87/Integrator (Discrete or Continuous)'
 * '<S614>' : 'test3/87/Enable//disable time constant/Compare To Zero'
 * '<S615>' : 'test3/87/Initialization/Init_u'
 * '<S616>' : 'test3/87/Integrator (Discrete or Continuous)/Discrete'
 * '<S617>' : 'test3/88/Enable//disable time constant'
 * '<S618>' : 'test3/88/Initialization'
 * '<S619>' : 'test3/88/Integrator (Discrete or Continuous)'
 * '<S620>' : 'test3/88/Enable//disable time constant/Compare To Zero'
 * '<S621>' : 'test3/88/Initialization/Init_u'
 * '<S622>' : 'test3/88/Integrator (Discrete or Continuous)/Discrete'
 * '<S623>' : 'test3/89/Enable//disable time constant'
 * '<S624>' : 'test3/89/Initialization'
 * '<S625>' : 'test3/89/Integrator (Discrete or Continuous)'
 * '<S626>' : 'test3/89/Enable//disable time constant/Compare To Zero'
 * '<S627>' : 'test3/89/Initialization/Init_u'
 * '<S628>' : 'test3/89/Integrator (Discrete or Continuous)/Discrete'
 * '<S629>' : 'test3/9/Enable//disable time constant'
 * '<S630>' : 'test3/9/Initialization'
 * '<S631>' : 'test3/9/Integrator (Discrete or Continuous)'
 * '<S632>' : 'test3/9/Enable//disable time constant/Compare To Zero'
 * '<S633>' : 'test3/9/Initialization/Init_u'
 * '<S634>' : 'test3/9/Integrator (Discrete or Continuous)/Discrete'
 * '<S635>' : 'test3/90/Enable//disable time constant'
 * '<S636>' : 'test3/90/Initialization'
 * '<S637>' : 'test3/90/Integrator (Discrete or Continuous)'
 * '<S638>' : 'test3/90/Enable//disable time constant/Compare To Zero'
 * '<S639>' : 'test3/90/Initialization/Init_u'
 * '<S640>' : 'test3/90/Integrator (Discrete or Continuous)/Discrete'
 * '<S641>' : 'test3/91/Enable//disable time constant'
 * '<S642>' : 'test3/91/Initialization'
 * '<S643>' : 'test3/91/Integrator (Discrete or Continuous)'
 * '<S644>' : 'test3/91/Enable//disable time constant/Compare To Zero'
 * '<S645>' : 'test3/91/Initialization/Init_u'
 * '<S646>' : 'test3/91/Integrator (Discrete or Continuous)/Discrete'
 * '<S647>' : 'test3/92/Enable//disable time constant'
 * '<S648>' : 'test3/92/Initialization'
 * '<S649>' : 'test3/92/Integrator (Discrete or Continuous)'
 * '<S650>' : 'test3/92/Enable//disable time constant/Compare To Zero'
 * '<S651>' : 'test3/92/Initialization/Init_u'
 * '<S652>' : 'test3/92/Integrator (Discrete or Continuous)/Discrete'
 * '<S653>' : 'test3/93/Enable//disable time constant'
 * '<S654>' : 'test3/93/Initialization'
 * '<S655>' : 'test3/93/Integrator (Discrete or Continuous)'
 * '<S656>' : 'test3/93/Enable//disable time constant/Compare To Zero'
 * '<S657>' : 'test3/93/Initialization/Init_u'
 * '<S658>' : 'test3/93/Integrator (Discrete or Continuous)/Discrete'
 * '<S659>' : 'test3/94/Enable//disable time constant'
 * '<S660>' : 'test3/94/Initialization'
 * '<S661>' : 'test3/94/Integrator (Discrete or Continuous)'
 * '<S662>' : 'test3/94/Enable//disable time constant/Compare To Zero'
 * '<S663>' : 'test3/94/Initialization/Init_u'
 * '<S664>' : 'test3/94/Integrator (Discrete or Continuous)/Discrete'
 * '<S665>' : 'test3/95/Enable//disable time constant'
 * '<S666>' : 'test3/95/Initialization'
 * '<S667>' : 'test3/95/Integrator (Discrete or Continuous)'
 * '<S668>' : 'test3/95/Enable//disable time constant/Compare To Zero'
 * '<S669>' : 'test3/95/Initialization/Init_u'
 * '<S670>' : 'test3/95/Integrator (Discrete or Continuous)/Discrete'
 * '<S671>' : 'test3/96/Enable//disable time constant'
 * '<S672>' : 'test3/96/Initialization'
 * '<S673>' : 'test3/96/Integrator (Discrete or Continuous)'
 * '<S674>' : 'test3/96/Enable//disable time constant/Compare To Zero'
 * '<S675>' : 'test3/96/Initialization/Init_u'
 * '<S676>' : 'test3/96/Integrator (Discrete or Continuous)/Discrete'
 * '<S677>' : 'test3/BMS_Function/Chart'
 * '<S678>' : 'test3/BMS_Function/Chart/Main.MainStateMachine.Charginig.Personal_Mode1.PI'
 * '<S679>' : 'test3/BMS_Function/Chart/Main.MainStateMachine.Charginig.PreCharge_Mode.PI'
 * '<S680>' : 'test3/CAN_VCU_Fault/Chart'
 * '<S681>' : 'test3/CAN_VCU_Fault/Chart1'
 * '<S682>' : 'test3/Current_Limit/ChargeCurrentLimit_Calc'
 * '<S683>' : 'test3/Current_Limit/DischargeCurrentLimit_Calc'
 * '<S684>' : 'test3/RCTcc/1'
 * '<S685>' : 'test3/RCTcc/Chart1'
 * '<S686>' : 'test3/RCTcc/1/Enable//disable time constant'
 * '<S687>' : 'test3/RCTcc/1/Initialization'
 * '<S688>' : 'test3/RCTcc/1/Integrator (Discrete or Continuous)'
 * '<S689>' : 'test3/RCTcc/1/Enable//disable time constant/Compare To Zero'
 * '<S690>' : 'test3/RCTcc/1/Initialization/Init_u'
 * '<S691>' : 'test3/RCTcc/1/Integrator (Discrete or Continuous)/Discrete'
 */
#endif                                 /* RTW_HEADER_test3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
