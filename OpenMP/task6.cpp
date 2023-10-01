//#include <iostream>
//#include <omp.h>
//
//
//int main() {
//    const int size = 10;
//    int a[size] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2 };
//    int b[size] = { 10, 2, 3, 4, 5, 1, 5, 9, 3, 2 };
//    int sum_a = 0, sum_b = 0;
//
//    #pragma omp parallel for reduction(+: sum_a) reduction(+: sum_b)
//    for (int i = 0; i < 10; i++) {
//        sum_a += a[i];
//        sum_b += b[i];
//    }
//
//    float average_a = sum_a / size;
//    float average_b = sum_b / size;
//
//    char sign = '=';
//
//    if (average_a > average_b) {
//        sign = '>';
//    } else if (average_a < average_b) {
//        sign = '<';
//    }
//    std::cout << average_a << sign << average_b << std::endl;
//}