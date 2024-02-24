#include "utils.h"
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

/* Функция перекодировки русских букв из UTF-8 в Win-1251 */
String utf8rus(String source)
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };
  k = source.length(); i = 0;
  while (i < k) {
    n = source[i]; i++;
    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB8; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
          break;
        }
      }
    }
    m[0] = n; target = target + String(m);
  }
return target;
}

void display2oled(String message) {

  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
      Serial.println("SSD1306 allocation failed");
      for(;;); }
    delay(50);
    display.setCursor(0, 0);
    display.cp437(true);
    display.clearDisplay();
    display.setTextSize(1);             
    display.setTextColor(WHITE);  
    display.println(utf8rus(message));
    display.display();

}

String get_time(uint32_t unix){
  UnixTime stamp(3);
  stamp.getDateTime(unix);
  String hour;
  String minute;
  if (stamp.hour < 10) {
    hour = "0" + String(stamp.hour);
  } else {
    hour = String(stamp.hour);
  };

  if (stamp.minute < 10) {
    minute = "0" + String(stamp.minute);
  } else {
    minute = String(stamp.minute);
  };


  return "[" + hour + ":" + minute + "]";
}

