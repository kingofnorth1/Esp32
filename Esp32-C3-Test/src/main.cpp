/*
*流水灯测试程序
*/
#include <Arduino.h>
int led1 = 12;
int led2 = 13;
 
 
void setup() {
  Serial.begin(115200);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
}
 
void loop() {
  Serial.println("Test");
  digitalWrite(led1,HIGH);digitalWrite(led2,LOW);
  delay(1000);
  digitalWrite(led1,LOW);digitalWrite(led2,HIGH);
  delay(1000);
}