cmake_minimum_required(VERSION 3.16)
project(ToDoList)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# Находим Qt6 (компонент Widgets для окон)
find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

# Создаём исполняемый файл
# ВНИМАНИЕ: перечисли здесь ВСЕ твои .cpp файлы
qt_add_executable(ToDoList
    main.cpp
    # добавь сюда другие твои .cpp файлы, если есть
)

# Подключаем Qt библиотеки
target_link_libraries(ToDoList PRIVATE Qt6::Widgets Qt6::Multimedia)