/*
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include Files */
#include "pso_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_maximum(const double x_data[], int x_size);

double b_minimum(const double x_data[], const int x_size[2], int *idx);

double c_maximum(const double x_data[], const int x_size[2], int *idx);

double c_minimum(const double x_data[], const int x_size[2]);

double d_maximum(const double x_data[], const int x_size[2]);

double d_minimum(const emxArray_real_T *x, int *idx);

double e_maximum(const emxArray_real_T *x, int *idx);

double e_minimum(const double x[9]);

double f_maximum(const double x[9]);

double maximum(const double x[9]);

double minimum(const double x_data[], int x_size);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for minOrMax.h
 *
 * [EOF]
 */
