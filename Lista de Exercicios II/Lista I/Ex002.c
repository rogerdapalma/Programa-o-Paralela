#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    const int N = 10; // Tamanho do vetor
    int vector[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Inicializa o vetor
        for (int i = 0; i < N; i++) {
            vector[i] = i + 1;
        }
        // Envia o vetor para todos os outros processos
        for (int i = 1; i < size; i++) {
            MPI_Send(vector, N, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(vector, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Processo %d recebeu o vetor: ", rank);
        for (int i = 0; i < N; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}

