
#include "motorInterface.h"
#include <xc.h>
#include "plib.h"

static int enable1;

void enable_1(){
     PORTSetBits(IOPORT_A, BIT_2);
}

void disable_1(){
    PORTClearBits(IOPORT_A, BIT_2);
}

void enable_2(){
     PORTSetBits(IOPORT_B, BIT_10);
}

void disable_2(){
    PORTClearBits(IOPORT_B, BIT_10);
}


void motorSetup(){
    
    mPORTBSetPinsDigitalOut(BIT_3 | BIT_4 | BIT_5 | BIT_7); 
    mPORTASetPinsDigitalOut(BIT_2); 
    mPORTBSetPinsDigitalOut(BIT_8 | BIT_9 | BIT_10 | BIT_13 | BIT_15);
    
}

void moveMotor(){
    
  
    
}
