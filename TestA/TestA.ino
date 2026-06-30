#include <Wire.h>
#include <ZumoShieldN.h>

int count;
String command;
char coms[20];

void setup() {
  Serial.begin(9600);  
  Serial.println("Input Possible");
  
}

void loop() {
  if(Serial.available()>0){
    String coms = Serial.readStringUntil('.');
    Serial.println(coms);
  }
}
