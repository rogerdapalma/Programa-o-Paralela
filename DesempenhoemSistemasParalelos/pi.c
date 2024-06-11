#include <stdio.h> 
#include <omp.h>

#define N 1000000000

int main(void) {
double pi = 0.0f; long i;
double ti, tf;

ti = omp_get_wtime();
	for (i=0; i<N; i++)
	{
		double t=(double) ((i+0.5)/N);
		pi += 4.0/(1.0+t*t);
	}
tf = omp_get_wtime();
	printf("pi=%f\ntempo: %fs\n",pi/N, tf-ti);
return 0;
}
