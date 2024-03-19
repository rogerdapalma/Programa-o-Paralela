#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  	int p, id, source, dest, tag = 1;
	char message[100];
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	if (id != 0) {
	    sprintf(message, "Saudações do processo % d\n", id);
	    dest = 0;
	    MPI_Send(message, strlen(message) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
	  } else{
	    for (source = 1; source < p; source++) {
	      MPI_Recv(message, 100, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
	      printf("%s – recebida de % d\n", message, source);
	   } 
	  }
	  MPI_Finalize();
}
