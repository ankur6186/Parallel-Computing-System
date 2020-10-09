
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define m1 70                 /* number of rows in matrix A */
#define n1  65                /* number of columns in matrix A */
#define n2 55                  /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k, chunk;
double	a[m1][n1],           /* matrix A to be multiplied */
	b[n1][n2],           /* matrix B to be multiplied */
	c[m1][n2];           /* result matrix C */

chunk = 2;                    /* set loop iteration chunk size */
double start = omp_get_wtime();
/*** Spawn a parallel region explicitly scoping all variables ***/
#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k)
  {
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Starting matrix multiple example with %d threads\n",nthreads);
    printf("Initializing matrices...\n");
    }
  /*** Initialize matrices ***/
  #pragma omp for schedule (static, chunk) 
  for (i=0; i<m1; i++)
    for (j=0; j<n1; j++)
      a[i][j]= i*j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<n1; i++)
    for (j=0; j<n2; j++)
      b[i][j]= i+j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<m1; i++)
    for (j=0; j<n2; j++)
      c[i][j]= 0;

  /*** Do matrix multiply sharing iterations on outer loop ***/
  /*** Display who does which iterations for demonstration purposes ***/
  printf("Thread %d starting matrix multiply...\n",tid);
  #pragma omp for schedule (static, chunk)
  for (i=0; i<m1; i++)    
    {
    printf("Thread=%d did row=%d\n",tid,i);
    for(j=0; j<n2; j++)       
      for (k=0; k<n1; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }   /*** End of parallel region ***/

/*** Print results ***/
printf("******************************************************\n");
printf("Result Matrix:\n");
for (i=0; i<m1; i++)
  {
  for (j=0; j<n2; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf("Total time taken for this computation= %f ms\n",(omp_get_wtime()-start)*1000);
printf ("Done.\n");

}