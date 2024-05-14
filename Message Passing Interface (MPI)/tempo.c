#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[]){
		int p, id, x;		
		double tInicial, tFinal;

		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &id);
		MPI_Comm_size(MPI_COMM_WORLD,&p);

		MPI_Barrier(MPI_COMM_WORLD);	        
		if (id == 0){
			tInicial = MPI_Wtime();
			x = 100;
 		}

                MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

		printf("Sou o processo %d x = %d\n", id, x);      
		
		MPI_Barrier(MPI_COMM_WORLD);	        
		if (id == 0){
			tFinal = MPI_Wtime();
			printf("Tempo: %fs\n", tFinal - tInicial);
 		}

		MPI_Finalize ();
		return 0;
}
