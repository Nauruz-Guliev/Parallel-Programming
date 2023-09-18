#include <iostream>
#include <omp.h>

/*

int main() {
    int a = 5, b = 7;
    printf("#before 1 a:%d b:%d\n", a, b);
    #pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        a = 5;
        a += omp_get_thread_num();
        b += omp_get_thread_num();
        printf("#during 1 %d a:%d b:%d\n", omp_get_thread_num(), a, b);
    }
    printf("#after 1 a:%d b:%d\n\n\n", a, b);
    printf("#before 2 a:%d b:%d\n", a, b);
    #pragma omp parallel num_threads(4) shared(a) private(b)
    {
        b = 7;
        #pragma omp atomic
        a -= omp_get_thread_num();
        b -= omp_get_thread_num();
        printf("#during 2 %d a:%d b:%d\n", omp_get_thread_num(), a, b);
    }
    printf("#after 2 a:%d b:%d\n\n\n", a, b);
}
*/