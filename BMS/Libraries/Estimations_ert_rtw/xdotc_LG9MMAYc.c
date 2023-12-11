/*
 * File: xdotc_LG9MMAYc.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "xdotc_LG9MMAYc.h"

/* Function for MATLAB Function: '<S5>/Correct' */
real_T xdotc_LG9MMAYc(int16_T n, const real_T x[9], int16_T ix0, const real_T y
                      [9], int16_T iy0)
{
  real_T d;
  int16_T ix;
  int16_T iy;
  int16_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
