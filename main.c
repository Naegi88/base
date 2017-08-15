#include <stdlib.h>
#include <avr/io.h>
#include "lcd.h"   //" = Lib in akt Projektverzeichnis
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU    8000000
#endif

uint32_t x;
uint8_t y, richtung;

int main(void)
{
	DDRD=0xFF;
	PORTD = 0xFF;
	
	DDRB = 0xFF;
	PORTB = 0xFF;
	
	

	
	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);  // initialisieren		
	lcd_clrscr();
    lcd_gotoxy(6,0);
	lcd_puts("Start up");
	lcd_gotoxy(4,1);
	lcd_puts("Ruag Defence");
	lcd_gotoxy(3,2);
	lcd_puts("Silvan Naegeli");
	lcd_gotoxy(5,3);
	lcd_puts("15.08.2017");
	
	

						
	while(1)
	{
	
	

	}//end of while
	return 0;
}//end of main


