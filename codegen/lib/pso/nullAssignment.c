/*
 * File: nullAssignment.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "nullAssignment.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double x_data[]
 *                int x_size[2]
 *                const bool idx_data[]
 *                int idx_size
 * Return Type  : void
 */
void nullAssignment(double x_data[], int x_size[2], const bool idx_data[],
                    int idx_size)
{
  int i;
  int j;
  int k;
  int nrows;
  int nrowx;
  nrowx = x_size[0];
  nrows = 0;
  for (k = 0; k < idx_size; k++) {
    nrows += idx_data[k];
  }
  nrows = x_size[0] - nrows;
  i = 0;
  for (k = 0; k < nrowx; k++) {
    if (!idx_data[k]) {
      for (j = 0; j < 9; j++) {
        x_data[i + x_size[0] * j] = x_data[k + x_size[0] * j];
      }
      i++;
    }
  }
  if (nrows < 1) {
    nrows = 0;
  }
  for (i = 0; i < 9; i++) {
    for (nrowx = 0; nrowx < nrows; nrowx++) {
      x_data[nrowx + nrows * i] = x_data[nrowx + x_size[0] * i];
    }
  }
  x_size[0] = nrows;
  x_size[1] = 9;
}

/*
 * File trailer for nullAssignment.c
 *
 * [EOF]
 */
