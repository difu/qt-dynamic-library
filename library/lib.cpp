#include <QEasingCurve>
#include "lib.h"

qreal getCurve(qreal progress) {
    QEasingCurve easing(QEasingCurve::InOutQuad);
    return easing.valueForProgress(progress);
}