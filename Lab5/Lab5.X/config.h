/* 
 * File:   config.h
 * Author: andersow
 *
 * Created on October 19, 2021, 1:37 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

// Configure clock
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#endif	/* CONFIG_H */

