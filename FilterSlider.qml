import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

/**
  * \brief QML instance : FilterSlider
  * The slider corresponding to a given filter
  */
Slider {
    id: slider
    Layout.fillWidth: true
    Layout.preferredHeight: 50

    property int digits : 2

    handle: Rectangle {
        x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
        y: slider.topPadding + slider.availableHeight / 2 - height / 2
        implicitWidth: 15
        implicitHeight: 15
        radius: 0
        color: slider.pressed ? "#f0f0f0" : "#f6f6f6"
        border.color: "#bdbebf"
    }

    Label
    {
        width : parent.width
        text : slider.valueAt(slider.position).toFixed(digits)
        color: "yellow"
        anchors.top : handle.bottom
        anchors.left: slider.left
        Layout.fillHeight: true
        horizontalAlignment : Text.AlignHCenter
    }

}
