
#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
#include "portb_out.h"

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

main() {
 uint8_t in;
 uint16_t out;
 porta_in_init();
 portb_out_init();
 while (1) {
 in = porta_in_read();
 switch(in){
     case 0x00: out = 0x0001; break;
     case 0x01: out = 0x0002; break;
     case 0x02: out = 0x0004; break;
     case 0x03: out = 0x0008; break;
     case 0x04: out = 0x0010; break;
     case 0x05: out = 0x0020; break;
     case 0x06: out = 0x0040; break;
     case 0x07: out = 0x0080; break;
     case 0x08: out = 0x0100; break;
     case 0x09: out = 0x0200; break;
     case 0x0A: out = 0x0400; break;
     case 0x0B: out = 0x0800; break;
     case 0x0C: out = 0x1000; break;
     case 0x0D: out = 0x2000; break;
     case 0x0E: out = 0x4000; break;
     case 0x0F: out = 0x8000; break;
 }
 portb_out_write(out);
 }
}