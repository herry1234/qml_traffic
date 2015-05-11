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
