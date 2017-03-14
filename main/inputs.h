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


// variables modified by interrupt handler must be declared as volatile
volatile long valJogWheel = 0;
volatile long mappedvalJogWheel = 0;
 // track direction: 0 = counter-clockwise; 1 = clockwise
short currentDirection = CLOCKWISE;
// track jogwheel activity 0 = inactive; 1 = active
int JogWheelActive = 0;

// Declare Digitals Inputs

char* inputsNames[NUM_BUTTONS] = { "SongSwitch", "PatternSwitch", "KitSwitch", "InsertSwitch", "DeleteSwitch", "MinusSwitch", "PlusSwitch", "TempoSwitch", "StopSwitch", "PlaySwitch", "RecSwitch", "BankPad", "CrashPad", "CupPad", "RidePad", "FunctionPad", "KickPad", "SnarePad", "ClosedHatPad", "OpenHatPad" }; 
const byte inputPins[NUM_BUTTONS] ={ 2, 3, 4, 5, 6, 7, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35}; //Declare Inputs Pins in the same order than names
String tempval, templast, tempdebounce, tempstate;

void inputs.begin(){
 
  pinMode(JogWheelPinA, INPUT); //DeclareJogWheel Pins
  pinMode(JogWheelPinB, INPUT);
 
 for (int i = 0; i < NUM_BUTTONS; i++) {
 #define inputsNames[i]  inputPins[i]; // Declare Names and Pins
 
 pinMode(inputPins[i], INPUT_PULLUP); // Use Pull up internal resistor switch wired between ground and input
 tempval = "val" + inputPins[i];
 templast = "last" + inputPins[i];
 tempdebounce = "last" + inputPins[i]; + "DebounceTime";
 tempstate = inputPins[i]; + "State";
 
 int tempval = 0; // Read Value
 int templast = 0; // Last Read Value
 unsigned long tempdebounce = 0;  // the last time the output pin was toggled
 int tempstate; // Switch or Pad State
 }

}
