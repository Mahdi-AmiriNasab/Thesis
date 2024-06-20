/*
 * File: _coder_pso_api.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "_coder_pso_api.h"
#include "_coder_pso_mex.h"
#include "xil_host_interface.h"

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

static boolean_T xilAlreadyInited;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
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

static void b_xilHostDeserializer(real_T *r);

static void b_xilHostSerializer(const real_T *r);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size[2]);

static void c_xilHostDeserializer(struct1_T _data[], int32_T _size[2]);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const real_T u_data[],
                                          const int32_T u_size);

static void d_xilHostDeserializer(int32_T r[2]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[9];

static const mxArray *e_emlrt_marshallOut(const struct2_T *u);

static void e_xilHostDeserializer(struct1_T *r);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[9];

static const mxArray *emlrt_marshallOut(const struct0_T u);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void f_xilHostDeserializer(real_T _data[], int32_T _size[2]);

static int32_T g_xilHostDeserializer(real_T _data[]);

static int32_T h_xilHostDeserializer(void);

static void i_xilHostDeserializer(struct2_T *r);

static void j_xilHostDeserializer(real_T r[9]);

static void pso_once(void);

static void xilHostDeserializer(struct0_T *r);

static void xilHostSerializer(const real_T r[9]);

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
  iv[1] = 50;
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 4, (const char_T **)&sv[0]));
  emlrtCreateField(y, "source_queue_cells");
  emlrtCreateField(y, "destination_queue_cells");
  emlrtCreateField(y, "source_target_soc_av");
  emlrtCreateField(y, "destination_target_soc_av");
  i = 0;
  for (b_j1 = 0; b_j1 < 50; b_j1++) {
    emlrtSetFieldR2017b(
        y, i, "source_queue_cells",
        c_emlrt_marshallOut(u_data[b_j1].source_queue_cells.data,
                            u_data[b_j1].source_queue_cells.size),
        0);
    emlrtSetFieldR2017b(
        y, i, "destination_queue_cells",
        c_emlrt_marshallOut(u_data[b_j1].destination_queue_cells.data,
                            u_data[b_j1].destination_queue_cells.size),
        1);
    emlrtSetFieldR2017b(
        y, i, "source_target_soc_av",
        d_emlrt_marshallOut(u_data[b_j1].source_target_soc_av.data,
                            u_data[b_j1].source_target_soc_av.size[0]),
        2);
    emlrtSetFieldR2017b(
        y, i, "destination_target_soc_av",
        d_emlrt_marshallOut(u_data[b_j1].destination_target_soc_av.data,
                            u_data[b_j1].destination_target_soc_av.size[0]),
        3);
    i++;
  }
  return y;
}

/*
 * Arguments    : real_T *r
 * Return Type  : void
 */
static void b_xilHostDeserializer(real_T *r)
{
  xilReadData((uint8_T *)r, (size_t)1, MEM_UNIT_DOUBLE_TYPE);
}

/*
 * Arguments    : const real_T *r
 * Return Type  : void
 */
static void b_xilHostSerializer(const real_T *r)
{
  xilWriteData((uint8_T *)r, (size_t)1, MEM_UNIT_DOUBLE_TYPE);
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
 * Arguments    : struct1_T _data[]
 *                int32_T _size[2]
 * Return Type  : void
 */
static void c_xilHostDeserializer(struct1_T _data[], int32_T _size[2])
{
  int32_T sizeVal[2];
  int32_T b_j1;
  d_xilHostDeserializer(sizeVal);
  _size[0] = sizeVal[0];
  _size[1] = sizeVal[1];
  for (b_j1 = 0; b_j1 < 50; b_j1++) {
    e_xilHostDeserializer(&_data[b_j1]);
  }
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
 * Arguments    : int32_T r[2]
 * Return Type  : void
 */
static void d_xilHostDeserializer(int32_T r[2])
{
  xilReadData((uint8_T *)&r[0], (size_t)2, MEM_UNIT_INT32_TYPE);
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
  emlrtSetFieldR2017b(y, 0, "soc", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u->time);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "time", c_y, 1);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->inconsistency);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "inconsistency", d_y, 2);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(u->eq_overlap);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "eq_overlap", e_y, 3);
  return y;
}

/*
 * Arguments    : struct1_T *r
 * Return Type  : void
 */
static void e_xilHostDeserializer(struct1_T *r)
{
  f_xilHostDeserializer(r->source_queue_cells.data, r->source_queue_cells.size);
  f_xilHostDeserializer(r->destination_queue_cells.data,
                        r->destination_queue_cells.size);
  r->source_target_soc_av.size[0] =
      g_xilHostDeserializer(r->source_target_soc_av.data);
  r->destination_target_soc_av.size[0] =
      g_xilHostDeserializer(r->destination_target_soc_av.data);
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
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(u.position);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "position", b_y, 0);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u.cost);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "cost", c_y, 1);
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
 * Arguments    : real_T _data[]
 *                int32_T _size[2]
 * Return Type  : void
 */
