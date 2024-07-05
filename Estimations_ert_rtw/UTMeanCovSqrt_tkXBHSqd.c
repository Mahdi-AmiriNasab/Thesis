/*
 * File: UTMeanCovSqrt_tkXBHSqd.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 14:53:07 2022
 */

#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "qr_284JFiJs.h"
#include "qr_sQLXF2xn.h"
#include "rotate_h3nP3JUD.h"
#include "svd_pFhYsdaI.h"
#include "UTMeanCovSqrt_tkXBHSqd.h"

/* Function for MATLAB Function: '<S6>/Predict' */
void UTMeanCovSqrt_tkXBHSqd(const real_T meanWeights[2], real_T covWeights[2],
  real_T OOM, real_T Y1[3], real_T Y2[18], real_T Ymean[3], real_T Sy[9])
{
  real_T W2[18];
  real_T unusedU0[18];
  real_T A[9];
  real_T Ss[9];
  real_T Sy_0[9];
  real_T c[3];
  real_T s[3];
  real_T x[3];
  real_T absxk;
  real_T b_t;
  real_T scale;
  real_T signOOM;
  real_T sqrtOOM;
  real_T temp;
  int32_T exitg1;
  int16_T Sy_tmp;
  int16_T Y2_tmp;
  int16_T kk;
  boolean_T errorCondition;
  boolean_T exitg2;
  boolean_T guard1 = false;
  Ymean[0] = Y1[0] * meanWeights[0];
  Ymean[1] = Y1[1] * meanWeights[0];
  Ymean[2] = Y1[2] * meanWeights[0];
  for (kk = 0; kk < 6; kk++) {
    Ymean[0] += Y2[3 * kk] * meanWeights[1];
    Ymean[1] += Y2[3 * kk + 1] * meanWeights[1];
    Ymean[2] += Y2[3 * kk + 2] * meanWeights[1];
  }

  sqrtOOM = Ymean[0] * OOM;
  Ymean[0] = sqrtOOM;
  Y1[0] -= sqrtOOM;
  sqrtOOM = Ymean[1] * OOM;
  Ymean[1] = sqrtOOM;
  Y1[1] -= sqrtOOM;
  sqrtOOM = Ymean[2] * OOM;
  temp = Y1[2] - sqrtOOM;
  Ymean[2] = sqrtOOM;
  Y1[2] = temp;
  for (kk = 0; kk < 6; kk++) {
    Y2[3 * kk] -= Ymean[0];
    Y2_tmp = 3 * kk + 1;
    Y2[Y2_tmp] -= Ymean[1];
    Y2_tmp = 3 * kk + 2;
    Y2[Y2_tmp] -= sqrtOOM;
  }

  if (OOM < 0.0) {
    signOOM = -1.0;
  } else if (OOM > 0.0) {
    signOOM = 1.0;
  } else if (OOM == 0.0) {
    signOOM = 0.0;
  } else {
    signOOM = (rtNaN);
  }

  covWeights[0] *= signOOM;
  OOM *= signOOM;
  sqrtOOM = sqrt(OOM);
  signOOM = sqrt(signOOM * covWeights[1]);
  for (kk = 0; kk < 3; kk++) {
    for (Y2_tmp = 0; Y2_tmp < 6; Y2_tmp++) {
      W2[Y2_tmp + 6 * kk] = Y2[3 * Y2_tmp + kk] * signOOM;
    }
  }

  qr_284JFiJs(W2, unusedU0, Sy);
  if (covWeights[0] < 0.0) {
    signOOM = -1.0;
  } else if (covWeights[0] > 0.0) {
    signOOM = 1.0;
  } else if (covWeights[0] == 0.0) {
    signOOM = 0.0;
  } else {
    signOOM = (rtNaN);
  }

  if (signOOM == 1.0) {
    for (kk = 0; kk < 2; kk++) {
      Sy[kk + 1] = 0.0;
    }

    Sy[5] = 0.0;
    c[2] = 0.0;
    s[2] = 0.0;
    rotate_h3nP3JUD(Sy[0], Y1[0], &c[0], &s[0], &Sy[0]);
    signOOM = c[0] * Y1[1] - s[0] * Sy[3];
    Sy[3] = c[0] * Sy[3] + s[0] * Y1[1];
    rotate_h3nP3JUD(Sy[4], signOOM, &c[1], &s[1], &Sy[4]);
    signOOM = temp;
    for (kk = 0; kk < 2; kk++) {
      temp = s[kk] * signOOM;
      scale = Sy[kk + 6];
      signOOM = c[kk] * signOOM - scale * s[kk];
      Sy[kk + 6] = scale * c[kk] + temp;
    }

    rotate_h3nP3JUD(Sy[8], signOOM, &c[2], &s[2], &Sy[8]);
    for (kk = 0; kk < 3; kk++) {
      Sy_0[3 * kk] = Sy[kk];
      Sy_0[3 * kk + 1] = Sy[kk + 3];
      Sy_0[3 * kk + 2] = Sy[kk + 6];
    }

    for (kk = 0; kk < 9; kk++) {
      Sy[kk] = sqrtOOM * Sy_0[kk];
    }
  } else {
    for (kk = 0; kk < 2; kk++) {
      Sy[kk + 1] = 0.0;
    }

    Sy[5] = 0.0;
    errorCondition = (Sy[0] == 0.0);
    if (!errorCondition) {
      errorCondition = ((Sy[4] == 0.0) || errorCondition);
    }

    if (!errorCondition) {
      errorCondition = ((Sy[8] == 0.0) || errorCondition);
    }

    guard1 = false;
    if (errorCondition) {
      guard1 = true;
    } else {
      x[2] = temp;
      scale = 3.3121686421112381E-35;
      x[0] = Y1[0] / Sy[0];
      absxk = fabs(x[0]);
      if (absxk > 3.3121686421112381E-35) {
        signOOM = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-35;
        signOOM = b_t * b_t;
      }

      x[1] = (Y1[1] - Sy[3] * x[0]) / Sy[4];
      absxk = fabs(x[1]);
      if (absxk > scale) {
        b_t = scale / absxk;
        signOOM = signOOM * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        signOOM += b_t * b_t;
      }

      for (kk = 0; kk < 2; kk++) {
        temp -= Sy[kk + 6] * x[kk];
      }

      x[2] = temp / Sy[8];
      absxk = fabs(x[2]);
      if (absxk > scale) {
        b_t = scale / absxk;
        signOOM = signOOM * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        signOOM += b_t * b_t;
      }

      signOOM = scale * sqrt(signOOM);
      if (signOOM >= 1.0) {
        guard1 = true;
      } else {
        rotate_h3nP3JUD(sqrt(1.0 - signOOM * signOOM), x[2], &c[2], &s[2], &temp);
        x[2] = 0.0;
        rotate_h3nP3JUD(temp, x[1], &c[1], &s[1], &temp);
        x[1] = 0.0;
        rotate_h3nP3JUD(temp, x[0], &c[0], &s[0], &temp);
        x[0] = 0.0;
        for (kk = 0; kk + 1 > 0; kk--) {
          temp = s[kk] * Sy[kk];
          Sy[kk] = c[kk] * Sy[kk] - s[kk] * x[0];
          x[0] = c[kk] * x[0] + temp;
        }

        for (kk = 1; kk + 1 > 0; kk--) {
          temp = Sy[kk + 3];
          Sy[kk + 3] = temp * c[kk] - s[kk] * x[1];
          x[1] = c[kk] * x[1] + temp * s[kk];
        }

        for (kk = 2; kk + 1 > 0; kk--) {
          temp = Sy[kk + 6];
          Sy[kk + 6] = temp * c[kk] - s[kk] * x[2];
          x[2] = c[kk] * x[2] + temp * s[kk];
        }
      }
    }

    if (guard1) {
      for (kk = 0; kk < 3; kk++) {
        for (Y2_tmp = 0; Y2_tmp < 3; Y2_tmp++) {
          Sy_tmp = kk + 3 * Y2_tmp;
          Sy_0[Sy_tmp] = 0.0;
          Sy_0[Sy_tmp] += Sy[3 * kk] * Sy[3 * Y2_tmp];
          Sy_0[Sy_tmp] += Sy[3 * kk + 1] * Sy[3 * Y2_tmp + 1];
          Sy_0[Sy_tmp] += Sy[3 * kk + 2] * Sy[3 * Y2_tmp + 2];
          Ss[Y2_tmp + 3 * kk] = Y1[Y2_tmp] * Y1[kk];
        }
      }

      errorCondition = true;
      for (kk = 0; kk < 9; kk++) {
        temp = Sy_0[kk] - Ss[kk];
        if (errorCondition && (rtIsInf(temp) || rtIsNaN(temp))) {
          errorCondition = false;
        }

        A[kk] = temp;
      }

      if (errorCondition) {
        svd_pFhYsdaI(A, Ss, s, Sy_0);
      } else {
        s[0] = (rtNaN);
        s[1] = (rtNaN);
        s[2] = (rtNaN);
        for (kk = 0; kk < 9; kk++) {
          Sy_0[kk] = (rtNaN);
        }
      }

      for (kk = 0; kk < 9; kk++) {
        Ss[kk] = 0.0;
      }

      Ss[0] = s[0];
      Ss[4] = s[1];
      Ss[8] = s[2];
      for (kk = 0; kk < 9; kk++) {
        Ss[kk] = sqrt(Ss[kk]);
      }

      for (kk = 0; kk < 3; kk++) {
        for (Y2_tmp = 0; Y2_tmp < 3; Y2_tmp++) {
          Sy_tmp = kk + 3 * Y2_tmp;
          Sy[Sy_tmp] = 0.0;
          Sy[Sy_tmp] += Ss[3 * kk] * Sy_0[Y2_tmp];
          Sy[Sy_tmp] += Ss[3 * kk + 1] * Sy_0[Y2_tmp + 3];
          Sy[Sy_tmp] += Ss[3 * kk + 2] * Sy_0[Y2_tmp + 6];
        }
      }

      errorCondition = true;
      kk = 0;
      exitg2 = false;
      while ((!exitg2) && (kk < 3)) {
        Y2_tmp = kk + 1;
        do {
          exitg1 = 0L;
          if (Y2_tmp + 1 < 4) {
            if (!(Sy[3 * kk + Y2_tmp] == 0.0)) {
              errorCondition = false;
              exitg1 = 1L;
            } else {
              Y2_tmp++;
            }
          } else {
            kk++;
            exitg1 = 2L;
          }
        } while (exitg1 == 0L);

        if (exitg1 == 1L) {
          exitg2 = true;
        }
      }

      if (!errorCondition) {
        for (kk = 0; kk < 9; kk++) {
          Sy_0[kk] = Sy[kk];
        }

        qr_sQLXF2xn(Sy_0, Ss, Sy);
      }
    }

    for (kk = 0; kk < 3; kk++) {
      Sy_0[3 * kk] = Sy[kk];
      Sy_0[3 * kk + 1] = Sy[kk + 3];
      Sy_0[3 * kk + 2] = Sy[kk + 6];
    }

    for (kk = 0; kk < 9; kk++) {
      Sy[kk] = sqrtOOM * Sy_0[kk];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
