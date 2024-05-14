#include <omp.h>
#include <stdio.h>

#define N 1000000000

int main(void) {
    double pi = 0.0;
    long i;
    double ti, tf;
    int qt, num_threads;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Define o número de threads usado pelo OpenMP
    omp_set_num_threads(num_threads);

    ti = omp_get_wtime();

    #pragma omp parallel reduction(+: pi)
    {
        qt = omp_get_num_threads();

        #pragma omp for
        for (i = 0; i < N; i++) {
            double t = (double)((i + 0.5) / N);
            pi += 4.0 / (1.0 + t * t);
        }
    }

    tf = omp_get_wtime();

    printf("pi = %f\n", pi / N);
    printf("tempo: %fs\n", tf - ti);
    printf("total threads: %d\n", qt);

    return 0;
}

