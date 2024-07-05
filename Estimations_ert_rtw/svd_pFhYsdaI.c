/*
 * File: svd_pFhYsdaI.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "xaxpy_JqyUiIN6.h"
#include "xaxpy_jLya3zjW.h"
#include "xaxpy_vWVgFQOY.h"
#include "xdotc_LG9MMAYc.h"
#include "xnrm2_5VDU76G0.h"
#include "xnrm2_Ktlg7eLV.h"
#include "xrot_qFzRtW7e.h"
#include "xrotg_clY2b9zV.h"
#include "xscal_HQKDLyyu.h"
#include "xscal_NhqFnfu9.h"
#include "xscal_acw0q764.h"
#include "xswap_4G8dlkZl.h"
#include "svd_pFhYsdaI.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void svd_pFhYsdaI(const real_T A[9], real_T U[9], real_T s[3], real_T V[9])
{
  real_T b_A[9];
  real_T b_s[3];
  real_T e[3];
  real_T work[3];
  real_T emm1;
  real_T nrm;
  real_T r;
  real_T rt;
  real_T shift;
  real_T smm1;
  real_T sqds;
  int16_T c_q;
  int16_T kase;
  int16_T m;
  int16_T qjj;
  int16_T qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  e[0] = 0.0;
  work[0] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (m = 0; m < 9; m++) {
    b_A[m] = A[m];
    U[m] = 0.0;
    V[m] = 0.0;
  }

  apply_transform = false;
  nrm = xnrm2_Ktlg7eLV(3, b_A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      b_s[0] = -nrm;
    } else {
      b_s[0] = nrm;
    }

    if (fabs(b_s[0]) >= 1.0020841800044864E-35) {
      xscal_HQKDLyyu(3, 1.0 / b_s[0], b_A, 1);
    } else {
      for (m = 0; m < 3; m++) {
        b_A[m] /= b_s[0];
      }
    }

    b_A[0]++;
    b_s[0] = -b_s[0];
  } else {
    b_s[0] = 0.0;
  }

  for (m = 1; m + 1 < 4; m++) {
    qjj = 3 * m;
    if (apply_transform) {
      xaxpy_vWVgFQOY(3, -(xdotc_LG9MMAYc(3, b_A, 1, b_A, qjj + 1) / b_A[0]), 1,
                     b_A, qjj + 1);
    }

    e[m] = b_A[qjj];
  }

  for (m = 0; m + 1 < 4; m++) {
    U[m] = b_A[m];
  }

  nrm = xnrm2_5VDU76G0(2, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      nrm = -nrm;
    }

    e[0] = nrm;
    if (fabs(nrm) >= 1.0020841800044864E-35) {
      xscal_acw0q764(2, 1.0 / nrm, e, 2);
    } else {
      for (m = 1; m < 3; m++) {
        e[m] /= nrm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (m = 2; m < 4; m++) {
      work[m - 1] = 0.0;
    }

    for (m = 1; m + 1 < 4; m++) {
      xaxpy_JqyUiIN6(2, e[m], b_A, 3 * m + 2, work, 2);
    }

    for (m = 1; m + 1 < 4; m++) {
      xaxpy_jLya3zjW(2, -e[m] / e[1], work, 2, b_A, 3 * m + 2);
    }
  }

  for (m = 1; m + 1 < 4; m++) {
    V[m] = e[m];
  }

  apply_transform = false;
  nrm = xnrm2_Ktlg7eLV(2, b_A, 5);
  if (nrm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      b_s[1] = -nrm;
    } else {
      b_s[1] = nrm;
    }

    if (fabs(b_s[1]) >= 1.0020841800044864E-35) {
      xscal_HQKDLyyu(2, 1.0 / b_s[1], b_A, 5);
    } else {
      for (m = 4; m < 6; m++) {
        b_A[m] /= b_s[1];
      }
    }

    b_A[4]++;
    b_s[1] = -b_s[1];
  } else {
    b_s[1] = 0.0;
  }

  for (m = 2; m + 1 < 4; m++) {
    qjj = 3 * m + 1;
    if (apply_transform) {
      xaxpy_vWVgFQOY(2, -(xdotc_LG9MMAYc(2, b_A, 5, b_A, qjj + 1) / b_A[4]), 5,
                     b_A, qjj + 1);
    }

    e[m] = b_A[qjj];
  }

  for (m = 1; m + 1 < 4; m++) {
    U[m + 3] = b_A[m + 3];
  }

  m = 1;
  b_s[2] = b_A[8];
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (c_q = 1; c_q >= 0; c_q--) {
    qq = 3 * c_q + c_q;
    if (b_s[c_q] != 0.0) {
      for (kase = c_q + 1; kase + 1 < 4; kase++) {
        qjj = (3 * kase + c_q) + 1;
        xaxpy_vWVgFQOY(3 - c_q, -(xdotc_LG9MMAYc(3 - c_q, U, qq + 1, U, qjj) /
          U[qq]), qq + 1, U, qjj);
      }

      for (qjj = c_q; qjj + 1 < 4; qjj++) {
        kase = 3 * c_q + qjj;
        U[kase] = -U[kase];
      }

      U[qq]++;
      if (0 <= c_q - 1) {
        U[3 * c_q] = 0.0;
      }
    } else {
      U[3 * c_q] = 0.0;
      U[3 * c_q + 1] = 0.0;
      U[3 * c_q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (c_q = 2; c_q >= 0; c_q--) {
    if ((c_q + 1 <= 1) && (e[0] != 0.0)) {
      for (qq = 2; qq < 4; qq++) {
        qjj = (qq - 1) * 3 + 2;
        xaxpy_vWVgFQOY(2, -(xdotc_LG9MMAYc(2, V, 2, V, qjj) / V[1]), 2, V, qjj);
      }
    }

    V[3 * c_q] = 0.0;
    V[3 * c_q + 1] = 0.0;
    V[3 * c_q + 2] = 0.0;
    V[c_q + 3 * c_q] = 1.0;
  }

  nrm = e[0];
  if (b_s[0] != 0.0) {
    rt = fabs(b_s[0]);
    r = b_s[0] / rt;
    b_s[0] = rt;
    nrm = e[0] / r;
    xscal_NhqFnfu9(r, U, 1);
  }

  if (nrm != 0.0) {
    rt = fabs(nrm);
    r = rt / nrm;
    nrm = rt;
    b_s[1] *= r;
    xscal_NhqFnfu9(r, V, 4);
  }

  e[0] = nrm;
  nrm = b_A[7];
  if (b_s[1] != 0.0) {
    rt = fabs(b_s[1]);
    r = b_s[1] / rt;
    b_s[1] = rt;
    nrm = b_A[7] / r;
    xscal_NhqFnfu9(r, U, 4);
  }

  if (nrm != 0.0) {
    rt = fabs(nrm);
    r = rt / nrm;
    nrm = rt;
    b_s[2] = b_A[8] * r;
    xscal_NhqFnfu9(r, V, 7);
  }

  e[1] = nrm;
  if (b_s[2] != 0.0) {
    rt = fabs(b_s[2]);
    r = b_s[2] / rt;
    b_s[2] = rt;
    xscal_NhqFnfu9(r, U, 7);
  }

  e[2] = 0.0;
  qq = 0;
  nrm = fmax(fmax(fmax(b_s[0], e[0]), fmax(b_s[1], nrm)), fmax(b_s[2], 0.0));
  while ((m + 2 > 0) && (qq < 75)) {
    c_q = m + 1;
    exitg1 = false;
    while (!(exitg1 || (c_q == 0))) {
      rt = fabs(e[c_q - 1]);
      if (rt <= (fabs(b_s[c_q - 1]) + fabs(b_s[c_q])) * 2.2204460492503131E-16)
      {
        e[c_q - 1] = 0.0;
        exitg1 = true;
      } else if ((rt <= 1.0020841800044864E-35) || ((qq > 20) && (rt <=
                   2.2204460492503131E-16 * nrm))) {
        e[c_q - 1] = 0.0;
        exitg1 = true;
      } else {
        c_q--;
      }
    }

    if (m + 1 == c_q) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= c_q)) {
        qjj = kase;
        if (kase == c_q) {
          exitg1 = true;
        } else {
          rt = 0.0;
          if (kase < m + 2) {
            rt = fabs(e[kase - 1]);
          }

          if (kase > c_q + 1) {
            rt += fabs(e[kase - 2]);
          }

          r = fabs(b_s[kase - 1]);
          if ((r <= 2.2204460492503131E-16 * rt) || (r <=
               1.0020841800044864E-35)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qjj == c_q) {
        kase = 3;
      } else if (m + 2 == qjj) {
        kase = 1;
      } else {
        kase = 2;
        c_q = qjj;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (qjj = m; qjj + 1 >= c_q + 1; qjj--) {
        xrotg_clY2b9zV(&b_s[qjj], &rt, &r, &sqds);
        if (qjj + 1 > c_q + 1) {
          rt = -sqds * e[0];
          e[0] *= r;
        }

        xrot_qFzRtW7e(V, 3 * qjj + 1, 3 * (m + 1) + 1, r, sqds);
      }
      break;

     case 2:
      rt = e[c_q - 1];
      e[c_q - 1] = 0.0;
      for (qjj = c_q; qjj < m + 2; qjj++) {
        xrotg_clY2b9zV(&b_s[qjj], &rt, &r, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= r;
        xrot_qFzRtW7e(U, 3 * qjj + 1, 3 * (c_q - 1) + 1, r, sqds);
      }
      break;

     case 3:
      rt = b_s[m + 1];
      r = fmax(fmax(fmax(fmax(fabs(rt), fabs(b_s[m])), fabs(e[m])), fabs(b_s[c_q])),
               fabs(e[c_q]));
      rt /= r;
      smm1 = b_s[m] / r;
      emm1 = e[m] / r;
      sqds = b_s[c_q] / r;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      smm1 = e[c_q] / r * sqds;
      for (qjj = c_q + 1; qjj <= m + 1; qjj++) {
        xrotg_clY2b9zV(&rt, &smm1, &r, &sqds);
        if (qjj > c_q + 1) {
          e[0] = rt;
        }

        smm1 = e[qjj - 1];
        emm1 = b_s[qjj - 1];
        rt = emm1 * r + smm1 * sqds;
        e[qjj - 1] = smm1 * r - emm1 * sqds;
        smm1 = sqds * b_s[qjj];
        b_s[qjj] *= r;
        xrot_qFzRtW7e(V, 3 * (qjj - 1) + 1, 3 * qjj + 1, r, sqds);
        xrotg_clY2b9zV(&rt, &smm1, &r, &sqds);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * r + sqds * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -sqds + r * b_s[qjj];
        smm1 = sqds * e[qjj];
        e[qjj] *= r;
        xrot_qFzRtW7e(U, 3 * (qjj - 1) + 1, 3 * qjj + 1, r, sqds);
      }

      e[m] = rt;
      qq++;
      break;

     default:
      if (b_s[c_q] < 0.0) {
        b_s[c_q] = -b_s[c_q];
        xscal_NhqFnfu9(-1.0, V, 3 * c_q + 1);
      }

      qq = c_q + 1;
      while ((c_q + 1 < 3) && (b_s[c_q] < b_s[qq])) {
        rt = b_s[c_q];
        b_s[c_q] = b_s[qq];
        b_s[qq] = rt;
        xswap_4G8dlkZl(V, 3 * c_q + 1, 3 * (c_q + 1) + 1);
        xswap_4G8dlkZl(U, 3 * c_q + 1, 3 * (c_q + 1) + 1);
        c_q = qq;
        qq++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  s[1] = b_s[1];
  s[2] = b_s[2];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
