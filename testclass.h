#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <QObject>

class testclass: public QObject
{

    Q_OBJECT
public slots:
    void cppSlot(const QString &msg);
public:
    testclass();
    ~testclass();

};

#endif // TESTCLASS_H
