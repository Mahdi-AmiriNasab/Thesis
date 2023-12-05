/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 01-Dec-2023 15:17:17
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "pso.h"
#include "pso_terminate.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "pso_dbscan.h"

/* Function Declarations */
static void argInit_1x9_real_T(double result[9]);

static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : double result[9]
 * Return Type  : void
 */
static void argInit_1x9_real_T(double result[9])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 9; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_pso();
  /* Terminate the application.
You do not need to do this more than one time. */
  pso_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_pso(void)
{
  struct0_T global_best;
  struct1_T eq_step;
  struct2_T stio;

	// pso_DBSCAN clustering test
	/*
	double eps = 16.3130;
	double cluster_dbscan_res		[100];
	double cluster_clt_res_cell		[100];
	double cluster_clt_res_soc		[100];
	double cluster_res_soc_av		[100];
	double cluster_clt_noise_soc	[100];	
	double cluster_clt_soc			[100];
	double cluster_noise_max		[100];
	double cluster_noise_min		[100];
	double cluster_single_noise 	[100];
  	double average;
	double cluster_clt_max_count;
	e_noise_stat cluster_noise_status;

  double soc[9] = {7, 88, 10, 95, 52, 50, 48, 42, 76};
//   Initialize function 'pso' input arguments. 
//    Initialize function input argument 'soc_in'. 
//   mp_tmp = argInit_real_T();
//   Call the entry-point 'pso'. 
//   pso(soc, 2, 0.5, 0.5, 0, &global_best, &eq_step, &stio);
	pso_DBSCAN(soc, 2, eps, &average, cluster_dbscan_res, cluster_clt_res_cell, cluster_clt_res_soc
	, cluster_res_soc_av, &cluster_clt_max_count, cluster_clt_noise_soc, cluster_clt_soc, cluster_noise_max
	, cluster_noise_min, cluster_single_noise, &cluster_noise_status);

	*/

	// log_clustering test
  	/*
		double soc[9] = {7, 88, 10, 95, 52, 50, 48, 42, 76};
		double lg_time;
		double lg_inconsistency;
		double lg_eq_overlap;

		lg_time = log_clustering(soc , 2, &lg_inconsistency, &lg_eq_overlap);
	*/


	// b_pso_DBSCAN clustering test
	
	double eps = 16.3130;
	double cluster_dbscan_res		[100];
	double cluster_clt_res_cell		[100];
	double cluster_clt_res_soc		[100];
	double cluster_res_soc_av		[100];
	double cluster_clt_noise_soc	[100];	
	double cluster_clt_soc			[100];
	double cluster_noise_max		[100];
	double cluster_noise_min		[100];
	double cluster_single_noise 	[100];
  	double average;
	double cluster_clt_max_count;
	e_noise_stat cluster_noise_status;

  double soc[9] = {7, 88, 10, 95, 52, 50, 48, 42, 76};
//   Initialize function 'pso' input arguments. 
//    Initialize function input argument 'soc_in'. 
//   mp_tmp = argInit_real_T();
//   Call the entry-point 'pso'. 
//   pso(soc, 2, 0.5, 0.5, 0, &global_best, &eq_step, &stio);
	b_pso_DBSCAN(soc, 2, &average, cluster_dbscan_res, cluster_clt_res_cell, cluster_clt_res_soc
	, cluster_res_soc_av, &cluster_clt_max_count, cluster_clt_noise_soc, cluster_clt_soc, cluster_noise_max
	, cluster_noise_min, cluster_single_noise, &cluster_noise_status);

	
	

}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
