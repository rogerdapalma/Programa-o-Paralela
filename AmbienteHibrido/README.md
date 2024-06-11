### Desempenho em Sistemas Paralelos

#### Sumário
- Introdução
- Tempo de execução
- Speedup
- Eficiência
- Escalabilidade

#### Introdução
- **Desempenho e Escalabilidade de Sistemas Paralelos**
  - O tempo de execução de um algoritmo paralelo depende:
    - do tamanho da entrada (n);
    - da organização da arquitetura do computador paralelo e
    - do número de processadores utilizados.
  - O tamanho da entrada também pode ser referido como o tamanho do problema.

- **Métricas de desempenho de programas paralelos são:**
  - Tempo de execução
  - Speedup
  - Eficiência

- **A escalabilidade de Sistemas Paralelos** refere-se à capacidade do sistema manter sua eficiência, dado o aumento do tamanho do problema e dos elementos de processamento.

#### Tempo de execução
- **Tempo de Execução** de uma aplicação paralela é o tempo decorrido desde o início da execução do primeiro processo até o término da execução do último processo da aplicação.
- Em **MPI**, é preciso sincronizar todos os processos da aplicação antes de ser efetuada a medida de tempo.
- Em **OpenMP**, podemos tomar os tempos antes do início da seção paralela e ao término desta seção.

#### Speedup
- **Speedup** é uma medida que mostra o benefício relativo da resolução em paralelo, ou seja, quanto desempenho é conseguido pela paralelização da aplicação sobre a implementação sequencial.
- O Speedup é a razão entre o tempo de execução sequencial (ou em 1 processo) e o tempo paralelo de execução do algoritmo paralelo em P processadores.
- O Speedup varia entre 1 e P e é a medida do ganho de tempo.
- O Speedup ideal é igual a P.

  - Fórmula: 
    - \( Speedup = \frac{T(n, 1)}{T(n, P)} \)
    - onde:
      - \( T(n, 1) \) é o tempo de execução sequencial ou em um processo do algoritmo para uma entrada n
      - \( T(n, P) \) é o tempo de execução do algoritmo paralelo para uma entrada de tamanho n com p processadores.

#### Eficiência
- **Eficiência** é a taxa de ocupação dos processadores na execução do programa paralelo, ou seja, é a medida do uso dos processadores.
- A Eficiência varia entre 0 e 1.
- A Eficiência ideal é igual a 1.

  - Fórmula: 
    - \( Eficiência = \frac{Speedup(n, P)}{P} \)
    - onde:
      - \( Speedup(n, P) \) é o speedup do algoritmo paralelo, para uma entrada n, executando em p processos.
      - \( P \) é a quantidade de processos utilizados.

#### Speedup e Eficiência Superlineares
- Em algumas situações, podemos obter um valor de:
  - Speedup superior à P e de
  - Eficiência superior à 1
- Valores superiores ao valor ideal.
- Este comportamento deve-se ao fato de ao dividir o domínio pelos vários processadores, cada um deles precisar de menor quantidade de memória (essencialmente cache e primária).
- O computador sequencial poderá ter de utilizar com maior frequência memória secundária, aumentando consideravelmente o tempo de processamento.
- Se na versão paralela o ganho, devido à gestão de memória feita pelo sistema operacional, for superior aos tempos de comunicação e gestão de paralelismo, então poder-se-á obter desempenho superlinear.

#### Escalabilidade dos Sistemas Paralelos
- A capacidade de manter a eficiência fixa quando é aumentado o número de processadores e o tamanho do problema, indica um sistema paralelo escalável.
- A escalabilidade é a medida da capacidade de aumentar o speedup em proporção ao número de processadores.
- Isso reflete também a capacidade do sistema em utilizar os recursos adicionados efetivamente.

