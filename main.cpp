/*
 * Copyright (c) 2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Create a DigitalOutput object to toggle an LED whenever data is received.
DigitalOut led(LED1);

// Create a UnbufferedSerial object with a default baud rate.
UnbufferedSerial serial_port(USBTX, USBRX);

int main(void)
{
    // Set desired properties (9600-8-N-1).
    serial_port.baud(9600);
    serial_port.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );

    led=1;

    serial_port.write("*", 1);

    char c;

    while(true){
        if(serial_port.read(&c, 1)){
            led = !led;

            serial_port.write("#", 1);
        }
    }
}
