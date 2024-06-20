/*
 * File: _coder_pso_mex.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "_coder_pso_mex.h"
#include "_coder_pso_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&pso_atexit);
  /* Module initialization. */
  pso_initialize();
  /* Dispatch the entry-point. */
  unsafe_pso_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  pso_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1L,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[5]
 * Return Type  : void
 */
void unsafe_pso_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                            const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[5];
  const mxArray *outputs[3];
  int32_T i;
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5L) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5L, 12L, 5L,
                        4L, 3L, "pso");
  }
  if (nlhs > 3L) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3L, 4L, 3L,
                        "pso");
  }
  /* Call the function. */
  for (i = 0L; i < 5L; i++) {
    b_prhs[i] = prhs[i];
  }
  pso_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1L) {
    i1 = 1L;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0L], &outputs[0L]);
}

/*
 * File trailer for _coder_pso_mex.c
 *
 * [EOF]
 */
