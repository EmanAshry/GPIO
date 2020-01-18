/*
 * GPIO_REQ8.c
 */ 

#include "led.h"
#include "pushButton.h"
#include "softwareDelay.h"

int main(void)
{
	En_buttonStatus_t previous_status = Released;
	En_buttonStatus_t Current_Status= Released;
	uint8_t Delay_limit = 0;
	uint8_t Presses_Count=0;

	pushButtonInit(BTN_0);
	Led_Init(LED_0);

	while(1)
	{
		
		Current_Status = pushButtonGetStatus(BTN_0);
		
		if(Current_Status)
		{
			previous_status = Pressed;
		}
		if(!Current_Status)
		{
			Delay_limit =0;
			while((previous_status==Pressed)&&(Delay_limit!=33))
			{
				Led_On(LED_0);
				
				if(pushButtonGetStatus(BTN_0))
				{
					if(!(pushButtonGetStatus(BTN_0)))
					{
						Presses_Count++;
					}
				}
				Delay_limit++;
			}
			softwareDelayMs(Presses_Count*500);
			Led_Off(LED_0);
			Presses_Count=0;
			previous_status = Released;
		}
	}
	return 0;
}
