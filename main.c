#include <stdlib.h>
#include <avr/io.h>
#include "lcd.h"   //" = Lib in akt Projektverzeichnis
#include <avr/interrupt.h>



#define F_CPU 8000000UL

#define Aktivierungstaster !(PINC & (1<<PC0))
#define Tuerkontakt !(PINC & (1<<PC1))
#define Atom !(PINC & (1<<PC5))
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
long ms = 0;
int ms_10 = 0;
long sec = 0;
long x = 0;
long y = 0;
uint16_t ISR_zaeler;			//definiere variabel

ISR (TIMER0_OVF_vect)			//Timer
{
	TCNT0 = 0;
	ISR_zaeler++;
	if(ISR_zaeler== 1)
	{
		ISR_zaeler=0;
		ms++;
	}
	
	if(ms==10)
	{
		ms = 0;
		ms_10++;
	}
	
}			//end uf ISR



int main(void)
{
	TCCR0A		= 0x00;
	TCCR0B		= 0x02;
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
	int  signal; 
	int  signal_alt;			// daklaration DCF77 Signal
	

	while(1)
	{
		

		signal = PINC & (1<<PC5);  // Signal einlesen

		if ((signal!=signal_alt) && (o==0))
		 {
		  y = ms_10;
		  ms_10 = 0;
		  
		  
		  o++;			//Sicherstelung das dieses if nur einmal pasiert
		  signal_alt = signal;			//gleichstelung
		  
		 lcd_gotoxy(0,1);
		 lcd_puts("      ");			//Bildschirm Leeren
		 
		 lcd_gotoxy(0,1);
		 lcd_count_16(y);			//Ausgabe der pausen zeit
		 beeper1_0;
		 
		 }
		 
		 if ((signal!=signal_alt) && (o ==1))
		 {
		  x = ms_10;
		  ms_10 = 0;
		  sec++;
		  
		  o--;			//Sicherstelung das dieses if nur einmal pasiert
		  signal_alt = signal;			//gleichstelung
		  
		 lcd_gotoxy(0,0);
		 lcd_puts("    ");			//Bildschirm Leeren
		 
		 lcd_gotoxy(0,0);
		 lcd_count_16(x);			//ausgabe des Logischen 1
		 
		 lcd_gotoxy(10,2);
		 lcd_count_16(sec);			//sec ausgabe
		 }
		
		
		 if(y>400)
		 {
		 
		  lcd_gotoxy(10,2);
		  lcd_puts("  ");			//Bildschirm Leeren
		 
			sec = 0;			//Bei einer minute sec reseten
			
			beeper1_1;
		 }
		
		 
		 
		 
	}
	
	
	
	
	return 0;
}//end of main

