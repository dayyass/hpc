# OpenMP / MPI

- [OpenMP](./openmp/)
- [MPI](./mpi/)

### MPI + OpenMP
Compilation command:
```
mpic++ -fopenmp mpi_openmp.cpp
```

Execution command:
```
OMP_NUM_THREADS={M} mpiexec -n {N} ./a.out
```
