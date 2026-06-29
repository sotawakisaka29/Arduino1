#include <Wire.h>
#include <ZumoShieldN.h>
#define MAX_COMMAND 20

char command[MAX_COMMAND];
int cmdIndex = 0;

void setup() {
  Serial.begin(9600);

  buzzer.playOn(); 
  Serial.println("Input Available");
  getCommand();

  Serial.println("Push button to start.");
  button.waitForButton();

  buzzer.playOn();
}

void loop() {

}


void getCommand(void){
  cmdIndex = 0;

  while (1) {
    if (Serial.available() > 0) {
      char input = Serial.read();

      if (input == '\n' || input == '\r') {
              continue;
      }

      if (cmdIndex >= MAX_COMMAND) {
        cmdIndex = 0;
        Serial.println("Over Max Command. Delete All Command!");
      }

      if (input == 'd') {
        cmdIndex = 0;
        Serial.println("Delete All Command!");
      }
      else if (input == 'r' || input == 'l' || input == 'f') {
        command[cmdIndex++] = input;
      }
      else if (input == '.') {
        command[cmdIndex] = '\0';
        Serial.print("Command: ");
        Serial.println(command);
        break;  // ← 入力完了で抜ける
      }
      else {
        Serial.println("Wrong Command!");
      }
    }
  }
}
