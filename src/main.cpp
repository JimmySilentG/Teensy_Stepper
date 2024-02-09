#include <Arduino.h>
#include <AccelStepper.h>

// put function declarations here:
int EnablePin = 2;
int DirPin = 3;
int PulPin = 4;

AccelStepper stepper(1, PulPin, DirPin);

void setup() {
  pinMode(EnablePin, OUTPUT);
  digitalWrite(EnablePin, LOW);
  stepper.setMaxSpeed(30); //6400 should be 8 revolutions per second which is max start speed for motor
  stepper.setAcceleration(10);
  stepper.moveTo(1450);
}

void loop() {
  stepper.run();
  if (abs(stepper.distanceToGo()) <= 10){
    stepper.moveTo(0);
   } 
}