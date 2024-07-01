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
