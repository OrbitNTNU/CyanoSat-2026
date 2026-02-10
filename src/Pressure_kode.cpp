#include "Pressure_kode.h"
#include "Adafruit_MPRLS.h"
#include <Arduino.h>

#define RESET_PIN  -1  // set to any GPIO pin # to hard-reset on begin()
#define EOC_PIN    -1  // set to any GPIO pin to read end-of-conversion by pin
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

float Pressure::measurePressure() {
    float pressureData;
    if (! mpr.begin()) {
        pressureData = -1;
    } else {
        pressureData = mpr.readPressure();
    }
    return pressureData;
}