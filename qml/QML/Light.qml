import QtQuick 2.0
import HighwayDept 1.0
Rectangle {
    width:300;height:400
    TrafficLight {
        id: lightbackend
    }
    Column {
        width: parent.width/3
        height: parent.height
        anchors.centerIn: parent
        spacing: 5
        Rectangle {
            id: red
            width: 100; height: 100
            color: "black"
            radius: width/2

        }

        Rectangle {
            id: yellow
            width: 100; height: 100
            color: "black"
            radius: width/2
        }

        Rectangle {
            id: green
            width: 100; height: 100
            color: "black"
            radius: width/2


        }
    }
    Rectangle {
        width: 100
        height: 75
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        color: "blue"
        Text {
            anchors.centerIn: parent
            text: "Walk"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: lightbackend.walk();
        }
    }

    states: [
        State {
            name : "Go"
            when : lightbackend.lightState === TrafficLight.Go
            PropertyChanges {
                target: green
                color: "green"

            }
        },
        State {
            name : "Slow"
            when : lightbackend.lightState === TrafficLight.Slow
            PropertyChanges {
                target: yellow
                color: "yellow"

            }
        },
        State {
            name : "Stop"
            when : lightbackend.lightState === TrafficLight.Stop
            PropertyChanges {
                target: red
                color: "red"

            }
        }


    ]

}

