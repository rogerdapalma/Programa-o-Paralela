#include <stdio.h>
#include <omp.h>

int main (){

int nthreads, id;

//Início de uma região paralela
#pragma omp parallel private(id)
  {

  // Busca o id da thread
  id = omp_get_thread_num();
  printf("Olá da thread = %d\n", id);

  // Podemos na região paralela, usar o paradigma SPMD.
  // Neste exemplo, somente a thread Zero executa
  if (id == 0) {
    // Número total de threads
    nthreads = omp_get_num_threads();
    printf("Número de threads = %d\n", nthreads);
    }
  } //Fim da região paralela

  //Execução sequencial
  printf("Término do programa\n");

  return 0;
}
