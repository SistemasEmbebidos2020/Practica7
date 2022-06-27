#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include <stdlib.h>

int main()
 {

ADMUX = 0B01000001;	//AVCC- AREF y ADC1
ADCSRA = 0B00000111;	//PRE-SCALER  128 - DISABLED ANALOG CONVERTER & CONVERSION NOT STARTED
ADCSRB = 0B00000000; 	//FREE RUNNING MODE
DIDR0 = 0B00000010;	//ENABLE ANALOG MODE ADC1
serial_begin(9600);
while (1)
      {
	 ADCSRA = 0B11000111; // ENABLED ANALOG CONVERTER & START CONVERSION
	 while(ADCSRA & (1<< ADSC)); // ADSC DISABLED? 
	
	/* PORTD = ADCL;
	 PORTB = ADCH;*/ //simulado
	
	//presencial
	float r = ADC/1023.0*5.0;
	char rec1[20] ;
	dtostrf(r, 2, 4, rec1);
	serial_println_str(rec1);
	
	
	 _delay_ms(200);
}
   return 0;
 }
