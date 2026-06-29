#include <Wire.h>
#include <ZumoShieldN.h>
#define MAX_COMMAND 20

char command[MAX_COMMAND];
int cmdIndex = 0;

void setup() {
  Serial.begin(9600);

  buzzer.playOn(); 
  getCommand();

  Serial.println("Push button to start.");
  button.waitForButton();

  buzzer.playOn();
}

void loop() {

}

void getCommand(void){
  if (Serial.available() > 0) {
    char input = Serial.read();

    if (cmdIndex >= MAX_COMMAND) {
      cmdIndex = 0;
      Serial.println("Over Max Command. Delete All Command!");
    }

    if (input == 'd') {
      cmdIndex = 0;
      Serial.println("Delete All Command!");
    }
    else if (input == 'r' || input == 'l' || input == 'f') {
      command[cmdIndex] = input;
      cmdIndex++;
    }
    else if (input == '.') {
      command[cmdIndex] = '\0'; 
      Serial.println(command);
    }
    else {
      Serial.println("Wrong Command!");
    }
  }
}
}