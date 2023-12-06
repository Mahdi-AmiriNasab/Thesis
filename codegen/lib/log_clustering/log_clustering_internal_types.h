/*
 * File: log_clustering_internal_types.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

#ifndef LOG_CLUSTERING_INTERNAL_TYPES_H
#define LOG_CLUSTERING_INTERNAL_TYPES_H

/* Include Files */
#include "log_clustering_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef enum_e_noise_stat
#define enum_e_noise_stat
enum e_noise_stat
{
  noise_not_found = 0, /* Default value */
  noise_found,
  noise_single_found
};
#endif /* enum_e_noise_stat */
#ifndef typedef_e_noise_stat
#define typedef_e_noise_stat
typedef enum e_noise_stat e_noise_stat;
#endif /* typedef_e_noise_stat */

#endif
/*
 * File trailer for log_clustering_internal_types.h
 *
 * [EOF]
 */
