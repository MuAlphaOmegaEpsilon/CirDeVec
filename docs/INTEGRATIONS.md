# [<img src="https://user-images.githubusercontent.com/26225010/44673467-ebbabe80-aa2b-11e8-9754-8b8b0b137ac1.png" height="128" alt="CirDeVec" title="CirDeVec GitHub Homepage">](https://github.com/MuAlphaOmegaEpsilon/CirDeVec) - Integrations

> ### ***CirDeVec***, a **Cir**cular **D**ouble-**e**nded **Vec**tor data-structure.

## Table of contents

- [The concept](#The-concept): a little overview at the basic concept of the implementation.
- [API](#API): some informations about the API of **CirDeVec**.
- [Efficiency](#Efficiency): some informations about the efficiency of **CirDeVec**.
- [Cache friendliness](#Cache-friendliness): the internal representation aims to be cache friendly.



## Integrations

This repository has an integrated benchmark, which is useful to assess the performance of the **CirDeVec** data structure against the commonly used **vector** and **deque**.

### Download benchmark dependencies

In order to launch the benchmark, you will first need to download the Google Benchmark library like this:

```bash
# If you aren't already inside the CirDeVec repository folder
$ cd Cirdevec

$ cd scripts
$ chmod +x downloadTestDependencies.sh
$ ./downloadTestDependencies.sh
$ cd ..
```

### Run the benchmark



```bash
# If you aren't already inside the CirDeVec repository folder
$ cd Cirdevec
#
$ cd build
$ cmake .. -DBENCH=ON
$ make
# 
$ ./bench
```