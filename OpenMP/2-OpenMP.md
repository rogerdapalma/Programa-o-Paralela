# OpenMP - Parte 2

## Sumário
- Work-Sharing Constructs
  - Diretiva for
  - Diretiva sections
  - Diretiva single
- Sincronização
  - Diretiva critical
  - Diretiva barrier
- Operação de redução
  - Diretiva reduction

## Work-Sharing Constructs
- Paraleliza a execução de uma região de código entre as threads da seção paralela.
- Não cria novas threads.
- Há uma barreira implícita no final da construção da região compartilhada.

### Diretivas
- **for**
  - Especifica a divisão das iterações de um laço entre os threads da seção paralela.
  - Paralelismo de Dados
  - Trabalhada na aula anterior!

- **sections**
  - Paralelismo de tarefas

- **single**
  - Serializa uma seção de código.

### Diretiva sections - Exemplo
- Neste exemplo, o que foi executado em paralelo?
- Altere o código removendo a diretiva `nowait`. O que acontece?

### Diretiva sections
- Divide o processamento entre as diferentes threads da região paralela, designando diferentes processamentos a cada thread ou grupo de threads.
- Há uma barreira implícita no final da diretiva `sections`, exceto se usada a cláusula `nowait`.

```c
#pragma omp sections [clause ...]
private (list)
firstprivate (list)
lastprivate (list)
reduction (operator: list)
```

### Diretiva single

- Especifica um código, dentro da região paralela, que será executado somente por uma thread.
- Especifica um código sequencial
- Por exemplo, para manipulação de E/S

```c
#pragma omp single [clause ...]
private (list)
firstprivate (list)
nowait
```
### Diretiva single - Exemplo

```c
#pragma omp single private (id)
{
    id = omp_get_thread_num();
    printf("Digite um valor para thread %d", id);
    scanf("%d", &valor);
}
```
### Teste a diretiva single, como neste exemplo, em uma região paralela de código e verifique o resultado.

- Diretivas combinadas
  - Sincronização

  - Proteção de seção crítica de código
  - Diretivas:
  - Critical
  - Barrier

### Diretiva critical

- Define uma seção de código que será executada com exclusão mútua.
- Define a proteção à seção crítica do código
- Somente uma thread de cada vez poderá executar esta seção.

### Diretiva barrier

- Define um ponto de sincronização de todas threads da aplicação.
- Quando uma thread chegar na diretiva barrier, irá esperar até que todos os outros threads tenham - chegado no mesmo ponto do código.

```c
#pragma omp barrier
```

### Operação de Redução
#### Diretiva reduction

- Realiza a redução de variáveis que aparecem na lista de reduction.
- Uma cópia de cada variável da lista é criada para cada thread.
 -Ao término da redução, as cópias são armazenadas na variável compartilhada.




