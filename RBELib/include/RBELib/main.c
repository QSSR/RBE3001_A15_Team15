/*
 * main.c
 *
 *  Created on: Sep 7, 2015
 *      Author: Michael
 */
#include "RBELib/RBELib.h"

#define count 0
#define time 0

ISR(TIMER0_COMP_vect){
	count++;
}
void main(){
	int potInput = 0,mVpot,anglePot,valueADC;
	initTimer(0,NORMAL,2);
	if(count >= 10){
		time++;
		valueADC = getADC(potInput);
		anglePot = potAngle(potInput);
		mVpot = potVolts(potInput);
		count = 0;
	}
	printf(time);
	printf("\n",valueADC);
	printf("\n",anglePot);
	printf("\n",mVpot);



}
