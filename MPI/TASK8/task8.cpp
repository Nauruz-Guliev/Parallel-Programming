//#include <stdio.h>
//#include <random>
//#include <mpi.h>
//
//#define MATRIX_SIZE 3
//
//int main(int argc, char** argv) {
//	int size, rank;
//	int A[MATRIX_SIZE][MATRIX_SIZE], B[MATRIX_SIZE][MATRIX_SIZE];
//	int i, j;
//
//	int C[MATRIX_SIZE * MATRIX_SIZE];
//
//	MPI_Init(&argc, &argv);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	// Only process 0 initializes matrices
//	if (rank == 0) {
//		for (i = 0; i < MATRIX_SIZE; i++) {
//			for (j = 0; j < MATRIX_SIZE; j++) {
//				A[i][j] = rand() % 10;
//				B[i][j] = rand() % 10;
//			}
//		}
//
//		// Send matrices to other processes
//		for (i = 1; i < size; i++) {
//			MPI_Send(A, MATRIX_SIZE * MATRIX_SIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
//			MPI_Send(B, MATRIX_SIZE * MATRIX_SIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
//		}
//	}
//	else {
//		// Receive matrices
//		MPI_Recv(A, MATRIX_SIZE * MATRIX_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//		MPI_Recv(B, MATRIX_SIZE * MATRIX_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//	}
//
//	// Matrix multiplication
//	for (i = 0; i < MATRIX_SIZE; i++) {
//		C[i * MATRIX_SIZE + rank] = 0;
//		for (j = 0; j < MATRIX_SIZE; j++) {
//			C[i * MATRIX_SIZE + rank] += A[i][j] * B[j][rank];
//		}
//	}
//
//	// Gather results to process 0
//	MPI_Gather(C, MATRIX_SIZE * MATRIX_SIZE, MPI_INT, C, MATRIX_SIZE * MATRIX_SIZE, MPI_INT, 0, MPI_COMM_WORLD);
//
//	if (rank == 0) {
//		printf("Result matrix:\n");
//		for (i = 0; i < MATRIX_SIZE; i++) {
//			for (j = 0; j < MATRIX_SIZE; j++) {
//				printf("%d ", C[i * MATRIX_SIZE + j]);
//			}
//			printf("\n");
//		}
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}