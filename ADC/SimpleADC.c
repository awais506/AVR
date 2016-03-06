/*  A simple program to show ADC in Atmega series of Avr MPS
    Taking PORTC0 as input and showing value using Leds on PORTB
	MUhammad Awais
	UET Lahore
	engr.mahmed506@gmail.com*/


// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>


// -------- Functions --------- //
//This function is simplest way of starting ADC on PORTC0

static inline void initADC0(void) 
{
ADMUX |= (1 << REFS0);                   
/* reference voltage on AVCC */

ADCSRA |= (1 << ADPS1) | (1 << ADPS0);  
/* ADC clock prescaler /8 */

ADCSRA |= (1 << ADEN);                  
/* enable ADC */
	
	}


int main(void) 
{

// To store values of adc we take variables of 1 and 2 byte
uint16_t ledValue;
uint16_t adcValue;
uint8_t i;

// -------- Inits --------- //
initADC0();
DDRB = 0xff;

// ------ Event loop ------ //
while (1) 
{

ADCSRA |= (1 << ADSC);  /* start ADC conversion */

loop_until_bit_is_clear(ADCSRA, ADSC);  /* wait until done, This will wait untill conversion is done */

adcValue = ADC;  /* read ADC in */

/*
Value is converted into 10 bit word.
ADC value is then stored in two registers ADCH and ADCL
ADCH have two higher bits and ADCL have 8 lower bits, but we can acess this as single register using ADC. 
*/


//using only 8 higher bits as we have 8 bits on PORTB
/* Have 10 bits, want 3 (eight LEDs after all) */
ledValue = (adcValue >> 7);

/* Light up all LEDs up to ledValue */
PORTB = 0;

for (i = 0; i <= ledValue; i++) {
PORTB |= (1 << i);

}
_delay_ms(50);

}  /* End event loop */


return (0);  /* This line is never reached */
}
