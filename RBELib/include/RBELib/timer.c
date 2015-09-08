/*
 * timer.c
 *
 *  Created on: Sep 7, 2015
 *      Author: Michael
 */
#include <avr/io.h>

/**
 * @brief Initializes the specified timer in the specified mode. This
 * header file provides constants for NORMAL operation mode and
 * CTC operation mode, however there are many more modes of operation
 * for the Timers that can be experimented with.
 *
 * @param timer The number of the timer to be initialized (0-2).
 * @param mode The mode to initialize the specified timer in.
 * @param comp Only used in CTC mode. The value that the
 * timer counts to before it triggers an interrupt and resets.
 *
 * @todo Create a function that initializes the desired timer in a given mode and set the compare value
 * (as appropriate).
 */
void initTimer(int timer, int mode, unsigned int comp){
	//enables global interrupts
	SREG |= 0x80;
	if(timer == 0){

		if(mode == 0){
			TCCR0A = 0x00;
			TCCR0B = 0x01;
		}
		else if(mode == 1){
			TCCR0A = 0x02;
			TCCR0B = 0x01;
			OCR0A = comp;
		}
	}
	else if(timer == 1){
		if(mode == 0){
			TCCR1A = 0x00;
			//clock prescaler set to 8
			TCCR1B = 0x02;
		}
		else if(mode == 1){
			TCCR1B = 0x08;
			TCCR1B = 0x01;
			OCR1A = comp;
		}
	}
	else{
		if(mode == 0){
			TCCR2A = 0x00;
			TCCR2B = 0x01;
		}
		else if(mode == 1){
			TCCR2A = 0x02;
			TCCR2B = 0x01;
			OCR2A = comp;
		}
	}






}

/**
 * @brief Only used when the specified timer is in CTC mode. Changes
 * the value of the comparison register to the new specified value.
 *
 * @param timer The timer comparison value to change (0-2).
 * @param comp The value to set the comparison register to.
 *
 * @todo Create a function that will set a new compare value for the given timer.
 */
void setCompValue(unsigned char timer, unsigned short int comp){
	if(timer == 0){
		OCR0A = comp;
	}
	else if(timer == 1){
		OCR1A = comp;
	}
	else{
		OCR2A = comp;
	}
}
