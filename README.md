# CirDeVec

CirDeVec, a **Cir**cular **D**ouble-**e**nded **Vec**tor implementation. 

CirDeVec is a hybrid data-structure that is heavily inspired by the behaviour of circular buffers, deques, and vectors.

## Table of contents
1. [API](#API)
2. [Some paragraph](#paragraph1)
    1. [Sub paragraph](#subparagraph1)
3. [Another paragraph](#paragraph2)


<!-- toc -->

## API

The CirDeVec API is basically the same of the deque one, but the internal implementation is much more similar to a vector, with the added bonus of circularity. 

From an efficiency point of view, everything is the same as vector, with a few differences:
* push_front has an O(1) amortized cost, instead of O(N)
* insert has an O(N) cost, the same as vector, but while vector has to move exactly N elements in the worst case scenario (front insert), CirDeVec only needs to move N/2 elements in the worst case (middle insert)



## Tools needed to take full advantage of this repository

Here is a list of extra-tools needed for certain purposes; a list of commands to install the tools on Ubuntu/Debian systems is also given down below:

* [<img src="https://git-scm.com/images/logo@2x.png" height="52" alt="Git" title="https://git-scm.com/">](https://git-scm.com/): it automates the download of both, the repository itself and the library needed for benchmarking.
  ```bash
  sudo apt install git
  ```
* [<img src="https://cmake.org/wp-content/uploads/2014/06/cmake_logo-main.png" height="70" alt="CMake" title="https://cmake.org/">](https://cmake.org/): used to create makefiles and such in an automated fashion.
  ```bash
  sudo apt install cmake
  ```
* [<img src="http://www.stack.nl/~dimitri/doxygen/images/doxygen.png" height="52" alt="Doxygen" title="http://www.doxygen.org/">](http://www.doxygen.org/): it generates documentation from source code.
  ```bash
  sudo apt install doxygen
  ```




## Cloning this repository

With the command below you will download the content of this repository in CURRENT_FOLDER/CirDeVec/.

```bash
$ git clone https://github.com/MuAlphaOmegaEpsilon/CirDeVec
```




## Benchmark CirDeVec

This repository has an integrated benchmark, which is useful to assess the performance of the CirDeVec data structure against the commonly used vector.

### Download benchmark dependencies

In order to launch the benchmark, you will first need to download the Google Benchmark library like this:

```bash
# First go into the repo folder, if you haven't already
$ cd Cirdevec

$ cd scripts
$ chmod +x downloadTestDependencies.sh
$ ./downloadTestDependencies.sh
$ cd ..
```

### Run the benchmark



```bash
# First go into the repo folder, if you haven't already
$ cd Cirdevec

$ cd build
$ cmake .. -DBUILD_TESTING=ON
$ make
$ make test
```




## Additional info

CirDeVec, also called CDV for short, basically behaves as a symmetric vector, where symmetrical means that doing an insert/remove operation near the head has equal cost compared to the same operation near the head, instead of the classical asymmetrical vector, where asymmetrical means that the cost of issueing an insert/remove operation near the head has a much higher cost compared to the same operation near the tail. 

The sizeof CDV itself is quite cache-friendly, since it only uses 4 pointers internally:
* [64bit] 32B each, meaning that up to 2 CDVs can be put inside a single 64B cache line
* [32bit] 16B each, meaning that up to 4 CDVs can be put inside a single 64B cache line



IMAGES
[Git]: https://git-scm.com/images/logo@2x.png