#include <omp.h>
#include <iostream>
#include <string>

/*

int main() {

    omp_set_dynamic(0);

    omp_set_num_threads(3);
    #pragma omp parallel if(omp_get_max_threads() > 1)
    {
        std::cout << "Hello from thread " << omp_get_thread_num() << ", nthreads " << omp_get_num_threads() << std::endl;
    }
    omp_set_num_threads(1);
    #pragma omp parallel if(omp_get_max_threads() > 1)
    {
        std::cout << "Hello from thread " << omp_get_thread_num() << ", nthreads " << omp_get_num_threads() << std::endl;
    }
}
*/