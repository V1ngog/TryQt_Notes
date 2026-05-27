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
    src/PAGE/mainpage.cpp
    src/PAGE/notemanager.cpp
    src/PAGE/showpage.cpp
    src/PAGE/addpage.cpp
    include/PAGE/addpage.h
    include/WIN/basewin.h      
    include/WIN/mainwin.h      
    include/PAGE/basepage.h    
    include/PAGE/mainpage.h    
    include/PAGE/notemanager.h
    include/PAGE/showpage.h
)

target_link_libraries(ToDoList PRIVATE Qt6::Widgets)

target_include_directories(ToDoList PRIVATE 
    ${CMAKE_SOURCE_DIR}/include/WIN
    ${CMAKE_SOURCE_DIR}/include/PAGE
)