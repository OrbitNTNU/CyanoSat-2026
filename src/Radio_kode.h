#pragma once
#include <Arduino.h>

struct Radio {
    void PowerUp();
    void Setup();
    void ExitRF();
    String ReadLine();
};