/*
 * File: log_clustering.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

#ifndef LOG_CLUSTERING_H
#define LOG_CLUSTERING_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double log_clustering(const double soc_in[9], double mp,
                      double *lg_inconsistency, double *lg_eq_overlap,
                      double soc_profile_data[], int soc_profile_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for log_clustering.h
 *
 * [EOF]
 */
