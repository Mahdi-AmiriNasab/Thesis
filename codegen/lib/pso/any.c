/*
 * File: any.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "any.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const bool x_data[]
 *                const int x_size[2]
 *                bool y_data[]
 * Return Type  : int
 */
int any(const bool x_data[], const int x_size[2], bool y_data[])
{
  int i1;
  int i2;
  int j;
  int loop_ub;
  int vstride;
  int y_size;
  y_size = x_size[0];
  loop_ub = x_size[0];
  vstride = x_size[0];
  i2 = x_size[0] << 3;
  i1 = 0;
  for (j = 0; j < loop_ub; j++) {
    int ix;
    bool exitg1;
    y_data[j] = false;
    i1++;
    i2++;
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && ((vstride > 0) && (ix <= i2))) {
      if (x_data[ix - 1]) {
        y_data[j] = true;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }
  return y_size;
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
