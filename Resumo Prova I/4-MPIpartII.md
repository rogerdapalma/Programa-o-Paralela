# MPI – MESSAGE PASSING INTERFACE

## Parte 2

## Comunicação Coletiva

Envolve todos os processos do comunicador. Todos os processos do comunicador precisam chamar a comunicação coletiva.

Operações:
-  Broadcast
-  Scatter
-  Gather
-  AllGather
-  Reduce
-  AllReduce

## Broadcast

Um processo envia o mesmo dado para cada um dos outros processos do comunicador. Todos os processos devem especificar o mesmo root e o mesmo comunicador.

### Broadcast (2)

```c
int MPI_Bcast(void* message, int count, MPI_Datatype datatype, int root, MPI_Comm comm);
```
-  message: endereço do dado a ser enviado.
-  count: número de elementos.
-  datatype: MPI_Datatype.
-  root: rank do processo remetente.
-  comm: comunicador.

### Broadcast (3)

message é in no processo root. Uma mensagem Broadcast não pode ser recebida com um MPI_Recv. count e datatype devem ser os mesmos em todos os processos do comunicador, assim não há necessidade do parâmetro status. Não há tag nas funções de comunicação coletiva.
### Broadcast (4)

### Exemplo:
```
float K;

MPI_Bcast(&K, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
```

### Scatter

- Um-para-todos. Um processo divide e distribui seus dados entre todos os outros processos. Especifica um processo root e todos os processos precisam especificar o mesmo processo root e o mesmo comunicador.
### Scatter (2)

```
int MPI_Scatter(void* send_data, int send_count, MPI_Datatype send_type, void* recv_data, int recv_count, MPI_Datatype recv_type, int root, MPI_Comm comm);
```
-    send_data: endereço do dado referenciado em cada processo.
-    send_count: número de elementos que cada processo enviará.
-    send_type: MPI_Datatype do envio.
-    recv_data: endereço onde ficará o dado recebido.
-    recv_count: número de elementos a receber de cada processo.
-    recv_type: MPI_Datatype do recebimento.
-    root: rank do processo que receberá.
-    comm: comunicador.

### Gather (3)

- Os parâmetros com prefixo recv têm significado somente ao processo root. send_count = recv_count e send_type = recv_type.

### Gather (4)

#### Exemplo:
```
float A[N/p];
float B[N];
...
MPI_Gather(A, N/p, MPI_FLOAT, B, N/p, MPI_FLOAT, 0, MPI_COMM_WORLD);
```
### AllGather

- Equivale à execução do gather por cada um dos processos do comunicador. MPI_Allgather envia o conteúdo de send_data de cada um dos processos para recv_data de cada um dos processos do comunicador.

### AllGather (2)

```
int MPI_Allgather(void* send_data, int send_count, MPI_Datatype send_type, void* recv_data, int recv_count, MPI_Datatype recv_type, MPI_Comm comm);
```

-    send_data: endereço do dado referenciado em cada processo.
-    send_count: número de elementos que cada processo enviará.
-    send_type: MPI_Datatype do envio.
-    recv_data: endereço onde ficará o dado recebido.
-    recv_count: número de elementos a receber de cada processo.
-    recv_type: MPI_Datatype do recebimento.
-    comm: comunicador.

### AllGather (3)

#### Exemplo:
```
float a;
float b[p];
...
MPI_Allgather(&a, 1, MPI_FLOAT, b, 1, MPI_FLOAT, MPI_COMM_WORLD);
```

### Reduce

- É uma operação de comunicação coletiva que combina os dados armazenados na memória referenciada por operando com a operação em operador e armazena na posição referenciada por resultado no processo root.
### Reduce (2)

Exemplo: MPI_MAX

```
a b c d e

root MPI_Reduce

1 2 3
0 1 2
3 1 1
0 2 4
2 1 2 a b c d e

root
1 2 3
0 1 2
3 1 1
0 2 4
2 1 2

MPI_MAX
3 2 4

```


### Reduce (3)

```
int MPI_Reduce(void* operando, void* resultado, int count, MPI_Datatype datatype, MPI_Op operador, int root, MPI_Comm comm);

```

-    operando: endereço do dado a ser combinado.
-    resultado: endereço onde o resultado será armazenado.
-    count: número de posições de memória do tipo datatype.
-    datatype: MPI_Datatype.
-    operador: operação de redução (por exemplo, MPI_SUM, MPI_MAX).
-    root: rank do processo que receberá o resultado.
-    comm: comunicador.

### Reduce (4)
```
Operações MPI:

    MPI_MAX
    MPI_MIN
    MPI_SUM
    MPI_PROD
```

### Reduce (5)

#### Exemplo: Soma Global
```
float a[N], total[N];
MPI_Reduce(&a, &total, N, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

```

### AllReduce

- A operação MPI_Allreduce faz com que cada um dos processos receba o resultado da operação global. Não há parâmetro root na função.
### AllReduce (2)

```
int MPI_Allreduce(void* operando, void* resultado, int count, MPI_Datatype datatype, MPI_Op operador, MPI_Comm comm);

```

- Os parâmetros têm o mesmo significado da função MPI_Reduce.
### AllReduce (3)

#### Exemplo: MPI_MAX

```
a b c d e

root MPI_Reduce

1 2 3
0 1 2
3 1 1
0 2 4
2 1 2 a b c d e

root
1 2 3
0 1 2
3 1 1
0 2 4
2 1 2

3 2 4
3 2 4
3 2 4
3 2 4
3 2 4
```
### Bibliografia

PACHECO, Peter. Parallel Programming with MPI. San Francisco: Morgan Kaufmann, 1997.
