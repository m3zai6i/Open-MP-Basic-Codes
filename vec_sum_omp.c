/* (Q). Write OpenMP code to perform vector addition using the parallel for construct. */

//Compile:      gcc -o <output> -fopenmp <fileName>.c
//Execute:      ./output
//----OR-----
//Compile:      gcc <fileName>.c -fopenmp 
//Execute:      ./a.out

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) 
{

	int n = 8;
	int i = 0;
	//int sum = 0;
	int vec1[n],vec2[n],vec_sum[n];

	//Vectors Initialization in Parallel
	#pragma omp parallel for shared(n) private(i)
	for (int i = 0; i < n; i++)
	{
		vec1[i] = i;
		vec2[i] = i;
	}

	/*-- Start of parallel region --*/
	#pragma omp parallel shared(n) private(i)
	{
		//#pragma omp for reduction (+:sum)
		#pragma omp for
		for (i=0; i<n; i++)
		{
			vec_sum[i] = vec1[i] + vec2[i];
			printf("Thread %d executes loop iteration %d\n",omp_get_thread_num(),i);
		}

	} /*-- End of parallel region --*/

	//Printing Vector Sum
	//#pragma omp parallel for shared(n) private(i)
	for (int i = 0; i < n; i++)
	{
		printf("Vec_Sum[%d] = %d\n", i,vec_sum[i]);
	}

}/*-- End of main --*/

