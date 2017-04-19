/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor
   Declare Inputs
*/


/***********************************************************************************************************************************
*                                                                                                                                  *

     The JogWheel and Datawheel section are inspired off arduino rotary encoder examples
     Permalink: http://playground.arduino.cc/Main/RotaryEncoders


     The ZOOM MRT-B uses 0603 red LEDs a green one for the play switch. The reds have 1.6V forward voltage and the green one 1.8V
     I want to glow them at 10mA since they can draws 20mA and the Arduino DUE digital out 15mA.
     So I'll use 180ohms resistor in serie for Red LEDs and 150ohms for the Green one.

     Some digital pins of the Arduino Due are limited to 3mA (2, 13, 16, 17, 18, 20, 21, 22, 43, 52), so I'll avoid them.
     https://www.arduino.cc/en/Hacking/PinMappingSAM3X

     LEDs are wired in common-anode the plus potential is the same on all LEDs
     You have to put the cathode to low (GND) in order to glow LED.

     Cathode(-) "Arduino Out 1" ---|<--|  Anode(+) "Vcc"
                "Arduino Out 2" ---|<--| "Vcc"
*                                                                                                                                 *
***********************************************************************************************************************************/


#define DataWheelCLK            10    // Declare DataWheel Pins
#define DataWheelDT             11
#define DataWheelSW             12

#define JogWheelPinA            9     // Declare JogWheel Pins
#define JogWheelPinB            8     // no interrupt required

#define JogWheelDebounce        7    // time before new Touch On send. Decrease to more reactive
#define JogWheelToggle          20    // time before new Touch Off send. Decrease to more reactive
#define JogWheelMaxSpeed        12000   // Max Jogvalue give by getJogSpeed function, used to map to max midi value (127)

#define debounceSwitchDelay     70    // the debounce time of switchs; to prevent flickers. Increase if the output flickers
#define debouncePadDelay        7     // the debounce time of pads; to prevent flickers. Increase if the output flickers

#define NUM_BUTTONS             20    // Number of digital inputs use switchs and pad only 
#define NUMBER_OF_LEDS          17    // Number of LEDS

#define BPMcc                   90    // CC to listen in order to drive BPM counter, send beat phase to this CC
#define BPMoffset               47    // Offset to get accurate BPM calc, linked to the loop time execution

const float pival = 3.141593;         // Use to get beat frequency from beat pulsation with basic trigonometry w=2pi/T=2piF

volatile long int lastBPMtime = 0;
volatile double BPMpulse = 0;
volatile double BPMvalue = 0;
String ScrennedBPM; // Stringed midi val for screen
String ScrennedPulse; // Stringed midi CC for screen
String ScrennedBPMtime; // Stringed midi CC for screen


// Outputs

int SongLed = 36;
int PatternLed = 37;
int KitLed = 38;
int MinusLed = 39;
int PlusLed = 40;
int TempoLed = 41;
int PlayLed = 42;
int RecLed = 35;
int BankLed = 44;
int CrashLed = 45;
int CupLed = 46;
int RideLed = 47;
int FunctionLed = 48;
int KickLed = 49;
int SnareLed = 50;
int ClosedHatLed = 51;
int OpenHatLed = 53;

char* outputsNames[NUMBER_OF_LEDS] = { "SongLed", "PatternLed", "KitLed", "MinusLed", "PlusLed", "TempoLed",  "PlayLed", "RecLed", "BankLed", "CrashLed", "CupLed", "RideLed", "FunctionLed", "KickLed", "SnareLed", "ClosedHatLed", "OpenHatLed" };
const byte outputPins[NUMBER_OF_LEDS] = { 36, 37, 38, 39, 40, 41, 42, 35, 44, 45, 46, 47, 48, 49, 50, 51, 53}; //Declare Outputs Pins in the same order than names


//Inputs

unsigned long lastDebounceTime = 0;

int positionDataWheel = 0;
int rotationDataWheel = 0;
int valueDataWheel = 0;
int lastDataWheel = 0;
unsigned long lastDataWheelDebounceTime = 0;

int valDataWheelSwitch = 0;
int lastDataWheelSwitch = 0;
unsigned long lastDataWheelSwitchDebounceTime = 0;
int DataWheelSwitchState = 0;

int JogWheelDif = 0;
int JogWheelPos = 0;
int JogWheelLastPos = 0;
int JogWheelPinALast = LOW;
int nJogWheel = LOW;
int JogWheelLastTime = 0;
volatile double Jogpulse = 0;
volatile double Jogvalue = 0;
volatile long int lastJogtime = 0;
int mappedJogvalue = 0;
int JogWheelActive = 0;

