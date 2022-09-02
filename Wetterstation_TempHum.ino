#include <cactus_io_AM2302.h>

#define AM2302_PIN 2

AM2302 dht(AM2302_PIN);

int temp = 0;
int humid = 0;


void setup() {
  Serial.begin(9600);
  dht.begin();

  // All the LEDs
  pinMode(8, OUTPUT); //LED 1
  pinMode(9, OUTPUT); //LED 2
  pinMode(10, OUTPUT); //LED 4
  pinMode(11, OUTPUT); //LED 8
  pinMode(12, OUTPUT); //LED 16

  pinMode(3, OUTPUT); //Energy for the Sensor
  
}


void loop() {

  digitalWrite(3, HIGH);

  dht.readTemperature();
  dht.readHumidity();

  if (isnan(dht.humidity) || isnan(dht.temperature_C)) {
    Serial.println("AM2302 sensor read failure!");
    return;
  }

  temp = (int)dht.temperature_C;
  humid = (int)dht.humidity;


  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Hum: ");
  Serial.print(humid);
  Serial.println("%");
  Serial.println("");

  
  // Refreshs the status of each LED
  if (temp >= 16) {
    digitalWrite(12, HIGH);
    temp = temp - 16;
  } else {
    digitalWrite(12, LOW);
  }
  
  if (temp >= 8) {
    digitalWrite(11, HIGH);
    temp = temp - 8;
  } else {
    digitalWrite(11, LOW);
  }
  
  if (temp >= 4) {
    digitalWrite(10, HIGH);
    temp = temp - 4;
  } else {
    digitalWrite(10, LOW);
  }
  
  if (temp >= 2) {
    digitalWrite(9, HIGH);
    temp = temp - 2;
  } else {
    digitalWrite(9, LOW);
  }
  
  if (temp >= 1) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(60000); // Updates every 60 secs
  //delay(3000); // 3 secs

}
