/*
 * File: db.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
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
  /* IDX(i)=C; */
  IDX->contents[(int)i - 1] = C;
  /* k = 1; */
  k = 1U;
  /* while true */
  double j_tmp;
  do {
    /* j = Neighbors(k); */
    j_tmp = Neighbors_data[(int)k - 1];
    /* if ~visited(j) */
    if (!visited->contents[(int)j_tmp - 1]) {
      int Neighbors2_size[2];
      boolean_T b_D[9];
      /* visited(j)=true; */
      visited->contents[(int)j_tmp - 1] = true;
      /* Neighbors2=RegionQuery(j); */
      /* Neighbors=find(D(i,:)<=epsilon); */
      for (b_i = 0; b_i < 9; b_i++) {
        b_D[b_i] =
            (D->contents[((int)j_tmp + 9 * b_i) - 1] <= epsilon->contents);
      }
      eml_find(b_D, Neighbors2_data, Neighbors2_size);
      /* if numel(Neighbors2)>=MinPts */
      if (Neighbors2_size[1] >= MinPts->contents) {
        int loop_ub;
        /* Neighbors=[Neighbors Neighbors2]; */
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
    /* if IDX(j)==0 */
    if (IDX->contents[(int)j_tmp - 1] == 0.0) {
      /* IDX(j)=C; */
      IDX->contents[(int)j_tmp - 1] = C;
    }
    /* k = k + 1; */
    k++;
    /* if k > numel(Neighbors) */
  } while (!(k > (unsigned int)Neighbors->size[1]));
}

/*
 * File trailer for db.c
 *
 * [EOF]
 */
