#ifndef UTILS_H 
#define UTILS_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <TimeLib.h>
#include <UnixTime.h>

String utf8rus(String source);

String get_time(uint32_t unix);

void display2oled(String message);

#endif
