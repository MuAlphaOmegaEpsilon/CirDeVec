/**
 * @brief This is the header file for the C++ implementation of CirDeVec, a Circular Double-Ended Vector data-structure. 
 * CirDeVec contains a templated implementation of a mixed data-structure that is heavily inspired by the behaviour of
 * circular buffers, double-ended queues, and vectors.
 * CirDeVec, also called CDV for short, basically behaves as a symmetric vector, where symmetrical means that doing an insert/remove operation near
 * the head has equal cost compared to the same operation near the head, instead of the classical asymmetrical vector, where asymmetrical means
 * that the cost of doing an insert/remove operation near the head has a much higher cost compared to the same operation near the tail.
 * 
 * @file CirDeVec.hpp
 * @license GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/MinLog
 * @date 11-07-2018
 */

// Never include this header twice or more in a row
#ifndef CIRDEVEC_HPP 
#define CIRDEVEC_HPP
#pragma once


template <class T, class Alloc = std::allocator<T>> class cirdevec 
{
private:
	T* head;
	T* tail;
	T* dataBegin;
	T* dataEnd;
};
#endif