#include <cstdio>
#include <omp.h>
#include <cstdlib>

int main() {
    int a = 10, b = 10;
    printf("#Area 1 BEFORE: a = %d b = %d\n", a, b);
    #pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        a += omp_get_thread_num();
        b += omp_get_thread_num();
        printf("#Area 1 DURING: Thread = %d a = %d b = %d\n", omp_get_thread_num(), a, b);
    }
    printf("#Area 1 AFTER: a = %d b = %d\n\n\n", a, b);
    printf("#Area 2 BEFORE: a = %d b = %d\n", a, b);
    #pragma omp parallel num_threads(4) shared(a) private(b)
    {
        #pragma omp atomic
        a -= omp_get_thread_num();
        b -= omp_get_thread_num();
        printf("#Area 2 DURING: Thread = %d a = %d b = %d\n", omp_get_thread_num(), a, b);
    }
    printf("#Area 2 AFTER: a = %d b = %d\n\n\n", a, b);
}