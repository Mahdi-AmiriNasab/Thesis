/*
 * File: _coder_log_clustering_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

#ifndef _CODER_LOG_CLUSTERING_API_H
#define _CODER_LOG_CLUSTERING_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void log_clustering(real_T soc_in[9], real_T mp, real_T ep_arr, real_T *lg_time,
                    real_T *lg_inconsistency, real_T *lg_eq_overlap);

void log_clustering_api(const mxArray *const prhs[3], int32_T nlhs,
                        const mxArray *plhs[3]);

void log_clustering_atexit(void);

void log_clustering_initialize(void);

void log_clustering_terminate(void);

void log_clustering_xil_shutdown(void);

void log_clustering_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_log_clustering_api.h
 *
 * [EOF]
 */
