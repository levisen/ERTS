#ifndef TOP_H
#define TOP_H
#include <systemc.h>
#include "producer.h"
#include "consumer.h"


SC_MODULE(Top) {

    Consumer *consumer1;
    Consumer *consumer2;
    Producer *producer;
    sc_fifo<TCPHeader*> channel1;
    sc_fifo<TCPHeader*> channel2;
    
    SC_CTOR(Top)
    {   
        consumer1 = new Consumer("consumer1");
        consumer2 = new Consumer("consumer2");
        producer = new Producer("producer");

        consumer1->in(channel1);
        consumer2->in(channel2);
        producer->out(channel1);
        producer->out(channel2);
    }
};
#endif
