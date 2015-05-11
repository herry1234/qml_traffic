import QtQuick 2.0

Item {
    width: 100; height: 100
    id: item
    property int someNumber: 120
    signal qmlSignal(string msg)
    Rectangle {
           anchors.fill: parent
           objectName: "rect"
           MouseArea {
               anchors.fill: parent
               onClicked: item.qmlSignal("emit signal")
           }
       }



    function myQmlFunction(msg) {
            console.log("Got message: ", msg)
            return "return value from qml function"
        }
}
