/*
 * File: sort.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
 */

/* Include Files */
#include "sort.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double x_data[]
 *                const int *x_size
 *                int idx_data[]
 *                int *idx_size
 * Return Type  : void
 */
void sort(double x_data[], const int *x_size, int idx_data[], int *idx_size)
{
  static double xwork_data[100];
  static double x4[4];
  static int iwork_data[100];
  int ib;
  int k;
  signed char perm[4];
  ib = (signed char)*x_size;
  *idx_size = (signed char)*x_size;
  if (ib - 1 >= 0) {
    memset(&idx_data[0], 0, ib * sizeof(int));
  }
  if (*x_size != 0) {
    int i2;
    int i3;
    int i4;
    int n;
    int nNaNs;
    int quartetOffset;
    signed char idx4[4];
    n = *x_size;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    if (ib - 1 >= 0) {
      memset(&iwork_data[0], 0, ib * sizeof(int));
    }
    ib = *x_size;
    if (ib - 1 >= 0) {
      memset(&xwork_data[0], 0, ib * sizeof(double));
    }
    nNaNs = 0;
    ib = -1;
    for (k = 0; k < n; k++) {
      if (rtIsNaN(x_data[k])) {
        i3 = (n - nNaNs) - 1;
        idx_data[i3] = k + 1;
        xwork_data[i3] = x_data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = (signed char)(k + 1);
        x4[ib] = x_data[k];
        if (ib + 1 == 4) {
          double d;
          double d1;
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[ib - 1];
          d1 = x4[i3 - 1];
          if (d >= d1) {
            d = x4[i2 - 1];
            if (d >= d1) {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i2;
              perm[2] = (signed char)i3;
              perm[3] = (signed char)i4;
            } else if (d >= x4[i4 - 1]) {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i2;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)i2;
            }
          } else {
            d1 = x4[i4 - 1];
            if (d >= d1) {
              if (x4[i2 - 1] >= d1) {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)ib;
                perm[2] = (signed char)i2;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)ib;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)i2;
              }
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)i4;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i2;
            }
          }
          idx_data[quartetOffset - 3] = idx4[perm[0] - 1];
          idx_data[quartetOffset - 2] = idx4[perm[1] - 1];
          idx_data[quartetOffset - 1] = idx4[perm[2] - 1];
          idx_data[quartetOffset] = idx4[perm[3] - 1];
          x_data[quartetOffset - 3] = x4[perm[0] - 1];
          x_data[quartetOffset - 2] = x4[perm[1] - 1];
          x_data[quartetOffset - 1] = x4[perm[2] - 1];
          x_data[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }
    i4 = (n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
        if (x4[0] >= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      for (k = 0; k <= ib; k++) {
        i3 = perm[k] - 1;
        quartetOffset = (i4 - ib) + k;
        idx_data[quartetOffset] = idx4[i3];
        x_data[quartetOffset] = x4[i3];
      }
    }
    ib = (nNaNs >> 1) + 1;
    for (k = 0; k <= ib - 2; k++) {
      quartetOffset = (i4 + k) + 1;
      i2 = idx_data[quartetOffset];
      i3 = (n - k) - 1;
      idx_data[quartetOffset] = idx_data[i3];
      idx_data[i3] = i2;
      x_data[quartetOffset] = xwork_data[i3];
      x_data[i3] = xwork_data[quartetOffset];
    }
    if ((nNaNs & 1) != 0) {
      ib += i4;
      x_data[ib] = xwork_data[ib];
    }
    i4 = *x_size - nNaNs;
    if (i4 > 1) {
      i3 = i4 >> 2;
      i2 = 4;
      while (i3 > 1) {
        if ((i3 & 1) != 0) {
          i3--;
          ib = i2 * i3;
          quartetOffset = i4 - ib;
          if (quartetOffset > i2) {
            merge(idx_data, x_data, ib, i2, quartetOffset - i2, iwork_data,
                  xwork_data);
          }
        }
        ib = i2 << 1;
        i3 >>= 1;
        for (k = 0; k < i3; k++) {
          merge(idx_data, x_data, k * ib, i2, i2, iwork_data, xwork_data);
        }
        i2 = ib;
      }
      if (i4 > i2) {
        merge(idx_data, x_data, 0, i2, i4 - i2, iwork_data, xwork_data);
      }
    }
    if ((nNaNs > 0) && (i4 > 0)) {
      for (k = 0; k < nNaNs; k++) {
        ib = i4 + k;
        xwork_data[k] = x_data[ib];
        iwork_data[k] = idx_data[ib];
      }
      for (k = i4; k >= 1; k--) {
        ib = (nNaNs + k) - 1;
        x_data[ib] = x_data[k - 1];
        idx_data[ib] = idx_data[k - 1];
      }
      memcpy(&x_data[0], &xwork_data[0], nNaNs * sizeof(double));
      memcpy(&idx_data[0], &iwork_data[0], nNaNs * sizeof(int));
    }
  }
}

/*
 * File trailer for sort.c
 *
 * [EOF]
 */
