#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[]){
		int p, id;		
		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &id);
		MPI_Comm_size(MPI_COMM_WORLD,&p);
		printf("- Ola!!!, do processo %d\n", id);
		MPI_Finalize ();
		for( ; ;);
		return 0;
}

