/*
 * File: pso.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

#ifndef PSO_H
#define PSO_H

/* Include Files */
#include "pso_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void pso(const double soc_in[9], double mp, double w_time,
                double w_inconsistency, double w_eq_overlap,
                struct0_T *global_best, struct1_T *eq_step, struct2_T *stio);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pso.h
 *
 * [EOF]
 */
