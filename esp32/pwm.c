#include <Arduino.h>
const int ledPin = 18; 
const int ledPin2 = 19;

const int freq = 10000;
const int canalPWM1 = 0;
const int canalPWM2 = 1;
const int resolucion = 8;
 
void setup(){
  // configurar la señal PWM
  ledcSetup(canalPWM1, freq, resolucion);
  ledcSetup(canalPWM2, freq, resolucion);
  // Asignar el canal pwm a cada pin
  ledcAttachPin(ledPin, canalPWM1);
  ledcAttachPin(ledPin2, canalPWM2);

}
 
void loop(){
  // Para aumentar la intensidad del primer led y disminuir la del siguiente
  int ciclo1=0;
  int ciclo2=255;
  while(ciclo1<255 && ciclo2>0){
    ledcWrite(canalPWM1, ciclo1);
    ledcWrite(canalPWM2,ciclo2);
    delay(50);
    ciclo1++;
    ciclo2--;
  }
  // Para disminuir la intensidad del primer led y aumentar la del siguiente
  ciclo1=255;
  ciclo2=0;
  while(ciclo2<255 && ciclo1>0){
    ledcWrite(canalPWM1, ciclo1);
    ledcWrite(canalPWM2,ciclo2);
    delay(50);
    ciclo1--;
    ciclo2++;
  }
  ciclo1=0;
  ciclo2=255;
}
