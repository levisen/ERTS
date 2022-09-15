#ifndef SIMPLE_PROCESS_EX_H
#define SIMPLE_PROCESS_EX_H
#include <systemc.h>
SC_MODULE(simple_process_ex) {
  int counter = 0;

  SC_CTOR(simple_process_ex) {
    SC_THREAD(my_thread_process);
  }

  void my_thread_process(void);

};

SC_MODULE(write_process) {
  sc_fifo_out<int> outP1;
  int counter = 0;

  SC_CTOR(write_process) {
    SC_THREAD(P1_CB);
  }

  void P1_CB(void);
};

SC_MODULE(read_process) {
  sc_fifo_in<int> inP2;

  SC_CTOR(read_process) {
    SC_THREAD(P2_CB);
  }

  void P2_CB(void);
};

#endif


