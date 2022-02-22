add_executable(tests main.cpp)

target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

