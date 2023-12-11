/*
 * File: xgerc_aZmBAV8G.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "xgerc_aZmBAV8G.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void xgerc_aZmBAV8G(int16_T m, int16_T n, real_T alpha1, int16_T ix0, const
                    real_T y[3], real_T A[18], int16_T ia0)
{
  real_T temp;
  int16_T b;
  int16_T ijA;
  int16_T ix;
  int16_T j;
  int16_T jA;
  int16_T jy;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 6;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
