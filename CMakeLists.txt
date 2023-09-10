cmake_minimum_required(VERSION 3.10)
project(Compressor VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create a library target for your project
add_library(Compressor_lib ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})


option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    # Include FetchContent
    include(FetchContent)

    # Fetch GoogleTest
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.10.0  # adjust the version as needed
    )

    FetchContent_MakeAvailable(googletest)
    # Disable -Werror for GoogleTest
    target_compile_options(gtest PRIVATE -Wno-error)
    target_compile_options(gtest_main PRIVATE -Wno-error)
    enable_testing()
    add_subdirectory(tests)
endif()
