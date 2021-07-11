/*

  What
  Skipping tests and expecting failue

  Why
  We live in the real word

  How
  QSKIP QEXPECT_FAIL

 */

#include <QTest>
#include "widget.h"

//Update .Pro file:  QT += testlib

QTEST_MAIN(Widget);
