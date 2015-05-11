#include <QtGui/QGuiApplication>
#include <QtQuick>
#include <QQmlApplicationEngine>
//#include "qtquick2applicationviewer.h"
#include "TrafficLight.h"
#include "testclass.h"
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


    // Using QQuickView
    QQuickView view;
    view.setSource(QStringLiteral("qrc:/testitem.qml"));
    view.show();
    QObject *object = view.rootObject();
    QObject *rect = object->findChild<QObject*>("rect");
    //read write Property from QML object
    if (rect)
        rect->setProperty("color", "red");
    qDebug() << "Property value:" << QQmlProperty::read(object, "someNumber").toInt();
    //call qml Method
    QVariant returnedValue;
    QVariant msg = "Hello from C++";
    QMetaObject::invokeMethod(object, "myQmlFunction",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));
    qDebug() << "QML function returned:" << returnedValue.toString();
    //wire signal
    testclass tc;
    QObject::connect(object,SIGNAL(qmlSignal(QString)),&tc,SLOT(cppSlot(QString)));

    return app.exec();

    //http://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html
}
