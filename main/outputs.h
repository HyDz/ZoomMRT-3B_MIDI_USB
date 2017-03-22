/*
   ZoomMRT-3B_MIDI_USB
   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor
   Declare Digitals Outputs
*/

/***********************************************************************************************************************************
*                                                                                                                                  *
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


#define NUM_LEDS    17  // Number of LEDS

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

char* outputsNames[NUM_LEDS] = { "SongLed", "PatternLed", "KitLed", "MinusLed", "PlusLed", "TempoLed",  "PlayLed", "RecLed", "BankLed", "CrashLed", "CupLed", "RideLed", "FunctionLed", "KickLed", "SnareLed", "ClosedHatLed", "OpenHatLed" };
const byte outputPins[NUM_LEDS] = { 36, 37, 38, 39, 40, 41, 42, 35, 44, 45, 46, 47, 48, 49, 50, 51, 53}; //Declare Outputs Pins in the same order than names

void outputsinit() {

  for (int i = 0; i < NUM_LEDS; i++) {
    // #define outputsNames[i]  outputPins[i] // Declare Name and Pins
    pinMode(outputPins[i], OUTPUT); //Set Outputs
    digitalWrite(i, LOW);
    delay(100);
  }

  for (int i = NUM_LEDS; i >= 0; i--) {
    digitalWrite(outputPins[i], HIGH);
    delay(50);
  }

}
