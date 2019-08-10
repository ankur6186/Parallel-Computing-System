#include<stdio.h>
#include<omp.h>

int main()
{
	int i;
	scanf("%d",&i);
	omp_set_num_threads(i);
	#pragma omp parallel //num_threads(6)
	{

		int id = omp_get_thread_num();
		// int id=0;
		printf("Hello(%d) ",id);
		printf("World(%d)\n",id);
	}
	
	return 0;
}