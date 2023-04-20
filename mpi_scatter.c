#include <stdio.h>
#include <mpi.h>

int main()
{
    int rank, size;
    int send[3], recv;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for (int i = 0; i<size; i++)
        send[i] = i+1;
    
    MPI_Scatter(send, 1, MPI_INT, &recv, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf(" %d: recv = %d\n", rank, recv);
    MPI_Finalize();
    return 0;
}