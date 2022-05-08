#include <cstdio>
#include <mpi.h>
using namespace std;

int main() {
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello World from process %i of %i process\n", rank, size);
    
    MPI_Finalize();
    return 0;
}
