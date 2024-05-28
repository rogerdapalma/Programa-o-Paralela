#include<stdio.h>
#include <omp.h>
#define N 1000
#define CHUNKSIZE 100

int main() {
  int i, chunk;
  float a[N], b[N], c[N];

/* Inicializações */
  for (i=0; i < N; i++)
     a[i] = b[i] = i * 2.5;

  chunk = CHUNKSIZE;

#pragma omp parallel for \
   shared(a,b,c,chunk) private(i) \
   schedule(static,chunk)
   for (i=0; i < N; i++){
     c[i] = a[i] + b[i];
     printf("c[%d] = %.2f\n", i, c[i]);
   }

return 0;
}

