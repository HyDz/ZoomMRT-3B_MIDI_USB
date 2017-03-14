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
#include "interruptsfunctions.h"



//Pulse per quarter note. Each beat has 24 pulses.
//Tempo is based on software inner BPM.
// int ppqn = 0; //not yet implemented

void setup() {

  Serial.begin(115200);
  inputsinit(); // set inputs
  outputsinit(); // set outputs
  interruptsfunctionsinit(); // set interrupts


}

void loop() {
  void getMidiIn();
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
