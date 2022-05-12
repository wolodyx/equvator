set(APP_SOURCES
    main.cpp
    DataProvider.h       DataProvider.cpp
    VideoCanvas.h        VideoCanvas.cpp
)

include_directories(
    ${wxWidgets_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

link_libraries(${wxWidgets_LIBRARY_DIRS})

add_executable(app ${APP_SOURCES})

target_link_libraries(app
    ${wxWidgets_LIBRARIES}
    ${OpenCV_LIBS}
)
