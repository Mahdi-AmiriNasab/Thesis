/*
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
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
double b_maximum(const double x_data[], const int x_size[2], int *idx);

double b_minimum(const double x_data[], const int x_size[2], int *idx);

double maximum(const double x_data[], int x_size);

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
