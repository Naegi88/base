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

int main(void)
{
	short zeit1;
	short zeit2;
	long x;
	char y;
	char p;
	char q;
	
	zeit1 = 50;
	zeit2 = 100;
	x = 1;
	y = 0;
	p = 0;
	q = 0;
	
	DDRD = 0xFF;//Port D als Ausgag setzen
	
	DDRB &= ~(1<<PB1);//Port B als eingang setzen
	
	PORTB |= (1<<PB1);//Pull up wiederstand aktivieren 
	PORTB |= (1<<PB2);
	PORTB |= (1<<PB3);
	
		while(1)
	{
	
			if((Taster1_1) || (y > 0) && (y < 3))
			{	LED1_0
				LED2_0
				LED3_0
				LED4_0
				LED5_0
				LED6_0
				LED7_0
				LED1_1
				
				_delay_ms(zeit1);
			
				LED2_1
				
				_delay_ms(zeit1);
				
				LED3_1
				
				_delay_ms(zeit1);
			
				LED4_1
				
				_delay_ms(zeit1);
			
				LED5_1
				
				_delay_ms(zeit1);
				
				LED6_1
				
				_delay_ms(zeit1);
				
				LED1_0
				
				_delay_ms(zeit1);
			
				LED2_0
				
				_delay_ms(zeit1);
				
				LED3_0
				
				_delay_ms(zeit1);
			
				LED4_0
				
				_delay_ms(zeit1);
			
				LED5_0
				
				_delay_ms(zeit1);
				
				LED6_0
				
				_delay_ms(zeit1);
			y++;
			p = 0;
			
			}
			
			
			
			else if (p == 0)	// 0
			{
				y = 0;
				LED1_1
				LED2_1
				LED3_1
				LED4_1
				LED5_1
				LED6_1
				

			}
			
			
			if(Taster2_1)
				{
					p++;
					_delay_ms(170);
				}
				
			switch(p)
			{
				case 1: 	LED1_0
							LED2_1
							LED3_1
							LED4_0
							LED5_0
							LED6_0
							LED7_0
							break;
							
				case 2: 	LED1_1
							LED2_1
							LED3_0
							LED4_1
							LED5_1
							LED6_0
							LED7_1
							break;	
						
				case 3: 	LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_0
							LED6_0
							LED7_1
							break;
								
				case 4: 	LED1_0
							LED2_1
							LED3_1
							LED4_0
							LED5_0
							LED6_1
							LED7_1
							break;
							
				case 5: 	LED1_1
							LED2_0
							LED3_1
							LED4_1
							LED5_0
							LED6_1
							LED7_1
							break;
							
				case 6: 	LED1_1
							LED2_0
							LED3_1
							LED4_1
							LED5_1
							LED6_1
							LED7_1
							break;
							
				case 7: 	LED1_1
							LED2_1
							LED3_1
							LED4_0
							LED5_0
							LED6_0
							LED7_0
							break;
								
				case 8: 	LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_1
							LED6_1
							LED7_1
							break;	
							
				case 9: 	LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_0
							LED6_1
							LED7_1
							break;
							
				case 10:	LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_0
							LED6_1
							LED7_1
							_delay_ms(zeit2);// 9
							
							LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_1
							LED6_1
							LED7_1
							_delay_ms(zeit2);// 8
							
							LED1_1
							LED2_1
							LED3_1
							LED4_0
							LED5_0
							LED6_0
							LED7_0
							_delay_ms(zeit2);// 7
							
							LED1_1
							LED2_0
							LED3_1
							LED4_1
							LED5_1
							LED6_1
							LED7_1
							_delay_ms(zeit2);// 6
							
							LED1_1
							LED2_0
							LED3_1
							LED4_1
							LED5_0
							LED6_1
							LED7_1
							_delay_ms(zeit2);// 5
							
							LED1_0
							LED2_1
							LED3_1
							LED4_0
							LED5_0
							LED6_1
							LED7_1
							_delay_ms(zeit2);// 4
							
							LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_0
							LED6_0
							LED7_1
							_delay_ms(zeit2);// 3
							
							LED1_1
							LED2_1
							LED3_0
							LED4_1
							LED5_1
							LED6_0
							LED7_1
							_delay_ms(zeit2);// 2
							
							LED1_0
							LED2_1
							LED3_1
							LED4_0
							LED5_0
							LED6_0
							LED7_0
							_delay_ms(zeit2);// 1
							
							LED1_1
							LED2_1
							LED3_1
							LED4_1
							LED5_1
							LED6_1
							LED7_0
							_delay_ms(zeit2);// 0
							
							p = 0;
							
							break;
							
			}
			

	}//end of while
	
	return 0;
}//end of main