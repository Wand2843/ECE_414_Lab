/* 
 * File:   touch_main.c
 * Author: watkinma
 *
 * Description: Prints out the detected position (x, y) of a press on the
 * touchscreen as well as the pressure (z).
 * 
 * IMPORTANT: For this example to work, you need to make the following 
 * connections from the touchpad to the PIC32:
 *  Y+ => AN1 (Pin 3)
 *  Y- => RA3 (Pin 10)
 *  X+ => RA4 (Pin 12)
 *  X- => AN0 (Pin 2)
 * 
 */

#include <xc.h>
#include <plib.h>
#include "config.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "ts_lcd.h"


#define XM AN0
#define YP AN1

/*
 * 
 */
int main(int argc, char** argv) {
    char buffer[30];
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    ts_lcd_init();
    tft_fillScreen(ILI9341_BLACK);  
    
    while(1){
        //tft_fillScreen(ILI9341_BLACK);
        tft_setCursor(20, 100);
        tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);

        //erase old text
        tft_setTextColor(ILI9341_BLACK);
        tft_writeString(buffer);
        
        struct TSPoint lcd;
        lcd.x = 0;
        lcd.y = 0;
        lcd.z = 0;
        
        uint8_t touched = ts_lcd_get_ts(&lcd.x , &lcd.y);
        if (lcd.y < 0) lcd.y = 0;
        tft_setCursor(20, 100);
        tft_setTextColor(ILI9341_WHITE);
        sprintf(buffer,"x: %d, y: %d, z: %d", lcd.x, lcd.y, lcd.z);
        tft_writeString(buffer);
    
        delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}


