import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id: root
    property string title: "Home"
    property var appWindow: null

    Text {
        id: name
        text: qsTr("home")
    }

    Button {
        text: "Push"
        y: 100
        onClicked: {
            console.log(appData.author);
            appWindow.push();
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
            appData.scan(drop.text)
        }
    }


}
