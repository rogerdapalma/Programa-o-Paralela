#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, N = 10;
    int send_buffer[N / size], recv_vector[N]; // Assumindo que N é divisível pelo número de processos

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Cada processo inicializa sua parte do vetor
    for (int i = 0; i < N / size; i++) {
        send_buffer[i] = rank * (N / size) + i + 1;
    }

    // Processo 0 recebe o vetor completo de todos os processos
    MPI_Gather(send_buffer, N / size, MPI_INT, recv_vector, N / size, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Processo 0 recebeu o vetor completo: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", recv_vector[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}

