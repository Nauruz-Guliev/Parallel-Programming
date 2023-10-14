#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 1) {
        int array[ARRAY_SIZE];
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = rand() % 100;
        }

        for (int i = 0; i < size; i++) {
            if (i != rank) {
                MPI_Send(array, ARRAY_SIZE, MPI_INT, i, 0, MPI_COMM_WORLD);
                printf("Process 1 sent the array to process %d.\n", i);
            }
        }
    }
    else {
        MPI_Status status;
        int count;

        MPI_Probe(1, 0, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &count);

        int* receivedArray = new int[count];

        MPI_Recv(receivedArray, count, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);

        printf("Process %d received the array:\n", rank);
        for (int i = 0; i < count; i++) {
            printf("%d ", receivedArray[i]);
        }
        printf("\n");

        delete[] receivedArray;
    }

    MPI_Finalize();
    return 0;
}