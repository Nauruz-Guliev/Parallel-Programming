#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    int count;

    const int SIZE = 10;
    const int PART = 5;

    if (rank == 0) {
        int matrix[SIZE][SIZE];
        int vector[SIZE];
        int result[SIZE];

        // Инициализация матрицы и вектора
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = i * SIZE + j;
            }
            vector[i] = i;
        }

        std::cout << "matrix: \n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "\nvector: \n";
        for (int i = 0; i < SIZE; ++i) {
            std::cout << vector[i] << std::endl;
        }

        int n = 1;
        for (int i = 0; i < SIZE; i += PART, n++) {
            // Отправка частей матрицы и вектора процессам
            MPI_Send(&matrix[i][0], PART * SIZE, MPI_INT, n, 10, MPI_COMM_WORLD);
            MPI_Send(&vector[0], SIZE, MPI_INT, n, 10, MPI_COMM_WORLD);
        }

        n = 1;
        for (int i = 0; i < SIZE; i += PART, n++) {
            // Получение результатов от процессов
            MPI_Recv(&result[i], PART, MPI_INT, n, 10, MPI_COMM_WORLD, &status);
        }

        std::cout << "Resulting vector: \n";
        for (int i = 0; i < SIZE; i++) {
            std::cout << "result[" << i << "] = " << result[i] << std::endl;
        }
    }
    else {
        MPI_Probe(0, 10, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);
        int matrix[10][SIZE];
        int vector[SIZE];
        int result[10];

        MPI_Recv(&matrix[0][0], PART * SIZE, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
        MPI_Recv(&vector[0], SIZE, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);

        for (int i = 0; i < PART; ++i) {
            result[i] = 0;
            for (int j = 0; j < SIZE; ++j) {
                result[i] += matrix[i][j] * vector[j];
            }
        }

        MPI_Send(&result[0], PART, MPI_INT, 0, 10, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
