/*
 * File: Estimations.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 7.6
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sun Aug 18 17:23:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Estimations.h"
#include "rtwtypes.h"
#include "Estimations_private.h"
#include "trisolve_9qKJiUg8.h"
#include <string.h>
#include <math.h>
#include "rotate_07DDyFSo.h"
#include "svd_wEmXrMkt.h"
#include "rt_nonfinite.h"
#include "qr_hNO30LFA.h"
#include "qr_GQsCMm2I.h"
#include "UTMeanCovSqrt_r0lePOnt.h"
#include "xnrm2_RSYnBhZb.h"
#include "rt_hypotd_snf.h"
#include "batteryMeasurementFcn1.h"
#include "batteryStateFcn1.h"
#include "batteryMeasurementFcn2.h"
#include "batteryStateFcn2.h"
#include "batteryMeasurementFcn3.h"
#include "batteryStateFcn3.h"
#include "batteryMeasurementFcn4.h"
#include "batteryStateFcn4.h"
#include "batteryMeasurementFcn5.h"
#include "batteryStateFcn5.h"
#include "batteryMeasurementFcn6.h"
#include "batteryStateFcn6.h"
#include "batteryMeasurementFcn7.h"
#include "batteryStateFcn7.h"
#include "batteryMeasurementFcn8.h"
#include "batteryStateFcn8.h"
#include "batteryMeasurementFcn9.h"
#include "batteryStateFcn9.h"

/* Block states (default storage) */
DW_Estimations_T Estimations_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Estimations_T Estimations_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Estimations_T Estimations_Y;

/* Real-time model */
static RT_MODEL_Estimations_T Estimations_M_;
RT_MODEL_Estimations_T *const Estimations_M = &Estimations_M_;

