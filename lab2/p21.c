#include<stdlib.h> 
#include<stdio.h> 

int main() 
{  
	int m1,m2,n1,n2;
	printf("Enter the row and column size of 1st matrix : ");
	scanf("%d %d",&m1,&m2);
	printf("Enter the row and column size of 2nd matrix : ");
	scanf("%d %d",&n1,&n2);
	int a[m1][m2],b[n1][n2],mul[m1][n2];
	
	if(m2==n1)
	{
		printf("Enter elements into 1st matrix : \n");
		for(int i=0;i<m1;i++)
		{
			for(int j=0;j<m2;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("Enter elements into 2nd matrix : \n");
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<n2;j++)
			{
				scanf("%d",&b[i][j]);
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
	return 0; 
} 
