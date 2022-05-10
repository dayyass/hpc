#include <cstdio>
#include <cmath>
#include <mpi.h>
using namespace std;

#define N_STEPS 100000000

int main() {

    MPI_Init(NULL, NULL);

    int size, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Only 2 processes required
    if (size != 2) {
        if (rank == 0) {
            printf("Error: 2 processes required\n");
            MPI_Abort(MPI_COMM_WORLD, MPI_ERR_OTHER); 
        }
    }

    double start_time = MPI_Wtime();

    double x, y, my_sum = 0;
    double step = 1.0 / (double)N_STEPS;

    for(int i = rank; i < N_STEPS; i += size) {
        x = (i + 0.5) * step;
        y = 4.0 / (1.0 + x*x);
        my_sum += y;
    }

    if (rank == 1) {
        MPI_Send(&my_sum, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
    } else {
        
        double other_sum = 0;
        MPI_Status status;
        MPI_Recv(&other_sum, 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &status);

        double end_time = MPI_Wtime();
        printf("Time: %f\n", end_time - start_time);

        double pi = (my_sum + other_sum) * step;
        printf("Integral: %.17g\n", pi);
        printf("Error: %.17g\n", abs(pi - M_PI));
    }

    MPI_Finalize();
    return 0;
}
