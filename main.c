	
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 80000000UL


int main(void)
{
	char y = 0;
	char p = 0;
	int x = 150;
	
	{	//pin belegung
	DDRD = 0xFF;//Port D als Ausgag setzen
	
	DDRB &= ~(1<<PB1);//Port B als eingang setzen
	
	PORTB |= (1<<PB1);//Pull up wiederstand aktivieren 
	PORTB |= (1<<PB2);
	PORTB |= (1<<PB3);
	}
	
	
		while(1)
	{
		
	}//end of while
	
	return 0;
}//end of main