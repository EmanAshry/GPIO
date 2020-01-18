/*
 * softwareDelay.c
 */ 
#include "softwareDelay.h"

void softwareDelayMs(uint32_t u32_delay_in_ms)
{
	volatile uint8_t delay_counter;

	for(uint64_t i=0;i<(u32_delay_in_ms*13);i++)
	{
		delay_counter++;
	}
}