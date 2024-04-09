# MPI – MESSAGE PASSING INTERFACE

## Parte 1

## Sumário

- Introdução
- Funções Básicas – parte I
- O que é uma Mensagem?
- MPI Datatype
- Comunicação Ponto-a-Ponto
- Funções Básicas – parte II

## Introdução

O padrão MPI foi desenvolvido em 1993 por indústrias (Cray, SGI, HP, Mach, NEC, Intel, IBM), universidades e laboratórios de pesquisa. Existem várias implementações do MPI, como mpich (ANL e MSU), CHIMP (Univ. Edinburgh) e LAM (Ohio Supercomputers).

## Introdução (2)

Os programas MPI podem seguir o modelo SPMD (Single Program, Multiple Data) ou o modelo mestre-escravo. Existe apenas um único arquivo executável para todos os processos.

## Introdução (3)

Os identificadores da biblioteca MPI começam com `MPI_`. As mensagens só podem ser transmitidas dentro de um comunicador, que é um conjunto de processos que conseguem enxergar uns aos outros.

## Introdução (4)

Cada processo em um comunicador é identificado por um número de 0 a n-1, onde n é o número total de processos. Esse número é chamado de rank ou identificador. As mensagens devem identificar o comunicador e o processo destinatário.

## Funções Básicas – Parte I

As funções básicas do MPI incluem:

- `MPI_Init`: Inicializa o ambiente MPI.
- `MPI_Finalize`: Finaliza o ambiente MPI.
- `MPI_Comm_size`: Retorna o número de processos no comunicador.
- `MPI_Comm_rank`: Retorna o rank do processo no comunicador.

## O que é uma Mensagem?

Uma mensagem no MPI é um vetor de elementos de um determinado tipo de dado do MPI (datatype MPI).

## MPI Datatype

Todas as mensagens no MPI são tipadas. O send e o receive devem especificar o tipo de mensagem.

## Comunicação Ponto-a-Ponto

A comunicação ponto-a-ponto ocorre entre dois processos. Para enviar uma mensagem, o processo remetente identifica o rank do processo destinatário. O processo destinatário também deve identificar de quem receberá a mensagem.

## Comunicação Ponto-a-Ponto (2)

Existem quatro modos de comunicação ponto-a-ponto: Standard, Synchronous, Buffered e Ready. Cada modo tem suas próprias características e regras para completar o envio e recebimento de mensagens.

## Comunicação Ponto-a-Ponto (3)

Todas as quatro formas de comunicação ponto-a-ponto podem ser bloqueantes ou não-bloqueantes. As rotinas não-bloqueantes devem ser testadas para verificar o término com `MPI_TEST` ou `MPI_WAIT`.

## Funções Básicas – Parte II

As funções básicas do MPI na parte II incluem:

- `MPI_Send`: Envia uma mensagem.
- `MPI_Recv`: Recebe uma mensagem.

## MPI_Send

`MPI_Send` é usado para enviar uma mensagem. Os parâmetros incluem o endereço do dado a ser enviado, o número de elementos, o tipo de dado, o rank do destinatário, a tag e o comunicador.

## MPI_Recv

`MPI_Recv` é usado para receber uma mensagem. Os parâmetros incluem o endereço onde o dado será armazenado, o número de elementos, o tipo de dado, o rank do remetente, a tag, o comunicador e o status.

## Exemplo

Um exemplo básico de programa MPI que utiliza `MPI_Send` e `MPI_Recv` para comunicação entre processos.

## Considerações Finais

Para compilar um programa em C que utiliza MPI, deve-se incluir o cabeçalho `<mpi.h>`. Para compilar, usa-se `mpicc`, e para executar, usa-se `mpirun` ou `mpiexec` com a opção `-np` para especificar o número de processos.

## Bibliografia

- PACHECO, Peter. Parallel Programming with MPI. San Francisco: Morgan Kaufmann, 1997.
- MPI: A Message-Passing Interface Standard. Disponível em http://www.mpi-forum.org/docs/mpi-11-html/mpi-report.html.

