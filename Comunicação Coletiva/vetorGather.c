#include <stdlib.h>
#include <mpi.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define N 12

int main (int argc, char* argv[]){
	int p, id, i;
	float *v, *vetor;
     
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &id);
    MPI_Comm_size (MPI_COMM_WORLD, &p);

    if (id == 0) {
            v = (float *) malloc(N/p*sizeof(float));
            vetor = (float *) malloc(N*sizeof(float));
    } else {
            v = (float *) malloc(N/p*sizeof(float));
    }
    
    //cada processo produz os dados na sua parte do vetor             
    for(i = 0; i < N/p; i++){
		v[i] = (i+1) * (id+1);
                printf("%.1f P%d\n", v[i], id);
    }

  
    //esta operação reune o vetor inteiro em um processo, no caso no P0
    MPI_Gather(v, N/p, MPI_FLOAT, vetor, N/p, MPI_FLOAT, 0, MPI_COMM_WORLD);
          
    if (id == 0){
  	   printf("Vetor completo no P0\n");
           for(i = 0; i<N; i++)
		printf("%.2f\n", vetor[i]);

           free(vetor);
    }
    
    free(v);

    MPI_Finalize();
    
    return 0;
}
