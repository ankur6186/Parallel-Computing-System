#include <stdio.h>
#include<stdlib.h>
#include <omp.h>


int main (int argc, char **argv)
{
	long int i,num_steps=100000;
	double x,steps,sum,pi; 
	double start,end;
	sum=0.0;
	steps=1.0/(double)num_steps;
	//start=omp_get_wtime();
	#pragma omp parallel private(i,x)
	{
		start=omp_get_wtime();
		#pragma omp for reduction(+:sum)
		for (i=0;i<num_steps;i++) 
		{
	        x=(i+0.5)*steps;
	        sum+=4.0/(1.0+x*x);
		}
		end=omp_get_wtime();
	} 
	//end=omp_get_wtime();

	/* All threads join master thread and terminate */
	pi= steps*sum;
	printf("PI = %lf\n",pi);
	printf("Time = %lf\n",end-start );
}