
#include <xc.h>
#include <inttypes.h>
#include "left_db.h"

enum db_states { db_init, db_noPush, db_maybePush, db_pushed, db_maybeNoPush } db_state_l;

uint8_t l_btn_pushed;

void leftdb_init_func() {
    db_state_l = db_init;
}

uint8_t left_db_check(uint8_t data)
{
  switch(db_state_l) {   // Transitions
     case db_init:  // Initial transition
        db_state_l = db_noPush;
        break;

     case db_noPush:
        if (data == 0x00 || data == 0x02) {
           db_state_l = db_maybePush;
        }
        else if (data == 0x01 || data == 0x03) {
           db_state_l = db_noPush;
        }
        break;

     case db_maybePush:
        if (data == 0x00 || data == 0x02) {
           db_state_l = db_pushed;
        }
        else if (data == 0x01 || data == 0x03) {
           db_state_l = db_noPush;
        }
        break;
        
     case db_pushed:
        if (data == 0x00 || data == 0x02) {
           db_state_l = db_pushed;
        }
        else if (data == 0x01 || data == 0x03) {
           db_state_l = db_maybeNoPush;
        }
        break;
        
     case db_maybeNoPush:
        if (data == 0x00 || data == 0x02) {
           db_state_l = db_pushed;
        }
        else if (data == 0x01 || data == 0x03) {
           db_state_l = db_noPush;
        }
        break;
        

     default:
        db_state_l = db_init;
        break;
  } // Transitions

  switch(db_state_l) {   // State actions
    
      case db_noPush:
          l_btn_pushed = 0x03;
          break;
          
           case db_maybePush:
          l_btn_pushed = 0x03;
          break;
          
           case db_maybeNoPush:
          l_btn_pushed = 0x03;
          break; 
      
      case db_pushed:
         l_btn_pushed = 0x00;
        break;

     default:
        break;
   } // State actions
  
  return l_btn_pushed;
}

