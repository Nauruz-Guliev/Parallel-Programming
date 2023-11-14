#include <iostream>
#include <mpi.h>
#include <random>

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    const int part = 20;
    const int vector_size = 100;
    int a[vector_size];

    if (rank == 0) {
        printf("a: ");
        for (int i = 0; i < vector_size; i++) {
            a[i] = rand() % 100;
            printf("%d ", a[i]);
        }
        printf("\n\n\n||a||: ");
    }

    double summ = 0.0;
    double norm = 0.0;

    int local_size = vector_size / size;
    int b[part];

    MPI_Scatter(a, local_size, MPI_INT, b, local_size, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < local_size; ++i) {
        summ += b[i];
    }

    MPI_Reduce(&summ, &norm, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("%.6f\n", norm);
    }

    printf("\n");

    MPI_Finalize();

    return 0;
}