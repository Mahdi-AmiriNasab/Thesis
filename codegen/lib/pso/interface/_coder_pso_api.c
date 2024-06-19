/*
 * File: _coder_pso_api.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "_coder_pso_api.h"
#include "_coder_pso_mex.h"

/* Type Definitions */
#ifndef typedef_emxArray_struct1_T_1x50
#define typedef_emxArray_struct1_T_1x50
typedef struct {
  struct1_T data[50];
  int32_T size[2];
} emxArray_struct1_T_1x50;
#endif /* typedef_emxArray_struct1_T_1x50 */

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,     /* bFirstTime */
    false,    /* bInitialized */
    131643UL, /* fVersionInfo */
    NULL,     /* fErrorFunction */
    "pso",    /* fFunctionName */
    NULL,     /* fRTCallStack */
    false,    /* bDebugMode */
    {2045744189UL, 2170104910UL, 2743257031UL, 4284093946UL}, /* fSigWrd */
    NULL                                                      /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static const mxArray *b_emlrt_marshallOut(const struct1_T u_data[]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
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

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
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
  iv[0L] = 1L;
  iv[1L] = 50L;
  emlrtAssign(
      &y, emlrtCreateStructArray(2L, &iv[0L], 4L, (const char_T **)&sv[0L]));
  emlrtCreateField(y, "source_queue_cells");
  emlrtCreateField(y, "destination_queue_cells");
  emlrtCreateField(y, "source_target_soc_av");
  emlrtCreateField(y, "destination_target_soc_av");
  i = 0L;
  for (b_j1 = 0L; b_j1 < 50L; b_j1++) {
    emlrtSetFieldR2017b(
        y, i, "source_queue_cells",
        c_emlrt_marshallOut(u_data[b_j1].source_queue_cells.data,
                            u_data[b_j1].source_queue_cells.size),
        0L);
    emlrtSetFieldR2017b(
        y, i, "destination_queue_cells",
        c_emlrt_marshallOut(u_data[b_j1].destination_queue_cells.data,
                            u_data[b_j1].destination_queue_cells.size),
        1L);
    emlrtSetFieldR2017b(
        y, i, "source_target_soc_av",
        d_emlrt_marshallOut(u_data[b_j1].source_target_soc_av.data,
                            u_data[b_j1].source_target_soc_av.size[0L]),
        2L);
    emlrtSetFieldR2017b(
        y, i, "destination_target_soc_av",
        d_emlrt_marshallOut(u_data[b_j1].destination_target_soc_av.data,
                            u_data[b_j1].destination_target_soc_av.size[0L]),
        3L);
    i++;
  }
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
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
  iv[0L] = u_size[0L];
  iv[1L] = 2L;
  m = emlrtCreateNumericArray(2L, &iv[0L], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0L;
  b_i = 0L;
  while (b_i < u_size[0L]) {
    pData[i] = u_data[0L];
    i++;
    b_i = 1L;
  }
  b_i = 0L;
  while (b_i < u_size[0L]) {
    pData[i] = u_data[1L];
    i++;
    b_i = 1L;
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
  m = emlrtCreateNumericArray(1L, (const void *)&u_size, mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0L;
  b_i = 0L;
  while (b_i < u_size) {
    pData[i] = u_data[0L];
    i++;
    b_i = 1L;
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
  static const int32_T dims[2] = {1L, 9L};
  real_T(*ret)[9];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2UL,
                            (const void *)&dims[0L], &bv[0L], &iv[0L]);
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
  static const int32_T iv[2] = {1L, 9L};
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
  emlrtAssign(&y,
              emlrtCreateStructMatrix(1L, 1L, 4L, (const char_T **)&sv[0L]));
  b_y = NULL;
  m = emlrtCreateNumericArray(2L, (const void *)&iv[0L], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  for (i = 0L; i < 9L; i++) {
    pData[i] = u->soc[i];
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0L, "soc", b_y, 0L);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->time);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0L, "time", c_y, 1L);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->inconsistency);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0L, "inconsistency", d_y, 2L);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(u->eq_overlap);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0L, "eq_overlap", e_y, 3L);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nullptr
 *                const char_T *identifier
 * Return Type  : real_T (*)[9]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
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
  emlrtAssign(&y,
              emlrtCreateStructMatrix(1L, 1L, 2L, (const char_T **)&sv[0L]));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(u.position);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0L, "position", b_y, 0L);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u.cost);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0L, "cost", c_y, 1L);
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
  static const int32_T dims = 0L;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0UL,
                          (const void *)&dims);
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
  static emxArray_struct1_T_1x50 eq_step;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T global_best;
  struct2_T stio;
  real_T(*soc_in)[9];
  real_T mp;
  real_T w_eq_overlap;
  real_T w_inconsistency;
  real_T w_time;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  soc_in = emlrt_marshallIn(&st, emlrtAlias(prhs[0L]), "soc_in");
  mp = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1L]), "mp");
  w_time = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2L]), "w_time");
  w_inconsistency =
      c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3L]), "w_inconsistency");
  w_eq_overlap = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4L]), "w_eq_overlap");
  /* Invoke the target function */
  pso(*soc_in, mp, w_time, w_inconsistency, w_eq_overlap, &global_best,
      eq_step.data, eq_step.size, &stio);
  /* Marshall function outputs */
  plhs[0L] = emlrt_marshallOut(global_best);
  if (nlhs > 1L) {
    plhs[1L] = b_emlrt_marshallOut(eq_step.data);
  }
  if (nlhs > 2L) {
    plhs[2L] = e_emlrt_marshallOut(&stio);
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
  emlrtClearAllocCountR2012b(&st, false, 0UL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_pso_api.c
 *
 * [EOF]
 */
