
#include "simple_process_ex.h"
int sc_main(int argc, char* argv[]) {
  simple_process_ex my_instance("my_instance");

  write_process process1("writer");
  read_process process2("reader");
  sc_fifo<int> Channel1("C1");

  process1.outP1(Channel1);
  process2.inP2(Channel1);

  sc_start(1000, SC_MS);
  return 0;
}
