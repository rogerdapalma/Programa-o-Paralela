#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, next, prev, message;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    message = rank; // Cada processo envia seu próprio rank como mensagem

    // Definindo o próximo e o anterior no anel
    next = (rank + 1) % size;
    prev = (rank - 1 + size) % size;

    if (rank == 0) {
        // O processo 0 envia primeiro e depois recebe
        MPI_Send(&message, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
        MPI_Recv(&message, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else {
        // Os outros processos recebem primeiro e depois enviam
        MPI_Recv(&message, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&message, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
    }

    printf("Processo %d recebeu a mensagem %d do processo %d\n", rank, message, prev);

    MPI_Finalize();
    return 0;
}

