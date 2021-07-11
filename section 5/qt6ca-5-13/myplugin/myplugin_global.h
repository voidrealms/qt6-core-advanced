#ifndef MYPLUGIN_GLOBAL_H
#define MYPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYPLUGIN_LIBRARY)
#  define MYPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define MYPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // MYPLUGIN_GLOBAL_H
