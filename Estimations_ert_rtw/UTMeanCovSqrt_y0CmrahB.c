/*
 * File: UTMeanCovSqrt_y0CmrahB.c
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
#include "cholUpdateFactor_9TQ1AyeS.h"
#include "rotate_h3nP3JUD.h"
#include "rt_hypotd_snf.h"
#include "xnrm2_ka2KfXxR.h"
#include "UTMeanCovSqrt_y0CmrahB.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void UTMeanCovSqrt_y0CmrahB(const real_T meanWeights[2], real_T covWeights[2],
  real_T OOM, real_T Y1, real_T Y2[6], const real_T X1[3], real_T X2[18], real_T
  *Ymean, real_T *Sy, real_T Pxy[3])
{
  real_T A[6];
  real_T X2_0[3];
  real_T S;
  real_T covWeights_0;
  real_T d;
  real_T signOOM;
  real_T xnorm;
  int16_T b_k;
  int16_T knt;
  *Ymean = Y1 * meanWeights[0];
  for (knt = 0; knt < 6; knt++) {
    *Ymean += Y2[knt] * meanWeights[1];
  }

  *Ymean *= OOM;
  Y1 -= *Ymean;
  for (knt = 0; knt < 6; knt++) {
    Y2[knt] -= *Ymean;
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
  covWeights_0 = signOOM * covWeights[1];
  OOM *= signOOM;
  signOOM = sqrt(covWeights_0);
  for (knt = 0; knt < 6; knt++) {
    A[knt] = signOOM * Y2[knt];
  }

  signOOM = A[0];
  xnorm = xnrm2_ka2KfXxR(5, A, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(A[0], xnorm);
    if (A[0] >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        for (b_k = 1; b_k < 6; b_k++) {
          A[b_k] *= 9.9792015476736E+35;
        }

        xnorm *= 9.9792015476736E+35;
        signOOM *= 9.9792015476736E+35;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-35));

      xnorm = rt_hypotd_snf(signOOM, xnrm2_ka2KfXxR(5, A, 2));
      if (signOOM >= 0.0) {
        xnorm = -xnorm;
      }

      for (b_k = 0; b_k <= knt; b_k++) {
        xnorm *= 1.0020841800044864E-35;
      }

      signOOM = xnorm;
    } else {
      signOOM = xnorm;
    }
  }

  if (covWeights[0] < 0.0) {
    xnorm = -1.0;
  } else if (covWeights[0] > 0.0) {
    xnorm = 1.0;
  } else if (covWeights[0] == 0.0) {
    xnorm = 0.0;
  } else {
    xnorm = (rtNaN);
  }

  if (xnorm == 1.0) {
    rotate_h3nP3JUD(signOOM, Y1, &xnorm, &d, &S);
    *Sy = sqrt(OOM) * S;
  } else {
    cholUpdateFactor_9TQ1AyeS(&signOOM, Y1);
    *Sy = sqrt(OOM) * signOOM;
  }

  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] -= X1[0];
    b_k = 3 * knt + 1;
    X2[b_k] -= X1[1];
    b_k = 3 * knt + 2;
    X2[b_k] -= X1[2];
  }

  covWeights_0 *= OOM;
  for (knt = 0; knt < 3; knt++) {
    X2_0[knt] = 0.0;
    for (b_k = 0; b_k < 6; b_k++) {
      X2_0[knt] += X2[3 * b_k + knt] * Y2[b_k];
    }

    Pxy[knt] = X2_0[knt] * covWeights_0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
