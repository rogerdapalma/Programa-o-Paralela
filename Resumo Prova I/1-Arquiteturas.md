# ARQUITETURAS DE ALTO DESEMPENHO

## Sumário

- Arquiteturas Paralelas
- Classificação de Flynn
- Classificação segundo o Modelo de Acesso à Memória
- Modelos Físicos de Máquinas Paralelas
- Grid Computing

## Arquiteturas Paralelas

Acelerar a execução de aplicações:
- Grande quantidade de dados
- Grande quantidade de processamento

Áreas:
- Física
- Engenharia
- Meteorologia
- Computação Gráfica
- Inteligência Artificial
- ...

Problema:
- Custo elevado
- Dificuldade de programar

Programação paralela exige o conhecimento de características específicas da máquina e da aplicação para a obtenção do desempenho.

## Taxonomia de Flynn (1972)

Arquiteturas Paralelas:

- SISD (Single Instruction, Single Data)
- SIMD (Single Instruction, Multiple Data)
- MISD (Multiple Instruction, Single Data)
- MIMD (Multiple Instruction, Multiple Data)

## SISD

- Máquinas von Neumann
- Apenas um processador
- Computadores pessoais
- Execução sequencial

## MISD

- Múltiplos fluxos de instruções atuam sobre um único fluxo de dados
- Diferentes instruções operam a mesma posição de memória ao mesmo tempo, executando instruções diferentes (inviável!)
- Não existem exemplos reais deste tipo de arquitetura

## SIMD

- Uma única instrução é executada ao mesmo tempo sobre múltiplos dados
- Máquinas Array (Exemplo: Cambridge Parallel Processing Gamma II Plus)

## MIMD

- Cada unidade de controle (C) recebe um fluxo de instruções próprio, repassa-o para sua unidade de processamento (P) que executa sobre um fluxo de dados próprio (M).
- Execução Assíncronos
- Exemplos: IBM SP, Fujitsu VPP5000, Intel Paragon

## Modelo de Acesso à Memória

- Memória Compartilhada
- Memória Distribuída

## Classificação Segundo Acesso à Memória

MIMD:
- Multiprocessadores
- Multicomputadores NORMA
- UMA (Uniform Memory Access)
- NUMA (Non-Uniform Memory Access)
- COMA (Cache-Only Memory Access)
- CC-NUMA (Cache-Coherent Non-Uniform Memory Access)
- NCC-NUMA (Non-Cache-Coherent Non-Uniform Memory Access)
- SC-NUMA (Software-Coherent Non-Uniform Memory Access)

## Multiprocessadores

- Espaço de endereçamento único
- Todos os processadores P são capazes de endereçar todas as memórias M
- Comunicação através de Memória Compartilhada

## Multicomputadores

- Cada processador P tem uma memória local M (e somente pode acessar esta memória)
- As memórias dos outros processadores são memórias remotas; espaço de endereçamento distinto
- Comunicação através de Trocas de Mensagens
- NORMA (Non-Remote Memory Access)

## Modelos Físicos de Máquinas Paralelas

- Processadores Vetoriais Paralelos (PVP)
- Multiprocessadores Simétricos (SMP)
- Máquinas Maciçamente Paralelas (MPP)
- Máquinas com Memória Compartilhada Distribuída (DSM)
- Redes de Estações de Trabalho (NOW)
- Máquinas Agregadas (COW)

## Grid Computing

- Uma rede computacional, dispersa geograficamente, onde o usuário se conecta para obter poder computacional (ciclos, armazenamento, software, periféricos...)
- Oferece recursos sob demanda
- Alocação de recursos para processamento paralelo
- Plataforma para execução de aplicações paralelas

## Considerações Finais

- A implementação de aplicações paralelas ainda está fortemente relacionada ao tipo de arquitetura da máquina utilizada para a execução.
