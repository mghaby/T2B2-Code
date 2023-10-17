/* 
  IR Breakbeam sensor demo!
*/
#include <FastLED.h>

#define LEDPIN_1 9
#define LEDPIN_2 7
#define NUM_LEDS_1 6
#define NUM_LEDS_2 4
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

#define SENSORPIN_1 4
#define SENSORPIN_2 2

// variables will change:
int sensorStatex = 0, lastStatex = 0;         // variable for reading the pushbutton status
int sensorStatey = 0, lastStatey = 0;
int count = 0;

CRGB leds_1[NUM_LEDS_1];
CRGB leds_2[NUM_LEDS_2];

void setup() {
  FastLED.addLeds<WS2812, LEDPIN_1, GRB>(leds_1, NUM_LEDS_1);
  FastLED.addLeds<WS2812, LEDPIN_2, GRB>(leds_2, NUM_LEDS_2);
  // initialize the LED pin as an output:    
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN_1, INPUT);     
  pinMode(SENSORPIN_2, INPUT);
  digitalWrite(SENSORPIN_1, HIGH); // turn on the pullup
  digitalWrite(SENSORPIN_2, HIGH);
  Serial.begin(9600);
}

void loop(){

  for (int i = 0; i < NUM_LEDS_1; i++){
     leds_1[i].setRGB(0, 255, 0); /* The higher the value 4 the less fade there is and vice versa */
     FastLED.show();
     delay(100); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */

     // read the state of the pushbutton value:
     sensorStatex = digitalRead(SENSORPIN_1);
     sensorStatey = digitalRead(SENSORPIN_2);

    // check if the sensor beam is broken
    // if it is, the sensorState is LOW:

    if (!sensorStatex && lastStatex) {
      count++;
      Serial.println(count);
    }


    if (!sensorStatey && lastStatey) {
      count--;
      Serial.println(count);
    }

    lastStatex =sensorStatex;
    lastStatey = sensorStatey;
  } 

    for (int i = 0; i < NUM_LEDS_2; i++){
     leds_2[i].setRGB(255,255,0); /* The higher the value 4 the less fade there is and vice versa */ 
     FastLED.show();
     delay(100); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */

     // read the state of the pushbutton value:
     sensorStatex = digitalRead(SENSORPIN_1);
     sensorStatey = digitalRead(SENSORPIN_2);

    // check if the sensor beam is broken
    // if it is, the sensorState is LOW:

    if (!sensorStatex && lastStatex) {
      count++;
      Serial.println(count);
    }


    if (!sensorStatey && lastStatey) {
      count--;
      Serial.println(count);
    }

    lastStatex =sensorStatex;
    lastStatey = sensorStatey;
  } 
  
  FastLED.clear();
  FastLED.show();
}
