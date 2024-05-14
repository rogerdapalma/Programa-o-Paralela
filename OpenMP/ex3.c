#include <omp.h>
#include <stdio.h>

int main (void)  {
   int id;

   omp_set_num_threads(8);

   // Início de uma região paralela
   #pragma omp parallel private(id)
   {
     id = omp_get_thread_num();
     printf("Olá da thread = %d\n", id);
   }

   printf("Fim das Threads\n\nExecução Sequencial\n\n");
   
   printf("Execução paralela novamente\n");
   #pragma omp parallel private (id) num_threads(2)
   {
     id = omp_get_thread_num();
     printf("Olá da thread = %d\n", id);
   }

   return 0;
}
