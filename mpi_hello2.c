#include <stdio.h>
#include <mpi.h>

// MPI_Send와 MPI_Recv에서 int type comm test
int main()
{
    int num = 0;
    int size, rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank != 0)
    {
        num = rank;
        MPI_Send(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    
    else
    {
        printf("%d\n", rank);

        for (int q = 1; q < size; q++)
        {
            MPI_Recv(&num, 1, MPI_INT, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            // MPI_Recv(&num, 1, MPI_INT, q, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%d\n", num);
        }
    }

    MPI_Finalize();
    return 0;
}