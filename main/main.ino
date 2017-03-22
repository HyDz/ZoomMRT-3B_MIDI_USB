/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor

*/
#define MidiChannel  2 // channel 3 (channel 1 has value 0)
#include "MIDIUSB.h"

void controlChange(byte channel, byte control, byte value) {
  Serial.print("CC: ");
  Serial.print(channel);
  Serial.print("| ");
  Serial.print(control);
  Serial.print("| ");
  Serial.println(value);

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
  Serial.println("start setup");

  inputsinit(); // set inputs
  outputsinit(); // set outputs
  Serial.println("setup end");


}

void loop() {


  getMidiIn();
  setMidiOut();


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

void setMidiOut() {


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
  if (valSongSwitch != lastSongSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastSongSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valSongSwitch != SongSwitchState) {
      SongSwitchState = valSongSwitch;
      if (SongSwitchState == LOW) {
        Serial.print("CC 40 Song Switch: ");
        Serial.println(valSongSwitch);
        controlChange(MidiChannel, 40, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastSongSwitch = valSongSwitch;
      }
    }
  }
  valPatternSwitch = digitalRead(PatternSwitch); // Read Analog Input
  if (valPatternSwitch != lastPatternSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastPatternSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valPatternSwitch != PatternSwitchState) {
      PatternSwitchState = valPatternSwitch;
      if (PatternSwitchState == LOW) {
        controlChange(MidiChannel, 41, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastPatternSwitch = valPatternSwitch;
      }
    }
  }
  valKitSwitch = digitalRead(KitSwitch); // Read Analog Input
  if (valKitSwitch != lastKitSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastKitSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valKitSwitch != KitSwitchState) {
      KitSwitchState = valKitSwitch;
      if (KitSwitchState == LOW) {
        controlChange(MidiChannel, 42, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastKitSwitch = valKitSwitch;
      }
    }
  }
  valInsertSwitch = digitalRead(InsertSwitch); // Read Analog Input
  if (valInsertSwitch != lastInsertSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastInsertSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valInsertSwitch != InsertSwitchState) {
      InsertSwitchState = valInsertSwitch;
      if (InsertSwitchState == LOW) {
        controlChange(MidiChannel, 43, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastInsertSwitch = valInsertSwitch;
      }
    }
  }
  valDeleteSwitch = digitalRead(DeleteSwitch); // Read Analog Input
  if (valDeleteSwitch != lastDeleteSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDeleteSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valDeleteSwitch != DeleteSwitchState) {
      DeleteSwitchState = valDeleteSwitch;
      if (DeleteSwitchState == LOW) {
        controlChange(MidiChannel, 44, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastDeleteSwitch = valDeleteSwitch;
      }
    }
  }
  valMinusSwitch = digitalRead(MinusSwitch); // Read Analog Input
  if (valMinusSwitch != lastMinusSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastMinusSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valMinusSwitch != MinusSwitchState) {
      MinusSwitchState = valMinusSwitch;
      if (MinusSwitchState == LOW) {
        controlChange(MidiChannel, 45, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastMinusSwitch = valMinusSwitch;
      }
    }
  }
  valPlusSwitch = digitalRead(PlusSwitch); // Read Analog Input
  if (valPlusSwitch != lastPlusSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastPlusSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valPlusSwitch != PlusSwitchState) {
      PlusSwitchState = valPlusSwitch;
      if (PlusSwitchState == LOW) {
        controlChange(MidiChannel, 46, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastPlusSwitch = valPlusSwitch;
      }
    }
  }
  valTempoSwitch = digitalRead(TempoSwitch); // Read Analog Input
  if (valTempoSwitch != lastTempoSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastTempoSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valTempoSwitch != TempoSwitchState) {
      TempoSwitchState = valTempoSwitch;
      if (TempoSwitchState == LOW) {
        controlChange(MidiChannel, 47, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastTempoSwitch = valTempoSwitch;
      }
    }
  }
  valStopSwitch = digitalRead(StopSwitch); // Read Analog Input
  if (valStopSwitch != lastStopSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastStopSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valStopSwitch != StopSwitchState) {
      StopSwitchState = valStopSwitch;
      if (StopSwitchState == LOW) {
        controlChange(MidiChannel, 48, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastStopSwitch = valStopSwitch;
      }
    }
  }
  valPlaySwitch = digitalRead(PlaySwitch); // Read Analog Input
  if (valPlaySwitch != lastPlaySwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastPlaySwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valPlaySwitch != PlaySwitchState) {
      PlaySwitchState = valPlaySwitch;
      if (PlaySwitchState == LOW) {
        controlChange(MidiChannel, 49, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastPlaySwitch = valPlaySwitch;
      }
    }
  }
  valRecSwitch = digitalRead(RecSwitch); // Read Analog Input
  if (valRecSwitch != lastRecSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastRecSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valRecSwitch != RecSwitchState) {
      RecSwitchState = valRecSwitch;
      if (RecSwitchState == LOW) {
        controlChange(MidiChannel, 50, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastRecSwitch = valRecSwitch;
      }
    }
  }
  valBankPad = digitalRead(BankPad); // Read Analog Input
  if (valBankPad != lastBankPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastBankPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valBankPad != BankPadState) {
      BankPadState = valBankPad;
      if (BankPadState == LOW) {
        controlChange(MidiChannel, 51, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastBankPad = valBankPad;
      }
    }
  }
  valCrashPad = digitalRead(CrashPad); // Read Analog Input
  if (valCrashPad != lastCrashPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastCrashPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valCrashPad != CrashPadState) {
      CrashPadState = valCrashPad;
      if (CrashPadState == LOW) {
        Serial.println("SEND CRASH!!!!!!!!!!!!!!!!!!!!!");
        controlChange(MidiChannel, 52, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastCrashPad = valCrashPad;
      }
    }
  }
  valCupPad = digitalRead(CupPad); // Read Analog Input
  if (valCupPad != lastCupPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastCupPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valCupPad != CupPadState) {
      CupPadState = valCupPad;
      if (CupPadState == LOW) {
        controlChange(MidiChannel, 53, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastCupPad = valCupPad;
      }
    }
  }

  valRidePad = digitalRead(RidePad); // Read Analog Input Shift Function
  if (valRidePad != lastRidePad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastRidePadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valRidePad != RidePadState) {
      digitalWrite(RideLed, LOW);
      Serial.println("RIDE PUSHH!!!  ");
      Serial.println(valRidePad);
      RidePadState = valRidePad;

      while (valRidePad == 0) {
        valKickPad = digitalRead(KickPad);
        valSnarePad = digitalRead(SnarePad);
        valClosedHatPad = digitalRead(ClosedHatPad);
        valOpenHatPad = digitalRead(OpenHatPad);
        if (RidePadState == LOW && valKickPad == HIGH) {
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
        valRidePad = digitalRead(RidePad);
      }
    } else {
      digitalWrite(RideLed, HIGH);
    }
  }


  valFunctionPad = digitalRead(FunctionPad); // Read Analog Input
  if (valFunctionPad != lastFunctionPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastFunctionPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valFunctionPad != FunctionPadState) {
      FunctionPadState = valFunctionPad;
      if (FunctionPadState == LOW) {
        controlChange(MidiChannel, 55, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastFunctionPad = valFunctionPad;
      }
    }
  }
  valKickPad = digitalRead(KickPad); // Read Analog Input
  if (valKickPad != lastKickPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastKickPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valKickPad != KickPadState) {
      KickPadState = valKickPad;
      if (KickPadState == LOW) {
        controlChange(MidiChannel, 56, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastKickPad = valKickPad;
      }
    }
  }
  valSnarePad = digitalRead(SnarePad); // Read Analog Input
  if (valSnarePad != lastSnarePad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastSnarePadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valSnarePad != SnarePadState) {
      SnarePadState = valSnarePad;
      if (SnarePadState == LOW) {
        controlChange(MidiChannel, 57, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastSnarePad = valSnarePad;
      }
    }
  }
  valClosedHatPad = digitalRead(ClosedHatPad); // Read Analog Input
  if (valClosedHatPad != lastClosedHatPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastClosedHatPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valClosedHatPad != ClosedHatPadState) {
      ClosedHatPadState = valClosedHatPad;
      if (ClosedHatPadState == LOW) {
        controlChange(MidiChannel, 58, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastClosedHatPad = valClosedHatPad;
      }
    }
  }
  valOpenHatPad = digitalRead(OpenHatPad); // Read Analog Input
  if (valOpenHatPad != lastOpenHatPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastOpenHatPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valOpenHatPad != OpenHatPadState) {
      OpenHatPadState = valOpenHatPad;
      if (OpenHatPadState == LOW) {
        controlChange(MidiChannel, 59, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastOpenHatPad = valOpenHatPad;
      }
    }
  }


}
