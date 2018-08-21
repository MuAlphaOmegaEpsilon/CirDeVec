/**
 * @brief This is the header-only file for the C++ implementation of CirDeVec, a Circular Double-ended Vector data-structure.  
 * Keep track of the latest updates of this project at https://github.com/MuAlphaOmegaEpsilon/CirDeVec
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
#include <string>

/**
 * @brief A Circular Double-ended Vector data-structure. 
 * @tparam T Is the type of the elements that the collection will contain.
 * If your type T is a struct or a class, be sure to have its member variables correctly placed and aligned in memory in order to achieve greater performances.
 */
template <class T> class cirdevec 
{
private:
	// Member variables
	T* dataHead; 	/// This points to the element at the head of the collection, if and only if the collection is not empty.
	T* dataTail;	/// This points to the element at the tail of the collection, if and only if the collection is not empty.
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
	
	//constexpr static string info = "[CirDeVec <" + typeid (T).name () + ">] INFO:\n";

public:
	// Type definitions
	//typedef T* iterator; /// The type definition of an iterator.
	//typedef const T* const_iterator; /// The type definition of a constant iterator.

	// Contructors and destructors
	cirdevec () noexcept; 
	explicit cirdevec (unsigned int) noexcept;
	explicit cirdevec (unsigned int, const T&) noexcept;
	cirdevec (T*, T*);
	cirdevec (std::initializer_list <T>);
	cirdevec (const cirdevec <T> &);
	cirdevec (cirdevec <T> &&) noexcept;
	~cirdevec () noexcept;
	cirdevec <T> & operator = (const cirdevec <T> &);
	cirdevec <T> & operator = (cirdevec <T> &&);
	cirdevec <T> & operator = (std::initializer_list <T>);
	void assign (unsigned int, const T &);
	void assign (T*, T*);
	void assign (std::initializer_list <T>);

	// iterators:
	T* begin () noexcept;
	const T* begin () const noexcept;
	T* end () noexcept;
	const T* cend () const noexcept;
	/*
	reverse_iterator rbegin () noexcept;
	const_reverse_iterator crbegin() const noexcept;
	reverse_iterator rend() noexcept;
	const_reverse_iterator crend() const noexcept;
	*/

	// 23.3.11.3, capacity:
	bool empty () const noexcept;
	bool full () const noexcept;
	unsigned int size () const noexcept;
	unsigned int max_size () const noexcept;
	unsigned int capacity () const noexcept;
	void resize (unsigned int);
	void resize (unsigned int, const T &);
	void reserve (unsigned int);
	void shrink_to_fit ();

	// element access
	T& operator [] (unsigned int);
	const T& operator [] (unsigned int) const;
	T& at (unsigned int);
	const T& at (unsigned int) const;
	T& front ();
	const T& front () const;
	T& back ();
	const T& back () const;

	// 23.3.11.4, data access:
	T * data() noexcept;
	const T * data() const noexcept; 

	// 23.3.11.5, modifiers:
	template <class ... Args> void emplace_back (Args&& ...);
	void push_back (const T &);
	void push_back (T &&);
	void pop_back ();
	template <class ... Args> void emplace_front (Args&& ...);
	void push_front (const T &);
	void push_front (T &&);
	void pop_front ();

	template <class ... Args> T* emplace (const T*, Args&& ...); 
	T* insert (const T*, const T&);
	T* insert (const T*, T&&);
	T* insert (const T*, unsigned int, const T&);
	template <class InputIt> T* insert (const T*, InputIt, InputIt);
	T* insert (const T*, std::initializer_list <T>);
	T* erase (const T*);
	T* erase (const T*, const T*);
	void swap (cirdevec <T> &);
	void clear () noexcept;

	bool operator == (const cirdevec <T> &) const;
	bool operator != (const cirdevec <T> &) const;
	bool operator < (const cirdevec <T> &) const;
	bool operator <= (const cirdevec <T> &) const;
	bool operator > (const cirdevec <T> &) const;
	bool operator >= (const cirdevec <T> &) const;
};

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