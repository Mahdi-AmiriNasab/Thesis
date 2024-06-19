/*
 * File: db.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 19-Jun-2024 19:12:12
 */

/* Include Files */
#include "db.h"
#include "find.h"
#include "pso_emxutil.h"
#include "pso_internal_types.h"
#include "pso_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * function ExpandCluster(i,Neighbors,C)
 *
 * Arguments    : const d_captured_var *D
 *                const captured_var *epsilon
 *                b_captured_var *IDX
 *                c_captured_var *visited
 *                const captured_var *MinPts
 *                double i
 *                emxArray_real_T *Neighbors
 *                double C
 * Return Type  : void
 */
void ExpandCluster(const d_captured_var *D, const captured_var *epsilon,
                   b_captured_var *IDX, c_captured_var *visited,
                   const captured_var *MinPts, double i,
                   emxArray_real_T *Neighbors, double C)
{
  double *Neighbors_data;
  int Neighbors2_data[9];
  int b_i;
  int i1;
  unsigned int k;
  Neighbors_data = Neighbors->data;
  /* 'db:24' IDX(i)=C; */
  IDX->contents[(int)i - 1] = C;
  /* 'db:25' k = 1; */
  k = 1U;
  /* 'db:26' while true */
  double j_tmp;
  do {
    /* 'db:27' j = Neighbors(k); */
    j_tmp = Neighbors_data[(int)k - 1];
    /* 'db:28' if ~visited(j) */
    if (!visited->contents[(int)j_tmp - 1]) {
      int Neighbors2_size[2];
      bool b_D[9];
      /* 'db:29' visited(j)=true; */
      visited->contents[(int)j_tmp - 1] = true;
      /* 'db:30' Neighbors2=RegionQuery(j); */
      /* 'db:46' Neighbors=find(D(i,:)<=epsilon); */
      for (b_i = 0; b_i < 9; b_i++) {
        b_D[b_i] =
            (D->contents[((int)j_tmp + 9 * b_i) - 1] <= epsilon->contents);
      }
      eml_find(b_D, Neighbors2_data, Neighbors2_size);
      /* 'db:31' if numel(Neighbors2)>=MinPts */
      if (Neighbors2_size[1] >= MinPts->contents) {
        int loop_ub;
        /* 'db:32' Neighbors=[Neighbors Neighbors2]; */
        b_i = Neighbors->size[1];
        loop_ub = Neighbors2_size[1];
        i1 = Neighbors->size[0] * Neighbors->size[1];
        Neighbors->size[1] += Neighbors2_size[1];
        emxEnsureCapacity_real_T(Neighbors, i1);
        Neighbors_data = Neighbors->data;
        for (i1 = 0; i1 < loop_ub; i1++) {
          Neighbors_data[b_i + i1] = Neighbors2_data[i1];
        }
      }
    }
    /* 'db:35' if IDX(j)==0 */
    if (IDX->contents[(int)j_tmp - 1] == 0.0) {
      /* 'db:36' IDX(j)=C; */
      IDX->contents[(int)j_tmp - 1] = C;
    }
    /* 'db:38' k = k + 1; */
    k++;
    /* 'db:39' if k > numel(Neighbors) */
  } while (!((long)k > Neighbors->size[1]));
}

/*
 * File trailer for db.c
 *
 * [EOF]
 */
