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
