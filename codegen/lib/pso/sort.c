/*
 * File: sort.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
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
 * Return Type  : int
 */
int sort(double x_data[], const int *x_size, int idx_data[])
{
  static double xwork_data[100];
  static int iwork_data[100];
  int ib;
  int idx_size;
  int k;
  idx_size = *x_size;
  ib = *x_size;
  if (ib - 1 >= 0) {
    memset(&idx_data[0], 0, (unsigned int)ib * sizeof(int));
  }
  if (*x_size != 0) {
    double x4[4];
    int b_i1;
    int i;
    int i1;
    int i2;
    int i3;
    int i4;
    int n;
    int nNaNs;
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
    ib = *x_size;
    if (ib - 1 >= 0) {
      memset(&iwork_data[0], 0, (unsigned int)ib * sizeof(int));
      memset(&xwork_data[0], 0, (unsigned int)ib * sizeof(double));
    }
    nNaNs = 0;
    ib = 0;
    for (k = 0; k < n; k++) {
      if (rtIsNaN(x_data[k])) {
        i3 = (n - nNaNs) - 1;
        idx_data[i3] = k + 1;
        xwork_data[i3] = x_data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib - 1] = (signed char)(k + 1);
        x4[ib - 1] = x_data[k];
        if (ib == 4) {
          double d;
          double d1;
          ib = k - nNaNs;
          if (x4[0] >= x4[1]) {
            i1 = 1;
            i2 = 2;
          } else {
            i1 = 2;
            i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[i3 - 1];
          d1 = x4[i1 - 1];
          if (d1 >= d) {
            d1 = x4[i2 - 1];
            if (d1 >= d) {
              i = i1;
              b_i1 = i2;
              i1 = i3;
              i2 = i4;
            } else if (d1 >= x4[i4 - 1]) {
              i = i1;
              b_i1 = i3;
              i1 = i2;
              i2 = i4;
            } else {
              i = i1;
              b_i1 = i3;
              i1 = i4;
            }
          } else {
            d = x4[i4 - 1];
            if (d1 >= d) {
              if (x4[i2 - 1] >= d) {
                i = i3;
                b_i1 = i1;
                i1 = i2;
                i2 = i4;
              } else {
                i = i3;
                b_i1 = i1;
                i1 = i4;
              }
            } else {
              i = i3;
              b_i1 = i4;
            }
          }
          idx_data[ib - 3] = idx4[i - 1];
          idx_data[ib - 2] = idx4[b_i1 - 1];
          idx_data[ib - 1] = idx4[i1 - 1];
          idx_data[ib] = idx4[i2 - 1];
          x_data[ib - 3] = x4[i - 1];
          x_data[ib - 2] = x4[b_i1 - 1];
          x_data[ib - 1] = x4[i1 - 1];
          x_data[ib] = x4[i2 - 1];
          ib = 0;
        }
      }
    }
    i4 = *x_size - nNaNs;
    if (ib > 0) {
      signed char perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
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
      i = (unsigned char)ib;
      for (k = 0; k < i; k++) {
        i3 = (i4 - ib) + k;
        b_i1 = perm[k];
        idx_data[i3] = idx4[b_i1 - 1];
        x_data[i3] = x4[b_i1 - 1];
      }
    }
    i1 = nNaNs >> 1;
    for (k = 0; k < i1; k++) {
      ib = i4 + k;
      i2 = idx_data[ib];
      i3 = (n - k) - 1;
      idx_data[ib] = idx_data[i3];
      idx_data[i3] = i2;
      x_data[ib] = xwork_data[i3];
      x_data[i3] = xwork_data[ib];
    }
    if ((nNaNs & 1) != 0) {
      i = i4 + i1;
      x_data[i] = xwork_data[i];
    }
    if (i4 > 1) {
      i3 = i4 >> 2;
      i2 = 4;
      while (i3 > 1) {
        if ((i3 & 1) != 0) {
          i3--;
          ib = i2 * i3;
          i1 = i4 - ib;
          if (i1 > i2) {
            merge(idx_data, x_data, ib, i2, i1 - i2, iwork_data, xwork_data);
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
        i = (nNaNs + k) - 1;
        x_data[i] = x_data[k - 1];
        idx_data[i] = idx_data[k - 1];
      }
      memcpy(&x_data[0], &xwork_data[0], (unsigned int)nNaNs * sizeof(double));
      memcpy(&idx_data[0], &iwork_data[0], (unsigned int)nNaNs * sizeof(int));
    }
  }
  return idx_size;
}

/*
 * File trailer for sort.c
 *
 * [EOF]
 */
