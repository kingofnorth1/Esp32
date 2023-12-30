#include<Arduino.h>
#include<WiFi.h>


String transEncryptionType(wifi_auth_mode_t encryptionType){		//对比出该wifi网络加密类型并返回相应的String值   
  switch(encryptionType){
      case (WIFI_AUTH_OPEN):
        return "Open";
      case (WIFI_AUTH_WEP):
        return "WEP";
      case (WIFI_AUTH_WPA_PSK):
        return "WPA_PSK";
      case (WIFI_AUTH_WPA2_PSK):
        return "WPA2_PSK";
      case (WIFI_AUTH_WPA_WPA2_PSK):
        return "WPA_WPA2_PSK";
      case (WIFI_AUTH_WPA2_ENTERPRISE):
        return "WPA2_ENTERPRISE";
      default:
        return("Unkonwn EncryptionType");
  }
}


void ScanNetWork(){
  Serial.println("scan deno");
  int n = WiFi.scanNetworks();
  if (n == 0){
    Serial.println("no network found");
  }else {
    Serial.println(n);
    Serial.println("network found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      String encryptionTypeDescription = transEncryptionType(WiFi.encryptionType(i));
      Serial.println(encryptionTypeDescription);
      Serial.println("-----------------------");
      delay(10);
    }
  }
  Serial.println("");
  delay(5000);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ScanNetWork();
  delay(100);
}

void loop() {
  // int d =  10;
  // Serial.println("hxt shi yi ge da ben dang "+d);
  delay(100);
}
