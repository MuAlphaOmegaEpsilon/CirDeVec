# [<img src="https://user-images.githubusercontent.com/26225010/44673467-ebbabe80-aa2b-11e8-9754-8b8b0b137ac1.png" height="100" alt="CirDeVec" title="CirDeVec GitHub Homepage">](https://github.com/MuAlphaOmegaEpsilon/CirDeVec) - Main Page

> ### ***CirDeVec***, a **Cir**cular **D**ouble-**e**nded **Vec**tor data-structure.

CirDeVec is a hybrid data-structure that is heavily inspired by the behaviour of circular buffers, deques, and vectors.

## Table of contents (with hyperlinks)

- [Repository folders structure](#Repository-folders-structure): a look at how the files are distributed in directories.
- [Download repository](#Download-Cirdevec): details on how to download this repository.
  - [Update repository](#Update-CirDeVec): details on how to update this repository.
- [Dependencies](#Dependencies): a list of dependencies and their use inside this project.


## Repository folders structure
Give a look at the [kriasoft's Folder Structure Conventions](https://github.com/kriasoft/Folder-Structure-Conventions) first if you need to, since the structure of this repository is based on that.

    .
    ├── build/                      # Local folder for project builds
    ├── cmake/                      # CMake script files
    ├── deps/                       # Dependency libraries (3rd party submodules)
    ├── docs/                       # Documentation markdown files
    ├── include/                    # Header files
    ├── tests/                      # Automated tests
    ├── CMakeLists.txt              # CMake main script file
    ├── Doxyfile                    # Doxygen configuration file
    ├── LICENSE.md                  # License markdown file 
    └── README.md                   # Readme markdown file (YOU ARE HERE)

## Download CirDeVec

Using the command below you can download the content of this repository in an automatically created  **CirDeVec** folder inside your current directory. ([Git](#Extra-tools) is needed)

```bash
$ git clone https://github.com/MuAlphaOmegaEpsilon/CirDeVec
```

### Update CirDeVec

If you already downloaded the **CirDeVec** repository, maybe some time ago, you might want to update it. You can use the command below.

```bash
# If you aren't already inside the CirDeVec repository folder
$ cd CirDeVec
# Update the repository
$ git pull origin master
```

## Dependencies

* [Google Benchmark library](https://github.com/google/benchmark): if you wish to benchmark the **CirDeVec** performance against other data structures, you need to download this.

  ```bash
  # If you aren't already inside the CirDeVec repository folder
  $ cd CirDeVec
  # Download the dependencies
  $ git submodule update --init
  ```



## Extra-tools

Here is a list of extra-tools needed for certain purposes; a list of commands to install the tools on Ubuntu/Debian systems is also given down below:

* [Build-essential (Linux only)](https://packages.debian.org/en/sid/build-essential): a collection of tools to build C and C++ projects.
  ```bash
  sudo apt-get install build-essential
  ```
* [<img src="https://git-scm.com/images/logo@2x.png" height="52" alt="Git" title="https://git-scm.com/" align="middle">](https://git-scm.com/): it automates the download of both, the repository itself and the library needed for benchmarking.
  ```bash
  sudo apt-get install git
  ```
* [<img src="https://cmake.org/wp-content/uploads/2014/06/cmake_logo-main.png" height="70" alt="CMake" title="https://cmake.org/" align="middle">](https://cmake.org/): used to create makefiles and such in an automated fashion.
  ```bash
  sudo apt-get install cmake
  ```
* [<img src="http://www.stack.nl/~dimitri/doxygen/images/doxygen.png" height="52" alt="Doxygen" title="http://www.doxygen.org/" align="middle">](http://www.doxygen.org/): it generates documentation from source code.
  ```bash
  sudo apt-get install doxygen
  ```