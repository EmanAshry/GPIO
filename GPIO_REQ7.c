
/*
 * GPIO_REQ7.c
 */ 
#include "sevenSeg.h"
#include "softwareDelay.h"

int main(void)
{
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);
	int counter =0;
	
	while (1)
	{
		for (int i=0;i<=9;i++)
		{
			for(int j=0; j<=9;j++)
			{
				counter =0;
				while(counter!=80)
				{
					
					sevenSegWrite(SEG_1,j);
					
					softwareDelayMs(5);
					
					sevenSegWrite(SEG_0,i);
					
					softwareDelayMs(5);
					counter++;
				}
			}
		}
}
return 0;
}