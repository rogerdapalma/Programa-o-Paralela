#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

float* alocarVetor(int n){
	int i;
	float *v;

	v = (float *) malloc(n * sizeof(float));

	if (v == NULL) {
		printf("Erro na alocação de memória...");
		exit(-1);
	}

	return v;
}

void gerarVetor(float *v, int n){
        int i;

	for (i = 0; i < n; i++){
		v[i] = rand() % 100;
	}
	
        return ;
}

void mostrarVetor(float *v, int n, char *nome, int rank){
	int i;

	printf("\nP%d: Vetor %s: ", rank, (char *)nome);
	for (i = 0; i < n; i++){
		printf("%.1f  ", v[i]);
	}

	return ;
}

void somarVetores(float *v1, float *v2, float *v3, int n, int rank){
	int i;

	printf("\n\nP%d: Vetor Soma: ", rank);
	for (i = 0; i < n; i++){
                v3[i] = v1[i] + v2[i];
		printf("%.1f  ", v3[i]);
	}

	return ;
}


int main(int argc, char* argv[]){
		int p, id, tam;
		float *a, *b, *c;	
	
		MPI_Init (&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &id);
		MPI_Comm_size(MPI_COMM_WORLD,&p);

		if (id == 0){
			printf("Insira o tamanho dos vetores:\n");
			scanf("%d", &tam);
		}

		MPI_Bcast(&tam, 1, MPI_INT, 0, MPI_COMM_WORLD);

		if (id == 0){
			a = alocarVetor(tam);
			b = alocarVetor(tam);
			c = alocarVetor(tam/p);
			gerarVetor(a, tam);
			gerarVetor(b, tam);
			mostrarVetor(a, tam, "A", id);			
			mostrarVetor(b, tam, "B", id);
		}else{
			a = alocarVetor(tam/p);
			b = alocarVetor(tam/p);
			c = alocarVetor(tam/p);
		}
	

              MPI_Scatter(a, tam/p, MPI_FLOAT, a, tam/p, MPI_FLOAT, 0, MPI_COMM_WORLD);
              MPI_Scatter(b, tam/p, MPI_FLOAT, b, tam/p, MPI_FLOAT, 0, MPI_COMM_WORLD);

              mostrarVetor(a, tam/p, "A", id);			
	      mostrarVetor(b, tam/p, "B", id);

	      somarVetores(a, b, c, tam/p, id);	      

	      free(a);
	      free(b);
	      free(c);
              MPI_Finalize ();
	      return 0;
}
