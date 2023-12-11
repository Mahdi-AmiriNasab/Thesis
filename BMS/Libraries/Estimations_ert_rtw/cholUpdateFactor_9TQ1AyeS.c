/*
 * File: cholUpdateFactor_9TQ1AyeS.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rotate_h3nP3JUD.h"
#include "cholUpdateFactor_9TQ1AyeS.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void cholUpdateFactor_9TQ1AyeS(real_T *S, real_T U)
{
  real_T R;
  real_T alpha;
  real_T c;
  real_T nrmx;
  real_T temp;
  int16_T p;
  R = *S;
  p = 0;
  if (*S == 0.0) {
    p = 2;
  } else {
    temp = U / *S;
    nrmx = fabs(temp);
    if (nrmx >= 1.0) {
      p = 1;
    } else {
      rotate_h3nP3JUD(sqrt(1.0 - nrmx * nrmx), temp, &R, &c, &alpha);
      R = R * *S - c * 0.0;
    }
  }

  *S = R;
  if (p != 0) {
    nrmx = R * R - U * U;
    if ((!rtIsInf(nrmx)) && (!rtIsNaN(nrmx))) {
      temp = 1.0;
      if (nrmx != 0.0) {
        nrmx = fabs(nrmx);
      }

      if (nrmx < 0.0) {
        nrmx = -nrmx;
        temp = -1.0;
      }
    } else {
      nrmx = (rtNaN);
      temp = (rtNaN);
    }

    *S = temp * sqrt(nrmx);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
