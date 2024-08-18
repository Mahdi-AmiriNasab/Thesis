/*
 * File: svd_wEmXrMkt.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "svd_wEmXrMkt.h"
#include "xnrm2_oMwXIV4S.h"
#include <math.h>
#include "xdotc_60wSSEjg.h"
#include "xaxpy_JWLefs7J.h"
#include "xnrm2_MbBfWnI8.h"
#include "xrotg_9ZHhnzNd.h"
#include "xaxpy_c8LoyTsT.h"
#include "xaxpy_SXGuMV6a.h"
#include "xrot_cReDmrQt.h"
#include "xswap_3MbvLAgx.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void svd_wEmXrMkt(const real_T A[9], real_T U[9], real_T s[3], real_T V[9])
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
  int16_T e_k;
  int16_T m;
  int16_T qjj;
  int16_T qp1;
  int16_T qq;
  int16_T qs;
  boolean_T apply_transform;
  boolean_T exitg1;
  b_s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (qs = 0; qs < 9; qs++) {
    b_A[qs] = A[qs];
    U[qs] = 0.0;
    V[qs] = 0.0;
  }

  for (m = 0; m < 2; m++) {
    qp1 = m + 2;
    qs = 3 * m + m;
    qq = qs + 1;
    apply_transform = false;
    nrm = xnrm2_oMwXIV4S(3 - m, b_A, qs + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qs] < 0.0) {
        nrm = -nrm;
      }

      b_s[m] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qs - m) + 3;
        for (e_k = qq; e_k <= qjj; e_k++) {
          b_A[e_k - 1] *= nrm;
        }
      } else {
        qjj = (qs - m) + 3;
        for (e_k = qq; e_k <= qjj; e_k++) {
          b_A[e_k - 1] /= b_s[m];
        }
      }

      b_A[qs]++;
      b_s[m] = -b_s[m];
    } else {
      b_s[m] = 0.0;
    }

    for (qq = qp1; qq < 4; qq++) {
      qjj = (qq - 1) * 3 + m;
      if (apply_transform) {
        xaxpy_JWLefs7J(3 - m, -(xdotc_60wSSEjg(3 - m, b_A, qs + 1, b_A, qjj + 1)
          / b_A[qs]), qs + 1, b_A, qjj + 1);
      }

      e[qq - 1] = b_A[qjj];
    }

    for (qq = m + 1; qq < 4; qq++) {
      qs = (3 * m + qq) - 1;
      U[qs] = b_A[qs];
    }

    if (m + 1 <= 1) {
      nrm = xnrm2_MbBfWnI8(2, e, 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }

        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (qq = qp1; qq < 4; qq++) {
            e[qq - 1] *= nrm;
          }
        } else {
          for (qq = qp1; qq < 4; qq++) {
            e[qq - 1] /= nrm;
          }
        }

        e[1]++;
        e[0] = -e[0];
        for (qq = qp1; qq < 4; qq++) {
          work[qq - 1] = 0.0;
        }

        for (qq = qp1; qq < 4; qq++) {
          xaxpy_c8LoyTsT(2, e[qq - 1], b_A, 3 * (qq - 1) + 2, work, 2);
        }

        for (qq = qp1; qq < 4; qq++) {
          xaxpy_SXGuMV6a(2, -e[qq - 1] / e[1], work, 2, b_A, 3 * (qq - 1) + 2);
        }
      }

      for (qq = qp1; qq < 4; qq++) {
        V[qq - 1] = e[qq - 1];
      }
    }
  }

  m = 1;
  b_s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (qp1 = 1; qp1 >= 0; qp1--) {
    qq = 3 * qp1 + qp1;
    if (b_s[qp1] != 0.0) {
      for (qs = qp1 + 2; qs < 4; qs++) {
        qjj = ((qs - 1) * 3 + qp1) + 1;
        xaxpy_JWLefs7J(3 - qp1, -(xdotc_60wSSEjg(3 - qp1, U, qq + 1, U, qjj) /
          U[qq]), qq + 1, U, qjj);
      }

      for (qjj = qp1 + 1; qjj < 4; qjj++) {
        qs = (3 * qp1 + qjj) - 1;
        U[qs] = -U[qs];
      }

      U[qq]++;
      if (qp1 - 1 >= 0) {
        U[3 * qp1] = 0.0;
      }
    } else {
      U[3 * qp1] = 0.0;
      U[3 * qp1 + 1] = 0.0;
      U[3 * qp1 + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (qp1 = 2; qp1 >= 0; qp1--) {
    if ((qp1 + 1 <= 1) && (e[0] != 0.0)) {
      xaxpy_JWLefs7J(2, -(xdotc_60wSSEjg(2, V, 2, V, 5) / V[1]), 2, V, 5);
      xaxpy_JWLefs7J(2, -(xdotc_60wSSEjg(2, V, 2, V, 8) / V[1]), 2, V, 8);
    }

    V[3 * qp1] = 0.0;
    V[3 * qp1 + 1] = 0.0;
    V[3 * qp1 + 2] = 0.0;
    V[qp1 + 3 * qp1] = 1.0;
  }

  qp1 = 0;
  nrm = 0.0;
  for (qq = 0; qq < 3; qq++) {
    r = b_s[qq];
    if (r != 0.0) {
      rt = fabs(r);
      r /= rt;
      b_s[qq] = rt;
      if (qq + 1 < 3) {
        e[qq] /= r;
      }

      qs = 3 * qq + 1;
      for (qjj = qs; qjj <= qs + 2; qjj++) {
        U[qjj - 1] *= r;
      }
    }

    if (qq + 1 < 3) {
      r = e[qq];
      if (r != 0.0) {
        rt = fabs(r);
        r = rt / r;
        e[qq] = rt;
        b_s[qq + 1] *= r;
        qs = (qq + 1) * 3 + 1;
        for (qjj = qs; qjj <= qs + 2; qjj++) {
          V[qjj - 1] *= r;
        }
      }
    }

    nrm = fmax(nrm, fmax(fabs(b_s[qq]), fabs(e[qq])));
  }

  while ((m + 2 > 0) && (qp1 < 75)) {
    qq = m + 1;
    exitg1 = false;
    while (!(exitg1 || (qq == 0))) {
      rt = fabs(e[qq - 1]);
      if (rt <= (fabs(b_s[qq - 1]) + fabs(b_s[qq])) * 2.2204460492503131E-16) {
        e[qq - 1] = 0.0;
        exitg1 = true;
      } else if ((rt <= 1.0020841800044864E-292) || ((qp1 > 20) && (rt <=
                   2.2204460492503131E-16 * nrm))) {
        e[qq - 1] = 0.0;
        exitg1 = true;
      } else {
        qq--;
      }
    }

    if (m + 1 == qq) {
      qjj = 4;
    } else {
      qs = m + 2;
      qjj = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qjj >= qq)) {
        qs = qjj;
        if (qjj == qq) {
          exitg1 = true;
        } else {
          rt = 0.0;
          if (qjj < m + 2) {
            rt = fabs(e[qjj - 1]);
          }

          if (qjj > qq + 1) {
            rt += fabs(e[qjj - 2]);
          }

          r = fabs(b_s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * rt) || (r <=
               1.0020841800044864E-292)) {
            b_s[qjj - 1] = 0.0;
            exitg1 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qs == qq) {
        qjj = 3;
      } else if (m + 2 == qs) {
        qjj = 1;
      } else {
        qjj = 2;
        qq = qs;
      }
    }

    switch (qjj) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (qs = m + 1; qs >= qq + 1; qs--) {
        xrotg_9ZHhnzNd(&b_s[qs - 1], &rt, &r, &sqds);
        if (qs > qq + 1) {
          rt = -sqds * e[0];
          e[0] *= r;
        }

        xrot_cReDmrQt(V, 3 * (qs - 1) + 1, 3 * (m + 1) + 1, r, sqds);
      }
      break;

     case 2:
      rt = e[qq - 1];
      e[qq - 1] = 0.0;
      for (qs = qq + 1; qs <= m + 2; qs++) {
        xrotg_9ZHhnzNd(&b_s[qs - 1], &rt, &sqds, &smm1);
        r = e[qs - 1];
        rt = -smm1 * r;
        e[qs - 1] = r * sqds;
        xrot_cReDmrQt(U, 3 * (qs - 1) + 1, 3 * (qq - 1) + 1, sqds, smm1);
      }
      break;

     case 3:
      rt = b_s[m + 1];
      r = fmax(fmax(fmax(fmax(fabs(rt), fabs(b_s[m])), fabs(e[m])), fabs(b_s[qq])),
               fabs(e[qq]));
      rt /= r;
      smm1 = b_s[m] / r;
      emm1 = e[m] / r;
      sqds = b_s[qq] / r;
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
      r = e[qq] / r * sqds;
      for (e_k = qq + 1; e_k <= m + 1; e_k++) {
        xrotg_9ZHhnzNd(&rt, &r, &sqds, &smm1);
        if (e_k > qq + 1) {
          e[0] = rt;
        }

        emm1 = e[e_k - 1];
        r = b_s[e_k - 1];
        e[e_k - 1] = emm1 * sqds - r * smm1;
        rt = smm1 * b_s[e_k];
        b_s[e_k] *= sqds;
        qs = (e_k - 1) * 3 + 1;
        qjj = 3 * e_k + 1;
        xrot_cReDmrQt(V, qs, qjj, sqds, smm1);
        b_s[e_k - 1] = r * sqds + emm1 * smm1;
        xrotg_9ZHhnzNd(&b_s[e_k - 1], &rt, &sqds, &smm1);
        r = e[e_k - 1];
        rt = r * sqds + smm1 * b_s[e_k];
        b_s[e_k] = r * -smm1 + sqds * b_s[e_k];
        r = smm1 * e[e_k];
        e[e_k] *= sqds;
        xrot_cReDmrQt(U, qs, qjj, sqds, smm1);
      }

      e[m] = rt;
      qp1++;
      break;

     default:
      if (b_s[qq] < 0.0) {
        b_s[qq] = -b_s[qq];
        qp1 = 3 * qq + 1;
        for (qs = qp1; qs <= qp1 + 2; qs++) {
          V[qs - 1] = -V[qs - 1];
        }
      }

      qp1 = qq + 1;
      while ((qq + 1 < 3) && (b_s[qq] < b_s[qp1])) {
        rt = b_s[qq];
        b_s[qq] = b_s[qp1];
        b_s[qp1] = rt;
        qs = 3 * qq + 1;
        qjj = (qq + 1) * 3 + 1;
        xswap_3MbvLAgx(V, qs, qjj);
        xswap_3MbvLAgx(U, qs, qjj);
        qq = qp1;
        qp1++;
      }

      qp1 = 0;
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
