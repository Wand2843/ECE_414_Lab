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

uint8_t numberClicked;

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
    
    setupGfx();
    
    calc_init_func();

    
    while(1){
        
        //tft_fillScreen(ILI9341_BLACK);
        tft_setCursor(20, 10);
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
        if ((lcd.x > 180 && lcd.x < 195) && lcd.y == 0) lcd.x = 0;
        numberClicked = numbClicked(lcd.x, lcd.y);
        calc_run(touched, numberClicked, lcd.x, lcd.y);
        uint64_t sum1 = getNumSum1();
        uint64_t sum2 = getNumSum2();
        uint32_t mainSum = getTotalSum();
        uint8_t display1 = getDisplaySum1();
        uint8_t display2 = getDisplaySum2();
        uint8_t displayResult = getDisplayResult();
        uint8_t displayError = getDisplayZero();
        
        tft_setCursor(20, 10);
        tft_setTextColor(ILI9341_WHITE);

        if(display1) {
            sprintf(buffer,"sum1: %d", sum1);
        }
        
        if(display2) {
            sprintf(buffer,"sum2: %d", sum2);
        }
        
        if(displayResult) {
            sprintf(buffer,"result: %d", mainSum);
        }
        
        if(displayError) {
            sprintf(buffer,"ERROR");
        }
        
      //  tft_setCursor(20, 10);
      //  sprintf(buffer,"sum1: %d, sum2: %d, result: %d", sum1, sum2, mainSum);
        
        tft_writeString(buffer);
    
        delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}


