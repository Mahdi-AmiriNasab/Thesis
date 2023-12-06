/*
 * File: balance_soc.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

#ifndef BALANCE_SOC_H
#define BALANCE_SOC_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void balance_soc(const double cluster_clt_res_cell[81],
                 const double cluster_clt_res_soc_av[18],
                 double cluster_clt_max_count,
                 const double cluster_noise_max[2],
                 const double cluster_noise_min[2], double soc_in[9],
                 double *soc_transfered, double *blc_time);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for balance_soc.h
 *
 * [EOF]
 */
