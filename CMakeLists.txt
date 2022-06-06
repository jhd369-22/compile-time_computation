cmake_minimum_required(VERSION 3.23)

# set the project name
project(cpp_compile_time LANGUAGES CXX)

# set Debug build type
set(CMAKE_BUILD_TYPE Debug)

# set c++ standard 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Note: to use Clang compiler
# cmake -D CMAKE_CXX_COMPILER=clang++

# Set the variable EXTRA_COMPILE_FLAGS to the desired compile flags
# to add for the particular compiler being used (as explained above).
# For GCC:
# set(EXTRA_COMPILE_FLAGS "-fconstexpr-loop-limit=10000")
# For Clang:
set(EXTRA_COMPILE_FLAGS "-fconstexpr-steps=100000000")
# Add the desired flags to the compilation of the
# app/test_mandelbrot.cpp file.
set_source_files_properties(app/test_mandelbrot.cpp PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})

# find catch2
find_package(Catch2 REQUIRED)

# include the file containing the sanitizer option
include(Sanitizers.cmake)

# include directory
include_directories(include)

# add executable
add_executable(test_cexpr_basic_string app/test_cexpr_basic_string.cpp)

add_executable(test_mandelbrot app/test_mandelbrot.cpp)

add_executable(test_cexpr_math app/test_cexpr_math.cpp)