int SongSwitch = 2;
int valSongSwitch = 0;
int lastSongSwitch = 0;
unsigned long lastSongSwitchDebounceTime = 0;
int SongSwitchState = 0;

int PatternSwitch = 3;
int valPatternSwitch = 0;
int lastPatternSwitch = 0;
unsigned long lastPatternSwitchDebounceTime = 0;
int PatternSwitchState = 0;

int KitSwitch = 4;
int valKitSwitch = 0;
int lastKitSwitch = 0;
unsigned long lastKitSwitchDebounceTime = 0;
int KitSwitchState = 0;

int InsertSwitch = 5;
int valInsertSwitch = 0;
int lastInsertSwitch = 0;
unsigned long lastInsertSwitchDebounceTime = 0;
int InsertSwitchState = 0;

int DeleteSwitch = 6;
int valDeleteSwitch = 0;
int lastDeleteSwitch = 0;
unsigned long lastDeleteSwitchDebounceTime = 0;
int DeleteSwitchState = 0;

int MinusSwitch = 7;
int valMinusSwitch = 0;
int lastMinusSwitch = 0;
unsigned long lastMinusSwitchDebounceTime = 0;
int MinusSwitchState = 0;

int PlusSwitch = 22;
int valPlusSwitch = 0;
int lastPlusSwitch = 0;
unsigned long lastPlusSwitchDebounceTime = 0;
int PlusSwitchState = 0;

int TempoSwitch = 23;
int valTempoSwitch = 0;
int lastTempoSwitch = 0;
unsigned long lastTempoSwitchDebounceTime = 0;
int TempoSwitchState = 0;

int StopSwitch = 24;
int valStopSwitch = 0;
int lastStopSwitch = 0;
unsigned long lastStopSwitchDebounceTime = 0;
int StopSwitchState = 0;

int PlaySwitch = 25;
int valPlaySwitch = 0;
int lastPlaySwitch = 0;
unsigned long lastPlaySwitchDebounceTime = 0;
int PlaySwitchState = 0;

int RecSwitch = 26;
int valRecSwitch = 0;
int lastRecSwitch = 0;
unsigned long lastRecSwitchDebounceTime = 0;
int RecSwitchState = 0;



int BankPad = 27;
int valBankPad = 0;
int lastBankPad = 0;
unsigned long lastBankPadDebounceTime = 0;
int BankPadState = 0;

int CrashPad = 28;
int valCrashPad = 0;
int lastCrashPad = 0;
unsigned long lastCrashPadDebounceTime = 0;
int CrashPadState = 0;

int CupPad = 29;
int valCupPad = 0;
int lastCupPad = 0;
unsigned long lastCupPadDebounceTime = 0;
int CupPadState = 0;

int RidePad = 30;
int valRidePad = 0;
int lastRidePad = 0;
unsigned long lastRidePadDebounceTime = 0;
int RidePadState = 0;

int FunctionPad = 31;
int valFunctionPad = 0;
int lastFunctionPad = 0;
unsigned long lastFunctionPadDebounceTime = 0;
int FunctionPadState = 0;

int KickPad = 32;
int valKickPad = 0;
int lastKickPad = 0;
unsigned long lastKickPadDebounceTime = 0;
int KickPadState = 0;

int SnarePad = 33;
int valSnarePad = 0;
int lastSnarePad = 0;
unsigned long lastSnarePadDebounceTime = 0;
int SnarePadState = 0;

int ClosedHatPad = 34;
int valClosedHatPad = 0;
int lastClosedHatPad = 0;
unsigned long lastClosedHatPadDebounceTime = 0;
int ClosedHatPadState = 0;

int OpenHatPad = 43;
int valOpenHatPad = 0;
int lastOpenHatPad = 0;
unsigned long lastOpenHatPadDebounceTime = 0;
int OpenHatPadState = 0;

char* inputsNames[NUM_BUTTONS] = { "SongSwitch", "PatternSwitch", "KitSwitch", "InsertSwitch", "DeleteSwitch", "MinusSwitch", "PlusSwitch", "TempoSwitch", "StopSwitch", "PlaySwitch", "RecSwitch", "BankPad", "CrashPad", "CupPad", "RidePad", "FunctionPad", "KickPad", "SnarePad", "ClosedHatPad", "OpenHatPad" };
const byte inputPins[NUM_BUTTONS] = { 2, 3, 4, 5, 6, 7, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 43}; //Declare Inputs Pins in the same order than names


