/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor

*/

#define ENABLE_DEBUG  0  // Set to 1 to enable serial debug out
#define USE_SCREEN    0 // Set to 1 to use screen, set to 0 not use
#define BENCH_TIME    0 // Set to 1 to have loop time exec in serial monitor

#if BENCH_TIME || ENABLE_DEBUG     
int looptime = 0 ;
int looptick = 0;
#endif

#include "screen.h"
#include "minimidi.h"
#include "IOS.h"

void setup() {
#if BENCH_TIME || ENABLE_DEBUG
  Serial.begin(115200);
  Serial.println("start setup");
#endif
#if USE_SCREEN
  screeninit(); // set screen
#endif
  outputsinit(); // set outputs
  inputsinit(); // set inputs
#if ENABLE_DEBUG
  Serial.println("setup end");
#endif
#if USE_SCREEN
  clearscreen();
#endif
}

void loop() {
#if BENCH_TIME || ENABLE_DEBUG
  looptime = millis() - looptick;
  if (looptime >= 2) {
    Serial.print("L00P T!W3: ");
    Serial.println(looptime);
  }
  looptick = millis();
#endif
  getMidiIn();
  readJogWheel();
  setMidiOut();
  readDataWheel();
}
