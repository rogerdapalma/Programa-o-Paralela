#include <stdio.h>
#include <mpi.h>
int main(int argc, char* argv[]){
		int p, id, x;		
		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &id);
		MPI_Comm_size(MPI_COMM_WORLD,&p);
		
                if (id == 0) x = 100;

                MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

                printf("Sou o processo %d x = %d\n", id, x);      
		
		MPI_Finalize ();
		return 0;
}
