cmake_minimum_required(VERSION 3.16)
project(todo_integration C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)

# Lõi: Store + Storage (lưu/đọc tệp) — đây là hai "đơn vị" ta sẽ test GHÉP nhau.
add_library(todocore src/store.c)
target_include_directories(todocore PUBLIC include)

# Chương trình hoàn chỉnh (cho e2e test).
add_executable(todo src/main.c)
target_link_libraries(todo PRIVATE todocore)

enable_testing()

# (1) Integration test: Store + Storage qua một tệp thật (round-trip).
add_executable(test_roundtrip tests/test_roundtrip.c)
target_include_directories(test_roundtrip PRIVATE tests)
target_link_libraries(test_roundtrip PRIVATE todocore)
add_test(NAME roundtrip COMMAND test_roundtrip)

# (2) End-to-end test: chạy CLI thật, kiểm output (black-box).
add_test(NAME cli_e2e COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/tests/run_cli.sh $<TARGET_FILE:todo>)