void inputsinit() {

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(inputPins[i], INPUT_PULLUP); // Use Pull up internal resistor switch wired between ground and input
  }
  pinMode(DataWheelCLK, INPUT);
  pinMode(DataWheelDT, INPUT);
  pinMode(DataWheelSW, INPUT_PULLUP);
  pinMode(JogWheelPinA, INPUT_PULLUP);
  pinMode(JogWheelPinB, INPUT_PULLUP);
}
void outputsinit() {

  for (int i = 0; i < NUMBER_OF_LEDS; i++) {
    // #define outputsNames[i]  outputPins[i] // Declare Name and Pins
    pinMode(outputPins[i], OUTPUT); //Set Outputs
#if ENABLE_DEBUG
    Serial.print("OutPut On:  ");
    Serial.println(outputPins[i]);
#endif
    digitalWrite(i, LOW);
    delay(100);
  }
  for (int i = NUMBER_OF_LEDS - 1; i >= 0; i--) {
    digitalWrite(outputPins[i], HIGH);
#if ENABLE_DEBUG
    Serial.print("OutPut Off:  ");
    Serial.println(outputPins[i]);
#endif
    delay(50);
  }
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}



void readDataWheel(void) {

  valueDataWheel = digitalRead(DataWheelCLK);
  rotationDataWheel = digitalRead(DataWheelDT);
  if (valueDataWheel != lastDataWheel) { // we use the DT pin to find out which way we turning.
    if (valueDataWheel == LOW) {
      if (rotationDataWheel == LOW) {  // Clockwise
#if ENABLE_DEBUG
        Serial.print("CC 68 DataRight: ");
        Serial.print(valueDataWheel);
        Serial.print(" | ");
        Serial.println(rotationDataWheel);
#endif
        controlChange(MidiChannel, 68, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        return;
      }
      else { //Counterclockwise
#if ENABLE_DEBUG
        Serial.print("CC 69 DataLeft: ");
        Serial.print(valueDataWheel);
        Serial.print(" | ");
        Serial.println(rotationDataWheel);
#endif
        controlChange(MidiChannel, 69, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        return;
      }
    }
    lastDataWheel = valueDataWheel;
  }
}
void getJogSpeed() {

  Jogpulse = (millis() - lastJogtime); // Calc time since last click = period
  //  Jogpulse = Jogpulse + Jogoffset; // Offset due to execution of print screen
  Jogpulse = Jogpulse / 1000; // convert it in seconds
  Jogpulse = 1 / Jogpulse; // get Jog in Hz frequency f=1/t
  Jogvalue = Jogpulse * 60; // Jog=F*60
  mappedJogvalue = map(Jogvalue, 0, JogWheelMaxSpeed, 0, 127);
#if ENABLE_DEBUG
  Serial.print("mapped Speed: ");
  Serial.print(mappedJogvalue);
  Serial.print(" Pulse: ");
  Serial.print(Jogpulse);
  Serial.print(" Speed: ");
  Serial.println(Jogvalue);
#endif
  lastJogtime = millis();
}

void getBPM(byte ccvalin) {
  if (ccvalin == 127) { // Only when click max
    BPMpulse = (millis() - lastBPMtime); // Calc time since last click = period
    BPMpulse = BPMpulse + BPMoffset; // Offset due to execution of print screen
    BPMpulse = BPMpulse / 1000; // convert it in seconds
    BPMpulse = 1 / BPMpulse; // get bpm in Hz frequency f=1/t
    BPMvalue = BPMpulse * 60; // BPM=F*60
#if USE_SCREEN
    String ScrennedBPM = String(BPMvalue);
    String ScrennedPulse = String(BPMpulse);
    clearscreen();
    printscreen(0, 15, 1, "BPM: ");
    printscreen(25, 10, 2, ScrennedBPM);
#endif
    lastBPMtime = millis();
  } else {
    return;
  }
}
void getMidiIn() {
  midiEventPacket_t rx;
  do {
    // setMidiOut();
    rx = MidiUSB.read();
    if (rx.header != 0) {
      if (rx.byte1 == 178) { // channel 3
        if (rx.byte2 == 70) { // SongLed
          digitalWrite(SongLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 71) { // PatternLed
          digitalWrite(PatternLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 72) { // KitLed
          digitalWrite(KitLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 73) { // MinusLed
          digitalWrite(MinusLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 74) { // PlusLed
          digitalWrite(PlusLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 75) { // TempoLed
          digitalWrite(TempoLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 76) { // PlayLed
          digitalWrite(PlayLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 77) { // RecLed
          digitalWrite(RecLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 78) { // BankLed
          digitalWrite(BankLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 79) { // CrashLed
          digitalWrite(CrashLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 80) { // CupLed
          digitalWrite(CupLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 81) { // RideLed
          digitalWrite(RideLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 82) { // FunctionLed
          digitalWrite(FunctionLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 83) { // KickLed
          digitalWrite(KickLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 84) { // SnareLed
          digitalWrite(SnareLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 85) { // ClosedHatLed
          digitalWrite(ClosedHatLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == 86) { // OpenHatLed
          digitalWrite(OpenHatLed, rx.byte3 >> 6); // 0 >> 6 = 0 and 127 >> 6 = 1
        }
        if (rx.byte2 == BPMcc) { // BeatPhase listener for BPM calc
          getBPM(rx.byte3);
        }
      }
    }
  } while (rx.header != 0);
}

void setMidiOut() {

  valDataWheelSwitch = digitalRead(DataWheelSW);
  if (valDataWheelSwitch != lastDataWheelSwitch) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDataWheelSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valDataWheelSwitch != DataWheelSwitchState) {
      DataWheelSwitchState = valDataWheelSwitch;
      if (DataWheelSwitchState == LOW) {
        controlChange(MidiChannel, 39, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastDataWheelSwitch = valDataWheelSwitch;
      } else {
        controlChange(MidiChannel, 39, 0);
      }
    }
  }


  valSongSwitch = digitalRead(SongSwitch);
  if (valSongSwitch != lastSongSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastSongSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
    if (valSongSwitch != SongSwitchState) {
      SongSwitchState = valSongSwitch;
      if (SongSwitchState == LOW) {
        controlChange(MidiChannel, 40, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastSongSwitch = valSongSwitch;
      } else {
        controlChange(MidiChannel, 40, 0);
      }
    }
    lastSongSwitchDebounceTime = millis();
  }

  valPatternSwitch = digitalRead(PatternSwitch);
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
      } else {
        controlChange(MidiChannel, 41, 0);
      }
    }
    lastPatternSwitchDebounceTime = millis();
  }
  valKitSwitch = digitalRead(KitSwitch);
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
      } else {
        controlChange(MidiChannel, 42, 0);
      }
    }
    lastKitSwitchDebounceTime = millis();
  }
  valInsertSwitch = digitalRead(InsertSwitch);
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
      } else {
        controlChange(MidiChannel, 43, 0);
      }
    }
    lastInsertSwitchDebounceTime = millis();
  }
  valDeleteSwitch = digitalRead(DeleteSwitch);
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
      } else {
        controlChange(MidiChannel, 44, 0);
      }
    }
    lastDeleteSwitchDebounceTime = millis();
  }
  valMinusSwitch = digitalRead(MinusSwitch);
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
      } else {
        controlChange(MidiChannel, 45, 0);
      }
    }
    lastMinusSwitchDebounceTime = millis();
  }
  valPlusSwitch = digitalRead(PlusSwitch);
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
      } else {
        controlChange(MidiChannel, 46, 0);
      }
    }
    lastPlusSwitchDebounceTime = millis();
  }
  valTempoSwitch = digitalRead(TempoSwitch);
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
      } else {
        controlChange(MidiChannel, 47, 0);
      }
    }
    lastTempoSwitchDebounceTime = millis();
  }
  valStopSwitch = digitalRead(StopSwitch);
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
      } else {
        controlChange(MidiChannel, 48, 0);
      }
    }
    lastStopSwitchDebounceTime = millis();
  }
  valPlaySwitch = digitalRead(PlaySwitch);
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
      } else {
        controlChange(MidiChannel, 49, 0);
      }
    }
    lastPlaySwitchDebounceTime = millis();
  }
  valRecSwitch = digitalRead(RecSwitch);
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
      } else {
        controlChange(MidiChannel, 50, 0);
      }
    }
    lastRecSwitchDebounceTime = millis();
  }
  valBankPad = digitalRead(BankPad);
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
      } else {
        controlChange(MidiChannel, 51, 0);
      }
    }
    lastBankPadDebounceTime = millis();
  }
  valCrashPad = digitalRead(CrashPad);
  if (valCrashPad != lastCrashPad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastCrashPadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valCrashPad != CrashPadState) {
      CrashPadState = valCrashPad;
      if (CrashPadState == LOW) {
        controlChange(MidiChannel, 52, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastCrashPad = valCrashPad;
      } else {
        controlChange(MidiChannel, 52, 0);
      }
    }
    lastCrashPadDebounceTime = millis();
  }
  valCupPad = digitalRead(CupPad);
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
      } else {
        controlChange(MidiChannel, 53, 0);
      }
    }
    lastCupPadDebounceTime = millis();
  }

  valRidePad = digitalRead(RidePad);
  if (valRidePad != lastRidePad) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastRidePadDebounceTime) > debouncePadDelay) { // Only send Midi CC if switch is pressed
    if (valRidePad != RidePadState) {
      RidePadState = valRidePad;
      if (RidePadState == LOW) {
        controlChange(MidiChannel, 54, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastRidePad = valRidePad;
      } else {
        controlChange(MidiChannel, 54, 0);
      }
    }
    lastRidePadDebounceTime = millis();
  }


  valFunctionPad = digitalRead(FunctionPad);
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
      } else {
        controlChange(MidiChannel, 55, 0);
      }
    }
    lastFunctionPadDebounceTime = millis();
  }

  valKickPad = digitalRead(KickPad);
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
      } else {
        controlChange(MidiChannel, 56, 0);
      }
    }
    lastKickPadDebounceTime = millis();
  }
  valSnarePad = digitalRead(SnarePad);
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
      } else {
        controlChange(MidiChannel, 57, 0);
      }
    }
    lastSnarePadDebounceTime = millis();
  }
  valClosedHatPad = digitalRead(ClosedHatPad);
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
      } else {
        controlChange(MidiChannel, 58, 0);
      }
    }
    lastClosedHatPadDebounceTime = millis();
  }
  valOpenHatPad = digitalRead(OpenHatPad);
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
      } else {
        controlChange(MidiChannel, 59, 0);
      }
    }
    lastOpenHatPadDebounceTime = millis();
  }
}


