#include <iostream>
#include <mpi.h>
#include <random>

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    int count;
    int a = 10;
    int b = 12;
    const int SIZE = 15;
    const int PART = 5;

    int x[SIZE];
    int y[SIZE];
    int z[SIZE];

    if (rank == 0) {
        for (int i = 0; i < SIZE; ++i) {
            x[i] = rand() % 100 + 1;
            y[i] = rand() % 100 + 1;
        }

        printf("x: ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", x[i]);
        }
        printf("\ny: ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", y[i]);
        }
        printf("\n");

        int n = 1;
        for (int i = 0; i < SIZE; i += PART, n++) {
            MPI_Send(&x[i], PART, MPI_INT, n, 10, MPI_COMM_WORLD);
            MPI_Send(&y[i], PART, MPI_INT, n, 10, MPI_COMM_WORLD);
        }

        n = 1;
        for (int i = 0; i < SIZE; i += PART, n++) {
            MPI_Recv(&z[i], PART, MPI_INT, n, 10, MPI_COMM_WORLD, &status);
        }

        printf("z: ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", z[i]);
        }
    }
    else {
        int x_chunk[PART];
        int y_chunk[PART];
        int z_chunk[PART];

        MPI_Recv(&x_chunk, PART, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
        MPI_Recv(&y_chunk, PART, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);

        for (int i = 0; i < PART; ++i) {
            z_chunk[i] = a * x_chunk[i] + b * y_chunk[i];
        }
        MPI_Send(&z_chunk, PART, MPI_INT, 0, 10, MPI_COMM_WORLD);
    }

    MPI_Finalize();

}