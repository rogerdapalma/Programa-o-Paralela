#include <stdlib.h>
#include <mpi.h>
#include <stdio.h>

#define N 12

int main (int argc, char* argv[]){
	int p, id, i;
	float *v, *vetor;
     
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &id);
    MPI_Comm_size (MPI_COMM_WORLD, &p);

    v = (float *) malloc(N/p*sizeof(float));
    vetor = (float *) malloc(N*sizeof(float));
    
    //cada processo produz os dados na sua parte do vetor             
    for(i = 0; i < N/p; i++){
		v[i] = (i+1) * (id+1);
                printf("%.1f P%d\n", v[i], id);
    }

  
    //esta operação reune o vetor inteiro em todos os processos
    MPI_Allgather(v, N/p, MPI_FLOAT, vetor, N/p, MPI_FLOAT, MPI_COMM_WORLD);
          
    for(i = 0; i<N; i++)
		printf("P%d: %.2f\n", id, vetor[i]);

    free(vetor);
    free(v);

    MPI_Finalize();
    
    return 0;
}
