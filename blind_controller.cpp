#include <blind_controller.h>

// Used for the definitions OUTPUT and INPUT
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif
// If debugging, use this, else nothing
// Remove these definitions to stop debug output
//#define DEBUG_STEP 1 
#define DEBUG 1
// end definitions
#ifdef DEBUG
 #define debug(x)   Serial.print (x)
 #define debugln(x) Serial.println (x)
#else
 #define debug(x)
 #define debugln(x)
#endif

//BlindController::BlindController(){}

bool BlindController::add_blind(uint8_t hb_1, uint8_t hb_2, uint8_t sensor){
    if(m_blind_ptr > m_blinds_max_size){
        return false;
    }
    Blind b(m_blind_ptr, hb_1, hb_2, sensor);
    m_blinds[m_blind_ptr++] = b;
    return true;
}

uint8_t BlindController::move_all_blinds(bool direction){
    uint8_t total = 0;
    
    for(int i = 0; i < m_blind_ptr; i++){
        total += move_blind(m_blinds[i].get_ID(), direction) ? 1 : 0;
    }

    return total;
}

bool BlindController::move_blind(uint8_t id, bool direction){
    for(int i = 0; i < m_blind_ptr; i++){
        if(m_blinds[i].get_ID() == id){
            return m_blinds[i].operate_motor(direction);
        }
    }
}

/* ~~~ Public functions ~~~ */

uint8_t BlindController::close_all_blinds(){
    return move_all_blinds(false);
}

uint8_t BlindController::open_all_blinds(){  
    return move_all_blinds(true);
}

bool BlindController::close_blind(uint8_t id){
    return move_blind(id, false);
}

bool BlindController::open_blind(uint8_t id){
    return move_blind(id, true);
}

bool BlindController::is_open(uint8_t id){
    for(int i = 0; i < m_blind_ptr; i++){
        if(m_blinds[i].get_ID() == id){
            return m_blinds[i].get_state() == 1;
        }
    }
    return 0;
}

/* ~~~ Blind definitions ~~~ */
/* --- Blind private functions --- */

uint8_t BlindController::Blind::get_state(){
    return 0;
}

bool BlindController::Blind::operate_motor(bool dir){
    return true;
}

bool BlindController::Blind::is_closed(){
    return true;
}

bool BlindController::Blind::is_open(){
    return true;
}

