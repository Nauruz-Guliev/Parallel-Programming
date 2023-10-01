#include <cstdio>
#include <omp.h>
#include <cstdlib>


int main() {

    omp_set_num_threads(3);
    #pragma omp parallel if(omp_get_max_threads() > 1)
    {
        printf("Area 1. Thread: %d. Number of threads: %d \n", omp_get_thread_num(), omp_get_num_threads());
    }
    omp_set_num_threads(1);
    #pragma omp parallel if(omp_get_max_threads() > 1)
    {
        printf("Area 2. Thread: %d. Number of threads: %d", omp_get_thread_num(), omp_get_num_threads());
    }
}