//#include <iostream>
//#include <chrono>
//#include <windows.h>
//
//
//int main()
//{
//    int const rows = 16000, columns = 8000, max_value = 100;
//
//    int static matrix[rows][columns];
//    int static vector[columns];
//    int static result[rows];
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            matrix[i][j] = rand() % max_value;
//        }
//    }
//
//    for (int i = 0; i < columns; i++) {
//        vector[i] = rand() % max_value;
//    }
//
//    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < rows; i++) {
//        result[i] = 0;
//        for (int j = 0; j < columns; j++) {
//            result[i] += matrix[i][j] * vector[j];
//        }
//    }
//    auto end = std::chrono::high_resolution_clock::now();
//
//    float duration = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
//    printf("Consist implementation time: %fms \n", duration);
//
//
//    start = std::chrono::high_resolution_clock::now();
//    #pragma omp parallel for
//    for (int i = 0; i < rows; i++) {
//        result[i] = 0;
//        for (int j = 0; j < columns; j++) {
//            result[i] += matrix[i][j] * vector[j];
//        }
//    }
//    end = std::chrono::high_resolution_clock::now();
//
//    duration = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
//    printf("Parallel implementation time: %fms \n", duration);
//}