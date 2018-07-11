###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.5)




###############################################################################
#                                  PROJECT                                    #
###############################################################################
PROJECT (CirDeVec LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "A C++ implementation of a Circular Double-Ended Vector")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (CirDeVec INTERFACE)




###############################################################################
#                               HEADERS INCLUSION                             #
###############################################################################
TARGET_INCLUDE_DIRECTORIES (CirDeVec INTERFACE "${PROJECT_SOURCE_DIR}/include")	




###############################################################################
#                                    TESTS                                    #
###############################################################################
IF (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)							# This IF-statement is true when someone is building the CirDeVec standalone
	IF (${BUILD_TESTING})														# This IF-statement is true when the -DBUILD_TESTING=ON flag is passed to the cmake command
		ADD_EXECUTABLE (CirDeVecTest "${PROJECT_SOURCE_DIR}/tests/main.cpp")
		TARGET_LINK_LIBRARIES (CirDeVecTest PRIVATE CirDeVec)
		SET_PROPERTY (TARGET CirDeVecTest PROPERTY CMAKE_CXX_FLAGS 				# Enable all warnings
						"${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")			
	ELSE ()
		MESSAGE (STATUS "Remember that you can build the examples in the tests/ folder by adding the -DBUILD_TESTING=ON to CMake.")
	ENDIF ()
ENDIF ()
