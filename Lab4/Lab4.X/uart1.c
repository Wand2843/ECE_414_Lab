
#include <xc.h>
#include <inttypes.h>
#include <stdlib.h>
#include "uart1.h"
#include "plib.h"

void uart1_init(uint32_t baudrate){
    ANSELA = 0;
    TRISA = 0;
    baudrate = 40000000/(16*baudrate)-1;
    OpenUART1(UART_EN | UART_NO_PAR_8BIT | UART_1STOPBIT, 
              UART_TX_ENABLE | UART_TX_DISABLE, baudrate);
    PPSInput(3, U1RX, RPA2);
    PPSOutput(1, RPA0, U1TX);

}

uint8_t uart1_txrdy() {
    if(BusyUART1() == 0) {
        return 1;
    }
    else return 0;
   
}

void uart1_txwrite(char c) {
    WriteUART1(c);
}

void uart1_txwrite_str(char *cp) {
    char *p = cp;
    while (*p != '\0') p++;
    WriteUART1(p);
}

uint8_t uart1_rxrdy() {
    if(DataRdyUART1() == 0){
        return 0;
    }
    else return 1;
}

uint8_t uart1_rxread() {
    return ReadUART1();
}
