#include <QtGui/QGuiApplication>
#include <QtQuick>
#include <QQmlApplicationEngine>
//#include "qtquick2applicationviewer.h"
#include "TrafficLight.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
//    TrafficLight light;
//    qmlRegisterUncreatableType<TrafficLight>("HighwayDept",1,0,"TrafficLight","");
    qmlRegisterType<TrafficLight>("HighwayDept",1,0,"TrafficLight");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
//    QtQuick2ApplicationViewer viewer;
//    //viewer.engine()->rootContext()->setContextProperty("lightbackend",&light);
//    viewer.setMainQmlFile(QStringLiteral("qml/QML/main.qml"));
//    viewer.showExpanded();

    return app.exec();
}
