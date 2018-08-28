# [<img src="https://user-images.githubusercontent.com/26225010/44673467-ebbabe80-aa2b-11e8-9754-8b8b0b137ac1.png" height="100" alt="CirDeVec" title="CirDeVec GitHub Homepage">](https://github.com/MuAlphaOmegaEpsilon/CirDeVec) - Inclusion

> ### ***CirDeVec***, a **Cir**cular **D**ouble-**e**nded **Vec**tor data-structure.



Let's get pragmatic.



## Table of contents

- [Include statement](#Include-statement): bring me in!
- [Header file](#Header-file): where's the header!?
- [CMake](#CMake): for bug-proof coders only.



## Include statement

Adding this library to your current source/header files is quite easy:

```c++
#include <CirDeVec/CirDeVec.hpp>
```



## Header file

If you are that kind of programmer that collects header files, or that simply prefers compiling the old way, than SEEK NO MORE!
Here is your header file, located in [PATH_TO_REPO/include/CirDeVec/](../include/CirDeVec/CirDeVec.hpp).



## CMake

Are you using a CMakeLists.txt file to manage your build system? Then just do this.

```cmake
# Run the CMakeLists.txt file of this project
ADD_SUBDIRECTORY (YOUR_PATH_TO_REPO)	
# Link against this library
TARGET_LINK_LIBRARIES (your_executable_name CirDeVec)
```