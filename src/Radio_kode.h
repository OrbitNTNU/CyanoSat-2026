#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

void radioPowerUp();
void radio_Setup();
void radio_ExitRF();
String radio_ReadLine();