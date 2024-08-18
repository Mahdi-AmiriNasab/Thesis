/*
 * File: UTMeanCovSqrt_r0lePOnt.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:04:06 2024
 */

#include "rtwtypes.h"
#include "UTMeanCovSqrt_r0lePOnt.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "xnrm2_Zus9lK00.h"
#include "rt_hypotd_snf.h"
#include "cholUpdateFactor_6TkD4oel.h"
#include "rotate_07DDyFSo.h"

/* Function for MATLAB Function: '<S5>/Correct' */
void UTMeanCovSqrt_r0lePOnt(const real_T meanWeights[2], real_T covWeights[2],
  real_T OOM, real_T Y1, real_T Y2[6], const real_T X1[3], real_T X2[18], real_T
  *Ymean, real_T *Sy, real_T Pxy[3])
{
  real_T A[6];
  real_T S;
  real_T beta1;
  real_T d;
  real_T signOOM;
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

  if (rtIsNaN(OOM)) {
    signOOM = (rtNaN);
  } else if (OOM < 0.0) {
    signOOM = -1.0;
  } else {
    signOOM = (OOM > 0.0);
  }

  covWeights[0] *= signOOM;
  covWeights[1] *= signOOM;
  OOM *= signOOM;
  signOOM = sqrt(covWeights[1]);
  for (knt = 0; knt < 6; knt++) {
    A[knt] = signOOM * Y2[knt];
  }

  signOOM = A[0];
  beta1 = xnrm2_Zus9lK00(5, A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(A[0], beta1);
    if (A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (b_k = 0; b_k < 5; b_k++) {
          A[b_k + 1] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        signOOM *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(signOOM, xnrm2_Zus9lK00(5, A, 2));
      if (signOOM >= 0.0) {
        beta1 = -beta1;
      }

      for (b_k = 0; b_k < knt; b_k++) {
        beta1 *= 1.0020841800044864E-292;
      }

      signOOM = beta1;
    } else {
      signOOM = beta1;
    }
  }

  if (rtIsNaN(covWeights[0])) {
    beta1 = (rtNaN);
  } else if (covWeights[0] < 0.0) {
    beta1 = -1.0;
  } else {
    beta1 = (covWeights[0] > 0.0);
  }

  if (beta1 == 1.0) {
    rotate_07DDyFSo(signOOM, Y1, &beta1, &d, &S);
    *Sy = sqrt(OOM) * S;
  } else {
    cholUpdateFactor_6TkD4oel(&signOOM, Y1);
    *Sy = sqrt(OOM) * signOOM;
  }

  signOOM = X1[0];
  beta1 = X1[1];
  d = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] -= signOOM;
    b_k = 3 * knt + 1;
    X2[b_k] -= beta1;
    b_k = 3 * knt + 2;
    X2[b_k] -= d;
  }

  signOOM = covWeights[1] * OOM;
  for (knt = 0; knt < 3; knt++) {
    beta1 = 0.0;
    for (b_k = 0; b_k < 6; b_k++) {
      beta1 += X2[3 * b_k + knt] * Y2[b_k];
    }

    Pxy[knt] = beta1 * signOOM;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
