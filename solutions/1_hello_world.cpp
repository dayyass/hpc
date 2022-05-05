#include <cstdio>
#include <omp.h>
using namespace std;

#define NUM_THREADS 4

int main() {

    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        printf("Hello World from thread %i of %i threads\n", thread_id, num_threads);
    }
}
