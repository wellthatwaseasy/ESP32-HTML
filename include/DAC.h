#ifndef _DAC_DEF
#define _DAC_DEF

#include <driver/dac.h>

struct DAC{
    uint8_t io;
    int amplitude;
    String type="DAC";
    
    void update(){
        dac_output_voltage(io == 25 ? DAC_CHANNEL_1: DAC_CHANNEL_2, amplitude);
    }
    int read(){
        return amplitude;
    }
    void init(){
    dac_output_enable(io == 25 ? DAC_CHANNEL_1: DAC_CHANNEL_2);
    dac_output_voltage(io == 25 ? DAC_CHANNEL_1: DAC_CHANNEL_2, amplitude);
    }
};

#endif