/* 
 * File:   main.c
 * Author: andersow
 *
 * Created on September 14, 2021, 1:53 PM
 */

#include <xc.h>
#include <inttypes.h>
#include "porta_init.h"
#include "portb_init.h"
#include "timer1.h"

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#define PWM_MS 25
//#define GAME_MS 400

uint16_t gameSpeed;

uint8_t l_btn_pushed = 0x03;
uint8_t r_btn_pushed = 0x03;

main() {
    
uint8_t in;
uint16_t out;
uint16_t ta1, ta2, tb1, tb2;
timer1_init();
porta_in_init();
portb_out_init();
game_init_func();
uint8_t decNumber;
rightdb_init_func();
leftdb_init_func();
LATB = 0x0000;
ta1 = ta2 = timer1_read();

while(1){
    ta2 = tb2 = timer1_read();
    in = porta_in_read();
    
    if (timer1_ms_elapsed(ta1, ta2) > PWM_MS) {
            l_btn_pushed = left_db_check(in);
            r_btn_pushed = right_db_check(in);
            ta1 = ta2;
    }
    
    if (timer1_ms_elapsed(tb1, tb2) > gameSpeed) {
    
            decNumber = game_run();
            
            gameSpeed = get_gameSpeed();
        
             switch(decNumber) {
             case 0x00: out = 0x0000; break;
             case 0x01: out = 0x0001; break;
             case 0x02: out = 0x0002; break;
             case 0x03: out = 0x0004; break;
             case 0x04: out = 0x0008; break;
             case 0x05: out = 0x0010; break;
             case 0x06: out = 0x0020; break;
             case 0x07: out = 0x0040; break;
             case 0x08: out = 0x0080; break;
        }
             portb_out_write(out);
             tb1 = tb2;
        }         
    }
    
}    

 
