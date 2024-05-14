# OpenMP

## Parte 1

### Sumário
- Modelos de Memória
- Processos x Threads
- OpenMP
  - O que é OpenMP?
  - Seção paralela de código
  - Diretivas
  - Construção de regiões paralelas
  - Funções OpenMP
  - Diretiva for

### Modelos de Memória
- **Memória Compartilhada**: Todos os processadores têm acesso à memória compartilhada.
- **Memória Distribuída**: Cada processador tem sua própria memória local.
- **Modelo híbrido**

### Processos x Threads
- **Processos**:
  - Espaço de endereçamento por processo.
  - Não compartilha o espaço de endereçamento com outros processos.
- **Threads**:
  - Espaço de endereçamento compartilhado com o processo.
  - Múltiplos threads compartilham o mesmo espaço de endereçamento.

### O que é OpenMP?
- Open Multi-Processing (OpenMP) é uma especificação aberta para multiprocessamento definida como um padrão pela indústria de hardware, software e academia.
- **Application Program Interface** (API) para programação paralela no modelo de memória compartilhada (shared memory).
- **Versões**:
  - 1997: versão 1.0
  - 2005: versão 2.5
  - 2008: versão 3.0
  - 2013: versão 4.0
  - 2015: versão 4.5
  - 2018: versão 5.0
  - 2020: versão 5.1
  - 2021: versão 5.2
  - 2023: versão 6.0

### OpenMP Diretivas
- Diretivas do compilador para Fortran, C/C++, e implementações em Java como JOMP e JaMP.
- Plataformas suportadas incluem Linux/Unix e Windows.
- Especificação disponível em [OpenMP.org](http://openmp.org/wp/).

### Modelo de Execução do tipo fork-join
- Paralelismo em laços de repetição com inclusão de diretivas do compilador.
- Algumas partes do código são sequenciais e outras partes, paralelas.

### Seção Paralela de Código
- Definição de seção paralela de código:
  ```c
  #pragma omp parallel
  {
      // Code executed by all threads
  }
  ```
- Variáveis compartilhadas: Utilizadas por todas threads da aplicação.
- Variáveis privadas: Escopo de cada thread; podem ter valores diferentes em cada thread.

### Construção de Regiões Paralelas

- Uma região paralela é uma seção de código executada por múltiplas threads.
- Diretiva parallel: Cria um grupo de threads, incluindo uma thread principal (id = 0).
- No final da seção paralela, implicitamente há uma barreira, e somente a thread principal continua a execução.

### Funções OpenMP

- omp_get_thread_num(): Retorna o id da thread.
- omp_get_num_threads(): Retorna o número total de threads.
- omp_set_num_threads(int): Define o número de threads da aplicação.

### Exemplos

- Compilação: gcc -o arquivo_executavel arquivo_fonte.c -fopenmp
- Execução: ./arquivo_executavel

### Diretiva for

- Especifica a divisão das iterações de um laço entre as threads da seção paralela.

```c
#pragma omp for [clause ...]
schedule (type [, chunk])
reduction (operator: list)

nowait
```

### Exemplos

```c
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    printf("Hello, world.\n");
    return 0;
}
```
```c
#include <stdio.h>
#include <omp.h>

int main() {
    int nthreads, id;

    // Início de uma região paralela
    #pragma omp parallel private(id)
    {
        // Busca o id da thread
        id = omp_get_thread_num();
        printf("Olá da thread = %d\n", id);

        // Podemos na região paralela, usar o paradigma SPMD.
        // Neste exemplo, somente a thread Zero executa
        if (id == 0) {
            // Número total de threads
            nthreads = omp_get_num_threads();
            printf("Número de threads = %d\n", nthreads);
        }
    }
    // Fim da região paralela

    // Execução sequencial
    printf("Término do programa\n");
    return 0;
}

```

```c
#include <stdio.h>
#include <omp.h>

int main() {
    int id;

    omp_set_num_threads(8);

    // Início de uma região paralela
    #pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        printf("Olá da thread = %d\n", id);
    }

    printf("Fim das Threads\n\nExecução Sequencial\n\n");

    printf("Execução paralela novamente\n");
    #pragma omp parallel private(id) num_threads(2)
    {
        id = omp_get_thread_num();
        printf("Olá da thread = %d\n", id);
    }

    return 0;
}
```

### Diretiva for: Cláusulas

- SCHEDULE: especifica como o laço é dividido entre as threads.
- STATIC: as iterações são divididas em pedaços de tamanho chunk, estaticamente.
- DYNAMIC: as iterações são divididas em pedaços de tamanho chunk e escalonadas dinamicamente entre as threads.

### Exemplos de Execução

- Exemplo 4: Execute várias vezes este exemplo para perceber o escalonamento dynamic. Altere a forma de escalonamento para static e verifique a execução.
- Exemplo 5: Cálculo do valor do número Pi.
- Exemplo 6: Cálculo do valor do número Pi com OpenMP.
