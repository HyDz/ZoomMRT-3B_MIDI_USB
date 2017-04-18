/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor
   Declare Inputs
*/

/**************************************************************************************************
*                                                                                                 *
   Declare Screen
   This section is based on Adafruit work.
   Permalink: https://github.com/adafruit/Adafruit_SSD1306
*                                                                                                 *
***************************************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

String Slogan = "EnA-N";

void screeninit(void) {
  display.begin(SSD1306_SWITCHCAPVCC);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.display();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(50, 0);
  display.print("HyDz");
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("MRT-3B USB");
  display.display();
}

void clearscreen(void) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(50, 0);
  display.print(Slogan);
  display.display();
}

void printscreen(int x, int y, int textsize, String content) {
  display.setCursor(x, y);
  display.setTextSize(textsize);
  display.print(content);
  display.display();
}
