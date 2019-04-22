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

#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QQuickItem>
#include <QtSerialPort/QSerialPort>

class SerialPort : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    SerialPort(QQuickItem* parent = 0);

    ~SerialPort();

public slots:

    void setPortName(QString portName);

    void open();

    void write(int byte);

private:

    QSerialPort serialPort;

};

#endif /* SERIALPORT_H */
