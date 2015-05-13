#include "testclass.h"
#include <QtDebug>
testclass::testclass()
{

}

testclass::~testclass()
{

}

void testclass::cppSlot(const QString &msg) {
    qDebug() <<"called cpp slot with msg:" << msg;
}
void testclass::objready(QObject *rootobj, const QUrl& url ) {
    qDebug() <<"loaded url is:" << url;
    qDebug() <<"loaded rootobj is:" << rootobj;
}
