#include "buzzer.h"

#define BUZZZER_PIN  18 // ESP32 pin GPIO18 connected to piezo buzzer

int melody[] = {
  NOTE_D2, NOTE_D2, NOTE_G4, NOTE_F2, NOTE_G4
};

int noteDurations[] = {
  2,2,4,2,2
};

void buzzer() {
  for (int thisNote = 0; thisNote < 5; thisNote++) {
    int noteDuration = 100 / noteDurations[thisNote];
    tone(BUZZZER_PIN, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZZER_PIN);
  }
}

