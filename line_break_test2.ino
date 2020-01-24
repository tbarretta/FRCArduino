/* 
  IR Breakbeam sensor demo!
*/

#define LEDPIN 13
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

#define FIRST_SENSORPIN 6
#define LAST_SENSORPIN 2

// variables will change:
int firstSensorState = 0, firstSensorStatePrev=0;         // variable for reading the pushbutton status
int lastSensorState = 0, lastSensorStatePrev=0;         // variable for reading the pushbutton status
unsigned long time;

void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(FIRST_SENSORPIN, INPUT);     
  digitalWrite(FIRST_SENSORPIN, HIGH); // turn on the pullup
  pinMode(LAST_SENSORPIN, INPUT);     
  digitalWrite(LAST_SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
}

void loop(){
  // read the state of the pin:
  firstSensorState = digitalRead(FIRST_SENSORPIN);
  lastSensorState = digitalRead(LAST_SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (firstSensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    // Not necessary if we don't want want to light the LED
    // digitalWrite(LEDPIN, LOW); 
  }

  if (lastSensorState == LOW) {     
    // turn LED on:
    // digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }

  if (firstSensorState && !firstSensorStatePrev) {
    Serial.println("First Unbroken @: ");
    time = millis();
    Serial.println(time); //prints time since program started
  } 
  if (!firstSensorState && firstSensorStatePrev) {
    Serial.println("First Broken @: ");
    time = millis();
    Serial.println(time); //prints time since program started
  }
  firstSensorStatePrev = firstSensorState;

  if (lastSensorState && !lastSensorStatePrev) {
    Serial.println("Last Unbroken @: ");
    time = millis();
    Serial.println(time); //prints time since program started
  } 
  if (!lastSensorState && lastSensorStatePrev) {
    Serial.println("Last Broken @: ");
    time = millis();
    Serial.println(time); //prints time since program started
  }
  lastSensorStatePrev = lastSensorState;

}
