#include <omp.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


int main() {
    const int max_value = 100;
    const int width = 6;
    const int height = 8;
    int d[width][height];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            d[i][j] = rand() % max_value;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    int max = -1;
    int min = max_value + 1;
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
    printf("counter is %d \n", counter);
    printf("max = %d, min = %d", max, min);
}