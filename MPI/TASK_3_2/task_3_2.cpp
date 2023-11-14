#include <iostream>
#include <mpi.h>
#include <random>

int main(int argc, char** argv) {
    const int ARRAY_SIZE = 100; // Размер векторов x и y
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Получение количества процессов
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Получение ранга текущего процесса

    const int block = 20; // Размер блока для разделения векторов x и y
    int x[ARRAY_SIZE], x_block[block], y[ARRAY_SIZE], y_block[block];

    if (rank == 0) {
        // Заполнение векторов x и y на процессе с рангом 0
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            x[i] = rand() % 100; // Случайное значение для x[i]
            y[i] = rand() % 100; // Случайное значение для y[i]
        }
    }

    // Разделение векторов x и y между процессами с помощью функции MPI_Scatter
    MPI_Scatter(&x[0], block, MPI_INT, &x_block[0], block, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&y[0], block, MPI_INT, &y_block[0], block, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Вывод векторов x и y на процессе с рангом 0
        printf("x: ");
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            printf("%d ", x[i]);
        }
        printf("\n");

        printf("y: ");
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            printf("%d ", y[i]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < block; ++i) {
        sum += x_block[i] * y_block[i]; // Вычисление суммы произведений элементов блоков x_block и y_block
    }

    int result;

    // Сбор и суммирование локальных сумм с помощью функции MPI_Reduce
    MPI_Reduce(&sum, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Вывод результата на процессе с рангом 0
        printf("result = %d\n", result);
    }

    MPI_Finalize(); // Окончание работы с MPI

    return 0;
}
