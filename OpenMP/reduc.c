#include <omp.h>
#include <stdio.h>

int main(){
  int   i, n = 100, chunk = 10;
  float a[n], somatorioA = 0.0;

  for (i=0; i < n; i++)
     a[i] = i;

#pragma omp parallel for \
  default(shared) private(i) \
  schedule(static,chunk) \
  reduction(+:somatorioA) 

  for (i=0; i < n; i++)
    somatorioA = somatorioA + a[i];

  printf("Final somatorio de A = %f\n",somatorioA);

return 0;
}
