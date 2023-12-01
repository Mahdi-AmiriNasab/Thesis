/*
 * File: all.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

/* Include Files */
#include "all.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const boolean_T x[18]
 *                boolean_T y[9]
 * Return Type  : void
 */
void all(const boolean_T x[18], boolean_T y[9])
{
  int i;
  int i2;
  i2 = 2;
  for (i = 0; i < 9; i++) {
    int a;
    int ix;
    boolean_T exitg1;
    y[i] = true;
    a = i2;
    ix = i2 - 1;
    i2 += 2;
    exitg1 = false;
    while ((!exitg1) && (ix <= a)) {
      if (!x[ix - 1]) {
        y[i] = false;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }
}

/*
 * File trailer for all.c
 *
 * [EOF]
 */
