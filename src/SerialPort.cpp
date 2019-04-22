/*
 * Copyright (C) 2016 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

#include "SerialPort.h"

#include <QDebug>

SerialPort::SerialPort(QQuickItem* parent) : QQuickItem(parent){

}

SerialPort::~SerialPort(){
    serialPort.flush();
    serialPort.close();
}

void SerialPort::setPortName(QString portName){
    serialPort.close();
    serialPort.setPortName(portName);
    serialPort.setFlowControl(QSerialPort::HardwareControl);
    serialPort.setBaudRate(QSerialPort::Baud115200);
}

void SerialPort::open(){
    if(!serialPort.open(QIODevice::ReadWrite))
        qCritical() << "ERROR! Could not open serial port.";
}

void SerialPort::write(int byte){
    if(byte < 0 || 255 < byte)
        qCritical() << "ERROR! Data is not a byte.";
    else{
        unsigned char c = (unsigned char) byte;
        serialPort.write((char*)&c, 1);
        if(!serialPort.waitForBytesWritten(1000))
            qCritical() << "ERROR! Could not write bytes.";
    }
}
