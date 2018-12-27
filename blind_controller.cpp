#include <blind_controller.h>

BlindController::BlindController(){
    // default constructor
}

uint8_t BlindController::add_blind(uint8_t hb_1, uint8_t hb_2, uint8_t hall_top, uint8_t hall_bottom){
    Blind b(m_blind_size, hb1, hb2, hall_top, hall_bottom);
    (m_blinds+m_blind_size++) = *b;
}

uint8_t BlindController::move_all_blinds(bool direction){
    uint8_t total = 0;
    
    for(Blind* ptr = m_blinds; ptr < m_blinds+m_blind_size; ptr++ ){
        total += move_blind(direction) ? 1 : 0;
    }

    return total;
}

bool BlindController::move_blind(bool direction){
    for(Blind* ptr = m_blinds; ptr < m_blinds+m_blind_size; ptr++ ){
        if(ptr->get_ID() == id){
            return ptr->operate_motor(direction);
        }
    }
}

/* ~~~ Public functions ~~~ */

uint8_t BlindController::close_all_blinds(){
    move_all_blinds(false);
}

uint8_t BlindController::open_all_blinds(){  
    move_all_blinds(true);
}

bool BlindController::close_blind(uint8_t id){
    move_blind(false);
}

bool BlindController::open_blind(uint8_t id){
    move_blind(true);
}

bool BlindController::is_open(uint8_t id){
    for(Blind* ptr = m_blinds; ptr < m_blinds+m_blind_size; ptr++ ){
        if(ptr->get_ID() == id){
            return ptr->get_state() == 1;
        }
    }
}

/* ~~~ Blind definitions ~~~ */
/* --- Blind private functions --- */

BlindController::Blind::Blind(){

}

uint8_t BlindController::Blind::get_state(){

}

BlindController::Blind::operate_motor(bool dir){

}

BlindController::Blind::is_closed(){

}

BlindController::Blind::is_open(){

}

