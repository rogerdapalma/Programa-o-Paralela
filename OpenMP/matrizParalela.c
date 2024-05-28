#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 20
#define N 50000

int main (){

   long int i, j, chunk = CHUNKSIZE, id, tam;
   float *a;
   double tInicial, tFinal;

   tam = (long int) N * N;
   tInicial = omp_get_wtime();

   a = (float *) malloc( tam * sizeof(float));

#pragma omp parallel private(i, j) shared(a, chunk) 
  {
//    id = omp_get_thread_num();
    #pragma omp for schedule(dynamic,chunk) nowait
     for (i=0; i < N; i++){
	for(j=0; j < N; j++){
             //   printf("%f\t", (float)(n * N));
	     //   printf("%f\t", (float)(N - (n - 1))); 
		*(a + (i*N+j)) = i*j;
             //   printf("a[%d] = %.2f\n", n, a[n-1]);
        }
     }
    }

   tFinal = omp_get_wtime();
   printf("Tempo de execução: %f segundos\n", tFinal - tInicial);
   free(a);
return 0;
}
