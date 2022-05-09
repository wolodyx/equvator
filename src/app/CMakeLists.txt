add_executable(app main.cpp)
include_directories(${wxWidgets_INCLUDE_DIRS})
link_libraries(${wxWidgets_LIBRARY_DIRS})
target_link_libraries(app ${wxWidgets_LIBRARIES})