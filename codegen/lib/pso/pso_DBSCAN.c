/*
 * File: pso_DBSCAN.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 20-Jun-2024 18:29:15
 */

/* Include Files */
#include "pso_DBSCAN.h"
#include "all.h"
#include "db.h"
#include "find.h"
#include "minOrMax.h"
#include "pdist2.h"
#include "pso_emxutil.h"
#include "pso_internal_types.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * function [cluster] = pso_DBSCAN(socs, minPts, eps)
 *
 * initialization
 *
 * Arguments    : const double socs[9]
 *                double minPts
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
 * Return Type  : double
 */
double
b_pso_DBSCAN(const double socs[9], double minPts, double *cluster_average,
             double cluster_dbscan_res[9], double cluster_clt_res_cell[81],
             double cluster_clt_res_soc[81], double cluster_clt_res_soc_av[18],
             double *cluster_clt_max_count, double cluster_clt_noise_soc[18],
             double cluster_clt_soc[18], double cluster_noise_max[2],
             double cluster_noise_min[2], double cluster_single_noise[2],
             e_noise_stat *cluster_noise_status)
{
  static b_captured_var IDX;
  static d_captured_var D;
  static double clt_noise_soc_cpy[18];
  static double Neighbors_data[9];
  static int tmp_data[9];
  c_captured_var visited;
  captured_var MinPts;
  captured_var epsilon;
  emxArray_real_T *r;
  double cluster_cell_cnt;
  double mn_tmp;
  double *r1;
  int Neighbors_size[2];
  int tmp_size[2];
  int C;
  int b_i;
  int i;
  int k;
  int n;
  int s_column;
  int s_index;
  signed char b_tmp_data[9];
  signed char c_tmp_data[9];
  boolean_T b_cluster_clt_noise_soc[18];
  boolean_T b_D[9];
  boolean_T exitg1;
  boolean_T y;
  /* 'pso_DBSCAN:6' cell_cnt = length(socs); */
  /* 'pso_DBSCAN:8' cluster = struct('cell_cnt', 0, 'average', 0, 'dbscan_res',
   * zeros(1, 9) ... */
  /* 'pso_DBSCAN:9' , 'clt_res_cell', zeros(cell_cnt, cell_cnt), 'clt_res_soc',
   * zeros(cell_cnt, cell_cnt) ... */
  /* 'pso_DBSCAN:10' , 'clt_res_soc_av', zeros(cell_cnt, 2), 'clt_max_count', 0,
   * 'clt_noise_soc', zeros(2, cell_cnt) ... */
  /* 'pso_DBSCAN:11' , 'clt_soc', zeros(2, cell_cnt), 'noise_max', zeros(2, 1),
   * 'noise_min', zeros(2, 1), 'single_noise', zeros(2, 1) ... */
  /* 'pso_DBSCAN:12' , 'noise_status', e_noise_stat.noise_found); */
  /* 'pso_DBSCAN:14' cluster.cell_cnt = length(socs); */
  cluster_cell_cnt = 9.0;
  /* socs = fix(rand (1, cell_cnt) * 100); */
  /*  eps = 10; */
  /*  minPts = 3; */
  /*  clustering */
  /* 'pso_DBSCAN:19' cluster.average = double(fix(mean(socs))); */
  mn_tmp = socs[0];
  for (k = 0; k < 8; k++) {
    mn_tmp += socs[k + 1];
  }
  mn_tmp /= 9.0;
  if (mn_tmp < 0.0) {
    *cluster_average = ceil(mn_tmp);
  } else {
    *cluster_average = floor(mn_tmp);
  }
  /* 'pso_DBSCAN:20' error = [(1:cell_cnt); socs - repmat(cluster.average, 1,
   * cell_cnt)]; */
  /* 'pso_DBSCAN:22' dbscan_res_clm = db(error(2, :)', eps, minPts); */
  MinPts.contents = minPts;
  epsilon.contents = 0.1;
  /* 'db:3' C=0; */
  C = 0;
  /* 'db:4' n=size(X,1); */
  /* 'db:5' IDX=zeros(n,1); */
  for (i = 0; i < 9; i++) {
    Neighbors_data[i] = socs[i] - *cluster_average;
    IDX.contents[i] = 0.0;
  }
  /* 'db:6' D=pdist2(X,X); */
  pdist2(Neighbors_data, Neighbors_data, D.contents);
  /* 'db:7' visited=false(n,1); */
  for (i = 0; i < 9; i++) {
    visited.contents[i] = false;
  }
  /* 'db:9' for i=1:n */
  emxInit_real_T(&r, 2);
  for (i = 0; i < 9; i++) {
    /* 'db:10' if ~visited(i) */
    if (!visited.contents[i]) {
      /* 'db:11' visited(i)=true; */
      visited.contents[i] = true;
      /* 'db:12' Neighbors=RegionQuery(i); */
      /* 'db:46' Neighbors=find(D(i,:)<=epsilon); */
      for (b_i = 0; b_i < 9; b_i++) {
        b_D[b_i] = (D.contents[i + 9 * b_i] <= 0.1);
      }
      eml_find(b_D, tmp_data, tmp_size);
      k = tmp_size[1];
      for (b_i = 0; b_i < k; b_i++) {
        Neighbors_data[b_i] = tmp_data[b_i];
      }
      /* 'db:13' if numel(Neighbors)<MinPts */
      if (tmp_size[1] < minPts) {
        /*  X(i,:) is NOISE */
        /* 'db:15' IDX(i)=-1; */
        IDX.contents[i] = -1.0;
      } else {
        /* 'db:16' else */
        /* 'db:17' C=C+1; */
        C++;
        /* 'db:18' ExpandCluster(i,Neighbors,C); */
        b_i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = tmp_size[1];
        emxEnsureCapacity_real_T(r, b_i);
        r1 = r->data;
        k = tmp_size[1] - 1;
        for (b_i = 0; b_i <= k; b_i++) {
          r1[b_i] = Neighbors_data[b_i];
        }
        ExpandCluster(&D, &epsilon, &IDX, &visited, &MinPts, (double)i + 1.0, r,
                      C);
      }
    }
  }
  emxFree_real_T(&r);
  /* data_cluster = [error(2, :); dbscan_res_clm']; */
  /*  finding adjacent clusters */
  /* 'pso_DBSCAN:26' s_index = 1; */
  s_index = 0;
  /*  stores cluster indices */
  /* 'pso_DBSCAN:27' s_column = 1; */
  s_column = 0;
  /*  stores number of each cells in the cluster */
  /* 'pso_DBSCAN:28' av_index = 1; */
  /*  stores the index average of each cluster */
  /* 'pso_DBSCAN:29' cluster.dbscan_res = dbscan_res_clm'; */
  memcpy(&cluster_dbscan_res[0], &IDX.contents[0], 9U * sizeof(double));
  /* 'pso_DBSCAN:30' cluster.clt_res_cell = zeros(cell_cnt, cell_cnt); */
  /*  init maximum number of clusters containig cell indices */
  /* 'pso_DBSCAN:31' cluster.clt_res_soc = zeros(cell_cnt, cell_cnt); */
  memset(&cluster_clt_res_cell[0], 0, 81U * sizeof(double));
  memset(&cluster_clt_res_soc[0], 0, 81U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  /* 'pso_DBSCAN:32' cluster.clt_res_soc_av = zeros(cell_cnt, 2); */
  memset(&cluster_clt_res_soc_av[0], 0, 18U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  /* 'pso_DBSCAN:33' for n = 1:cell_cnt */
  for (n = 0; n < 9; n++) {
    /* 'pso_DBSCAN:35' if (cluster.clt_res_cell(s_index, s_column) == 0) */
    b_i = s_index + 9 * s_column;
    if (cluster_clt_res_cell[b_i] == 0.0) {
      /* 'pso_DBSCAN:36' cluster.clt_res_cell(s_index, s_column) = n; */
      cluster_clt_res_cell[b_i] = (double)n + 1.0;
      /* 'pso_DBSCAN:37' cluster.clt_res_soc(s_index, s_column) = socs(1, n); */
      cluster_clt_res_soc[b_i] = socs[n];
    } else {
      /* 'pso_DBSCAN:38' else */
      /*  find simularities whilest the data is not noise */
      /* 'pso_DBSCAN:40' if(cluster.dbscan_res(1, n) == cluster.dbscan_res(1,
       * n-1) && cluster.dbscan_res(1, n) ~= -1) */
      mn_tmp = IDX.contents[n];
      if ((mn_tmp == IDX.contents[n - 1]) && (mn_tmp != -1.0)) {
        /* 'pso_DBSCAN:41' s_column = s_column + 1; */
        s_column++;
        /* 'pso_DBSCAN:42' cluster.clt_res_cell(s_index, s_column) = n; */
        C = s_index + 9 * s_column;
        cluster_clt_res_cell[C] = (double)n + 1.0;
        /* 'pso_DBSCAN:43' cluster.clt_res_soc(s_index, s_column) = socs(1, n);
         */
        cluster_clt_res_soc[C] = socs[n];
      } else {
        /* 'pso_DBSCAN:44' else */
        /*  update the cluster index if no similarities found */
        /* 'pso_DBSCAN:46' s_column = 1; */
        s_column = 0;
        /* 'pso_DBSCAN:47' s_index = s_index + 1; */
        s_index++;
        /* 'pso_DBSCAN:48' cluster.clt_res_cell(s_index, s_column) = n; */
        cluster_clt_res_cell[s_index] = (double)n + 1.0;
        /* 'pso_DBSCAN:49' cluster.clt_res_soc(s_index, s_column) = socs(1, n);
         */
        cluster_clt_res_soc[s_index] = socs[n];
      }
    }
    /*  calculating average of each cluster */
    /* 'pso_DBSCAN:53' mn_tmp = mean(nonzeros(cluster.clt_res_soc(s_index, :)));
     */
    C = 0;
    i = -1;
    for (k = 0; k < 9; k++) {
      mn_tmp = cluster_clt_res_soc[s_index + 9 * k];
      if (mn_tmp != 0.0) {
        C++;
        i++;
        Neighbors_data[i] = mn_tmp;
      }
    }
    if (C == 0) {
      mn_tmp = 0.0;
    } else {
      mn_tmp = Neighbors_data[0];
      for (k = 2; k <= C; k++) {
        mn_tmp += Neighbors_data[k - 1];
      }
    }
    mn_tmp /= (double)C;
    /* 'pso_DBSCAN:54' if(~isnan(mn_tmp)) */
    if (!rtIsNaN(mn_tmp)) {
      /* 'pso_DBSCAN:55' cluster.clt_res_soc_av(s_index, 1) = fix(mn_tmp); */
      if (mn_tmp < 0.0) {
        cluster_clt_res_soc_av[s_index] = ceil(mn_tmp);
      } else {
        cluster_clt_res_soc_av[s_index] = floor(mn_tmp);
      }
      /* 'pso_DBSCAN:56' cluster.clt_res_soc_av(s_index, 2) = s_index; */
      cluster_clt_res_soc_av[s_index + 9] = s_index + 1;
    }
  }
  /*  sorting */
  /* 'pso_DBSCAN:62' cluster.clt_res_soc_av = sortrows(cluster.clt_res_soc_av,
   * 1, 'descend'); */
  sortrows(cluster_clt_res_soc_av);
  /* 'pso_DBSCAN:64' cluster.clt_max_count = max(cluster.clt_res_soc_av(:, 2));
   */
  *cluster_clt_max_count = maximum(&cluster_clt_res_soc_av[9]);
  /*  finding noises */
  /* 'pso_DBSCAN:68' s_column = 1; */
  s_column = 0;
  /* 'pso_DBSCAN:69' c_column = 1; */
  s_index = 0;
  /* 'pso_DBSCAN:70' cluster.clt_noise_soc = zeros (2, cell_cnt); */
  /*  to store noise vs soc */
  /* 'pso_DBSCAN:71' cluster.clt_soc = zeros (2, cell_cnt); */
  memset(&cluster_clt_noise_soc[0], 0, 18U * sizeof(double));
  memset(&cluster_clt_soc[0], 0, 18U * sizeof(double));
  /*  to store cluster vs average soc */
  /* 'pso_DBSCAN:72' for n = 1:cell_cnt */
  for (n = 0; n < 9; n++) {
    /* 'pso_DBSCAN:74' if cluster.clt_res_cell(n , 1) ~= 0 */
    mn_tmp = cluster_clt_res_cell[n];
    if (mn_tmp != 0.0) {
      /*  noise detected */
      /* 'pso_DBSCAN:75' if (cluster.clt_res_cell(n, 2) == 0) */
      if (cluster_clt_res_cell[n + 9] == 0.0) {
        /* 'pso_DBSCAN:76' cluster.clt_noise_soc(1, s_column) = n; */
        C = s_column << 1;
        cluster_clt_noise_soc[C] = (double)n + 1.0;
        /* cluster.clt_res_cell(n, 1); */
        /* 'pso_DBSCAN:77' cluster.clt_noise_soc(2, s_column) = socs(1,
         * cluster.clt_res_cell(n, 1)); */
        cluster_clt_noise_soc[C + 1] = socs[(int)mn_tmp - 1];
        /* 'pso_DBSCAN:78' s_column = s_column + 1; */
        s_column++;
      } else {
        /* 'pso_DBSCAN:79' else */
        /* cluster detected */
        /* 'pso_DBSCAN:80' cluster.clt_soc(1, c_column) = n; */
        C = s_index << 1;
        cluster_clt_soc[C] = (double)n + 1.0;
        /*  find the corresponding soc of the index (n) */
        /* 'pso_DBSCAN:82' found_index = find(cluster.clt_res_soc_av(:, 2) ==
         * n); */
        for (b_i = 0; b_i < 9; b_i++) {
          b_D[b_i] = (cluster_clt_res_soc_av[b_i + 9] == (double)n + 1.0);
        }
        k = b_eml_find(b_D, tmp_data);
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = tmp_data[b_i];
        }
        /*  check if the found_index is not empty */
        /* 'pso_DBSCAN:84' if ~isempty(found_index) */
        if (k != 0) {
          /* 'pso_DBSCAN:85' cluster.clt_soc(2, c_column) =
           * cluster.clt_res_soc_av(found_index(1, 1) ,1); */
          cluster_clt_soc[C + 1] =
              cluster_clt_res_soc_av[(int)Neighbors_data[0] - 1];
        }
        /* 'pso_DBSCAN:87' c_column = c_column + 1; */
        s_index++;
      }
    }
  }
  /* 'pso_DBSCAN:93' cluster.noise_max = [0; 0]; */
  /* 'pso_DBSCAN:94' cluster.noise_min = [0; 0]; */
  /* 'pso_DBSCAN:95' cluster.single_noise = [0; 0]; */
  cluster_single_noise[0] = 0.0;
  cluster_single_noise[1] = 0.0;
  /*  if no single noise found */
  /* 'pso_DBSCAN:98' if all(cluster.clt_noise_soc == 0) */
  for (b_i = 0; b_i < 18; b_i++) {
    b_cluster_clt_noise_soc[b_i] = (cluster_clt_noise_soc[b_i] == 0.0);
  }
  all(b_cluster_clt_noise_soc, b_D);
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!b_D[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    /* 'pso_DBSCAN:99' cluster.noise_status = e_noise_stat.noise_not_found; */
    *cluster_noise_status = noise_not_found;
    /*  minimum cluster as noise */
    /* 'pso_DBSCAN:101' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
    /* 'pso_DBSCAN:102' cluster.noise_min(2, 1) =
     * min(cluster.clt_res_soc_av(non_zero_indices, 1)); */
    k = 0;
    C = 0;
    for (i = 0; i < 9; i++) {
      if (cluster_clt_res_soc_av[i + 9] != 0.0) {
        k++;
        b_tmp_data[C] = (signed char)i;
        C++;
      }
    }
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i]];
    }
    cluster_noise_min[1] = minimum(Neighbors_data, k);
    /* 'pso_DBSCAN:103' tmp = find(cluster.clt_res_soc_av(:, 1) ==
     * cluster.noise_min(2, 1)); */
    for (b_i = 0; b_i < 9; b_i++) {
      b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_min[1]);
    }
    k = b_eml_find(b_D, tmp_data);
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = tmp_data[b_i];
    }
    /* 'pso_DBSCAN:104' cluster.noise_min(1, 1) = cluster.clt_res_soc_av(tmp(1,
     * 1), 2); */
    cluster_noise_min[0] = cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
    /*  maximum cluster as noise */
    /* 'pso_DBSCAN:107' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
    /* 'pso_DBSCAN:108' cluster.noise_max(2, 1) =
     * max(cluster.clt_res_soc_av(non_zero_indices, 1)); */
    k = 0;
    C = 0;
    for (i = 0; i < 9; i++) {
      if (cluster_clt_res_soc_av[i + 9] != 0.0) {
        k++;
        c_tmp_data[C] = (signed char)i;
        C++;
      }
    }
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = cluster_clt_res_soc_av[c_tmp_data[b_i]];
    }
    cluster_noise_max[1] = b_maximum(Neighbors_data, k);
    /* 'pso_DBSCAN:109' tmp = find(cluster.clt_res_soc_av(:, 1) ==
     * cluster.noise_max(2, 1)); */
    for (b_i = 0; b_i < 9; b_i++) {
      b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_max[1]);
    }
    k = b_eml_find(b_D, tmp_data);
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = tmp_data[b_i];
    }
    /* 'pso_DBSCAN:110' cluster.noise_max(1, 1) = cluster.clt_res_soc_av(tmp(1,
     * 1), 2); */
    cluster_noise_max[0] = cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
    /*  if just one noise found */
  } else {
    n = 0;
    for (k = 0; k < 9; k++) {
      if (cluster_clt_noise_soc[(k << 1) + 1] != 0.0) {
        n++;
      }
    }
    if (n == 1) {
      /* 'pso_DBSCAN:113' elseif nnz(cluster.clt_noise_soc(2, :)) == 1 */
      /* 'pso_DBSCAN:115' cluster.noise_status =
       * e_noise_stat.noise_single_found; */
      *cluster_noise_status = noise_single_found;
      /* 'pso_DBSCAN:117' single_noise = cluster.clt_noise_soc(:, 1); */
      /* 'pso_DBSCAN:118' search_indices = 1 : cell_cnt; */
      /* 'pso_DBSCAN:119' if single_noise(2, 1) > cluster.average */
      if (cluster_clt_noise_soc[1] > *cluster_average) {
        /*  maximum single noise */
        /* 'pso_DBSCAN:122' cluster.noise_max = single_noise; */
        cluster_noise_max[0] = cluster_clt_noise_soc[0];
        cluster_noise_max[1] = cluster_clt_noise_soc[1];
        /*  minimum cluster as noise */
        /* 'pso_DBSCAN:125' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~=
         * 0; */
        /* 'pso_DBSCAN:126' cluster.noise_min(2, 1) =
         * min(cluster.clt_res_soc_av(non_zero_indices, 1)); */
        k = 0;
        C = 0;
        for (i = 0; i < 9; i++) {
          if (cluster_clt_res_soc_av[i + 9] != 0.0) {
            k++;
            b_tmp_data[C] = (signed char)i;
            C++;
          }
        }
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i]];
        }
        cluster_noise_min[1] = minimum(Neighbors_data, k);
        /* 'pso_DBSCAN:127' tmp = find(cluster.clt_res_soc_av(:, 1) ==
         * cluster.noise_min(2, 1)); */
        for (b_i = 0; b_i < 9; b_i++) {
          b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_min[1]);
        }
        k = b_eml_find(b_D, tmp_data);
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = tmp_data[b_i];
        }
        /* 'pso_DBSCAN:128' cluster.noise_min(1, 1) =
         * cluster.clt_res_soc_av(tmp(1, 1), 2); */
        cluster_noise_min[0] =
            cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
      } else {
        /* 'pso_DBSCAN:130' else */
        /*  maximum cluster as noise */
        /* 'pso_DBSCAN:133' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~=
         * 0; */
        /* 'pso_DBSCAN:134' cluster.noise_max(2, 1) =
         * max(cluster.clt_res_soc_av(non_zero_indices, 1)); */
        k = 0;
        C = 0;
        for (i = 0; i < 9; i++) {
          if (cluster_clt_res_soc_av[i + 9] != 0.0) {
            k++;
            b_tmp_data[C] = (signed char)i;
            C++;
          }
        }
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i]];
        }
        cluster_noise_max[1] = b_maximum(Neighbors_data, k);
        /* 'pso_DBSCAN:135' tmp = find(cluster.clt_res_soc_av(:, 1) ==
         * cluster.noise_max(2, 1)); */
        for (b_i = 0; b_i < 9; b_i++) {
          b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_max[1]);
        }
        k = b_eml_find(b_D, tmp_data);
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = tmp_data[b_i];
        }
        /* 'pso_DBSCAN:136' cluster.noise_max(1, 1) =
         * cluster.clt_res_soc_av(tmp(1, 1), 2); */
        cluster_noise_max[0] =
            cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
        /*  minimum single noise */
        /* 'pso_DBSCAN:139' cluster.noise_min = single_noise; */
        cluster_noise_min[0] = cluster_clt_noise_soc[0];
        cluster_noise_min[1] = cluster_clt_noise_soc[1];
      }
      /*  if several noises available */
    } else {
      /* 'pso_DBSCAN:144' else */
      /* 'pso_DBSCAN:146' cluster.noise_status = e_noise_stat.noise_found; */
      *cluster_noise_status = noise_found;
      /*  indice to clear the noise cluster */
      /* 'pso_DBSCAN:148' indice_to_clear = 0; */
      /* 'pso_DBSCAN:150' clt_noise_soc_cpy = cluster.clt_noise_soc; */
      memcpy(&clt_noise_soc_cpy[0], &cluster_clt_noise_soc[0],
             18U * sizeof(double));
      /*  minimum niose */
      /* 'pso_DBSCAN:153' non_zero_indices =  clt_noise_soc_cpy(1, :) ~= 0; */
      /* 'pso_DBSCAN:154' [cluster.noise_min(2, 1), indice_to_clear] = min(
       * clt_noise_soc_cpy(2, non_zero_indices)); */
      k = 0;
      C = 0;
      for (i = 0; i < 9; i++) {
        if (cluster_clt_noise_soc[i << 1] != 0.0) {
          k++;
          b_tmp_data[C] = (signed char)i;
          C++;
        }
      }
      Neighbors_size[0] = 1;
      Neighbors_size[1] = k;
      for (b_i = 0; b_i < k; b_i++) {
        Neighbors_data[b_i] = cluster_clt_noise_soc[(b_tmp_data[b_i] << 1) + 1];
      }
      b_minimum(Neighbors_data, Neighbors_size, &C);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_min(2, 1)); */
      /* 'pso_DBSCAN:156' cluster.noise_min =  clt_noise_soc_cpy(:,
       * indice_to_clear); */
      C = (C - 1) << 1;
      cluster_noise_min[0] = cluster_clt_noise_soc[C];
      cluster_noise_min[1] = cluster_clt_noise_soc[C + 1];
      /*  clear the picked noise as minimum to avoid repeated selection */
      /* 'pso_DBSCAN:160' clt_noise_soc_cpy(1, indice_to_clear) = -1; */
      clt_noise_soc_cpy[C] = -1.0;
      /* 'pso_DBSCAN:161' clt_noise_soc_cpy(2, indice_to_clear) = -1; */
      clt_noise_soc_cpy[C + 1] = -1.0;
      /*  maximum niose */
      /* 'pso_DBSCAN:165' [cluster.noise_max(2, 1), indice_to_clear] = max(
       * clt_noise_soc_cpy(2, non_zero_indices)); */
      Neighbors_size[0] = 1;
      Neighbors_size[1] = k;
      for (b_i = 0; b_i < k; b_i++) {
        Neighbors_data[b_i] = clt_noise_soc_cpy[(b_tmp_data[b_i] << 1) + 1];
      }
      c_maximum(Neighbors_data, Neighbors_size, &C);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_max(2, 1)); */
      /* 'pso_DBSCAN:167' cluster.noise_max =  clt_noise_soc_cpy(:,
       * indice_to_clear); */
      C = (C - 1) << 1;
      cluster_noise_max[0] = clt_noise_soc_cpy[C];
      cluster_noise_max[1] = clt_noise_soc_cpy[C + 1];
      /* 'pso_DBSCAN:169' if coder.target('MATLAB') */
    }
  }
  return cluster_cell_cnt;
}

