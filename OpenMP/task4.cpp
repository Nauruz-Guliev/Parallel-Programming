#include <omp.h>
#include <stdio.h>


//int main() {
//    int a[10] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2 };
//    int b[10] = { 10, 2, 3, 4, 5, 1, 5, 4, 3, 2 };
//    int min_a = 1000;
//    int max_b = -1000;
//    #pragma omp parallel sections num_threads(2)
//    {
//    #pragma omp section
//        {
//            for (int i = 0; i < 10; i++) {
//                if (min_a > a[i]) { min_a = a[i]; }
//            }
//        }
//    #pragma omp section
//        {
//            for (int i = 0; i < 10; i++) {
//                if (max_b < b[i]) { max_b = b[i]; }
//            }
//        }
//    }
//    printf("min_a is %d, max_b is %d\n", min_a, max_b);
//}
