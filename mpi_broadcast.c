#include <stdio.h>
#include <mpi.h>

int main()
{
    int rank;
    int msg[4];

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank==0)
    {
        for (int i = 0; i<4; i++)
            msg[i] = i+1;
    }
    else
    {
        for (int i = 0; i<4; i++)
            msg[i] = 0;
    }

    printf("%d: BEFORE:", rank);

    for (int i = 0; i<4; i++)
        printf(" %d", msg[i]);
    printf("\n");

    MPI_Bcast(msg, 4, MPI_INT, 0, MPI_COMM_WORLD);

    printf("%d: AFTER:", rank);

    for (int i = 0; i<4; i++)
        printf(" %d", msg[i]);
    printf("\n");

    MPI_Finalize();
    return 0;
}