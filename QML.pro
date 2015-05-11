TEMPLATE = app

QT += qml quick

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    TrafficLight.cpp \
    testclass.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
#include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
#qtcAddDeployment()

HEADERS += \
    TrafficLight.h \
    testclass.h

