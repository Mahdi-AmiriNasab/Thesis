/*
 * File: isLocalExtrema.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
 */

/* Include Files */
#include "isLocalExtrema.h"
#include "diff.h"
#include "pso_emxutil.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void getAllLocalMax(const double A_data[], int A_size,
                           boolean_T maxVals_data[], int *maxVals_size,
                           boolean_T inflectionPts_data[],
                           int *inflectionPts_size);

/* Function Definitions */
/*
 * Arguments    : const double A_data[]
 *                int A_size
 *                boolean_T maxVals_data[]
 *                int *maxVals_size
 *                boolean_T inflectionPts_data[]
 *                int *inflectionPts_size
 * Return Type  : void
 */
static void getAllLocalMax(const double A_data[], int A_size,
                           boolean_T maxVals_data[], int *maxVals_size,
                           boolean_T inflectionPts_data[],
                           int *inflectionPts_size)
{
  static double b_data[99];
  static double b_y_data[99];
  static double d_tmp_data[99];
  static double s_data[99];
  static signed char b_tmp_data[99];
  static signed char b_x_data[99];
  static signed char c_tmp_data[99];
  static boolean_T b_uniquePts_data[100];
  static boolean_T nanMask_data[100];
  static boolean_T tmp_data[100];
  static boolean_T uniquePts_data[100];
  static boolean_T idx_data[99];
  static boolean_T x_data[99];
  emxArray_int8_T *b_y;
  double tmp;
  int i;
  int k;
  int low_ip1;
  int nz;
  int s_size;
  signed char *y_data;
  boolean_T exitg1;
  boolean_T y;
  diff(A_data, A_size, s_data, &s_size);
  for (k = 0; k < s_size; k++) {
    tmp = s_data[k];
    if (!rtIsNaN(tmp)) {
      if (tmp < 0.0) {
        tmp = -1.0;
      } else {
        tmp = (tmp > 0.0);
      }
    }
    s_data[k] = tmp;
  }
  for (i = 0; i < A_size; i++) {
    nanMask_data[i] = rtIsNaN(A_data[i]);
  }
  y = false;
  nz = 1;
  exitg1 = false;
  while ((!exitg1) && (nz <= A_size)) {
    if (nanMask_data[nz - 1]) {
      y = true;
      exitg1 = true;
    } else {
      nz++;
    }
  }
  if (y) {
    for (low_ip1 = 0; low_ip1 <= A_size - 2; low_ip1++) {
      if (nanMask_data[low_ip1]) {
        s_data[low_ip1] = -1.0;
      }
    }
    nz = A_size - 1;
    for (i = 0; i < nz; i++) {
      idx_data[i] = !nanMask_data[i];
    }
    for (low_ip1 = 0; low_ip1 < nz; low_ip1++) {
      if (idx_data[low_ip1] && nanMask_data[low_ip1 + 1]) {
        s_data[low_ip1] = 1.0;
      }
    }
  }
  y = true;
  nz = 1;
  exitg1 = false;
  while ((!exitg1) && (nz <= s_size)) {
    if (s_data[nz - 1] == 0.0) {
      y = false;
      exitg1 = true;
    } else {
      nz++;
    }
  }
  if (!y) {
    int low_i;
    if (s_size - 1 >= 0) {
      memcpy(&b_data[0], &s_data[0], s_size * sizeof(double));
    }
    for (i = 0; i < s_size; i++) {
      idx_data[i] = (s_data[i] != 0.0);
    }
    for (i = 0; i < s_size; i++) {
      x_data[i] = (s_data[i] != 0.0);
    }
    if (s_size == 0) {
      nz = 0;
    } else {
      nz = x_data[0];
      for (k = 2; k <= s_size; k++) {
        nz += x_data[k - 1];
      }
    }
    if (nz > 1) {
      int b_trueCount;
      int trueCount;
      emxInit_int8_T(&b_y);
      y_data = b_y->data;
      if (s_size < 1) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        i = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = s_size;
        emxEnsureCapacity_int8_T(b_y, i);
        y_data = b_y->data;
        low_ip1 = s_size - 1;
        for (i = 0; i <= low_ip1; i++) {
          y_data[i] = (signed char)(i + 1);
        }
      }
      nz = s_size - 1;
      trueCount = 0;
      low_i = 0;
      for (low_ip1 = 0; low_ip1 <= nz; low_ip1++) {
        if (s_data[low_ip1] != 0.0) {
          trueCount++;
          b_tmp_data[low_i] = (signed char)(low_ip1 + 1);
          low_i++;
        }
      }
      b_trueCount = 0;
      low_i = 0;
      for (low_ip1 = 0; low_ip1 <= nz; low_ip1++) {
        if (!(s_data[low_ip1] != 0.0)) {
          b_trueCount++;
          c_tmp_data[low_i] = (signed char)(low_ip1 + 1);
          low_i++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        b_x_data[i] = y_data[b_tmp_data[i] - 1];
      }
      for (i = 0; i < trueCount; i++) {
        b_y_data[i] = s_data[b_tmp_data[i] - 1];
      }
      if (b_trueCount - 1 >= 0) {
        memset(&d_tmp_data[0], 0, b_trueCount * sizeof(double));
      }
      if (b_trueCount != 0) {
        if (y_data[b_tmp_data[1] - 1] < y_data[b_tmp_data[0] - 1]) {
          i = trueCount >> 1;
          for (low_ip1 = 0; low_ip1 < i; low_ip1++) {
            nz = b_x_data[low_ip1];
            low_i = (trueCount - low_ip1) - 1;
            b_x_data[low_ip1] = b_x_data[low_i];
            b_x_data[low_i] = (signed char)nz;
          }
          if (trueCount > 1) {
            for (k = 0; k < i; k++) {
              tmp = b_y_data[k];
              nz = (trueCount - k) - 1;
              b_y_data[k] = b_y_data[nz];
              b_y_data[nz] = tmp;
            }
          }
        }
        for (k = 0; k < b_trueCount; k++) {
          i = y_data[c_tmp_data[k] - 1];
          if (i > b_x_data[trueCount - 1]) {
            d_tmp_data[k] = rtNaN;
          } else if (i < b_x_data[0]) {
            d_tmp_data[k] = b_y_data[0];
          } else {
            nz = trueCount;
            low_i = 1;
            low_ip1 = 2;
            while (nz > low_ip1) {
              int mid_i;
              mid_i = (low_i >> 1) + (nz >> 1);
              if (((low_i & 1) == 1) && ((nz & 1) == 1)) {
                mid_i++;
              }
              if (i >= b_x_data[mid_i - 1]) {
                low_i = mid_i;
                low_ip1 = mid_i + 1;
              } else {
                nz = mid_i;
              }
            }
            if (y_data[c_tmp_data[k] - 1] <= b_x_data[low_i - 1]) {
              low_i--;
            }
            d_tmp_data[k] = b_y_data[low_i];
          }
        }
      }
      emxFree_int8_T(&b_y);
      low_i = 0;
      for (low_ip1 = 0; low_ip1 < s_size; low_ip1++) {
        if (!(b_data[low_ip1] != 0.0)) {
          b_data[low_ip1] = d_tmp_data[low_i];
          low_i++;
        }
      }
    }
    tmp = 0.0;
    nz = 0;
    low_i = s_size;
    for (k = 0; k < s_size; k++) {
      if (idx_data[k]) {
        if (tmp == 0.0) {
          nz = k;
        }
        low_i = k + 1;
        tmp++;
      }
    }
    if (nz < 1) {
      low_ip1 = 0;
    } else {
      low_ip1 = nz;
    }
    for (i = 0; i < low_ip1; i++) {
      b_data[i] = s_data[nz];
    }
    if (low_i + 1 > s_size) {
      i = 0;
      nz = 0;
    } else {
      i = low_i;
      nz = s_size;
    }
    low_ip1 = nz - i;
    for (nz = 0; nz < low_ip1; nz++) {
      b_data[i + nz] = s_data[low_i - 1];
    }
    if (s_size - 1 >= 0) {
      memcpy(&s_data[0], &b_data[0], s_size * sizeof(double));
    }
  }
  *maxVals_size = A_size;
  if (A_size - 1 >= 0) {
    memset(&maxVals_data[0], 0, A_size * sizeof(boolean_T));
  }
  diff(s_data, s_size, b_data, &nz);
  for (i = 0; i < nz; i++) {
    maxVals_data[i + 1] = (b_data[i] < 0.0);
  }
  uniquePts_data[0] = true;
  for (i = 0; i <= A_size - 2; i++) {
    uniquePts_data[i + 1] = (A_data[i + 1] != A_data[i]);
  }
  for (i = 0; i < A_size; i++) {
    nanMask_data[i] = rtIsNaN(A_data[i]);
  }
  y = false;
  nz = 1;
  exitg1 = false;
  while ((!exitg1) && (nz <= A_size)) {
    if (nanMask_data[nz - 1]) {
      y = true;
      exitg1 = true;
    } else {
      nz++;
    }
  }
  if (y) {
    low_ip1 = A_size - 2;
    nz = A_size - 1;
    for (i = 0; i <= low_ip1; i++) {
      nanMask_data[i] = rtIsNaN(A_data[i + 1]);
    }
    for (i = 0; i < nz; i++) {
      tmp_data[i] = rtIsNaN(A_data[i]);
    }
    low_ip1 = A_size - 2;
    b_uniquePts_data[0] = uniquePts_data[0];
    for (i = 0; i <= low_ip1; i++) {
      b_uniquePts_data[i + 1] =
          (uniquePts_data[i + 1] && ((!nanMask_data[i]) || (!tmp_data[i])));
    }
    memcpy(&uniquePts_data[0], &b_uniquePts_data[0],
           A_size * sizeof(boolean_T));
  }
  if (s_size - 1 < 1) {
    low_ip1 = 1;
  } else {
    low_ip1 = s_size;
  }
  i = (s_size >= 2);
  *inflectionPts_size = low_ip1 + 1;
  inflectionPts_data[0] = true;
  for (nz = 0; nz <= low_ip1 - 2; nz++) {
    inflectionPts_data[nz + 1] =
        ((s_data[nz] != s_data[i + nz]) && uniquePts_data[nz + 1]);
  }
  inflectionPts_data[low_ip1] = true;
}

