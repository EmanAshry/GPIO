/*
 * GPIO_REQ9.c
 */ 
#include "led.h"
#include "softwareDelay.h"

typedef enum LED_State{
	GO,
	STOP,
	GET_READY
}EN_LED_State;


int main(void)
{
	
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);

	EN_LED_State LED_State = GO;
	
	while(1)
	{
		switch (LED_State)
		{
			case GO:
			Led_On(LED_0);
			Led_Off(LED_1);
			Led_Off(LED_2);
			LED_State = STOP;
			softwareDelayMs(1000);
			break;
			case STOP:
			Led_On(LED_2);
			Led_Off(LED_0);
			Led_Off(LED_1);
			LED_State = GET_READY;
			softwareDelayMs(1000);
			break;
			case GET_READY:
			Led_On(LED_1);
			Led_Off(LED_0);
			Led_Off(LED_2);
			LED_State = GO;
			softwareDelayMs(1000);
			break;
		}
	}
	return 0;
}
