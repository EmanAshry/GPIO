/*
 * sevenSeg.c
 */ 

#include "sevenSegConfig.h"
#include "sevenSeg.h"

void sevenSegInit(En_SevenSegId_t a_segment_id)
{
	gpioPinDirection(SEG_BCD_GPIO,SEG_BCD_BITS,OUTPUT);
	switch (a_segment_id)
	{
	case SEG_0:
		gpioPinDirection(SEG_EN1_GPIO,SEG_EN1_BIT,OUTPUT);
		break;
	case SEG_1:
		gpioPinDirection(SEG_EN2_GPIO,SEG_EN2_BIT,OUTPUT);
		break;
	}
}

void sevenSegEnable(En_SevenSegId_t en_segment_id)
{
	switch (en_segment_id)
	{
	case SEG_0:
		gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,LOW);
		gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,HIGH);
		break;
	case SEG_1:
		gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,LOW);
		gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,HIGH);
		break;
	}
}

void sevenSegDisable(En_SevenSegId_t en_segment_id)
{
	switch (en_segment_id)
	{
	case SEG_0:
		gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,LOW);
		break;
	case SEG_1:
		gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,LOW);
		break;
	}
}

void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number)
{
	sevenSegEnable(en_segment_id);
	gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,LOW);
	gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,u8_number);
	
}