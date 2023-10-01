#include <iostream>
#include <math.h>

int main() {

    int n = 210;
    int square = 0;

    #pragma omp parallel for reduction(+:square)
    for (int i = 0; i < n; i++) {
    #pragma omp atomic
        square += (2 * i + 1);
    }

    printf("Square of %d: %d\n", n, square);
}