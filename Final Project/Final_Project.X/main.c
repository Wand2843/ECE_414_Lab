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
#include "motorInterface.h"


#define XM AN0
#define YP AN1

uint8_t numberClicked;

/*
 * 
 */
int main(int argc, char** argv) {
    char buffer[30];
    char buffer1[30];
    char buffer2[30];
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
    setupGfx();
   
    INTEnableSystemMultiVectoredInt();
    
    motorSetup();
    motorFSM_init();
    
    
    zTimerOn();
    zTimerSet(40);
        
    //enable_1();
    
    int ctr;
    ctr = 0;
    int ctr2;
    ctr2 = 0;
      
    while(1){
        
        uint8_t forward1 = getMotor1Forward();
        uint8_t backward1 = getMotor1Backward();
        uint8_t forward2 = getMotor2Forward();
        uint8_t backward2 = getMotor2Backward();
        
        if(zTimerReadFlag() && (forward1 || backward1 || forward2 || backward2)){
        
        if(ctr == 4) ctr = 0;    
            
        if(ctr==0 && backward1){    
        PORTSetBits(IOPORT_B, BIT_7 | BIT_3);
        PORTClearBits(IOPORT_B, BIT_4 | BIT_5);
        }
        else if (ctr ==1 && backward1) {
        PORTSetBits(IOPORT_B, BIT_3 | BIT_5);
        PORTClearBits(IOPORT_B, BIT_4 | BIT_7);
        }
        else if (ctr ==2 && backward1) {
        PORTSetBits(IOPORT_B, BIT_4 | BIT_5);
        PORTClearBits(IOPORT_B, BIT_3 | BIT_7);
        }
        else if (ctr ==3 && backward1) {
        PORTSetBits(IOPORT_B, BIT_7 | BIT_4);
        PORTClearBits(IOPORT_B, BIT_3 | BIT_5);
        }
        else if(ctr==0 && forward1){    
        PORTSetBits(IOPORT_B, BIT_7 | BIT_4);
        PORTClearBits(IOPORT_B, BIT_3 | BIT_5);
        }
        else if (ctr ==1 && forward1) {
        PORTSetBits(IOPORT_B, BIT_4 | BIT_5);
        PORTClearBits(IOPORT_B, BIT_3 | BIT_7);
        }
        else if (ctr ==2 && forward1) {
        PORTSetBits(IOPORT_B, BIT_3 | BIT_5);
        PORTClearBits(IOPORT_B, BIT_4 | BIT_7);
        }
        else if (ctr ==3 && forward1) {
        PORTSetBits(IOPORT_B, BIT_7 | BIT_3);
        PORTClearBits(IOPORT_B, BIT_4 | BIT_5);
        }
         else if(ctr==0 && forward2){    
        PORTSetBits(IOPORT_B, BIT_13 | BIT_8);
        PORTClearBits(IOPORT_B, BIT_9 | BIT_15);
        }
        else if (ctr ==1 && forward2) {
        PORTSetBits(IOPORT_B, BIT_13 | BIT_9);
        PORTClearBits(IOPORT_B, BIT_8 | BIT_15);
        }
        else if (ctr ==2 && forward2) {
        PORTSetBits(IOPORT_B, BIT_15 | BIT_9);
        PORTClearBits(IOPORT_B, BIT_8 | BIT_13);
        }
        else if (ctr ==3 && forward2) {
        PORTSetBits(IOPORT_B, BIT_15 | BIT_8);
        PORTClearBits(IOPORT_B, BIT_9 | BIT_13);
        }
        else if(ctr==0 && backward2){    
        PORTSetBits(IOPORT_B, BIT_15 | BIT_8);
        PORTClearBits(IOPORT_B, BIT_9 | BIT_13);
        }
        else if (ctr ==1 && backward2) {
          PORTSetBits(IOPORT_B, BIT_15 | BIT_9);
        PORTClearBits(IOPORT_B, BIT_8 | BIT_13);
        }
        else if (ctr ==2 && backward2) {
         PORTSetBits(IOPORT_B, BIT_13 | BIT_9);
        PORTClearBits(IOPORT_B, BIT_8 | BIT_15);
        }
        else if (ctr ==3 && backward2) {
        PORTSetBits(IOPORT_B, BIT_13 | BIT_8);
        PORTClearBits(IOPORT_B, BIT_9 | BIT_15);
        }
        ctr = ctr + 1;    
        }   

        
        // tft_fillScreen(ILI9341_BLACK);
         tft_setCursor(20, 20);
         tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);
        
        
        

       // erase old text
        tft_setTextColor(ILI9341_BLACK);
        tft_writeString(buffer);
        
       struct TSPoint lcd;
        lcd.x = 0;
        lcd.y = 0;
        lcd.z = 0;
        
          uint8_t touched = ts_lcd_get_ts(&lcd.x , &lcd.y);
          if (lcd.y < 0) lcd.y = 0;
          if ((lcd.x > 180 && lcd.x < 195) && lcd.y == 0) lcd.x = 0;
          if (lcd.x > 300) lcd.x = 0;
          if (touched == 0) {
              lcd.x = 0;
              lcd.y = 0;
          }
          
        motor_run(touched, lcd.x, lcd.y);
        
        tft_setCursor(20, 20);
        tft_setTextColor(ILI9341_WHITE);
        sprintf(buffer,"x: %d, y: %d, z: %d", lcd.x, lcd.y, touched);
        //tft_writeString(buffer);
        
        

        tft_setCursor(20, 20);
        tft_setTextColor(ILI9341_WHITE);
        sprintf(buffer2, "Solar Controller UI");
        tft_writeString(buffer2);
        
        tft_setCursor(20, 200);
        tft_setTextColor(ILI9341_WHITE);
        sprintf(buffer1, "Voltage:");
        tft_writeString(buffer1);
    
    
        //delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}






