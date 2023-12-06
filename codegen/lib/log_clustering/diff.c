/*
 * File: diff.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

/* Include Files */
#include "diff.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const double x_data[]
 *                int x_size
 *                double y_data[]
 *                int *y_size
 * Return Type  : void
 */
void diff(const double x_data[], int x_size, double y_data[], int *y_size)
{
  int u0;
  if (x_size == 0) {
    *y_size = 0;
  } else {
    u0 = x_size - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      *y_size = 0;
    } else {
      *y_size = x_size - 1;
      if (x_size - 1 != 0) {
        double work_data;
        work_data = x_data[0];
        for (u0 = 2; u0 <= x_size; u0++) {
          double tmp2;
          tmp2 = work_data;
          work_data = x_data[u0 - 1];
          y_data[u0 - 2] = work_data - tmp2;
        }
      }
    }
  }
}

/*
 * File trailer for diff.c
 *
 * [EOF]
 */
