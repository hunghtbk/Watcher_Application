import QtQuick 2.5
import QtQuick.Window 2.2
import Time 1.0
Window {
    visible: true
    objectName: "applicationWindow"
    width: 480
    height: 480
    title: qsTr("Watch Application")


    Image {
        x: 0
        y: 0
        anchors.fill: parent
        source: "qrc:/Image/clock.png"
    }
    Image {
        x: 140
        y: 140
        width: 200
        height: 200
        source: "qrc:/Image/flower.png"
    }

    Minute {
        id: minute
        objectName: "minute"
        x: 0
        y: 0
        anchors.fill: parent
        property int minuterotate: 0
        property int minuteValue: 0
        onMinuteValueChanged: {
            minute.rotation += minuterotate
        }
    }
    Hour {
        id: hour
        objectName: "hour"
        x: 0
        y: 0
        anchors.fill: parent
        property int hourrotate: 0
        property int hourValue: 0
        onHourValueChanged: {
            hour.rotation += hourrotate
        }
    }
    Second {
        id: second
        objectName: "second"
        x: 0
        y: 0
        anchors.fill: parent
        property int secondrotate: 0
        property int secondValue: 0
        onSecondValueChanged: {
            second.rotation += secondrotate
        }
    }

}
