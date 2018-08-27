IF (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)						# This is true only when someone is building the CirDeVec standalone

	SET (GBENCH "dependencies/benchmark")											# A simple shortcut for the path "extra/benchmark"

	SET (CMAKE_BUILD_TYPE RELEASE)											# Build type is RELEASE
	OPTION (BENCHMARK_ENABLE_TESTING OFF)									# Disable testing of the Google Benchmark library
	OPTION (BENCHMARK_ENABLE_LTO ON)										# Enable link time optimisation of the Google Benchmark library
	OPTION (BENCHMARK_DOWNLOAD_DEPENDENCIES ON)								# Allow the downloading and in-tree building of unmet dependencies for the Google Benchmark library
	OPTION (BENCHMARK_ENABLE_INSTALL OFF)									# Disable installation of the Google Benchmark library
	OPTION (BENCHMARK_ENABLE_GTEST_TESTS OFF)								# Disable building the unit tests (which depend on gtest) of the Google Benchmark library
	ADD_SUBDIRECTORY (${GBENCH})											# Adding the Google Benchmark library's CMakeLists.txt file
			
	ADD_EXECUTABLE (bench "tests/bench.cpp")								# Add the benchmark.cpp as an executable to build

	TARGET_INCLUDE_DIRECTORIES (bench PUBLIC ${GBENCH}/include)				# The include folder of the Google Benchmark library

	FIND_PACKAGE (Threads REQUIRED)											# Finding pthread, since it is REQUIRED
	TARGET_LINK_LIBRARIES (bench pthread)									# It is necessary to link with the pthread library due to how GCC implements std::thread
	TARGET_LINK_LIBRARIES (bench benchmark)									# Linking to the Google Benchmark static library
	
ENDIF ()