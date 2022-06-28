#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic sonar(12,13);
Servo motor;
int distancia;
int ang;

void setup(){
  motor.attach(9);
  Serial.begin(9600);
}
void loop(){
  distancia = sonar.read();
  ang = 10;

  if (distancia <= 20){
    for(ang = 10; ang <= 145; ang += 1){
      motor.write(ang);
      Serial.print("angulação: ");
      Serial.println(ang);
      delay(10);
      }
    delay(5000);
  
    for(ang = 145; ang >= 10; ang -= 1){
      motor.write(ang);
      Serial.print("angulação: ");
      Serial.println(ang);
      delay(10);
    }
    delay(1000);
  }
}