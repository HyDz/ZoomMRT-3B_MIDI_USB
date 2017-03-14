/*
   ZoomMRT-3B_MIDI_USB

   Created: 13/3/2017
   Author: HyDz
   USB Midified ZoomMRT-3B for Traktor
   Declare Inputs
*/

/**************************************************************************************************
*                                                                                                 *
   Declare Pins for Rotary Encoder
   This section is based on Brenda A Bell work.
   Permalink: http://www.brendaabell.com/2014/02/arduino-series-working-with-an-optical-encoder/
*                                                                                                 *
***************************************************************************************************/

#define JogWheelPinA         8       // this pin needs to support interrupts
#define JogWheelPinB         9       // no interrupt required
#define CPR                  400     // encoder cycles per revolution
#define CLOCKWISE            1       // direction constant
#define COUNTER_CLOCKWISE    2       // direction constant
#define JogWheelMaxval       4000    // Increase to have a smoother effect
#define JogWheelToggle       200     // To prevent intempestive move decrease for more sensitive

#define debounceSwitchDelay  50      // the debounce time of switchs; to prevent flickers. Increase if the output flickers
#define debouncePadDelay     20      // the debounce time of pads; to prevent flickers. Increase if the output flickers
#define NUM_BUTTONS          20      // Number of digital inputs use switchs and pad only 

unsigned long lastDebounceTime = 0;

// variables modified by interrupt handler must be declared as volatile
volatile long valJogWheel = 0;
volatile long mappedvalJogWheel = 0;
// track direction: 0 = counter-clockwise; 1 = clockwise
short currentDirection = CLOCKWISE;
// track jogwheel activity 0 = inactive; 1 = active
int JogWheelActive = 0;

// Declare Digitals Inputs

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

int OpenHatPad = 35;
int valOpenHatPad = 0;
int lastOpenHatPad = 0;
unsigned long lastOpenHatPadDebounceTime = 0;
int OpenHatPadState = 0;



char* inputsNames[NUM_BUTTONS] = { "SongSwitch", "PatternSwitch", "KitSwitch", "InsertSwitch", "DeleteSwitch", "MinusSwitch", "PlusSwitch", "TempoSwitch", "StopSwitch", "PlaySwitch", "RecSwitch", "BankPad", "CrashPad", "CupPad", "RidePad", "FunctionPad", "KickPad", "SnarePad", "ClosedHatPad", "OpenHatPad" };
const byte inputPins[NUM_BUTTONS] = { 2, 3, 4, 5, 6, 7, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35}; //Declare Inputs Pins in the same order than names


void inputsinit() {

  pinMode(JogWheelPinA, INPUT); //DeclareJogWheel Pins
  pinMode(JogWheelPinB, INPUT);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(inputPins[i], INPUT_PULLUP); // Use Pull up internal resistor switch wired between ground and input
  }

}
