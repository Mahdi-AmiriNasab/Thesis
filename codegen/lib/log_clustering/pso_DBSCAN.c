/*
 * File: pso_DBSCAN.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 11:40:38
 */

/* Include Files */
#include "pso_DBSCAN.h"
#include "find.h"
#include "log_clustering_emxutil.h"
#include "log_clustering_internal_types.h"
#include "log_clustering_types.h"
#include "minOrMax.h"
#include "pdist2.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * initialization
 *
 * Arguments    : const double socs[9]
 *                double minPts
 *                double eps
 *                double *cluster_cell_cnt
 *                double *cluster_average
 *                double cluster_dbscan_res[9]
 *                double cluster_clt_res_cell[81]
 *                double cluster_clt_res_soc[81]
 *                double cluster_clt_res_soc_av[18]
 *                double *cluster_clt_max_count
 *                double cluster_clt_noise_soc[18]
 *                double cluster_clt_soc[18]
 *                double cluster_noise_max[2]
 *                double cluster_noise_min[2]
 *                double cluster_single_noise[2]
 *                e_noise_stat *cluster_noise_status
 * Return Type  : void
 */
void pso_DBSCAN(const double socs[9], double minPts, double eps,
                double *cluster_cell_cnt, double *cluster_average,
                double cluster_dbscan_res[9], double cluster_clt_res_cell[81],
                double cluster_clt_res_soc[81],
                double cluster_clt_res_soc_av[18],
                double *cluster_clt_max_count, double cluster_clt_noise_soc[18],
                double cluster_clt_soc[18], double cluster_noise_max[2],
                double cluster_noise_min[2], double cluster_single_noise[2],
                e_noise_stat *cluster_noise_status)
{
  emxArray_int32_T *Neighbors;
  double D_contents[81];
  double clt_noise_soc_cpy[18];
  double found_index_data[9];
  double C;
  int Neighbors_data[9];
  int cluster_clt_noise_soc_size[2];
  int b_i;
  int c_column;
  int i;
  int idx;
  int n;
  int s_column;
  int s_index;
  int *b_Neighbors_data;
  signed char b_tmp_data[9];
  signed char tmp_data[9];
  boolean_T x[18];
  boolean_T non_zero_indices[9];
  boolean_T visited_contents[9];
  boolean_T exitg1;
  boolean_T y;
  *cluster_cell_cnt = 9.0;
  /* socs = fix(rand (1, cell_cnt) * 100); */
  /*  eps = 10; */
  /*  minPts = 3; */
  /*  clustering */
  C = socs[0];
  for (c_column = 0; c_column < 8; c_column++) {
    C += socs[c_column + 1];
  }
  *cluster_average = trunc(C / 9.0);
  C = 0.0;
  for (i = 0; i < 9; i++) {
    found_index_data[i] = socs[i] - *cluster_average;
    cluster_dbscan_res[i] = 0.0;
    visited_contents[i] = false;
  }
  pdist2(found_index_data, found_index_data, D_contents);
  emxInit_int32_T(&Neighbors);
  for (i = 0; i < 9; i++) {
    if (!visited_contents[i]) {
      int Neighbors_size[2];
      visited_contents[i] = true;
      for (b_i = 0; b_i < 9; b_i++) {
        non_zero_indices[b_i] = (D_contents[i + 9 * b_i] <= eps);
      }
      eml_find(non_zero_indices, Neighbors_data, Neighbors_size);
      idx = Neighbors_size[1];
      if (Neighbors_size[1] < minPts) {
        /*  X(i,:) is NOISE */
        cluster_dbscan_res[i] = -1.0;
      } else {
        unsigned int k;
        C++;
        b_i = Neighbors->size[0] * Neighbors->size[1];
        Neighbors->size[0] = 1;
        Neighbors->size[1] = Neighbors_size[1];
        emxEnsureCapacity_int32_T(Neighbors, b_i);
        b_Neighbors_data = Neighbors->data;
        for (b_i = 0; b_i < idx; b_i++) {
          b_Neighbors_data[b_i] = Neighbors_data[b_i];
        }
        cluster_dbscan_res[i] = C;
        k = 1U;
        do {
          c_column = b_Neighbors_data[(int)k - 1];
          if (!visited_contents[c_column - 1]) {
            visited_contents[c_column - 1] = true;
            for (b_i = 0; b_i < 9; b_i++) {
              non_zero_indices[b_i] =
                  (D_contents[(c_column + 9 * b_i) - 1] <= eps);
            }
            eml_find(non_zero_indices, Neighbors_data, Neighbors_size);
            if (Neighbors_size[1] >= minPts) {
              b_i = Neighbors->size[1];
              idx = Neighbors_size[1];
              s_index = Neighbors->size[0] * Neighbors->size[1];
              Neighbors->size[1] += Neighbors_size[1];
              emxEnsureCapacity_int32_T(Neighbors, s_index);
              b_Neighbors_data = Neighbors->data;
              for (s_index = 0; s_index < idx; s_index++) {
                b_Neighbors_data[b_i + s_index] = Neighbors_data[s_index];
              }
            }
          }
          if (cluster_dbscan_res[c_column - 1] == 0.0) {
            cluster_dbscan_res[c_column - 1] = C;
          }
          k++;
        } while (!(k > (unsigned int)Neighbors->size[1]));
      }
    }
  }
  emxFree_int32_T(&Neighbors);
  /* data_cluster = [error(2, :); dbscan_res_clm']; */
  /*  finding adjacent clusters */
  s_index = 0;
  /*  stores cluster indices */
  s_column = 0;
  /*  stores number of each cells in the cluster */
  /*  stores the index average of each cluster */
  /*  init maximum number of clusters containig cell indices */
  memset(&cluster_clt_res_cell[0], 0, 81U * sizeof(double));
  memset(&cluster_clt_res_soc[0], 0, 81U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  memset(&cluster_clt_res_soc_av[0], 0, 18U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  for (n = 0; n < 9; n++) {
    b_i = s_index + 9 * s_column;
    if (cluster_clt_res_cell[b_i] == 0.0) {
      cluster_clt_res_cell[b_i] = (double)n + 1.0;
      cluster_clt_res_soc[b_i] = socs[n];

      /*  find simularities whilest the data is not noise */
    } else if ((cluster_dbscan_res[n] == cluster_dbscan_res[n - 1]) &&
               (cluster_dbscan_res[n] != -1.0)) {
      s_column++;
      idx = s_index + 9 * s_column;
      cluster_clt_res_cell[idx] = (double)n + 1.0;
      cluster_clt_res_soc[idx] = socs[n];
    } else {
      /*  update the cluster index if no similarities found */
      s_column = 0;
      s_index++;
      cluster_clt_res_cell[s_index] = (double)n + 1.0;
      cluster_clt_res_soc[s_index] = socs[n];
    }
    /*  calculating average of each cluster */
    idx = 0;
    i = -1;
    for (c_column = 0; c_column < 9; c_column++) {
      C = cluster_clt_res_soc[s_index + 9 * c_column];
      if (C != 0.0) {
        idx++;
        i++;
        found_index_data[i] = C;
      }
    }
    if (idx == 0) {
      C = 0.0;
    } else {
      C = found_index_data[0];
      for (c_column = 2; c_column <= idx; c_column++) {
        C += found_index_data[c_column - 1];
      }
    }
    C /= (double)idx;
    if (!rtIsNaN(C)) {
      cluster_clt_res_soc_av[s_index] = trunc(C);
      cluster_clt_res_soc_av[s_index + 9] = s_index + 1;
    }
  }
  /*  sorting */
  sortrows(cluster_clt_res_soc_av);
  if (!rtIsNaN(cluster_clt_res_soc_av[9])) {
    idx = 1;
  } else {
    idx = 0;
    c_column = 2;
    exitg1 = false;
    while ((!exitg1) && (c_column <= 9)) {
      if (!rtIsNaN(cluster_clt_res_soc_av[c_column + 8])) {
        idx = c_column;
        exitg1 = true;
      } else {
        c_column++;
      }
    }
  }
  if (idx == 0) {
    *cluster_clt_max_count = cluster_clt_res_soc_av[9];
  } else {
    *cluster_clt_max_count = cluster_clt_res_soc_av[idx + 8];
    b_i = idx + 1;
    for (c_column = b_i; c_column < 10; c_column++) {
      C = cluster_clt_res_soc_av[c_column + 8];
      if (*cluster_clt_max_count < C) {
        *cluster_clt_max_count = C;
      }
    }
  }
  /*  finding noises */
  s_column = 0;
  c_column = 0;
  /*  to store noise vs soc */
  memset(&cluster_clt_noise_soc[0], 0, 18U * sizeof(double));
  memset(&cluster_clt_soc[0], 0, 18U * sizeof(double));
  /*  to store cluster vs average soc */
  for (n = 0; n < 9; n++) {
    C = cluster_clt_res_cell[n];
    if (C != 0.0) {
      /*  noise detected */
      if (cluster_clt_res_cell[n + 9] == 0.0) {
        idx = s_column << 1;
        cluster_clt_noise_soc[idx] = (double)n + 1.0;
        /* cluster.clt_res_cell(n, 1); */
        cluster_clt_noise_soc[idx + 1] = socs[(int)C - 1];
        s_column++;
      } else {
        /* cluster detected */
        idx = c_column << 1;
        cluster_clt_soc[idx] = (double)n + 1.0;
        /*  find the corresponding soc of the index (n) */
        for (b_i = 0; b_i < 9; b_i++) {
          visited_contents[b_i] =
              (cluster_clt_res_soc_av[b_i + 9] == (double)n + 1.0);
        }
        b_eml_find(visited_contents, Neighbors_data, &s_index);
        for (b_i = 0; b_i < s_index; b_i++) {
          found_index_data[b_i] = Neighbors_data[b_i];
        }
        /*  check if the found_index is not empty */
        if (s_index != 0) {
          cluster_clt_soc[idx + 1] =
              cluster_clt_res_soc_av[(int)found_index_data[0] - 1];
        }
        c_column++;
      }
    }
  }
  cluster_single_noise[0] = 0.0;
  cluster_single_noise[1] = 0.0;
  /*  if no single noise found */
  for (b_i = 0; b_i < 18; b_i++) {
    x[b_i] = (cluster_clt_noise_soc[b_i] == 0.0);
  }
  idx = 2;
  for (i = 0; i < 9; i++) {
    non_zero_indices[i] = true;
    c_column = idx;
    s_index = idx - 1;
    idx += 2;
    exitg1 = false;
    while ((!exitg1) && (s_index <= c_column)) {
      if (!x[s_index - 1]) {
        non_zero_indices[i] = false;
        exitg1 = true;
      } else {
        s_index++;
      }
    }
  }
  y = true;
  c_column = 0;
  exitg1 = false;
  while ((!exitg1) && (c_column < 9)) {
    if (!non_zero_indices[c_column]) {
      y = false;
      exitg1 = true;
    } else {
      c_column++;
    }
  }
  if (y) {
    *cluster_noise_status = noise_not_found;
    /*  minimum cluster as noise */
    c_column = 0;
    idx = 0;
    for (i = 0; i < 9; i++) {
      y = (cluster_clt_res_soc_av[i + 9] != 0.0);
      non_zero_indices[i] = y;
      if (y) {
        c_column++;
        tmp_data[idx] = (signed char)(i + 1);
        idx++;
      }
    }
    for (b_i = 0; b_i < c_column; b_i++) {
      found_index_data[b_i] = cluster_clt_res_soc_av[tmp_data[b_i] - 1];
    }
    cluster_noise_min[1] = minimum(found_index_data, c_column);
    for (b_i = 0; b_i < 9; b_i++) {
      visited_contents[b_i] =
          (cluster_clt_res_soc_av[b_i] == cluster_noise_min[1]);
    }
    b_eml_find(visited_contents, Neighbors_data, &s_index);
    for (b_i = 0; b_i < s_index; b_i++) {
      found_index_data[b_i] = Neighbors_data[b_i];
    }
    cluster_noise_min[0] = cluster_clt_res_soc_av[(int)found_index_data[0] + 8];
    /*  maximum cluster as noise */
    c_column = 0;
    idx = 0;
    for (i = 0; i < 9; i++) {
      if (non_zero_indices[i]) {
        c_column++;
        b_tmp_data[idx] = (signed char)(i + 1);
        idx++;
      }
    }
    for (b_i = 0; b_i < c_column; b_i++) {
      found_index_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i] - 1];
    }
    cluster_noise_max[1] = maximum(found_index_data, c_column);
    for (b_i = 0; b_i < 9; b_i++) {
      visited_contents[b_i] =
          (cluster_clt_res_soc_av[b_i] == cluster_noise_max[1]);
    }
    b_eml_find(visited_contents, Neighbors_data, &s_index);
    for (b_i = 0; b_i < s_index; b_i++) {
      found_index_data[b_i] = Neighbors_data[b_i];
    }
    cluster_noise_max[0] = cluster_clt_res_soc_av[(int)found_index_data[0] + 8];
    /*  if just one noise found */
  } else {
    n = 0;
    for (c_column = 0; c_column < 9; c_column++) {
      if (cluster_clt_noise_soc[(c_column << 1) + 1] != 0.0) {
        n++;
      }
    }
    if (n == 1) {
      *cluster_noise_status = noise_single_found;
      if (cluster_clt_noise_soc[1] > *cluster_average) {
        /*  maximum single noise */
        cluster_noise_max[0] = cluster_clt_noise_soc[0];
        cluster_noise_max[1] = cluster_clt_noise_soc[1];
        /*  minimum cluster as noise */
        c_column = 0;
        idx = 0;
        for (i = 0; i < 9; i++) {
          y = (cluster_clt_res_soc_av[i + 9] != 0.0);
          if (y) {
            c_column++;
            tmp_data[idx] = (signed char)(i + 1);
            idx++;
          }
        }
        for (b_i = 0; b_i < c_column; b_i++) {
          found_index_data[b_i] = cluster_clt_res_soc_av[tmp_data[b_i] - 1];
        }
        cluster_noise_min[1] = minimum(found_index_data, c_column);
        for (b_i = 0; b_i < 9; b_i++) {
          visited_contents[b_i] =
              (cluster_clt_res_soc_av[b_i] == cluster_noise_min[1]);
        }
        b_eml_find(visited_contents, Neighbors_data, &s_index);
        for (b_i = 0; b_i < s_index; b_i++) {
          found_index_data[b_i] = Neighbors_data[b_i];
        }
        cluster_noise_min[0] =
            cluster_clt_res_soc_av[(int)found_index_data[0] + 8];
      } else {
        /*  maximum cluster as noise */
        c_column = 0;
        idx = 0;
        for (i = 0; i < 9; i++) {
          y = (cluster_clt_res_soc_av[i + 9] != 0.0);
          if (y) {
            c_column++;
            tmp_data[idx] = (signed char)(i + 1);
            idx++;
          }
        }
        for (b_i = 0; b_i < c_column; b_i++) {
          found_index_data[b_i] = cluster_clt_res_soc_av[tmp_data[b_i] - 1];
        }
        cluster_noise_max[1] = maximum(found_index_data, c_column);
        for (b_i = 0; b_i < 9; b_i++) {
          visited_contents[b_i] =
              (cluster_clt_res_soc_av[b_i] == cluster_noise_max[1]);
        }
        b_eml_find(visited_contents, Neighbors_data, &s_index);
        for (b_i = 0; b_i < s_index; b_i++) {
          found_index_data[b_i] = Neighbors_data[b_i];
        }
        cluster_noise_max[0] =
            cluster_clt_res_soc_av[(int)found_index_data[0] + 8];
        /*  minimum single noise */
        cluster_noise_min[0] = cluster_clt_noise_soc[0];
        cluster_noise_min[1] = cluster_clt_noise_soc[1];
      }
      /*  if several noises available */
    } else {
      *cluster_noise_status = noise_found;
      /*  indice to clear the noise cluster */
      memcpy(&clt_noise_soc_cpy[0], &cluster_clt_noise_soc[0],
             18U * sizeof(double));
      /*  minimum niose */
      c_column = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        y = (cluster_clt_noise_soc[i << 1] != 0.0);
        non_zero_indices[i] = y;
        if (y) {
          c_column++;
          tmp_data[idx] = (signed char)(i + 1);
          idx++;
        }
      }
      cluster_clt_noise_soc_size[0] = 1;
      cluster_clt_noise_soc_size[1] = c_column;
      for (b_i = 0; b_i < c_column; b_i++) {
        found_index_data[b_i] =
            cluster_clt_noise_soc[((tmp_data[b_i] - 1) << 1) + 1];
      }
      b_minimum(found_index_data, cluster_clt_noise_soc_size, &C, &idx);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_min(2, 1)); */
      idx = (idx - 1) << 1;
      cluster_noise_min[0] = cluster_clt_noise_soc[idx];
      cluster_noise_min[1] = cluster_clt_noise_soc[idx + 1];
      /*  clear the picked noise as minimum to avoid repeated selection */
      clt_noise_soc_cpy[idx] = -1.0;
      clt_noise_soc_cpy[idx + 1] = -1.0;
      /*  maximum niose */
      c_column = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        if (non_zero_indices[i]) {
          c_column++;
          b_tmp_data[idx] = (signed char)(i + 1);
          idx++;
        }
      }
      cluster_clt_noise_soc_size[0] = 1;
      cluster_clt_noise_soc_size[1] = c_column;
      for (b_i = 0; b_i < c_column; b_i++) {
        found_index_data[b_i] =
            clt_noise_soc_cpy[((b_tmp_data[b_i] - 1) << 1) + 1];
      }
      b_maximum(found_index_data, cluster_clt_noise_soc_size, &C, &idx);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_max(2, 1)); */
      idx = (idx - 1) << 1;
      cluster_noise_max[0] = clt_noise_soc_cpy[idx];
      cluster_noise_max[1] = clt_noise_soc_cpy[idx + 1];
    }
  }
}

/*
 * File trailer for pso_DBSCAN.c
 *
 * [EOF]
 */
