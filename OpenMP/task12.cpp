#include <omp.h>
#include <iostream>
#include <string>


int main() {
    #pragma omp parallel num_threads(8)
    {
    int thread_id = omp_get_thread_num();
    #pragma omp critical
        {
            for (int i = 7; i >= 0; i--) {
                if (i == thread_id) {
                    printf("Hello World: from thread %d, threads %d\n", omp_get_thread_num(), omp_get_num_threads());
                }
            }
        }
    }
}
