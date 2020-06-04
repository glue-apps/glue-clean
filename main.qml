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
                }
            }
            Label {
                text: stackView.currentItem.title
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
        HomeView {
            appWindow: window
        }
    }

    Component {
        id: detailsView
        DetailsView {
            appWindow: window
        }
    }

    Component.onCompleted: {
        appData.author = "Jonah"  // invokes Message::setAuthor()
    }

    Connections {
        target: appData
        function onAuthorChanged() {
            console.log("onAuthorChanged");
        }
    }

    function push(viewName) {
        var views = {
            "Home": homeView,
            "Details": detailsView
        }
        var viewId = views[viewName];
        if (viewId) {
            stackView.push(viewId);
        }
    }

    function scan(path) {

    }
}
