#include <Arduino.h>
#include "KeyWord.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


void WiFi_Connect(){
  WiFi.begin(Key, Word);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
}



void getBiliBiliFollower(String uuid){
  String followerUrl = "https://api.bilibili.com/x/relation/stat?vmid=" + uuid;
  long follower = 0;
  DynamicJsonDocument doc(1024);
  HTTPClient http;

  http.begin(followerUrl);
  int httpCode = http.GET();
  if (httpCode > 0){
    Serial.printf("HTTP Get Code: %d\r\n", httpCode);
    String refBuff = http.getString();
    //	输出示例：{"mid":123456789,"following":226,"whisper":0,"black":0,"follower":867}}
    Serial.println(refBuff);

    //	使用ArduinoJson_6.x版本，具体请移步：https://github.com/bblanchon/ArduinoJson
    deserializeJson(doc, refBuff); //开始使用Json解析
			follower = doc["data"]["follower"];
			Serial.printf("Followers: %ld \r\n", follower);
  }
  else {
    Serial.printf("HTTP Get Error: %s\n", http.errorToString(httpCode).c_str());
  }

}

void setup() {
  Serial.begin(115200);
  int temp =  WiFi.mode(WIFI_STA);
  // Serial.println(temp);
  Serial.println("Connecing...");

  WiFi_Connect();
  IPAddress Ip= WiFi.localIP();

  Serial.println("WiFi is Connect!");
  Serial.printf("IP Address:  %s\n",Ip.toString().c_str());
  Serial.println();
}

void loop() {
  String uuid = "393959823";
  getBiliBiliFollower(uuid);
  delay(10000);
}