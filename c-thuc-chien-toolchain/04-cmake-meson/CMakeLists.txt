cmake_minimum_required(VERSION 3.16)
project(myapp C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)

# Thư viện util: header công khai ở include/ (PUBLIC), nguồn ở src/.
add_library(util src/util.c)
target_include_directories(util PUBLIC include)

# Chương trình app: link util → tự thừa hưởng include/ (PUBLIC) của util.
add_executable(app src/main.c)
target_link_libraries(app PRIVATE util)
