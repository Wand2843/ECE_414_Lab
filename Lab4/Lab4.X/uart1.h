/* 
 * File:   uart1.h
 * Author: andersow
 *
 * Created on October 5, 2021, 1:19 PM
 */

#ifndef UART1_H
#define	UART1_H
#include <inttypes.h>
void uart1_init(uint32_t baudrate);
uint8_t uart1_txrdy();
void uart1_txwrite(char c);
void uart1_txwrite_str(char *cp);
uint8_t uart1_rxrdy();
uint8_t uart1_rxread();
#endif	/* GAME_H */


