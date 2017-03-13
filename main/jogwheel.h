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
volatile long valJogWheel = 0;
 
// track direction: 0 = counter-clockwise; 1 = clockwise
short currentDirection = CLOCKWISE;
 
// track last position so we know whether it's worth printing new output
long lastJogWheel = 0;

