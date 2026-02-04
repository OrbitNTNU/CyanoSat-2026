#include "Radio_kode.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

void radio_PowerUp() {
    mySerial.begin(38400);
}

void radio_Setup() {
    mySerial.write("mode ax25-1k2\r\n");
    delay(100);
    mySerial.write("access csma\r\n");
    delay(100);
    mySerial.write("freq 145500000\r\n");
    delay(100);
    mySerial.write("port0 text\r\n");
    delay(100);
    mySerial.write("set\r\n");
}

void radio_ExitRF() {
    mySerial.write(3); //Ctrl+C
}

String radio_ReadLine() {
    String line = "";
    if (mySerial.available()) {
        line = mySerial.readStringUntil('\n'); // reads whole command as string
        line.trim(); // removes \r and starting and ending whitespaces
    }
    return line;
}

