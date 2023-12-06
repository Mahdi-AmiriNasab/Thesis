/*
 * File: pso_DBSCAN.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

#ifndef PSO_DBSCAN_H
#define PSO_DBSCAN_H

/* Include Files */
#include "pso_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_pso_DBSCAN(const double socs[9], double minPts, double *cluster_cell_cnt,
                  double *cluster_average, double cluster_dbscan_res[9],
                  double cluster_clt_res_cell[81],
                  double cluster_clt_res_soc[81],
                  double cluster_clt_res_soc_av[18],
                  double *cluster_clt_max_count,
                  double cluster_clt_noise_soc[18], double cluster_clt_soc[18],
                  double cluster_noise_max[2], double cluster_noise_min[2],
                  double cluster_single_noise[2],
                  e_noise_stat *cluster_noise_status);

void pso_DBSCAN(const double socs[9], double minPts, double eps,
                double *cluster_cell_cnt, double *cluster_average,
                double cluster_dbscan_res[9], double cluster_clt_res_cell[81],
                double cluster_clt_res_soc[81],
                double cluster_clt_res_soc_av[18],
                double *cluster_clt_max_count, double cluster_clt_noise_soc[18],
                double cluster_clt_soc[18], double cluster_noise_max[2],
                double cluster_noise_min[2], double cluster_single_noise[2],
                e_noise_stat *cluster_noise_status);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for pso_DBSCAN.h
 *
 * [EOF]
 */
