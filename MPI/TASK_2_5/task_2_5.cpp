#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    const int MATRIX_SIZE = 10;
    int rank;
    int size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    if (rank == 0) {
        int matrix[MATRIX_SIZE][MATRIX_SIZE];
        int transposedMatrix[MATRIX_SIZE][MATRIX_SIZE];

        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                matrix[i][j] = i + 2 * j;
            }
        }

        printf("original: \n ");
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        int destination = 1;
        int increment = 1;
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                MPI_Send(&matrix[i][j], 1, MPI_INT, destination, destination, MPI_COMM_WORLD);
                MPI_Send(&matrix[j][i], 1, MPI_INT, destination, destination, MPI_COMM_WORLD);
                if (increment % 5 == 0) {
                    destination++;
                }
                increment++;
            }
        }

        destination = 1;
        increment = 1;
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                MPI_Recv(&transposedMatrix[i][j], 1, MPI_INT, destination, destination, MPI_COMM_WORLD, &status);
                MPI_Recv(&transposedMatrix[j][i], 1, MPI_INT, destination, destination, MPI_COMM_WORLD, &status);
                if (increment % 5 == 0) {
                    destination++;
                }
                increment++;
            }
        }
        printf("transposed: \n ");
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                printf("%d ", transposedMatrix[i][j]);
            }
            printf("\n");
        }
    }
    else if (rank <= ((MATRIX_SIZE * MATRIX_SIZE) / 5)) {
        int a;
        int b;
        for (int increment = 0; increment < 5; increment++) {
            MPI_Recv(&a, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);
            MPI_Recv(&b, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, &status);

            MPI_Send(&b, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
            MPI_Send(&a, 1, MPI_INT, 0, rank, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
}
