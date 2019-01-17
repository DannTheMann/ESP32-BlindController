#ifndef BLIND_CONTROLLER
#define BLIND_CONTROLLER 1

// Library used for correct bit memory allocations on specific machines
#include <stdint.h>

#define DEFAULT_MAX_BLINDS 10

class BlindController{    

    public: 

        BlindController(){};
        bool add_blind(uint8_t hb_1, uint8_t hb_2, uint8_t sensor);
        uint8_t close_all_blinds();
        uint8_t open_all_blinds();
        bool close_blind(uint8_t id);
        bool open_blind(uint8_t id);
        bool is_open(uint8_t id);

    private:

        bool move_blind(uint8_t id, bool direction);
        uint8_t move_all_blinds(bool direction);

        class Blind{

            public:

                Blind();
                Blind(uint8_t id, uint8_t hb_1, uint8_t hb_2, uint8_t sensor){
                    m_id = id;
                    m_hbridge_input_1 = hb_1;
                    m_hbridge_input_2 = hb_2;
                    m_sensor = sensor;
                };
                
                uint8_t get_ID(){return m_id;}
                uint8_t get_state();
                bool operate_motor(bool direction);
                bool is_closed();
                bool is_open();

            private:

                void check_sensors(){}

                bool m_moving;
                uint8_t m_id;
                /* pins for driver and sensors */
                uint8_t m_hbridge_input_1;
                uint8_t m_hbridge_input_2;
                uint8_t m_sensor;

        };
    
        Blind  m_blinds[DEFAULT_MAX_BLINDS];
        uint8_t m_blind_ptr;
        uint8_t m_blinds_max_size = DEFAULT_MAX_BLINDS;

};

#endif