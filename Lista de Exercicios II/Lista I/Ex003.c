#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, value;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    value = rank; // Cada processo envia seu próprio rank como escalar

    if (rank == 0) {
        int received_value;
        printf("Processo 0 recebeu os seguintes valores: %d", value);
        for (int i = 1; i < size; i++) {
            MPI_Recv(&received_value, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf(", %d", received_value);
        }
        printf("\n");
    } else {
        MPI_Send(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

