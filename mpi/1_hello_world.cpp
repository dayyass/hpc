#include <cstdio>
#include <mpi.h>
using namespace std;

int main() {
    int rank, size, name_len;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Get_processor_name(processor_name, &name_len);

    printf("Hello World from processor %s, rank %i of %i processors\n", processor_name, rank, size);

    MPI_Finalize();
    return 0;
}
