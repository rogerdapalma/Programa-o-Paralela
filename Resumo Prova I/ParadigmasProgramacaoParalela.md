# PARADIGMAS DE PROGRAMAÇÃO PARALELA

## Sumário

- Definições
- Paradigmas de Programação Paralela
- Mapeamento de dados

## Definições

- **Processo:** Uma instância de um programa em execução.
- **Programa Paralelo:** Um programa que pode executar várias instruções simultaneamente.
- **Paradigmas de programação paralela:** Diferentes maneiras de gerenciar os processos, incluindo criação, destruição, comunicação e sincronização de processos.

## Paradigmas de Programação Paralela

1. **Shared Memory Programming (Programação com Memória Compartilhada):** Os processos compartilham um espaço de memória comum e podem comunicar-se através desse espaço.
2. **Message Passing (Passagem de Mensagens):** Os processos comunicam-se enviando mensagens uns aos outros.
3. **Data Parallel Languages (Linguagens de Paralelismo de Dados):** Os processos executam as mesmas operações em diferentes partes dos dados.

## Shared Memory Programming

- **Memória Compartilhada:** Os processos têm acesso a um espaço de memória comum.
- **Memória Distribuída:** Cada processo tem seu próprio espaço de memória, mas pode emular memória compartilhada através de mecanismos de comunicação.

### Exemplo

```c
int private_x;
shared int sum = 0;

// Código que pode ser executado por vários processos
sum = sum + private_x;

### Como garantir que esta linha de código seja executada por um processo de cada vez?

## Message Passing

- Memória distribuída: Cada processo tem seu próprio espaço de memória.
- Arquiteturas do tipo MIMD: Múltiplas Instruções, Múltiplos Dados.
- Primitivas send e receive: Para comunicação entre processos.
- SPMD (Single Program, Multiple Data): Um único programa é executado em paralelo, mas cada processo trabalha com dados diferentes.

### Comunicação entre processos

- Comunicação Síncrona: O processo A espera até que o processo B esteja pronto para receber a mensagem.
- Comunicação Bufferizada: A mensagem pode ser armazenada em um buffer até que o processo receptor esteja pronto.
- Comunicação Bloqueante: O processo espera até receber a mensagem.
- Comunicação Não-Bloqueante: O processo continua a execução e verifica posteriormente se a mensagem foi recebida.

### Data Parallel Languages

- Paralelismo de Dados: Os processos executam as mesmas operações em diferentes partes dos dados.
- Estruturas de dados distribuídas: Cada processo trabalha com uma parte dos dados.
- Exemplo em HPF (High Performance Fortran):

!HPF$ PROCESSORS p(10)
Real x(1000), y(1000), z(1000)
!HPF$ ALIGN y(:) with x(:)
!HPF$ ALIGN z(:) with x(:)
!HPF$ DISTRIBUTE x(BLOCK) ONTO P
// Inicializa x e y
Z = x + y;

### Mapeamento de Dados

- Balanceamento de Carga: É importante distribuir os dados de forma equilibrada entre os processos.
- Mapeamento por blocos: Particiona os elementos do vetor em blocos consecutivos para cada processador.
- Mapeamento Cíclico: Distribui os elementos do vetor em ordem, um elemento por processo.
- Mapeamento Bloco-Cíclico: Combinação dos dois métodos anteriores.
- Para matrizes: Pode-se utilizar mapeamento Bloco-linha, Bloco-coluna, Bloco-cíclico linha ou Bloco-bloco (checkerboard).
