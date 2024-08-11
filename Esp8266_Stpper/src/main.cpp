#include <Arduino.h>
#include <Stepper.h>

#define STEPS 100
         
Stepper stepper(STEPS, 14, 13, 12, 16);


void setup() {
  stepper.setSpeed(90);

  Serial.begin(9600);
}

void loop()
{
    // 顺时针旋转一周
    Serial.println("shun");
    stepper.step(2048); //4步模式下旋转一周用2048 步。
    delay(500);

    // 逆时针旋转半周
    Serial.println("ni");
    stepper.step(-1024); //4步模式下旋转一周用2048 步。
    delay(500);
}
