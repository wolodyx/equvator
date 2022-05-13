cmake_minimum_required(VERSION 3.16.3)

project(equvator
  VERSION 0.0.1
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

find_package(OpenCV 4.5.5 REQUIRED)

enable_testing()

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

