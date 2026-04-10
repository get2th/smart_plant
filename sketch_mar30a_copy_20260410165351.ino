#include <Arduino.h>
#include <DHT11.h>
/*#include <SoftwareSerial.h>
#include "DS3231.h"
DS3231 clock;
RTCDateTime dt;*/
//char weekDay[][6] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
DHT11 dht11(2);
int sensorf1Pin = A0;
int sensorf1Value = 0;
int sensorf2Pin = A2;
int sensorf2Value = 0;
int wdpin = A1;
int wdValue = 0;
/*int Rclock = 2;
int TimeValue = 0;*/
//int Date = RClock.getDate();

void setup() {
 Serial.begin(9600);
 Serial.println("1и");
 //clock.begin();
 Serial.println("2");
 //Rclock.adjust(DateTime(2026, 4, 3, 12, 0, 0))
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
//TimeValue = digitalRead(Rclock);
Serial.print("Вологість землі першої квітки: ");
Serial.println(sensorf1Value);
Serial.print("Вологість землі другої квітки: ");
Serial.println(sensorf2Value);
Serial.print("Обєм води: ");
Serial.println(wdValue);
delay(1000);
}

/*void my_clock_set(){
  int hour, minute, second;
  sscanf(__TIME__, "%d:%d:%d", &hour, &minute, &second);
  second += 11;
  if (second >= 60) {
    second -= 60;
    minute++;
    if (minute >= 60) {
      minute = 0;
      hour++;
      if (hour >= 24) hour = 0;
    }
  }

  char monthStr[4];
  int day, year, month = 0;
  sscanf(__DATE__, "%s %d %d", monthStr, &day, &year);
  const char* months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
   for (int i = 0; i < 12; i++) {
    if (strncmp(monthStr, months[i], 3) == 0) month = i + 1;
  }

  clock.setDateTime(year, month, day, hour, minute, second);
  Serial.println("RTC синхронізовано з +11 секунд");
}*/