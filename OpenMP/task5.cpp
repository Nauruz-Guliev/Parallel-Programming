#include <omp.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAGIC 30

int main() {
    int d[6][8];
    srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % MAGIC;
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    #pragma omp parallel sections
    {
    #pragma omp section
        {
            int elements = 0;
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    sum += d[i][j];
                    elements++;
                }
            }
            std::cout << "mid is " << sum * 1.0 / elements << " from " << omp_get_thread_num() << " thread" << std::endl;
        }
    #pragma omp section
        {
            int max = MAGIC + 1;
            int min = -1;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (max > d[i][j]) {
                        max = d[i][j];
                    }
                    if (min < d[i][j]) {
                        min = d[i][j];
                    }
                }
            }
            std::cout << "max is " << max << " and min is " << min << " from " << omp_get_thread_num() << " thread" << std::endl;
        }
    #pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (d[i][j] % 3 == 0) {
                        sum += d[i][j];
                    }
                }
            }
            std::cout << "sum of deviders is " << sum << " from " << omp_get_thread_num() << " thread" << std::endl;
        }
    }
}