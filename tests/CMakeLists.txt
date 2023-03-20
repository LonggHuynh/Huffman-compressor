# Create a test executable
file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(test_${PROJECT_NAME} ${TEST_SOURCES})

# Link with Google Test and the main project library
target_link_libraries(test_${PROJECT_NAME} gtest gtest_main Compressor_lib)

# Add the tests to CTest
add_test(NAME ${PROJECT_NAME}_tests COMMAND test_${PROJECT_NAME})
