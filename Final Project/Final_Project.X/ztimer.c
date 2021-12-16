

/*
 * File:   ztimer.h
 * Author: nestorj
 *
 * Created on September 5, 2019, 2:06 PM
 * Updated October 3, 2019 to use vectored interrupt.
 * This module implements a timer matching the functionality of the interrupt-
 * driven timer described in Section 4.5 of the Zybook "Programming Embedded
 * Systems".  A key difference is that the timer flag is encapsulated in the
 * module calling ReadTimerFlag returns its value and clears the flag.  This
 * means that we don't have to use a global variable to pass the flag.
 *
 * PIC32 Implementation details:
 * This module is implemented using Timer2 as a 16-bit counter and
 * assumes a 40MHz clock.  This updated version uses a vectored interrupt.
 * Note: since this version is intended to be used with multiple vectored
 * interrupts, the user of this (and other modules) should call
 * INTEnableSystemMultiVectoredInt() after initialization
 */

#include <xc.h>
#include <plib.h>
#include <inttypes.h>
#include "ztimer.h"

static uint32_t count, countms;
static uint32_t period, targetCount;

static uint8_t zTimerFlag = 0;


// Timer2 ISR
void __ISR(_TIMER_4_VECTOR, ipl2) Timer4ISR(void)
{
    count++;
    countms++;
    if (count == period-1) {
        zTimerFlag = 1;
        count = 0;
    }
    // clear the timer interrupt flag
    mT4ClearIntFlag();
}

// initialize timer to set a flag every given period (in ms)
void zTimerSet(uint32_t pdms) {
    period = pdms;
}

void zTimerOn() {
    // set up timer2 interrupt every 1ms with a 40MHz clock
    OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_8, 4999);
    ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_2);
    mT4ClearIntFlag(); // and clear the interrupt flag
    count = 0;
    countms = 0;
    zTimerFlag = 0;

}
void zTimerOff() {
    countms = 0;
    CloseTimer4();
}

// read and return the timer flag value
// SIDE EFFECT: clear the flag
uint8_t zTimerReadFlag() {
    if (zTimerFlag) {
        zTimerFlag = 0;
        return 1;
    } else return 0;
}

uint32_t zTimerReadms(){
    return countms; 
}

