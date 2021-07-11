/*

  What
  Data driven tests

  Why
  We want to test data

  How
  QTEST_MAIN addColumn addRow QFETCH

 */

#include <QCoreApplication>
#include <QTest>
#include "widget.h"

//Replaces the main function
QTEST_MAIN(Widget);
