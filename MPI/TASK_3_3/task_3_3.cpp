#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    // Размеры матрицы и вектора
    const int MATRIX_SIZE = 10;
    const int VECTOR_SIZE = 10;

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double matrix[MATRIX_SIZE][MATRIX_SIZE];
    double vector[VECTOR_SIZE];
    double local_result[MATRIX_SIZE];

    if (rank == 0) {
        // Генерация матрицы и вектора на нулевом процессе
        printf("Matrix:\n");
        srand(time(NULL));
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            for (int j = 0; j < MATRIX_SIZE; ++j) {
                matrix[i][j] = rand() % 100 + 1;
                printf("%.0f ", matrix[i][j]);
            }
            printf("\n");
        }

        printf("Vector:\n");
        for (int i = 0; i < VECTOR_SIZE; ++i) {
            vector[i] = rand() % 100 + 1;
            printf("%.0f ", vector[i]);
        }
        printf("\n");
    }

    // Рассылка вектора всем процессам
    MPI_Bcast(vector, VECTOR_SIZE, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Размер подматрицы для каждого процесса
    int local_rows = MATRIX_SIZE / size;

    double local_matrix[20][MATRIX_SIZE];

    // Распределение частей матрицы
    MPI_Scatter(matrix, local_rows * MATRIX_SIZE, MPI_DOUBLE, local_matrix, local_rows * MATRIX_SIZE, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Умножение матрицы на вектор
    for (int i = 0; i < local_rows; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            local_result[i + rank * local_rows] += local_matrix[i][j] * vector[j];
        }
    }

    // Сбор результатов на нулевом процессе
    double* global_result = NULL;
    if (rank == 0) {
        global_result = (double*)malloc(MATRIX_SIZE * sizeof(double));
    }

    MPI_Gather(local_result, local_rows, MPI_DOUBLE, global_result, local_rows, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Вывод результата на нулевом процессе
        printf("Resulting vector:\n");
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            printf("%.4e ", global_result[i]);
        }
        printf("\n");
        free(global_result);
    }

    MPI_Finalize();
    return 0;
}
