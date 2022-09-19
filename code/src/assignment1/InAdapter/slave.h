#pragma once
#include <systemc.h>
#include <iomanip>
#include "params.h"
using std::setw;
SC_MODULE(Slave) 
{
  public:
    sc_in_clk CLK;
    sc_in<sc_logic> reset; // Reset
    sc_out<sc_logic> ready; // Ready signal
    sc_in<sc_logic> valid; // Valid signal
    sc_in<sc_int<CHANNEL_BITS>> channel;
    sc_in<sc_int<ERROR_BITS>> error;
    sc_in<sc_int<DATA_BITS>> data;
    ofstream MyFile;

    void consume(void){
        ofstream MyFile("data.txt");
        while(1){
            valid.read();
            auto msg = data.read();
            error.read();
            channel.read();
            
            if (valid == SC_LOGIC_1)
            {
                cout << msg << setw(8) << sc_time_stamp() << endl;
                MyFile << msg << endl;
            } 

            if ((rand()%2) == 1) //some random logic for when ready should be true
            {
                ready.write(SC_LOGIC_1);
            }
            else 
            {
                ready.write(SC_LOGIC_0);
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
