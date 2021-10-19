/* 
 * File:   ts_lcd.h
 * Author: andersow
 *
 * Created on October 19, 2021, 1:55 PM
 */

#ifndef TS_LCD_H
#define	TS_LCD_H

#include <inttypes.h>

uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y);

void ts_lcd_init();

#endif	/* TS_LCD_H */

