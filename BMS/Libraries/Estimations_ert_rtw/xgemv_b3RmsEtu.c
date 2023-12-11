/*
 * File: xgemv_b3RmsEtu.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "xgemv_b3RmsEtu.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xgemv_b3RmsEtu(int16_T m, int16_T n, const real_T A[9], int16_T ia0, const
                    real_T x[9], int16_T ix0, real_T y[3])
{
  real_T c;
  int16_T b;
  int16_T b_iy;
  int16_T d;
  int16_T ia;
  int16_T iac;
  int16_T ix;
  if ((m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n - 1) * 3 + ia0;
    for (iac = ia0; iac <= b; iac += 3) {
      ix = ix0;
      c = 0.0;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
