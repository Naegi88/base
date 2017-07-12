#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL					//Zeit definiert

#define TASTE1 !(PINB & (1<<PB1))		//Taster1
#define TASTE2 !(PINB & (1<<PB2))		//Taster2
#define TASTE3 !(PINB & (1<<PB3))		//Taster3

#define LED0_AUS PORTD &= ~(1<<PD0);	//löscht bit PD0
#define LED0_EIN PORTD |= (1<<PD0);		//setzt PD0

#define LED1_AUS PORTD &= ~(1<<PD1);	//löscht bit PD1
#define LED1_EIN PORTD |= (1<<PD1);		//setzt PD1

#define LED2_AUS PORTD &= ~(1<<PD2);	//löscht bit PD2
#define LED2_EIN PORTD |= (1<<PD2);		//setzt PD2

#define LED3_AUS PORTD &= ~(1<<PD3);	//löscht bit PD3
#define LED3_EIN PORTD |= (1<<PD3);		//setzt PD3

#define LED4_AUS PORTD &= ~(1<<PD4);	//löscht bit PD4
#define LED4_EIN PORTD |= (1<<PD4);		//setzt PD4

#define LED5_AUS PORTD &= ~(1<<PD5);	//löscht bit PD5
#define LED5_EIN PORTD |= (1<<PD5);		//setzt PD5

#define LED6_AUS PORTD &= ~(1<<PD6);	//löscht bit PD6
#define LED6_EIN PORTD |= (1<<PD6);		//setzt PD6

#define LED7_AUS PORTD &= ~(1<<PD7);	//löscht bit PD7
#define LED7_EIN PORTD |= (1<<PD7);		//setzt PD7

int main(void)
{
	
	DDRD = 0xFF;						//Port D als Ausgang setzen
	PORTD = 0x00;						// alle Pins an Port D auf high setzen
	
	
	DDRB &= ~(1<<PB1);					//Eingang1
	PORTB |= (1<<PB1);					//Pull-up Widerstand
	DDRB &= ~(1<<PB2);					//Eingang2
	PORTB |= (1<<PB2);					//Pull-up Widerstand
	DDRB &= ~(1<<PB3);					//Eingang2
	PORTB |= (1<<PB3);					//Pull-up Widerstand
	
	
	
	
	short zeita=200;
	short zeitb=25;
	
	while(1) {
	
		if(TASTE2){
		
			if(TASTE1){
			
			LED0_EIN;
			
			_delay_ms(zeita);
			
			
			LED0_AUS;
			LED1_EIN;
			
			
			_delay_ms(zeita);		
			
			
			LED1_AUS;
			LED2_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED2_AUS;
			LED3_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED3_AUS;
			LED4_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED4_AUS;
			LED5_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED5_AUS;
			LED6_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED6_AUS;
			LED7_EIN;
			
			
			_delay_ms(zeita);
			
			LED7_AUS;
			
			}
			
			else{

			LED0_EIN;
			
			_delay_ms(zeitb);
			
			
			LED0_AUS;
			LED1_EIN;
			
			
			_delay_ms(zeitb);		
			
			
			LED1_AUS;
			LED2_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED2_AUS;
			LED3_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED3_AUS;
			LED4_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED4_AUS;
			LED5_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED5_AUS;
			LED6_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED6_AUS;
			LED7_EIN;
			
			
			_delay_ms(zeitb);
			
			LED7_AUS;
			
			}
		}
		
		else{
			
			if(TASTE1){
			
			LED7_EIN;
			
			_delay_ms(zeita);
			
			
			LED7_AUS;
			LED6_EIN;
			
			
			_delay_ms(zeita);		
			
			
			LED6_AUS;
			LED5_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED5_AUS;
			LED4_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED4_AUS;
			LED3_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED3_AUS;
			LED2_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED2_AUS;
			LED1_EIN;
			
			
			_delay_ms(zeita);
			
			
			LED1_AUS;
			LED0_EIN;
			
			
			_delay_ms(zeita);
			
			LED0_AUS;
			
			}
			
			else{

			LED7_EIN;
			
			_delay_ms(zeitb);
			
			
			LED7_AUS;
			LED6_EIN;
			
			
			_delay_ms(zeitb);		
			
			
			LED6_AUS;
			LED5_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED5_AUS;
			LED4_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED4_AUS;
			LED3_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED3_AUS;
			LED2_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED2_AUS;
			LED1_EIN;
			
			
			_delay_ms(zeitb);
			
			
			LED1_AUS;
			LED0_EIN;
			
			
			_delay_ms(zeitb);
			
			LED0_AUS;
			
			}
			
		}
		
	}//end of while
	
	return 0;
}//end of main
