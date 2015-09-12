/*
 * main.c
 *
 *  Created on: Sep 7, 2015
 *      Author: Michael
 */
#include "RBELib/RBELib.h"
#include <avr/io.h>
volatile int count
volatile long time 0
#define low 45
#define high 90
#define comp 90


#define potInput 4
#define signalGen 1
int mVpot,anglePot,valueADC,flag,sampled = 0;

ISR(TIMER0_COMP_vect){
	count++;

}

void main(){
	//Question 2 in Lab
	//keep timer init for Question 6 and Question 7
	initTimer(0,NORMAL,2);
	if(count >= 10){
		time++;
		valueADC = getADC(potInput);
		anglePot = potAngle(potInput);
		mVpot = potVolts(potInput);
		count = 0;
	}
	printf("\n",time);
	printf("\n",valueADC);
	printf("\n",anglePot);
	printf("\n",mVpot);
/*
 *
	DDRD = 0x00; //Port D all pins input
	PORTD = 0x70; //all pull up
	MCUCR = 0x00;
	if(PIND4 == 0)
		flag = 1;
	while(flag && sampled != 255){
		//samples at around 255Hz
		if(count >= 40){
			time++;
			valueADC = getADC(potInput);
			anglePot = potAngle(potInput);
			mVpot = potVolts(potInput);
			count = 0;
			sampled++;
		}
	}
	if(sampled >= 255){
		flag = 0;
	}
	//print info
	printf("\n",time);
	printf("\n",valueADC);
	printf("\n",anglePot);
	printf("\n",mVpot);
*/

/*
 * Question 3 in Lab
	initPWM();
	initTimer(0,NORMAL,comp);
	//duty cycle equals 50% but about 100Hz
	if(PIND4 == 0){
		low = 45;
		high = 90;
	}
	//duty cycle 50% and 20Hz
	else if(PIND5 == 0){
		low = 225;
		high = 450;
	}
	//duty cycle 50% and 1 Hz
	else if(PIND6 == 0){
		low = 4482;
		high = 8964;
	}
	//depends on pot angle capability
	//assuming around 340 degree pot

	anglePot = potAngle(potInput);
	low = (anglePotV2 * high)/340;

	// low/high = duty cycle
	if(count >= low){
		PORTB = 0x00;
	}
	if(count >= high){
		PORTB = 0x01;
		count = 0;
	}
*/

/*
 * Question 7
	//get adc value from signal generator
	valueADC = getADC(signalGen);
	printf("\n",valueADC);
*/
}
void initPWM(){
	DDRB = 0x01; // Port B Pin 1 is output
	PORTB = 0x00; //start port b pin 1 in low
	DDRD = 0x00; //Port D all pins input
	PORTD = 0x70; //all pull up
	MCUCR = 0x00;
}
