/*
 * File: _coder_pso_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

#ifndef _CODER_PSO_API_H
#define _CODER_PSO_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T position;
  real_T cost;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T soc[9];
  real_T time;
  real_T inconsistency;
  real_T eq_overlap;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef struct_emxArray_real_T_1x2
#define struct_emxArray_real_T_1x2
struct emxArray_real_T_1x2 {
  real_T data[2];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_1x2 */
#ifndef typedef_emxArray_real_T_1x2
#define typedef_emxArray_real_T_1x2
typedef struct emxArray_real_T_1x2 emxArray_real_T_1x2;
#endif /* typedef_emxArray_real_T_1x2 */

#ifndef struct_emxArray_real_T_1
#define struct_emxArray_real_T_1
struct emxArray_real_T_1 {
  real_T data[1];
  int32_T size[1];
};
#endif /* struct_emxArray_real_T_1 */
#ifndef typedef_emxArray_real_T_1
#define typedef_emxArray_real_T_1
typedef struct emxArray_real_T_1 emxArray_real_T_1;
#endif /* typedef_emxArray_real_T_1 */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  emxArray_real_T_1x2 source_queue_cells;
  emxArray_real_T_1x2 destination_queue_cells;
  emxArray_real_T_1 source_target_soc_av;
  emxArray_real_T_1 destination_target_soc_av;
} struct1_T;
#endif /* typedef_struct1_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void pso(real_T soc_in[9], real_T mp, real_T w_time, real_T w_inconsistency,
         real_T w_eq_overlap, struct0_T *global_best, struct1_T eq_step_data[],
         int32_T eq_step_size[2], struct2_T *stio);

void pso_api(const mxArray *const prhs[5], int32_T nlhs,
             const mxArray *plhs[3]);

void pso_atexit(void);

void pso_initialize(void);

void pso_terminate(void);

void pso_xil_shutdown(void);

void pso_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_pso_api.h
 *
 * [EOF]
 */
