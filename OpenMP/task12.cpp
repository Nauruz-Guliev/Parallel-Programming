#include <omp.h>
#include <iostream>
#include <string>


int main() {
    int thread_id = omp_get_thread_num();
    #pragma omp barrier
    for (int i = omp_get_num_threads() - 1; i >= 0; i--)
    {
        if (i == thread_id)
        {
            printf("Hello World: from thread %d, threads %d\n", i, omp_get_num_threads());
        }
    #pragma omp barrier
    }
}

