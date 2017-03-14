/*
 * ZoomMRT-3B_MIDI_USB
 *
 * Created: 13/3/2017 
 * Author: HyDz
 * USB Midified ZoomMRT-3B for Traktor
 * Declare Inputs
 */

/**************************************************************************************************
*                                                                                                 *
*  Declare Pins for Rotary Encoder                                                                *
*  This section is based on Brenda A Bell work.                                                   *
*  Permalink: http://www.brendaabell.com/2014/02/arduino-series-working-with-an-optical-encoder/  *
*                                                                                                 *
***************************************************************************************************/

#define JogWheelPinA         8      // this pin needs to support interrupts
#define JogWheelPinB         9      // no interrupt required
#define CPR                  400    // encoder cycles per revolution
#define CLOCKWISE            1       // direction constant
#define COUNTER_CLOCKWISE    2       // direction constant
 
int JogWheelActive = 0;
const int JogWheelMaxval = 4000; // Increase to have a smoother effect
const int JogWheelToggle = 200; // To prevent intempestive move
// variables modified by interrupt handler must be declared as volatile
volatile long valJogWheel = 0;
volatile long mappedvalJogWheel = 0;
 // track direction: 0 = counter-clockwise; 1 = clockwise
short currentDirection = CLOCKWISE;


// Declare Digitals Inputs

#define SongSwitch  2

int valSongSwitch = 0;
int lastSongSwitch = 0;


#define PatternSwitch  3

int valPatternSwitch = 0;
int lastPatternSwitch = 0;


#define KitSwitch  4

int valKitSwitch = 0;
int lastKitSwitch = 0;


#define InsertSwitch  5

int valInsertSwitch =0;
int lastInsertSwitch = 0;


#define DeleteSwitch  6

int valDeleteSwitch = 0;
int lastDeleteSwitch = 0;


#define MinusSwitch  7

int valMinusSwitch = 0;
int lastMinusSwitch = 0;


#define PlusSwitch  22

int valPlusSwitch = 0;
int lastPlusSwitch = 0;


#define TempoSwitch  23

int valTempoSwitch = 0;
int lastTempoSwitch = 0;


#define StopSwitch  24

int valStopSwitch = 0;
int lastStopSwitch = 0;


#define PlaySwitch  25

int valPlaySwitch = 0;
int lastPlaySwitch = 0;


#define RecSwitch  26

int valRecSwitch = 0;
int lastRecSwitch = 0;


#define BankPad  27

int valBankPad = 0;
int lastBankPad = 0;


#define CrashPad  28

int valCrashPad = 0;
int lastCrashPad = 0;


#define CupPad  29

int valCupPad = 0;
int lastCupPad = 0;


#define RidePad  30

int valRidePad = 0;
int lastRidePad = 0;


#define FunctionPad  31

int valFunctionPad = 0;
int lastFunctionPad = 0;


#define KickPad  32

int valKickPad = 0;
int lastKickPad = 0;


#define SnarePad  33

int valSnarePad = 0;
int lastSnarePad = 0;


#define ClosedHatPad  34

int valClosedHatPad = 0;
int lastClosedHatPad = 0;


#define OpenHatPad  35

int valOpenHatPad = 0;
int lastOpenHatPad = 0;
