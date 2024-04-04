#include <QApplication>
#include <QLibrary>
#include <QEasingCurve>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLibrary library("./library/liblib.so");
    if (!library.load())
        qDebug() << library.errorString();
    if (library.load())
        qDebug() << "library loaded";

    typedef qreal (*ReturnEaseCurveValueFunction)(qreal);
    ReturnEaseCurveValueFunction revf = (ReturnEaseCurveValueFunction)library.resolve("getCurve");
    QEasingCurve easing(QEasingCurve::InOutQuad);
    if(revf) {
        qDebug() << "getCurve loaded!";
        for(qreal inputVal=0.0; inputVal<=1.0; inputVal+=0.2) {
            qreal valFromLib = revf(inputVal);
            qDebug() << "Returned val from library for " << inputVal << ": " << valFromLib;
            qDebug() << "Returned val from local   for " << inputVal << ": " << easing.valueForProgress(inputVal);
        }
        
    } else {
        qDebug() << "Cannot access function!";
    }
    return 0;
    return app.exec();
}
