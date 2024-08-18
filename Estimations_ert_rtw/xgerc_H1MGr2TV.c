/*
 * File: xgerc_H1MGr2TV.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "xgerc_H1MGr2TV.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void xgerc_H1MGr2TV(int16_T m, int16_T n, real_T alpha1, int16_T ix0, const
                    real_T y[3], real_T A[18], int16_T ia0)
{
  int16_T ijA;
  int16_T j;
  if (!(alpha1 == 0.0)) {
    int16_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int16_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 6;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
