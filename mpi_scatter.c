#include <stdio.h>
#include <mpi.h>

int main()
{
    int rank, size;
    int send[6], recv[2];

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    for (int i = 0; i<6; i++)
        send[i] = i+1;
    
    MPI_Scatter(send, 2, MPI_INT, recv, 2, MPI_INT, 0, MPI_COMM_WORLD);
    for (int p = 0; p < 2; p++)
        printf(" %d: recv = %d\n", rank, recv[p]);
    MPI_Finalize();
    return 0;
}