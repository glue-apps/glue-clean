import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id: root
    property string title: "Home123"
    property var win: null

    signal stackPush()

    Text {
        id: name
        text: qsTr("text")
    }

    Button {
        text: "Ok"
        onClicked: {
//            root.stackPush();
            win.demo();
        }
    }

    DropArea {
        id: dropArea
        anchors.fill: parent
        keys: ["text/uri-list"]

        onEntered: {
//            console.log("onEntered", drag.text);
        }

        onDropped: {
            console.log("onDropped", drop.text);
        }
    }


}
