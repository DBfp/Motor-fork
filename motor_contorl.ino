#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int xposPin = A0; // 雙軸按鍵搖桿 VRx 接 Arduino Analog pin A0
int yposPin = A1; // 雙軸按鍵搖桿 VRy 接 Arduino Analog pin A1
int Xpos, Ypos;
char command;

void setup() {
  Serial.begin(9600);
  Serial.println("Motor control via Serial Monitor!");
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);

}

void loop() {
  Xpos = analogRead(xposPin);
  Ypos = analogRead(yposPin);
  Serial.print(Xpos);
  Serial.print("--");
  Serial.println(Ypos);
  Serial.println(command);

  if (Xpos > 800 && Ypos <800 && Ypos>300) {
    command = 'W';
  } else if (Xpos < 10 && 300 < Ypos <800 ) {
    command = 'S';
  } else if (Ypos > 800 && 300 < Xpos <800 ) {
    command = 'D';
  } else if (Ypos < 10 && Xpos <800 && Xpos>300) {
    command = 'A';
  } else{
    command = 'X';  
  }

  switch (command) {
    case 'W':
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      delay(100);
      break;
    case 'A':
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      delay(100);
      break;
    case 'S':
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      delay(100);
      break;
    case 'D':
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      delay(100);
      break;
    case 'X':
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      delay(100);
      break;
  }
  Xpos = 524;
  Ypos = 524;
  delay(100);
}
