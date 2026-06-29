#include <Wire.h>
#include <ZumoShieldN.h>

void setup() {
  buzzer.playOn();
}

void loop() {
  button.waitForPress();
  delay(500);

  led.on();
  motors.setSpeeds(500, 500);
  delay(500);
  motors.setSpeeds(0, 0);
  
  led.off();
  motors.setSpeeds(-500, -500);
  delay(500);
  motors.setSpeeds(0, 0);

  led.on();
  buzzer.playNum(1);
  motors.setSpeeds(-500, 500);
  delay(500);
  motors.setSpeeds(0, 0);

  led.off();
  buzzer.playNum(1);
  motors.setSpeeds(500, -500);
  delay(500);
  motors.setSpeeds(0, 0);
  
}
