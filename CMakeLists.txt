cmake_minimum_required(VERSION 3.16.3)

project(equvator
  VERSION 0.0.1
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

enable_testing()

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

