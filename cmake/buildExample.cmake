IF (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	
	ADD_EXECUTABLE (example "tests/example.cpp")							# Add the example.cpp as an executable to build
	TARGET_LINK_LIBRARIES (example CirDeVec)								# Linking to the CirDeVec static library
	
	SET_TARGET_PROPERTIES (example PROPERTIES 								# Enabling C++17 features: this is equivalent to adding the parameter -std=c++17 to the compiler	
							CXX_STANDARD 20
							CMAKE_CXX_STANDARD_REQUIRED ON
							CXX_EXTENSIONS OFF)				

ENDIF ()