void readJogWheel(void) {
  nJogWheel = digitalRead(JogWheelPinA);
  if ((JogWheelPinALast == LOW) && (nJogWheel == HIGH)) { // PinA Read Change
    JogWheelDif = millis() - JogWheelLastTime;
    if (JogWheelDif > JogWheelDebounce && JogWheelActive == 0) {
      JogWheelActive = 1;
#if ENABLE_DEBUG
      Serial.println("JogOn");
#endif
      JogWheelLastTime = millis();
      controlChange(MidiChannel, 63, 127); // Send CC
      MidiUSB.flush(); // Be sure CC is Send
    }
    if (digitalRead(JogWheelPinB) == LOW) {
      JogWheelPos--;
    } else {
      JogWheelPos++;
    }
    if (JogWheelPos > JogWheelLastPos) {         // ClockWise
      getJogSpeed();
#if ENABLE_DEBUG
      Serial.print("ClockWise: ");
      Serial.print(JogWheelPos);
      Serial.print(" / ");
      Serial.print(JogWheelDif);
      Serial.print(" / ");
      Serial.print(JogWheelLastTime);
      Serial.print(" / ");
      Serial.println(Jogvalue);
#endif
      controlChange(MidiChannel, 61, mappedJogvalue); // Send CC
      MidiUSB.flush(); // Be sure CC is Send
    }
    if (JogWheelPos < JogWheelLastPos) {           // CounterClockWise
      getJogSpeed();
#if ENABLE_DEBUG
      Serial.print("CounterClockWise: ");
      Serial.print(JogWheelPos);
      Serial.print(" / ");
      Serial.print(JogWheelDif);
      Serial.print(" / ");
      Serial.print(JogWheelLastTime);
      Serial.print(" / ");
      Serial.println(Jogvalue);
#endif
      controlChange(MidiChannel, 62, mappedJogvalue); // Send CC
      MidiUSB.flush(); // Be sure CC is Send
    }
    JogWheelLastTime = millis();
    JogWheelLastPos = JogWheelPos;                  // Update Wheel Position
  }
  JogWheelDif = millis() - JogWheelLastTime;
  if (JogWheelDif > JogWheelToggle && JogWheelActive == 1) {
#if ENABLE_DEBUG
    Serial.print(JogWheelLastTime);
    Serial.print(" / ");
    Serial.print(JogWheelDif);
    Serial.print(" / ");
    Serial.println("JogOff");
#endif
    JogWheelActive = 0;
    JogWheelLastTime = millis();
    controlChange(MidiChannel, 63, 0); // Send CC
    MidiUSB.flush(); // Be sure CC is Send
  }
  // JogWheelLastTime = millis();
  JogWheelPinALast = nJogWheel;                     // Update PinA Read
}


