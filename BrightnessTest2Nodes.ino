// Use if you want to force the software SPI subsystem to be used for some reason (generally, you don't)
// #define FASTLED_FORCE_SOFTWARE_SPI
// Use if you want to force non-accelerated pin access (hint: you really don't, it breaks lots of things)
// #define FASTLED_FORCE_SOFTWARE_SPI
// #define FASTLED_FORCE_SOFTWARE_PINS
#include <FastLED.h>

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 
///////////////////////////////////////////////////////////////////////////////////////////

// How many leds are in the strip?
#define NUM_LEDS 150

// Data pin that led data will be written out over
#define DATA_PIN D4 

// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8

#define _SFS 40 // start of first step
#define _EFS 55 // end of first step
#define _SFP 80 // start of first platform step
#define _EFP 90 // end of first platform step
#define _SSP 200 // start of second platform step
#define _ESP 215 // end of second platform step
#define _SSS 265 // start of second step
#define _ESS 280 // end of second step  

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
    	delay(2000);
      FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
//      FastLED.setBrightness(200);
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed].red =  15;
      leds[whiteLed].green =  15;
      leds[whiteLed].blue =  15;

      whiteLed = whiteLed + 1;
      
      leds[whiteLed].red =  50;
      leds[whiteLed].green =  50;
      leds[whiteLed].blue =  50;
      
      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      //delay(100);
      delay(0);
  
      // Turn our current led back to black for the next loop around
      //leds[whiteLed] = CRGB::Black;
   }
}
