#include <Arduino.h>             
#include <DHT11.h>
#include <SoftwareSerial.h>
#include "DS3231.h"
#include <Wire.h>

DS3231 clock;
RTCDateTime dt;
DHT11 dht11(2);

int sensorf1Pin = A0;
int sensorf1Value = 0;
int sensorf2Pin = A2;
const int relay1 = 3;
const int relay2 = 4;


int sensorf2Value = 0;
int wdpin = A1;
int wdValue;
int buzzerPin;
int humidity;
int result;
char weekDay[][4] = {"Mon","Tue","Wed","Thu","Fri"};

void setup() {
  Serial.begin(9600);
 Serial.println("test 1");
  clock.begin();
  Serial.println("test 1");
  Wire.begin();
 Serial.println("test 2");
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);                
  digitalWrite(relay2, HIGH);
  Serial.println("test 3");
  Serial.println("set time!");
  
  my_clock_set(); // разово синхронізує час і додає 11 сек для точності
  
  //clock.setDateTime(__DATE__, __TIME__); 
  //dt = clock.convertStringToDateTime(__DATE__, __TIME__);
  //dt = addSeconds(dt, 13); 
  //clock.setDateTime(dt);
}

void loop() {
  int temperature = 0;
  dt = clock.getDateTime();
  Serial.println("test 2");
  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  wdValue = analogRead(wdpin);

  int humidity = 0;
  int result = dht11.readTemperatureHumidity(temperature, humidity);
  if (wdValue <=300){
    tone(buzzerPin, 1000);
  }
  else {
    noTone(buzzerPin);
  
    if (result == 0) {
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\tHumidity: ");
      Serial.print(humidity);
      Serial.println(" %");
      sensorf1Value = analogRead(sensorf1Pin);
      sensorf2Value = analogRead(sensorf2Pin);
      Serial.print("Вологість землі першої квітки: ");
      Serial.println(sensorf1Value);
      Serial.print("Вологість землі другої квітки: ");
      Serial.println(sensorf2Value);
      Serial.print("Обєм води: ");
      Serial.println(wdValue);
      if (dt.hour >= 17){
        if (sensorf1Value >= 300){
          digitalWrite(relay1, LOW);
        }
        else{

        }
        if (sensorf2Value >= 300){
          digitalWrite(relay2, LOW);
        }
        else{

        }
      }
      else{

      }
      }
    else{

  }
  }

delay(1000);
  }


// Синхронізує час і додає ще 11 секунд
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

  // Розбір дати
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
