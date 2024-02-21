#define SENSOR_PIN A0 
#define RELAY_PIN 12  

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  int humidity = analogRead(SENSOR_PIN); 
  float humidityPercentage = humidity * 100.0 / 1023; 
  
  if (humidityPercentage < 60.0) { 
    digitalWrite(RELAY_PIN, HIGH); 
  } else {
    digitalWrite(RELAY_PIN, LOW); 
  }

  delay(1000); 

  
}