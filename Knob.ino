#include <Servo.h>

// constants won't change
const int BUTTON_PIN1 = 7; // Arduino pin connected to button's pin
const int BUTTON_PIN2 = 12;
const int BUTTON_PIN3 = 2;
const int SERVO_PIN1  = 9; // Arduino pin connected to first servo's pin
const int SERVO_PIN2 = 8; // Arduino pin connected to second servo's pin

// create servo objects to control the servos
Servo servo1;
Servo servo2;

// variables will change:
int angle = 0;          // the current angle of servo motors
int lastButtonState1;    // the previous state of button
int lastButtonState2;
int lastButtonState3;
int currentButtonState1; // the current state of button
int currentButtonState2;
int currentButtonState3;

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN1, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  servo1.attach(SERVO_PIN1);
  servo2.attach(SERVO_PIN2);
  servo1.write(angle);
  servo2.write(angle);
  currentButtonState1 = digitalRead(BUTTON_PIN1);
  currentButtonState2 = digitalRead(BUTTON_PIN2);
  currentButtonState3 = digitalRead(BUTTON_PIN3);
}

void loop() {
  lastButtonState1    = currentButtonState1;      // save the last state
  lastButtonState2    = currentButtonState2;
  lastButtonState3    = currentButtonState3;
  currentButtonState1 = digitalRead(BUTTON_PIN1);
  currentButtonState2 = digitalRead(BUTTON_PIN2);
  currentButtonState3 = digitalRead(BUTTON_PIN3);

  if(lastButtonState1 == HIGH && currentButtonState1 == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motors
    if(angle == 0)
      angle += 90;
    else
    if(angle == 90)
      angle = 0;

    // control servo motors arccoding to the angle
    servo1.write(angle);
    servo2.write(angle);
  }

    if(lastButtonState2 == HIGH && currentButtonState2 == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motors
    if(angle >= 0 && angle <= 90)
      angle += 180;
    else
    if(angle >= 170)
      angle = 0;

    // control servo motors arccoding to the angle
    servo1.write(angle);
    servo2.write(angle);
  }

    if(lastButtonState3 == HIGH && currentButtonState3 == LOW) {
    Serial.println("The button is pressed");

      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);    
  }
}
