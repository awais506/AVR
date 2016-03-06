/* A simple program to show blinking of led on PORTB pin 0
	MUhammad Awais
	UET Lahore
	engr.mahmed506@gmail.com*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
 
  //------Inits-------
  DDRB = 0b00000001; 
  //Makes PORTB pin 0 as Output
  //Data dirction Register
  
  //-------Event loop------
  while(1) 
  {
    PORTB = 0b00000001; //Turns ON  LED on Pin 0
	
    _delay_ms(200); //2 milli second delay
	
    PORTB=  0b00000000; //Turns OFF LED
	
    _delay_ms(200); //2 milli second delay
  }
}
