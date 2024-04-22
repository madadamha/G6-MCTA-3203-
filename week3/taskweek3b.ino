#include <Servo.h>

Servo servo;
int servoPin = 9;
int angle;
int potPin = A0; // Analog pin for potentiometer
int potValue;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    angle = Serial.read();
    servo.write(angle);
    delay(15);
  }
  
  potValue = analogRead(potPin);
  angle = map(potValue, 0, 1023, 0, 180); // Map potentiometer value to servo angle
  servo.write(angle);
  
  if (Serial.available() > 0) {
    char key = Serial.read();
    if (key == 'q') {
      while (Serial.available() > 0) Serial.read(); // Clear serial buffer
      servo.write(90); // Stop the servo at 90 degrees
    }
  }
}
 
