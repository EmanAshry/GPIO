/*
 * pushButton.c
 */ 

#include "pushButtonConfig.h"
#include "pushButton.h"

void pushButtonInit(En_buttonId_t en_butotn_id)
{
	switch (en_butotn_id)
	{
	case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		break;
	case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		break;
	case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		break;
	case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		break;
	}
}

En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
	En_buttonStatus_t Btn_Status= Released;
	
	switch (en_butotn_id)
	{
		case BTN_0:
		Btn_Status = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		break;
		case BTN_1:
		Btn_Status = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		break;
		case BTN_2:
		Btn_Status = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		break;
		case BTN_3:
		Btn_Status = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		break;
	}
	
	softwareDelayMs(30);
	
	switch (en_butotn_id)
	{
		case BTN_0:
		Btn_Status = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		break;
		case BTN_1:
		Btn_Status = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		break;
		case BTN_2:
		Btn_Status = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		break;
		case BTN_3:
		Btn_Status = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		break;
	}
	
	return Btn_Status;
}