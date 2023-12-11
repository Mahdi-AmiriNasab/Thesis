/*
 * File: xaxpy_JqyUiIN6.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "xaxpy_JqyUiIN6.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xaxpy_JqyUiIN6(int16_T n, real_T a, const real_T x[9], int16_T ix0, real_T
                    y[3], int16_T iy0)
{
  int16_T ix;
  int16_T iy;
  int16_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
