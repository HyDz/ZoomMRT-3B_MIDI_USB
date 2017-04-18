/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor

*/

#define ENABLE_DEBUG  0  // Set to 1 to enable serial debug out
#include "screen.h"
#include "minimidi.h"
#include "IOS.h"

void setup() {
#if ENABLE_DEBUG
  Serial.begin(115200);
  Serial.println("start setup");
#endif
  screeninit(); // set screen
  outputsinit(); // set outputs
  inputsinit(); // set inputs
#if ENABLE_DEBUG
  Serial.println("setup end");
#endif
  clearscreen();
}

void loop() {
  getMidiIn();
  readJogWheel();
  setMidiOut();
  readDataWheel();
}
