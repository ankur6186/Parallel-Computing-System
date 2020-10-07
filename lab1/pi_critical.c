#include<stdio.h>
#include <omp.h>
static long num_steps=100000;         
double step;
#define NUM_THREADS 2
int main(int argc, char const *argv[])
{
	double  pi,start,end;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel
	{
		int i, id,nthreads,numthreads;    
		double x;
		id=omp_get_thread_num();
		nthreads=omp_get_num_threads();
		start=omp_get_wtime();
		if (id == 0)   
		numthreads= nthreads;   
		id = omp_get_thread_num();
		nthreads= omp_get_num_threads();
		for (i=id;i< num_steps; i=i+nthreads)
		{
			x = (i+0.5)*step;
			#pragma omp critical
			pi += 4.0/(1.0+x*x);
		}
		end=omp_get_wtime();
	}
	pi*=step;
	printf("PI = %lf\n",pi);
	printf("Time = %lf\n",end-start );
}
