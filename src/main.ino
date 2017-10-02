/////////////
// CONTENT //
/////////////
// 1. libraries
// 2. variables
// 3. initializes
// 4. setup function
// 5. loop function
// 6. callable functions

///////////////
// LIBRARIES //
///////////////
#include <Stepper.h>


///////////////
// VARIABLES //
///////////////
#define motorSteps 64

// Setup for motorpins
const int motor1 = 8;
const int motor2 = 9;
const int motor3 = 10;
const int motor4 = 11;

// other variables
// switch button
int switchPin = 2;
int switchState = 0;
// ledPin
int ledPin = 13;


////////////////
// INITIALIZE //
////////////////
// initialize Stepper library
Stepper stepper1(motorSteps, motor1, motor2);


///////////
// SETUP //
///////////
void setup() {
  // start Serial
  Serial.begin(9600);

  // let me know it's working by blinking led
  blink(4);

  // setting up switchPin
  pinMode(switchPin, INPUT);
}


//////////
// LOOP //
//////////
void loop() {
  switchState = digitalRead(switchPin);

  Serial.println("100 forward");
  stepper1.step(100);
  delay(100);

  Serial.println("100 backward");
  stepper1.step(-100);
  delay(100);
}


//////////////
// CALLABLE //
//////////////
void blink(int howManyTimes) {
  int i;
  for (i=0; i< howManyTimes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}
