#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 2        // DHT22 data pin connected to D2 on Arduino
#define DHTTYPE DHT22   // Define sensor type

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial espSerial(10, 11); // RX = D10, TX = D11 for ESP8266

void setup() {
  Serial.begin(115200);
  espSerial.begin(115200);
  dht.begin();

  delay(2000);
  Serial.println("DHT22 Sensor Initialized");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  // Send data to ESP8266 via Software Serial
  espSerial.print(temperature);
  espSerial.print(",");
  espSerial.println(humidity);

  delay(2000);
}
