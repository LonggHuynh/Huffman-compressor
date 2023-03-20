cmake_minimum_required(VERSION 3.10)
project(Compressor VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Google Test as a dependency
add_subdirectory(googletest)
enable_testing()

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create a library target for your project
add_library(Compressor_lib ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})


# Test target
add_subdirectory(tests)
