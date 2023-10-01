//#include <omp.h>
//#include <iostream>
//
//
//int main() {
//    const int size = 12;
//    int a[size], b[size], c[size];
//    int max_value = 100;
//    {
//    #pragma omp parallel for schedule(static, 3) num_threads(3)
//        for (int i = 0; i < size; i++) {
//            a[i] = rand() % max_value;
//            b[i] = rand() % max_value;
//            printf("\nThread: %d. Number of threads: %d ", omp_get_thread_num(), omp_get_num_threads());
//        }
//    }
//    printf("\na : ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\nb : ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", b[i]);
//    }
//    #pragma omp parallel for schedule(dynamic, 4) num_threads(4)
//    for (int i = 0; i < size; i++) {
//        c[i] = a[i] + b[i];
//        printf("\nThread: %d. Number of threads: %d", omp_get_thread_num(), omp_get_num_threads());
//    }
//    printf("\nc : ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", c[i]);
//    }
//}