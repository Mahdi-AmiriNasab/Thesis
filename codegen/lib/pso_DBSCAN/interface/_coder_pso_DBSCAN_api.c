/*
 * File: _coder_pso_DBSCAN_api.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

/* Include Files */
#include "_coder_pso_DBSCAN_api.h"
#include "_coder_pso_DBSCAN_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131642U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "pso_DBSCAN",                                         /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[9];

static const mxArray *b_emlrt_marshallOut(const real_T u[81]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *minPts,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u[18]);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *socs,
                                 const char_T *identifier))[9];

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

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
 * Arguments    : const real_T u[81]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u[81])
{
  static const int32_T iv[2] = {9, 9};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    for (c_i = 0; c_i < 9; c_i++) {
      pData[i + c_i] = u[c_i + 9 * b_i];
    }
    i += 9;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *minPts
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *minPts,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(minPts), &thisId);
  emlrtDestroyArray(&minPts);
  return y;
}

/*
 * Arguments    : const real_T u[18]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u[18])
{
  static const int32_T iv[2] = {2, 9};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    int32_T i1;
    i1 = b_i << 1;
    pData[i] = u[i1];
    pData[i + 1] = u[i1 + 1];
    i += 2;
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
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[9])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *socs
 *                const char_T *identifier
 * Return Type  : real_T (*)[9]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *socs,
                                 const char_T *identifier))[9]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[9];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(socs), &thisId);
  emlrtDestroyArray(&socs);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct0_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u)
{
  static const int32_T enumValues[3] = {0, 1, 2};
  static const int32_T iv[2] = {1, 9};
  static const int32_T iv1[2] = {9, 2};
  static const int32_T i1 = 2;
  static const int32_T i2 = 2;
  static const int32_T i3 = 2;
  static const char_T *sv[13] = {
      "cell_cnt",    "average",        "dbscan_res",    "clt_res_cell",
      "clt_res_soc", "clt_res_soc_av", "clt_max_count", "clt_noise_soc",
      "clt_soc",     "noise_max",      "noise_min",     "single_noise",
      "noise_status"};
  static const char_T *enumNames[3] = {"noise_not_found", "noise_found",
                                       "noise_single_found"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 13, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(u->cell_cnt);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "cell_cnt", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->average);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "average", c_y, 1);
  d_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (i = 0; i < 9; i++) {
    pData[i] = u->dbscan_res[i];
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "dbscan_res", d_y, 2);
  emlrtSetFieldR2017b(y, 0, "clt_res_cell",
                      b_emlrt_marshallOut(u->clt_res_cell), 3);
  emlrtSetFieldR2017b(y, 0, "clt_res_soc", b_emlrt_marshallOut(u->clt_res_soc),
                      4);
  e_y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  b_i = 0;
  for (i = 0; i < 2; i++) {
    for (c_i = 0; c_i < 9; c_i++) {
      pData[b_i + c_i] = u->clt_res_soc_av[c_i + 9 * i];
    }
    b_i += 9;
  }
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "clt_res_soc_av", e_y, 5);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u->clt_max_count);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "clt_max_count", f_y, 6);
  emlrtSetFieldR2017b(y, 0, "clt_noise_soc",
                      c_emlrt_marshallOut(u->clt_noise_soc), 7);
  emlrtSetFieldR2017b(y, 0, "clt_soc", c_emlrt_marshallOut(u->clt_soc), 8);
  g_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i1, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->noise_max[0];
  pData[1] = u->noise_max[1];
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "noise_max", g_y, 9);
  h_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i2, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->noise_min[0];
  pData[1] = u->noise_min[1];
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, "noise_min", h_y, 10);
  i_y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i3, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->single_noise[0];
  pData[1] = u->single_noise[1];
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, "single_noise", i_y, 11);
  j_y = NULL;
  m1 = NULL;
  emlrtCheckEnumR2012b((emlrtConstCTX)sp, "e_noise_stat", 3,
                       (const char_T **)&enumNames[0], &enumValues[0]);
  k_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = (int32_T)u->noise_status;
  emlrtAssign(&k_y, m);
  emlrtAssign(&m1, k_y);
  emlrtAssign(&j_y,
              emlrtCreateEnumR2012b((emlrtConstCTX)sp, "e_noise_stat", m1));
  emlrtDestroyArray(&m1);
  emlrtSetFieldR2017b(y, 0, "noise_status", j_y, 12);
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
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray **plhs
 * Return Type  : void
 */
void pso_DBSCAN_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  struct0_T cluster;
  real_T(*socs)[9];
  real_T eps;
  real_T minPts;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  socs = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "socs");
  minPts = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "minPts");
  eps = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "eps");
  /* Invoke the target function */
  pso_DBSCAN(*socs, minPts, eps, &cluster);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &cluster);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_DBSCAN_atexit(void)
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
  pso_DBSCAN_xil_terminate();
  pso_DBSCAN_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void pso_DBSCAN_initialize(void)
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
void pso_DBSCAN_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_pso_DBSCAN_api.c
 *
 * [EOF]
 */
