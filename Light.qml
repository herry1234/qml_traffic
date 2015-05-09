import QtQuick 2.0
import HighwayDept 1.0
Rectangle {
    width: 100
    height: 62
    TrafficLight {
        id: lightBackend
    }
    Connections {
        target: lightBackend
        onStateChanged: {console.log("change")}
    }

}

