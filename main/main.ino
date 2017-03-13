/*
 * ZoomMRT-3B_MIDI_USB
 *
 * Created: 13/3/2017 
 * Author: HyDz
 * USB Midified ZoomMRT-3B for Traktor
 * 
 */ 
 
#include "MIDIUSB.h"
#include "inputs.h"
#include "outputs.h"

const int MidiChannel = 2; // channel 3 (channel 1 has value 0)

//Pulse per quarter note. Each beat has 24 pulses.
//Tempo is based on software inner BPM.
int ppqn = 0;

void setup(){
Serial.begin(115200);

for (int i=2; i<=7; i++){pinMode(i, INPUT);} // Set Inputs

for (int i=22; i<=35; i++){pinMode(i, INPUT);} // Set Inputs

for (int i=36; i<=52; i++){pinMode(i, OUTPUT);} // Set Outputs
 
for (int i=36; i<=52; i++){digitalWrite(i, HIGH);delay(250);} // Toggle Leds ON
for (int i=36; i<=52; i++){digitalWrite(i, LOW);delay(250);} // Toggle Leds OFF
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

 midiEventPacket_t rx;
 rx = MidiUSB.read();
    
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 70) { // SongLed
      digitalWrite(SongLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 71) { // PatternLed
      digitalWrite(PatternLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 72) { // KitLed
      digitalWrite(KitLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 73) { // MinusLed
      digitalWrite(MinusLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 74) { // PlusLed
      digitalWrite(PlusLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 75) { // TempoLed
      digitalWrite(TempoLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 76) { // PlayLed
      digitalWrite(PlayLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }

 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 77) { // RecLed
      digitalWrite(RecLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 78) { // BankLed
      digitalWrite(BankLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 79) { // CrashLed
      digitalWrite(CrashLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 80) { // CupLed
      digitalWrite(CupLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 81) { // RideLed
      digitalWrite(RideLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 82) { // FunctionLed
      digitalWrite(FunctionLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 83) { // KickLed
      digitalWrite(KickLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 84) { // SnareLed
      digitalWrite(SnareLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 85) { // ClosedHatLed
      digitalWrite(ClosedHatLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }
 
 if((rx.header >> 4) == MidiChannel) { // channel 3 (channel 1 has value 0)
  if((rx.header & 0b1111) == 0b1011) { // control change
    if(rx.byte1 == 86) { // OpenHatLed
      digitalWrite(OpenHatLed, rx.byte2 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
     }
   }
 }


}

void setMidiOut(){

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
valRidePad = digitalRead(RidePad); // Read Analog Input
 if (lastRidePad != valRidePad){ // Only send Midi CC if changed is detected
  controlChange(MidiChannel, 54, valRidePad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastRidePad = valRidePad;
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
