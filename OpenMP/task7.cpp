#include <omp.h>
#include <iostream>

/*

int main() {
    const int size = 12;
    int a[size], b[size], c[size];

    {
    #pragma omp for schedule(static) num_threads(3)
        for (int i = 0; i < size; i++) {
            a[i] = i * 2;
            b[i] = i * 3;
            std::cout << "working " << omp_get_thread_num() << " of " << omp_get_num_threads() << " threads" << std::endl;
        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    } 
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << b[i] << " ";
    } 
    std::cout << std::endl;

    #pragma omp parallel for schedule(dynamic, 4) num_threads(4)
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
        std::cout << "working " << omp_get_thread_num() << " of " << omp_get_num_threads() << " threads" << std::endl;
    }
    for (int i = 0; i < size; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}
*/