
#include <xc.h>
#include <inttypes.h>
#include "right_db.h"

enum db_states { db_init, db_noPush, db_maybePush, db_pushed, db_maybeNoPush } db_state_r;

uint8_t r_btn_pushed;

void rightdb_init_func() {
    db_state_r = db_init;
}

uint8_t right_db_check(uint8_t data)
{
  switch(db_state_r) {   // Transitions
     case db_init:  // Initial transition
        db_state_r = db_noPush;
        break;

     case db_noPush:
        if (data == 0x00 || data == 0x01) {
           db_state_r = db_maybePush;
        }
        else if (data == 0x02 || data == 0x03) {
           db_state_r = db_noPush;
        }
        break;

     case db_maybePush:
        if (data == 0x00 || data == 0x01) {
           db_state_r = db_pushed;
        }
        else if (data == 0x02 || data == 0x03) {
           db_state_r = db_noPush;
        }
        break;
        
     case db_pushed:
        if (data == 0x00 || data == 0x01) {
           db_state_r = db_pushed;
        }
        else if (data == 0x02 || data == 0x03) {
           db_state_r = db_maybeNoPush;
        }
        break;
        
     case db_maybeNoPush:
        if (data == 0x00 || data == 0x01) {
           db_state_r = db_pushed;
        }
        else if (data == 0x02 || data == 0x03) {
           db_state_r = db_noPush;
        }
        break;
        

     default:
        db_state_r = db_init;
        break;
  } // Transitions

  switch(db_state_r) {   // State actions
     
     case db_noPush:
        r_btn_pushed = 0x03;
        break;
        
     case db_maybePush:
        r_btn_pushed = 0x03;
        break;
        
     case db_maybeNoPush:
        r_btn_pushed = 0x03;
        break;
      
     case db_pushed:
        r_btn_pushed = 0x00;
        break;

     default:
        break;
   } // State actions
  
  return r_btn_pushed;
}