/*
 * function [cluster] = pso_DBSCAN(socs, minPts, eps)
 *
 * initialization
 *
 * Arguments    : const double socs[9]
 *                double minPts
 *                double eps
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
 * Return Type  : double
 */
double
pso_DBSCAN(const double socs[9], double minPts, double eps,
           double *cluster_average, double cluster_dbscan_res[9],
           double cluster_clt_res_cell[81], double cluster_clt_res_soc[81],
           double cluster_clt_res_soc_av[18], double *cluster_clt_max_count,
           double cluster_clt_noise_soc[18], double cluster_clt_soc[18],
           double cluster_noise_max[2], double cluster_noise_min[2],
           double cluster_single_noise[2], e_noise_stat *cluster_noise_status)
{
  static d_captured_var D;
  static double clt_noise_soc_cpy[18];
  static double Neighbors_data[9];
  b_captured_var IDX;
  c_captured_var visited;
  captured_var MinPts;
  captured_var epsilon;
  emxArray_real_T *r;
  double cluster_cell_cnt;
  double mn_tmp;
  double *r1;
  int tmp_data[9];
  int Neighbors_size[2];
  int tmp_size[2];
  int C;
  int b_i;
  int i;
  int k;
  int n;
  int s_column;
  int s_index;
  signed char b_tmp_data[9];
  signed char c_tmp_data[9];
  boolean_T b_cluster_clt_noise_soc[18];
  boolean_T b_D[9];
  boolean_T exitg1;
  boolean_T y;
  /* 'pso_DBSCAN:6' cell_cnt = length(socs); */
  /* 'pso_DBSCAN:8' cluster = struct('cell_cnt', 0, 'average', 0, 'dbscan_res',
   * zeros(1, 9) ... */
  /* 'pso_DBSCAN:9' , 'clt_res_cell', zeros(cell_cnt, cell_cnt), 'clt_res_soc',
   * zeros(cell_cnt, cell_cnt) ... */
  /* 'pso_DBSCAN:10' , 'clt_res_soc_av', zeros(cell_cnt, 2), 'clt_max_count', 0,
   * 'clt_noise_soc', zeros(2, cell_cnt) ... */
  /* 'pso_DBSCAN:11' , 'clt_soc', zeros(2, cell_cnt), 'noise_max', zeros(2, 1),
   * 'noise_min', zeros(2, 1), 'single_noise', zeros(2, 1) ... */
  /* 'pso_DBSCAN:12' , 'noise_status', e_noise_stat.noise_found); */
  /* 'pso_DBSCAN:14' cluster.cell_cnt = length(socs); */
  cluster_cell_cnt = 9.0;
  /* socs = fix(rand (1, cell_cnt) * 100); */
  /*  eps = 10; */
  /*  minPts = 3; */
  /*  clustering */
  /* 'pso_DBSCAN:19' cluster.average = double(fix(mean(socs))); */
  mn_tmp = socs[0];
  for (k = 0; k < 8; k++) {
    mn_tmp += socs[k + 1];
  }
  mn_tmp /= 9.0;
  if (mn_tmp < 0.0) {
    *cluster_average = ceil(mn_tmp);
  } else {
    *cluster_average = floor(mn_tmp);
  }
  /* 'pso_DBSCAN:20' error = [(1:cell_cnt); socs - repmat(cluster.average, 1,
   * cell_cnt)]; */
  /* 'pso_DBSCAN:22' dbscan_res_clm = db(error(2, :)', eps, minPts); */
  MinPts.contents = minPts;
  epsilon.contents = eps;
  /* 'db:3' C=0; */
  C = 0;
  /* 'db:4' n=size(X,1); */
  /* 'db:5' IDX=zeros(n,1); */
  for (i = 0; i < 9; i++) {
    Neighbors_data[i] = socs[i] - *cluster_average;
    IDX.contents[i] = 0.0;
  }
  /* 'db:6' D=pdist2(X,X); */
  pdist2(Neighbors_data, Neighbors_data, D.contents);
  /* 'db:7' visited=false(n,1); */
  for (i = 0; i < 9; i++) {
    visited.contents[i] = false;
  }
  /* 'db:9' for i=1:n */
  emxInit_real_T(&r, 2);
  for (i = 0; i < 9; i++) {
    /* 'db:10' if ~visited(i) */
    if (!visited.contents[i]) {
      /* 'db:11' visited(i)=true; */
      visited.contents[i] = true;
      /* 'db:12' Neighbors=RegionQuery(i); */
      /* 'db:46' Neighbors=find(D(i,:)<=epsilon); */
      for (b_i = 0; b_i < 9; b_i++) {
        b_D[b_i] = (D.contents[i + 9 * b_i] <= eps);
      }
      eml_find(b_D, tmp_data, tmp_size);
      k = tmp_size[1];
      for (b_i = 0; b_i < k; b_i++) {
        Neighbors_data[b_i] = tmp_data[b_i];
      }
      /* 'db:13' if numel(Neighbors)<MinPts */
      if (tmp_size[1] < minPts) {
        /*  X(i,:) is NOISE */
        /* 'db:15' IDX(i)=-1; */
        IDX.contents[i] = -1.0;
      } else {
        /* 'db:16' else */
        /* 'db:17' C=C+1; */
        C++;
        /* 'db:18' ExpandCluster(i,Neighbors,C); */
        b_i = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = tmp_size[1];
        emxEnsureCapacity_real_T(r, b_i);
        r1 = r->data;
        k = tmp_size[1] - 1;
        for (b_i = 0; b_i <= k; b_i++) {
          r1[b_i] = Neighbors_data[b_i];
        }
        ExpandCluster(&D, &epsilon, &IDX, &visited, &MinPts, (double)i + 1.0, r,
                      C);
      }
    }
  }
  emxFree_real_T(&r);
  /* data_cluster = [error(2, :); dbscan_res_clm']; */
  /*  finding adjacent clusters */
  /* 'pso_DBSCAN:26' s_index = 1; */
  s_index = 0;
  /*  stores cluster indices */
  /* 'pso_DBSCAN:27' s_column = 1; */
  s_column = 0;
  /*  stores number of each cells in the cluster */
  /* 'pso_DBSCAN:28' av_index = 1; */
  /*  stores the index average of each cluster */
  /* 'pso_DBSCAN:29' cluster.dbscan_res = dbscan_res_clm'; */
  memcpy(&cluster_dbscan_res[0], &IDX.contents[0], 9U * sizeof(double));
  /* 'pso_DBSCAN:30' cluster.clt_res_cell = zeros(cell_cnt, cell_cnt); */
  /*  init maximum number of clusters containig cell indices */
  /* 'pso_DBSCAN:31' cluster.clt_res_soc = zeros(cell_cnt, cell_cnt); */
  memset(&cluster_clt_res_cell[0], 0, 81U * sizeof(double));
  memset(&cluster_clt_res_soc[0], 0, 81U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  /* 'pso_DBSCAN:32' cluster.clt_res_soc_av = zeros(cell_cnt, 2); */
  memset(&cluster_clt_res_soc_av[0], 0, 18U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  /* 'pso_DBSCAN:33' for n = 1:cell_cnt */
  for (n = 0; n < 9; n++) {
    /* 'pso_DBSCAN:35' if (cluster.clt_res_cell(s_index, s_column) == 0) */
    b_i = s_index + 9 * s_column;
    if (cluster_clt_res_cell[b_i] == 0.0) {
      /* 'pso_DBSCAN:36' cluster.clt_res_cell(s_index, s_column) = n; */
      cluster_clt_res_cell[b_i] = (double)n + 1.0;
      /* 'pso_DBSCAN:37' cluster.clt_res_soc(s_index, s_column) = socs(1, n); */
      cluster_clt_res_soc[b_i] = socs[n];
    } else {
      /* 'pso_DBSCAN:38' else */
      /*  find simularities whilest the data is not noise */
      /* 'pso_DBSCAN:40' if(cluster.dbscan_res(1, n) == cluster.dbscan_res(1,
       * n-1) && cluster.dbscan_res(1, n) ~= -1) */
      mn_tmp = IDX.contents[n];
      if ((mn_tmp == IDX.contents[n - 1]) && (mn_tmp != -1.0)) {
        /* 'pso_DBSCAN:41' s_column = s_column + 1; */
        s_column++;
        /* 'pso_DBSCAN:42' cluster.clt_res_cell(s_index, s_column) = n; */
        C = s_index + 9 * s_column;
        cluster_clt_res_cell[C] = (double)n + 1.0;
        /* 'pso_DBSCAN:43' cluster.clt_res_soc(s_index, s_column) = socs(1, n);
         */
        cluster_clt_res_soc[C] = socs[n];
      } else {
        /* 'pso_DBSCAN:44' else */
        /*  update the cluster index if no similarities found */
        /* 'pso_DBSCAN:46' s_column = 1; */
        s_column = 0;
        /* 'pso_DBSCAN:47' s_index = s_index + 1; */
        s_index++;
        /* 'pso_DBSCAN:48' cluster.clt_res_cell(s_index, s_column) = n; */
        cluster_clt_res_cell[s_index] = (double)n + 1.0;
        /* 'pso_DBSCAN:49' cluster.clt_res_soc(s_index, s_column) = socs(1, n);
         */
        cluster_clt_res_soc[s_index] = socs[n];
      }
    }
    /*  calculating average of each cluster */
    /* 'pso_DBSCAN:53' mn_tmp = mean(nonzeros(cluster.clt_res_soc(s_index, :)));
     */
    C = 0;
    i = -1;
    for (k = 0; k < 9; k++) {
      mn_tmp = cluster_clt_res_soc[s_index + 9 * k];
      if (mn_tmp != 0.0) {
        C++;
        i++;
        Neighbors_data[i] = mn_tmp;
      }
    }
    if (C == 0) {
      mn_tmp = 0.0;
    } else {
      mn_tmp = Neighbors_data[0];
      for (k = 2; k <= C; k++) {
        mn_tmp += Neighbors_data[k - 1];
      }
    }
    mn_tmp /= (double)C;
    /* 'pso_DBSCAN:54' if(~isnan(mn_tmp)) */
    if (!rtIsNaN(mn_tmp)) {
      /* 'pso_DBSCAN:55' cluster.clt_res_soc_av(s_index, 1) = fix(mn_tmp); */
      if (mn_tmp < 0.0) {
        cluster_clt_res_soc_av[s_index] = ceil(mn_tmp);
      } else {
        cluster_clt_res_soc_av[s_index] = floor(mn_tmp);
      }
      /* 'pso_DBSCAN:56' cluster.clt_res_soc_av(s_index, 2) = s_index; */
      cluster_clt_res_soc_av[s_index + 9] = s_index + 1;
    }
  }
  /*  sorting */
  /* 'pso_DBSCAN:62' cluster.clt_res_soc_av = sortrows(cluster.clt_res_soc_av,
   * 1, 'descend'); */
  sortrows(cluster_clt_res_soc_av);
  /* 'pso_DBSCAN:64' cluster.clt_max_count = max(cluster.clt_res_soc_av(:, 2));
   */
  *cluster_clt_max_count = maximum(&cluster_clt_res_soc_av[9]);
  /*  finding noises */
  /* 'pso_DBSCAN:68' s_column = 1; */
  s_column = 0;
  /* 'pso_DBSCAN:69' c_column = 1; */
  s_index = 0;
  /* 'pso_DBSCAN:70' cluster.clt_noise_soc = zeros (2, cell_cnt); */
  /*  to store noise vs soc */
  /* 'pso_DBSCAN:71' cluster.clt_soc = zeros (2, cell_cnt); */
  memset(&cluster_clt_noise_soc[0], 0, 18U * sizeof(double));
  memset(&cluster_clt_soc[0], 0, 18U * sizeof(double));
  /*  to store cluster vs average soc */
  /* 'pso_DBSCAN:72' for n = 1:cell_cnt */
  for (n = 0; n < 9; n++) {
    /* 'pso_DBSCAN:74' if cluster.clt_res_cell(n , 1) ~= 0 */
    mn_tmp = cluster_clt_res_cell[n];
    if (mn_tmp != 0.0) {
      /*  noise detected */
      /* 'pso_DBSCAN:75' if (cluster.clt_res_cell(n, 2) == 0) */
      if (cluster_clt_res_cell[n + 9] == 0.0) {
        /* 'pso_DBSCAN:76' cluster.clt_noise_soc(1, s_column) = n; */
        C = s_column << 1;
        cluster_clt_noise_soc[C] = (double)n + 1.0;
        /* cluster.clt_res_cell(n, 1); */
        /* 'pso_DBSCAN:77' cluster.clt_noise_soc(2, s_column) = socs(1,
         * cluster.clt_res_cell(n, 1)); */
        cluster_clt_noise_soc[C + 1] = socs[(int)mn_tmp - 1];
        /* 'pso_DBSCAN:78' s_column = s_column + 1; */
        s_column++;
      } else {
        /* 'pso_DBSCAN:79' else */
        /* cluster detected */
        /* 'pso_DBSCAN:80' cluster.clt_soc(1, c_column) = n; */
        C = s_index << 1;
        cluster_clt_soc[C] = (double)n + 1.0;
        /*  find the corresponding soc of the index (n) */
        /* 'pso_DBSCAN:82' found_index = find(cluster.clt_res_soc_av(:, 2) ==
         * n); */
        for (b_i = 0; b_i < 9; b_i++) {
          b_D[b_i] = (cluster_clt_res_soc_av[b_i + 9] == (double)n + 1.0);
        }
        k = b_eml_find(b_D, tmp_data);
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = tmp_data[b_i];
        }
        /*  check if the found_index is not empty */
        /* 'pso_DBSCAN:84' if ~isempty(found_index) */
        if (k != 0) {
          /* 'pso_DBSCAN:85' cluster.clt_soc(2, c_column) =
           * cluster.clt_res_soc_av(found_index(1, 1) ,1); */
          cluster_clt_soc[C + 1] =
              cluster_clt_res_soc_av[(int)Neighbors_data[0] - 1];
        }
        /* 'pso_DBSCAN:87' c_column = c_column + 1; */
        s_index++;
      }
    }
  }
  /* 'pso_DBSCAN:93' cluster.noise_max = [0; 0]; */
  /* 'pso_DBSCAN:94' cluster.noise_min = [0; 0]; */
  /* 'pso_DBSCAN:95' cluster.single_noise = [0; 0]; */
  cluster_single_noise[0] = 0.0;
  cluster_single_noise[1] = 0.0;
  /*  if no single noise found */
  /* 'pso_DBSCAN:98' if all(cluster.clt_noise_soc == 0) */
  for (b_i = 0; b_i < 18; b_i++) {
    b_cluster_clt_noise_soc[b_i] = (cluster_clt_noise_soc[b_i] == 0.0);
  }
  all(b_cluster_clt_noise_soc, b_D);
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!b_D[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    /* 'pso_DBSCAN:99' cluster.noise_status = e_noise_stat.noise_not_found; */
    *cluster_noise_status = noise_not_found;
    /*  minimum cluster as noise */
    /* 'pso_DBSCAN:101' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
    /* 'pso_DBSCAN:102' cluster.noise_min(2, 1) =
     * min(cluster.clt_res_soc_av(non_zero_indices, 1)); */
    k = 0;
    C = 0;
    for (i = 0; i < 9; i++) {
      if (cluster_clt_res_soc_av[i + 9] != 0.0) {
        k++;
        b_tmp_data[C] = (signed char)i;
        C++;
      }
    }
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i]];
    }
    cluster_noise_min[1] = minimum(Neighbors_data, k);
    /* 'pso_DBSCAN:103' tmp = find(cluster.clt_res_soc_av(:, 1) ==
     * cluster.noise_min(2, 1)); */
    for (b_i = 0; b_i < 9; b_i++) {
      b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_min[1]);
    }
    k = b_eml_find(b_D, tmp_data);
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = tmp_data[b_i];
    }
    /* 'pso_DBSCAN:104' cluster.noise_min(1, 1) = cluster.clt_res_soc_av(tmp(1,
     * 1), 2); */
    cluster_noise_min[0] = cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
    /*  maximum cluster as noise */
    /* 'pso_DBSCAN:107' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
    /* 'pso_DBSCAN:108' cluster.noise_max(2, 1) =
     * max(cluster.clt_res_soc_av(non_zero_indices, 1)); */
    k = 0;
    C = 0;
    for (i = 0; i < 9; i++) {
      if (cluster_clt_res_soc_av[i + 9] != 0.0) {
        k++;
        c_tmp_data[C] = (signed char)i;
        C++;
      }
    }
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = cluster_clt_res_soc_av[c_tmp_data[b_i]];
    }
    cluster_noise_max[1] = b_maximum(Neighbors_data, k);
    /* 'pso_DBSCAN:109' tmp = find(cluster.clt_res_soc_av(:, 1) ==
     * cluster.noise_max(2, 1)); */
    for (b_i = 0; b_i < 9; b_i++) {
      b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_max[1]);
    }
    k = b_eml_find(b_D, tmp_data);
    for (b_i = 0; b_i < k; b_i++) {
      Neighbors_data[b_i] = tmp_data[b_i];
    }
    /* 'pso_DBSCAN:110' cluster.noise_max(1, 1) = cluster.clt_res_soc_av(tmp(1,
     * 1), 2); */
    cluster_noise_max[0] = cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
    /*  if just one noise found */
  } else {
    n = 0;
    for (k = 0; k < 9; k++) {
      if (cluster_clt_noise_soc[(k << 1) + 1] != 0.0) {
        n++;
      }
    }
    if (n == 1) {
      /* 'pso_DBSCAN:113' elseif nnz(cluster.clt_noise_soc(2, :)) == 1 */
      /* 'pso_DBSCAN:115' cluster.noise_status =
       * e_noise_stat.noise_single_found; */
      *cluster_noise_status = noise_single_found;
      /* 'pso_DBSCAN:117' single_noise = cluster.clt_noise_soc(:, 1); */
      /* 'pso_DBSCAN:118' search_indices = 1 : cell_cnt; */
      /* 'pso_DBSCAN:119' if single_noise(2, 1) > cluster.average */
      if (cluster_clt_noise_soc[1] > *cluster_average) {
        /*  maximum single noise */
        /* 'pso_DBSCAN:122' cluster.noise_max = single_noise; */
        cluster_noise_max[0] = cluster_clt_noise_soc[0];
        cluster_noise_max[1] = cluster_clt_noise_soc[1];
        /*  minimum cluster as noise */
        /* 'pso_DBSCAN:125' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~=
         * 0; */
        /* 'pso_DBSCAN:126' cluster.noise_min(2, 1) =
         * min(cluster.clt_res_soc_av(non_zero_indices, 1)); */
        k = 0;
        C = 0;
        for (i = 0; i < 9; i++) {
          if (cluster_clt_res_soc_av[i + 9] != 0.0) {
            k++;
            b_tmp_data[C] = (signed char)i;
            C++;
          }
        }
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i]];
        }
        cluster_noise_min[1] = minimum(Neighbors_data, k);
        /* 'pso_DBSCAN:127' tmp = find(cluster.clt_res_soc_av(:, 1) ==
         * cluster.noise_min(2, 1)); */
        for (b_i = 0; b_i < 9; b_i++) {
          b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_min[1]);
        }
        k = b_eml_find(b_D, tmp_data);
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = tmp_data[b_i];
        }
        /* 'pso_DBSCAN:128' cluster.noise_min(1, 1) =
         * cluster.clt_res_soc_av(tmp(1, 1), 2); */
        cluster_noise_min[0] =
            cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
      } else {
        /* 'pso_DBSCAN:130' else */
        /*  maximum cluster as noise */
        /* 'pso_DBSCAN:133' non_zero_indices = cluster.clt_res_soc_av(:, 2) ~=
         * 0; */
        /* 'pso_DBSCAN:134' cluster.noise_max(2, 1) =
         * max(cluster.clt_res_soc_av(non_zero_indices, 1)); */
        k = 0;
        C = 0;
        for (i = 0; i < 9; i++) {
          if (cluster_clt_res_soc_av[i + 9] != 0.0) {
            k++;
            b_tmp_data[C] = (signed char)i;
            C++;
          }
        }
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = cluster_clt_res_soc_av[b_tmp_data[b_i]];
        }
        cluster_noise_max[1] = b_maximum(Neighbors_data, k);
        /* 'pso_DBSCAN:135' tmp = find(cluster.clt_res_soc_av(:, 1) ==
         * cluster.noise_max(2, 1)); */
        for (b_i = 0; b_i < 9; b_i++) {
          b_D[b_i] = (cluster_clt_res_soc_av[b_i] == cluster_noise_max[1]);
        }
        k = b_eml_find(b_D, tmp_data);
        for (b_i = 0; b_i < k; b_i++) {
          Neighbors_data[b_i] = tmp_data[b_i];
        }
        /* 'pso_DBSCAN:136' cluster.noise_max(1, 1) =
         * cluster.clt_res_soc_av(tmp(1, 1), 2); */
        cluster_noise_max[0] =
            cluster_clt_res_soc_av[(int)Neighbors_data[0] + 8];
        /*  minimum single noise */
        /* 'pso_DBSCAN:139' cluster.noise_min = single_noise; */
        cluster_noise_min[0] = cluster_clt_noise_soc[0];
        cluster_noise_min[1] = cluster_clt_noise_soc[1];
      }
      /*  if several noises available */
    } else {
      /* 'pso_DBSCAN:144' else */
      /* 'pso_DBSCAN:146' cluster.noise_status = e_noise_stat.noise_found; */
      *cluster_noise_status = noise_found;
      /*  indice to clear the noise cluster */
      /* 'pso_DBSCAN:148' indice_to_clear = 0; */
      /* 'pso_DBSCAN:150' clt_noise_soc_cpy = cluster.clt_noise_soc; */
      memcpy(&clt_noise_soc_cpy[0], &cluster_clt_noise_soc[0],
             18U * sizeof(double));
      /*  minimum niose */
      /* 'pso_DBSCAN:153' non_zero_indices =  clt_noise_soc_cpy(1, :) ~= 0; */
      /* 'pso_DBSCAN:154' [cluster.noise_min(2, 1), indice_to_clear] = min(
       * clt_noise_soc_cpy(2, non_zero_indices)); */
      k = 0;
      C = 0;
      for (i = 0; i < 9; i++) {
        if (cluster_clt_noise_soc[i << 1] != 0.0) {
          k++;
          b_tmp_data[C] = (signed char)i;
          C++;
        }
      }
      Neighbors_size[0] = 1;
      Neighbors_size[1] = k;
      for (b_i = 0; b_i < k; b_i++) {
        Neighbors_data[b_i] = cluster_clt_noise_soc[(b_tmp_data[b_i] << 1) + 1];
      }
      b_minimum(Neighbors_data, Neighbors_size, &C);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_min(2, 1)); */
      /* 'pso_DBSCAN:156' cluster.noise_min =  clt_noise_soc_cpy(:,
       * indice_to_clear); */
      C = (C - 1) << 1;
      cluster_noise_min[0] = cluster_clt_noise_soc[C];
      cluster_noise_min[1] = cluster_clt_noise_soc[C + 1];
      /*  clear the picked noise as minimum to avoid repeated selection */
      /* 'pso_DBSCAN:160' clt_noise_soc_cpy(1, indice_to_clear) = -1; */
      clt_noise_soc_cpy[C] = -1.0;
      /* 'pso_DBSCAN:161' clt_noise_soc_cpy(2, indice_to_clear) = -1; */
      clt_noise_soc_cpy[C + 1] = -1.0;
      /*  maximum niose */
      /* 'pso_DBSCAN:165' [cluster.noise_max(2, 1), indice_to_clear] = max(
       * clt_noise_soc_cpy(2, non_zero_indices)); */
      Neighbors_size[0] = 1;
      Neighbors_size[1] = k;
      for (b_i = 0; b_i < k; b_i++) {
        Neighbors_data[b_i] = clt_noise_soc_cpy[(b_tmp_data[b_i] << 1) + 1];
      }
      c_maximum(Neighbors_data, Neighbors_size, &C);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_max(2, 1)); */
      /* 'pso_DBSCAN:167' cluster.noise_max =  clt_noise_soc_cpy(:,
       * indice_to_clear); */
      C = (C - 1) << 1;
      cluster_noise_max[0] = clt_noise_soc_cpy[C];
      cluster_noise_max[1] = clt_noise_soc_cpy[C + 1];
      /* 'pso_DBSCAN:169' if coder.target('MATLAB') */
    }
  }
  return cluster_cell_cnt;
}

/*
 * File trailer for pso_DBSCAN.c
 *
 * [EOF]
 */
