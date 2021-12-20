#include <Arduino.h>

#include "SPI.h"
#include "TFT_eSPI.h"
#ifndef SERIAL_BAUD
#define SERIAL_BAUD 115200
#endif

#include "frame.h"
#include "bsod.h"

#ifdef ESP32
#include "welcome.h"
#include "error2.h"
#endif

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  tft.init();
  tft.setRotation(TFT_ROTATION);
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);
}

void loop()
{
  for (int i = 0; i < 4; i++)
    for (int i = 0; i < 12; i++)
    {
      tft.pushImage(52, 56, 150, 151, frame[i]);
      delay(80);
    }

#ifdef ESP32
  tft.pushImage(0, 0, 240, 240, welcome);
  delay(5200);
  tft.fillScreen(TFT_BLACK);
  tft.pushImage(40, 50, 160, 102, error2);
  delay(4000);
#endif
  tft.pushImage(0, 0, 240, 240, bsod);
  delay(7000);

  tft.fillScreen(TFT_BLACK);
}
