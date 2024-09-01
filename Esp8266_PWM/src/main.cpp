#include <Arduino.h>

#define analogPin 16

void setup()
{
  pinMode(16, OUTPUT);
}

void loop()
{
  analogWrite(16, 200);
}