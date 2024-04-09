#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define N 12

int main (int argc, char* argv[]){
	int p, my_rank, i, j;
	float *matriz;
     
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size (MPI_COMM_WORLD, &p);

    if (my_rank==0) {
            matriz = (float *) malloc((N*N)*sizeof(float));
    } else {
       matriz = (float *) malloc((N*N)/p*sizeof(float));
    }
     
    if (my_rank == 0) {
        for(i=0; i<N; i++)
            for (j=0; j<N; j++)
                matriz[i*N+j]=i+j;
            }
            
    MPI_Scatter(matriz, (N*N)/p, MPI_FLOAT, matriz, (N*N)/p, MPI_FLOAT, 0, MPI_COMM_WORLD);
          
    
    for (i=0; i <N/p; i++)
	for(j = 0; j<N; j++)
		printf("%.2f processo%d\n", matriz[i*N+j], my_rank);
    
   
    free(matriz);
   
    MPI_Finalize();
 

    return 0;
}
