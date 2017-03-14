void sendJogWheel()
{
 // read both inputs
  int a = digitalRead(JogWheelPinA);
  int b = digitalRead(JogWheelPinB);
 
  if (a == b )
  {
    // b is leading a (counter-clockwise)
    valJogWheel--;
    currentDirection = COUNTER_CLOCKWISE;
  }
  else
  {
    // a is leading b (clockwise)
    valJogWheel++;
    currentDirection = CLOCKWISE;
  }
 
  // track 0 to 400
  valJogWheel = valJogWheel % CPR;
 if (valJogWheel >= JogWheelToggle) { //Prevent Intempestive Move
  controlChange(MidiChannel, 63, 127); // Send CC For JogWheel Activity
  mappedvalJogWheel = map(abs(valJogWheel), 0, JogWheelMaxval, 0, 127); //map Jog Wheel value from 0 to 127
  JogWheelActive = 1;  
    if (currentDirection = CLOCKWISE) {
     controlChange(MidiChannel, 61, mappedvalJogWheel); // Send CC For JogWheel Direction
      }
    if (currentDirection = COUNTER_CLOCKWISE) {
     controlChange(MidiChannel, 62, mappedvalJogWheel); // Send CC For JogWheel Direction
      }
  MidiUSB.flush(); // Be sure CC is Send
  valJogWheel = 0;
  }
}
