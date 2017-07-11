#include <stdlib.h>
#include <avr/io.h>
#include <until/delay.h>

#define Taster1_1 !(PINB & (1<<PB1))
#define Taster1_0 (PINB & (1<<PB1))

#define Taster2_1 !(PINB & (1<<PB2))
#define Taster2_0 (PINB & (1<<PB2))


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

int main(void)
{

	long x;
	
	x = 1;

	DDRD = 0xFF;//Port D als Ausgag setzen
	
	DDRB &= ~(1<<PB1);//Port B als eingang setzen
	
	PORTB |= (1<<PB1);//Pull up wiederstand aktivieren 
	PORTB |= (1<<PB2);
	
		while(1)
	{

	while(Taster1_1) // Bei Tasterdrücken LEDs stoppen 
	{
		LED1_1 LED8_1;
	}	
	
			for(x=0; x<30000; x++) //Schleiff erstellen 
			{
				LED1_1;
				LED8_1;
			}
		
				LED1_0;
				LED8_0;//LEDs abschalten
	
	
	while(Taster1_1)
	{
		LED2_1 LED7_1;
	}	
		
			for(x=0; x<30000; x++)
			{
				LED2_1;
				LED7_1;
			}
		
				LED2_0;
				LED7_0;
		
	while(Taster1_1)
	{
		LED3_1 LED6_1;
	}
	
			for(x=0; x<30000; x++)
			{
				LED3_1;
				LED6_1;
			}
			
				LED3_0;
				LED6_0;
				
	while(Taster1_1)
	{
		LED4_1 LED5_1;
	}	

			for(x=0; x<30000; x++)
			{
				LED4_1; 
				LED5_1;
			}
			
				LED4_0;
				LED5_0;
				
	while(Taster1_1)
	{
		LED5_1 LED4_1;
	}
	
			for(x=0; x<30000; x++)
			{
				LED5_1;
				LED4_1;
			}
			
				LED5_0;
				LED4_0;
				
	while(Taster1_1)
	{
		LED6_1 LED3_1;
	}			
	
			for(x=0; x<30000; x++)
			{
				LED6_1;
				LED3_1;
			}
			
				LED6_0;
				LED3_0;
				
	while(Taster1_1)
	{
		LED7_1 LED2_1;
	} 
				
			
			for(x=0; x<30000; x++)
			{
				LED7_1;
				LED2_1;
			}
			
				LED7_0;
				LED2_0;
	
	while(Taster1_1)
	{
		LED8_1 LED1_1;
	}	
			for(x=0; x<30000; x++)
			{
				LED8_1;
				LED1_1;
			}
		
				LED8_0;
				LED1_0;
	 

	}//end of while
	
	return 0;
}//end of main
