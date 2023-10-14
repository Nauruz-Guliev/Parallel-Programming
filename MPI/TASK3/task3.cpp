#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    const int ARRAY_SIZE = 10;
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        printf("This program should be run with exactly 2 processes.\n");
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        int array[ARRAY_SIZE];
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = rand() % 100;
        }

        MPI_Send(array, ARRAY_SIZE, MPI_INT, 1, 0, MPI_COMM_WORLD);

        printf("Process 0 sent the array to process 1.\n");
    }
    else if (rank == 1) {
        int receivedArray[ARRAY_SIZE];

        MPI_Recv(receivedArray, ARRAY_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Process 1 received the array:\n");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", receivedArray[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
}
