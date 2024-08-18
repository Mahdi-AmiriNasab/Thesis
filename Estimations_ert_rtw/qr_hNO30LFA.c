/*
 * File: qr_hNO30LFA.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "qr_hNO30LFA.h"
#include "xnrm2_oMwXIV4S.h"
#include "rt_hypotd_snf.h"
#include <math.h>
#include "xgemv_z1P8pvMn.h"
#include "xgerc_1gopXIGt.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void qr_hNO30LFA(const real_T A[9], real_T Q[9], real_T R[9])
{
  real_T b_A[9];
  real_T tau[3];
  real_T work[3];
  real_T atmp;
  real_T b_A_0;
  real_T beta1;
  int32_T exitg1;
  int16_T b_coltop;
  int16_T b_lastv;
  int16_T c_k;
  int16_T d_i;
  int16_T ii;
  int16_T knt;
  boolean_T exitg2;
  for (d_i = 0; d_i < 9; d_i++) {
    b_A[d_i] = A[d_i];
  }

  tau[0] = 0.0;
  work[0] = 0.0;
  tau[1] = 0.0;
  work[1] = 0.0;
  tau[2] = 0.0;
  work[2] = 0.0;
  for (d_i = 0; d_i < 3; d_i++) {
    ii = d_i * 3 + d_i;
    if (d_i + 1 < 3) {
      atmp = b_A[ii];
      b_lastv = ii + 2;
      tau[d_i] = 0.0;
      beta1 = xnrm2_oMwXIV4S(2 - d_i, b_A, ii + 2);
      if (beta1 != 0.0) {
        b_A_0 = b_A[ii];
        beta1 = rt_hypotd_snf(b_A_0, beta1);
        if (b_A_0 >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          b_coltop = (ii - d_i) + 3;
          do {
            knt++;
            for (c_k = b_lastv; c_k <= b_coltop; c_k++) {
              b_A[c_k - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

          beta1 = rt_hypotd_snf(atmp, xnrm2_oMwXIV4S(2 - d_i, b_A, ii + 2));
          if (atmp >= 0.0) {
            beta1 = -beta1;
          }

          tau[d_i] = (beta1 - atmp) / beta1;
          atmp = 1.0 / (atmp - beta1);
          for (c_k = b_lastv; c_k <= b_coltop; c_k++) {
            b_A[c_k - 1] *= atmp;
          }

          for (b_lastv = 0; b_lastv < knt; b_lastv++) {
            beta1 *= 1.0020841800044864E-292;
          }

          atmp = beta1;
        } else {
          tau[d_i] = (beta1 - b_A_0) / beta1;
          atmp = 1.0 / (b_A_0 - beta1);
          knt = (ii - d_i) + 3;
          for (b_coltop = b_lastv; b_coltop <= knt; b_coltop++) {
            b_A[b_coltop - 1] *= atmp;
          }

          atmp = beta1;
        }
      }

      b_A[ii] = 1.0;
      if (tau[d_i] != 0.0) {
        b_lastv = 3 - d_i;
        knt = (ii - d_i) + 2;
        while ((b_lastv > 0) && (b_A[knt] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - d_i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = ((knt - 1) * 3 + ii) + 3;
          c_k = b_coltop;
          do {
            exitg1 = 0L;
            if (c_k + 1 <= b_coltop + b_lastv) {
              if (b_A[c_k] != 0.0) {
                exitg1 = 1L;
              } else {
                c_k++;
              }
            } else {
              knt--;
              exitg1 = 2L;
            }
          } while (exitg1 == 0L);

          if (exitg1 == 1L) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        xgemv_z1P8pvMn(b_lastv, knt, b_A, ii + 4, b_A, ii + 1, work);
        xgerc_1gopXIGt(b_lastv, knt, -tau[d_i], ii + 1, work, b_A, ii + 4);
      }

      b_A[ii] = atmp;
    } else {
      tau[2] = 0.0;
    }
  }

  for (d_i = 0; d_i < 3; d_i++) {
    for (ii = 0; ii <= d_i; ii++) {
      R[ii + 3 * d_i] = b_A[3 * d_i + ii];
    }

    for (ii = d_i + 2; ii < 4; ii++) {
      R[(ii + 3 * d_i) - 1] = 0.0;
    }

    work[d_i] = 0.0;
  }

  for (d_i = 2; d_i >= 0; d_i--) {
    ii = (d_i * 3 + d_i) + 4;
    if (d_i + 1 < 3) {
      b_A[ii - 4] = 1.0;
      if (tau[d_i] != 0.0) {
        b_lastv = 3 - d_i;
        knt = ii - d_i;
        while ((b_lastv > 0) && (b_A[knt - 2] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - d_i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = (knt - 1) * 3 + ii;
          c_k = b_coltop;
          do {
            exitg1 = 0L;
            if (c_k <= (b_coltop + b_lastv) - 1) {
              if (b_A[c_k - 1] != 0.0) {
                exitg1 = 1L;
              } else {
                c_k++;
              }
            } else {
              knt--;
              exitg1 = 2L;
            }
          } while (exitg1 == 0L);

          if (exitg1 == 1L) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        xgemv_z1P8pvMn(b_lastv, knt, b_A, ii, b_A, ii - 3, work);
        xgerc_1gopXIGt(b_lastv, knt, -tau[d_i], ii - 3, work, b_A, ii);
      }

      b_lastv = (ii - d_i) - 1;
      for (knt = ii - 2; knt <= b_lastv; knt++) {
        b_A[knt - 1] *= -tau[d_i];
      }
    }

    b_A[ii - 4] = 1.0 - tau[d_i];
    for (b_lastv = 0; b_lastv < d_i; b_lastv++) {
      b_A[(ii - b_lastv) - 5] = 0.0;
    }
  }

  for (d_i = 0; d_i < 3; d_i++) {
    Q[3 * d_i] = b_A[3 * d_i];
    ii = 3 * d_i + 1;
    Q[ii] = b_A[ii];
    ii = 3 * d_i + 2;
    Q[ii] = b_A[ii];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
