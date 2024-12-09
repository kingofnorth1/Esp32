#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

#define SSID "WZ"
#define PASSWORD "82913954"

#define LED_PIN 2

ESP8266WebServer server(80);

const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; }
        .button { padding: 15px 32px; font-size: 16px; cursor: pointer; display: inline-block; margin: 10px; }
        .on { background-color: #4CAF50; color: white; border: none; }
        .off { background-color: #f44336; color: white; border: none; }
    </style>
</head>
<body>
    <h1>ESP8266 LED Control</h1>
    <button class="button on" onclick="sendCommand('LED_ON')">Turn On</button>
    <button class="button off" onclick="sendCommand('LED_OFF')">Turn Off</button>

    <script>
        function sendCommand(command) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/command?cmd=" + command, true);
            xhr.onreadystatechange = function () {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    alert(xhr.responseText);
                }
            };
            xhr.send();
        }
    </script>
</body>
</html>
)rawliteral";

void WiFiConnected();
void WebServerInit();
void handleRoot();
void handleCommand();

void setup() {
  Serial.begin(115200);
  delay(10); // 添加一个小延迟
  Serial.println("Starting setup...");

  pinMode(LED_PIN, OUTPUT); // 设置 LED_PIN 为输出模式
  digitalWrite(LED_PIN, HIGH); // 初始化 LED_PIN 为高电平（假设HIGH为熄灭）

  WiFiConnected();
  WebServerInit();
  delay(10); // 添加一个小延迟

  Serial.println("Setup complete.");
}

void loop() {
  server.handleClient();
  yield(); // 让系统有机会处理其他任务
}

void WiFiConnected() {
  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void WebServerInit() {
  server.on("/", handleRoot);
  server.on("/command", handleCommand);
  server.begin();
  Serial.println("HTTP server started");
}

void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

void handleCommand() {
  String command = server.arg("cmd");
  if (command.length() > 0) {
    Serial.println("Received command: " + command);
    if (command == "LED_ON") {
      digitalWrite(LED_PIN, LOW); // 假设 LOW 为点亮 LED
      server.send(200, "text/plain", "LED turned ON");
    } else if (command == "LED_OFF") {
      digitalWrite(LED_PIN, HIGH); // 假设 HIGH 为熄灭 LED
      server.send(200, "text/plain", "LED turned OFF");
    } else {
      server.send(200, "text/plain", "Unknown command: " + command);
    }
  } else {
    server.send(200, "text/plain", "No command provided");
  }
}