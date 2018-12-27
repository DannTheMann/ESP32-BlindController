#ifndef BLIND_CONTROLLER
#define BLIND_CONTROLLER 1

class BlindController{    

    private:

        bool move_blind(bool direction);
        uint8_t move_all_blinds(bool direction);

        class Blind{

            public:

                Blind(uint8_t id, uint8_t hb_1, uint8_t hb_2, uint8_t hall_top, uint8_t hall_bottom){
                    m_id = id;
                    m_hbridge_input_1 = hb1;
                    m_hbridge_input_2 = hb2;
                    m_hall_top = hall_top;
                    m_hall_bottom = hall_bottom;
                }
                
                uint8_t get_ID(){return m_id;}
                uint8_t get_state();
                bool operate_motor(bool direction);
                bool is_closed();
                bool is_open();

            private:

                void check_sensors();

                bool m_moving;
                uint8_t m_id;
                /* pins for driver and sensors */
                uint8_t m_hbridge_input_1;
                uint8_t m_hbridge_input_2;
                uint8_t m_hall_top;
                uint8_t m_hall_bottom;

        };
    
        Blind*  m_blinds;
        uint8_t m_blind_size;

    public: 

        uint8_t add_blind(uint8_t hb_1, uint8_t hb_2, uint8_t hall_top, uint8_t hall_bottom);
        uint8_t close_all_blinds();
        uint8_t open_all_blinds();
        bool close_blind(uint8_t id);
        bool open_blind(uint8_t id);
        bool is_open(uint8_t id);

};

#endif