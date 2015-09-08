/*
 * pot.c
 *
 *  Created on: Sep 7, 2015
 *      Author: Michael
 */
#include <avr/io.h>


/**
 * @brief Find the angle of the given potentiometer.
 * @param  pot The pot to check.
 * @return angle Angle of the potentiometer.
 *
 * @todo Calculate the angle using the ADC reading.
 */
int potAngle(int pot){
	//clears ADC registers
	clearADC(pot);
	//initADC
	initADC(pot);
	unsigned short result;
	//reads ADC
	result = getADC(pot);
	int angle;
	//converts adc value to mV (*2.5) then to degrees using guessed value of (.068degrees/mV)
	angle = result * 0.17;
	return angle;
}

/**
 * @brief Find the voltage value of the given potentiometer.
 * @param  pot The pot to get the value of.
 * @return volts Voltage of  potentiometer.
 *
 * @todo Convert the ADC value into a voltage in mV (so no floats needed).
 */
int potVolts(int pot){
	//clears ADC
	clearADC(pot);
	//initADC
	initADC(pot);
	unsigned short result;
	//reads ADC
	result = getADC(pot);
	int mV;
	//converts adc value to mV
	mV = result * 2.5;
	return mV;
}
