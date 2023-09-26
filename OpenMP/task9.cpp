#include <omp.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

/*


int main() {
    const int size = 100;
    const int width = 6;
    const int height = 8;
    int d[width][height];
    srand(time(NULL));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            d[i][j] = rand() % size;
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    int max = -1;
    int min = size + 1;
    int counter = 0;
    #pragma omp parallel num_threads(6) reduction(+: counter)
    for (int i = 0; i < width; i++) {
        #pragma omp for
        for (int j = 0; j < height; j++) {
            counter++;
            if (min > d[i][j]) {
            #pragma omp critical
                min = d[i][j];
            }
            if (max < d[i][j]) {
            #pragma omp critical
                max = d[i][j];
            }
        }
    }
    std::cout << "counter is " << counter << std::endl;
    std::cout << "max is " << max << " min is " << min << std::endl;
}
*/