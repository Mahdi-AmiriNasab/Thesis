/*
 * File: find.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
 */

#ifndef FIND_H
#define FIND_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_eml_find(const boolean_T x[9], int i_data[], int *i_size);

void c_eml_find(const boolean_T x_data[], const int x_size[2], int i_data[],
                int i_size[2]);

void eml_find(const boolean_T x[9], int i_data[], int i_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for find.h
 *
 * [EOF]
 */
