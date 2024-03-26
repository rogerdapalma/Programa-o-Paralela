#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, next, prev, message, received_message;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    message = rank; // Cada processo envia seu próprio rank como mensagem

    // Definindo o próximo e o anterior no anel
    next = (rank + 1) % size;
    prev = (rank - 1 + size) % size;

    // Todos os processos enviam e recebem simultaneamente
    MPI_Sendrecv(&message, 1, MPI_INT, next, 0,
                 &received_message, 1, MPI_INT, prev, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("Processo %d recebeu a mensagem %d do processo %d\n", rank, received_message, prev);

    MPI_Finalize();
    return 0;
}

