#include<stdio.h>
#include<omp.h>

static long num_steps = 10000000;
double step;
#define NUM_THREADS 4

int main()
{
	// Serial
	// double time_spent = 0.0;
	// double begin = clock();
	// int i;
	// double x,pi,sum=0.0;
	// step = 1.0/(double)num_steps;
	// for(int i=0;i<num_steps;i++)
	// {
	// 	x = (i+0.5)*step;
	// 	sum = sum + 4.0/(1.0+x*x);
	// }
	// pi = step*sum;

	// Parallel(Simple)
	// double time = omp_get_wtime();
	// int i,nthreads;
	// double pi,sum[NUM_THREADS];
	// step = 1.0/(double)num_steps;
	// omp_set_num_threads(NUM_THREADS);

	// #pragma omp parallel
	// {
	// 	int i,id,nthrds;
	// 	double x;
	// 	id = omp_get_thread_num();
	// 	nthrds = omp_get_num_threads();
	// 	if(id == 0)
	// 		nthreads = nthrds;
	// 	for(i=id,sum[id]=0.0;i<num_steps;i=i+nthrds)
	// 	{
	// 		x = (i+0.5)*step;
	// 		sum[id] += 4.0/(1.0+x*x);
	// 	}
	// }
	// for(i=0,pi=0.0;i<nthreads;i++)
	// 	pi += sum[i]*step;

	// Parallel(Critical)
	// double time = omp_get_wtime();
	// int i,nthreads;
	// double pi,sum=0.0;
	// step = 1.0/(double)num_steps;
	// omp_set_num_threads(NUM_THREADS);
	// #pragma omp parallel
	// {
	// 	int i,id,nthrds;
	// 	double x,sum;
	// 	id = omp_get_thread_num();
	// 	nthrds = omp_get_num_threads();
	// 	if(id == 0)
	// 		nthreads = nthrds;
	// 	id = omp_get_thread_num();
	// 	nthrds = omp_get_num_threads();
	// 	for(i=id,sum=0.0;i<num_steps;i=i+nthreads)
	// 	{
	// 		x = (i+0.5)*step;
	// 		sum += 4.0/(1.0+x*x);
	// 	}
	// 	#pragma omp critical
	// 		pi += sum*step;
	// }

	// Parallel(Atomic)
	// double pi,time = omp_get_wtime();
	// step = 1.0/(double)num_steps;
	// int i,nthreads;
	// omp_set_num_threads(NUM_THREADS);
	// #pragma omp parallel
	// {
	// 	int i,id,nthrds;
	// 	double x,sum;
	// 	id = omp_get_num_threads();
	// 	nthrds = omp_get_num_threads();
	// 	if(id == 0)
	// 		nthreads = nthrds;
	// 	id = omp_get_thread_num();
	// 	nthrds = omp_get_num_threads();
	// 	for(i=id,sum=0.0;i<num_steps;i=i+nthrds)
	// 	{
	// 		x = (i+0.5)*step;
	// 		sum += 4.0/(1.0+x*x);
	// 	}
	// 	sum = sum*step;
	// 	#pragma atomic
	// 		pi += sum;
	// }

	// Parallel(Reduction)
	int i,nthreads;
	double x,pi,sum=0.0;
	double time=omp_get_wtime();
	step = 1.0/(double)num_steps;
	#pragma omp parallel
	{
		double x;
		#pragma omp for reduction(+:sum)
			for(i=0;i<num_steps;i++)
			{
				x = (i+0.5)*step;
				sum = sum+4.0/(1.0+x*x);
			}
	}
	pi = step*sum;

	// double end = clock();
	// printf("Execution Time is %lf\n", (double)(end-begin)/(double)CLOCKS_PER_SEC);
	// printf("Execution Time is %f", time_spent);
	time = omp_get_wtime() - time;
	printf("Execution Time is %lf\n", time);
	printf("Value of pi is %lf\n", pi);

	return 0;
}