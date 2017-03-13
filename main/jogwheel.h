/*
 * ZoomMRT-3B_MIDI_USB
 * USB Midified ZoomMRT-3B for Traktor
 * 
 * Created: 13/3/2017 
 * Author: HyDz
 *
 * This section is based on Brenda A Bell work.
 * Permalink: http://www.brendaabell.com/2014/02/arduino-series-working-with-an-optical-encoder/
 * 
 * Declare Digitals Inputs
 */ 
 
#define ENCODER0PINA         JogWheelPinA      // this pin needs to support interrupts
#define ENCODER0PINB         JogWheelPinB      // no interrupt required
#define CPR                  400    // encoder cycles per revolution
#define CLOCKWISE            1       // direction constant
#define COUNTER_CLOCKWISE    2       // direction constant
 
// variables modified by interrupt handler must be declared as volatile
volatile long encoder0Position = 0;
volatile long interruptsReceived = 0;
 
// track direction: 0 = counter-clockwise; 1 = clockwise
short currentDirection = CLOCKWISE;
 
// track last position so we know whether it's worth printing new output
long previousPosition = 0;
 

void loop()
{
  // only display position info if has changed
  if (encoder0Position != previousPosition )
  {
    Serial.print(encoder0Position, DEC);
    Serial.print("\t");
    Serial.print(currentDirection == CLOCKWISE ? "clockwise" : "counter-clockwise");
    Serial.print("\t");
    Serial.println(interruptsReceived, DEC);
    previousPosition = encoder0Position;
  }
}
 
// interrupt function needs to do as little as possible
void onInterrupt()
{
  // read both inputs
  int a = digitalRead(ENCODER0PINA);
  int b = digitalRead(ENCODER0PINB);
 
  if (a == b )
  {
    // b is leading a (counter-clockwise)
    encoder0Position--;
    currentDirection = COUNTER_CLOCKWISE;
  }
  else
  {
    // a is leading b (clockwise)
    encoder0Position++;
    currentDirection = CLOCKWISE;
  }
 
  // track 0 to 1249
  encoder0Position = encoder0Position % CPR;
 
  // track the number of interrupts
  interruptsReceived++;
}
