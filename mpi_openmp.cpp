#include <cstdio>
#include <mpi.h>
#include <omp.h>
using namespace std;

int main() {

    MPI_Init(NULL, NULL);

    int world_size, world_rank, name_len;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Get_processor_name(processor_name, &name_len);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        printf(
            "Hello world from processor %s, rank %d out of %d processors, thread %d out of %d threads\n",
            processor_name, world_rank, world_size, thread_id, num_threads
        );
    }

    MPI_Finalize();
    return 0;
}
