#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	static long num_steps=100000;
	double step,x,pi,sum=0.0,start,end;
	int i;
	step=1.0/(double)num_steps;
	start=omp_get_wtime();
	for(i=0;i<num_steps;i++)
	{
		x=(i+0.5)*step;
		sum+=4.0/(1.0+x*x);
	}
	pi=step*sum;
	end=omp_get_wtime();
	printf("PI = %lf\n",pi );
	printf("Time = %lf\n",end-start );
	return 0;
}