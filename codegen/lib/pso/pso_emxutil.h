/*
 * File: pso_emxutil.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
 */

#ifndef PSO_EMXUTIL_H
#define PSO_EMXUTIL_H

/* Include Files */
#include "pso_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

void emxFree_int8_T(emxArray_int8_T **pEmxArray);

void emxFree_real_T(emxArray_real_T **pEmxArray);

void emxInit_int8_T(emxArray_int8_T **pEmxArray);

void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pso_emxutil.h
 *
 * [EOF]
 */
