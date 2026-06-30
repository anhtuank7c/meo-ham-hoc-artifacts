cmake_minimum_required(VERSION 3.16)
project(todo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # sinh compile_commands.json cho clang-tidy
add_compile_options(-Wall -Wextra)

# Lõi tái dùng: module store. include/ là PUBLIC -> ai liên kết cũng thấy header.
add_library(todocore src/store.c)
target_include_directories(todocore PUBLIC include)

# Chương trình chính dùng lõi.
add_executable(todo src/main.c)
target_link_libraries(todo PRIVATE todocore)

# Kiểm thử: chạy bằng `ctest`.
enable_testing()
add_executable(test_store tests/test_store.c)
target_link_libraries(test_store PRIVATE todocore)
add_test(NAME store COMMAND test_store)
