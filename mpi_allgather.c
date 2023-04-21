#include <stdio.h>
#include <mpi.h>

int main()
{
    int rank, size;
    int send, recv[3];

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    send = rank + 1;

    MPI_Allgather(&send, 1, MPI_INT, recv, 1, MPI_INT, MPI_COMM_WORLD);

    printf("%d recv = ", rank);
    for (int i = 0; i < 3; i++)
    {
        printf(" %d", recv[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;

}