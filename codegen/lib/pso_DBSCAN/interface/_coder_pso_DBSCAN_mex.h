/*
 * File: _coder_pso_DBSCAN_mex.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

#ifndef _CODER_PSO_DBSCAN_MEX_H
#define _CODER_PSO_DBSCAN_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_pso_DBSCAN_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                   const mxArray *prhs[3]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_pso_DBSCAN_mex.h
 *
 * [EOF]
 */
