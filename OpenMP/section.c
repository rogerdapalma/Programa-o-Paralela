//Código fonte: section.c

#include <stdio.h>
#include <omp.h>
#define N 1000

int main ()
{

int i, id;
float a[N], b[N], c[N], d[N];

/* Inicializações */
for (i=0; i < N; i++) {
  a[i] = i * 1.5;
  b[i] = i + 22.35;
  }

#pragma omp parallel shared(a,b,c,d) private(i, id)
{
  id = omp_get_thread_num();
  #pragma omp sections nowait
  // nowait nao cria barreira no fim da seções
  {

    #pragma omp section
    for (i=0; i < N; i++){
      c[i] = a[i] + b[i];
      printf("Thread %d: c[%d] = %.2f\n", id, i, c[i]);
    }

    #pragma omp section
    for (i=0; i < N; i++){
      d[i] = a[i] * b[i];
      printf("Thread %d: c[%d] = %.2f\n", id, i, c[i]);
    }

    }  /* fim das seções */

  }  /* término da região paralela */

return 0;
}


