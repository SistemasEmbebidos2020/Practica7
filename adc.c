#include <avr/io.h>
#include <util/delay.h>
int main()
 {
DDRD = 0XFF;
DDRB |= ((1<<0)|(1<<1));
ADMUX = 0B01000001;	
ADCSRA = 0B00000111;	//PRE ESCALADOR  DE  128
ADCSRB = 0B00000000;
DIDR0 = 0B00000010;
while (1)
      {
	 ADCSRA = 0B11000111;
	 while(ADCSRA & (1<< ADSC));
	 //ADCSRA = 0B00000111;
	 PORTD = ADCL;
	 PORTB = ADCH;
	 _delay_ms(200);
}
   return 0;
 }

