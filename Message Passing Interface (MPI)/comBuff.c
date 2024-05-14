#include <stdio.h>
#include <mpi.h>

#define MAX_BUF 100
#define N 10

int main(int argc, char* argv[]){
		int p, id, i;		
		int buffer_size = MAX_BUF;
		int a[N], b[N];
		double tInicial, tFinal;
		char buffer[MAX_BUF];
		MPI_Status status;

		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &id);
		MPI_Comm_size(MPI_COMM_WORLD,&p);

		MPI_Barrier(MPI_COMM_WORLD);	        
		if (id == 0){
			tInicial = MPI_Wtime();
 		}
		
		MPI_Buffer_attach(buffer, buffer_size);

		if (id == 0){
			for (i = 0; i < 10; i++)
				a[i] = i;
			MPI_Bsend(a, N, MPI_INT, 1, 0, MPI_COMM_WORLD);
		}
		else if (id == 1){
			MPI_Recv(b, N, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
			for (i = 0; i<10; i++)
				printf("b[%d] = %d\n", i, b[i]);
		     }

		MPI_Buffer_detach(buffer, &buffer_size);
		
		MPI_Barrier(MPI_COMM_WORLD);	        
		if (id == 0){
			tFinal = MPI_Wtime();
			printf("Tempo: %fs\n", tFinal - tInicial);
 		}

		MPI_Finalize ();
		return 0;
}
