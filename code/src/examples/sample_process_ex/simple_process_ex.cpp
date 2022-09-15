
#include "simple_process_ex.h"
#include <iostream>
void simple_process_ex::my_thread_process(void) {
  std::cout << "my_thread_process executed within "
            << name() 
            << std::endl;
}


void write_process::P1_CB(void) {
  while(1) {
    outP1.write(counter);
    counter++;
    wait(10,SC_MS);
  }
}

void read_process::P2_CB(void) {
  while(1) {
    std::cout << inP2.read() << std::endl;
  }
}