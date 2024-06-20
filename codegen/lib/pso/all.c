/*
 * File: all.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "all.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const bool x[18]
 *                bool y[9]
 * Return Type  : void
 */
void all(const bool x[18], bool y[9])
{
  int i;
  int i2;
  i2 = 2;
  for (i = 0; i < 9; i++) {
    int a;
    int ix;
    bool exitg1;
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
