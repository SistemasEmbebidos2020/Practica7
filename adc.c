#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include <stdlib.h>

void mostrarleds(){
	float r = ADC/1023.0*5.0;

	 if (r<0.49) {PORTB = 0; PORTD = 0;}
else if (r<1.00) {PORTB=1; PORTD &= ~0B11110000; }
else if (r<1.50) {PORTB=3;  PORTD = 0;  }
else if (r<2.00) {PORTB=7;  PORTD = 0;  }
else if (r<2.50) {PORTB=15; PORTD = 0;  }
else if (r<3.00) {PORTB=31; PORTD = 0;  }
else if (r<3.50) {PORTB=63; PORTD = 0;  }
//else if (r>=3.50) {PORTB=63; PORTD =  0X10 ;  }	//PARA USAR ESTO, SE REQUIERE REAZILAR LA CONEXION DE PULL UP EXTERNAMENTE
else if (r<4.00) {PORTB=63; PORTD |=  0B00010000; PORTD &= ~(1<<5) ;  }
else if (r<4.50) {PORTB=63; PORTD |=  0B00110000; PORTD &= ~(1<<6) ;  }
else if (r<5.00) {PORTB=63; PORTD |=  0B01110000; PORTD &= ~(1<<7) ;  }
else 			 {PORTB=63; PORTD |=  0B11110000;  }

}

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
	
	//presencial
	mostrarleds();
	 _delay_ms(200);
}
   return 0;
 }
