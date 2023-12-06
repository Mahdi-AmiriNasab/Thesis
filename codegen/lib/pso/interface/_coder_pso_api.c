/*
 * File: _coder_pso_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "_coder_pso_api.h"
#include "_coder_pso_mex.h"

/* Type Definitions */
#ifndef typedef_emxArray_struct1_T_1x100
#define typedef_emxArray_struct1_T_1x100
typedef struct {
  struct1_T data[100];
  int32_T size[2];
} emxArray_struct1_T_1x100;
#endif /* typedef_emxArray_struct1_T_1x100 */

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "pso",                                                /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static const mxArray *b_emlrt_marshallOut(const struct1_T u_data[]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mp,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2]);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9];

static const mxArray *e_emlrt_marshallOut(const struct2_T *u);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *soc_in,
                                 const char_T *identifier))[9];

static const mxArray *emlrt_marshallOut(const struct0_T u);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[9]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9]
{
  real_T(*y)[9];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const struct1_T u_data[]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const struct1_T u_data[])
{
  static const char_T *sv[4] = {"source_queue_cells", "destination_queue_cells",
                                "source_target_soc_av",
                                "destination_target_soc_av"};
  const mxArray *y;
  int32_T iv[2];
  int32_T b_j1;
  int32_T i;
  y = NULL;
  iv[0] = 1;
  iv[1] = 100;
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 4, (const char_T **)&sv[0]));
  emlrtCreateField(y, (const char_T *)"source_queue_cells");
  emlrtCreateField(y, (const char_T *)"destination_queue_cells");
  emlrtCreateField(y, (const char_T *)"source_target_soc_av");
  emlrtCreateField(y, (const char_T *)"destination_target_soc_av");
  i = 0;
  for (b_j1 = 0; b_j1 < 100; b_j1++) {
    emlrtSetFieldR2017b(
        y, i, (const char_T *)"source_queue_cells",
        c_emlrt_marshallOut(u_data[b_j1].source_queue_cells.data,
                            u_data[b_j1].source_queue_cells.size),
        0);
    emlrtSetFieldR2017b(
        y, i, (const char_T *)"destination_queue_cells",
        c_emlrt_marshallOut(u_data[b_j1].destination_queue_cells.data,
                            u_data[b_j1].destination_queue_cells.size),
        1);
    emlrtSetFieldR2017b(
        y, i, (const char_T *)"source_target_soc_av",
        d_emlrt_marshallOut(u_data[b_j1].source_target_soc_av.data,
                            u_data[b_j1].source_target_soc_av.size[0]),
        2);
    emlrtSetFieldR2017b(
        y, i, (const char_T *)"destination_target_soc_av",
        d_emlrt_marshallOut(u_data[b_j1].destination_target_soc_av.data,
                            u_data[b_j1].destination_target_soc_av.size[0]),
        3);
    i++;
  }
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *mp
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *mp,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(mp), &thisId);
  emlrtDestroyArray(&mp);
  return y;
}

/*
 * Arguments    : const real_T u_data[]
 *                const int32_T u_size[2]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2])
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  y = NULL;
  iv[0] = u_size[0];
  iv[1] = 2;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  b_i = 0;
  while (b_i < u_size[0]) {
    pData[i] = u_data[0];
    i++;
    b_i = 1;
  }
  b_i = 0;
  while (b_i < u_size[0]) {
    pData[i] = u_data[1];
    i++;
    b_i = 1;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u_data[]
 *                const int32_T u_size
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&u_size, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  b_i = 0;
  while (b_i < u_size) {
    pData[i] = u_data[0];
    i++;
    b_i = 1;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[9]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9]
{
  static const int32_T dims[2] = {1, 9};
  real_T(*ret)[9];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const struct2_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const struct2_T *u)
{
  static const int32_T iv[2] = {1, 9};
  static const char_T *sv[4] = {"soc", "time", "inconsistency", "eq_overlap"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (i = 0; i < 9; i++) {
    pData[i] = u->soc[i];
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"soc", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->time);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"time", c_y, 1);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->inconsistency);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"inconsistency", d_y, 2);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(u->eq_overlap);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"eq_overlap", e_y, 3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *soc_in
 *                const char_T *identifier
 * Return Type  : real_T (*)[9]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *soc_in,
                                 const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(soc_in), &thisId);
  emlrtDestroyArray(&soc_in);
  return y;
}

/*
 * Arguments    : const struct0_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const struct0_T u)
{
  static const char_T *sv[2] = {"position", "cost"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(u.position);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"position", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u.cost);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"cost", c_y, 1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[5]
 *                int32_T nlhs
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void pso_api(const mxArray *const prhs[5], int32_T nlhs, const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_struct1_T_1x100 eq_step;
  struct0_T global_best;
  struct2_T stio;
  real_T(*soc_in)[9];
  real_T mp;
  real_T w_eq_overlap;
  real_T w_inconsistency;
  real_T w_time;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  soc_in = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "soc_in");
  mp = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "mp");
  w_time = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "w_time");
  w_inconsistency =
      c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "w_inconsistency");
  w_eq_overlap = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "w_eq_overlap");
  /* Invoke the target function */
  pso(*soc_in, mp, w_time, w_inconsistency, w_eq_overlap, &global_best,
      eq_step.data, eq_step.size, &stio);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(global_best);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(eq_step.data);
  }
  if (nlhs > 2) {
    plhs[2] = e_emlrt_marshallOut(&stio);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  pso_xil_terminate();
  pso_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_pso_api.c
 *
 * [EOF]
 */
