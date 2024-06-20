/*
 * File: isLocalExtrema.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
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
static int getAllLocalMax(const double A_data[], int A_size,
                          boolean_T maxVals_data[],
                          boolean_T inflectionPts_data[],
                          int *inflectionPts_size);

/* Function Definitions */
/*
 * Arguments    : const double A_data[]
 *                int A_size
 *                boolean_T maxVals_data[]
 *                boolean_T inflectionPts_data[]
 *                int *inflectionPts_size
 * Return Type  : int
 */
static int getAllLocalMax(const double A_data[], int A_size,
                          boolean_T maxVals_data[],
                          boolean_T inflectionPts_data[],
                          int *inflectionPts_size)
{
  static double Vq_data[99];
  static double b_data[99];
  static double b_y_data[99];
  static double s_data[99];
  static signed char b_tmp_data[99];
  static signed char c_tmp_data[99];
  static signed char x_data[99];
  static boolean_T b_uniquePts_data[100];
  static boolean_T uniquePts_data[100];
  static boolean_T tmp_data[99];
  emxArray_int8_T *b_y;
  double tmp;
  int b_trueCount;
  int i;
  int k;
  int low_i;
  int low_ip1;
  int maxVals_size;
  int mid_i;
  int nz;
  int s_size;
  int trueCount;
  signed char i1;
  signed char *y_data;
  boolean_T exitg1;
  boolean_T y;
  s_size = diff(A_data, A_size, s_data);
  for (k = 0; k < s_size; k++) {
    if (rtIsNaN(s_data[k])) {
      s_data[k] = rtNaN;
    } else if (s_data[k] < 0.0) {
      s_data[k] = -1.0;
    } else {
      s_data[k] = (s_data[k] > 0.0);
    }
  }
  y = false;
  nz = 1;
  exitg1 = false;
  while ((!exitg1) && (nz <= A_size)) {
    if (rtIsNaN(A_data[nz - 1])) {
      y = true;
      exitg1 = true;
    } else {
      nz++;
    }
  }
  if (y) {
    nz = A_size - 1;
    for (i = 0; i < nz; i++) {
      tmp_data[i] = rtIsNaN(A_data[i]);
    }
    low_ip1 = A_size - 2;
    for (mid_i = 0; mid_i <= low_ip1; mid_i++) {
      if (tmp_data[mid_i]) {
        s_data[mid_i] = -1.0;
      }
    }
    for (i = 0; i < nz; i++) {
      tmp_data[i] = ((!rtIsNaN(A_data[i])) && rtIsNaN(A_data[i + 1]));
    }
    for (mid_i = 0; mid_i <= low_ip1; mid_i++) {
      if (tmp_data[mid_i]) {
        s_data[mid_i] = 1.0;
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
    if (s_size - 1 >= 0) {
      memcpy(&b_data[0], &s_data[0], (unsigned int)s_size * sizeof(double));
    }
    if (s_size == 0) {
      nz = 0;
    } else {
      nz = (s_data[0] != 0.0);
      for (k = 2; k <= s_size; k++) {
        nz += (s_data[k - 1] != 0.0);
      }
    }
    if (nz > 1) {
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
        nz = s_size - 1;
        for (i = 0; i <= nz; i++) {
          y_data[i] = (signed char)(i + 1);
        }
      }
      low_ip1 = s_size - 1;
      trueCount = 0;
      nz = 0;
      b_trueCount = 0;
      low_i = 0;
      for (mid_i = 0; mid_i <= low_ip1; mid_i++) {
        tmp = s_data[mid_i];
        if (!(tmp != 0.0)) {
          trueCount++;
          b_tmp_data[nz] = (signed char)mid_i;
          nz++;
        }
        if (tmp != 0.0) {
          b_trueCount++;
          c_tmp_data[low_i] = (signed char)mid_i;
          low_i++;
        }
      }
      for (i = 0; i < b_trueCount; i++) {
        i1 = c_tmp_data[i];
        x_data[i] = y_data[i1];
        b_y_data[i] = s_data[i1];
      }
      if (trueCount - 1 >= 0) {
        memset(&Vq_data[0], 0, (unsigned int)trueCount * sizeof(double));
      }
      if (trueCount != 0) {
        if (y_data[c_tmp_data[1]] < y_data[c_tmp_data[0]]) {
          i = b_trueCount >> 1;
          for (low_ip1 = 0; low_ip1 < i; low_ip1++) {
            nz = x_data[low_ip1];
            low_i = (b_trueCount - low_ip1) - 1;
            x_data[low_ip1] = x_data[low_i];
            x_data[low_i] = (signed char)nz;
          }
          if (b_trueCount > 1) {
            for (k = 0; k < i; k++) {
              tmp = b_y_data[k];
              nz = (b_trueCount - k) - 1;
              b_y_data[k] = b_y_data[nz];
              b_y_data[nz] = tmp;
            }
          }
        }
        for (k = 0; k < trueCount; k++) {
          i = y_data[b_tmp_data[k]];
          if (i > x_data[b_trueCount - 1]) {
            Vq_data[k] = rtNaN;
          } else if (i < x_data[0]) {
            Vq_data[k] = b_y_data[0];
          } else {
            nz = b_trueCount;
            low_i = 1;
            low_ip1 = 2;
            while (nz > low_ip1) {
              mid_i = (low_i >> 1) + (nz >> 1);
              if (((low_i & 1) == 1) && ((nz & 1) == 1)) {
                mid_i++;
              }
              if (i >= x_data[mid_i - 1]) {
                low_i = mid_i;
                low_ip1 = mid_i + 1;
              } else {
                nz = mid_i;
              }
            }
            if (i <= x_data[low_i - 1]) {
              low_i--;
            }
            Vq_data[k] = b_y_data[low_i];
          }
        }
      }
      emxFree_int8_T(&b_y);
      for (i = 0; i < trueCount; i++) {
        b_data[b_tmp_data[i]] = Vq_data[i];
      }
    }
    nz = 0;
    low_i = 0;
    low_ip1 = s_size;
    for (k = 0; k < s_size; k++) {
      if (s_data[k] != 0.0) {
        if (nz == 0) {
          low_i = k;
        }
        low_ip1 = k + 1;
        nz++;
      }
    }
    for (i = 0; i < low_i; i++) {
      b_data[i] = s_data[low_i];
    }
    if (low_ip1 + 1 > s_size) {
      i = 0;
      low_i = 0;
    } else {
      i = low_ip1;
      low_i = s_size;
    }
    nz = low_i - i;
    for (low_i = 0; low_i < nz; low_i++) {
      b_data[i + low_i] = s_data[low_ip1 - 1];
    }
    if (s_size - 1 >= 0) {
      memcpy(&s_data[0], &b_data[0], (unsigned int)s_size * sizeof(double));
    }
  }
  maxVals_size = A_size;
  if (A_size - 1 >= 0) {
    memset(&maxVals_data[0], 0, (unsigned int)A_size * sizeof(boolean_T));
  }
  diff(s_data, s_size, b_data);
  nz = A_size - 2;
  for (i = 0; i < nz; i++) {
    maxVals_data[i + 1] = (b_data[i] < 0.0);
  }
  uniquePts_data[0] = true;
  for (i = 0; i <= A_size - 2; i++) {
    uniquePts_data[i + 1] = (A_data[i + 1] != A_data[i]);
  }
  y = false;
  nz = 1;
  exitg1 = false;
  while ((!exitg1) && (nz <= A_size)) {
    if (rtIsNaN(A_data[nz - 1])) {
      y = true;
      exitg1 = true;
    } else {
      nz++;
    }
  }
  if (y) {
    b_uniquePts_data[0] = uniquePts_data[0];
    for (i = 0; i <= A_size - 2; i++) {
      b_uniquePts_data[i + 1] =
          (uniquePts_data[i + 1] &&
           ((!rtIsNaN(A_data[i + 1])) || (!rtIsNaN(A_data[i]))));
    }
    if (A_size - 1 >= 0) {
      memcpy(&uniquePts_data[0], &b_uniquePts_data[0],
             (unsigned int)A_size * sizeof(boolean_T));
    }
  }
  if (s_size - 1 < 1) {
    nz = 1;
  } else {
    nz = s_size;
  }
  i = (s_size >= 2);
  *inflectionPts_size = nz + 1;
  inflectionPts_data[0] = true;
  for (low_i = 0; low_i <= nz - 2; low_i++) {
    inflectionPts_data[low_i + 1] =
        ((s_data[low_i] != s_data[i + low_i]) && uniquePts_data[low_i + 1]);
  }
  inflectionPts_data[nz] = true;
  return maxVals_size;
}

/*
 * Arguments    : double A_data[]
 *                int A_size
 *                double maxNumExt
 *                boolean_T maxVals_data[]
 *                double P_data[]
 *                int *P_size
 * Return Type  : int
 */
int doLocalMaxSearch(double A_data[], int A_size, double maxNumExt,
                     boolean_T maxVals_data[], double P_data[], int *P_size)
{
  static double leftRange_data[101];
  static double idxTemp_data[100];
  static double c_tmp_data[99];
  static int iidx_data[100];
  static signed char ranges_data[202];
  static signed char rightRange_data[102];
  static signed char d_tmp_data[101];
  static signed char b_tmp_data[100];
  static signed char extremaList_data[100];
  static signed char tmp_data[100];
  static boolean_T flatRegion_data[101];
  static boolean_T infMaxVals_data[100];
  static boolean_T inflectionPts_data[100];
  static boolean_T locUniLeadMax_data[99];
  double ctr;
  double localMaxValue_tmp;
  double localMins_idx_0;
  double localMins_idx_0_tmp;
  double localMins_idx_1;
  int b_i;
  int exitg2;
  int exitg3;
  int i;
  int i2;
  int k;
  int maxVals_size;
  int nz;
  int right;
  int trueCount;
  signed char i1;
  boolean_T colRngTF;
  boolean_T exitg4;
  *P_size = A_size;
  if (A_size - 1 >= 0) {
    memset(&P_data[0], 0, (unsigned int)A_size * sizeof(double));
  }
  if (A_size < 3) {
    maxVals_size = A_size;
    if (A_size - 1 >= 0) {
      memset(&maxVals_data[0], 0, (unsigned int)A_size * sizeof(boolean_T));
    }
  } else {
    for (i = 0; i < A_size; i++) {
      ctr = A_data[i];
      infMaxVals_data[i] = (rtIsInf(ctr) && (ctr > 0.0));
    }
    nz = A_size - 1;
    trueCount = 0;
    right = 0;
    for (b_i = 0; b_i <= nz; b_i++) {
      ctr = A_data[b_i];
      colRngTF = rtIsInf(ctr);
      if (colRngTF && (ctr > 0.0)) {
        trueCount++;
        extremaList_data[right] = (signed char)b_i;
        right++;
      }
    }
    for (i = 0; i < trueCount; i++) {
      A_data[extremaList_data[i]] = rtNaN;
    }
    maxVals_size =
        getAllLocalMax(A_data, A_size, maxVals_data, inflectionPts_data, &nz);
    for (i = 0; i < maxVals_size; i++) {
      maxVals_data[i] = (maxVals_data[i] || infMaxVals_data[i]);
    }
    for (i = 0; i < trueCount; i++) {
      A_data[extremaList_data[i]] = rtInf;
    }
    nz = maxVals_data[0];
    for (k = 2; k <= maxVals_size; k++) {
      nz += maxVals_data[k - 1];
    }
    if (maxNumExt < nz) {
      nz = maxVals_size - 1;
      trueCount = 0;
      right = 0;
      for (b_i = 0; b_i <= nz; b_i++) {
        if (maxVals_data[b_i] || inflectionPts_data[b_i]) {
          trueCount++;
          tmp_data[right] = (signed char)b_i;
          right++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        extremaList_data[i] = (signed char)(tmp_data[i] + 1);
      }
      memcpy(&infMaxVals_data[0], &maxVals_data[0],
             (unsigned int)A_size * sizeof(boolean_T));
      for (b_i = 0; b_i < trueCount; b_i++) {
        i1 = tmp_data[b_i];
        if (infMaxVals_data[i1]) {
          localMaxValue_tmp = A_data[i1];
          if (rtIsInf(localMaxValue_tmp) || rtIsNaN(localMaxValue_tmp)) {
            P_data[i1] = rtInf;
          } else {
            localMins_idx_0_tmp = A_data[extremaList_data[b_i] - 1];
            localMins_idx_0 = localMins_idx_0_tmp;
            localMins_idx_1 = localMins_idx_0_tmp;
            nz = b_i - 1;
            right = b_i + 1;
            do {
              exitg3 = 0;
              if (nz + 1 > 0) {
                if (!infMaxVals_data[tmp_data[nz]]) {
                  ctr = A_data[extremaList_data[nz] - 1];
                  if ((!(localMins_idx_0 <= ctr)) && (!rtIsNaN(ctr))) {
                    localMins_idx_0 = ctr;
                  }
                  nz--;
                } else if (A_data[tmp_data[nz]] > localMaxValue_tmp) {
                  exitg3 = 1;
                } else {
                  nz--;
                }
              } else {
                exitg3 = 2;
              }
            } while (exitg3 == 0);
            do {
              exitg2 = 0;
              if (right + 1 <= trueCount) {
                if (!infMaxVals_data[tmp_data[right]]) {
                  ctr = A_data[extremaList_data[right] - 1];
                  if ((!(localMins_idx_1 <= ctr)) && (!rtIsNaN(ctr))) {
                    localMins_idx_1 = ctr;
                  }
                  right++;
                } else if (A_data[tmp_data[right]] > localMaxValue_tmp) {
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
            i1 = tmp_data[b_i];
            P_data[i1] = localMins_idx_0_tmp - localMins_idx_0;
            maxVals_data[i1] = (P_data[i1] >= 0.0);
          }
        }
      }
    }
    nz = maxVals_data[0];
    for (k = 2; k <= maxVals_size; k++) {
      nz += maxVals_data[k - 1];
    }
    if (maxNumExt < nz) {
      nz = maxVals_size - 1;
      trueCount = 0;
      right = 0;
      for (b_i = 0; b_i <= nz; b_i++) {
        if (maxVals_data[b_i]) {
          trueCount++;
          b_tmp_data[right] = (signed char)b_i;
          right++;
        }
      }
      for (i = 0; i < trueCount; i++) {
        idxTemp_data[i] = P_data[b_tmp_data[i]];
      }
      nz = sort(idxTemp_data, &trueCount, iidx_data);
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
      for (i2 = 0; i2 < right; i2++) {
        maxVals_data[b_tmp_data[(int)idxTemp_data[i + i2] - 1]] = false;
      }
    }
    colRngTF = false;
    nz = 1;
    exitg4 = false;
    while ((!exitg4) && (nz <= maxVals_size)) {
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
    if (nz < 1) {
      i = -1;
    } else {
      i = 0;
    }
    for (k = 0; k <= i; k++) {
      memcpy(&idxTemp_data[0], &A_data[0],
             (unsigned int)A_size * sizeof(double));
      nz = diff(idxTemp_data, A_size, c_tmp_data);
      for (i2 = 0; i2 < nz; i2++) {
        locUniLeadMax_data[i2] = (c_tmp_data[i2] != 0.0);
      }
      memset(&idxTemp_data[0], 0, (unsigned int)A_size * sizeof(double));
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
      leftRange_data[0] = 1.0;
      for (i2 = 0; i2 < right; i2++) {
        leftRange_data[i2 + 1] = idxTemp_data[i2] + 1.0;
      }
      if (right + 1 < 2) {
        i2 = 0;
        b_i = 0;
      } else {
        i2 = 1;
        b_i = right + 1;
      }
      trueCount = b_i - i2;
      nz = trueCount + 1;
      for (b_i = 0; b_i < trueCount; b_i++) {
        rightRange_data[b_i] = (signed char)((int)leftRange_data[i2 + b_i] - 1);
      }
      rightRange_data[trueCount] = (signed char)A_size;
      for (i2 = 0; i2 < nz; i2++) {
        flatRegion_data[i2] = (rightRange_data[i2] > (int)leftRange_data[i2]);
      }
      colRngTF = false;
      nz = 1;
      exitg4 = false;
      while ((!exitg4) && (nz <= trueCount + 1)) {
        if (flatRegion_data[nz - 1]) {
          colRngTF = true;
          exitg4 = true;
        } else {
          nz++;
        }
      }
      if (colRngTF) {
        colRngTF = false;
        nz = 0;
        exitg4 = false;
        while ((!exitg4) && (nz + 1 <= right + 1)) {
          if (maxVals_data[(int)leftRange_data[nz] - 1] &&
              flatRegion_data[nz]) {
            colRngTF = true;
            exitg4 = true;
          } else {
            nz++;
          }
        }
        if (colRngTF) {
          nz = right;
          trueCount = 0;
          right = 0;
          for (b_i = 0; b_i <= nz; b_i++) {
            if (maxVals_data[(int)leftRange_data[b_i] - 1] &&
                flatRegion_data[b_i]) {
              trueCount++;
              d_tmp_data[right] = (signed char)b_i;
              right++;
            }
          }
          for (i2 = 0; i2 < trueCount; i2++) {
            i1 = d_tmp_data[i2];
            ranges_data[i2] = (signed char)leftRange_data[i1];
            ranges_data[i2 + trueCount] = rightRange_data[i1];
          }
          for (i2 = 0; i2 < trueCount; i2++) {
            maxVals_data[ranges_data[i2] - 1] = false;
          }
          if (trueCount == 0) {
            trueCount = 0;
          } else {
            for (nz = 0; nz < trueCount; nz++) {
              leftRange_data[nz] =
                  ranges_data[nz] + ranges_data[trueCount + nz];
            }
          }
          for (nz = 0; nz < trueCount; nz++) {
            ctr = floor(leftRange_data[nz] / 2.0);
            leftRange_data[nz] = ctr;
            maxVals_data[(int)ctr - 1] = true;
          }
        }
      }
    }
  }
  return maxVals_size;
}

/*
 * File trailer for isLocalExtrema.c
 *
 * [EOF]
 */
