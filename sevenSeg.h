/*
 * sevenSeg_BCD.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Sprints
 */

#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#include "gpio.h"
#include "sevenSegConfig.h"

/************************************************************************/
/*				 Enum for defining segments                          */
/************************************************************************/
typedef enum En_SevenSegId_t{
	SEG_0,
	SEG_1,
}En_SevenSegId_t;

/**
 * Description: 
 * @param Intialize the pins for the seven-segment and takes the following values
 *						- 0 -> SEG_0
 * 						- 1 -> SEG_1				
 */
void sevenSegInit(En_SevenSegId_t a_segment_id);

/**
 * Description: 
 * @param Enable the the selected seven-segment and takes the following values
 *						- 0 -> SEG_0
 * 						- 1 -> SEG_1
 */
void sevenSegEnable(En_SevenSegId_t en_segment_id);

/**
 * Description: 
 * @param Disable the the selected seven-segment and takes the following values
 *						- 0 -> SEG_0
 * 						- 1 -> SEG_1
 */
void sevenSegDisable(En_SevenSegId_t en_segment_id);

/**
 * Description: 
 * @param Write digit to the selected seven-segment and takes the following values Segment ID and uint8 number
 *						- 0 -> SEG_0
 * 						- 1 -> SEG_1
 */
void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number);


#endif /* SEVENSEG_BCD_H_ */
