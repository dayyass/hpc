#include <mpi.h>
using namespace std;

// cuda kernel function signature
void launch_kernel(int rank, int size);

int main() {

    MPI_Init(NULL, NULL);

    int world_size, world_rank;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // cuda kernel
    launch_kernel(world_rank, world_size);

    MPI_Finalize();
    return 0;
}
