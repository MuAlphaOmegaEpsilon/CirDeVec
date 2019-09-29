/**
 * @brief Header-only file for the C++ implementation of ConstexprDSUtils.
 * A constant expression data-structure oriented utility library.  
 * This little library aims at giving some tools to improve the workflow
 * of data-structure coding, especially from a cache friendliness perspective,
 * without giving away anything in terms of performance, but instead trying
 * to squeeze out every piece of information about the architecture 
 * at compile-time. 
 * Keep track of the latest updates of this project at https://github.com/MuAlphaOmegaEpsilon/
 * @file ConstexprDSUtils.hpp
 * @license GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> 
 * @github https://github.com/MuAlphaOmegaEpsilon/
 * @date 18-09-2018
 */ 

/// Macro used as an "INCLUDE GUARD".
// Useful to prevent double-definition during link phase.
// It never includes this header twice or more in a row.
#ifndef CONSTEXPR_DS_UTILS_HPP 
#define CONSTEXPR_DS_UTILS_HPP
#pragma once

#include <cstdint>	// Portable integer types
#include <new> 		// Access to std::hardware_destructive_interference_size


/// Define this macro to use a custom defined cacheline size.
// This macro should be defined whenever there isn't 100% guarantee that the
// correct cacheline size will be programmatically obtained.
// When this macro is defined, remember to check the knownL1CachelineSize 
// constexpr value, since that will be used instead.
#define USE_KNOWN_L1_CACHELINE_SIZE

/// Define this macro to enable the usage of all the likely/unlikely macros
// commonly used to give hints to the compiler about branching.
// If your compiler doesn't support the built-in function used here, you
// can easily undefine this macro down here in order to nullify the hints.
#define USE_LIKELY_BRANCHING


#ifdef USE_LIKELY_BRANCHING
#define LIKELY(x)			__builtin_expect ((x), 1)			// Use this to wrap a single condition as likely to verify
#define UNLIKELY(x) 		__builtin_expect ((x), 0)			// Use this to wrap a single condition as unlikely to verify
#define likely_if(x) 		if (__builtin_expect ((x), 1))		// Use this to wrap an entire if-statement's condition as likely to verify
#define unlikely_if(x) 		if (__builtin_expect ((x), 0))		// Use this to wrap an entire if-statement's condition as unlikely to verify
#define likely_else_if(x) 	else if (__builtin_expect ((x), 1)) // Use this to wrap an entire else_if-statement's condition as likely to verify
#define unlikely_else_if(x) else if (__builtin_expect ((x), 0))	// Use this to wrap an entire if-statement's condition as unlikely to verify
#else
#define LIKELY(x)			x
#define UNLIKELY(x) 		x
#define likely_if(x) 		if (x)
#define unlikely_if(x) 		if (x)
#define likely_else_if(x) 	else if (x)
#define unlikely_else_if(x) else if (x)
#endif 

/// Defaulting the cacheline size to this value. 
// 64 bytes is the most widespread cache line size.
constexpr static uint16_t knownL1CachelineSize = 64U;


/**
 * @brief 
 * @return constexpr uint16_t 
 */
constexpr uint16_t cachelineSize () 
{
#ifdef USE_KNOWN_L1_CACHELINE_SIZE
	return knownL1CachelineSize;
#else
	return (uint8_t) std::hardware_destructive_interference_size;
#endif
}

#endif