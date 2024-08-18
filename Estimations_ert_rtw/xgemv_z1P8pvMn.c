/*
 * File: xgemv_z1P8pvMn.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "xgemv_z1P8pvMn.h"
#include <string.h>
#include "div_nde_s16_floor.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void xgemv_z1P8pvMn(int16_T m, int16_T n, const real_T A[9], int16_T ia0, const
                    real_T x[9], int16_T ix0, real_T y[3])
{
  int16_T b_iy;
  int16_T ia;
  if ((m != 0) && (n != 0)) {
    int16_T b;
    if (n - 1 >= 0) {
      memset(&y[0], 0, (uint16_T)n * sizeof(real_T));
    }

    b = (n - 1) * 3 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 3) {
      real_T c;
      int16_T d;
      c = 0.0;
      d = b_iy + m;
      for (ia = b_iy; ia < d; ia++) {
        c += x[((ix0 + ia) - b_iy) - 1] * A[ia - 1];
      }

      ia = div_nde_s16_floor(b_iy - ia0, 3);
      y[ia] += c;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
