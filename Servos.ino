#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN1  = 9; // Arduino pin connected to first servo's pin
const int SERVO_PIN2 = 8; // Arduino pin connected to second servo's pin

// create servo objects to control the servos
Servo servo1;
Servo servo2;

// variables will change:
int angle = 0;          // the current angle of servo motors
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  servo1.attach(SERVO_PIN1);
  servo2.attach(SERVO_PIN2);
  servo1.write(angle);
  servo2.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motors
    if(angle >= 0)
      angle += 90;
    else
    if(angle == 180)
      angle == 0;

    // control servo motors arccoding to the angle
    servo1.write(angle);
    servo2.write(angle);
  }
}