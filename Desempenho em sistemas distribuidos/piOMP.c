#include <omp.h>
#include <stdio.h>

#define N 1000000000

int main(void) {
	double pi = 0.0f; long i;
	double ti, tf;
	int qt;

   	ti = omp_get_wtime();

   	#pragma omp parallel reduction(+: pi)
   	{
	   qt = omp_get_num_threads();
	   
   	   #pragma omp for
		for (i=0; i<N; i++)
		{
			double t = (double) ((i+0.5)/N);
			pi += 4.0/(1.0+t*t);
		}
    	}
    	
	tf = omp_get_wtime();
    
        printf("pi=%f\ntempo: %fs\ntotal threads: %d\n",pi/N, tf-ti, qt);

	return 0;
}
