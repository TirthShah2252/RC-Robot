#include <stdio.h>  
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/sfr_defs.h>
#define ubrr 12
void initialise ()                                   //initializing UART
{
	UBRRH = (12>>8);                //set baut rate = 9600
	UBRRL = 12;
	UCSRB = 0b00011000 ;                   // enabling receiver and transmitor
	UCSRC = 0b10000110;                              //asynchronous and 1 stop bits and 8bit data
	
}

void letter(unsigned char x)                          //send letter
{
	while(!((UCSRA) & (1<<UDRE)));                   //waiting for buffer to get empty
	UDR=x;                                           //transfer data from x to udr

}


	int main()
	{//UCSRB=0x00;
	//UCSRC=0x00;
		
		initialise();
		//DDRD=0xFF;
		while (1) 
		{
		
			
	    if (bit_is_set(PINA,0))
			
			{
				letter ('d');
				_delay_ms(100);
			}
			//PORTD=(1<<PD0)|(1<<PD1);
		else if (bit_is_set(PINA,3))
			
			{
				letter ('f');
			}
		else if (bit_is_set(PINA,5))
		  
		  {
			  letter ('r');
		  }
		  
		   else if(bit_is_set(PINA,7))
		   
		  
		  {
			  letter ('l');
		  }
		  else 
		  {
			  letter('n');
			  _delay_ms(100);
		  }
		/*letter ('s');
		_delay_ms(100);*/
		
		
		}
		return 0;
		
	}

   