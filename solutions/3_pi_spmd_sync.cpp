#include <cstdio>
#include <omp.h>
using namespace std;

#define NUM_THREADS 2
#define N_STEPS 100000000

int main() {
    double sum, pi = 0;
    double step = 1.0 / (double)N_STEPS;

    double start_time = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        double x, y, sum_p = 0;
        int n_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();

        for(int i = thread_id; i < N_STEPS; i+=n_threads) {
            x = (i + 0.5) * step;
            y = 4.0 / (1.0 + x*x);
            sum_p += y;
        }
        #pragma omp critical  // atomic
        sum += sum_p;
    }
    
    double end_time = omp_get_wtime();
    printf("Time: %f\n", end_time - start_time);

    pi = sum * step;
    printf("Integral: %f\n", pi);
}
