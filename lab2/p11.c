#include<stdlib.h>
#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
	int N,i,a[N],b[N];
	printf("Enter size of array : ");
	scanf("%d",&N);
	double start=omp_get_wtime();
	for(i=0;i<N;i++)
	{
		a[i]=i;
	}
	for(i=0;i<N;i++)
	{
		a[i]=a[i]+b[i];
	}
	double end=omp_get_wtime();
	printf("%lf\n",(start-end));
	return 0;
}
