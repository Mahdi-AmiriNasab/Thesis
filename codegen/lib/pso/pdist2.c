/*
 * File: pdist2.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "pdist2.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double Xin[9]
 *                const double Yin[9]
 *                double D[81]
 * Return Type  : void
 */
void pdist2(const double Xin[9], const double Yin[9], double D[81])
{
  int ii;
  int qq;
  bool logIndX[9];
  bool logIndY[9];
  for (qq = 0; qq < 81; qq++) {
    D[qq] = rtNaN;
  }
  for (qq = 0; qq < 9; qq++) {
    logIndX[qq] = true;
    if (rtIsNaN(Xin[qq])) {
      logIndX[qq] = false;
    }
    logIndY[qq] = true;
    if (rtIsNaN(Yin[qq])) {
      logIndY[qq] = false;
    }
  }
  for (ii = 0; ii < 9; ii++) {
    if (logIndY[ii]) {
      for (qq = 0; qq < 9; qq++) {
        if (logIndX[qq]) {
          double D_tmp;
          D_tmp = Xin[qq] - Yin[ii];
          D[qq + 9 * ii] = sqrt(D_tmp * D_tmp);
        }
      }
    }
  }
}

/*
 * File trailer for pdist2.c
 *
 * [EOF]
 */
