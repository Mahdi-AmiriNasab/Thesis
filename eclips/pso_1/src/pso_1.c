/*
 ============================================================================
 Name        : pso_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pso.h"
#include "pso_internal_types.h"
#include "pso_terminate.h"
#include "pso_types.h"
#include "rt_nonfinite.h"
#include "calculate_overlap.h"


#ifndef typedef_emxArray_struct1_T_1x100
#define typedef_emxArray_struct1_T_1x100
typedef struct {
  struct1_T data[100];
  int size[2];
} emxArray_struct1_T_1x100;
#endif /* typedef_emxArray_struct1_T_1x100 */

static emxArray_struct1_T_1x50 eq_step;
static struct2_T stio;
static double dv[9];
struct0_T global_best;
double w_time = 0.2;
double w_inc = 0.8;
double w_ovp = 0;




int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	for(int i = 0;i < 1;i++)
	{

		  double soc[9] = {7, 88, 10, 95, 52, 50, 48, 42, 76};
//		  pso(soc, 2, w_time, w_inc, w_ovp, &global_best, eq_step.data, eq_step.size, &stio);
//		  printf("b c = %2.2f  b p = %2.2f s t = %2.2f s i = %2.2f s o = %2.2f \n",
//				  global_best.cost,
//				  global_best.position,
//				  stio.time,
//				  stio.inconsistency,
//				  stio.eq_overlap);
//		      double test_case1[] = {7, 39, 23, 55};
//		      double test_case2[] = {10, 10, 42, 38};
//		      double test_case3[] = {7, 34, 16, 52};
//		      double test_case4[] = {88, 88, 48, 51};
//
//		      printf("Overlap for test_case1: %.2f\n", calculate_overlap(test_case1, 4));
//		      printf("Overlap for test_case2: %.2f\n", calculate_overlap(test_case2, 4));
//		      printf("Overlap for test_case3: %.2f\n", calculate_overlap(test_case3, 4));
//		      printf("Overlap for test_case4: %.2f\n", calculate_overlap(test_case4, 4));

		    // Test cases as specified
		    double test_case1[] = {3.0, 2.0, 1.0, 0.0, 0.0, 5.0, 0.0};
		    double test_case2[] = {100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0};
		    double test_case3[] = {5.0, 2.0, 0.0, 1.0, 20.0, 60.0, 7.0};
		    double test_case4[] = {10.0, 80.0, 50.0, 30.0, 10.0, 0.0, 5.0};
		    double test_case5[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
		    double test_case6[] = {1.0, 2.0, 3.0, 4.0, 5.0, 4.0, 3.0};

		    // Print the test cases and call the function
		    printf("Overlap for Test Case 1: %.2f\n", calculate_overlap(test_case1, 7));
		    printf("Overlap for Test Case 2: %.2f\n", calculate_overlap(test_case2, 7));
		    printf("Overlap for Test Case 3: %.2f\n", calculate_overlap(test_case3, 7));
		    printf("Overlap for Test Case 4: %.2f\n", calculate_overlap(test_case4, 7));
		    printf("Overlap for Test Case 5: %.2f\n", calculate_overlap(test_case5, 7));
		    printf("Overlap for Test Case 6: %.2f\n", calculate_overlap(test_case6, 7));

	}

	puts("program terminated");/* prints !!!Hello World!!! */


	return EXIT_SUCCESS;
}
