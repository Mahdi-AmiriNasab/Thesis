/*
 * File: xdotc_60wSSEjg.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "xdotc_60wSSEjg.h"

/* Function for MATLAB Function: '<S5>/Correct' */
real_T xdotc_60wSSEjg(int16_T n, const real_T x[9], int16_T ix0, const real_T y
                      [9], int16_T iy0)
{
  real_T d;
  int16_T k;
  d = 0.0;
  if (n >= 1) {
    for (k = 0; k < n; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }

  return d;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
