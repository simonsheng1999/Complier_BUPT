cmake_minimum_required(VERSION 3.16)
project(pascal_s)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pascal_s
        semantic.cpp
        compile.h
        yacc.tab.h
        lex.yy.cpp
        yacc.tab.cpp
        main.cpp
        generate_code.cpp)
