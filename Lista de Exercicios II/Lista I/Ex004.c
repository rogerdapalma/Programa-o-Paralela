#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    const int N = 5; // Tamanho do vetor
    int vector[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Cada processo inicializa seu próprio vetor
    for (int i = 0; i < N; i++) {
        vector[i] = rank * N + i + 1;
    }

    if (rank == 0) {
        int received_vector[N];
        printf("Processo 0 recebeu os seguintes vetores:\n");
        printf("Vetor do processo 0: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");

        for (int i = 1; i < size; i++) {
            MPI_Recv(received_vector, N, MPI

