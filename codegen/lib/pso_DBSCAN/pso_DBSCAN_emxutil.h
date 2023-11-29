/*
 * File: pso_DBSCAN_emxutil.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

#ifndef PSO_DBSCAN_EMXUTIL_H
#define PSO_DBSCAN_EMXUTIL_H

/* Include Files */
#include "pso_DBSCAN_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pso_DBSCAN_emxutil.h
 *
 * [EOF]
 */
