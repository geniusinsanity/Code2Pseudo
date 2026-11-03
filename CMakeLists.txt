
cmake_minimum_required(VERSION 3.20)

project(Code2Pseudo
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(code2pseudo
    compiler/app/main.cpp
    compiler/core/source/sourceFile.cpp
    compiler/input/cpp/lexer/lexer.cpp
    )

target_include_directories(code2pseudo PRIVATE compiler)

target_compile_options(code2pseudo
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)
