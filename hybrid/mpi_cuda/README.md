# MPI + CUDA ([link](https://docs.ccv.brown.edu/oscar/gpu-computing/mpi-cuda))
Compilation command:
```
mpic++ -c mpi_cuda_main.cpp
nvcc -c mpi_cuda_kernel.cu
mpic++ mpi_cuda_main.o mpi_cuda_kernel.o -lcudart -L/usr/local/cuda/lib64
```

Execution command:
```
mpiexec -n {N} ./a.out
```
