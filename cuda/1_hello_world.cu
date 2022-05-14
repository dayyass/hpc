#include <cstdio>

__global__  // __global__ functions, or "kernels", execute on the device
void hello_kernel() {
    printf("Hello world from the device!\n");
}

int main() {

    // greet from the host
    printf("Hello world from the host!\n");

    // launch a kernel with a single thread to greet from the device
    hello_kernel<<<1,1>>>();
    
    // wait for the device to finish so that we see the message
    cudaDeviceSynchronize();

    return 0;
}
