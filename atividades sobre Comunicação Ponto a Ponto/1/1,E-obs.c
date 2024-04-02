#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N;
    int *x = NULL; // Vetor completo no processo 0
    int *sub_x;    // Subvetor para cada processo

    MPI_Init(&argc, &argv);                 // Inicializa o MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   // Obtém o rank do processo
    MPI_Comm_size(MPI_COMM_WORLD, &size);   // Obtém o número total de processos

    // O processo 0 define o tamanho N e inicializa o vetor
    if (rank == 0) {
        N = 120; // Por exemplo, N deve ser divisível por size
        x = malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            x[i] = i; // Inicializa o vetor com algum valor
        }
    }

    // Broadcast do tamanho N para todos os processos
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Calcula o tamanho do subvetor
    int sub_size = N / size;

    // Cada processo aloca espaço para o seu subvetor
    sub_x = malloc(sub_size * sizeof(int));

    // Distribui partes iguais do vetor x para todos os processos
    MPI_Scatter(x, sub_size, MPI_INT, sub_x, sub_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Agora, cada processo tem uma parte do vetor original
    // Processo 0: x[0] a x[sub_size-1]
    // Processo 1: x[sub_size] a x[2*sub_size-1], e assim por diante...

    // (Aqui cada processo pode fazer o que precisa com o seu subvetor)

    // Libera memória alocada
    free(sub_x);
    if (rank == 0) {
        free(x);
    }

    MPI_Finalize(); // Finaliza o MPI
    return 0;
}
