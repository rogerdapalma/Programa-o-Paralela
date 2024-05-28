#include<stdio.h>
#include <omp.h>
int main()
{
    int x = 0;

    #pragma omp parallel shared(x)
    {
    // #pragma omp critical
        x = x + 1;
    }
   
   /* fim da seção paralela*/
   printf("x = %d\n", x);
   
  return 0;
} 

