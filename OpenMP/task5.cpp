#include <omp.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


//int main() {
//    const int max_value = 100;
//    int size_a = 6;
//    int size_b = 8;
//    int d[6][8];
//    for (int i = 0; i < size_a; i++) {
//        for (int j = 0; j < size_b; j++) {
//            d[i][j] = rand() % max_value;
//            printf("%d ", d[i][j]);
//        }
//    }
//    printf("\n\n\n");
//    #pragma omp parallel sections
//    {
//    #pragma omp section
//        {
//            int elements = 0;
//            int sum = 0;
//            for (int i = 0; i < size_a; i++) {
//                for (int j = 0; j < size_b; j++) {
//                    sum += d[i][j];
//                    elements++;
//                }
//            }
//            printf("Average is %d. Thread: %d \n", (sum / elements), omp_get_thread_num());
//        }
//    #pragma omp section
//        {
//            int max = max_value + 1;
//            int min = -1;
//            for (int i = 0; i < size_a; i++) {
//                for (int j = 0; j < size_b; j++) {
//                    if (max > d[i][j]) {
//                        max = d[i][j];
//                    }
//                    if (min < d[i][j]) {
//                        min = d[i][j];
//                    }
//                }
//            }
//            printf("Max = %d, Min = %d. Thread: %d\n", max, min, omp_get_thread_num());
//        }
//    #pragma omp section
//        {
//            int divider = 3;
//            int count = 0;
//            for (int i = 0; i < size_a; i++) {
//                for (int j = 0; j < size_b; j++) {
//                    if (d[i][j] % 3 == 0) {
//                        count++;
//                    }
//                }
//            }
//            printf("Count of elements that are multiples of 3: %d. Thread: %d", count, omp_get_thread_num());
//        }
//    }
//}