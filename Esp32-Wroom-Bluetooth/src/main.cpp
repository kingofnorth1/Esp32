#include <Arduino.h>
#include <BluetoothSerial.h>
// #include <ArduinoBLE.h>

BluetoothSerial SerialBT;
void setup() {
  Serial.begin(115200);
  SerialBT.begin("homepage");
  // SerialBT.setPin("1234");
  Serial.printf("BT inital is ok and Ready pair. \r\n");
}

void loop() {
  if (Serial.available()){
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()){
    Serial.write(SerialBT.read());
  }
}