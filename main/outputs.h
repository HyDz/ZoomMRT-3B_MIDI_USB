/*
 * ZoomMRT-3B_MIDI_USB
 *
 * Created: 13/3/2017 
 * Author: HyDz
 * USB Midified ZoomMRT-3B for Traktor
 * Declare Digitals Outputs
 */ 

#define NUM_LEDS    17  // Number of LEDS

 int SongLed = 36;
 int PatternLed = 37;
 int KitLed = 38;
 int MinusLed = 39;
 int PlusLed = 40;
 int TempoLed = 41;
 int PlayLed = 42;
 int RecLed = 43;
 int BankLed = 44;
 int CrashLed = 45;
 int CupLed = 46;
 int RideLed = 47;
 int FunctionLed = 48;
 int KickLed = 49;
 int SnareLed = 50;
 int ClosedHatLed = 51;
 int OpenHatLed = 52;

char* outputsNames[NUM_LEDS] = { "SongLed", "PatternLed", "KitLed", "MinusLed", "PlusLed", "TempoLed",  "PlayLed", "RecLed", "BankLed", "CrashLed", "CupLed", "RideLed", "FunctionLed", "KickLed", "SnareLed", "ClosedHatLed", "OpenHatLed" }; 
const byte outputPins[NUM_LEDS] ={ 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52}; //Declare Outputs Pins in the same order than names

void outputsinit(){
 
 for (int i = 0; i < NUM_LEDS; i++) {
 #define outputsNames[i]  outputPins[i]; // Declare Name and Pins
 pinMode(outputPins[i], OUTPUT); //Set Outputs
 digitalWrite(i, HIGH);
 }
 
 for (int i = 0; i < NUM_LEDS; i++) {
 digitalWrite(i, LOW);
 }
 
}

