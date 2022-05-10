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

    double x, y, my_sum = 0;
    double step = 1.0 / (double)N_STEPS;

    for(int i = rank; i < N_STEPS; i += size) {
        x = (i + 0.5) * step;
        y = 4.0 / (1.0 + x*x);
        my_sum += y;
    }

    double sum = 0;
    MPI_Reduce(&my_sum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double pi = sum * step;
        printf("Integral: %.17g\n", pi);
        printf("Error: %.17g\n", abs(pi - M_PI));
    }

    MPI_Finalize();
    return 0;
}
