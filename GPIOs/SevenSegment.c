//A simple program to on seven segment
//Common cathode, For common anode, reverse all the PORTB vlaues like this PORTB= ~(0b0000000); in function void sevenSegment(int num)

#include <avr/io.h>
#include <util/delay.h>


//----Functions for seven segment
void sevenSegment(int num)
{
switch (num)
{
case 0:
PORTB=(0b00111111);
break;
case 1:
PORTB=(0b00110000);
break;
case 2:
PORTB=(0b01011011);
break;
case 3:
PORTB=(0b01001111);
break;
case 4:
PORTB=(0b01100110);
break;
case 5:
PORTB=(0b01101101);
break;
case 6:
PORTB=(0b01111101);
break;
case 7:
PORTB=(0b00000111);
break;
case 8:
PORTB=(0b01111111);
break;
case 9:
PORTB=(0b01100111);
break;

	}
		}
		
void segOff()
{
PORTB=0b00000000;
	}
	
void segOn()
{

PORTB=0b11111111;
	}

//======Mian function======

int main(void)
{
  //Makes PORTB as Output
  DDRB = 0xFF; 
  
  //-----Event Loop-----
  while(1) 
  {
    for (int i=0;i<10;i++)
	{
	segOff();
    sevenSegment(i);
	_delay_ms(100);
	}
  }
}
