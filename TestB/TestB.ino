#include <Wire.h>
#include <ZumoShieldN.h>

int speed = 50;
bool turn = false;
char com[20] = "rlrrl";
int index = 0;
int i;

void setup() {
  buzzer.playOn();
  Serial.begin(9600);
  Serial.println("Zumo sample Start!");
}

void loop() {
  button.waitForButton()
  for(i=0;i<20;i++){

    motors.setSpeeds(speed, speed);
    reflectances.update();
    if (reflectances.value(2) > 300 || reflectances.value(5) > 300) {
      delay(1000);
      speed = 0;
      turn = true;
    }else{
      if (turn == false){
        speed = 50;
      }
    }
    if (turn == true){
      if (com[index] == '\0'){
        motors.setSpeeds(0,0);
      }else{
        if (com[index] == 'r'){
          motors.setSpeeds(100,-100);
        }else{
          motors.setSpeeds(-100,100);
        }
        delay(1500);
        motors.setSpeeds(0,0);
        turn = false;
        index += 1;
      }
    }
  }
  
}
