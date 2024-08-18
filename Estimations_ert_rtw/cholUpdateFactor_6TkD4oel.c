/*
 * File: cholUpdateFactor_6TkD4oel.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "cholUpdateFactor_6TkD4oel.h"
#include <math.h>
#include "rotate_07DDyFSo.h"
#include "rt_nonfinite.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void cholUpdateFactor_6TkD4oel(real_T *S, real_T U)
{
  real_T R;
  real_T alpha;
  real_T c;
  real_T nrmx;
  real_T x;
  int16_T Vf;
  R = *S;
  Vf = 0;
  if (*S == 0.0) {
    Vf = 2;
  } else {
    x = U / *S;
    nrmx = fabs(x);
    if (nrmx >= 1.0) {
      Vf = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), x, &R, &c, &alpha);
      R = R * *S - c * 0.0;
    }
  }

  *S = R;
  if (Vf != 0) {
    nrmx = R * R - U * U;
    if ((!rtIsInf(nrmx)) && (!rtIsNaN(nrmx))) {
      Vf = 1;
      if (nrmx != 0.0) {
        nrmx = fabs(nrmx);
      }

      if (nrmx < 0.0) {
        nrmx = -nrmx;
        Vf = -1;
      }

      x = Vf;
    } else {
      nrmx = (rtNaN);
      x = (rtNaN);
    }

    *S = x * sqrt(nrmx);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
