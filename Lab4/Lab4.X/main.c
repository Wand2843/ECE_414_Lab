
#include <xc.h>
#include <inttypes.h>
#include "uart1.h"
#include <stdio.h>


#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

main() {
    
    uart1_init(1200);
    uint8_t transmitReady;
    uint8_t readReady;
    char c;
    
    while(1) {
        
        readReady = uart1_rxrdy();
        transmitReady = uart1_txrdy();
        
        if(readReady) c = uart1_rxread();
        
       // if(transmitReady) printf("%d", uart1_txwrite(c));
    }
    
}
