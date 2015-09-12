#include <RBELib/RBELib.h>
//Globals
//Timer0
volatile unsigned long counter = 0;
volatile unsigned long millisecond = 0;
//ADC
volatile int ADCval = 0;

//Timer ISR
ISR(TIMER0_OVF_vect){
  //Using a prescaler of 8
  // ((18432000 / 8) / 256) / 1000 = 9 interrupts in a ms
  counter++;
  if(counter >= 9){
    millisecond++;
    counter = 0;
  }
}

//ADC ISR
ISR(ADC_vect){

  //Combine the two values into a 10-bit result
  ADCval = ADCW;
}
