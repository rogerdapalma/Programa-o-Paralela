#include <omp.h>
#include <stdio.h>

#define CHUNKSIZE 2
#define N 10

int main (){

   int i, chunk = CHUNKSIZE, id;
   float a[N], b[N];

   tI = omp_get_wtime();

   #pragma omp parallel private(i, id) shared(a, b, chunk) 
   {
     id = omp_get_thread_num();
     #pragma omp for schedule(dynamic,chunk) nowait
     for (i=0; i < N; i++){
		a[i] = i*10;
		b[i] = a[i]*3 + 10;
                printf("thread %d b[%d] = %.2f\n", id, i, b[i]);
     }
   }

return 0;
}
