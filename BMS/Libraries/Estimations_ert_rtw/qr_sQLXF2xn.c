/*
 * File: qr_sQLXF2xn.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_hypotd_snf.h"
#include "xgemv_b3RmsEtu.h"
#include "xgerc_IEYljYzT.h"
#include "xnrm2_Ktlg7eLV.h"
#include "qr_sQLXF2xn.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void qr_sQLXF2xn(const real_T A[9], real_T Q[9], real_T R[9])
{
  real_T b_A[9];
  real_T work[3];
  real_T atmp;
  real_T beta1;
  real_T tau_idx_0;
  real_T tau_idx_1;
  int32_T exitg1;
  int16_T b_coltop;
  int16_T c_lastc;
  int16_T coltop;
  int16_T knt;
  boolean_T exitg2;
  tau_idx_0 = 0.0;
  tau_idx_1 = 0.0;
  for (knt = 0; knt < 9; knt++) {
    b_A[knt] = A[knt];
  }

  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  atmp = b_A[0];
  beta1 = xnrm2_Ktlg7eLV(2, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 1; c_lastc < 3; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+35;
        }

        beta1 *= 9.9792015476736E+35;
        atmp *= 9.9792015476736E+35;
      } while (!(fabs(beta1) >= 1.0020841800044864E-35));

      beta1 = rt_hypotd_snf(atmp, xnrm2_Ktlg7eLV(2, b_A, 2));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 1; c_lastc < 3; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-35;
      }

      atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      atmp = 1.0 / (b_A[0] - beta1);
      for (knt = 1; knt < 3; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 3;
    c_lastc = 0;
    while ((knt > 0) && (b_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      b_coltop = (c_lastc - 1) * 3 + 3;
      coltop = b_coltop;
      do {
        exitg1 = 0L;
        if (coltop + 1 <= b_coltop + knt) {
          if (b_A[coltop] != 0.0) {
            exitg1 = 1L;
          } else {
            coltop++;
          }
        } else {
          c_lastc--;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_b3RmsEtu(knt, c_lastc, b_A, 4, b_A, 1, work);
    xgerc_IEYljYzT(knt, c_lastc, -tau_idx_0, 1, work, b_A, 4);
  }

  b_A[0] = atmp;
  atmp = b_A[4];
  beta1 = xnrm2_Ktlg7eLV(1, b_A, 6);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[4], beta1);
    if (b_A[4] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 5; c_lastc < 6; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+35;
        }

        beta1 *= 9.9792015476736E+35;
        atmp *= 9.9792015476736E+35;
      } while (!(fabs(beta1) >= 1.0020841800044864E-35));

      beta1 = rt_hypotd_snf(atmp, xnrm2_Ktlg7eLV(1, b_A, 6));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 5; c_lastc < 6; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-35;
      }

      atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - b_A[4]) / beta1;
      atmp = 1.0 / (b_A[4] - beta1);
      for (knt = 5; knt < 6; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 2;
    c_lastc = 3;
    while ((knt > 0) && (b_A[c_lastc + 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    coltop = 7;
    do {
      exitg1 = 0L;
      if (coltop + 1 <= 7 + knt) {
        if (b_A[coltop] != 0.0) {
          exitg1 = 1L;
        } else {
          coltop++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1L;
      }
    } while (exitg1 == 0L);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_b3RmsEtu(knt, c_lastc, b_A, 8, b_A, 5, work);
    xgerc_IEYljYzT(knt, c_lastc, -tau_idx_1, 5, work, b_A, 8);
  }

  b_A[4] = atmp;
  R[0] = b_A[0];
  for (knt = 1; knt + 1 < 4; knt++) {
    R[knt] = 0.0;
  }

  work[0] = 0.0;
  for (knt = 0; knt < 2; knt++) {
    R[knt + 3] = b_A[knt + 3];
  }

  for (knt = 2; knt + 1 < 4; knt++) {
    R[knt + 3] = 0.0;
  }

  work[1] = 0.0;
  for (knt = 0; knt < 3; knt++) {
    R[knt + 6] = b_A[knt + 6];
  }

  work[2] = 0.0;
  b_A[8] = 1.0;
  for (knt = 0; knt < 2; knt++) {
    b_A[7 - knt] = 0.0;
  }

  b_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 2;
    c_lastc = 7;
    while ((knt > 0) && (b_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_coltop = 8;
    do {
      exitg1 = 0L;
      if (b_coltop <= knt + 7) {
        if (b_A[b_coltop - 1] != 0.0) {
          exitg1 = 1L;
        } else {
          b_coltop++;
        }
      } else {
        c_lastc = 0;
        exitg1 = 1L;
      }
    } while (exitg1 == 0L);
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_b3RmsEtu(knt, c_lastc, b_A, 8, b_A, 5, work);
    xgerc_IEYljYzT(knt, c_lastc, -tau_idx_1, 5, work, b_A, 8);
  }

  for (knt = 5; knt < 6; knt++) {
    b_A[knt] *= -tau_idx_1;
  }

  b_A[4] = 1.0 - tau_idx_1;
  b_A[3] = 0.0;
  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 3;
    c_lastc = 4;
    while ((knt > 0) && (b_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      coltop = (c_lastc - 1) * 3 + 4;
      b_coltop = coltop;
      do {
        exitg1 = 0L;
        if (b_coltop <= (coltop + knt) - 1) {
          if (b_A[b_coltop - 1] != 0.0) {
            exitg1 = 1L;
          } else {
            b_coltop++;
          }
        } else {
          c_lastc--;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    c_lastc = 0;
  }

  if (knt > 0) {
    xgemv_b3RmsEtu(knt, c_lastc, b_A, 4, b_A, 1, work);
    xgerc_IEYljYzT(knt, c_lastc, -tau_idx_0, 1, work, b_A, 4);
  }

  for (knt = 1; knt < 3; knt++) {
    b_A[knt] *= -tau_idx_0;
  }

  b_A[0] = 1.0 - tau_idx_0;
  for (knt = 0; knt < 3; knt++) {
    Q[3 * knt] = b_A[3 * knt];
    c_lastc = 3 * knt + 1;
    Q[c_lastc] = b_A[c_lastc];
    c_lastc = 3 * knt + 2;
    Q[c_lastc] = b_A[c_lastc];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
