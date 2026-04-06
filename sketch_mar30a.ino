#include <SoftwareSerial.h>
#include <Arduino.h>
#include "DS3231.h"
DS3231 clock;
RTCDateTime dt;
char weekDay[][6] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
int sensorPin = A0;
int sensorValue = 0;
int Date = RClock.getDate();

void setup() {
 Serial.begin(9600);
 clock.begin();
 Serial.println("Початок роботи");
 RCT.adjust(DataTime(2026, 4, 3, 12, 0, 0))
}

void loop() {
  dt = clock.getDateTime();
  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
sensorValue = analogRead(sensorPin);
Serial.print("Вологість землі: ");
Serial.println(sensorValue);
delay(10000);
}

void my_clock_set(){
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

}