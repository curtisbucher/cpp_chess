cmake_minimum_required(VERSION 3.10)
project(bucherchess)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### FOR BUILDING THE MAIN EXECUTABLE ###

# includes
include_directories(
  include
)

# find header & source
file(GLOB_RECURSE HEADER "src/*.h")
file(GLOB_RECURSE SOURCE "src/*.cpp")

add_executable(${PROJECT_NAME}
  ${SOURCE}
  ${HEADER}
)

source_group("Header include" FILES ${HEADER})
source_group("Source src"     FILES ${SOURCE})

# link libraries
#target_link_libraries(${PROJECT_NAME} ${SOME_LIB})

### FOR BUILDING TESTS (use with --target test) ###
set(TEST_NAME ${PROJECT_NAME}_test)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Define test files
file(GLOB_RECURSE TEST "test/*.cpp")

# remove main from source files
list(REMOVE_ITEM SOURCE ${CMAKE_SOURCE_DIR}/src/chess.cpp)

# Create an executable for the tests
add_executable(${TEST_NAME}
    ${SOURCE}
    ${HEADER}
    ${TEST}
)

# Link GoogleTest to the test executable
target_link_libraries(${TEST_NAME} gtest_main)

# Add tests
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

# Custom target to run tests
add_custom_target(run_tests
    COMMAND ${TEST_NAME}
    DEPENDS ${TEST_NAME}
    COMMENT "Running all tests"
)
