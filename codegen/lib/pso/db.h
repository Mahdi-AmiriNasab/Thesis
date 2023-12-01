/*
 * File: db.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

#ifndef DB_H
#define DB_H

/* Include Files */
#include "pso_internal_types.h"
#include "pso_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ExpandCluster(const d_captured_var *D, const captured_var *epsilon,
                   b_captured_var *IDX, c_captured_var *visited,
                   const captured_var *MinPts, double i,
                   emxArray_real_T *Neighbors, double C);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for db.h
 *
 * [EOF]
 */
