cmake_minimum_required(VERSION 3.14)

project(qt6ca-7-assign LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test REQUIRED)

add_executable(qt6ca-7-assign
  main.cpp
  widget.cpp
  widget.h
)
target_link_libraries(qt6ca-7-assign Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Test)
