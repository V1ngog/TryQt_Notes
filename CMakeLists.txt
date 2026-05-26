cmake_minimum_required(VERSION 3.16)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)


qt_add_executable(ToDoList
    src/main.cpp
)

target_link_libraries(ToDoList PRIVATE Qt6::Widgets Qt6::Multimedia)
target_include_directories(ToDoList PRIVATE include)