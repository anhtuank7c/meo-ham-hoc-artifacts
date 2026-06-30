cmake_minimum_required(VERSION 3.16)
project(stack_unit_tests C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)

# Module duoc kiem thu (unit under test).
add_library(stack src/stack.c)
target_include_directories(stack PUBLIC include)

enable_testing()

# Test chay duoi sanitizer cho chac (bat ASan/UBSan khi cau hinh -DSAN=ON).
option(SAN "Bat AddressSanitizer + UBSan cho test" OFF)
if(SAN)
    add_compile_options(-fsanitize=address,undefined -g)
    add_link_options(-fsanitize=address,undefined)
endif()

add_executable(test_stack tests/test_stack.c)
target_include_directories(test_stack PRIVATE tests)
target_link_libraries(test_stack PRIVATE stack)
add_test(NAME stack_unit COMMAND test_stack)
