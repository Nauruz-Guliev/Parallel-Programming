#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MATRIX_SIZE 10

int main() {
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    float A[MATRIX_SIZE][MATRIX_SIZE];
    float B[MATRIX_SIZE][MATRIX_SIZE];
    float C[MATRIX_SIZE][MATRIX_SIZE];

    if (rank == 0) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                A[i][j] = (float)(i * MATRIX_SIZE + j);
                B[i][j] = 1.0;
            }
        }
    }

    MPI_Bcast(&A, MATRIX_SIZE * MATRIX_SIZE, MPI_FLOAT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&B, MATRIX_SIZE * MATRIX_SIZE, MPI_FLOAT, 0, MPI_COMM_WORLD);

    int rows_per_process = MATRIX_SIZE / size;
    int start_row = rank * rows_per_process;
    int end_row = start_row + rows_per_process;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }

    float* recv_buf = NULL;
    if (rank == 0) {
        recv_buf = (float*)malloc(MATRIX_SIZE * MATRIX_SIZE * sizeof(float));
    }
    MPI_Gather(&C[start_row], rows_per_process * MATRIX_SIZE, MPI_FLOAT, recv_buf, rows_per_process * MATRIX_SIZE, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result matrix C:\n");
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                printf("%.2f ", recv_buf[i * MATRIX_SIZE + j]);
            }
            printf("\n");
        }
        free(recv_buf);
    }

    MPI_Finalize();
}
