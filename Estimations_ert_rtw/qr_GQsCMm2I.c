/*
 * File: qr_GQsCMm2I.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "qr_GQsCMm2I.h"
#include <string.h>
#include "xnrm2_VDVlDcOl.h"
#include "rt_hypotd_snf.h"
#include <math.h>
#include "xgemv_Cp2xCWRq.h"
#include "xgerc_H1MGr2TV.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void qr_GQsCMm2I(const real_T A[18], real_T Q[18], real_T R[9])
{
  real_T tau[3];
  real_T work[3];
  real_T atmp;
  real_T b_A;
  real_T beta1;
  int32_T exitg1;
  int16_T b_coltop;
  int16_T b_lastv;
  int16_T c_k;
  int16_T d_i;
  int16_T ii;
  int16_T knt;
  boolean_T exitg2;
  memcpy(&Q[0], &A[0], 18U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  for (d_i = 0; d_i < 3; d_i++) {
    ii = d_i * 6 + d_i;
    atmp = Q[ii];
    b_lastv = ii + 2;
    tau[d_i] = 0.0;
    beta1 = xnrm2_VDVlDcOl(5 - d_i, Q, ii + 2);
    if (beta1 != 0.0) {
      b_A = Q[ii];
      beta1 = rt_hypotd_snf(b_A, beta1);
      if (b_A >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = 0;
        b_coltop = (ii - d_i) + 6;
        do {
          knt++;
          for (c_k = b_lastv; c_k <= b_coltop; c_k++) {
            Q[c_k - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          atmp *= 9.9792015476736E+291;
        } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

        beta1 = rt_hypotd_snf(atmp, xnrm2_VDVlDcOl(5 - d_i, Q, ii + 2));
        if (atmp >= 0.0) {
          beta1 = -beta1;
        }

        tau[d_i] = (beta1 - atmp) / beta1;
        atmp = 1.0 / (atmp - beta1);
        for (c_k = b_lastv; c_k <= b_coltop; c_k++) {
          Q[c_k - 1] *= atmp;
        }

        for (b_lastv = 0; b_lastv < knt; b_lastv++) {
          beta1 *= 1.0020841800044864E-292;
        }

        atmp = beta1;
      } else {
        tau[d_i] = (beta1 - b_A) / beta1;
        atmp = 1.0 / (b_A - beta1);
        knt = (ii - d_i) + 6;
        for (b_coltop = b_lastv; b_coltop <= knt; b_coltop++) {
          Q[b_coltop - 1] *= atmp;
        }

        atmp = beta1;
      }
    }

    Q[ii] = atmp;
    if (d_i + 1 < 3) {
      Q[ii] = 1.0;
      if (tau[d_i] != 0.0) {
        b_lastv = 6 - d_i;
        knt = (ii - d_i) + 5;
        while ((b_lastv > 0) && (Q[knt] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - d_i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = ((knt - 1) * 6 + ii) + 6;
          c_k = b_coltop;
          do {
            exitg1 = 0L;
            if (c_k + 1 <= b_coltop + b_lastv) {
              if (Q[c_k] != 0.0) {
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
        xgemv_Cp2xCWRq(b_lastv, knt, Q, ii + 7, Q, ii + 1, work);
        xgerc_H1MGr2TV(b_lastv, knt, -tau[d_i], ii + 1, work, Q, ii + 7);
      }

      Q[ii] = atmp;
    }
  }

  for (d_i = 0; d_i < 3; d_i++) {
    for (ii = 0; ii <= d_i; ii++) {
      R[ii + 3 * d_i] = Q[6 * d_i + ii];
    }

    for (ii = d_i + 2; ii < 4; ii++) {
      R[(ii + 3 * d_i) - 1] = 0.0;
    }

    work[d_i] = 0.0;
  }

  for (d_i = 2; d_i >= 0; d_i--) {
    ii = (d_i * 6 + d_i) + 7;
    if (d_i + 1 < 3) {
      Q[ii - 7] = 1.0;
      if (tau[d_i] != 0.0) {
        b_lastv = 6 - d_i;
        knt = ii - d_i;
        while ((b_lastv > 0) && (Q[knt - 2] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - d_i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = (knt - 1) * 6 + ii;
          c_k = b_coltop;
          do {
            exitg1 = 0L;
            if (c_k <= (b_coltop + b_lastv) - 1) {
              if (Q[c_k - 1] != 0.0) {
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
        xgemv_Cp2xCWRq(b_lastv, knt, Q, ii, Q, ii - 6, work);
        xgerc_H1MGr2TV(b_lastv, knt, -tau[d_i], ii - 6, work, Q, ii);
      }
    }

    b_lastv = (ii - d_i) - 1;
    for (knt = ii - 5; knt <= b_lastv; knt++) {
      Q[knt - 1] *= -tau[d_i];
    }

    Q[ii - 7] = 1.0 - tau[d_i];
    for (b_lastv = 0; b_lastv < d_i; b_lastv++) {
      Q[(ii - b_lastv) - 8] = 0.0;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
