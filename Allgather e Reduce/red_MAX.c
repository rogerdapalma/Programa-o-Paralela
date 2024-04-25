#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

#define N 3

int main(int argc, char* argv[]){
		int p, id, i;
                int a[N], resultado[N];		
		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &id);
		MPI_Comm_size(MPI_COMM_WORLD,&p);
		
                for(i=0; i<N; i++){
		        a[i] = i + id;
			printf("Processo %d a[%d] = %d\n", id, i, a[i]);
                }

		MPI_Reduce(a, resultado, N, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
		
		if (id == 0) {

	        	for(i=0; i<N; i++){
				printf("Processo %d resultado[%d] = %d\n", id, i, resultado[i]);
                	}
		}

		MPI_Finalize ();
		return 0;
}
