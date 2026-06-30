cmake_minimum_required(VERSION 3.16)
project(lab08 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -g)

add_library(util util.c)

add_executable(app main.c)
target_link_libraries(app PRIVATE util)

enable_testing()
add_executable(tests test_util.c)
target_link_libraries(tests PRIVATE util)
add_test(NAME util_tests COMMAND tests)
