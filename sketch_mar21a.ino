
int sensorPin = A0;
int sensorValue = 0;

void setup() {
 Serial.begin(9600);
Serial.println("Початок роботи");
}

void loop() {
 sensorValue = analogRead(sensorPin);
  Serial.print("Вологість землі: ");
  Serial.println(sensorValue);
 delay(10000);
}
