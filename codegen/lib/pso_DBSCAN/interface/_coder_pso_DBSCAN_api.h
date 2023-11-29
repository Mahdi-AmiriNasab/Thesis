/*
 * File: _coder_pso_DBSCAN_api.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

#ifndef _CODER_PSO_DBSCAN_API_H
#define _CODER_PSO_DBSCAN_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef enum_e_noise_stat
#define enum_e_noise_stat
enum e_noise_stat
{
  noise_not_found = 0, /* Default value */
  noise_found,
  noise_single_found
};
#endif /* enum_e_noise_stat */
#ifndef typedef_e_noise_stat
#define typedef_e_noise_stat
typedef enum e_noise_stat e_noise_stat;
#endif /* typedef_e_noise_stat */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T cell_cnt;
  real_T average;
  real_T dbscan_res[9];
  real_T clt_res_cell[81];
  real_T clt_res_soc[81];
  real_T clt_res_soc_av[18];
  real_T clt_max_count;
  real_T clt_noise_soc[18];
  real_T clt_soc[18];
  real_T noise_max[2];
  real_T noise_min[2];
  real_T single_noise[2];
  e_noise_stat noise_status;
} struct0_T;
#endif /* typedef_struct0_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void pso_DBSCAN(real_T socs[9], real_T minPts, real_T eps, struct0_T *cluster);

void pso_DBSCAN_api(const mxArray *const prhs[3], const mxArray **plhs);

void pso_DBSCAN_atexit(void);

void pso_DBSCAN_initialize(void);

void pso_DBSCAN_terminate(void);

void pso_DBSCAN_xil_shutdown(void);

void pso_DBSCAN_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_pso_DBSCAN_api.h
 *
 * [EOF]
 */
