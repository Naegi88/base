#include <stdlib.h>
#include <avr/io.h>
#include "lcd.h"   //" = Lib in akt Projektverzeichnis
#include <avr/interrupt.h>



#define F_CPU 8000000UL

#define Aktivierungstaster !(PINC & (1<<PC0))
#define Tuerkontakt !(PINC & (1<<PC1))
#define taster0 !(PINC & (1<<PC5))
#define taster1 !(PINC & (1<<PC2))
#define taster2 !(PINC & (1<<PC3))
#define taster3 !(PINC & (1<<PC4))

#define led1_1 (PORTB |= (1<<PB4))
#define led1_0 (PORTB &= ~(1<<PB4))
#define led2_1 (PORTB |= (1<<PB5))
#define led2_0 (PORTB &= ~(1<<PB5))
#define beeper1_1 (PORTB |= (1<<PB6))
#define beeper1_0 (PORTB &= ~(1<<PB6))

#define AUS		0
#define	SCHARF	1
#define ALARM	2

long o = 0;
long p = 0;
char min = 2;
char state = AUS;
int ms_100 = 0;
long sec = 1;
uint16_t ISR_zaeler;

ISR (TIMER0_OVF_vect)
{
	TCNT0 = 0;
	ISR_zaeler++;
	if(ISR_zaeler== 13)
	{
		ISR_zaeler=0;
		ms_100++;
	}
	
	if(ms_100==10)
	{
		ms_100 = 0;
		sec++;
	}
	
}



int main(void)
{
	TCCR0A		= 0x00;
	TCCR0B		= 0x04;
	TIMSK0		|= (1<<TOIE0);
	TIFR0		|(1<<TOV0);
	sei();
	
	DDRD = 0xFF;
	DDRB = 0xFF;//Ausgängesetzen
	DDRC = 0x00;//Eingangsetzten
	
	PORTB |= (1<<PD2);// Hintergrundbeleuchtung
	
	
	PORTC |= (1<<PD0);
	PORTC |= (1<<PD1);
	PORTC |= (1<<PD2);
	PORTC |= (1<<PD3);
	PORTC |= (1<<PD4);
	PORTC |= (1<<PD5);//Pull Up Widerstand
	
	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);  // initialisieren		
	lcd_clrscr();
	
	

	while(1)
	{
	lcd_gotoxy(10,1);
	lcd_count_16(sec);
	}
	return 0;
}//end of main

