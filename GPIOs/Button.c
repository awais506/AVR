/*
Demo of the simplest on/off button code
Button connected to PD7
LEDs connected to PB0
*/


// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>

int main(void) 
{

// -------- Inits --------- //
PORTD = 0b10000000; 		 	/* initialize pullup resistor on our input pin */
DDRB  = 0xff;  					/* set up all LEDs for output */
//All pins of AVR are in input mode so no need to configure them


// ------ Event loop ------ //
while (1) 

{
if((PIND & (1 << PD7)) == 0 )     /* look for button press */
{  

PORTB = 0b00111101;  /* pressed */
   }

else 
{  
/* not pressed */
PORTB = 0b11000010;
	}
			}  
/* End event loop */
return (0);
}
