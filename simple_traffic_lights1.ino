/*
  Demo of a traffic light (3 leds) plus 1 button,

  The leds are light are connected to three pins:
    pin 2 -> Red
    pin 3 -> Yellow
    pin 4 -> Green
  green waits 2 seconds, yellow waits 1.5 seconds and red waits 3 seconds.
  The button is useles: one challenge is to change the light pattern
  to yellow on, yellow off when the button is pressed, and come back
  to the regular pattern when the button is pressed again -> it looks
  simple but it's not.
*/

#define LED_RED 2       // three consecutive digital outputs to connect Red,
#define LED_YELLOW 3    // Yellow and
#define LED_GREEN 4     // Green light
#define BUTT_IN  8      // the digital pin the button is connected to (unused)


// the setup function runs once when you press reset or power the board
void setup()
{                           // initialize input / output of the pins.
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUTT_IN, INPUT);
  digitalWrite(LED_RED, LOW);	// leds initially off
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

/*
// typical loop function for controling a simple traffic light circuit
void loop()
{
  digitalWrite(LED_GREEN, HIGH);	// show green
  delay(2000);						// wait for 2 secs.
  digitalWrite(LED_GREEN, LOW);

  digitalWrite(LED_YELLOW, HIGH);	// show yellow
  delay(1500);						// wait for 1.5 secs.
  digitalWrite(LED_YELLOW, LOW);

  digitalWrite(LED_RED, HIGH);		// show red
  delay(3000);						// wait for 3 secs.
  digitalWrite(LED_RED, LOW);
}
*/

// improved loop function for calling the update_lights() support function
void loop()
{
  update_lights(1);					// show red
  delay(3000);						// wait for 3 secs.

  update_lights(4);					// show green
  delay(2000);						// wait for 2 secs.

  update_lights(2);					// show yellow
  delay(1500);						// wait for 1.5 secs.
}


// update_lights(): support function for turning on or off the digital pins
// that control the traffic lights, assuming the pin numbering is sequential,
// starting with the red light pin (coded in the LED_RED symbol).
// Parameters:
//	bincode: a three-bit number to code the state of each light;
//		bit 0 -> red light
//		bit 1 -> yellow light
//		bit 2 -> green light
void update_lights(short bincode)
{
  short i;
  
  for (i = 0; i < 3; i++)             // assuming there are only three bits
  {
    if (bincode & (1 << i))           // check the status of the current bit
      digitalWrite(LED_RED + i, HIGH);  // update light status
    else
      digitalWrite(LED_RED + i, LOW);
  }
}