/*
 * File: Estimations.c
 *
 * Code generated for Simulink model 'Estimations'.
 *
 * Model version                  : 1.373
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed May 11 15:23:20 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Estimations.h"
#include "Estimations_private.h"
#include "UTMeanCovSqrt_tkXBHSqd.h"
#include "UTMeanCovSqrt_y0CmrahB.h"
#include "qr_284JFiJs.h"
#include "qr_sQLXF2xn.h"
#include "rotate_h3nP3JUD.h"
#include "rt_hypotd_snf.h"
#include "svd_pFhYsdaI.h"
#include "trisolve_1hqRQ712.h"
#include "xnrm2_jKc60KuO.h"

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

/* Function for MATLAB Function: '<S5>/Correct' */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T tempY;
  real_T xnorm;
  int16_T X2_tmp;
  int16_T knt;
  xnorm = alpha * alpha;
  tempY = xnorm * (kappa + 3.0);
  Wmean[0] = 1.0 - 3.0 / tempY;
  Wmean[1] = 1.0 / (2.0 * tempY);
  Wcov[0] = ((1.0 - xnorm) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    xnorm = Wmean[0];
    Wmean_0 = Wmean[0];
    Wcov[0] /= Wmean[0];
    Wmean[0] /= Wmean[0];
    Wmean[1] /= Wmean_0;
    Wcov[1] /= xnorm;
  } else {
    xnorm = 1.0;
  }

  tempY = sqrt(tempY);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = tempY * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += X1[0];
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += X1[1];
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1[2];
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn1(&X2[3 * knt]);
  }

  tempY = batteryMeasurementFcn1(X1);
  UTMeanCovSqrt_y0CmrahB(Wmean, Wcov, xnorm, tempY, Y2, X1, X2, Ymean, Sy, Pxy);
  Wmean[0] = *Sy;
  Wmean[1] = Rs;
  xnorm = xnrm2_jKc60KuO(1, Wmean, 2);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(*Sy, xnorm);
    if (*Sy >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-35) {
      knt = -1;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+35;
        xnorm *= 9.9792015476736E+35;
        *Sy *= 9.9792015476736E+35;
      } while (!(fabs(xnorm) >= 1.0020841800044864E-35));

      xnorm = rt_hypotd_snf(*Sy, xnrm2_jKc60KuO(1, Wmean, 2));
      if (*Sy >= 0.0) {
        xnorm = -xnorm;
      }

      for (X2_tmp = 0; X2_tmp <= knt; X2_tmp++) {
        xnorm *= 1.0020841800044864E-35;
      }

      *Sy = xnorm;
    } else {
      *Sy = xnorm;
    }
  }
}

