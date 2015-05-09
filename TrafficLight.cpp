#include "TrafficLight.h"

TrafficLight::TrafficLight(QObject *parent) :
    QObject(parent)
{
    timer.setInterval(1000);
    timer.start();
    connect(&timer,SIGNAL(timeout()), this, SLOT(advanceLight()));
}

void TrafficLight::setState(State state) {
    if(state != _currentState) {
        if(state == Slow) {
            timer.setInterval(500);
        } else {
            timer.setInterval(1000);
        }
        _currentState = state;
        emit stateChanged();
    }

}
void TrafficLight::walk() {

    timer.setInterval(3000);
    setState(Stop);
}

void TrafficLight::advanceLight() {
    if(_currentState == Stop) {
        setState(Go);
    } else if(_currentState == Slow) {
        setState(Stop);
    } else if(_currentState == Stop) {
        setState(Stop);
    } else {
        setState(Slow);
    }
}

TrafficLight::State TrafficLight::getState() const {
    return _currentState;
}
