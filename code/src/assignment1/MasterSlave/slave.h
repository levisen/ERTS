#pragma once
#include <systemc.h>
#include <iomanip>
#include "params.h"
using std::setw;

SC_MODULE(Slave) {
    sc_in_clk CLK;
    bool ready;
    bool valid;
    sc_int<ERROR_BITS> error;
    sc_int<CHANNEL_BITS> channel;
    sc_int<DATA_BITS> data;
    sc_port<sc_signal<sc_int<DATA_BITS>>,0> in_data;
    sc_port<sc_signal<bool>,0> in_valid;
    sc_port<sc_signal<sc_int<ERROR_BITS>>,0> in_error;
    sc_port<sc_signal<sc_int<CHANNEL_BITS>>,0> in_channel;
    sc_port<sc_signal<bool>,0> out_ready;
    ofstream MyFile;

    void consume(void){
        ofstream MyFile("data.txt");
        while(1){
            valid = in_valid->read();
            data = in_data->read();
            error = in_error->read();
            channel = in_channel->read();
            
            if (valid)
            {
                cout << in_data->read() << setw(8) << sc_time_stamp() << endl;
                MyFile << in_data->read() << endl;
            } 

            if ((rand()%2) == 1) //some random logic for when ready should be true
            {
                ready = true;
                for (int i = 0; i < out_ready.size(); i++)
                {
                    out_ready[i]->write(ready);
                }
            }
            else 
            {
                ready = false;
                for (int i = 0; i < out_ready.size(); i++)
                {
                    out_ready[i]->write(ready);
                }
            }
            wait();
	    }
    }

    SC_CTOR(Slave) {
        SC_THREAD(consume);
        sensitive << CLK.pos();
    }
    ~Slave(){
        cout << "Closed data.txt file" << endl;
        MyFile.close();
    }
};
