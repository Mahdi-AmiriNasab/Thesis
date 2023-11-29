/*
 * File: pso_DBSCAN.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

/* Include Files */
#include "pso_DBSCAN.h"
#include "find.h"
#include "minOrMax.h"
#include "pso_DBSCAN_emxutil.h"
#include "pso_DBSCAN_types.h"
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
 *                double eps
 *                struct0_T *cluster
 * Return Type  : void
 */
void pso_DBSCAN(const double socs[9], double minPts, double eps,
                struct0_T *cluster)
{
  emxArray_int32_T *Neighbors;
  double D_contents[81];
  double clt_noise_soc_cpy[18];
  double found_index_data[9];
  double C;
  double D_contents_tmp;
  int Neighbors_data[9];
  int cluster_size[2];
  int b_i;
  int i;
  int idx;
  int k;
  int n;
  int s_column;
  int s_index;
  int *b_Neighbors_data;
  signed char b_tmp_data[9];
  signed char tmp_data[9];
  boolean_T x[18];
  boolean_T logIndX[9];
  boolean_T logIndY[9];
  boolean_T visited_contents[9];
  boolean_T exitg1;
  boolean_T y;
  /* cell_cnt = length(socs); */
  /* cluster = struct('cell_cnt', 0, 'average', 0, 'dbscan_res', zeros(1, 9) ...
   */
  /* , 'clt_res_cell', zeros(cell_cnt, cell_cnt), 'clt_res_soc', zeros(cell_cnt,
   * cell_cnt) ... */
  /* , 'clt_res_soc_av', zeros(cell_cnt, 2), 'clt_max_count', 0,
   * 'clt_noise_soc', zeros(2, cell_cnt) ... */
  /* , 'clt_soc', zeros(2, cell_cnt), 'noise_max', zeros(2, 1), 'noise_min',
   * zeros(2, 1), 'single_noise', zeros(2, 1) ... */
  /* , 'noise_status', e_noise_stat.noise_found); */
  /* cluster.cell_cnt = length(socs); */
  cluster->cell_cnt = 9.0;
  /* socs = fix(rand (1, cell_cnt) * 100); */
  /*  eps = 10; */
  /*  minPts = 3; */
  /*  clustering */
  /* cluster.average = double(fix(mean(socs))); */
  C = socs[0];
  for (k = 0; k < 8; k++) {
    C += socs[k + 1];
  }
  cluster->average = trunc(C / 9.0);
  /* error = [(1:cell_cnt); socs - repmat(cluster.average, 1, cell_cnt)]; */
  /* dbscan_res_clm = db(error(2, :)', eps, minPts); */
  /* C=0; */
  C = 0.0;
  /* n=size(X,1); */
  /* IDX=zeros(n,1); */
  for (i = 0; i < 9; i++) {
    found_index_data[i] = socs[i] - cluster->average;
    cluster->dbscan_res[i] = 0.0;
  }
  /* D=pdist2(X,X); */
  for (i = 0; i < 81; i++) {
    D_contents[i] = rtNaN;
  }
  for (idx = 0; idx < 9; idx++) {
    logIndX[idx] = true;
    y = rtIsNaN(found_index_data[idx]);
    if (y) {
      logIndX[idx] = false;
    }
    logIndY[idx] = true;
    if (y) {
      logIndY[idx] = false;
    }
  }
  /* visited=false(n,1); */
  for (s_index = 0; s_index < 9; s_index++) {
    if (logIndY[s_index]) {
      for (idx = 0; idx < 9; idx++) {
        if (logIndX[idx]) {
          D_contents_tmp = found_index_data[idx] - found_index_data[s_index];
          D_contents[idx + 9 * s_index] = sqrt(D_contents_tmp * D_contents_tmp);
        }
      }
    }
    visited_contents[s_index] = false;
  }
  /* for i=1:n */
  emxInit_int32_T(&Neighbors);
  for (b_i = 0; b_i < 9; b_i++) {
    /* if ~visited(i) */
    if (!visited_contents[b_i]) {
      int Neighbors_size[2];
      /* visited(i)=true; */
      visited_contents[b_i] = true;
      /* Neighbors=RegionQuery(i); */
      /* Neighbors=find(D(i,:)<=epsilon); */
      for (i = 0; i < 9; i++) {
        logIndX[i] = (D_contents[b_i + 9 * i] <= eps);
      }
      eml_find(logIndX, Neighbors_data, Neighbors_size);
      /* if numel(Neighbors)<MinPts */
      idx = Neighbors_size[1];
      if (Neighbors_size[1] < minPts) {
        /*  X(i,:) is NOISE */
        /* IDX(i)=-1; */
        cluster->dbscan_res[b_i] = -1.0;
      } else {
        unsigned int b_k;
        /* else */
        /* C=C+1; */
        C++;
        /* ExpandCluster(i,Neighbors,C); */
        i = Neighbors->size[0] * Neighbors->size[1];
        Neighbors->size[0] = 1;
        Neighbors->size[1] = Neighbors_size[1];
        emxEnsureCapacity_int32_T(Neighbors, i);
        b_Neighbors_data = Neighbors->data;
        for (i = 0; i < idx; i++) {
          b_Neighbors_data[i] = Neighbors_data[i];
        }
        /* IDX(i)=C; */
        cluster->dbscan_res[b_i] = C;
        /* k = 1; */
        b_k = 1U;
        /* while true */
        do {
          /* j = Neighbors(k); */
          s_index = b_Neighbors_data[(int)b_k - 1];
          /* if ~visited(j) */
          if (!visited_contents[s_index - 1]) {
            /* visited(j)=true; */
            visited_contents[s_index - 1] = true;
            /* Neighbors2=RegionQuery(j); */
            /* Neighbors=find(D(i,:)<=epsilon); */
            for (i = 0; i < 9; i++) {
              logIndX[i] = (D_contents[(s_index + 9 * i) - 1] <= eps);
            }
            eml_find(logIndX, Neighbors_data, Neighbors_size);
            /* if numel(Neighbors2)>=MinPts */
            if (Neighbors_size[1] >= minPts) {
              /* Neighbors=[Neighbors Neighbors2]; */
              i = Neighbors->size[1];
              idx = Neighbors_size[1];
              k = Neighbors->size[0] * Neighbors->size[1];
              Neighbors->size[1] += Neighbors_size[1];
              emxEnsureCapacity_int32_T(Neighbors, k);
              b_Neighbors_data = Neighbors->data;
              for (k = 0; k < idx; k++) {
                b_Neighbors_data[i + k] = Neighbors_data[k];
              }
            }
          }
          /* if IDX(j)==0 */
          if (cluster->dbscan_res[s_index - 1] == 0.0) {
            /* IDX(j)=C; */
            cluster->dbscan_res[s_index - 1] = C;
          }
          /* k = k + 1; */
          b_k++;
          /* if k > numel(Neighbors) */
        } while (!(b_k > (unsigned int)Neighbors->size[1]));
      }
    }
  }
  emxFree_int32_T(&Neighbors);
  /* data_cluster = [error(2, :); dbscan_res_clm']; */
  /*  finding adjacent clusters */
  /* s_index = 1; */
  s_index = 0;
  /*  stores cluster indices */
  /* s_column = 1; */
  s_column = 0;
  /*  stores number of each cells in the cluster */
  /* av_index = 1; */
  /*  stores the index average of each cluster */
  /* cluster.dbscan_res = dbscan_res_clm'; */
  /* cluster.clt_res_cell = zeros(cell_cnt, cell_cnt); */
  /*  init maximum number of clusters containig cell indices */
  /* cluster.clt_res_soc = zeros(cell_cnt, cell_cnt); */
  memset(&cluster->clt_res_cell[0], 0, 81U * sizeof(double));
  memset(&cluster->clt_res_soc[0], 0, 81U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  /* cluster.clt_res_soc_av = zeros(cell_cnt, 2); */
  memset(&cluster->clt_res_soc_av[0], 0, 18U * sizeof(double));
  /*  init maximum number of clusters containig cell socs */
  /* for n = 1:cell_cnt */
  for (n = 0; n < 9; n++) {
    /* if (cluster.clt_res_cell(s_index, s_column) == 0) */
    i = s_index + 9 * s_column;
    if (cluster->clt_res_cell[i] == 0.0) {
      /* cluster.clt_res_cell(s_index, s_column) = n; */
      cluster->clt_res_cell[i] = (double)n + 1.0;
      /* cluster.clt_res_soc(s_index, s_column) = socs(1, n); */
      cluster->clt_res_soc[i] = socs[n];

      /* else */
      /*  find simularities whilest the data is not noise */
      /* if(cluster.dbscan_res(1, n) == cluster.dbscan_res(1, n-1) &&
       * cluster.dbscan_res(1, n) ~= -1) */
    } else if ((cluster->dbscan_res[n] == cluster->dbscan_res[n - 1]) &&
               (cluster->dbscan_res[n] != -1.0)) {
      /* s_column = s_column + 1; */
      s_column++;
      /* cluster.clt_res_cell(s_index, s_column) = n; */
      i = s_index + 9 * s_column;
      cluster->clt_res_cell[i] = (double)n + 1.0;
      /* cluster.clt_res_soc(s_index, s_column) = socs(1, n); */
      cluster->clt_res_soc[i] = socs[n];
    } else {
      /* else */
      /*  update the cluster index if no similarities found */
      /* s_column = 1; */
      s_column = 0;
      /* s_index = s_index + 1; */
      s_index++;
      /* cluster.clt_res_cell(s_index, s_column) = n; */
      cluster->clt_res_cell[s_index] = (double)n + 1.0;
      /* cluster.clt_res_soc(s_index, s_column) = socs(1, n); */
      cluster->clt_res_soc[s_index] = socs[n];
    }
    /*  calculating average of each cluster */
    /* mn_tmp = mean(nonzeros(cluster.clt_res_soc(s_index, :))); */
    idx = 0;
    b_i = -1;
    for (k = 0; k < 9; k++) {
      C = cluster->clt_res_soc[s_index + 9 * k];
      if (C != 0.0) {
        idx++;
        b_i++;
        found_index_data[b_i] = C;
      }
    }
    if (idx == 0) {
      C = 0.0;
    } else {
      C = found_index_data[0];
      for (k = 2; k <= idx; k++) {
        C += found_index_data[k - 1];
      }
    }
    C /= (double)idx;
    /* if(~isnan(mn_tmp)) */
    if (!rtIsNaN(C)) {
      /* cluster.clt_res_soc_av(s_index, 1) = fix(mn_tmp); */
      cluster->clt_res_soc_av[s_index] = trunc(C);
      /* cluster.clt_res_soc_av(s_index, 2) = s_index; */
      cluster->clt_res_soc_av[s_index + 9] = s_index + 1;
    }
  }
  /*  sorting */
  /* cluster.clt_res_soc_av = sortrows(cluster.clt_res_soc_av, 1, 'descend'); */
  sortrows(cluster->clt_res_soc_av);
  /* cluster.clt_max_count = max(cluster.clt_res_soc_av(:, 2)); */
  if (!rtIsNaN(cluster->clt_res_soc_av[9])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 9)) {
      if (!rtIsNaN(cluster->clt_res_soc_av[k + 8])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    cluster->clt_max_count = cluster->clt_res_soc_av[9];
  } else {
    D_contents_tmp = cluster->clt_res_soc_av[idx + 8];
    i = idx + 1;
    for (k = i; k < 10; k++) {
      C = cluster->clt_res_soc_av[k + 8];
      if (D_contents_tmp < C) {
        D_contents_tmp = C;
      }
    }
    cluster->clt_max_count = D_contents_tmp;
  }
  /*  finding noises */
  /* s_column = 1; */
  s_column = 0;
  /* c_column = 1; */
  idx = 0;
  /* cluster.clt_noise_soc = zeros (2, cell_cnt); */
  /*  to store noise vs soc */
  /* cluster.clt_soc = zeros (2, cell_cnt); */
  memset(&cluster->clt_noise_soc[0], 0, 18U * sizeof(double));
  memset(&cluster->clt_soc[0], 0, 18U * sizeof(double));
  /*  to store cluster vs average soc */
  /* for n = 1:cell_cnt */
  for (n = 0; n < 9; n++) {
    /* if cluster.clt_res_cell(n , 1) ~= 0 */
    if (cluster->clt_res_cell[n] != 0.0) {
      /*  noise detected */
      /* if (cluster.clt_res_cell(n, 2) == 0) */
      if (cluster->clt_res_cell[n + 9] == 0.0) {
        /* cluster.clt_noise_soc(1, s_column) = n; */
        i = s_column << 1;
        cluster->clt_noise_soc[i] = (double)n + 1.0;
        /* cluster.clt_res_cell(n, 1); */
        /* cluster.clt_noise_soc(2, s_column) = socs(1, cluster.clt_res_cell(n,
         * 1)); */
        cluster->clt_noise_soc[i + 1] = socs[(int)cluster->clt_res_cell[n] - 1];
        /* s_column = s_column + 1; */
        s_column++;
      } else {
        /* else */
        /* cluster detected */
        /* cluster.clt_soc(1, c_column) = n; */
        i = idx << 1;
        cluster->clt_soc[i] = (double)n + 1.0;
        /*  find the corresponding soc of the index (n) */
        /* found_index = find(cluster.clt_res_soc_av(:, 2) == n); */
        for (k = 0; k < 9; k++) {
          visited_contents[k] =
              (cluster->clt_res_soc_av[k + 9] == (double)n + 1.0);
        }
        s_index = b_eml_find(visited_contents, Neighbors_data);
        for (k = 0; k < s_index; k++) {
          found_index_data[k] = Neighbors_data[k];
        }
        /*  check if the found_index is not empty */
        /* if ~isempty(found_index) */
        if (s_index != 0) {
          /* cluster.clt_soc(2, c_column) =
           * cluster.clt_res_soc_av(found_index(1, 1) ,1); */
          cluster->clt_soc[i + 1] =
              cluster->clt_res_soc_av[(int)found_index_data[0] - 1];
        }
        /* c_column = c_column + 1; */
        idx++;
      }
    }
  }
  /* cluster.noise_max = [0; 0]; */
  /* cluster.noise_min = [0; 0]; */
  /* cluster.single_noise = [0; 0]; */
  cluster->single_noise[0] = 0.0;
  cluster->single_noise[1] = 0.0;
  /*  if no single noise found */
  /* if all(cluster.clt_noise_soc == 0) */
  for (i = 0; i < 18; i++) {
    x[i] = (cluster->clt_noise_soc[i] == 0.0);
  }
  idx = 2;
  for (b_i = 0; b_i < 9; b_i++) {
    logIndX[b_i] = true;
    s_index = idx;
    k = idx - 1;
    idx += 2;
    exitg1 = false;
    while ((!exitg1) && (k <= s_index)) {
      if (!x[k - 1]) {
        logIndX[b_i] = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!logIndX[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    /* cluster.noise_status = e_noise_stat.noise_not_found; */
    cluster->noise_status = noise_not_found;
    /*  minimum cluster as noise */
    /* non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
    /* cluster.noise_min(2, 1) = min(cluster.clt_res_soc_av(non_zero_indices,
     * 1)); */
    s_index = 0;
    idx = 0;
    for (b_i = 0; b_i < 9; b_i++) {
      if (cluster->clt_res_soc_av[b_i + 9] != 0.0) {
        s_index++;
        tmp_data[idx] = (signed char)b_i;
        idx++;
      }
    }
    for (i = 0; i < s_index; i++) {
      found_index_data[i] = cluster->clt_res_soc_av[tmp_data[i]];
    }
    cluster->noise_min[1] = minimum(found_index_data, s_index);
    /* tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_min(2, 1)); */
    for (i = 0; i < 9; i++) {
      visited_contents[i] =
          (cluster->clt_res_soc_av[i] == cluster->noise_min[1]);
    }
    s_index = b_eml_find(visited_contents, Neighbors_data);
    for (i = 0; i < s_index; i++) {
      found_index_data[i] = Neighbors_data[i];
    }
    /* cluster.noise_min(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2); */
    cluster->noise_min[0] =
        cluster->clt_res_soc_av[(int)found_index_data[0] + 8];
    /*  maximum cluster as noise */
    /* non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
    /* cluster.noise_max(2, 1) = max(cluster.clt_res_soc_av(non_zero_indices,
     * 1)); */
    s_index = 0;
    idx = 0;
    for (b_i = 0; b_i < 9; b_i++) {
      if (cluster->clt_res_soc_av[b_i + 9] != 0.0) {
        s_index++;
        b_tmp_data[idx] = (signed char)b_i;
        idx++;
      }
    }
    for (i = 0; i < s_index; i++) {
      found_index_data[i] = cluster->clt_res_soc_av[b_tmp_data[i]];
    }
    cluster->noise_max[1] = maximum(found_index_data, s_index);
    /* tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_max(2, 1)); */
    for (i = 0; i < 9; i++) {
      visited_contents[i] =
          (cluster->clt_res_soc_av[i] == cluster->noise_max[1]);
    }
    s_index = b_eml_find(visited_contents, Neighbors_data);
    for (i = 0; i < s_index; i++) {
      found_index_data[i] = Neighbors_data[i];
    }
    /* cluster.noise_max(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2); */
    cluster->noise_max[0] =
        cluster->clt_res_soc_av[(int)found_index_data[0] + 8];
    /*  if just one noise found */
  } else {
    n = 0;
    for (k = 0; k < 9; k++) {
      if (cluster->clt_noise_soc[(k << 1) + 1] != 0.0) {
        n++;
      }
    }
    if (n == 1) {
      /* elseif nnz(cluster.clt_noise_soc(2, :)) == 1 */
      /* cluster.noise_status = e_noise_stat.noise_single_found; */
      cluster->noise_status = noise_single_found;
      /* single_noise = cluster.clt_noise_soc(:, 1); */
      /* search_indices = 1 : cell_cnt; */
      /* if single_noise(2, 1) > cluster.average */
      if (cluster->clt_noise_soc[1] > cluster->average) {
        /*  maximum single noise */
        /* cluster.noise_max = single_noise; */
        cluster->noise_max[0] = cluster->clt_noise_soc[0];
        cluster->noise_max[1] = cluster->clt_noise_soc[1];
        /*  minimum cluster as noise */
        /* non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
        /* cluster.noise_min(2, 1) =
         * min(cluster.clt_res_soc_av(non_zero_indices, 1)); */
        s_index = 0;
        idx = 0;
        for (b_i = 0; b_i < 9; b_i++) {
          if (cluster->clt_res_soc_av[b_i + 9] != 0.0) {
            s_index++;
            tmp_data[idx] = (signed char)b_i;
            idx++;
          }
        }
        for (i = 0; i < s_index; i++) {
          found_index_data[i] = cluster->clt_res_soc_av[tmp_data[i]];
        }
        cluster->noise_min[1] = minimum(found_index_data, s_index);
        /* tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_min(2, 1));
         */
        for (i = 0; i < 9; i++) {
          visited_contents[i] =
              (cluster->clt_res_soc_av[i] == cluster->noise_min[1]);
        }
        s_index = b_eml_find(visited_contents, Neighbors_data);
        for (i = 0; i < s_index; i++) {
          found_index_data[i] = Neighbors_data[i];
        }
        /* cluster.noise_min(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2); */
        cluster->noise_min[0] =
            cluster->clt_res_soc_av[(int)found_index_data[0] + 8];
      } else {
        /* else */
        /*  maximum cluster as noise */
        /* non_zero_indices = cluster.clt_res_soc_av(:, 2) ~= 0; */
        /* cluster.noise_max(2, 1) =
         * max(cluster.clt_res_soc_av(non_zero_indices, 1)); */
        s_index = 0;
        idx = 0;
        for (b_i = 0; b_i < 9; b_i++) {
          if (cluster->clt_res_soc_av[b_i + 9] != 0.0) {
            s_index++;
            tmp_data[idx] = (signed char)b_i;
            idx++;
          }
        }
        for (i = 0; i < s_index; i++) {
          found_index_data[i] = cluster->clt_res_soc_av[tmp_data[i]];
        }
        cluster->noise_max[1] = maximum(found_index_data, s_index);
        /* tmp = find(cluster.clt_res_soc_av(:, 1) == cluster.noise_max(2, 1));
         */
        for (i = 0; i < 9; i++) {
          visited_contents[i] =
              (cluster->clt_res_soc_av[i] == cluster->noise_max[1]);
        }
        s_index = b_eml_find(visited_contents, Neighbors_data);
        for (i = 0; i < s_index; i++) {
          found_index_data[i] = Neighbors_data[i];
        }
        /* cluster.noise_max(1, 1) = cluster.clt_res_soc_av(tmp(1, 1), 2); */
        cluster->noise_max[0] =
            cluster->clt_res_soc_av[(int)found_index_data[0] + 8];
        /*  minimum single noise */
        /* cluster.noise_min = single_noise; */
        cluster->noise_min[0] = cluster->clt_noise_soc[0];
        cluster->noise_min[1] = cluster->clt_noise_soc[1];
      }
      /*  if several noises available */
    } else {
      /* else */
      /* cluster.noise_status = e_noise_stat.noise_found; */
      cluster->noise_status = noise_found;
      /*  indice to clear the noise cluster */
      /* indice_to_clear = 0; */
      /* clt_noise_soc_cpy = cluster.clt_noise_soc; */
      memcpy(&clt_noise_soc_cpy[0], &cluster->clt_noise_soc[0],
             18U * sizeof(double));
      /*  minimum niose */
      /* non_zero_indices =  clt_noise_soc_cpy(1, :) ~= 0; */
      /* [cluster.noise_min(2, 1), indice_to_clear] = min( clt_noise_soc_cpy(2,
       * non_zero_indices)); */
      s_index = 0;
      idx = 0;
      for (b_i = 0; b_i < 9; b_i++) {
        if (cluster->clt_noise_soc[b_i << 1] != 0.0) {
          s_index++;
          tmp_data[idx] = (signed char)b_i;
          idx++;
        }
      }
      cluster_size[0] = 1;
      cluster_size[1] = s_index;
      for (i = 0; i < s_index; i++) {
        found_index_data[i] = cluster->clt_noise_soc[(tmp_data[i] << 1) + 1];
      }
      b_minimum(found_index_data, cluster_size, &idx);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_min(2, 1)); */
      /* cluster.noise_min =  clt_noise_soc_cpy(:, indice_to_clear); */
      i = (idx - 1) << 1;
      cluster->noise_min[0] = cluster->clt_noise_soc[i];
      cluster->noise_min[1] = cluster->clt_noise_soc[i + 1];
      /*  clear the picked noise as minimum to avoid repeated selection */
      /* clt_noise_soc_cpy(1, indice_to_clear) = -1; */
      clt_noise_soc_cpy[i] = -1.0;
      /* clt_noise_soc_cpy(2, indice_to_clear) = -1; */
      clt_noise_soc_cpy[i + 1] = -1.0;
      /*  maximum niose */
      /* [cluster.noise_max(2, 1), indice_to_clear] = max( clt_noise_soc_cpy(2,
       * non_zero_indices)); */
      cluster_size[0] = 1;
      cluster_size[1] = s_index;
      for (i = 0; i < s_index; i++) {
        found_index_data[i] = clt_noise_soc_cpy[(tmp_data[i] << 1) + 1];
      }
      b_maximum(found_index_data, cluster_size, &idx);
      /* tmp = find( clt_noise_soc_cpy(2, non_zero_indices) ==
       * cluster.noise_max(2, 1)); */
      /* cluster.noise_max =  clt_noise_soc_cpy(:, indice_to_clear); */
      i = (idx - 1) << 1;
      cluster->noise_max[0] = clt_noise_soc_cpy[i];
      cluster->noise_max[1] = clt_noise_soc_cpy[i + 1];
      /* clear tmp clt_noise_soc_cpy non_zero_indices */
    }
  }
}

/*
 * File trailer for pso_DBSCAN.c
 *
 * [EOF]
 */
