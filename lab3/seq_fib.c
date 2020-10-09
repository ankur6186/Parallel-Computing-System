#include <stdio.h>
#include<stdlib.h>
#include<omp.h>

void fibonacci(float n) 
{ 
	float f1=0,f2=1,i; 
	if(n<1) 
		return; 
	for(i=1;i<=n;i++) 
	{ 
		//printf("%f ",f2); 
		float next=f1+f2; 
		f1=f2; 
		f2=next; 
	} 
} 

int main() 
{ 
	double start1,end1;
	start1=omp_get_wtime();
	for(int i=0;i<100;i++)
	{
		float n=100;
		double start,end;
		start=omp_get_wtime();
		fibonacci(n);
		//printf("\n");
		end=omp_get_wtime();
	}
	end1=omp_get_wtime();
	printf("Serial Execution of Fibbonacci Series \n");
	printf("Total Time : %lf seconds\n",(end1-start1)/100);
	printf("------------------------------------------------\n");
	return 0; 
} 
