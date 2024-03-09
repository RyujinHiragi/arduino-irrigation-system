#include <Servo.h>
#include <TimeLib.h>

#define SENSOR_PIN A0
#define RELAY_PIN 12
#define SERVO_PIN 9

Servo myservo;
unsigned long lastMovedTime = 0;
const unsigned long interval = 4 * 30 * 24 * 60 * 60UL;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  int humidity = analogRead(SENSOR_PIN);
  float humidityPercentage = humidity * 100.0 / 1023;

  unsigned long currentTime = now();

  if (humidityPercentage < 60.0) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  if (currentTime - lastMovedTime >= interval) {
    moveServo();
    lastMovedTime = currentTime;
  }

  delay(1000);
}

void moveServo() {
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
}
