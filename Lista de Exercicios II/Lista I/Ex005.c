#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N = 10;
    int vector[N], recv_buffer[N / size]; // Assumindo que N é divisível pelo número de processos

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Inicializa o vetor
        for (int i = 0; i < N; i++) {
            vector[i] = i + 1;
        }
    }

    // Distribui o vetor entre todos os processos
    MPI_Scatter(vector, N / size, MPI_INT, recv_buffer, N / size, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Processo %d recebeu: ", rank);
    for (int i = 0; i < N / size; i++) {
        printf("%d ", recv_buffer[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}

