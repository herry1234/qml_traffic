#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QObject>
#include <QTimer>
class TrafficLight : public QObject
{
    Q_OBJECT
    Q_ENUMS(State)
    Q_PROPERTY(State lightState READ getState WRITE setState NOTIFY stateChanged)
public:
    enum State { Stop=0, Slow, Go};
    explicit TrafficLight(QObject *parent = 0);
    void setState(State newState);
    State getState() const;
    Q_INVOKABLE void walk();

signals:
    void stateChanged();
public slots:
private slots:
    void advanceLight();
private:
    State _currentState;
    QTimer  timer;

};

#endif // TRAFFICLIGHT_H
