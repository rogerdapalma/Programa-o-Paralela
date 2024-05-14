# MPI – Message Passing Interface

## Parte 3

### Sumário
- Criando barreiras: `MPI_Barrier`
- Medindo o tempo de execução: `MPI_Wtime`
- Usando `MPI_Status` e `MPI_Get_count`

### Criando barreiras: `MPI_Barrier`

Com a função `MPI_Barrier`, é possível criar uma barreira, um ponto de sincronização onde todos os processos de um comunicador se encontram (SILVA, 2019 p.43).

Todos os processos do comunicador devem chamar a função `MPI_Barrier`. Os processos só prosseguem a execução quando todos os processos do comunicador passado como argumento à função `MPI_Barrier`, estiverem na barreira. É uma forma de sincronização.

### Medindo o tempo de execução

Podemos medir o tempo de execução de uma aplicação paralela, tomando o tempo inicial e o tempo final do processamento. A função `MPI_Wtime()` retorna o tempo total de relógio decorrido em segundos, em precisão dupla. Devemos lembrar que a execução é em ambiente com memória distribuída e, por isso, possivelmente haverá uma diferença nos relógios das máquinas. Portanto, um dos processos faz a medida de tempo.

### Usando `MPI_Status` e `MPI_Get_count`

Na estrutura `MPI_Status`, há informações sobre o recebimento de mensagens com a função `MPI_Recv`. `MPI_Status` possui três elementos:
- origem;
- etiqueta (tag);
- e informação de erro (SILVA, 2019 p.36).

Extrai a quantidade de itens recebidos na mensagem. Protótipo:
`int MPI_Get_count(MPI_Status *estado, MPI_Datatype tipo_mpi, int *total)`
O número total de elementos recebidos na mensagem será retornado na variável `total`.

### Exemplo
Exemplo adaptado de SILVA (2019, p.36).

