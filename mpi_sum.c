#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main() 
{
    int i, n, m, size, rank;
    double *numbers, sum, totalsum;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    n = size; // n은 프로세스 개수로 설정
    m = 24; // 각 프로세스가 처리할 숫자 개수

    numbers = (double*)malloc(sizeof(double) * m);

    // 각 프로세스에 할당된 숫자 생성
    for (i = 0; i < m; i++) 
    {
        numbers[i] = i+1;
    }

    /*
    // 각 프로세스가 처리할 숫자 범위 계산
    int start = rank * (m/n);
    int end = start + (m/n);

    // 각 프로세스에 할당된 숫자만큼의 부분합 계산
    sum = 0.0;
    for (i = start; i < end; i++) 
    {
        sum += numbers[i];
    }
    */

   // 각 프로세스에 할당된 숫자 범위 계산
    int start = rank * (m/n);
    int end = start + (m/n);

    // 마지막 프로세스가 나머지 숫자를 처리하는 경우
    if (rank == n-1) {
        end = m;
    }

    // 각 프로세스에 할당된 숫자만큼의 부분합 계산
    sum = 0.0;
    for (i = start; i < end; i++) {
        sum += numbers[i];
    }

    // 부분합을 모든 프로세스에서 합산하여 총합 계산
    MPI_Reduce(&sum, &totalsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // 결과 출력
    if (rank == 0) 
    {
        printf("Total sum is %.2f\n", totalsum);
    }

    free(numbers);

    MPI_Finalize();
    return 0;
}
