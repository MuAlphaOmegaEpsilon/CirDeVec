# [<img src="https://user-images.githubusercontent.com/26225010/44673467-ebbabe80-aa2b-11e8-9754-8b8b0b137ac1.png" height="100" alt="CirDeVec" title="CirDeVec GitHub Homepage">](https://github.com/MuAlphaOmegaEpsilon/CirDeVec) - Implementation

> ### ***CirDeVec***, a **Cir**cular **D**ouble-**e**nded **Vec**tor data-structure.

## Table of contents

- [The concept](#The-concept): a little overview at the basic concept of the implementation.
- [API](#API): some informations about the API of **CirDeVec**.
- [Efficiency](#Efficiency): some informations about the efficiency of **CirDeVec**.
- [Cache friendliness](#Cache-friendliness): the internal representation aims to be cache friendly.

## The concept

CirDeVec basically behaves as a symmetrical vector, where symmetrical means that doing an insert/remove operation near the head has equal cost compared to the same operation near the tail, instead of the classical asymmetrical vector, where asymmetrical means that the cost of issueing an insert/remove operation near the head has a much higher cost compared to the same operation near the tail: this property is given by the added circularity. 



## API

The **CirDeVec** API is basically the same of the **deque** one, but the internal implementation is much more similar to a **vector**, with the added bonus of circularity. 

*Custom allocators are not supported at the moment.



## Efficiency
From an efficiency point of view, everything is the same as **vector**, with a few differences:
* ***push_front*** has an **O(1)** amortized cost, instead of **O(N)**
* ***insert*** has an **O(N)** cost, the same as **vector**, but while **vector** has to move exactly N elements in the worst case scenario (front insert), **CirDeVec** only needs to move N/2 elements in the worst case (middle insert)



## Cache friendliness

4 pointers to T (template parameter) are needed in order to correctly structure the boundaries of the allocated array AND the circularity property, so the sizeof(CirDeVec <T>) itself is quite cache-friendly, since only those 4 pointers are used internally:

* [64bit] 32B for each CirDeVec instance, meaning that up to 2 instances can be put inside a single 64B cache line
* [32bit] 16B for each CirDeVec instance, meaning that up to 4 instances can be put inside a single 64B cache line