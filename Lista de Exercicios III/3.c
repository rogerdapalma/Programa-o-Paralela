#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Função para calcular fatorial
void* calcularFatorial(void* arg) {
    int n = *((int*)arg);
    unsigned long long fatorial = 1; // use unsigned long long para lidar com números grandes
    for(int i = 1; i <= n; ++i) {
        fatorial *= i;
    }
    unsigned long long* resultado = malloc(sizeof(unsigned long long));
    *resultado = fatorial;
    return resultado;
}

// Função para calcular o n-ésimo número de Fibonacci
void* calcularFibonacci(void* arg) {
    int n = *((int*)arg);
    unsigned long long primeiro = 0, segundo = 1, fibonacci = n; // lida com números grandes

    for (int i = 2; i <= n; ++i) {
        fibonacci = primeiro + segundo;
        primeiro = segundo;
        segundo = fibonacci;
    }
    unsigned long long* resultado = malloc(sizeof(unsigned long long));
    *resultado = fibonacci;
    return resultado;
}

int main() {
    pthread_t thread1, thread2;
    int numero;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Erro: A entrada deve ser um número inteiro positivo.\n");
        return 1;
    }

    // Inicia as threads
    pthread_create(&thread1, NULL, calcularFatorial, &numero);
    pthread_create(&thread2, NULL, calcularFibonacci, &numero);

    // Aguarda as threads terminarem e captura os resultados
    void *fatorial;
    void *fibonacci;
    pthread_join(thread1, &fatorial);
    pthread_join(thread2, &fibonacci);

    // Imprime os resultados
    printf("Fatorial de %d: %llu\n", numero, *((unsigned long long*) fatorial));
    printf("Fibonacci de %d: %llu\n", numero, *((unsigned long long*) fibonacci));

    // Libera a memória alocada
    free(fatorial);
    free(fibonacci);

    return 0;
}
