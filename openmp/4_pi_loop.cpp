#include <cstdio>
#include <cmath>
#include <omp.h>
using namespace std;

#define NUM_THREADS 2
#define N_STEPS 100000000

int main() {
    double sum = 0, pi = 0;
    double step = 1.0 / (double)N_STEPS;

    double start_time = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    // #pragma omp parallel
    // {
    //     double x, y;
    //     #pragma omp for reduction (+:sum)
    //     for(int i = 0; i < N_STEPS; i++) {
    //         x = (i + 0.5) * step;
    //         y = 4.0 / (1.0 + x*x);
    //         sum += y;
    //     }
    // }

    double x, y;
    #pragma omp parallel for reduction (+:sum) private(x, y)
    for(int i = 0; i < N_STEPS; i++) {
        x = (i + 0.5) * step;
        y = 4.0 / (1.0 + x*x);
        sum += y;
    }
    
    double end_time = omp_get_wtime();
    printf("Time: %f\n", end_time - start_time);

    pi = sum * step;
    printf("Integral: %.17g\n", pi);
    printf("Error: %.17g\n", abs(pi - M_PI));
}
