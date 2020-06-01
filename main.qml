import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Stack")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        RowLayout {
            anchors.fill: parent

            ToolButton {
                id: toolButton
                text: stackView.depth > 1 ? "\u25C0" : " "
                font.pixelSize: Qt.application.font.pixelSize * 1.6
                onClicked: {
                    if (stackView.depth > 1) {
                        stackView.pop()
                    }
                    else {
//                        drawer.open()
                        stackView.push("Home.qml")
                    }
                }
            }
            Label {
//                text: stackView.currentItem.title
                text: appData.author
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: {
                    console.log("hello")
                }
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: {
                    console.log("hello2")
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: homeView
        anchors.fill: parent
    }

    Component {
        id: homeView
        Home {
            win: window
        }
    }

    Component.onCompleted: {
        appData.author = "Jonah"  // invokes Message::setAuthor()
    }

    function demo() {
        console.log("in main.qml demo()");
    }
}
