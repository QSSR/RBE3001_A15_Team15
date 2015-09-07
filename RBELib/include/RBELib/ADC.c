/*
 * ADC.c
 *
 *  Created on: Sep 7, 2015
 *      Author: Michael
 */

#include <avr/io.h>



/**
 * @brief Initializes the ADC and make one channel active.
 * You can choose to use either interrupts or polling to read
 * the desired channel.
 *
 * @param channel The ADC channel to initialize.
 *
 * @todo Create the corresponding function to initialize the ADC
 * using the channel parameter.
 */
void initADC(int channel){

	//enables global interrupts
	SREG |= 0x80;
	unsigned char x = 0x00;
	int i = 0;
	//takes int channel and produces hex equivalent for ADMUX
	while(channel != i){
		x++;
		i++;
	}
	//set Vref to 2.56V
	//not left adjusted
	//connects to proper channel
	ADMUX = 0xC0 | x;
	//turns ADC on, sets to single conversion and enables interrupt flag
	//prescaler set to 2
	ADCSRA = 0x88;




}

/**
 * @brief Disables ADC functionality and clears any saved values (globals).
 *
 * @param channel  The ADC channel to disable.
 *
 * @todo Create the corresponding function to clear the last ADC
 * calculation register and disconnect the input to the ADC if desired.
 */
void clearADC(int channel){


	//nothing done with channel..... have to figure that out
	unsigned char x = 0x00;
	int i = 0;
	//takes int channel and produces hex equivalent for ADMUX
	while(channel != i){
		x++;
		i++;
	}
	//turns off ADC
	//stopping any conversion underway
	ADCSRA = 0;
	//clears data registers H and L
	ADCL = 0;
	ADCH = 0;
}
/**
 * @brief Run a conversion on and get the analog value from one ADC
 * channel if using polling.
 *
 * @param channel  The ADC channel to run a conversion on.
 * @return adcVal The 8-10 bit value returned by the ADC
 * conversion.  The precision depends on your settings and
 * how much accuracy you desire.
 *
 * @todo Create the corresponding function to obtain the value of the
 * last calculation if you are using polling.
 */
unsigned short getADC(int channel){
	unsigned short result;
	unsigned char x = 0x00;
	int i = 0;
	//takes int channel and produces hex equivalent for ADMUX
	while(channel != i){
		x++;
		i++;
	}
	//clears input channel in there
	ADMUX &= 0xE0;
	//connects to input channel
	ADMUX |= x;
	//start conversion
	ADCSRA |= 0x40;
	//wait for interrupt flag to say conversion is complete
	while(!(ADIF));
	//shift ADCH up 8 and ors with ADCL
	result = (ADCH << 8) | ADCL;
	return result;

}

/**
 * @brief Change the channel the ADC is sampling if using interrupts.
 *
 * @param channel  The ADC channel to switch to.
 *
 * @todo Create a way to switch ADC channels if you are using interrupts.
 */
void changeADC(int channel){
	unsigned char x = 0x00;
	int i = 0;
	//takes int channel and produces hex equivalent for ADMUX
	while(channel != i){
		x++;
		i++;
	}
	//clears input channel in there
	ADMUX &= 0xE0;
	//connects to input channel
	ADMUX |= x;
}

