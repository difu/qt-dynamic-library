#include <QEasingCurve>

#if defined MAKE_CURVE_LIB
 #define CURVE_LIB_EXPORT Q_DECL_EXPORT
#else
 #define CURVE_LIB_EXPORT Q_DECL_IMPORT
#endif

extern "C" CURVE_LIB_EXPORT qreal getCurve(qreal progress);