#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

float fibonacci(int n)
{
	float i,j;
	if(n<2)
		return n;
	else
	{
		#pragma omp task shared(i) firstprivate(n)
		i=fibonacci(n-1);

		#pragma omp task shared(j) firstprivate(n)
		j=fibonacci(n-2);

		#pragma omp taskwait
		return(i+j);
	}
}

int main(int argc, char const *argv[])
{
	float n,t;
	double start,end;
	n=strtol(argv[2],NULL,10);
	t=strtol(argv[1],NULL,10);
	omp_set_num_threads(t);
	start=omp_get_wtime();
	//float k;
	printf("Parallel Execution of Fibonacci with data-scoping and %f threads\n",t);
	#pragma omp parallel shared(n)
	{
		#pragma omp single
		{
			//k=fibonacci(n);
			printf("Fibonacci of %f : %f\n",n,fibonacci(n));
		}
	}
	end=omp_get_wtime();
	printf("Total Time : %lf\n",(end-start));
	printf("----------------------------------------------\n");
	return 0;
}