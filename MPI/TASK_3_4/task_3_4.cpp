#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv) {
    const int ROWS = 12;
    const int COLS = 10;
    const int BLOCK_SIZE = 3;

    int matrix[ROWS][COLS];
    int result;
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Заполнение и вывод исходной матрицы на нулевом процессе
        printf("Matrix:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                matrix[i][j] = rand() % 100 + 1;
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int blockMatrix[BLOCK_SIZE][COLS];

    // Разделение матрицы на блоки и распределение между процессами
    MPI_Scatter(matrix, BLOCK_SIZE * COLS, MPI_INT, blockMatrix, BLOCK_SIZE * COLS, MPI_INT, 0, MPI_COMM_WORLD);

    int sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += blockMatrix[i][j];
        }
        if (sum > max) {
            max = sum;
        }
        sum = 0;
    }

    // Сбор максимального значения среди всех процессов на нулевом процессе
    MPI_Reduce(&max, &result, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result: %d", result);
    }

    MPI_Finalize();
    return 0;
}
