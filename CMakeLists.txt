cmake_minimum_required(VERSION 3.16)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(ToDoList
    src/main.cpp
    src/WIN/basewin.cpp
    src/WIN/mainwin.cpp
    include/WIN/basewin.h      # ← добавить
    include/WIN/mainwin.h      # ← добавить
    include/PAGE/basepage.h    # ← добавить
    include/PAGE/mainpage.h    # ← добавить
)

target_link_libraries(ToDoList PRIVATE Qt6::Widgets)

target_include_directories(ToDoList PRIVATE 
    ${CMAKE_SOURCE_DIR}/include/WIN
    ${CMAKE_SOURCE_DIR}/include/PAGE
)