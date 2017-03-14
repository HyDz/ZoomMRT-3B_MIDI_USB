/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor

*/
#define MidiChannel  2 // channel 3 (channel 1 has value 0)
#include "MIDIUSB.h"

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}


#include "inputs.h"
#include "outputs.h"




//Pulse per quarter note. Each beat has 24 pulses.
//Tempo is based on software inner BPM.
// int ppqn = 0; //not yet implemented

void setup() {

  Serial.begin(115200);
  inputsinit(); // set inputs
  outputsinit(); // set outputs


}

void loop() {
  void getMidiIn();
  void SetMidiOut();
}



void getMidiIn() {

  midiEventPacket_t rx;
  rx = MidiUSB.read();

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 70) { // SongLed
        digitalWrite(SongLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 71) { // PatternLed
        digitalWrite(PatternLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 72) { // KitLed
        digitalWrite(KitLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 73) { // MinusLed
        digitalWrite(MinusLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 74) { // PlusLed
        digitalWrite(PlusLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 75) { // TempoLed
        digitalWrite(TempoLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 76) { // PlayLed
        digitalWrite(PlayLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 77) { // RecLed
        digitalWrite(RecLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 78) { // BankLed
        digitalWrite(BankLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 79) { // CrashLed
        digitalWrite(CrashLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 80) { // CupLed
        digitalWrite(CupLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 81) { // RideLed
        digitalWrite(RideLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 82) { // FunctionLed
        digitalWrite(FunctionLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 83) { // KickLed
        digitalWrite(KickLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 84) { // SnareLed
        digitalWrite(SnareLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 85) { // ClosedHatLed
        digitalWrite(ClosedHatLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }

  if ((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
    if ((rx.header & 0b1111) == 0b1011) { // control change
      if (rx.byte1 == 86) { // OpenHatLed
        digitalWrite(OpenHatLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
      }
    }
  }
}

void setMidiOut(){

  // read both inputs of Jog Wheel

  int a = digitalRead(JogWheelPinA);
  int b = digitalRead(JogWheelPinB);

  if (a == b ) { // b is leading a (counter-clockwise)
    valJogWheel--;
    currentDirection = COUNTER_CLOCKWISE;
  }
  else { // a is leading b (clockwise)
    valJogWheel++;
    currentDirection = CLOCKWISE;
  }

  valJogWheel = valJogWheel % CPR; // track 0 to 400
  if (valJogWheel >= JogWheelToggle) { //Prevent Intempestive Move or flickering
    controlChange(MidiChannel, 63, 127); // Send CC For JogWheel Activity
    mappedvalJogWheel = map(abs(valJogWheel), 0, JogWheelMaxval, 0, 127); //map Jog Wheel value from 0 to 127
    JogWheelActive = 1;
    if (currentDirection = CLOCKWISE) {
      controlChange(MidiChannel, 61, mappedvalJogWheel); // Send CC For JogWheel FORWARD Direction
    }
    if (currentDirection = COUNTER_CLOCKWISE) {
      controlChange(MidiChannel, 62, mappedvalJogWheel); // Send CC For JogWheel REWARD Direction
    }
    MidiUSB.flush(); // Be sure CC is Send
    valJogWheel = 0;
  }   
   
valSongSwitch = digitalRead(SongSwitch); // Read Analog Input
 if (lastSongSwitch != valSongSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 40, valSongSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastSongSwitch = valSongSwitch;
  }
valPatternSwitch = digitalRead(PatternSwitch); // Read Analog Input
 if (lastPatternSwitch != valPatternSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 41, valPatternSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastPatternSwitch = valPatternSwitch;
  }
valKitSwitch = digitalRead(KitSwitch); // Read Analog Input
 if (lastKitSwitch != valKitSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 42, valKitSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastKitSwitch = valKitSwitch;
  }
valInsertSwitch = digitalRead(InsertSwitch); // Read Analog Input
 if (lastInsertSwitch != valInsertSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 43, valInsertSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastInsertSwitch = valInsertSwitch;
  }
valDeleteSwitch = digitalRead(DeleteSwitch); // Read Analog Input
 if (lastDeleteSwitch != valDeleteSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 44, valDeleteSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastDeleteSwitch = valDeleteSwitch;
  }
valMinusSwitch = digitalRead(MinusSwitch); // Read Analog Input
 if (lastMinusSwitch != valMinusSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 45, valMinusSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastMinusSwitch = valMinusSwitch;
  }
valPlusSwitch = digitalRead(PlusSwitch); // Read Analog Input
 if (lastPlusSwitch != valPlusSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 46, valPlusSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastPlusSwitch = valPlusSwitch;
  }
valTempoSwitch = digitalRead(TempoSwitch); // Read Analog Input
 if (lastTempoSwitch != valTempoSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 47, valTempoSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastTempoSwitch = valTempoSwitch;
  }
valStopSwitch = digitalRead(StopSwitch); // Read Analog Input
 if (lastStopSwitch != valStopSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 48, valStopSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastStopSwitch = valStopSwitch;
  }
valPlaySwitch = digitalRead(PlaySwitch); // Read Analog Input
 if (lastPlaySwitch != valPlaySwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 49, valPlaySwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastPlaySwitch = valPlaySwitch;
  }
valRecSwitch = digitalRead(RecSwitch); // Read Analog Input
 if (lastRecSwitch != valRecSwitch){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 50, valRecSwitch); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastRecSwitch = valRecSwitch;
  }
valBankPad = digitalRead(BankPad); // Read Analog Input
 if (lastBankPad != valBankPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 51, valBankPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastBankPad = valBankPad;
  }
valCrashPad = digitalRead(CrashPad); // Read Analog Input
 if (lastCrashPad != valCrashPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 52, valCrashPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastCrashPad = valCrashPad;
  }
valCupPad = digitalRead(CupPad); // Read Analog Input
 if (lastCupPad != valCupPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 53, valCupPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastCupPad = valCupPad;
  }
 
  valRidePad = digitalRead(RidePad); // Read Analog Input Shift Function
  valKickPad = digitalRead(KickPad);
  valSnarePad = digitalRead(SnarePad);
  valClosedHatPad = digitalRead(ClosedHatPad);
  valOpenHatPad = digitalRead(OpenHatPad);

  if (valRidePad != lastRidePad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastRidePadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valRidePad != RidePadState) {
      RidePadState = valRidePad;
      if (RidePadState == LOW && valKickPad == LOW) {
        controlChange(MidiChannel, 64, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastRidePad = valRidePad;
      }
      if (RidePadState == LOW && valSnarePad == LOW) {
        controlChange(MidiChannel, 65, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastRidePad = valRidePad;
      }
      if (RidePadState == LOW && valClosedHatPad == LOW) {
        controlChange(MidiChannel, 66, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastRidePad = valRidePad;
      }
      if (RidePadState == LOW && valOpenHatPad == LOW) {
        controlChange(MidiChannel, 67, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastRidePad = valRidePad;
      }

    }
  }
valFunctionPad = digitalRead(FunctionPad); // Read Analog Input
 if (lastFunctionPad != valFunctionPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 55, valFunctionPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastFunctionPad = valFunctionPad;
  }
valKickPad = digitalRead(KickPad); // Read Analog Input
 if (lastKickPad != valKickPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 56, valKickPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastKickPad = valKickPad;
  }
valSnarePad = digitalRead(SnarePad); // Read Analog Input
 if (lastSnarePad != valSnarePad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 57, valSnarePad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastSnarePad = valSnarePad;
  }
valClosedHatPad = digitalRead(ClosedHatPad); // Read Analog Input
 if (lastClosedHatPad != valClosedHatPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 58, valClosedHatPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastClosedHatPad = valClosedHatPad;
  }
valOpenHatPad = digitalRead(OpenHatPad); // Read Analog Input
 if (lastOpenHatPad != valOpenHatPad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 59, valOpenHatPad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastOpenHatPad = valOpenHatPad;
  }

}
