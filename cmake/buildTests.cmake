IF (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	
	ENABLE_TESTING ()														# Enable the testing generation

	# EXAMPLE WITH A push_back SOURCE FILE:
	#ADD_EXECUTABLE (push_back "tests/push_back.cpp")						# Add the push_back.cpp as an executable to build
	#ADD_TEST (PUSH_BACK push_back)											# Add the test PUSH_BACK to run the push_back executable

	ENDIF ()