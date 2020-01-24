#include <Adafruit_NeoPixel.h>
 
#define PIN    D2
#define N_LEDS 150
#define START_FIRST_STEP 50 #define START_FIRST_STEP 50 

#define _SFS 40 // start of first step
#define _EFS 55 // end of first step
#define _SFP 80 // start of first platform step
#define _EFP 90 // end of first platform step
#define _SSP 200 // start of second platform step
#define _ESP 215 // end of second platform step
#define _SSS 265 // start of second step
#define _ESS 280 // end of second step  


 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  strip.setBrightness(15);
}
 
void loop() {
  full(strip.Color(43, 63, 63), strip.Color(6, 7, 7)); // Bright White and Dim White
//  full(strip.Color(175, 255, 255), strip.Color(22, 31, 31)); // Bright White and Dim White
//  chase(strip.Color(255, 255, 255)); // White
//  chase(strip.Color(255, 0, 0)); // Red
//  chase(strip.Color(0, 255, 0)); // Green
//  chase(strip.Color(0, 0, 255)); // Blue
}
 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}

static void full(uint32_t b, uint32_t d) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    if(( i>_SFS && i<_EFS ) ||
        ( i>_SFP && i<_EFP ) ||
        ( i>_SSP && i<_ESP ) ||
        ( i>_SSS && i<_ESS ) ) {
          strip.setPixelColor(i, b); // Draw new bright pixel
        } else {
          strip.setPixelColor(i, d); // Draw new dim pixel
        }

      strip.setPixelColor(i  , b); // Draw new pixel
      strip.show();
      delay(0);
  }
}
