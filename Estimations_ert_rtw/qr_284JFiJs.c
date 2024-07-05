/*
 * File: qr_284JFiJs.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "rt_hypotd_snf.h"
#include "xgemv_VcPNwKUA.h"
#include "xgerc_aZmBAV8G.h"
#include "xnrm2_ILvMWxbD.h"
#include "qr_284JFiJs.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void qr_284JFiJs(const real_T A[18], real_T Q[18], real_T R[9])
{
  real_T b_A[18];
  real_T work[3];
  real_T atmp;
  real_T beta1;
  real_T tau_idx_0;
  real_T tau_idx_1;
  real_T tau_idx_2;
  int32_T exitg1;
  int16_T b_coltop;
  int16_T c_lastc;
  int16_T coltop;
  int16_T knt;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 18U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  atmp = b_A[0];
  tau_idx_0 = 0.0;
  beta1 = xnrm2_ILvMWxbD(5, b_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[0], beta1);
    if (b_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 1; c_lastc < 6; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+35;
        }

        beta1 *= 9.9792015476736E+35;
        atmp *= 9.9792015476736E+35;
      } while (!(fabs(beta1) >= 1.0020841800044864E-35));

      beta1 = rt_hypotd_snf(atmp, xnrm2_ILvMWxbD(5, b_A, 2));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 1; c_lastc < 6; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-35;
      }

      atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - b_A[0]) / beta1;
      atmp = 1.0 / (b_A[0] - beta1);
      for (knt = 1; knt < 6; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 6;
    c_lastc = 0;
    while ((knt > 0) && (b_A[c_lastc + 5] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      b_coltop = (c_lastc - 1) * 6 + 6;
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
    xgemv_VcPNwKUA(knt, c_lastc, b_A, 7, b_A, 1, work);
    xgerc_aZmBAV8G(knt, c_lastc, -tau_idx_0, 1, work, b_A, 7);
  }

  b_A[0] = atmp;
  atmp = b_A[7];
  tau_idx_1 = 0.0;
  beta1 = xnrm2_ILvMWxbD(4, b_A, 9);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[7], beta1);
    if (b_A[7] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 8; c_lastc < 12; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+35;
        }

        beta1 *= 9.9792015476736E+35;
        atmp *= 9.9792015476736E+35;
      } while (!(fabs(beta1) >= 1.0020841800044864E-35));

      beta1 = rt_hypotd_snf(atmp, xnrm2_ILvMWxbD(4, b_A, 9));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 8; c_lastc < 12; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-35;
      }

      atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - b_A[7]) / beta1;
      atmp = 1.0 / (b_A[7] - beta1);
      for (knt = 8; knt < 12; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[7] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 5;
    c_lastc = 6;
    while ((knt > 0) && (b_A[c_lastc + 5] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    coltop = 13;
    do {
      exitg1 = 0L;
      if (coltop + 1 <= 13 + knt) {
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
    xgemv_VcPNwKUA(knt, c_lastc, b_A, 14, b_A, 8, work);
    xgerc_aZmBAV8G(knt, c_lastc, -tau_idx_1, 8, work, b_A, 14);
  }

  b_A[7] = atmp;
  atmp = b_A[14];
  tau_idx_2 = 0.0;
  beta1 = xnrm2_ILvMWxbD(3, b_A, 16);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(b_A[14], beta1);
    if (b_A[14] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        for (c_lastc = 15; c_lastc < 18; c_lastc++) {
          b_A[c_lastc] *= 9.9792015476736E+35;
        }

        beta1 *= 9.9792015476736E+35;
        atmp *= 9.9792015476736E+35;
      } while (!(fabs(beta1) >= 1.0020841800044864E-35));

      beta1 = rt_hypotd_snf(atmp, xnrm2_ILvMWxbD(3, b_A, 16));
      if (atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_2 = (beta1 - atmp) / beta1;
      atmp = 1.0 / (atmp - beta1);
      for (c_lastc = 15; c_lastc < 18; c_lastc++) {
        b_A[c_lastc] *= atmp;
      }

      for (c_lastc = 0; c_lastc <= knt; c_lastc++) {
        beta1 *= 1.0020841800044864E-35;
      }

      atmp = beta1;
    } else {
      tau_idx_2 = (beta1 - b_A[14]) / beta1;
      atmp = 1.0 / (b_A[14] - beta1);
      for (knt = 15; knt < 18; knt++) {
        b_A[knt] *= atmp;
      }

      atmp = beta1;
    }
  }

  b_A[14] = atmp;
  R[0] = b_A[0];
  for (knt = 1; knt + 1 < 4; knt++) {
    R[knt] = 0.0;
  }

  work[0] = 0.0;
  for (knt = 0; knt < 2; knt++) {
    R[knt + 3] = b_A[knt + 6];
  }

  for (knt = 2; knt + 1 < 4; knt++) {
    R[knt + 3] = 0.0;
  }

  work[1] = 0.0;
  for (knt = 0; knt < 3; knt++) {
    R[knt + 6] = b_A[knt + 12];
  }

  work[2] = 0.0;
  for (knt = 15; knt < 18; knt++) {
    b_A[knt] *= -tau_idx_2;
  }

  b_A[14] = 1.0 - tau_idx_2;
  for (knt = 0; knt < 2; knt++) {
    b_A[13 - knt] = 0.0;
  }

  b_A[7] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 5;
    c_lastc = 13;
    while ((knt > 0) && (b_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 1;
    b_coltop = 14;
    do {
      exitg1 = 0L;
      if (b_coltop <= knt + 13) {
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
    xgemv_VcPNwKUA(knt, c_lastc, b_A, 14, b_A, 8, work);
    xgerc_aZmBAV8G(knt, c_lastc, -tau_idx_1, 8, work, b_A, 14);
  }

  for (knt = 8; knt < 12; knt++) {
    b_A[knt] *= -tau_idx_1;
  }

  b_A[7] = 1.0 - tau_idx_1;
  b_A[6] = 0.0;
  b_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 6;
    c_lastc = 7;
    while ((knt > 0) && (b_A[c_lastc - 2] == 0.0)) {
      knt--;
      c_lastc--;
    }

    c_lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (c_lastc > 0)) {
      coltop = (c_lastc - 1) * 6 + 7;
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
    xgemv_VcPNwKUA(knt, c_lastc, b_A, 7, b_A, 1, work);
    xgerc_aZmBAV8G(knt, c_lastc, -tau_idx_0, 1, work, b_A, 7);
  }

  for (knt = 1; knt < 6; knt++) {
    b_A[knt] *= -tau_idx_0;
  }

  b_A[0] = 1.0 - tau_idx_0;
  for (knt = 0; knt < 3; knt++) {
    for (c_lastc = 0; c_lastc < 6; c_lastc++) {
      Q[c_lastc + 6 * knt] = b_A[6 * knt + c_lastc];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
