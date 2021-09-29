
#include <xc.h>
#include <inttypes.h>
#include "porta_init.h"

void porta_in_init() {
    ANSELA = 0;
    TRISA = 0x03;
    CNPUA = 0x03;
}
uint8_t porta_in_read() {
    uint8_t data = PORTA;
    return data;
}

