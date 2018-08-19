/**
 * @brief This is the header-only file for the C++ implementation of CirDeVec, a Circular Double-Ended Vector data-structure.  
 * You can keep track of the latest updates of this projecy on https://github.com/MuAlphaOmegaEpsilon/CirDeVec
 * @file CirDeVec.hpp
 * @license GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/
 * @date 11-07-2018
 */

// Never include this header twice or more in a row
#ifndef CIRDEVEC_HPP 
#define CIRDEVEC_HPP
#pragma once

#include <memory>

/**
 * @brief A Circular Double-Ended Vector collection class. 
 * CirDeVec contains a templated implementation of a hybrid data-structure that is heavily inspired by the behaviour of
 * circular buffers, double-ended queues, and vectors.
 * CirDeVec, also called CDV for short, basically behaves as a symmetric vector, where symmetrical means that doing an insert/remove operation near
 * the head has equal cost compared to the same operation near the head, instead of the classical asymmetrical vector, where asymmetrical means
 * that the cost of issueing an insert/remove operation near the head has a much higher cost compared to the same operation near the tail.
 * The memory of this data structures will be allocated in chunks, usually sized as a factor of the cache line size.
 * The sizeof CDV itself are quite cache-friendly, since it uses only 4 pointers:
 * on 64bit machines: 32B each, meaning that up to 2 CDVs can be put inside a single 64B cache line
 * on 32bit machines: 16B each, meaning that up to 4 CDVs can be put inside a single 64B cache line
 * @tparam T Is the type of the elements that the collection will contain.
 * If your type T is a struct or a class, be sure to have its member variables correctly placed and aligned in memory in order to achieve greater performances.
 */
template <class T> class cirdevec 
{
private:
	// Member variables
	T* dataHead; 	/// This points to the element at the head of the collection, if and only if the collection is not empty.
	T* dataTail;	/// This points to the first element outer to the collection.
	T* arrayBegin;	/// This points to the first byte of the allocated memory.
	T* arrayEnd;	/// This points to the first byte outer to the allocated memory.

	// Constant expressions: these are template dependant
	constexpr static unsigned int T_size = sizeof (T); /// The size of T in bytes.
	constexpr static unsigned int cachelineSize = 64; /// 64 bytes is the most widespread cache line size.
	constexpr static bool isCachelineSmallerThanT = (T_size > cachelineSize); /// A boolean that describes who's bigger between the sizeof(T) and the cacheline size.
	constexpr static unsigned int chunkSize = cachelineSize * ((isCachelineSmallerThanT) ? 1 + (T_size / cachelineSize) : 1); /// The actual chunk size should be the maximum between the sizeof(T) and the cacheline size.
	constexpr static unsigned int elementsPerChunk = chunkSize / T_size; /// The number of elements that entirely fit into a single chunk. This value will always be >= 1. 
	constexpr static unsigned int remainderPerChunk = chunkSize % T_size; /// The number of bytes wasted when memorizing T elements inside a single chunk.

	constexpr static unsigned int baseElementsAllocNum = 16; /// The first default allocation will be of at least the amount of elements specified here.
	constexpr static unsigned int baseAllocDiv = baseElementsAllocNum * T_size / chunkSize; /// The division between the total size occupied by the elements during the first allocation and the chunk size.
	constexpr static unsigned int baseAllocMod = baseElementsAllocNum * T_size % chunkSize; /// The modulo of the division between the total size occupied by the elements during the first allocation and the chunk size.
	constexpr static unsigned int baseChunksAllocNum = baseAllocDiv + ((baseAllocMod) ? 1 : 0); /// The number of chunks to allocate in order to fully contain all the elements during the first allocation.
	

public:
	// Type definitions
	typedef T* iterator; /// The type definition of an iterator.
	typedef const T* const_iterator; /// The type definition of a constant iterator.

	// Contructors and destructors
	cirdevec () noexcept; 
	explicit cirdevec (unsigned int) noexcept;
	cirdevec (unsigned int, const T&) noexcept;
	cirdevec (typename cirdevec <T>::iterator, typename cirdevec <T>::iterator );
	cirdevec (std::initializer_list <T>);
	cirdevec (const cirdevec <T> &);
	cirdevec (cirdevec <T> &&) noexcept;
	~cirdevec () noexcept;
	cirdevec <T> & operator = (const cirdevec <T> &);
	cirdevec <T> & operator = (cirdevec <T> &&);
	cirdevec <T> & operator = (std::initializer_list <T>);
	void assign (unsigned int, const T &);
	void assign (typename cirdevec <T>::iterator, typename cirdevec <T>::iterator);
	void assign (std::initializer_list <T>);

	// Interface functions
	void push_back (const T&);
};
template <class T> using cdv = cirdevec <T>;


template <class T>
cirdevec <T>::cirdevec () noexcept
{
	dataHead = dataTail = arrayBegin = new T [baseElementsAllocNum];
	arrayEnd = arrayBegin + baseElementsAllocNum;
}

template <class T>
cirdevec <T>::~cirdevec () noexcept
{
	delete [] arrayBegin;
	dataHead = dataTail = arrayBegin = arrayEnd = nullptr;
}

#endif