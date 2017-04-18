
#define MidiChannel  2 // channel 3 (channel 1 has value 0)
#include "MIDIUSB.h"
int CCval; // Constrained Midi Value
String ScrennedVal; // Stringed midi val for screen
String ScrennedCC; // Stringed midi CC for screen

void controlChange(byte channel, byte control, byte value) {
#if ENABLE_DEBUG
  Serial.print("CC: ");
  Serial.print(channel + 1);
  Serial.print("| ");
  Serial.print(control);
  Serial.print("| ");
  Serial.println(value);
#endif
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
  clearscreen();
  String ScrennedVal = String(value, DEC);
  String ScrennedCC = String(control, DEC);
  printscreen(0, 25, 1, "CC: 3 | ");
  printscreen(45, 25, 1, ScrennedCC);
  printscreen(55, 25, 1, " | ");
  printscreen(72, 25, 1, ScrennedVal);
  // return;
}
