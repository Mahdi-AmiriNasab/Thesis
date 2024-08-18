/*
 * File: xaxpy_SXGuMV6a.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "xaxpy_SXGuMV6a.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xaxpy_SXGuMV6a(int16_T n, real_T a, const real_T x[3], int16_T ix0, real_T
                    y[9], int16_T iy0)
{
  int16_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int16_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
