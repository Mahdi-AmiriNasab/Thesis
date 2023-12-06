/*
 * File: sortrows.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "sortrows.h"
#include "rt_nonfinite.h"
#include "sortrowsLE.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : double y_data[]
 *                const int y_size[2]
 * Return Type  : void
 */
void b_sortrows(double y_data[], const int y_size[2])
{
  double ycol_data[9];
  double v1;
  double v2;
  int idx_data[9];
  int iwork_data[9];
  int b_i;
  int i;
  int i2;
  int j;
  int k;
  int n;
  int pEnd;
  int qEnd;
  n = y_size[0] + 1;
  i2 = y_size[0];
  if (i2 - 1 >= 0) {
    memset(&idx_data[0], 0, i2 * sizeof(int));
  }
  i = y_size[0] - 1;
  for (k = 1; k <= i; k += 2) {
    i2 = k + y_size[0];
    v1 = y_data[i2 - 1];
    v2 = y_data[i2];
    if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2)) || (v1 <= v2) ||
        rtIsNaN(v2)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((y_size[0] & 1) != 0) {
    idx_data[y_size[0] - 1] = y_size[0];
  }
  b_i = 2;
  while (b_i < n - 1) {
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n) {
        qEnd = n;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int v1_tmp_tmp;
        int v2_tmp_tmp;
        v1_tmp_tmp = idx_data[p - 1];
        v1 = y_data[(v1_tmp_tmp + y_size[0]) - 1];
        v2_tmp_tmp = idx_data[q - 1];
        v2 = y_data[(v2_tmp_tmp + y_size[0]) - 1];
        if ((v1 == v2) || (rtIsNaN(v1) && rtIsNaN(v2)) || (v1 <= v2) ||
            rtIsNaN(v2)) {
          iwork_data[k] = v1_tmp_tmp;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = v2_tmp_tmp;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  for (j = 0; j < 2; j++) {
    for (b_i = 0; b_i <= i; b_i++) {
      ycol_data[b_i] = y_data[(idx_data[b_i] + y_size[0] * j) - 1];
    }
    for (b_i = 0; b_i <= i; b_i++) {
      y_data[b_i + y_size[0] * j] = ycol_data[b_i];
    }
  }
}

/*
 * Arguments    : double y[18]
 * Return Type  : void
 */
void c_sortrows(double y[18])
{
  double ycol[9];
  int idx[9];
  int iwork[9];
  int i;
  int j;
  int k;
  int pEnd;
  int qEnd;
  if (sortrowsLE(y, 2, 1, 2)) {
    idx[0] = 1;
    idx[1] = 2;
  } else {
    idx[0] = 2;
    idx[1] = 1;
  }
  if (sortrowsLE(y, 2, 3, 4)) {
    idx[2] = 3;
    idx[3] = 4;
  } else {
    idx[2] = 4;
    idx[3] = 3;
  }
  if (sortrowsLE(y, 2, 5, 6)) {
    idx[4] = 5;
    idx[5] = 6;
  } else {
    idx[4] = 6;
    idx[5] = 5;
  }
  if (sortrowsLE(y, 2, 7, 8)) {
    idx[6] = 7;
    idx[7] = 8;
  } else {
    idx[6] = 8;
    idx[7] = 7;
  }
  idx[8] = 9;
  i = 2;
  while (i < 9) {
    int i2;
    i2 = i << 1;
    j = 1;
    for (pEnd = i + 1; pEnd < 10; pEnd = qEnd + i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 10) {
        qEnd = 10;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int b_i;
        int i1;
        b_i = idx[q - 1];
        i1 = idx[p - 1];
        if (sortrowsLE(y, 2, i1, b_i)) {
          iwork[k] = i1;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = b_i;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork[k] = idx[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }
      j = qEnd;
    }
    i = i2;
  }
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 9; i++) {
      ycol[i] = y[(idx[i] + 9 * j) - 1];
    }
    memcpy(&y[j * 9], &ycol[0], 9U * sizeof(double));
  }
}

/*
 * Arguments    : double y[18]
 * Return Type  : void
 */
void sortrows(double y[18])
{
  double ycol[9];
  int idx[9];
  int iwork[9];
  int i;
  int j;
  int k;
  int pEnd;
  int qEnd;
  if (sortrowsLE(y, -1, 1, 2)) {
    idx[0] = 1;
    idx[1] = 2;
  } else {
    idx[0] = 2;
    idx[1] = 1;
  }
  if (sortrowsLE(y, -1, 3, 4)) {
    idx[2] = 3;
    idx[3] = 4;
  } else {
    idx[2] = 4;
    idx[3] = 3;
  }
  if (sortrowsLE(y, -1, 5, 6)) {
    idx[4] = 5;
    idx[5] = 6;
  } else {
    idx[4] = 6;
    idx[5] = 5;
  }
  if (sortrowsLE(y, -1, 7, 8)) {
    idx[6] = 7;
    idx[7] = 8;
  } else {
    idx[6] = 8;
    idx[7] = 7;
  }
  idx[8] = 9;
  i = 2;
  while (i < 9) {
    int i2;
    i2 = i << 1;
    j = 1;
    for (pEnd = i + 1; pEnd < 10; pEnd = qEnd + i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 10) {
        qEnd = 10;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int b_i;
        int i1;
        b_i = idx[q - 1];
        i1 = idx[p - 1];
        if (sortrowsLE(y, -1, i1, b_i)) {
          iwork[k] = i1;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = b_i;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork[k] = idx[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }
      j = qEnd;
    }
    i = i2;
  }
  for (j = 0; j < 2; j++) {
    for (i = 0; i < 9; i++) {
      ycol[i] = y[(idx[i] + 9 * j) - 1];
    }
    memcpy(&y[j * 9], &ycol[0], 9U * sizeof(double));
  }
}

/*
 * File trailer for sortrows.c
 *
 * [EOF]
 */
