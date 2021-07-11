cmake_minimum_required(VERSION 3.14)

project(myapp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(myapp
  main.cpp
)
add_library(mylib SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(mylib PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libmylib.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/inc"
)
target_link_libraries(myapp mylib Qt${QT_VERSION_MAJOR}::Core)
