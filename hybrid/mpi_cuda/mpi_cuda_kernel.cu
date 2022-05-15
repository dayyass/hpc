#include <cstdio>

__global__
void kernel(int rank, int size) {
    printf("Hello world from the device, rank %d out of %d processors\n", rank, size);
}

extern void launch_kernel(int rank, int size) {
    kernel<<<1,1>>>(rank, size);
    cudaDeviceSynchronize();
}
