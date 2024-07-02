# LINGUAGEM DE PROGRAMAÇÃO JULIA

## TRABALHO
Roger da Palma, Guilherme Painko Scalcon

## SUMÁRIO
1. HISTÓRICO DA LINGUAGEM JULIA
2. PARADIGMA DE PROGRAMAÇÃO
3. PRIMITIVAS PARA COMUNICAÇÃO E SINCRONIZAÇÃO ENTRE PROCESSOS
4. EXEMPLO DE APLICAÇÃO
5. CONCLUSÕES
   - O que será apresentado

### 1. HISTÓRICO DA LINGUAGEM JULIA

Julia foi criada com o objetivo de ser uma linguagem rápida, de alto nível e de alto desempenho para computação técnica. Desenvolvida por Jeff Bezanson, Stefan Karpinski, Viral B. Shah e Alan Edelman, a linguagem foi oficialmente lançada em 2012. O desenvolvimento de Julia começou em 2009, com a intenção de superar os trade-offs entre a facilidade de uso de linguagens como Python e R e a velocidade de linguagens como C e Fortran.

### 2. PARADIGMA DE PROGRAMAÇÃO

Julia é uma linguagem multi-paradigma, suportando programação procedural, funcional e orientada a objetos. É dinâmica, com um sistema de tipos rico e uma forte ênfase em computação numérica e científica. O sistema de despacho múltiplo de Julia, que é central para muitas de suas capacidades, permite que os métodos sejam definidos por combinações de tipos de seus argumentos.

### 3. PRIMITIVAS PARA COMUNICAÇÃO E SINCRONIZAÇÃO ENTRE PROCESSOS

Julia foi projetada para ser boa em computação paralela e distribuída, oferecendo primitivas como:
- `@spawn`: Para criar tarefas assíncronas em qualquer processo disponível.
- `Channel`: Usados para comunicação segura entre tarefas.
- `@async` e `@await`: Para programação assíncrona.
- Barreiras de sincronização e locks: Para sincronização direta entre tarefas.

Além disso, Julia suporta a passagem de mensagens com `RemoteChannel` e `@distributed` para loops paralelos.

### 4. EXEMPLO DE APLICAÇÃO

```julia
using Base.Threads

function parallel_matrix_operations(A::Array{Float64, 2}, B::Array{Float64, 2}, C::Array{Float64, 2})
    @assert size(A) == size(B) == size(C) "As matrizes A, B e C devem ter o mesmo tamanho"
    @assert size(B, 2) == size(C, 1) "O número de colunas de B deve ser igual ao número de linhas de C"

    # Etapa 1: Calcula B * C de forma paralela
    D = zeros(Float64, size(B, 1), size(C, 2))
    @threads for i in 1:size(B, 1)
        for j in 1:size(C, 2)
            for k in 1:size(B, 2)
                D[i, j] += B[i, k] * C[k, j]
            end
        end
    end

    # Etapa 2: Calcula A + D de forma paralela
    E = zeros(Float64, size(A))
    @threads for i in 1:size(A, 1)
        for j in 1:size(A, 2)
            E[i, j] = A[i, j] + D[i, j]
        end
    end

    return E
end

# Exemplo de uso
A = [1.0 2.0; 3.0 4.0]
B = [5.0 6.0; 7.0 8.0]
C = [1.0 0.0; 0.0 1.0]

E = parallel_matrix_operations(A, B, C)
println(E)
```

### 5. CONCLUSÕES

Julia combina a facilidade de uso de linguagens de alto nível com o desempenho de linguagens de baixo nível, tornando-a ideal para aplicações que requerem computação intensiva, como modelagem matemática, simulações e aprendizado de máquina. A comunidade Julia está crescendo rapidamente, e sua biblioteca de pacotes continua a expandir, aumentando sua aplicabilidade em diversos campos da ciência e engenharia.

### Referências

- [Julia Programming Language Official Site](https://julialang.org/)
- [Monteiro, 2022 PDF on Distributed Computing in Julia](https://run.unl.pt/bitstream/10362/144294/1/Monteiro_2022.pdf)

