#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <iostream>


int is_prime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int start, end;
    printf("Start: ");
    std::cin >> start;
    printf("End: ");
    std::cin >> end;

    printf("Prime numbers in the range [%d, %d]: ", start, end);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        for (int i = start + thread_id; i <= end; i += num_threads) {
            if (is_prime(i)) {
    #pragma omp critical
                printf("%d ", i);
            }
        }
    }

    printf("\n");

}