/*

  What
  Use an external lib

  Why
  See how to use libs outside our normal project

  How
  Build the lib
  Modify the app Cmake
  Build the app
  :-1: error: library not found for -lmylib
  Correct the path

  copy the compiled lib and includes to the source dir
  Modyfy CMakeLists.txt

    add_library(mylib SHARED IMPORTED) # or STATIC instead of SHARED
    set_target_properties(mylib PROPERTIES
      IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libmylib.dylib"
      INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/inc"
    )
    target_link_libraries(myapp mylib Qt${QT_VERSION_MAJOR}::Core)

*/

#include <QCoreApplication>
#include "inc/mylib_global.h"
#include "inc/mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib lib;
    lib.test();

    return a.exec();
}
