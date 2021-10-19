/* 
 * File:   Touchscreen.h
 * Author: andersow
 *
 * Created on October 19, 2021, 1:40 PM
 */

#ifndef TOUCHSCREEN_H
#define	TOUCHSCREEN_H

#include <stdint.h>

typedef short int16_t;
typedef unsigned short uint16_t;
//typedef char int8_t;
typedef unsigned char uint8_t;

//Assuming Port A for all
#define XPbit BIT_4
#define XMbit BIT_0
//XM ADC position
#define XMAN 0
#define YPbit BIT_1
//YP ADC position
#define YPAN 1
#define YMbit BIT_3

//resistance between X+ and X- terminals
//measure for specific device
#define RXPLATE 275

struct TSPoint {
  int16_t x, y, z;
};

void setTSPoint(struct TSPoint * p, int16_t x0, int16_t y0, int16_t z0);

 
/*uint16_t pressure(void);
int readTouchY();
int readTouchX();*/
void getPoint(struct TSPoint * p);

#endif	/* TOUCHSCREEN_H */

