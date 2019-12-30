This plugin is for sending data through serial usb port


After connecting to the usb, check the name of the port with dmesg.
Give the write permission to anyone by: sudo chmod 777 /dev/nameoftheport

In cellulo code create a serial port object and set port name:
SerialPort {
    id: serialPort
    Component.onCompleted: {
        serialPort.setPortName("/dev/nameoftheport")
        serialPort.open()
    }
}

