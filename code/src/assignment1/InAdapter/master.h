#pragma once
#include <systemc.h>
#include <iomanip>
#include "params.h"

SC_MODULE(Master) {
    sc_fifo_out<sc_int<DATA_BITS>> out;
    sc_int<DATA_BITS> data;

    void produce(void){
        while (1){
            data++;
            out.write(data);
        }
    }

    SC_CTOR(Master) {
        SC_THREAD(produce);
    }
};

