#include <Arduino.h>
// #include<driver/touch_sensor_common.h>
// #include<driver/touch_sensor.h>

#define EXT_ISR_MODE 0

void TouchEvent(){
  Serial.printf("Touch Event.\r\n");
}

void PinIntEvent(){
  Serial.println("PinInt Event.\r\n");
}

void setup() {
  Serial.begin(115200);
  // ledcSetup()
  // touch_pad_init();
  // touch_pad_sw_start();
  // touch_pad_filter_enable();
  #if 1 == EXT_ISR_MODE
    touchAttachInterrupt(T2, TouchEvent, 100);
  #elif 2 == EXT_ISR_MODE
    Serial.println("Test");
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(T2, PinIntEvent, FALLING);
  #endif
}

void loop() {
  #if 0 == EXT_ISR_MODE
    Serial.printf("touch:%d\r\n", touchRead(T2)/1000);
  #endif
  delay(200);
}
