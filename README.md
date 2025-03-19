# IoT-Based Temperature & Humidity Monitoring using Arduino & ESP8266

## Overview
This project utilizes an **Arduino Uno**, **ESP8266 WiFi module**, and **DHT22 sensor** to measure temperature and humidity in real-time. The ESP8266 hosts a web page displaying the live sensor data, making it accessible over a local WiFi network. This system is ideal for IoT applications, environmental monitoring, and smart home automation.

## Features
- **Real-time temperature & humidity monitoring** using DHT22.
- **Web-based interface** hosted by ESP8266.
- **Wireless communication** between Arduino and ESP8266.
- **Easy circuit implementation** with minimal components.

## Components Required
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| ESP8266 WiFi Module | 1 |
| DHT22 Sensor | 1 |
| 10kΩ Resistor | 1 |
| Breadboard & Jumper Wires | As required |

## Circuit Connections
| ESP8266 Pin | Arduino Uno Pin |
|-------------|---------------|
| VCC | 3.3V |
| GND | GND |
| TX | D1 |
| RX | D2 |
| CH_PD | 3.3V |

| DHT22 Pin | Arduino Uno Pin |
|-----------|---------------|
| VCC | 5V |
| GND | GND |
| DATA | D4 |

## Installation & Setup
1. **Install Required Libraries:**
   - Install the `DHT` library from the Arduino Library Manager.
   - Install the `ESP8266WiFi` library.
2. **Upload Code to Arduino:**
   - Connect the Arduino to your PC and upload the `Arduino_Communication.ino` sketch.
3. **Upload Code to ESP8266:**
   - Upload the `ESP8266_Webserver.ino` sketch.
4. **Power the Circuit:**
   - Ensure proper voltage supply to ESP8266 (3.3V) and Arduino (5V).
5. **Access Web Page:**
   - Connect to the ESP8266 hotspot and navigate to the provided IP address in a browser.

## Code Explanation
- **Arduino Code:** Reads temperature and humidity data from DHT22 and sends it to ESP8266 via Serial communication.
- **ESP8266 Code:** Receives data from Arduino, hosts a web server, and displays real-time readings.

## Observations
| Observation | Temperature (°C) | Humidity (%) |
|------------|----------------|--------------|
| 1st | 30.90 | 83.20 |
| 2nd | 31.00 | 83.30 |
| 3rd | 31.02 | 82.40 |

## Real-Time Applications
- Smart agriculture monitoring
- Industrial temperature regulation
- Home automation & IoT applications

## License
This project is open-source and available under the **MIT License**.
