#include <avr/io.h>
#include <util/delay.h>
 
int main(void){
   DDRD |= 0b01100000;
   TCCR0A = 0b11100011; 
   TCCR0B = 0b00000001; 				  
   OCR0A = 0; //valor inicial de pwm para el pin OC0A
   OCR0B = 0; //valor inicial de pwm para el pin OC0B
while(1){
      do{
         OCR0A++;
         OCR0B++;
         _delay_ms (10);
      }while(OCR0A<255);
      _delay_ms (2000L);
do{
         OCR0A--;
         OCR0B--;
         _delay_ms (10);
      }while(OCR0A>0);
      _delay_ms (3000L);
    }
   return 0;
}
