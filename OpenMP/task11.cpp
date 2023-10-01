//#include <omp.h>
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//
//
//int main() {
//    const int size = 200;
//    const int divider = 7;
//    int a[size];
//    int base_max = -1;
//    for (int i = 0; i < size; i++) {
//        a[i] = rand() % size;
//    }
//    int max = -1;
//    #pragma omp parallel for shared(max)
//    for (int i = 0; i < size; i++) {
//        if (a[i] % divider == 0 && max < a[i]) {
//            #pragma omp critical
//            {
//                max = a[i];
//            }
//        }
//    }
//    std::cout << max << std::endl;
//}