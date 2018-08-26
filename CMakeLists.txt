###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.5)




###############################################################################
#                                  PROJECT                                    #
###############################################################################
PROJECT (CirDeVec VERSION 1.0.0 LANGUAGES CXX 
		DESCRIPTION "A C++ implementation of a Circular Double-ended Vector"
		HOMEPAGE_URL "https://github.com/MuAlphaOmegaEpsilon/CirDeVec/")




###############################################################################
#                                  OPTIONS                                    #
###############################################################################
OPTION (TEST "Is library testing enabled?" OFF)									# Default is OFF
OPTION (BENCH "Is library benchmarking enabled?" OFF)							# Default is OFF




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (CirDeVec INTERFACE)




###############################################################################
#                               HEADERS INCLUSION                             #
###############################################################################
TARGET_INCLUDE_DIRECTORIES (CirDeVec INTERFACE "include")						# The include folder of the CirDeVec library




###############################################################################
#                                    TESTS                                    #
###############################################################################
IF (TEST)
	INCLUDE (cmake/buildTests.cmake)
ENDIF ()




###############################################################################
#                                   BENCHMARK                                 #
###############################################################################
IF (BENCH)
	INCLUDE (cmake/buildBenchmark.cmake)
ENDIF ()




###############################################################################
#                                OPTIONS LISTING                              #
###############################################################################
MESSAGE (STATUS "Down here there is a list of useful options flags:")			# Listing the options flags
MESSAGE (STATUS "  [${TEST}] -DTEST=ON/OFF to enable/disable library functionality testing")
MESSAGE (STATUS "  [${BENCH}] -DBENCH=ON/OFF to enable/disable library benchmarking against vector")
MESSAGE (STATUS "")	