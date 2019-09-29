/**
 * @brief Header-only file for the C++ implementation of CirDeVec, a Circular Double-ended Vector data-structure.  
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

//#include <memory>
#include <cstdint>
#include <string>






/**
 * @brief A Circular Double-ended Vector data-structure. 
 * @tparam T Is the type of the elements that the collection will contain.
 * CirDeVec is "naturally aligned", in order to maximize its cache friendliness.
 * If your type T is a struct or a class, be sure to have its member variables
 * correctly placed and aligned in memory in order to achieve greater performance.
 */
template <class T> 
class alignas (4 * sizeof (T*)) cirdevec 
{

/**********| PRIVATE MEMBER VARIABLES |*********/
/*    Contains the class internal footprint.   */

private:

	/// Pointer to the element at the head of the collection. 
	// When the collection is empty, this has the same meaning of the dataTail pointer.
	T* head; 	

	/// Pointer to the next free element-slot at the tail of the collection. 
	// When the collections is full, this has the same meaning of the dataHead pointer.
	T* tail;	

	/// Pointer to the dynamically allocated memory.
	// This pointer is aligned to the cacheline size, so it's going to have the \f$log_2(cachelineSize)\f$ least significant bits set to zero.
	// The aforementioned least significant bits are going to be used to "tag" the pointer with extra information.
	T* begin_TAGGED;	

	/// Pointer to the first byte outside the allocated memory.
	// This pointer is aligned to the cacheline size, so it's going to have the \f$log_2(cachelineSize)\f$ least significant bits set to zero.
	T* end;

/************| CONSTEXPR UTILITIES |************/
/*   Contains constant expressions and macros  */
/*     used to sculpt the functionality of     */
/*             the data structure.             */

private:

			

	constexpr uint16_t bitsWastedInCachelines (uint32_t);
	constexpr uint8_t bytesWastedInCachelines (uint32_t);
	constexpr uint8_t cachelineSize (); 
	
	

	

	/** @brief Gives back the number of whole elements that can be contained inside the number of cachelines specified. */
	

	/** @brief Gives back the number of whole elements that can be contained inside the number of cachelines specified. */
	constexpr uint16_t elementsInCachelines (uint32_t numCacheLines)
	{
		return (uint32_t) cachelineSize () * numCacheLines / sizeof (T);
	}
};

/**
 * @brief Gives back the number of bits wasted when filling with elements a given amount of cachelines.
 * This function underneath makes use of the "sizeof" function, which has byte-granularity:
 * don't expect this constexpr function to have bit-granularity!
 * @tparam T Is the type of the elements that the collection will contain.
 * @param numCacheLines The number of cachelines to eventually fill with elements.
 * @return constexpr uint16_t The remainding space.
 */
template <class T>
constexpr uint16_t cirdevec <T>::bitsWastedInCachelines (uint32_t numCacheLines)
{
	return 8 * bytesWastedInCachelines (numCacheLines);
}

/**
 * @brief Gives back the number of bytes wasted when filling with elements a given amount of cachelines.
 * This function underneath makes use of the "sizeof" function, which has byte-granularity.
 * @tparam T Is the type of the elements that the collection will contain.
 * @param numCacheLines The number of cachelines to eventually fill with elements.
 * @return constexpr uint8_t The remainding space.
 */
template <class T>
constexpr uint8_t cirdevec <T>::bytesWastedInCachelines (uint32_t numCacheLines)
{
	return cachelineSize () * numCacheLines % sizeof (T);
}








/*

public:
	// Type definitions
	//typedef T* iterator; /// The type definition of an iterator.
	//typedef const T* const_iterator; /// The type definition of a constant iterator.

	// Contructors and destructors
	cirdevec () noexcept = default; ///TODO: default dtor is just for debug purposes: this should be removed when defining the function
	explicit cirdevec (unsigned int) noexcept;
	explicit cirdevec (unsigned int, const T&) noexcept;
	cirdevec (T*, T*);
	cirdevec (std::initializer_list <T>);
	cirdevec (const cirdevec <T> &);
	cirdevec (cirdevec <T> &&) noexcept;
	~cirdevec () noexcept = default; ///TODO: default dtor is just for debug purposes: this should be removed when defining the function
	cirdevec <T> & operator = (const cirdevec <T> &);
	cirdevec <T> & operator = (cirdevec <T> &&);
	cirdevec <T> & operator = (std::initializer_list <T>);
	void assign (unsigned int, const T &);
	void assign (T*, T*);
	void assign (std::initializer_list <T>);

	// utility
	void getAlignment (T*, int&, long&) noexcept;
	void getCacheLineInfo () noexcept;

	// iterators:
	T* begin () noexcept;
	const T* begin () const noexcept;
	T* end () noexcept;
	const T* cend () const noexcept;
	
	reverse_iterator rbegin () noexcept;
	const_reverse_iterator crbegin() const noexcept;
	reverse_iterator rend() noexcept;
	const_reverse_iterator crend() const noexcept;
	

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
	printf ("[CIRDEVEC] standard ctor called, class fields are:\n");
	printf ("this: %p, ALGND: %s\n", this, ((unsigned long)(void*) this % (unsigned long) (4 * sizeof (void*)) == 0) ? "yes" : "no");
	dataHead = dataTail = arrayBegin = new T [baseElementsAllocNum];
	arrayEnd = arrayBegin + baseElementsAllocNum;

	int beginLSbZ, endLSbZ;
	long beginAlgnmt, endAlgnmt;
	getAlignment (arrayBegin, beginLSbZ, beginAlgnmt);
	getAlignment (arrayEnd, endLSbZ, endAlgnmt);
	printf ("arrayBegin: %p (LSbZ: %i, ALGNMNT: %liB) \narrayEnd:   %p (LSbZ: %i, ALGNMNT: %liB)\n", arrayBegin, beginLSbZ, beginAlgnmt, arrayEnd, endLSbZ, endAlgnmt);
	getCacheLineInfo ();
}

template <class T>
cirdevec <T>::~cirdevec () noexcept
{
	printf ("[CIRDEVEC] standard dtor called\n");
	//printf ("[CIRDEVEC] L1 Cache Line size is: %d Bytes\n", __builtin_hardware_destructive_interference_size ());
	delete [] arrayBegin;
	dataHead = dataTail = arrayBegin = arrayEnd = nullptr;
}

template <class T>
void cirdevec <T>::getAlignment (T* ptr, int& leastSignificantBitsZeroed, long& alignment) noexcept
{
	leastSignificantBitsZeroed = 0;
	alignment = 1;
	while (((long) ptr & alignment) == 0x00000000)
	{
		leastSignificantBitsZeroed++;
		alignment = alignment << 1;
	}
}

template <class T>
void cirdevec <T>::getCacheLineInfo () noexcept
{
	int itemsAllocated = capacity ();
	int bytesAllocated = itemsAllocated * T_size;
	int cachelineSpan = 1 + (long) (arrayEnd - 1) / cachelineSize - (long) arrayBegin / cachelineSize;
	int bytesWasted = (unsigned long)(void*) arrayBegin % (unsigned long) cachelineSize;

	printf ("Items allocated: %d\nBytes allocated: %d\nNumber of cachelines used: %d\nBytes wasted on the first cacheline: %d\n\n", itemsAllocated, bytesAllocated, cachelineSpan, bytesWasted);
}

template <class T>
unsigned int cirdevec <T>::capacity () const noexcept
{
	return arrayEnd - arrayBegin;
}
*/
#endif
