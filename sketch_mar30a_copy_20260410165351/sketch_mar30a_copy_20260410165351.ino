#include <Arduino.h>
#include <DHT11.h>
#include <SoftwareSerial.h>
#include "DS3231.h"
DS3231 clock;
RTCDateTime dt;
DHT11 dht11(2);
int sensorf1Pin = A0;
int sensorf1Value = 0;
int sensorf2Pin = A2;
int sensorf2Value = 0;
int wdpin = A1;
int wdValue = 0;
int buzzerPin
char weekDay[][4] = {"Mon","Tue","Wed","Thu","Fri",};

void setup() {
 Serial.begin(9600);
 Serial.println("1и");
 Serial.println("2");
}

void loop() {
  int temperature = 0;
  int humidity = 0;
  int result = dht11.readTemperatureHumidity(temperature, humidity);
  if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
sensorf1Value = analogRead(sensorf1Pin);
sensorf2Value = analogRead(sensorf2Pin);
wdValue = analogRead(wdpin);
if (wdValue <=300){
  //tone(buzzerPin, 1000);
  }
else {
  //noTone(buzzerPin);
}
Serial.print("Вологість землі першої квітки: ");
Serial.println(sensorf1Value);
Serial.print("Вологість землі другої квітки: ");
Serial.println(sensorf2Value);
Serial.print("Обєм води: ");
Serial.println(wdValue);
delay(1000);
  }

}

