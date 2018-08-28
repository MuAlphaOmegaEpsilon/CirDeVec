# [<img src="https://user-images.githubusercontent.com/26225010/44673467-ebbabe80-aa2b-11e8-9754-8b8b0b137ac1.png" height="100" alt="CirDeVec" title="CirDeVec GitHub Homepage">](https://github.com/MuAlphaOmegaEpsilon/CirDeVec) - Integrations

> ### ***CirDeVec***, a **Cir**cular **D**ouble-**e**nded **Vec**tor data-structure.



This repository has some integrated modules that expands the simple functionality of a bare library. Remember that you need to 



## Table of contents

- [Benchmark](#Benchmark): let's crunch some numbers.
- [Unit-test](#Unit-test): yeah, but does it really work afterall?



## Benchmark

What's the purpose of a data-structure that can't even compete with its own competitors!? Run this benchmark to check if **CirDeVec** has all you are looking for.

```bash
# If you aren't already inside the CirDeVec repository folder
$ cd Cirdevec
# If you aren't already inside the build folder
$ cd build
# Run CMake with the benchmark module enabled, then build
$ cmake .. -DBENCH=ON
$ make
# Run the benchmark
$ ./bench
```



## Unit-test

The unit-test module is a suite of programs that make use of the library API, checking that all the functionalities are correctly implemented.

```bash
# If you aren't already inside the CirDeVec repository folder
$ cd Cirdevec
# If you aren't already inside the build folder
$ cd build
# Run CMake with the unit-test module enabled, then build
$ cmake .. -DTEST=ON
$ make
# Run the unit-test suite
$ make test
```