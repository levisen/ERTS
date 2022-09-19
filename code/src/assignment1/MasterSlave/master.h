#pragma once
#include <systemc.h>
#include <iomanip>
#include "params.h"

SC_MODULE(Master) {
    sc_in_clk CLK;
    bool ready;
    bool valid;
    sc_int<DATA_BITS> data;
    sc_int<ERROR_BITS> error;
    sc_int<CHANNEL_BITS> channel;
    sc_port<sc_signal<sc_int<DATA_BITS>>,0> out_data;
    sc_port<sc_signal<bool>,0> out_valid;
    sc_port<sc_signal<sc_int<ERROR_BITS>>,0> out_error;
    sc_port<sc_signal<sc_int<CHANNEL_BITS>>,0> out_channel;
    sc_port<sc_signal<bool>,0> in_ready;

    void produce(){
        while (1)
        {
            ready = in_ready->read();
            if(ready && !valid) {
                valid = true;
                data++;
                this->write();
            } else if(ready && valid){
                valid = true;
                data++;        
                this->write();
            } else if(!ready){
                valid = false;
                this->write();
            } else {
                this->write();
            }
            wait();
        }
    }
    void write() {
        for (int i = 0; i < out_data.size(); i++)
        {
            out_data[i]->write(data);
            out_error[i]->write(error);
            out_channel[i]->write(channel);
            out_valid[i]->write(valid);
        }
    }

    SC_CTOR(Master) {
        SC_THREAD(produce);
        sensitive << CLK.pos();
    }
};
