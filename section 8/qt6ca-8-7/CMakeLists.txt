cmake_minimum_required(VERSION 3.14)

project(qt6ca-8-7 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

#add_executable(qt6ca-8-7
#  main.cpp
#)

add_executable(qt6ca-8-7 MACOSX_BUNDLE
  main.cpp
)
set_target_properties(qt6ca-8-7 PROPERTIES
    BUNDLE True
    MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.qt6ca-8-7
    MACOSX_BUNDLE_BUNDLE_NAME qt6ca-8-7
    MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
    #MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/customtemplate.plist.in

)

target_link_libraries(qt6ca-8-7 Qt${QT_VERSION_MAJOR}::Core)


