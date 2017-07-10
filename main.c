#include <stdlib.h>
#include <avr/io.h>


#define LED1_Aus PORTD &= ~(1<<PD1);
#define LED1_Ein PORTD |= (1<<PD1);

int main(void)
{
DDRD = 0xFF;//Port D als Ausgag setzen

	PORTD = 0xFF;
	
	LED1_Aus;//LED 1 Ausschalten
	
	
	while(1)
	{

	}//end of while
	
	return 0;
}//end of main