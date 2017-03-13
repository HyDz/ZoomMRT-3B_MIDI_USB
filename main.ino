/*
 * ZoomMRT-3B_MIDI_USB
 *
 * Created: 13/3/2017 
 * Author: HyDz
 * USB Midified ZoomMRT-3B for Traktor
 * 
 */ 
 
#include "MIDIUSB.h"
#include <inputs.h>
#include <outputs.h>

void setup(){
Serial.begin(115200);

for (int i=2, i<=7, i++){pinMode(i, INPUT);} // Set Inputs

for (int i=22, i<=35, i++){pinMode(i, INPUT);} // Set Inputs

for (int i=36, i<=52, i++){pinMode(i, OUTPUT);} // Set Outputs

}

void loop(){
void getMidiIn();
void setMidiOut();
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void getMidiIn(){

}

void setMidiOut(){

}
