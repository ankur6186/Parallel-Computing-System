#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define m1 300                 /* number of rows in matrix A */
#define n1  500                /* number of columns in matrix A */
#define n2 600                  /* number of columns in matrix B */

int main (int argc, char *argv[])
{
  int	tid, nthreads, i, j, k, chunk;
  double	a[m1][n1],           /* matrix A to be multiplied */
	b[n1][n2],           /* matrix B to be multiplied */
	c[m1][n2];           /* result matrix C */

  int N;    /*Number of processes and chuck size */
  printf("Enter number of threads:");
  scanf("%d",&N);
chunk =100;         
omp_set_num_threads(N);
double start = omp_get_wtime();

/*** Entry into  parallel region  ***/
printf("Start of parallel region\n");
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

  printf("Thread %d starting matrix multiply...\n",tid);/*** Display who does which iterations for demonstration purposes ***/
  #pragma omp for schedule (static, chunk)
  for (i=0; i<m1; i++)
    {
    //printf("Thread=%d did row=%d\n",tid,i);
    for(j=0; j<n2; j++)
      for (k=0; k<n1; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }   /*** End of parallel region ***/
    printf("End of parallel region\n");

printf("Total time taken for this computation= %f ms\n",(omp_get_wtime()-start)*1000);
printf ("Done.\n");

}
