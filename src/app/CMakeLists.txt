set(APP_SOURCES
    main.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/resource.cpp
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

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resource.cpp
    COMMAND ${wxWidgets_wxrc_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/resource.xrc
            -c
            -v
            -o ${CMAKE_CURRENT_BINARY_DIR}/resource.cpp
    COMMENT "Generate resource file."
)
