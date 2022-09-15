#ifndef CONSUMER_H
#define CONSUMER_H
#include <systemc.h>
#include "TCPHeader.h"
#include <iomanip>

SC_MODULE(Consumer) {
    sc_fifo_in<TCPHeader*> in;

    void consume(void);

    SC_CTOR(Consumer) {
        SC_THREAD(consume);
    }
};
#endif
