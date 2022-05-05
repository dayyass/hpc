#include <cstdio>
#include <omp.h>
using namespace std;

int main() {
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        printf("hello(%i)", ID);
        printf(" world(%i)\n", ID);
    }
}
