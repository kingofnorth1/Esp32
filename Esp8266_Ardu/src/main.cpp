#include <Arduino.h>
#include <Stepper.h>

enum gpio
{
  IN1 = 14,
  IN2 = 13,
  IN3 = 12,
  IN4 = 16
};

void WritePins(gpio in, uint8_t temp);

void WritePins(gpio in, uint8_t temp)
{
  digitalWrite(in, temp);
  delay(200);
}

void loop() {

}
