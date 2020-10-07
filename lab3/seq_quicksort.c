#include<stdio.h> 
#include<stdlib.h>
#include<omp.h>

void swap(long long int* a,long long int* b) 
{ 
	long long int temp=*a; 
	*a=*b; 
	*b=temp; 
} 

long long int partition(long long int arr[],long long int low,long long int high) 
{ 
	long long int pivot=arr[high]; 
	long long int i=(low-1);
	for (long long int j=low;j<=high-1;j++) 
	{  
		if(arr[j]<pivot) 
		{ 
			i++; 
			swap(&arr[i],&arr[j]); 
		} 
	} 
	swap(&arr[i+1],&arr[high]); 
	return(i+1); 
} 

void QS(long long int arr[],long long int low,long long int high) 
{ 
	if (low < high) 
	{
		int x=partition(arr,low,high); 
		QS(arr,low,x-1); 
		QS(arr,x+1,high); 
	} 
} 
 
int main(int argc, char const *argv[]) 
{ 
	long long int n=50000;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
    	arr[i]=rand()%n+1;
    }
	double start,end;
	start=omp_get_wtime(); 
	QS(arr,0,n-1); 
	//printf("Sorted array :\n"); 
	//for (int i=0;i<n;i++) 
		//printf("%lld ",arr[i]); 
	printf("\n"); 
	end=omp_get_wtime();
	printf("Serial Execution of Quicksort\n");
	printf("Total Time : %lf\n",(end-start));
	printf("------------------------------------------\n");
	return 0; 
} 
