import QtQuick 2.0

Item {
    property string title: "Details"
    property var appWindow: null

    Text {
        id: name
        text: qsTr("details")
    }

    Connections {
        target: appData
        function onDirAdded(dirInfo) {
            console.log("Details onDirAdded", dirInfo);
        }
    }
}
