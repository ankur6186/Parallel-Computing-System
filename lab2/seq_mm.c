#include<stdlib.h> 
#include<stdio.h> 
#include<omp.h>

#define m1 511 
#define m2  510             
#define n1  510              
#define n2 500

int main() 
{  
	int a[m1][m2],b[n1][n2],mul[m1][n2];
	double start=omp_get_wtime();
	if(m2==n1)
	{
		//printf("Enter elements into 1st matrix : \n");
		for(int i=0;i<m1;i++)
		{
			for(int j=0;j<m2;j++)
			{
				a[i][j]= i;
			}
		}
		//printf("Enter elements into 2nd matrix : \n");
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<n2;j++)
			{
				b[i][j]= i+j;
			}
		}
		for(int i=0;i<m1;i++)
			{
				for(int j=0;j<n2;j++)
				{
					mul[i][j]=0;
					for(int k=0;k<m2;k++)
					{
						mul[i][j]+=a[i][k]*b[k][j];
					}
				}
			}
		for(int i=0;i<m1;i++)
		{
			for(int j=0;j<n2;j++)
			{
				printf("%d ",mul[i][j]);
			}
			printf("\n");
		}
	}
	else
	printf("The matrices are not compatible for multiplication\n"); 
	double end=omp_get_wtime();
	printf("Total time : %lf\n",(end-start) );
	return 0; 
} 

// Time taken = 1.17 seconds