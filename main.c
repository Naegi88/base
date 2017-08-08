	
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 80000000UL

#define Taster1_1 !(PINB & (1<<PB1))
#define Taster1_0 (PINB & (1<<PB1))

#define Taster2_1 !(PINB & (1<<PB2))
#define Taster2_0 (PINB & (1<<PB2))	//Pin abfrage

#define Taster3_1 !(PINB & (1<<PB3))
#define Taster3_0 (PINB & (1<<PB3))


#define LED1_0 PORTD &= ~(1<<PD0);
#define LED1_1 PORTD |= (1<<PD0);

#define LED2_0 PORTD &= ~(1<<PD1);
#define LED2_1 PORTD |= (1<<PD1);

#define LED3_0 PORTD &= ~(1<<PD2);
#define LED3_1 PORTD |= (1<<PD2);

#define LED4_0 PORTD &= ~(1<<PD3);
#define LED4_1 PORTD |= (1<<PD3);

#define LED5_0 PORTD &= ~(1<<PD4);
#define LED5_1 PORTD |= (1<<PD4);

#define LED6_0 PORTD &= ~(1<<PD5);
#define LED6_1 PORTD |= (1<<PD5);

#define LED7_0 PORTD &= ~(1<<PD6);
#define LED7_1 PORTD |= (1<<PD6);

#define LED8_0 PORTD &= ~(1<<PD7);
#define LED8_1 PORTD |= (1<<PD7);     //Alle LEDs definiert mit Behfehl 1 und 0 


void led(char nr, char zustand);

int taster(char tas);


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
			LED1_1
			
			if(taster(1)==1)
			{
				LED7_1	
			}
			
			if(taster(2)==1)
			{
				LED7_0
			}
			
			led(4,taster(3));
	
	}//end of while
	
	return 0;
}//end of main


void led(char nr, char zustand)
{		//led steuerung
	if(zustand == 1)
	{
		switch(nr)
		{
			case 1: LED1_1
				break;
				
			case 2: LED2_1
				break;
				
			case 3: LED3_1
				break;
				
			case 4: LED4_1
				break;
				
			case 5: LED5_1
				break;
				
			case 6: LED6_1
				break;
				
			case 7: LED7_1
				break;
				
			case 8: LED8_1
				break;		
			
		}
	}
	
	else
	{
		switch(nr)
		{
			case 1: LED1_0
				break;
				
			case 2: LED2_0
				break;
				
			case 3: LED3_0
				break;
				
			case 4: LED4_0
				break;
				
			case 5: LED5_0
				break;
				
			case 6: LED6_0
				break;
				
			case 7: LED7_0
				break;
				
			case 8: LED8_0
				break;		
			
		}
	}
}	

int taster(char tas)
{		//Taster kontrolle

	int res = 0;
	
		switch(tas)
			{
				case 1: if(!(PINB & (1<<PB1)))
						{
							res = 1;
						}	
						
					break;
					
				case 2: if(!(PINB & (1<<PB2)))
						{
							res = 1;
						}
						
					break;
					
				case 3: if(!(PINB & (1<<PB3)))
						{
							res = 1;
						}
						
					break;
				
			}
			
	return res;
}