/* Forward declaration for local functions */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPredi_l(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPredi_e(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPredi_f(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPredi_m(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPredi_k(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPred_ly(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPredi_p(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);
static void UKFCorrectorAdditive_getPred_ew(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);

/*
 * Output and update for atomic system:
 *    '<S12>/Subsystem'
 *    '<S22>/Subsystem'
 *    '<S32>/Subsystem'
 *    '<S42>/Subsystem'
 *    '<S52>/Subsystem'
 *    '<S62>/Subsystem'
 *    '<S72>/Subsystem'
 *    '<S82>/Subsystem'
 *    '<S92>/Subsystem'
 */
void Estimations_Subsystem(boolean_T rtu_uBlockOrdering, real_T rty_x[3], real_T
  rty_P[9], boolean_T *rty_yBlockOrdering, const real_T rtd_P[9], const real_T
  rtd_x[3])
{
  int16_T i;
  int16_T i_0;
  for (i = 0; i < 3; i++) {
    /* DataStoreRead: '<S16>/Data Store Read' */
    rty_x[i] = rtd_x[i];

    /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
     *  DataStoreRead: '<S16>/Data Store Read1'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rty_P[i + 3 * i_0] = (rtd_P[i + 3] * rtd_P[i_0 + 3] + rtd_P[i] * rtd_P[i_0])
        + rtd_P[i + 6] * rtd_P[i_0 + 6];
    }

    /* End of MATLAB Function: '<S16>/MATLAB Function' */
  }

  /* SignalConversion generated from: '<S16>/uBlockOrdering' */
  *rty_yBlockOrdering = rtu_uBlockOrdering;
}

/* Function for MATLAB Function: '<S14>/Correct' */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn1(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn1(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S24>/Correct' */
static void UKFCorrectorAdditive_getPredi_l(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn2(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn2(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S34>/Correct' */
static void UKFCorrectorAdditive_getPredi_e(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn3(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn3(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S44>/Correct' */
static void UKFCorrectorAdditive_getPredi_f(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn4(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn4(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S54>/Correct' */
static void UKFCorrectorAdditive_getPredi_m(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn5(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn5(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S64>/Correct' */
static void UKFCorrectorAdditive_getPredi_k(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn6(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn6(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S74>/Correct' */
static void UKFCorrectorAdditive_getPred_ly(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn7(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn7(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S84>/Correct' */
static void UKFCorrectorAdditive_getPredi_p(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn8(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn8(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Function for MATLAB Function: '<S94>/Correct' */
static void UKFCorrectorAdditive_getPred_ew(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T X1_0;
  real_T beta1;
  real_T tempY;
  int16_T X2_tmp;
  int16_T knt;
  beta1 = alpha * alpha;
  tempY = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wmean_0 = Wmean[1] / Wmean_0;
    Wmean[1] = Wmean_0;
    Wcov[1] = Wmean_0;
  } else {
    beta1 = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  tempY = X1[0];
  Wmean_0 = X1[1];
  X1_0 = X1[2];
  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += tempY;
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += Wmean_0;
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1_0;
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn9(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn9(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - tempY) + tempY;
  }

  UTMeanCovSqrt_r0lePOnt(Wmean, Wcov, beta1, tempY, Y2_0, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  beta1 = xnrm2_RSYnBhZb(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(*Sy, beta1);
    if (*Sy >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_RSYnBhZb(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Model step function */
void Estimations_step(void)
{
  real_T X2state[18];
  real_T Y2[18];
  real_T tmp[18];
  real_T Pxy_0[9];
  real_T Ss[9];
  real_T rtb_P_ec[9];
  real_T rtb_P_iz[9];
  real_T K[3];
  real_T Pxy[3];
  real_T b_c[3];
  real_T b_s[3];
  real_T s[3];
  real_T Ymean;
  real_T nrmx;
  real_T scale;
  real_T t;
  real_T temp;
  int32_T exitg1;
  int16_T c_j;
  int16_T coffset;
  int16_T i;
  int16_T iAcol;
  boolean_T errorCondition;
  boolean_T exitg2;

  /* Outputs for Enabled SubSystem: '<S12>/Correct1' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  /* MATLAB Function: '<S14>/Correct' incorporates:
   *  Constant: '<S12>/R1'
   *  DataStoreRead: '<S14>/Data Store ReadX'
   *  DataStoreWrite: '<S14>/Data Store WriteP'
   *  Inport: '<Root>/voltage1'
   */
  batteryMeasurementFcn1(Estimations_DW.x);
  UKFCorrectorAdditive_getPredict(0.031622776601683791, Estimations_DW.x,
    Estimations_DW.P, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage1 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P[3 * i] = rtb_P_ec[i];
    Estimations_DW.P[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S14>/Data Store WriteX' */
    Estimations_DW.x[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S14>/Correct' */
  /* End of Outputs for SubSystem: '<S12>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S12>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P,
                        Estimations_DW.x);

  /* End of Outputs for SubSystem: '<S12>/Subsystem' */

  /* Outport: '<Root>/SOC1' */
  Estimations_Y.SOC1 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S12>/Predict' */
  /* MATLAB Function: '<S15>/Predict' incorporates:
   *  Constant: '<S12>/Q'
   *  DataStoreRead: '<S15>/Data Store ReadX'
   *  DataStoreWrite: '<S15>/Data Store WriteP'
   */
  batteryStateFcn1(Estimations_DW.x, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P[i];
    Estimations_DW.P[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x[0];
  temp = Estimations_DW.x[1];
  t = Estimations_DW.x[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn1(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn1(Estimations_DW.x, Pxy);
  Estimations_DW.x[0] = Pxy[0] * 0.0;
  Estimations_DW.x[1] = Pxy[1] * 0.0;
  Estimations_DW.x[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x[0];
  temp = Estimations_DW.x[1];
  t = Estimations_DW.x[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x[2] = t;
  Estimations_DW.x[1] = temp;
  Estimations_DW.x[0] = Ymean;
  Pxy[0] -= Estimations_DW.x[0];
  Pxy[1] -= Estimations_DW.x[1];
  Pxy[2] -= Estimations_DW.x[2];
  Ymean = Estimations_DW.x[0];
  temp = Estimations_DW.x[1];
  t = Estimations_DW.x[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P[i] = 0.0;
  }

  Estimations_DW.P[0] = 1.0;
  Estimations_DW.P[4] = 1.0;
  Estimations_DW.P[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P[c_j + 3];
    temp = Estimations_DW.P[c_j];
    t = Estimations_DW.P[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P[3 * i] = rtb_P_ec[i];
    Estimations_DW.P[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S15>/Predict' */
  /* End of Outputs for SubSystem: '<S12>/Predict' */

  /* Outputs for Enabled SubSystem: '<S22>/Correct1' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  /* MATLAB Function: '<S24>/Correct' incorporates:
   *  Constant: '<S22>/R1'
   *  DataStoreRead: '<S24>/Data Store ReadX'
   *  DataStoreWrite: '<S24>/Data Store WriteP'
   *  Inport: '<Root>/voltage2'
   */
  batteryMeasurementFcn2(Estimations_DW.x_a);
  UKFCorrectorAdditive_getPredi_l(0.031622776601683791, Estimations_DW.x_a,
    Estimations_DW.P_e, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage2 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_e[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_e[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_e[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_e[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_e[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_e[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S24>/Data Store WriteX' */
    Estimations_DW.x_a[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S24>/Correct' */
  /* End of Outputs for SubSystem: '<S22>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S22>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P_e,
                        Estimations_DW.x_a);

  /* End of Outputs for SubSystem: '<S22>/Subsystem' */

  /* Outport: '<Root>/SOC2' */
  Estimations_Y.SOC2 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S22>/Predict' */
  /* MATLAB Function: '<S25>/Predict' incorporates:
   *  Constant: '<S22>/Q'
   *  DataStoreRead: '<S25>/Data Store ReadX'
   *  DataStoreWrite: '<S25>/Data Store WriteP'
   */
  batteryStateFcn2(Estimations_DW.x_a, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_e[i];
    Estimations_DW.P_e[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_a[0];
  temp = Estimations_DW.x_a[1];
  t = Estimations_DW.x_a[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn2(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn2(Estimations_DW.x_a, Pxy);
  Estimations_DW.x_a[0] = Pxy[0] * 0.0;
  Estimations_DW.x_a[1] = Pxy[1] * 0.0;
  Estimations_DW.x_a[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_a[0];
  temp = Estimations_DW.x_a[1];
  t = Estimations_DW.x_a[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_a[2] = t;
  Estimations_DW.x_a[1] = temp;
  Estimations_DW.x_a[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_a[0];
  Pxy[1] -= Estimations_DW.x_a[1];
  Pxy[2] -= Estimations_DW.x_a[2];
  Ymean = Estimations_DW.x_a[0];
  temp = Estimations_DW.x_a[1];
  t = Estimations_DW.x_a[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_e[i] = 0.0;
  }

  Estimations_DW.P_e[0] = 1.0;
  Estimations_DW.P_e[4] = 1.0;
  Estimations_DW.P_e[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_e[c_j + 3];
    temp = Estimations_DW.P_e[c_j];
    t = Estimations_DW.P_e[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_p[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_p[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_p[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_e[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_e[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_e[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S25>/Predict' */
  /* End of Outputs for SubSystem: '<S22>/Predict' */

  /* Outputs for Enabled SubSystem: '<S32>/Correct1' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  /* MATLAB Function: '<S34>/Correct' incorporates:
   *  Constant: '<S32>/R1'
   *  DataStoreRead: '<S34>/Data Store ReadX'
   *  DataStoreWrite: '<S34>/Data Store WriteP'
   *  Inport: '<Root>/voltage3'
   */
  batteryMeasurementFcn3(Estimations_DW.x_av);
  UKFCorrectorAdditive_getPredi_e(0.031622776601683791, Estimations_DW.x_av,
    Estimations_DW.P_i, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage3 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_i[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_i[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_i[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_i[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_i[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_i[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S34>/Data Store WriteX' */
    Estimations_DW.x_av[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S34>/Correct' */
  /* End of Outputs for SubSystem: '<S32>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S32>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P_i,
                        Estimations_DW.x_av);

  /* End of Outputs for SubSystem: '<S32>/Subsystem' */

  /* Outport: '<Root>/SOC3' */
  Estimations_Y.SOC3 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S32>/Predict' */
  /* MATLAB Function: '<S35>/Predict' incorporates:
   *  Constant: '<S32>/Q'
   *  DataStoreRead: '<S35>/Data Store ReadX'
   *  DataStoreWrite: '<S35>/Data Store WriteP'
   */
  batteryStateFcn3(Estimations_DW.x_av, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_i[i];
    Estimations_DW.P_i[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_av[0];
  temp = Estimations_DW.x_av[1];
  t = Estimations_DW.x_av[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn3(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn3(Estimations_DW.x_av, Pxy);
  Estimations_DW.x_av[0] = Pxy[0] * 0.0;
  Estimations_DW.x_av[1] = Pxy[1] * 0.0;
  Estimations_DW.x_av[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_av[0];
  temp = Estimations_DW.x_av[1];
  t = Estimations_DW.x_av[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_av[2] = t;
  Estimations_DW.x_av[1] = temp;
  Estimations_DW.x_av[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_av[0];
  Pxy[1] -= Estimations_DW.x_av[1];
  Pxy[2] -= Estimations_DW.x_av[2];
  Ymean = Estimations_DW.x_av[0];
  temp = Estimations_DW.x_av[1];
  t = Estimations_DW.x_av[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_i[i] = 0.0;
  }

  Estimations_DW.P_i[0] = 1.0;
  Estimations_DW.P_i[4] = 1.0;
  Estimations_DW.P_i[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_i[c_j + 3];
    temp = Estimations_DW.P_i[c_j];
    t = Estimations_DW.P_i[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_n[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_n[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_n[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_i[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_i[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_i[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S35>/Predict' */
  /* End of Outputs for SubSystem: '<S32>/Predict' */

  /* Outputs for Enabled SubSystem: '<S42>/Correct1' incorporates:
   *  EnablePort: '<S44>/Enable'
   */
  /* MATLAB Function: '<S44>/Correct' incorporates:
   *  Constant: '<S42>/R1'
   *  DataStoreRead: '<S44>/Data Store ReadX'
   *  DataStoreWrite: '<S44>/Data Store WriteP'
   *  Inport: '<Root>/voltage4'
   */
  batteryMeasurementFcn4(Estimations_DW.x_n);
  UKFCorrectorAdditive_getPredi_f(0.031622776601683791, Estimations_DW.x_n,
    Estimations_DW.P_p, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage4 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_p[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_p[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_p[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_p[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_p[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_p[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S44>/Data Store WriteX' */
    Estimations_DW.x_n[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S44>/Correct' */
  /* End of Outputs for SubSystem: '<S42>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S42>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P_p,
                        Estimations_DW.x_n);

  /* End of Outputs for SubSystem: '<S42>/Subsystem' */

  /* Outport: '<Root>/SOC4' */
  Estimations_Y.SOC4 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S42>/Predict' */
  /* MATLAB Function: '<S45>/Predict' incorporates:
   *  Constant: '<S42>/Q'
   *  DataStoreRead: '<S45>/Data Store ReadX'
   *  DataStoreWrite: '<S45>/Data Store WriteP'
   */
  batteryStateFcn4(Estimations_DW.x_n, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_p[i];
    Estimations_DW.P_p[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_n[0];
  temp = Estimations_DW.x_n[1];
  t = Estimations_DW.x_n[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn4(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn4(Estimations_DW.x_n, Pxy);
  Estimations_DW.x_n[0] = Pxy[0] * 0.0;
  Estimations_DW.x_n[1] = Pxy[1] * 0.0;
  Estimations_DW.x_n[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_n[0];
  temp = Estimations_DW.x_n[1];
  t = Estimations_DW.x_n[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_n[2] = t;
  Estimations_DW.x_n[1] = temp;
  Estimations_DW.x_n[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_n[0];
  Pxy[1] -= Estimations_DW.x_n[1];
  Pxy[2] -= Estimations_DW.x_n[2];
  Ymean = Estimations_DW.x_n[0];
  temp = Estimations_DW.x_n[1];
  t = Estimations_DW.x_n[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_p[i] = 0.0;
  }

  Estimations_DW.P_p[0] = 1.0;
  Estimations_DW.P_p[4] = 1.0;
  Estimations_DW.P_p[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_p[c_j + 3];
    temp = Estimations_DW.P_p[c_j];
    t = Estimations_DW.P_p[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_nq[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_nq[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_nq[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_p[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_p[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_p[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S45>/Predict' */
  /* End of Outputs for SubSystem: '<S42>/Predict' */

  /* Outputs for Enabled SubSystem: '<S52>/Correct1' incorporates:
   *  EnablePort: '<S54>/Enable'
   */
  /* MATLAB Function: '<S54>/Correct' incorporates:
   *  Constant: '<S52>/R1'
   *  DataStoreRead: '<S54>/Data Store ReadX'
   *  DataStoreWrite: '<S54>/Data Store WriteP'
   *  Inport: '<Root>/voltage5'
   */
  batteryMeasurementFcn5(Estimations_DW.x_d);
  UKFCorrectorAdditive_getPredi_m(0.031622776601683791, Estimations_DW.x_d,
    Estimations_DW.P_in, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage5 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_in[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_in[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_in[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_in[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_in[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_in[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S54>/Data Store WriteX' */
    Estimations_DW.x_d[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S54>/Correct' */
  /* End of Outputs for SubSystem: '<S52>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S52>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition,
                        Estimations_DW.P_in, Estimations_DW.x_d);

  /* End of Outputs for SubSystem: '<S52>/Subsystem' */

  /* Outport: '<Root>/SOC5' */
  Estimations_Y.SOC5 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S52>/Predict' */
  /* MATLAB Function: '<S55>/Predict' incorporates:
   *  Constant: '<S52>/Q'
   *  DataStoreRead: '<S55>/Data Store ReadX'
   *  DataStoreWrite: '<S55>/Data Store WriteP'
   */
  batteryStateFcn5(Estimations_DW.x_d, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_in[i];
    Estimations_DW.P_in[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_d[0];
  temp = Estimations_DW.x_d[1];
  t = Estimations_DW.x_d[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn5(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn5(Estimations_DW.x_d, Pxy);
  Estimations_DW.x_d[0] = Pxy[0] * 0.0;
  Estimations_DW.x_d[1] = Pxy[1] * 0.0;
  Estimations_DW.x_d[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_d[0];
  temp = Estimations_DW.x_d[1];
  t = Estimations_DW.x_d[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_d[2] = t;
  Estimations_DW.x_d[1] = temp;
  Estimations_DW.x_d[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_d[0];
  Pxy[1] -= Estimations_DW.x_d[1];
  Pxy[2] -= Estimations_DW.x_d[2];
  Ymean = Estimations_DW.x_d[0];
  temp = Estimations_DW.x_d[1];
  t = Estimations_DW.x_d[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_in[i] = 0.0;
  }

  Estimations_DW.P_in[0] = 1.0;
  Estimations_DW.P_in[4] = 1.0;
  Estimations_DW.P_in[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_in[c_j + 3];
    temp = Estimations_DW.P_in[c_j];
    t = Estimations_DW.P_in[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_p4[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_p4[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_p4[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_in[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_in[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_in[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S55>/Predict' */
  /* End of Outputs for SubSystem: '<S52>/Predict' */

  /* Outputs for Enabled SubSystem: '<S62>/Correct1' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  /* MATLAB Function: '<S64>/Correct' incorporates:
   *  Constant: '<S62>/R1'
   *  DataStoreRead: '<S64>/Data Store ReadX'
   *  DataStoreWrite: '<S64>/Data Store WriteP'
   *  Inport: '<Root>/voltage6'
   */
  batteryMeasurementFcn6(Estimations_DW.x_m);
  UKFCorrectorAdditive_getPredi_k(0.031622776601683791, Estimations_DW.x_m,
    Estimations_DW.P_k, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage6 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_k[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_k[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_k[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_k[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_k[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_k[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S64>/Data Store WriteX' */
    Estimations_DW.x_m[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S64>/Correct' */
  /* End of Outputs for SubSystem: '<S62>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S62>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P_k,
                        Estimations_DW.x_m);

  /* End of Outputs for SubSystem: '<S62>/Subsystem' */

  /* Outport: '<Root>/SOC6' */
  Estimations_Y.SOC6 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S62>/Predict' */
  /* MATLAB Function: '<S65>/Predict' incorporates:
   *  Constant: '<S62>/Q'
   *  DataStoreRead: '<S65>/Data Store ReadX'
   *  DataStoreWrite: '<S65>/Data Store WriteP'
   */
  batteryStateFcn6(Estimations_DW.x_m, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_k[i];
    Estimations_DW.P_k[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_m[0];
  temp = Estimations_DW.x_m[1];
  t = Estimations_DW.x_m[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn6(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn6(Estimations_DW.x_m, Pxy);
  Estimations_DW.x_m[0] = Pxy[0] * 0.0;
  Estimations_DW.x_m[1] = Pxy[1] * 0.0;
  Estimations_DW.x_m[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_m[0];
  temp = Estimations_DW.x_m[1];
  t = Estimations_DW.x_m[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_m[2] = t;
  Estimations_DW.x_m[1] = temp;
  Estimations_DW.x_m[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_m[0];
  Pxy[1] -= Estimations_DW.x_m[1];
  Pxy[2] -= Estimations_DW.x_m[2];
  Ymean = Estimations_DW.x_m[0];
  temp = Estimations_DW.x_m[1];
  t = Estimations_DW.x_m[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_k[i] = 0.0;
  }

  Estimations_DW.P_k[0] = 1.0;
  Estimations_DW.P_k[4] = 1.0;
  Estimations_DW.P_k[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_k[c_j + 3];
    temp = Estimations_DW.P_k[c_j];
    t = Estimations_DW.P_k[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_b[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_b[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_b[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_k[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_k[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_k[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S65>/Predict' */
  /* End of Outputs for SubSystem: '<S62>/Predict' */

  /* Outputs for Enabled SubSystem: '<S72>/Correct1' incorporates:
   *  EnablePort: '<S74>/Enable'
   */
  /* MATLAB Function: '<S74>/Correct' incorporates:
   *  Constant: '<S72>/R1'
   *  DataStoreRead: '<S74>/Data Store ReadX'
   *  DataStoreWrite: '<S74>/Data Store WriteP'
   *  Inport: '<Root>/voltage7'
   */
  batteryMeasurementFcn7(Estimations_DW.x_j);
  UKFCorrectorAdditive_getPred_ly(0.031622776601683791, Estimations_DW.x_j,
    Estimations_DW.P_in1, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage7 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_in1[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_in1[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_in1[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_in1[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_in1[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_in1[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S74>/Data Store WriteX' */
    Estimations_DW.x_j[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S74>/Correct' */
  /* End of Outputs for SubSystem: '<S72>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S72>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition,
                        Estimations_DW.P_in1, Estimations_DW.x_j);

  /* End of Outputs for SubSystem: '<S72>/Subsystem' */

  /* Outport: '<Root>/SOC7' */
  Estimations_Y.SOC7 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S72>/Predict' */
  /* MATLAB Function: '<S75>/Predict' incorporates:
   *  Constant: '<S72>/Q'
   *  DataStoreRead: '<S75>/Data Store ReadX'
   *  DataStoreWrite: '<S75>/Data Store WriteP'
   */
  batteryStateFcn7(Estimations_DW.x_j, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_in1[i];
    Estimations_DW.P_in1[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_j[0];
  temp = Estimations_DW.x_j[1];
  t = Estimations_DW.x_j[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn7(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn7(Estimations_DW.x_j, Pxy);
  Estimations_DW.x_j[0] = Pxy[0] * 0.0;
  Estimations_DW.x_j[1] = Pxy[1] * 0.0;
  Estimations_DW.x_j[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_j[0];
  temp = Estimations_DW.x_j[1];
  t = Estimations_DW.x_j[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_j[2] = t;
  Estimations_DW.x_j[1] = temp;
  Estimations_DW.x_j[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_j[0];
  Pxy[1] -= Estimations_DW.x_j[1];
  Pxy[2] -= Estimations_DW.x_j[2];
  Ymean = Estimations_DW.x_j[0];
  temp = Estimations_DW.x_j[1];
  t = Estimations_DW.x_j[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_in1[i] = 0.0;
  }

  Estimations_DW.P_in1[0] = 1.0;
  Estimations_DW.P_in1[4] = 1.0;
  Estimations_DW.P_in1[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_in1[c_j + 3];
    temp = Estimations_DW.P_in1[c_j];
    t = Estimations_DW.P_in1[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_n4[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_n4[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_n4[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_in1[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_in1[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_in1[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S75>/Predict' */
  /* End of Outputs for SubSystem: '<S72>/Predict' */

  /* Outputs for Enabled SubSystem: '<S82>/Correct1' incorporates:
   *  EnablePort: '<S84>/Enable'
   */
  /* MATLAB Function: '<S84>/Correct' incorporates:
   *  Constant: '<S82>/R1'
   *  DataStoreRead: '<S84>/Data Store ReadX'
   *  DataStoreWrite: '<S84>/Data Store WriteP'
   *  Inport: '<Root>/voltage8'
   */
  batteryMeasurementFcn8(Estimations_DW.x_e);
  UKFCorrectorAdditive_getPredi_p(0.031622776601683791, Estimations_DW.x_e,
    Estimations_DW.P_j, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage8 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_j[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_j[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_j[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_j[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_j[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_j[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S84>/Data Store WriteX' */
    Estimations_DW.x_e[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S84>/Correct' */
  /* End of Outputs for SubSystem: '<S82>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S82>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P_j,
                        Estimations_DW.x_e);

  /* End of Outputs for SubSystem: '<S82>/Subsystem' */

  /* Outport: '<Root>/SOC8' */
  Estimations_Y.SOC8 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S82>/Predict' */
  /* MATLAB Function: '<S85>/Predict' incorporates:
   *  Constant: '<S82>/Q'
   *  DataStoreRead: '<S85>/Data Store ReadX'
   *  DataStoreWrite: '<S85>/Data Store WriteP'
   */
  batteryStateFcn8(Estimations_DW.x_e, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_j[i];
    Estimations_DW.P_j[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_e[0];
  temp = Estimations_DW.x_e[1];
  t = Estimations_DW.x_e[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn8(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn8(Estimations_DW.x_e, Pxy);
  Estimations_DW.x_e[0] = Pxy[0] * 0.0;
  Estimations_DW.x_e[1] = Pxy[1] * 0.0;
  Estimations_DW.x_e[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_e[0];
  temp = Estimations_DW.x_e[1];
  t = Estimations_DW.x_e[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_e[2] = t;
  Estimations_DW.x_e[1] = temp;
  Estimations_DW.x_e[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_e[0];
  Pxy[1] -= Estimations_DW.x_e[1];
  Pxy[2] -= Estimations_DW.x_e[2];
  Ymean = Estimations_DW.x_e[0];
  temp = Estimations_DW.x_e[1];
  t = Estimations_DW.x_e[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_j[i] = 0.0;
  }

  Estimations_DW.P_j[0] = 1.0;
  Estimations_DW.P_j[4] = 1.0;
  Estimations_DW.P_j[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_j[c_j + 3];
    temp = Estimations_DW.P_j[c_j];
    t = Estimations_DW.P_j[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_h[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_h[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_h[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_j[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_j[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_j[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S85>/Predict' */
  /* End of Outputs for SubSystem: '<S82>/Predict' */

  /* Outputs for Enabled SubSystem: '<S92>/Correct1' incorporates:
   *  EnablePort: '<S94>/Enable'
   */
  /* MATLAB Function: '<S94>/Correct' incorporates:
   *  Constant: '<S92>/R1'
   *  DataStoreRead: '<S94>/Data Store ReadX'
   *  DataStoreWrite: '<S94>/Data Store WriteP'
   *  Inport: '<Root>/voltage9'
   */
  batteryMeasurementFcn9(Estimations_DW.x_l);
  UKFCorrectorAdditive_getPred_ew(0.031622776601683791, Estimations_DW.x_l,
    Estimations_DW.P_d, 1.0, 2.0, 0.0, &Ymean, Pxy, &temp);
  Ymean = Estimations_U.voltage9 - Ymean;
  for (c_j = 0; c_j < 3; c_j++) {
    rtb_P_ec[3 * c_j] = Estimations_DW.P_d[c_j];
    rtb_P_ec[3 * c_j + 1] = Estimations_DW.P_d[c_j + 3];
    rtb_P_ec[3 * c_j + 2] = Estimations_DW.P_d[c_j + 6];
    b_s[c_j] = Pxy[c_j];
  }

  trisolve_9qKJiUg8(temp, b_s);
  K[0] = b_s[0];
  K[1] = b_s[1];
  K[2] = b_s[2];
  trisolve_9qKJiUg8(temp, K);
  for (c_j = 0; c_j < 3; c_j++) {
    Pxy[c_j] = K[c_j] * temp;
    if (1 - c_j >= 0) {
      memset(&rtb_P_ec[(c_j << 2) + 1], 0, (uint16_T)((1 - c_j) + 1) * sizeof
             (real_T));
    }
  }

  c_j = 0;
  errorCondition = (rtb_P_ec[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (rtb_P_ec[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (rtb_P_ec[8] == 0.0);
  }

  if (errorCondition) {
    c_j = 2;
  } else {
    b_s[0] = Pxy[0];
    b_s[1] = Pxy[1];
    b_s[2] = Pxy[2];
    nrmx = 0.0;
    scale = 3.3121686421112381E-170;
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = b_s[i];
      for (coffset = 0; coffset < i; coffset++) {
        temp -= rtb_P_ec[coffset + iAcol] * b_s[coffset];
      }

      temp /= rtb_P_ec[i + iAcol];
      b_s[i] = temp;
      temp = fabs(temp);
      if (temp > scale) {
        t = scale / temp;
        nrmx = nrmx * t * t + 1.0;
        scale = temp;
      } else {
        t = temp / scale;
        nrmx += t * t;
      }
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      c_j = 1;
    } else {
      rotate_07DDyFSo(sqrt(1.0 - nrmx * nrmx), b_s[2], &b_c[2], &s[2], &temp);
      b_s[2] = 0.0;
      rotate_07DDyFSo(temp, b_s[1], &b_c[1], &s[1], &temp);
      b_s[1] = 0.0;
      rotate_07DDyFSo(temp, b_s[0], &b_c[0], &s[0], &temp);
      b_s[0] = 0.0;
      for (coffset = 0; coffset < 3; coffset++) {
        for (i = coffset + 1; i >= 1; i--) {
          t = s[i - 1];
          iAcol = (3 * coffset + i) - 1;
          nrmx = rtb_P_ec[iAcol];
          scale = b_c[i - 1];
          temp = b_s[coffset];
          rtb_P_ec[iAcol] = scale * nrmx - t * temp;
          b_s[coffset] = scale * temp + t * nrmx;
        }
      }
    }
  }

  if (c_j != 0) {
    for (i = 0; i < 3; i++) {
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_iz[i + 3 * c_j] = (rtb_P_ec[3 * i + 1] * rtb_P_ec[3 * c_j + 1] +
          rtb_P_ec[3 * i] * rtb_P_ec[3 * c_j]) + rtb_P_ec[3 * i + 2] * rtb_P_ec
          [3 * c_j + 2];
        Pxy_0[c_j + 3 * i] = Pxy[c_j] * Pxy[i];
      }
    }

    errorCondition = true;
    for (c_j = 0; c_j < 9; c_j++) {
      temp = rtb_P_iz[c_j] - Pxy_0[c_j];
      Ss[c_j] = temp;
      if (errorCondition && (rtIsInf_est(temp) || rtIsNaN_est(temp))) {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      svd_wEmXrMkt(Ss, Pxy_0, s, rtb_P_iz);
    } else {
      s[0] = (rtNaN_est);
      s[1] = (rtNaN_est);
      s[2] = (rtNaN_est);
      for (i = 0; i < 9; i++) {
        rtb_P_iz[i] = (rtNaN_est);
      }
    }

    for (i = 0; i < 9; i++) {
      Ss[i] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (c_j = 0; c_j < 9; c_j++) {
      Ss[c_j] = sqrt(Ss[c_j]);
    }

    for (i = 0; i < 3; i++) {
      temp = Ss[3 * i + 1];
      t = Ss[3 * i];
      nrmx = Ss[3 * i + 2];
      for (c_j = 0; c_j < 3; c_j++) {
        rtb_P_ec[i + 3 * c_j] = (rtb_P_iz[c_j + 3] * temp + t * rtb_P_iz[c_j]) +
          rtb_P_iz[c_j + 6] * nrmx;
      }
    }

    errorCondition = true;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 3)) {
      c_j = i + 1;
      do {
        exitg1 = 0L;
        if (c_j + 1 < 4) {
          if (!(rtb_P_ec[3 * i + c_j] == 0.0)) {
            errorCondition = false;
            exitg1 = 1L;
          } else {
            c_j++;
          }
        } else {
          i++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      for (c_j = 0; c_j < 9; c_j++) {
        rtb_P_iz[c_j] = rtb_P_ec[c_j];
      }

      qr_hNO30LFA(rtb_P_iz, Pxy_0, rtb_P_ec);
    }
  }

  for (i = 0; i < 3; i++) {
    Estimations_DW.P_d[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_d[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_d[3 * i + 2] = rtb_P_ec[i + 6];

    /* DataStoreWrite: '<S94>/Data Store WriteX' */
    Estimations_DW.x_l[i] += K[i] * Ymean;
  }

  /* End of MATLAB Function: '<S94>/Correct' */
  /* End of Outputs for SubSystem: '<S92>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S92>/Subsystem' */
  Estimations_Subsystem(true, b_c, rtb_P_ec, &errorCondition, Estimations_DW.P_d,
                        Estimations_DW.x_l);

  /* End of Outputs for SubSystem: '<S92>/Subsystem' */

  /* Outport: '<Root>/SOC9' */
  Estimations_Y.SOC9 = b_c[0];

  /* Outputs for Atomic SubSystem: '<S92>/Predict' */
  /* MATLAB Function: '<S95>/Predict' incorporates:
   *  Constant: '<S92>/Q'
   *  DataStoreRead: '<S95>/Data Store ReadX'
   *  DataStoreWrite: '<S95>/Data Store WriteP'
   */
  batteryStateFcn9(Estimations_DW.x_l, b_c);
  for (i = 0; i < 9; i++) {
    Ymean = 1.7320508075688772 * Estimations_DW.P_d[i];
    Estimations_DW.P_d[i] = Ymean;
    X2state[i] = Ymean;
    X2state[i + 9] = -Ymean;
  }

  Ymean = Estimations_DW.x_l[0];
  temp = Estimations_DW.x_l[1];
  t = Estimations_DW.x_l[2];
  for (c_j = 0; c_j < 6; c_j++) {
    X2state[3 * c_j] += Ymean;
    i = 3 * c_j + 1;
    X2state[i] += temp;
    i = 3 * c_j + 2;
    X2state[i] += t;
  }

  for (c_j = 0; c_j < 6; c_j++) {
    batteryStateFcn9(&X2state[3 * c_j], &Y2[3 * c_j]);
  }

  batteryStateFcn9(Estimations_DW.x_l, Pxy);
  Estimations_DW.x_l[0] = Pxy[0] * 0.0;
  Estimations_DW.x_l[1] = Pxy[1] * 0.0;
  Estimations_DW.x_l[2] = Pxy[2] * 0.0;
  Ymean = Estimations_DW.x_l[0];
  temp = Estimations_DW.x_l[1];
  t = Estimations_DW.x_l[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Ymean += Y2[3 * c_j] * 0.16666666666666666;
    temp += Y2[3 * c_j + 1] * 0.16666666666666666;
    t += Y2[3 * c_j + 2] * 0.16666666666666666;
  }

  Estimations_DW.x_l[2] = t;
  Estimations_DW.x_l[1] = temp;
  Estimations_DW.x_l[0] = Ymean;
  Pxy[0] -= Estimations_DW.x_l[0];
  Pxy[1] -= Estimations_DW.x_l[1];
  Pxy[2] -= Estimations_DW.x_l[2];
  Ymean = Estimations_DW.x_l[0];
  temp = Estimations_DW.x_l[1];
  t = Estimations_DW.x_l[2];
  for (c_j = 0; c_j < 6; c_j++) {
    Y2[3 * c_j] -= Ymean;
    i = 3 * c_j + 1;
    Y2[i] -= temp;
    i = 3 * c_j + 2;
    Y2[i] -= t;
  }

  for (i = 0; i < 3; i++) {
    for (c_j = 0; c_j < 6; c_j++) {
      tmp[c_j + 6 * i] = Y2[3 * c_j + i] * 0.408248290463863;
    }
  }

  qr_GQsCMm2I(tmp, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    if (1 - i >= 0) {
      memset(&rtb_P_ec[(i << 2) + 1], 0, (uint16_T)((1 - i) + 1) * sizeof(real_T));
    }

    b_c[i] = 0.0;
    b_s[i] = 0.0;
  }

  rotate_07DDyFSo(rtb_P_ec[0], Pxy[0], &b_c[0], &b_s[0], &rtb_P_ec[0]);
  for (c_j = 0; c_j < 2; c_j++) {
    t = Pxy[c_j + 1];
    for (i = 0; i <= c_j; i++) {
      temp = b_s[i];
      Ymean = temp * t;
      scale = b_c[i];
      iAcol = (c_j + 1) * 3 + i;
      nrmx = rtb_P_ec[iAcol];
      t = scale * t - temp * nrmx;
      rtb_P_ec[iAcol] = scale * nrmx + Ymean;
    }

    i = ((c_j + 1) * 3 + c_j) + 1;
    rotate_07DDyFSo(rtb_P_ec[i], t, &b_c[c_j + 1], &b_s[c_j + 1], &rtb_P_ec[i]);
  }

  for (i = 0; i < 3; i++) {
    rtb_P_iz[3 * i] = rtb_P_ec[i];
    rtb_P_iz[3 * i + 1] = rtb_P_ec[i + 3];
    rtb_P_iz[3 * i + 2] = rtb_P_ec[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_P_ec[i] = rtb_P_iz[i];
    Estimations_DW.P_d[i] = 0.0;
  }

  Estimations_DW.P_d[0] = 1.0;
  Estimations_DW.P_d[4] = 1.0;
  Estimations_DW.P_d[8] = 1.0;
  for (c_j = 0; c_j < 3; c_j++) {
    coffset = c_j * 3;
    Ymean = Estimations_DW.P_d[c_j + 3];
    temp = Estimations_DW.P_d[c_j];
    t = Estimations_DW.P_d[c_j + 6];
    for (i = 0; i < 3; i++) {
      iAcol = i * 3;
      Ss[coffset + i] = (rtb_P_ec[iAcol + 1] * (real_T)(int16_T)Ymean +
                         rtb_P_ec[iAcol] * (real_T)(int16_T)temp) +
        rtb_P_ec[iAcol + 2] * (real_T)(int16_T)t;
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = Ss[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value_a[i];
    Y2[6 * i + 1] = Ss[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value_a[i + 3];
    Y2[6 * i + 2] = Ss[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value_a[i + 6];
  }

  qr_GQsCMm2I(Y2, X2state, rtb_P_ec);
  for (i = 0; i < 3; i++) {
    Estimations_DW.P_d[3 * i] = rtb_P_ec[i];
    Estimations_DW.P_d[3 * i + 1] = rtb_P_ec[i + 3];
    Estimations_DW.P_d[3 * i + 2] = rtb_P_ec[i + 6];
  }

  /* End of MATLAB Function: '<S95>/Predict' */
  /* End of Outputs for SubSystem: '<S92>/Predict' */
}

/* Model initialize function */
void Estimations_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int16_T i;

    /* Start for DataStoreMemory: '<S12>/DataStoreMemory - x' */
    Estimations_DW.x[0] = 0.5;
    Estimations_DW.x[1] = 0.0;
    Estimations_DW.x[2] = 0.01;

    /* Start for DataStoreMemory: '<S22>/DataStoreMemory - x' */
    Estimations_DW.x_a[0] = 0.5;
    Estimations_DW.x_a[1] = 0.0;
    Estimations_DW.x_a[2] = 0.01;

    /* Start for DataStoreMemory: '<S32>/DataStoreMemory - x' */
    Estimations_DW.x_av[0] = 0.5;
    Estimations_DW.x_av[1] = 0.0;
    Estimations_DW.x_av[2] = 0.01;

    /* Start for DataStoreMemory: '<S42>/DataStoreMemory - x' */
    Estimations_DW.x_n[0] = 0.5;
    Estimations_DW.x_n[1] = 0.0;
    Estimations_DW.x_n[2] = 0.01;

    /* Start for DataStoreMemory: '<S52>/DataStoreMemory - x' */
    Estimations_DW.x_d[0] = 0.5;
    Estimations_DW.x_d[1] = 0.0;
    Estimations_DW.x_d[2] = 0.01;

    /* Start for DataStoreMemory: '<S62>/DataStoreMemory - x' */
    Estimations_DW.x_m[0] = 0.5;
    Estimations_DW.x_m[1] = 0.0;
    Estimations_DW.x_m[2] = 0.01;

    /* Start for DataStoreMemory: '<S72>/DataStoreMemory - x' */
    Estimations_DW.x_j[0] = 0.5;
    Estimations_DW.x_j[1] = 0.0;
    Estimations_DW.x_j[2] = 0.01;

    /* Start for DataStoreMemory: '<S82>/DataStoreMemory - x' */
    Estimations_DW.x_e[0] = 0.5;
    Estimations_DW.x_e[1] = 0.0;
    Estimations_DW.x_e[2] = 0.01;
    for (i = 0; i < 9; i++) {
      /* Start for DataStoreMemory: '<S12>/DataStoreMemory - P' */
      Estimations_DW.P[i] = rtCP_DataStoreMemoryP_InitialVa[i];

      /* Start for DataStoreMemory: '<S22>/DataStoreMemory - P' */
      Estimations_DW.P_e[i] = rtCP_DataStoreMemoryP_Initial_j[i];

      /* Start for DataStoreMemory: '<S32>/DataStoreMemory - P' */
      Estimations_DW.P_i[i] = rtCP_DataStoreMemoryP_Initial_b[i];

      /* Start for DataStoreMemory: '<S42>/DataStoreMemory - P' */
      Estimations_DW.P_p[i] = rtCP_DataStoreMemoryP_Initial_d[i];

      /* Start for DataStoreMemory: '<S52>/DataStoreMemory - P' */
      Estimations_DW.P_in[i] = rtCP_DataStoreMemoryP_Initial_f[i];

      /* Start for DataStoreMemory: '<S62>/DataStoreMemory - P' */
      Estimations_DW.P_k[i] = rtCP_DataStoreMemoryP_Initial_c[i];

      /* Start for DataStoreMemory: '<S72>/DataStoreMemory - P' */
      Estimations_DW.P_in1[i] = rtCP_DataStoreMemoryP_Initia_bi[i];

      /* Start for DataStoreMemory: '<S82>/DataStoreMemory - P' */
      Estimations_DW.P_j[i] = rtCP_DataStoreMemoryP_Initial_m[i];

      /* Start for DataStoreMemory: '<S92>/DataStoreMemory - P' */
      Estimations_DW.P_d[i] = rtCP_DataStoreMemoryP_Initial_h[i];
    }

    /* Start for DataStoreMemory: '<S92>/DataStoreMemory - x' */
    Estimations_DW.x_l[0] = 0.5;
    Estimations_DW.x_l[1] = 0.0;
    Estimations_DW.x_l[2] = 0.01;
  }
}

/* Model terminate function */
void Estimations_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
