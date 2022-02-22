cmake_minimum_required(VERSION 3.16.3)

project(equvator
  VERSION 0.0.1
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(lib)
add_subdirectory(tests)

