#include <Servo.h>

int distance = 0;

Servo servo_3;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // will set the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // will read the echo pin, and return the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_3.attach(3, 500, 2500);

}

void loop()
{
  servo_3.write(0);
  distance = 0.01723 * readUltrasonicDistance(2, 2);
  if (distance <= 100) {
    servo_3.write(90);
    delay(1000); // will wait for 1000 millisecond(s)
    servo_3.write(0);
  }
  servo_3.write(0);
}