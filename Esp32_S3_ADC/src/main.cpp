#include <Arduino.h>

void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {
  int adc = 0;
  adc = analogRead(3);
  Serial.print(adc);
  Serial.print("\n");
  delay(300);
}
