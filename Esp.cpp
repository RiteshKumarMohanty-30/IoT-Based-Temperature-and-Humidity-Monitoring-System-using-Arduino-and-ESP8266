#include <ESP8266WiFi.h>

const char *ssid = "ESP8266_Sensor";
const char *password = "12345678";
WiFiServer server(80);

String temperature = "0";
String humidity = "0";

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  server.begin();
  Serial.println("ESP8266 Web Server Started");
}

void loop() {
  WiFiClient client = server.available();
  if (Serial.available()) {
    temperature = Serial.readStringUntil(',');
    humidity = Serial.readStringUntil('\n');
  }

  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><head><style>");
    client.println("body{text-align:center;font-family:Arial;background:#f4f4f4;}");
    client.println(".container{margin:auto;width:50%;background:white;padding:20px;border-radius:10px;box-shadow:0 0 10px gray;}");
    client.println("</style></head><body>");
    client.println("<h1>ESP8266 Sensor Data</h1>");
    client.println("<div class='container'>");
    client.println("<p><b>Temperature:</b> " + temperature + " °C</p>");
    client.println("<p><b>Humidity:</b> " + humidity + " %</p>");
    client.println("</div></body></html>");
    client.stop();
  }
}
