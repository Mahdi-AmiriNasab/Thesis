/*
 * File: isLocalExtrema.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

#ifndef ISLOCALEXTREMA_H
#define ISLOCALEXTREMA_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void doLocalMaxSearch(double A_data[], int A_size, double maxNumExt,
                      boolean_T maxVals_data[], int *maxVals_size,
                      double P_data[], int *P_size);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for isLocalExtrema.h
 *
 * [EOF]
 */