static void f_xilHostDeserializer(real_T _data[], int32_T _size[2])
{
  int32_T sizeVal[2];
  d_xilHostDeserializer(sizeVal);
  _size[0] = sizeVal[0];
  _size[1] = sizeVal[1];
  xilReadData((uint8_T *)&_data[0], (size_t)(_size[0] << 1),
              MEM_UNIT_DOUBLE_TYPE);
}

/*
 * Arguments    : real_T _data[]
 * Return Type  : int32_T
 */
static int32_T g_xilHostDeserializer(real_T _data[])
{
  int32_T _size;
  _size = h_xilHostDeserializer();
  xilReadData((uint8_T *)&_data[0], (size_t)_size, MEM_UNIT_DOUBLE_TYPE);
  return _size;
}

/*
 * Arguments    : void
 * Return Type  : int32_T
 */
static int32_T h_xilHostDeserializer(void)
{
  int32_T i;
  xilReadData((uint8_T *)&i, (size_t)1, MEM_UNIT_INT32_TYPE);
  return i;
}

/*
 * Arguments    : struct2_T *r
 * Return Type  : void
 */
static void i_xilHostDeserializer(struct2_T *r)
{
  j_xilHostDeserializer(r->soc);
  b_xilHostDeserializer(&r->time);
  b_xilHostDeserializer(&r->inconsistency);
  b_xilHostDeserializer(&r->eq_overlap);
}

/*
 * Arguments    : real_T r[9]
 * Return Type  : void
 */
static void j_xilHostDeserializer(real_T r[9])
{
  xilReadData((uint8_T *)&r[0], (size_t)9, MEM_UNIT_DOUBLE_TYPE);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void pso_once(void)
{
  xilAlreadyInited = false;
}

/*
 * Arguments    : struct0_T *r
 * Return Type  : void
 */
static void xilHostDeserializer(struct0_T *r)
{
  b_xilHostDeserializer(&r->position);
  b_xilHostDeserializer(&r->cost);
}

/*
 * Arguments    : const real_T r[9]
 * Return Type  : void
 */
static void xilHostSerializer(const real_T r[9])
{
  xilWriteData((uint8_T *)&r[0], (size_t)9, MEM_UNIT_DOUBLE_TYPE);
}

/*
 * Arguments    : const real_T soc_in[9]
 *                real_T mp
 *                real_T w_time
 *                real_T w_inconsistency
 *                real_T w_eq_overlap
 *                struct0_T *global_best
 *                struct1_T eq_step_data[]
 *                int32_T eq_step_size[2]
 *                struct2_T *stio
 * Return Type  : void
 */
void psoXilWrapper(const real_T soc_in[9], real_T mp, real_T w_time,
                   real_T w_inconsistency, real_T w_eq_overlap,
                   struct0_T *global_best, struct1_T eq_step_data[],
                   int32_T eq_step_size[2], struct2_T *stio)
{
  /* Serialize function input argument soc_in. */
  xilHostSerializer(soc_in);
  /* Serialize function input argument mp. */
  b_xilHostSerializer(&mp);
  /* Serialize function input argument w_time. */
  b_xilHostSerializer(&w_time);
  /* Serialize function input argument w_inconsistency. */
  b_xilHostSerializer(&w_inconsistency);
  /* Serialize function input argument w_eq_overlap. */
  b_xilHostSerializer(&w_eq_overlap);
  /* Calling XIL to invoke target side. */
  xilEntryPointHost(1U);
  /* Deserialize function output argument global_best. */
  xilHostDeserializer(global_best);
  /* Deserialize function output argument eq_step. */
  c_xilHostDeserializer(eq_step_data, eq_step_size);
  /* Deserialize function output argument stio. */
  i_xilHostDeserializer(stio);
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
  soc_in = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "soc_in");
  mp = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "mp");
  w_time = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "w_time");
  w_inconsistency =
      c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "w_inconsistency");
  w_eq_overlap = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "w_eq_overlap");
  /* Calling XIL to setup. */
  xilPreEntryPointHost(1U);
  /* Invoke the wrapper function */
  psoXilWrapper(*soc_in, mp, w_time, w_inconsistency, w_eq_overlap,
                &global_best, eq_step.data, eq_step.size, &stio);
  /* Calling Xil to clean-up. */
  xilPostEntryPointHost(1U);
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
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    pso_once();
  }
  if (!xilAlreadyInited) {
    xilInitializeHost(&xil_terminate);
    xilAlreadyInited = true;
  }
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
 * Arguments    : void
 * Return Type  : void
 */
void xil_terminate(void)
{
  xilAlreadyInited = false;
  pso_terminate();
}

/*
 * File trailer for _coder_pso_api.c
 *
 * [EOF]
 */
