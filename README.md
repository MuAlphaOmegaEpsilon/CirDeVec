# CirDeVec

CirDeVec contains a templated implementation of a hybrid data-structure that is heavily inspired by the behaviour of circular buffers, double-ended queues, and vectors.

## Additional info

CirDeVec, also called CDV for short, basically behaves as a symmetric vector, where symmetrical means that doing an insert/remove operation near the head has equal cost compared to the same operation near the head, instead of the classical asymmetrical vector, where asymmetrical means that the cost of issueing an insert/remove operation near the head has a much higher cost compared to the same operation near the tail. 

The sizeof CDV itself is quite cache-friendly, since it only uses 4 pointers internally:
* [64bit] 32B each, meaning that up to 2 CDVs can be put inside a single 64B cache line
* [32bit] 16B each, meaning that up to 4 CDVs can be put inside a single 64B cache line

<style
  type="text/css">
h2 {color:red;}

p {color:blue;}
</style>
okay