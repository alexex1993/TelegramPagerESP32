#include <FastBot.h>
#include "src\utils.h"
#include "src\buzzer.h"

#define WIFI_SSID "Kitel_24"
#define WIFI_PASS "1234567888"
#define BOT_TOKEN "6900137681:AAGc0fg_4Xni4JSFOY-qo-PChlTN04IcBic"

FastBot bot(BOT_TOKEN);

// обработчик сообщений
void newMsg(FB_msg& msg) {
  // выводим всю информацию о сообщении
  Serial.println(msg.toString());
  // отправить сообщение обратно
  bot.replyMessage("Доставлено!", msg.messageID, msg.chatID);
  display2oled(get_time(msg.unix) + " " + msg.text);
  buzzer();
}

void setup() {
  Serial.begin(115200);
  
  connectWiFi();
  bot.attach(newMsg);
}

void loop() {
  bot.tick();
}

void connectWiFi() {
  delay(2000);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > 15000) ESP.restart();
  }
  Serial.println("Connected");
  display2oled("WiFi connect - OK \n\n\nNo messages yet\n\n\nSend message to bot");
}






