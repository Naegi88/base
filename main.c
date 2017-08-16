#include <stdlib.h>
#include <avr/io.h>
#include "lcd.h"   //" = Lib in akt Projektverzeichnis
#include <avr/interrupt.h>


#define F_CPU 80000000UL

#define Aktivierungstaster !(PINC & (1<<PC0))
#define Codeschalter !(PINC & (1<<PC1))
#define Tuerkontakt !(PINC & (1<<PC2))

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
char state = AUS;




int main(void)
{

	
	DDRD = 0xFF;
	DDRB = 0xFF;//Ausgängesetzen
	DDRC = 0x00;//Eingangsetzten
	
	PORTB |= (1<<PD2);// Hintergrundbeleuchtung
	
	
	PORTC |= (1<<PD0);
	PORTC |= (1<<PD1);
	PORTC |= (1<<PD2);//Pull Up Widerstand
	
	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);  // initialisieren		
	lcd_clrscr();
	
	
	lcd_gotoxy(3,1);
	lcd_puts("Ausgeschaltet");

	while(1)
	{
	
	
		
	switch(state)
	{
		case AUS:			if(Aktivierungstaster)
								{
									state = SCHARF;
									
									lcd_clrscr();
								lcd_gotoxy(6,0);
								lcd_puts("AKTIV!");
								lcd_gotoxy(8,1);
								lcd_puts("und");
								lcd_gotoxy(6,2);
								lcd_puts("SCHARF");
								}
								
								beeper1_0;
								led1_0;
								led2_1;
			break;
			
		case SCHARF:		if(Codeschalter)
								{
									state = AUS;
									
									lcd_clrscr();
								lcd_gotoxy(3,1);
								lcd_puts("Ausgeschaltet");
								}
								
							if(Tuerkontakt)
								{
									state = ALARM;
									
									lcd_clrscr();
								lcd_gotoxy(6,1);
								lcd_puts("ALARM!");
								
								}
								
								beeper1_0;
								led2_0;
								o++;
								if(o>120000)
								{
									led1_1;
								}
								
								if(o==129000)
								{
									led1_0;
									o = 0;
								}
			break;			
			
		case ALARM:				if(Codeschalter)
								{
									state = AUS;
									
								lcd_clrscr();
								lcd_gotoxy(3,1);
								lcd_puts("Ausgeschaltet");
								beeper1_0;
								
								}
								
								
								
								if(p<30000)
								{
									led2_0;
									led1_1;
									beeper1_1;
									p++;
								}
								
								if(p>29999)
								{
									led1_0;
									led2_1;
									beeper1_0;
									p++;
								}
								
								if(p==60000)
								{
									p=0;
								}
			break;
	}
	}
	return 0;
}//end of main


