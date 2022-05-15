# High Performance Computing

- [OpenMP](./openmp/)
- [MPI](./mpi/)
- [CUDA](./cuda/)

### MPI + OpenMP
Compilation command:
```
mpic++ -fopenmp mpi_openmp.cpp
```

Execution command:
```
OMP_NUM_THREADS={M} mpiexec -n {N} ./a.out
```

### MPI + CUDA
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
