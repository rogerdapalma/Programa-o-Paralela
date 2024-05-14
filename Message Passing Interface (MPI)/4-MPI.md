# MPI – Message Passing Interface

## Parte 4

### Sumário
- Comunicação ponto-a-ponto
- Send bloqueante
- Send não bloqueante
- Receive bloqueante
- Receive não bloqueante

### Comunicação Ponto-a-Ponto

#### Send Bloqueante
- **Send Bloqueante** continua a execução somente se as modificações nos dados a serem enviados não afetam o recebimento dos mesmos.
  - **Síncrono**: sincronizado com o receive; confirmar o envio da mensagem.
  - **Assíncrono**: usa o buffer do sistema para armazenar os dados a serem enviados.

#### Receive Bloqueante
- Retorna somente após todos os dados serem recebidos e estarem disponíveis para o uso.

#### Send e Receive Não-Bloqueantes
- Estas operações retornam imediatamente, sem esperar a entrega da mensagem ou o buffer do sistema estar vazio.
- Há operação `wait` para permitir esperar pelas operações não-bloqueantes.
- São usados para sobrepor operações de computação e comunicação, melhorando o desempenho da aplicação.

#### MPI_Send
```c
int MPI_Send(void* message, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)

#### Send Síncrono

- Usado quando processo remetente precisa saber se o processo destinatário recebeu a mensagem.
- O processo destinatário envia ao remetente uma mensagem informando o recebimento.
- É recebido pelo remetente antes do send estar completo.
- Não necessita bufferização.

```c
int MPI_Ssend(void* buffer, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
```
#### Send Buferizado: MPI_Bsend

- Operação Send é local (usa buffer do sistema).
- Para estar completa não precisa de um receive correspondente.
- Copia a mensagem para um buffer do sistema para posterior transmissão.

```c
int MPI_Bsend(void* buffer, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
int MPI_Buffer_attach(void* buffer, int buffer_size)
int MPI_Buffer_detach(void* buffer_address, int* size_ptr)
```

#### Send Não-bloqueante
```c
int MPI_Isend(void* buffer, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request request)
```


#### Receive Bloqueante

```c
int MPI_Recv(void* message, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status status)
```

#### Receive Não-Bloqueante

```c
int MPI_Irecv(void* buffer, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request request)
```

#### Exemplos de MPI_Bsend e MPI_Isend

- Exemplos demonstram o uso de MPI_Bsend e MPI_Isend em operações bloqueantes e não-bloqueantes.
