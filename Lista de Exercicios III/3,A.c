// MPI 3 - exercise 1
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 12

int main(int argc, char *argv[]) {
  int p, id, bloco;
  int *a, *b, *c;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);

  bloco = N / p;

  if (id == 0) {
    a = malloc(N * sizeof(int));
    b = malloc(N * sizeof(int));
    c = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
      a[i] = i;
      b[i] = rand() % 10;
    }
    // partitioning of the vector
    for (int dest = 1; dest < p; dest++) {
      MPI_Send(&a[bloco * dest], bloco, MPI_INT, dest, 1, MPI_COMM_WORLD);
      MPI_Send(&b[bloco * dest], bloco, MPI_INT, dest, 1, MPI_COMM_WORLD);
      printf("processo o enviou para %d\n", dest);
    }
    // operations with a and b here, potentially to fill c
    // omitted: code to handle the master's own chunk
  } else {
    a = malloc(bloco * sizeof(int));
    b = malloc(bloco * sizeof(int));
    c = malloc(bloco * sizeof(int));
    MPI_Recv(a, bloco, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    MPI_Recv(b, bloco, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
    // operations with a and b here, to fill c
    // omitted: code for slave processes to perform on their chunk
  }
  for (int i = 0; i < bloco; i++) {
    c[i] = a[i] + b[i];
    printf("P%d c[%d] = %d = %d + %d\n", id, i, c[i], a[i], b[i]);
  }
  // omitted: code to gather c from all processes to the root

  free(a);
  free(b);
  free(c);

  MPI_Finalize();
  return 0;
}
