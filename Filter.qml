import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Frame {
    property string filterName: ""
    property alias filterLayout: layout

    Layout.preferredWidth: 200
    Layout.fillHeight: true

    padding: 2

    background: Rectangle {
        color: "black"
        border.color: "black"
    }

    ColumnLayout {
        id: layout

        Label {
            Layout.fillWidth: true
            Layout.preferredHeight: 10

            text: filterName
            color: "yellow"
            font.pixelSize: 15
            font.underline: true
        }
    }
}
