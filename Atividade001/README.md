# Atividade 1 - Arquitetura de Computadores Paralelos

Desenvolva a Atividade 1 individualmente. Procure aprofundar as características da arquitetura escolhida, considerando os seguintes aspectos:

- **Memória:** Descreva o tipo de memória utilizada (memória compartilhada, memória distribuída, etc.), bem como suas características e como ela é organizada e gerenciada na arquitetura.

- **Processamento:** Detalhe os componentes de processamento, como CPUs, GPUs ou outros processadores paralelos. Explique a forma de paralelismo utilizada (paralelismo de dados, paralelismo de tarefas, etc.) e como os processadores interagem entre si e com a memória.

- **Rede de Interconexão:** Descreva a rede de interconexão utilizada para a comunicação entre os componentes da arquitetura. Explique o tipo de rede (malha, anel, árvore, etc.), suas propriedades (largura de banda, latência, topologia, etc.) e como ela afeta o desempenho e a escalabilidade do sistema.

## Entrega

Faça a entrega do trabalho no Moodle, até o dia **12/03/2024**.

# Computação Paralela e de Alto Desempenho

## a) Classificação da Tecnologia

- **OpenMP:** Paralelismo Explícito em Memória Compartilhada.
- **MPI:** Paralelismo Implícito em Memória Distribuída.

## b) Características de Cada API

### OpenMP

- **Objetivo:** Simplificar a programação paralela em CPUs multicore.
- **Facilidade de Programação:** Alta, com diretivas de compilação simples.
- **Desenvolvimento no Ambiente Paralelo:** Suporta threads, sincronização e dados compartilhados.
- **Portabilidade:** Alta.
- **Performance:** Eficiente em multicore, limitada em sistemas distribuídos.

### MPI

- **Objetivo:** Comunicação eficiente entre processos em sistemas distribuídos.
- **Facilidade de Programação:** Moderada, requer conhecimento em comunicação entre processos.
- **Desenvolvimento no Ambiente Paralelo:** Ampla gama de rotinas de comunicação e sincronização.
- **Portabilidade:** Alta.
- **Performance:** Alta eficiência em sistemas distribuídos.

## c) Desafios da Computação de Alto Desempenho Moderna

1. **Escalabilidade:** Lidar com mais processadores e aplicações complexas.
2. **Eficiência Energética:** Reduzir consumo de energia mantendo desempenho.
3. **Programabilidade:** Simplificar desenvolvimento de aplicações paralelas.
4. **Portabilidade:** Executar aplicações em diferentes plataformas e hardware.
5. **Resiliência:** Melhorar capacidade de lidar com falhas de hardware e software.
6. **Balanceamento de Carga:** Distribuir tarefas eficientemente entre processadores.
7. **Gerenciamento de Memória:** Otimizar uso de memória para reduzir latência.
8. **Comunicação e Sincronização:** Minimizar custo de comunicação e evitar erros de sincronização.
9. **Interoperabilidade:** Garantir compatibilidade entre diferentes tecnologias e ferramentas.
