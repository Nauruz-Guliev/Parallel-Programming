#include <iostream>
#include <math.h>

int main() {
    const int size = 30;
    int a[size] = { 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1 };
    int result = 0;

    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < size; i++) {
        result = result * 2 + a[i];
    }

    printf("Result: %d\n", result);
}