/* Model step function */
void Estimations_step(void)
{
  static const real_T Wcov[2] = { 2.0, 0.16666666666666666 };

  real_T X2state[18];
  real_T Y2[18];
  real_T R[9];
  real_T Ss[9];
  real_T unusedU0[9];
  real_T C[3];
  real_T U[3];
  real_T c[3];
  real_T rtb_DataStoreRead[3];
  real_T s[3];
  real_T Wcov_0[2];
  real_T tmp[2];
  real_T absxk;
  real_T nrmx;
  real_T residual;
  real_T scale;
  real_T t;
  int32_T exitg1;
  int16_T b_I[9];
  int16_T aoffset;
  int16_T coffset;
  int16_T i;
  int16_T j;
  boolean_T exitg2;
  boolean_T p;

  /* Outputs for Enabled SubSystem: '<S3>/Correct1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* MATLAB Function: '<S5>/Correct' incorporates:
   *  Constant: '<S3>/R1'
   *  DataStoreRead: '<S5>/Data Store ReadX'
   *  DataStoreWrite: '<S5>/Data Store WriteP'
   *  Inport: '<Root>/voltage'
   */
  for (j = 0; j < 9; j++) {
    Ss[j] = Estimations_DW.P[j];
  }

  p = true;
  j = 0;
  exitg2 = false;
  while ((!exitg2) && (j < 3)) {
    i = 0;
    do {
      exitg1 = 0L;
      if (i <= j - 1) {
        if (!(Estimations_DW.P[3 * j + i] == 0.0)) {
          p = false;
          exitg1 = 1L;
        } else {
          i++;
        }
      } else {
        j++;
        exitg1 = 2L;
      }
    } while (exitg1 == 0L);

    if (exitg1 == 1L) {
      exitg2 = true;
    }
  }

  if (!p) {
    for (j = 0; j < 3; j++) {
      Ss[3 * j] = Estimations_DW.P[j];
      Ss[3 * j + 1] = Estimations_DW.P[j + 3];
      Ss[3 * j + 2] = Estimations_DW.P[j + 6];
    }

    qr_sQLXF2xn(Ss, unusedU0, R);
    for (j = 0; j < 3; j++) {
      Ss[3 * j] = R[j];
      Ss[3 * j + 1] = R[j + 3];
      Ss[3 * j + 2] = R[j + 6];
    }
  }

  UKFCorrectorAdditive_getPredict(0.031622776601683791, Estimations_DW.x, Ss,
    1.0, 2.0, 0.0, &residual, U, &nrmx);
  residual = Estimations_U.voltage - residual;
  C[0] = U[0];
  C[1] = U[1];
  C[2] = U[2];
  trisolve_1hqRQ712(nrmx, C);
  rtb_DataStoreRead[0] = C[0];
  rtb_DataStoreRead[1] = C[1];
  rtb_DataStoreRead[2] = C[2];
  trisolve_1hqRQ712(nrmx, rtb_DataStoreRead);
  for (i = 0; i < 3; i++) {
    U[i] = rtb_DataStoreRead[i] * nrmx;
    Estimations_DW.P[3 * i] = Ss[i];
    Estimations_DW.P[3 * i + 1] = Ss[i + 3];
    Estimations_DW.P[3 * i + 2] = Ss[i + 6];
  }

  for (j = 0; j < 2; j++) {
    Estimations_DW.P[j + 1] = 0.0;
  }

  Estimations_DW.P[5] = 0.0;
  j = 0;
  if ((Estimations_DW.P[0] == 0.0) || (Estimations_DW.P[4] == 0.0) ||
      (Estimations_DW.P[8] == 0.0)) {
    j = 2;
  } else {
    C[2] = U[2];
    scale = 3.3121686421112381E-35;
    C[0] = U[0] / Estimations_DW.P[0];
    absxk = fabs(C[0]);
    if (absxk > 3.3121686421112381E-35) {
      nrmx = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-35;
      nrmx = t * t;
    }

    C[1] = (U[1] - Estimations_DW.P[3] * C[0]) / Estimations_DW.P[4];
    absxk = fabs(C[1]);
    if (absxk > scale) {
      t = scale / absxk;
      nrmx = nrmx * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrmx += t * t;
    }

    absxk = U[2];
    for (i = 0; i < 2; i++) {
      absxk -= Estimations_DW.P[i + 6] * C[i];
    }

    C[2] = absxk / Estimations_DW.P[8];
    absxk = fabs(C[2]);
    if (absxk > scale) {
      t = scale / absxk;
      nrmx = nrmx * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      nrmx += t * t;
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      j = 1;
    } else {
      rotate_h3nP3JUD(sqrt(1.0 - nrmx * nrmx), C[2], &c[2], &s[2], &scale);
      C[2] = 0.0;
      rotate_h3nP3JUD(scale, C[1], &c[1], &s[1], &scale);
      C[1] = 0.0;
      rotate_h3nP3JUD(scale, C[0], &c[0], &s[0], &scale);
      C[0] = 0.0;
      for (i = 0; i + 1 > 0; i--) {
        nrmx = s[i] * Estimations_DW.P[i];
        Estimations_DW.P[i] = c[i] * Estimations_DW.P[i] - s[i] * C[0];
        C[0] = c[i] * C[0] + nrmx;
      }

      for (i = 1; i + 1 > 0; i--) {
        nrmx = Estimations_DW.P[i + 3];
        Estimations_DW.P[i + 3] = nrmx * c[i] - s[i] * C[1];
        C[1] = c[i] * C[1] + nrmx * s[i];
      }

      for (i = 2; i + 1 > 0; i--) {
        nrmx = Estimations_DW.P[i + 6] * s[i];
        Estimations_DW.P[i + 6] = Estimations_DW.P[i + 6] * c[i] - s[i] * C[2];
        C[2] = c[i] * C[2] + nrmx;
      }
    }
  }

  if (j != 0) {
    for (j = 0; j < 3; j++) {
      for (i = 0; i < 3; i++) {
        coffset = j + 3 * i;
        Ss[coffset] = 0.0;
        Ss[coffset] += Estimations_DW.P[3 * j] * Estimations_DW.P[3 * i];
        Ss[coffset] += Estimations_DW.P[3 * j + 1] * Estimations_DW.P[3 * i + 1];
        Ss[coffset] += Estimations_DW.P[3 * j + 2] * Estimations_DW.P[3 * i + 2];
        R[i + 3 * j] = U[i] * U[j];
      }
    }

    p = true;
    for (j = 0; j < 9; j++) {
      nrmx = Ss[j] - R[j];
      if (p && (rtIsInf(nrmx) || rtIsNaN(nrmx))) {
        p = false;
      }

      unusedU0[j] = nrmx;
    }

    if (p) {
      svd_pFhYsdaI(unusedU0, Ss, s, R);
    } else {
      s[0] = (rtNaN);
      s[1] = (rtNaN);
      s[2] = (rtNaN);
      for (j = 0; j < 9; j++) {
        R[j] = (rtNaN);
      }
    }

    for (j = 0; j < 9; j++) {
      Ss[j] = 0.0;
    }

    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (j = 0; j < 9; j++) {
      Ss[j] = sqrt(Ss[j]);
    }

    for (j = 0; j < 3; j++) {
      for (i = 0; i < 3; i++) {
        coffset = j + 3 * i;
        Estimations_DW.P[coffset] = 0.0;
        Estimations_DW.P[coffset] += Ss[3 * j] * R[i];
        Estimations_DW.P[coffset] += Ss[3 * j + 1] * R[i + 3];
        Estimations_DW.P[coffset] += Ss[3 * j + 2] * R[i + 6];
      }
    }

    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 3)) {
      i = j + 1;
      do {
        exitg1 = 0L;
        if (i + 1 < 4) {
          if (!(Estimations_DW.P[3 * j + i] == 0.0)) {
            p = false;
            exitg1 = 1L;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2L;
        }
      } while (exitg1 == 0L);

      if (exitg1 == 1L) {
        exitg2 = true;
      }
    }

    if (!p) {
      qr_sQLXF2xn(Estimations_DW.P, unusedU0, Ss);
      for (j = 0; j < 9; j++) {
        Estimations_DW.P[j] = Ss[j];
      }
    }
  }

  for (j = 0; j < 3; j++) {
    Ss[3 * j] = Estimations_DW.P[j];
    Ss[3 * j + 1] = Estimations_DW.P[j + 3];
    Ss[3 * j + 2] = Estimations_DW.P[j + 6];
  }

  /* DataStoreWrite: '<S5>/Data Store WriteX' incorporates:
   *  DataStoreRead: '<S5>/Data Store ReadX'
   *  MATLAB Function: '<S5>/Correct'
   */
  Estimations_DW.x[0] += rtb_DataStoreRead[0] * residual;

  /* End of Outputs for SubSystem: '<S3>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S3>/Subsystem' */
  /* DataStoreRead: '<S7>/Data Store Read' */
  rtb_DataStoreRead[0] = Estimations_DW.x[0];

  /* End of Outputs for SubSystem: '<S3>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S3>/Correct1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* DataStoreWrite: '<S5>/Data Store WriteX' incorporates:
   *  DataStoreRead: '<S5>/Data Store ReadX'
   *  MATLAB Function: '<S5>/Correct'
   */
  Estimations_DW.x[1] += rtb_DataStoreRead[1] * residual;
  Estimations_DW.x[2] += rtb_DataStoreRead[2] * residual;

  /* End of Outputs for SubSystem: '<S3>/Correct1' */

  /* Outputs for Atomic SubSystem: '<S3>/Subsystem' */
  /* DataStoreRead: '<S7>/Data Store Read' */
  Estimations_Y.R0 = Estimations_DW.x[2];

  /* End of Outputs for SubSystem: '<S3>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<S3>/Predict' */
  /* Outputs for Enabled SubSystem: '<S3>/Correct1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  for (j = 0; j < 9; j++) {
    /* MATLAB Function: '<S5>/Correct' incorporates:
     *  DataStoreWrite: '<S5>/Data Store WriteP'
     */
    Estimations_DW.P[j] = Ss[j];

    /* MATLAB Function: '<S6>/Predict' incorporates:
     *  DataStoreWrite: '<S6>/Data Store WriteP'
     */
    residual = 1.7320508075688772 * Estimations_DW.P[j];
    X2state[j] = residual;
    X2state[j + 9] = -residual;
  }

  /* End of Outputs for SubSystem: '<S3>/Correct1' */

  /* MATLAB Function: '<S6>/Predict' incorporates:
   *  DataStoreRead: '<S6>/Data Store ReadX'
   */
  for (j = 0; j < 6; j++) {
    X2state[3 * j] += Estimations_DW.x[0];
    i = 3 * j + 1;
    X2state[i] += Estimations_DW.x[1];
    i = 3 * j + 2;
    X2state[i] += Estimations_DW.x[2];
  }

  for (j = 0; j < 6; j++) {
    batteryStateFcn1(&X2state[3 * j], U);
    Y2[3 * j] = U[0];
    Y2[3 * j + 1] = U[1];
    Y2[3 * j + 2] = U[2];
  }

  batteryStateFcn1(Estimations_DW.x, U);
  tmp[0] = 0.0;
  tmp[1] = 0.16666666666666666;
  for (j = 0; j < 2; j++) {
    Wcov_0[j] = Wcov[j];
  }

  /* DataStoreWrite: '<S6>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S6>/Predict'
   */
  UTMeanCovSqrt_tkXBHSqd(tmp, Wcov_0, 1.0, U, Y2, Estimations_DW.x, Ss);

  /* MATLAB Function: '<S6>/Predict' incorporates:
   *  Constant: '<S3>/Q'
   *  DataStoreWrite: '<S6>/Data Store WriteP'
   */
  for (j = 0; j < 9; j++) {
    b_I[j] = 0;
  }

  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (j = 0; j < 3; j++) {
    coffset = j * 3;
    for (i = 0; i < 3; i++) {
      aoffset = i * 3;
      unusedU0[coffset + i] = (Ss[aoffset + 1] * (real_T)b_I[j + 3] + Ss[aoffset]
        * (real_T)b_I[j]) + Ss[aoffset + 2] * (real_T)b_I[j + 6];
    }
  }

  for (j = 0; j < 3; j++) {
    Y2[6 * j] = unusedU0[3 * j];
    Y2[6 * j + 3] = rtCP_Q_Value[j];
    Y2[6 * j + 1] = unusedU0[3 * j + 1];
    Y2[6 * j + 4] = rtCP_Q_Value[j + 3];
    Y2[6 * j + 2] = unusedU0[3 * j + 2];
    Y2[6 * j + 5] = rtCP_Q_Value[j + 6];
  }

  qr_284JFiJs(Y2, X2state, Ss);
  for (j = 0; j < 3; j++) {
    Estimations_DW.P[3 * j] = Ss[j];
    Estimations_DW.P[3 * j + 1] = Ss[j + 3];
    Estimations_DW.P[3 * j + 2] = Ss[j + 6];
  }

  /* End of Outputs for SubSystem: '<S3>/Predict' */

  /* Outport: '<Root>/SOC' */
  Estimations_Y.SOC = rtb_DataStoreRead[0];

  /* Outport: '<Root>/R1_filter' */
  Estimations_Y.R1_filter = Estimations_Y.R0;
}

/* Model initialize function */
void Estimations_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int16_T i;

    /* Start for DataStoreMemory: '<S3>/DataStoreMemory - P' */
    for (i = 0; i < 9; i++) {
      Estimations_DW.P[i] = rtCP_DataStoreMemoryP_InitialVa[i];
    }

    /* End of Start for DataStoreMemory: '<S3>/DataStoreMemory - P' */

    /* Start for DataStoreMemory: '<S3>/DataStoreMemory - x' */
    Estimations_DW.x[0] = 0.5;
    Estimations_DW.x[1] = 0.0;
    Estimations_DW.x[2] = 0.01;
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
