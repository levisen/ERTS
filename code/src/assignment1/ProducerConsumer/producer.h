#ifndef PRODUCER_H
#define PRODUCER_H
#include <systemc.h>
#include <iomanip>
#include "TCPHeader.h"


SC_MODULE(Producer) {
    sc_port<sc_fifo_out_if<TCPHeader*>,0> out;
    sc_uint<32> package_number;
    TCPHeader* package;

    void produce(void);

    SC_CTOR(Producer) {
        SC_THREAD(produce);
    }
};
#endif
