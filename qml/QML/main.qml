import QtQuick 2.0
import HighwayDept 1.0
Rectangle {
    width: 1024
    height: 800
    Row {
        spacing : 5
        Light {
            id: light1

        }
        Light {
            id: light2
        }
    }


    Connections {
        target: light1
        onStateChanged: {console.log("change")}
    }

}

