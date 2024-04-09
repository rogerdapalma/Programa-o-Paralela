# Resumo de Programação Paralela e Arquiteturas de Alto Desempenho

## Paradigmas de Programação Paralela

### Shared Memory Programming
- Processos têm acesso a variáveis compartilhadas.
- Necessita de mecanismos para sincronização e prevenção de acesso impróprio.

### Message Passing
- Comunicação entre processos em arquiteturas de memória distribuída.
- Modos de comunicação incluem síncrona, bufferizada, bloqueante e não-bloqueante.

### Data Parallel Languages
- Dados distribuídos entre processos que executam as mesmas instruções.
- Exemplo: High Performance Fortran (HPF).

## MPI – Message Passing Interface
- **Comunicação Ponto-a-Ponto:** Envio e recebimento de mensagens entre dois processos.
- **Comunicação Coletiva:** Operações como broadcast, scatter, gather, allgather, reduce e allreduce.

## Arquiteturas de Alto Desempenho

### Classificação de Flynn
- SISD, SIMD, MISD, MIMD.

### Modelo de Acesso à Memória
- UMA (Uniform Memory Access) e NUMA (Non-Uniform Memory Access).

### Multiprocessadores
- Arquiteturas com memória compartilhada.
- Classificações: UMA, NUMA, NCC-NUMA, CC-NUMA, SC-NUMA, COMA.

### Multicomputadores
- Arquiteturas com memória distribuída.
- Classificação: NORMA (Non-Remote Memory Access).

## Modelos Físicos de Máquinas Paralelas

### Processadores Vetoriais Paralelos (PVP)
- Máquinas com poucos processadores vetoriais poderosos.

### Multiprocessadores Simétricos (SMP)
- Máquinas com processadores comerciais conectados a memória compartilhada.

### Máquinas Maciçamente Paralelas (MPP)
- Máquinas com milhares de processadores comerciais conectados por uma rede proprietária.

