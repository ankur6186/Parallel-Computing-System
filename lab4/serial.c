/******************************************************************************
* FILE: lab222.c
* DESCRIPTION:  
*   OpenMp Lab2 problem 2.1- Matrix Multiply - C Version
*   Demonstrates a matrix multiply using serial. 
* AUTHOR: Venkatesh B H
* LAST REVISED: 21/08/19
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define m1 300                 /* number of rows in matrix A */
#define n1  500                /* number of columns in matrix A */
#define n2 600                  /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
int	tid, nthreads,i,j,k,chunk;
double	a[m1][n1],           /* matrix A to be multiplied */
	b[n1][n2],           /* matrix B to be multiplied */
	c[m1][n2];           /* result matrix C */
  double start=omp_get_wtime();
  printf("Initializing matrices...\n");

  printf("Start of Serial region for matrix multiplication\n");
  /*** Initialize matrices ***/
  for (i=0; i<m1; i++)
    for (j=0; j<n1; j++)
      a[i][j]= i*j;
 
  for (i=0; i<n1; i++)
    for (j=0; j<n2; j++)
      b[i][j]= i+j;
  
  for (i=0; i<m1; i++)
    for (j=0; j<n2; j++)
      c[i][j]= 0;

  
  for (i=0; i<m1; i++)    
    {
    for(j=0; j<n2; j++)       
      for (k=0; k<n1; k++)
        c[i][j] += a[i][k]*b[k][j];
    }
    printf("End of Serial region\n");
/*** Print results ***/
// printf("******************************************************\n");
// printf("Result Matrix:\n");
// for (i=0; i<m1; i++)
//   {
//   for (j=0; j<n2; j++) 
//     printf("%6.2f   ", c[i][j]);
//   printf("\n"); 
//   }
// printf("******************************************************\n");
printf("Total time taken for this computation= %f ms\n",(omp_get_wtime()-start)*1000);
printf ("Done.\n");

}