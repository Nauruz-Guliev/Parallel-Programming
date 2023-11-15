//#include <iostream>
//#include <mpi.h>
//
//int main(int argc, char** argv) {
//
//    int rank;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Status status;
//    int count;
//
//    const int N = 15;  // Размер матрицы
//    const int PART = 5;  // Размер блока обработки
//
//    if (rank == 0) {  // Процесс 0
//        int a[N][N];
//        int b[N][N];
//        int c[N][N];
//
//        // Заполнение и вывод матриц A и B
//        printf("A:\n");
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                a[i][j] = rand() % 5 + 1;
//                printf("%d ", a[i][j]);
//            }
//            printf("\n");
//        }
//
//        printf("\nb:\n");
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                b[i][j] = rand() % 8 + 1;
//                printf("%d ", b[i][j]);
//            }
//            printf("\n");
//        }
//
//        int n = 1;
//        int j = 0;
//        for (int i = 0; i < N; i += PART, n++) {
//            MPI_Send(&a[i][j], PART * N, MPI_INT, n, 10, MPI_COMM_WORLD);
//            MPI_Send(&b[j][j], N * N, MPI_INT, n, 10, MPI_COMM_WORLD);
//        }
//
//        n = 1;
//        for (int i = 0; i < N; i += PART, n++) {
//            MPI_Recv(&c[i][j], PART * N, MPI_INT, n, 10, MPI_COMM_WORLD, &status);
//        }
//
//        // Вывод матрицы C
//        printf("\nC:\n");
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                printf("%d ", c[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    else {  // Остальные процессы
//        MPI_Probe(0, 10, MPI_COMM_WORLD, &status);
//        MPI_Get_count(&status, MPI_INT, &count);
//        int a[PART][N];
//        int b[N][N];
//        int c[PART][N];
//
//        // Инициализация матрицы C
//        for (int i = 0; i < PART; i++) {
//            for (int j = 0; j < N; j++) {
//                c[i][j] = 0;
//            }
//        }
//
//        // Получение подматриц A и B
//        MPI_Recv(&a[0][0], PART * N, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
//        MPI_Recv(&b[0][0], N * N, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
//
//        // Вычисление подматрицы C
//        for (int i = 0; i < PART; i++) {
//            for (int j = 0; j < N; j++) {
//                for (int k = 0; k < N; k++) {
//                    c[i][j] += a[i][k] * b[k][j];
//                }
//            }
//        }
//        MPI_Send(&c, PART * N, MPI_INT, 0, 10, MPI_COMM_WORLD);
//    }
//
//    MPI_Finalize();
//
//    return 0;
//}
