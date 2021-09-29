#include <xc.h>
#include <inttypes.h>
#include "game.h"
#include "left_db.h"
#include "right_db.h"
#include <stdlib.h>


enum game_states { game_init, game_assign, game_shiftLeft, game_shiftRight, game_over } game_state;

uint8_t decodeNumber;
uint8_t leftWon;
uint8_t rightWon;
uint8_t counter = 1;
uint16_t speed = 400;
int r = 1;
int og = 10;





void game_init_func() {
    game_state = game_init;
}

uint16_t get_gameSpeed(){
    return speed;
}

uint8_t game_run()
{
  switch(game_state) {   // Transitions
     case game_init:  // Initial transition
         game_state = game_assign;
        break;

     case game_assign:
          if (r % 2) {
              decodeNumber = 0x01;
              if(!l_btn_pushed) {
                  game_state = game_shiftRight;
              }    
          }
         
          else  {
              decodeNumber = 0x08;
                      if(!r_btn_pushed) {
                          game_state = game_shiftLeft;
                      }
          }
        break;

     case game_shiftLeft:
       
         if(decodeNumber > 0x08) {
             leftWon = 0x01;
             game_state = game_over;
         }
         
         else if(decodeNumber < 0x01){
             rightWon = 0x01;
             game_state = game_over;
         }
         
         if(!l_btn_pushed) {
             game_state = game_shiftRight;
         }
        
        break;
        
     case game_shiftRight:
        
         if(decodeNumber > 0x08) {
             leftWon = 0x01;
             game_state = game_over;
         }
         
         else if(decodeNumber < 0x01){
             rightWon = 0x01;
             game_state = game_over;
         }
         
         if(!r_btn_pushed){
             game_state = game_shiftLeft;
         }
        break;
        
     case game_over:
        if(counter == 7) {
            counter = 1;
            game_state = game_init;
            speed = speed/(1.2);
        }
        break;
        

     default:
        game_state = game_init;
        break;
  } // Transitions

  switch(game_state) {   // State actions
     case game_init:
         rightWon = 0x00;
         leftWon = 0x00;
         break;
         
      case game_assign:
          break;
        
     case game_shiftLeft:
         decodeNumber = decodeNumber - 1;
         r = r + 1;
         break;
        
     case game_shiftRight:       
         decodeNumber = decodeNumber + 1;
         r = r + 1;
         break;
         
     case game_over: 
         
         if(counter % 2) {
         
         if(rightWon == 0x01) {
             decodeNumber = 0x08;
         }
         if(leftWon == 0x01) {
             decodeNumber = 0x01;
         }
         
         }
            
         else decodeNumber = 0x00;
         
         counter++;
         break;
         
         
     default:
        break;
   } // State actions
  
  return decodeNumber;
}
