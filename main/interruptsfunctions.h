/*
 * ZoomMRT-3B_MIDI_USB
 *
 * Created: 13/3/2017 
 * Author: HyDz
 * USB Midified ZoomMRT-3B for Traktor
 * Interrupts Functions
 * What is done when switchs, pads or jog wheel is active
 */

#define NUM_FUNCTIONS   20

char* functionNames[NUM_FUNCTIONS] = { "sendSong", "sendPattern", "sendKit", "sendInsert", "sendDelete", "sendMinus", "sendPlus", "sendTempo", "sendStop", "sendPlay", "sendRec", "sendBank", "sendCrash", "sendCup", "sendRide", "sendFunction", "sendKick", "sendSnare", "sendClosedHat", "sendOpenHat" }; 
const byte attachedPins[NUM_FUNCTIONS] ={ SongSwitch, PatternSwitch, KitSwitch, InsertSwitch, DeleteSwitch, MinusSwitch, PlusSwitch, TempoSwitch, StopSwitch, PlaySwitch, RecSwitch, BankPad, CrashPad, CupPad, RidePad, FunctionPad, KickPad, SnarePad, ClosedHatPad, OpenHatPad}; //Declare Inputs Pins in the same order than names
//String tempfunct;

void interruptsfunctions.begin(){
  attachInterrupt(JogWheelPinA, sendJogWheel, RISING); // interrupts on rising 
  for (int i = 0; i < NUM_BUTTONS; i++) {
  attachInterrupt(attachedPins[i], functionNames[i], LOW); // interrupts when btton is pressed
 // tempfunct = "void " + functionNames[i] + "(){" + 
  }
}



void sendJogWheel() { // read both inputs
  
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
}
 
void sendSong(){
 valSongSwitch = digitalRead(SongSwitch); // Read Analog Input
 if (valSongSwitch != lastSongSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 if ((millis() - lastSongSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
  if (valSongSwitch != SongSwitchState) {
      SongSwitchState = valSongSwitch;
       if (buttonState == LOW) {
        controlChange(MidiChannel, 40, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastSongSwitch = valSongSwitch;
      }
    }       
  }
 }

void sendPattern(){
valPatternSwitch = digitalRead(PatternSwitch); // Read Analog Input
 if (valPatternSwitch != lastPatternSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 if ((millis() - lastPatternSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
  if (valPatternSwitch != PatternSwitchState) {
      PatternSwitchState = valPatternSwitch;
       if (buttonState == LOW) {
        controlChange(MidiChannel, 41, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastPatternSwitch = valPatternSwitch;
      }
    }       
  }
}

void sendKit(){
valKitSwitch = digitalRead(KitSwitch); // Read Analog Input
 if (valKitSwitch != lastKitSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 if ((millis() - lastKitSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
  if (valKitSwitch != KitSwitchState) {
      KitSwitchState = valKitSwitch;
       if (buttonState == LOW) {
        controlChange(MidiChannel, 42, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastKitSwitch = valKitSwitch;
      }
    }       
  }
}
void sendInsert(){
valInsertSwitch = digitalRead(InsertSwitch); // Read Analog Input
 if (valInsertSwitch != lastInsertSwitch) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 if ((millis() - lastInsertSwitchDebounceTime) > debounceSwitchDelay) { // Only send Midi CC if switch is pressed
  if (valInsertSwitch != InsertSwitchState) {
      InsertSwitchState = valInsertSwitch;
       if (buttonState == LOW) {
        controlChange(MidiChannel, 43, 127); // Send CC
        MidiUSB.flush(); // Be sure CC is Send
        lastInsertSwitch = valInsertSwitch;
      }
    }       
  }
}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
void sendSong(){}
