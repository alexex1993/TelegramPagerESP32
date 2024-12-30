# Telegram pager for microcontroller ESP32 (ESP8266) and OLED display SSD1306.

Need components:
1) ESP32 (ESP8266) board
2) SSD1306 OLED Display

Optional: Buzzer 5V

![image](https://github.com/alexex1993/TelegramPagerESP32/assets/6523682/71e377eb-660a-4db4-9bf9-838b6ad7e032)

## Features
- Receive messages from a telegram bot
- Send message back about successful delivery
- Show message time in format [HH:MM]
- Play a programmed melody when a message is sent

## Getting started

0) Create telegram bot and get token
1) Setting Arduino IDE for using ESP32 boards
2) Install libraries in Arduino IDE (Adafruit_SSD1306, FastBot, TimeLib)
3) Connect display to ESP32 (also optional connect Buzzer 5V)
4) Download code from this repository
5) Edit first rows in project for wifi credentials and token
6) Upload sketch to ESP32 (ESP8266)
7) Use the paiger 

## How to connect components

| ESP32 (ESP8266) Board | SSD1306 OLED Display |
| ----------- | ----------- |
| GND   | GND   |
| 3V3 | VCC   |
| D22    | SCL   |
| D21    | SDA   |

| ESP32 Board | Buzzer 5V |
| ----------- | ----------- |
| GND   | GND   |
| D18 | Plus contact   |

Also, you can use modification ESP8266 with internal oled display

[Demonstration on YouTube](https://youtu.be/ok_MZ0AdNfg?si=WcUMEWS6AgMilHYF)
