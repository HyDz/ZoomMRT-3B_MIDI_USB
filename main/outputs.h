/*
 * ZoomMRT-3B_MIDI_USB
 *
 * Created: 13/3/2017 
 * Author: HyDz
 * USB Midified ZoomMRT-3B for Traktor
 * Declare Digitals Outputs
 */ 

#define NUM_LEDS    17  // Number of LEDS

char* outputsNames[NUM_LEDS] = { "SongLed", "PatternLed", "KitLed", "MinusLed", "PlusLed", "TempoLed",  "PlayLed", "RecLed", "BankLed", "CrashLed", "CupLed", "RideLed", "FunctionLed", "KickLed", "SnareLed", "ClosedHatLed", "OpenHatLed" }; 
const byte outputPins[NUM_LEDS] ={ 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52}; //Declare Outputs Pins in the same order than names

void inputs.begin(){
 
 for (int i = 0; i < NUM_LEDS; i++) {
 #define outputsNames[i]  outputPins[i]; // Declare Name and Pins
 pinMode(outputPins[i], OUTPUT); //Set Outputs
 digitalWrite(i, HIGH);
 }
 
 for (int i = 0; i < NUM_LEDS; i++) {
 digitalWrite(i, LOW);
 }
 
}

