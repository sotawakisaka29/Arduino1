#include <Wire.h>
#include <ZumoShieldN.h>

void setup() {
   buzzer.playOn();
}

void loop() {
  button.waitForPress();
  buzzer.playNote(NOTE_E(4),500,15);
  buzzer.playNote(NOTE_E(4),500,15);
  buzzer.playNote(NOTE_F(4),500,15);
  buzzer.playNote(NOTE_G(4),500,15);
  buzzer.playNote(NOTE_G(4),500,15);
  buzzer.playNote(NOTE_F(4),500,15);
  buzzer.playNote(NOTE_E(4),500,15);
  buzzer.playNote(NOTE_D(4),500,15);
  buzzer.playNote(NOTE_C(4),500,15);
  buzzer.playNote(NOTE_C(4),500,15);
  buzzer.playNote(NOTE_D(4),500,15);
  buzzer.playNote(NOTE_E(4),500,15);
  buzzer.playNote(NOTE_E(4),1000,15);
  buzzer.playNote(NOTE_D(4),500,15);
  buzzer.playNote(NOTE_D(4),1000,15);
  button.waitForRelease();
}
