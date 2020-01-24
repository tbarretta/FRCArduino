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
unsigned long firstStartTime;
unsigned long firstBreakTime;
unsigned long lastStartTime;
unsigned long lastBreakTime;
double deltaStartTime;
double deltaBreakTime;
double distance = 1.04167;
double startVelocity;
double breakVelocity;

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
    Serial.print("First Unbroken @: ");
    firstStartTime = millis();
    Serial.println(firstStartTime); //prints time since program started
  } 
  if (!firstSensorState && firstSensorStatePrev) {
    Serial.print("First Broken @: ");
    firstBreakTime = millis();
    Serial.println(firstBreakTime); //prints time since program started
  }
  firstSensorStatePrev = firstSensorState;

  if (lastSensorState && !lastSensorStatePrev) {
    Serial.print("Last Unbroken @: ");
    lastStartTime = millis();
    deltaStartTime = lastStartTime-firstStartTime;
    startVelocity = distance / deltaStartTime * 1000;
    Serial.println(lastStartTime); //prints time since program started
    Serial.print("Start Velocity: ");
    Serial.print((startVelocity));
    Serial.println(" ft/s");
  } 
  if (!lastSensorState && lastSensorStatePrev) {
    Serial.print("Last Broken @: ");
    lastBreakTime = millis();
    deltaBreakTime = lastBreakTime-firstBreakTime;
    breakVelocity = distance / deltaBreakTime * 1000;
    Serial.println(lastBreakTime); //prints time since program started
    Serial.print("Break Veloctiy: ");
    Serial.print((breakVelocity));
    Serial.println(" ft/s");
  }
  lastSensorStatePrev = lastSensorState;

}
