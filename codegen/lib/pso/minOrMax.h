/*
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
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

void b_minimum(const double x_data[], const int x_size[2], double *ex,
               int *idx);

void c_maximum(const double x_data[], const int x_size[2], double *ex,
               int *idx);

double c_minimum(const double x_data[], const int x_size[2]);

double d_maximum(const double x_data[], const int x_size[2]);

void d_minimum(const emxArray_real_T *x, double *ex, int *idx);

void e_maximum(const emxArray_real_T *x, double *ex, int *idx);

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
