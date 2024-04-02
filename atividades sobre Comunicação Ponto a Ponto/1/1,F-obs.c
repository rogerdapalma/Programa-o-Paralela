#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N;
    int *full_vector = NULL; // Vetor completo no processo 0
    int *sub_vector;         // Subvetor em cada processo

    MPI_Init(&argc, &argv);                 // Inicializa o MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   // Obtém o rank do processo
    MPI_Comm_size(MPI_COMM_WORLD, &size);   // Obtém o número total de processos

    // Assumimos que N é conhecido de antemão e é divisível pelo número de processos
    N = 120; // Por exemplo, para este caso, com 3 processos
    int sub_size = N / size; // Tamanho de cada subvetor

    // Aloca espaço para o vetor completo apenas no processo 0
    if (rank == 0) {
        full_vector = malloc(N * sizeof(int));
    }

    // Aloca espaço para o subvetor em todos os processos
    sub_vector = malloc(sub_size * sizeof(int));

    // Inicializa o subvetor em cada processo
    // (Aqui você precisa inicializar o subvetor no seu problema real)
    for (int i = 0; i < sub_size; i++) {
        sub_vector[i] = rank * sub_size + i; // Simula os dados já existentes
    }

    // Coleta os subvetores de todos os processos no vetor completo no processo 0
    MPI_Gather(sub_vector, sub_size, MPI_INT, full_vector, sub_size, MPI_INT, 0, MPI_COMM_WORLD);

    // No processo 0, agora o vetor completo está disponível
    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            printf("%d ", full_vector[i]);
        }
        printf("\n");
        free(full_vector); // Libera a memória alocada para o vetor completo
    }

    // Libera a memória alocada para os subvetores em todos os processos
    free(sub_vector);

    MPI_Finalize(); // Finaliza o MPI
    return 0;
}
