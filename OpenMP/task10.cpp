
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*

int main() {
    const int size = 30;
    const int divider = 9;
    srand(time(NULL));
    int a[size];
    int basic_counter = 0;
    for (int i = 0; i < size; i++) {
        a[i] = rand() % size;
    }
    int counter = 0;
    #pragma omp parallel for shared(counter)
    for (int i = 0; i < size; i++) {
        if (a[i] % divider == 0) {
        #pragma omp atomic
            counter++;
        }
    }
    printf("counter is %d\n", counter);
}
*/