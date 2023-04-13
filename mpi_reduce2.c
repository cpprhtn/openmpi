#include <mpi.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int myrank;
    int a,b,c,d;

    a = 1;
    b = 0;
    c = 2;
    d = 0;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0)
    {
        printf("myrank = 0\n");
        MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
        MPI_Reduce(&c, &d, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    }

    else if (myrank == 1)
    {
        printf("myrank = 1\n");
        MPI_Reduce(&c, &d, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
        MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    }

    else if (myrank == 2)
    {
        printf("myrank = 2\n");
        MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
        MPI_Reduce(&c, &d, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    }

    if (myrank==0)
        printf("END\na = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    MPI_Finalize();

    return 0;
}