#include <omp.h>
#include <iostream>
#include <string>

/*

int main() {
    #pragma omp parallel num_threads(8) 
    {
        std::cout << "Hello World " << std::to_string(omp_get_thread_num()) << " of " << std::to_string(omp_get_num_threads()) << std::endl;
    }
}
*/