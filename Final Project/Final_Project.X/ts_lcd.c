

#include "ts_lcd.h"
#include <xc.h>
#include <plib.h>
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"

uint8_t pressed;

uint8_t getPressed(){
    return pressed;
}

uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y){
         
    uint32_t x1 = 125;
    uint32_t x2 = 900;
    uint32_t y2 = 960;  //original 960
    uint32_t y1 = 109;
    
    uint32_t x1_lcd = 0;
    uint32_t x2_lcd = 319;
    uint32_t y1_lcd = 0;
    uint32_t y2_lcd = 239;
    
        struct TSPoint p;
        p.x = 0;
        p.y = 0;
        p.z = 0;
        getPoint(&p);
       
        *y = ((p.x-x1)*(x2_lcd - x1_lcd))/(x2-x1)+ x1_lcd ;
        
        *x = ((p.y-y1)*(y2_lcd - y1_lcd))/(y2-y1)+ y1_lcd ; //((p.y-y1)*(y2_lcd - y1_lcd))/(y2-y1)+ y1_lcd ;
        
        if(p.z < 1){
            return 0x00;
            pressed = 0;
        }
        else {
            return 0x01;
            pressed = 1;
        
}
}

void ts_lcd_init(){

    //ANSELA = 0;
    //ANSELB = 0;
   // CM1CON = 0;
    //CM2CON = 0;
    
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    
}

uint8_t numbClicked(uint16_t lcd_x, uint16_t lcd_y){
    
    if((lcd_x < 214 && lcd_x > 171) && (lcd_y < 104 && lcd_y > 52)) return 7;
    if((lcd_x < 160 && lcd_x > 118) && (lcd_y < 104 && lcd_y > 52)) return 8;
    if((lcd_x < 104 && lcd_x > 63) && (lcd_y < 104 && lcd_y > 52)) return 9;
    
    if((lcd_x < 214 && lcd_x > 171) && (lcd_y < 172 && lcd_y > 120)) return 4;
    if((lcd_x < 160 && lcd_x > 118) && (lcd_y < 172 && lcd_y > 120)) return 5;
    if((lcd_x < 104 && lcd_x > 63) && (lcd_y < 172 && lcd_y > 120)) return 6;
    
    if((lcd_x < 214 && lcd_x > 171) && (lcd_y < 235 && lcd_y > 185)) return 1;
    if((lcd_x < 160 && lcd_x > 118) && (lcd_y < 235 && lcd_y > 185)) return 2;
    if((lcd_x < 104 && lcd_x > 63) && (lcd_y < 235 && lcd_y > 185)) return 3;
    
    if((lcd_x < 214 && lcd_x > 171) && (lcd_y < 298 && lcd_y > 253)) return 0;
    
    else return 10;
    
}

