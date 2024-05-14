#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAX 100

int main(int argc, char *argv[]) {
	int id, p, tag = 0, total_num, i;
	int origem=0, destino=1, numeros[MAX];
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
        MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	if (id == origem) {
		/* Escolhe uma quantidade aleatória de inteiros para enviar para o processo 1 */
		srand(MPI_Wtime());
		total_num = (rand() / (float)RAND_MAX) * MAX;
        	/* Inicializa o vetor */
		for (i = 0; i < total_num; i++)
			numeros[i] = i;
		/* Envia a quantidade de inteiros para o processo 1 */
		MPI_Send(numeros, total_num, MPI_INT, destino, tag, MPI_COMM_WORLD);
		printf("Processo %d enviou %d números para 1\n", origem, total_num);
        }
	else if (id == destino) {
		/* Recebe no máximo MAX números do processo 0 */
		MPI_Recv(numeros, MAX, MPI_INT, origem, tag, MPI_COMM_WORLD, &status);
		/* Quando chegar a mensagem, verificar o status para determinar quantos números foram realmente recebidos */
		MPI_Get_count(&status, MPI_INT, &total_num);
		/* Imprime a quantidade de números e a informação adicional que está no manipulador "estado" */
		printf("Processo %d recebeu %d números. Origem da mensagem = %d, etiqueta = %d\n\n", destino, total_num, status.MPI_SOURCE, status.MPI_TAG);
		printf("Vetor recebido: ");
		for (i = 0; i < total_num; i++) printf("%d\t", numeros[i]);
	}
	MPI_Finalize();
	return 0;
}




