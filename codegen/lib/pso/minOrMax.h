/*
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include Files */
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

double d_minimum(const double x[9]);

double e_maximum(const double x[9]);

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