/*
 * Arguments    : double A_data[]
 *                int A_size
 *                double maxNumExt
 *                boolean_T maxVals_data[]
 *                int *maxVals_size
 *                double P_data[]
 *                int *P_size
 * Return Type  : void
 */
void doLocalMaxSearch(double A_data[], int A_size, double maxNumExt,
                      boolean_T maxVals_data[], int *maxVals_size,
                      double P_data[], int *P_size)
{
  static double leftRange_data[101];
  static double idxTemp_data[100];
  static double c_tmp_data[99];
  static int d_tmp_data[101];
  static int e_tmp_data[101];
  static int iidx_data[100];
  static signed char ranges_data[202];
  static signed char rightRange_data[102];
  static signed char b_tmp_data[100];
  static signed char extremaList_data[100];
  static boolean_T flatRegion_data[101];
  static boolean_T x_data[101];
  static boolean_T inflectionPts_data[100];
  static boolean_T isLocMax_data[100];
  static boolean_T tmp_data[100];
  static boolean_T locUniLeadMax_data[99];
  int b_i;
  int i;
  int i1;
  int k;
  int nz;
  int right;
  int trueCount;
  *P_size = A_size;
  if (A_size - 1 >= 0) {
    memset(&P_data[0], 0, A_size * sizeof(double));
  }
  if (A_size < 3) {
    *maxVals_size = A_size;
    if (A_size - 1 >= 0) {
      memset(&maxVals_data[0], 0, A_size * sizeof(boolean_T));
    }
  } else {
    double ctr;
    boolean_T colRngTF;
    boolean_T exitg4;
    for (i = 0; i < A_size; i++) {
      isLocMax_data[i] = rtIsInf(A_data[i]);
    }
    for (i = 0; i < A_size; i++) {
      tmp_data[i] = (A_data[i] > 0.0);
    }
    for (b_i = 0; b_i < A_size; b_i++) {
      if (isLocMax_data[b_i] && tmp_data[b_i]) {
        A_data[b_i] = rtNaN;
      }
    }
    getAllLocalMax(A_data, A_size, maxVals_data, maxVals_size,
                   inflectionPts_data, &nz);
    for (i = 0; i < *maxVals_size; i++) {
      maxVals_data[i] = (maxVals_data[i] || (isLocMax_data[i] && tmp_data[i]));
    }
    for (b_i = 0; b_i < A_size; b_i++) {
      if (isLocMax_data[b_i] && tmp_data[b_i]) {
        A_data[b_i] = rtInf;
      }
    }
    nz = maxVals_data[0];
    for (k = 2; k <= *maxVals_size; k++) {
      nz += maxVals_data[k - 1];
    }
    if (maxNumExt < nz) {
      nz = *maxVals_size - 1;
      trueCount = 0;
      right = 0;
      for (b_i = 0; b_i <= nz; b_i++) {
        if (maxVals_data[b_i] || inflectionPts_data[b_i]) {
          trueCount++;
          iidx_data[right] = b_i + 1;
          right++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        extremaList_data[i] = (signed char)iidx_data[i];
      }
      memcpy(&isLocMax_data[0], &maxVals_data[0], A_size * sizeof(boolean_T));
      for (b_i = 0; b_i < trueCount; b_i++) {
        i = iidx_data[b_i];
        if (isLocMax_data[i - 1]) {
          ctr = A_data[i - 1];
          if (rtIsInf(ctr) || rtIsNaN(ctr)) {
            P_data[i - 1] = rtInf;
          } else {
            double localMins_idx_0;
            double localMins_idx_0_tmp;
            double localMins_idx_1;
            localMins_idx_0_tmp = A_data[extremaList_data[b_i] - 1];
            localMins_idx_0 = localMins_idx_0_tmp;
            localMins_idx_1 = localMins_idx_0_tmp;
            nz = b_i - 1;
            right = b_i + 1;
            int exitg3;
            do {
              exitg3 = 0;
              if (nz + 1 > 0) {
                if (!isLocMax_data[iidx_data[nz] - 1]) {
                  localMins_idx_0 =
                      fmin(localMins_idx_0, A_data[extremaList_data[nz] - 1]);
                  nz--;
                } else if (A_data[iidx_data[nz] - 1] > ctr) {
                  exitg3 = 1;
                } else {
                  nz--;
                }
              } else {
                exitg3 = 2;
              }
            } while (exitg3 == 0);
            int exitg2;
            do {
              exitg2 = 0;
              if (right + 1 <= trueCount) {
                if (!isLocMax_data[iidx_data[right] - 1]) {
                  localMins_idx_1 = fmin(localMins_idx_1,
                                         A_data[extremaList_data[right] - 1]);
                  right++;
                } else if (A_data[iidx_data[right] - 1] > ctr) {
                  exitg2 = 1;
                } else {
                  right++;
                }
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);
            if ((localMins_idx_0 < localMins_idx_1) ||
                (rtIsNaN(localMins_idx_0) && (!rtIsNaN(localMins_idx_1)))) {
              localMins_idx_0 = localMins_idx_1;
            }
            i = iidx_data[b_i];
            P_data[i - 1] = localMins_idx_0_tmp - localMins_idx_0;
            maxVals_data[i - 1] = (P_data[i - 1] >= 0.0);
          }
        }
      }
    }
    nz = maxVals_data[0];
    for (k = 2; k <= *maxVals_size; k++) {
      nz += maxVals_data[k - 1];
    }
    if (maxNumExt < nz) {
      nz = *maxVals_size - 1;
      trueCount = 0;
      right = 0;
      for (b_i = 0; b_i <= nz; b_i++) {
        if (maxVals_data[b_i]) {
          trueCount++;
          b_tmp_data[right] = (signed char)(b_i + 1);
          right++;
        }
      }
      if (trueCount - 1 >= 0) {
        memcpy(&extremaList_data[0], &b_tmp_data[0],
               trueCount * sizeof(signed char));
      }
      for (i = 0; i < trueCount; i++) {
        idxTemp_data[i] = P_data[extremaList_data[i] - 1];
      }
      sort(idxTemp_data, &trueCount, iidx_data, &nz);
      for (i = 0; i < nz; i++) {
        idxTemp_data[i] = iidx_data[i];
      }
      if (maxNumExt + 1.0 > nz) {
        i = 0;
        nz = 0;
      } else {
        i = (int)(maxNumExt + 1.0) - 1;
      }
      right = nz - i;
      for (i1 = 0; i1 < right; i1++) {
        iidx_data[i1] = extremaList_data[(int)idxTemp_data[i + i1] - 1];
      }
      for (i = 0; i < right; i++) {
        maxVals_data[iidx_data[i] - 1] = false;
      }
    }
    colRngTF = false;
    nz = 1;
    exitg4 = false;
    while ((!exitg4) && (nz <= *maxVals_size)) {
      if (maxVals_data[nz - 1]) {
        colRngTF = true;
        exitg4 = true;
      } else {
        nz++;
      }
    }
    nz = 0;
    if (colRngTF) {
      nz = 1;
    }
    i = (nz >= 1);
    for (k = 0; k < i; k++) {
      int loop_ub;
      memcpy(&idxTemp_data[0], &A_data[0], A_size * sizeof(double));
      diff(idxTemp_data, A_size, c_tmp_data, &nz);
      for (i1 = 0; i1 < nz; i1++) {
        locUniLeadMax_data[i1] = (c_tmp_data[i1] != 0.0);
      }
      memset(&idxTemp_data[0], 0, A_size * sizeof(double));
      ctr = 1.0;
      for (right = 0; right < nz; right++) {
        if (locUniLeadMax_data[right]) {
          idxTemp_data[(int)ctr - 1] = (double)right + 1.0;
          ctr++;
        }
      }
      if (ctr - 1.0 < 1.0) {
        right = 0;
      } else {
        right = (int)(ctr - 1.0);
      }
      trueCount = right + 1;
      leftRange_data[0] = 1.0;
      for (i1 = 0; i1 < right; i1++) {
        leftRange_data[i1 + 1] = idxTemp_data[i1] + 1.0;
      }
      if (right + 1 < 2) {
        i1 = 0;
        b_i = 0;
      } else {
        i1 = 1;
        b_i = right + 1;
      }
      loop_ub = b_i - i1;
      nz = loop_ub + 1;
      for (b_i = 0; b_i < loop_ub; b_i++) {
        rightRange_data[b_i] = (signed char)((int)leftRange_data[i1 + b_i] - 1);
      }
      rightRange_data[loop_ub] = (signed char)A_size;
      for (i1 = 0; i1 < nz; i1++) {
        flatRegion_data[i1] = (rightRange_data[i1] > (int)leftRange_data[i1]);
      }
      colRngTF = false;
      nz = 1;
      exitg4 = false;
      while ((!exitg4) && (nz <= loop_ub + 1)) {
        if (flatRegion_data[nz - 1]) {
          colRngTF = true;
          exitg4 = true;
        } else {
          nz++;
        }
      }
      if (colRngTF) {
        for (i1 = 0; i1 < trueCount; i1++) {
          x_data[i1] = (maxVals_data[(int)leftRange_data[i1] - 1] &&
                        flatRegion_data[i1]);
        }
        colRngTF = false;
        nz = 1;
        exitg4 = false;
        while ((!exitg4) && (nz <= right + 1)) {
          if (x_data[nz - 1]) {
            colRngTF = true;
            exitg4 = true;
          } else {
            nz++;
          }
        }
        if (colRngTF) {
          nz = right;
          trueCount = 0;
          for (b_i = 0; b_i <= right; b_i++) {
            if (maxVals_data[(int)leftRange_data[b_i] - 1] &&
                flatRegion_data[b_i]) {
              trueCount++;
            }
          }
          right = 0;
          for (b_i = 0; b_i <= nz; b_i++) {
            if (maxVals_data[(int)leftRange_data[b_i] - 1] &&
                flatRegion_data[b_i]) {
              d_tmp_data[right] = b_i + 1;
              right++;
            }
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            ranges_data[i1] = (signed char)leftRange_data[d_tmp_data[i1] - 1];
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            ranges_data[i1 + trueCount] = rightRange_data[d_tmp_data[i1] - 1];
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            e_tmp_data[i1] = ranges_data[i1];
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            maxVals_data[e_tmp_data[i1] - 1] = false;
          }
          if (trueCount == 0) {
            trueCount = 0;
          } else {
            for (nz = 0; nz < trueCount; nz++) {
              leftRange_data[nz] = ranges_data[nz];
            }
            for (nz = 0; nz < trueCount; nz++) {
              leftRange_data[nz] += (double)ranges_data[trueCount + nz];
            }
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            leftRange_data[i1] /= 2.0;
          }
          for (nz = 0; nz < trueCount; nz++) {
            leftRange_data[nz] = floor(leftRange_data[nz]);
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            e_tmp_data[i1] = (int)leftRange_data[i1];
          }
          for (i1 = 0; i1 < trueCount; i1++) {
            maxVals_data[e_tmp_data[i1] - 1] = true;
          }
        }
      }
    }
  }
}

/*
 * File trailer for isLocalExtrema.c
 *
 * [EOF]
 */
