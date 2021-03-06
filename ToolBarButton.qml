import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

/**
  * \brief QML instance : VizPage
  * Basic information of toolbar button
  */
ToolButton {
    id: button
    property string buttonText : ""
    property bool selected: false

    Layout.preferredWidth: 150
    Layout.fillHeight: true

    z: 50

    background: Rectangle {
        id: backgroundRect
        anchors.fill: parent

        color: Qt.lighter("#112627", button.hovered || button.selected ? 2.0 : 1.0)
        border.color: "white"
    }

    Label {
        anchors.fill: parent

        text: buttonText
        font.pixelSize: 15
        color: "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
