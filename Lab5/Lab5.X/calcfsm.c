
#include "ts_lcd.h"
#include <xc.h>
#include <plib.h>
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "ts_lcd.h"


enum calc_states { calc_init, calc_notPressed, calc_first, calc_second, calc_result, calc_continueCalc, calc_intermSum, calc_waitClear, calc_waitNoPress } calc_state;

uint64_t numSum1;
uint32_t numSum1Checker;
uint64_t numSum2;
uint64_t sumChecker;
uint32_t totalSum;
uint8_t equals;
uint8_t secondState;
uint8_t operator1;
uint8_t operator2;
uint8_t calcPressed;
uint8_t clearFlag;
uint8_t error;
uint8_t displaySum1;
uint8_t displaySum2;
uint8_t displayResult;
uint8_t displayZero;

void clear(){
    numSum1 = 0;
    numSum2 = 0;
    sumChecker = 0;
    equals = 0;
    secondState = 0;
    operator1 = 0;
    operator2 = 0;
    totalSum = 0;
    error = 0;
    displaySum1 = 0;
    displaySum2 = 0;
    displayResult = 0;    
    displayZero = 0;
}

uint32_t getNumSum1(){
    return numSum1;
}

uint32_t getNumSum2(){
    return numSum2;
}

uint32_t getTotalSum(){
    return totalSum;
}

uint8_t getDisplaySum1(){
    return displaySum1;
}

uint8_t getDisplaySum2(){
    return displaySum2;
}

uint8_t getDisplayResult(){
    return displayResult;
}

uint8_t getDisplayZero(){
    return displayZero;
}

void calc_init_func() {
    calc_state = calc_init;
}

