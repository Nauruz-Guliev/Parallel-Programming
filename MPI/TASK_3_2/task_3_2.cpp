#include <iostream>
#include <mpi.h>
#include <random>

int main(int argc, char** argv) {
    const int ARRAY_SIZE = 100; // ������ �������� x � y
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size); // ��������� ���������� ���������
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // ��������� ����� �������� ��������

    const int block = 20; // ������ ����� ��� ���������� �������� x � y
    int x[ARRAY_SIZE], x_block[block], y[ARRAY_SIZE], y_block[block];

    if (rank == 0) {
        // ���������� �������� x � y �� �������� � ������ 0
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            x[i] = rand() % 100; // ��������� �������� ��� x[i]
            y[i] = rand() % 100; // ��������� �������� ��� y[i]
        }
    }

    // ���������� �������� x � y ����� ���������� � ������� ������� MPI_Scatter
    MPI_Scatter(&x[0], block, MPI_INT, &x_block[0], block, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(&y[0], block, MPI_INT, &y_block[0], block, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // ����� �������� x � y �� �������� � ������ 0
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
        sum += x_block[i] * y_block[i]; // ���������� ����� ������������ ��������� ������ x_block � y_block
    }

    int result;

    // ���� � ������������ ��������� ���� � ������� ������� MPI_Reduce
    MPI_Reduce(&sum, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // ����� ���������� �� �������� � ������ 0
        printf("result = %d\n", result);
    }

    MPI_Finalize(); // ��������� ������ � MPI

    return 0;
}
