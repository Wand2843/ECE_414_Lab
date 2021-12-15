
#include "motorFSM.h"
#include <xc.h>
#include "plib.h"



enum motor_states { motor_init, motor_notPressed, motor_waitNoPress } motor_state;

uint8_t motor1Forward;
uint8_t motor1Backward;
uint8_t motor2Forward;
uint8_t motor2Backward;


uint8_t getMotor1Forward(){
    return motor1Forward;
}

uint8_t getMotor2Forward(){
    return motor2Forward;
}

uint8_t getMotor1Backward(){
    return motor1Backward;
}

uint8_t getMotor2Backward(){
    return motor2Backward;
}


void motorFSM_init(){
    motor_state = motor_init;
}

void motor_run(uint8_t clickedDown, uint16_t lcd_x, uint16_t lcd_y)
{
  switch(motor_state) {   // Transitions
     case motor_init:          
          motor1Forward = 0;
          motor1Backward = 0;
          motor2Backward = 0;
          motor2Forward = 0;
          
          motor_state = motor_notPressed;
          break;
        
      case motor_notPressed: 
          if(clickedDown) {
              motor_state = motor_waitNoPress;
          }
          
          else motor_state = motor_notPressed;
          break;

     case motor_waitNoPress:
         
         if((lcd_x > 155 && lcd_x < 195) && (lcd_y > 130 && lcd_y < 190)) {
             enable_1();
             motor1Forward = 1;
         }
         
         if((lcd_x > 45 && lcd_x < 90) && (lcd_y > 130 && lcd_y < 190)){
             enable_1();
             motor1Backward = 1;
         }
         
         if((lcd_x > 95 && lcd_x < 140) && (lcd_y > 70 && lcd_y < 120)){
             enable_2();
             motor2Forward = 1;
         }
         
         if((lcd_x > 95 && lcd_x < 140) && (lcd_y > 190 && lcd_y < 240)){
             enable_2();
             motor2Backward = 1;
         }
         
         if(clickedDown){
             motor_state = motor_waitNoPress;
         }
         else {
             disable_1();
             disable_2();
             motor2Forward = 0;
             motor1Forward = 0;
             motor1Backward = 0;
             motor2Backward = 0;
             motor_state = motor_notPressed;
         }
        break;
        

     default:
         motor_state = motor_init;
         break;
  } // Transitions

}