void calc_run(uint8_t clickedDown, uint8_t funcNumberClicked, uint16_t lcd_x, uint16_t lcd_y)
{
  switch(calc_state) {   // Transitions
     case calc_init:          
          calc_state = calc_notPressed;
          displaySum1 = 1;
          break;
        
      case calc_notPressed: 
          if(clickedDown && !secondState) {
              calc_state = calc_first;
          }
          else if (clickedDown && secondState) calc_state = calc_second;
          else calc_state = calc_notPressed;
          break;

     case calc_first:
         
         if((lcd_x < 156 && lcd_x > 115) && (lcd_y < 300 && lcd_y > 255)) {
             clear();
             calc_state = calc_init;
         }
                 
         if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 104 && lcd_y > 52)) {
             operator1 = operator2 = 1;
             secondState = 1;
             displaySum1 = 0;
             calc_state = calc_second;
         }
         else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 175 && lcd_y > 125)) {
             operator1 = operator2 = 2;
             secondState = 1;
             displaySum1 = 0;
             calc_state = calc_second;
         }
         else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 240 && lcd_y > 195)) {
             operator1 = operator2 = 3;
             secondState = 1;
             displaySum1 = 0;
             calc_state = calc_second;
         }
         else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 300 && lcd_y > 255)) {
             operator1 = operator2 = 4;
             secondState = 1;
             displaySum1 = 0;
             calc_state = calc_second;
         }
       
         
         else{
             if(numSum1 < 42949672){
             displaySum1 = 1;
             if(!(funcNumberClicked == 10)) {
             numSum1 = (numSum1 * 10) + funcNumberClicked;
             calc_state = calc_waitNoPress;
             }
             }
             else {
                 error = 1;
                 calc_state = calc_waitClear; 
             }
         }
         
        break;

     case calc_second:
          if((lcd_x < 156 && lcd_x > 115) && (lcd_y < 300 && lcd_y > 255)) {
             clear();
             calc_state = calc_init;
          }
          
          if((lcd_x < 104 && lcd_x > 61) && (lcd_y < 300 && lcd_y > 255)) {
              displaySum2 = 0;
              displaySum1 = 0;            
              calc_state = calc_result;
          }
          
          else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 104 && lcd_y > 52)) {
             operator2 = 1;             
             displaySum2 = 0;
             calc_state = calc_intermSum;
         }
          else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 175 && lcd_y > 125)) {
             operator2 = 2;           
             displaySum2 = 0;
             calc_state = calc_intermSum;
         }
          else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 240 && lcd_y > 195)) {
             operator2 = 3;
             displaySum2 = 0;
             calc_state = calc_intermSum;
         }
          else if((lcd_x < 50 && lcd_x > 10) && (lcd_y < 300 && lcd_y > 255)) {
             operator2 = 4;
             displaySum2 = 0;
             calc_state = calc_intermSum;
         }
          
          else{
              displaySum2 = 1;
              
          if(numSum1 < 42949672){   
          if(!(funcNumberClicked == 10)) {
             numSum2 = (numSum2 * 10) + funcNumberClicked;
             }
             
             calc_state = calc_waitNoPress;
          }
          else{
              error = 1;
              calc_state = calc_waitClear;
          }
          }
        break;
        
     case calc_result:
         if(operator2 == 1){   
             sumChecker = numSum1 + numSum2;
             if(sumChecker < 4294967296) {
              
                 totalSum = numSum1 + numSum2;
                 displayResult = 1;       
             }
             else error = 1;
         }
         
         if(operator2 == 2){
             sumChecker = numSum1 - numSum2;
             if(sumChecker < 4294967296) {
                 totalSum = numSum1 - numSum2;
                 displayResult = 1;
                 
             }
             else error = 1;
             
         }
         if(operator2 == 3){
             sumChecker = numSum1 * numSum2;
             if(sumChecker < 4294967296) {
                 totalSum = numSum1 * numSum2;
                 displayResult = 1;
                
             }
             else error = 1;       
         }
         
         if(operator2 == 4){
             if(numSum2 == 0){
                 error = 1;
             }
             
             else if((numSum1 / numSum2) > 4294967296) error = 1;
         else {
             totalSum = numSum1 / numSum2;
             displayResult = 1;            
         }
         }
         calc_state = calc_waitClear;
        break;
        
      case calc_intermSum:
       
          if((lcd_x < 156 && lcd_x > 115) && (lcd_y < 300 && lcd_y > 255)) {
             clear();
             calc_state = calc_init;
          }                 
          
          if(operator1 == 1){   
             sumChecker = numSum1 + numSum2;
             if(sumChecker < 4294967296) {             
                 totalSum = numSum1 + numSum2;
                 numSum1 = totalSum;
             }
             else error = 1;
         }
         if(operator1 == 2){
             sumChecker = numSum1 - numSum2;
             if(sumChecker < 4294967296) {
                 totalSum = numSum1 - numSum2;                
                 numSum1 = totalSum;
             }
             else error = 1;
             
         }
         if(operator1 == 3){
             sumChecker = numSum1 * numSum2;
             if(sumChecker < 4294967296) {
                 totalSum = numSum1 * numSum2;                 
                 numSum1 = totalSum;
             }
             else error = 1;
         }
         if(operator1 == 4){
             if(numSum2 == 0){
                 error = 1;
             }
             
             else if((numSum1 / numSum2) > 4294967296) error = 1;
         else {
             totalSum = numSum1 / numSum2;
             numSum1 = totalSum;
                                                  
         }
         }
         operator1 = 0;
         displaySum1 = 1; 
         
          if(!(funcNumberClicked == 10)) {
             numSum2 = 0;
             calc_state = calc_second;
             }
                           
        break;
          
      
        case calc_waitClear:
         if(error){
            displayZero = 1;    
         }
         
         if((lcd_x < 156 && lcd_x > 115) && (lcd_y < 300 && lcd_y > 255)) {
             clear();
             calc_state = calc_init;
         }
         else calc_state = calc_waitClear;
        break;
        
     case calc_waitNoPress:
         if(clickedDown){
             calc_state = calc_waitNoPress;
         }
         else calc_state = calc_notPressed;
        break;
        

     default:
         calc_state = calc_init;
         break;
  } // Transitions

}