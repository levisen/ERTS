#ifndef MONITOR_H
#define MONITOR_H
#include <systemc.h>
SC_MODULE(Monitor) {
    sc_in<int> f;

    sc_in<bool> clk;

    void monitor() {
        while (1) {
            std::cout << f << std::endl;
            wait();
        }
    }

    SC_CTOR(Monitor) {
        SC_THREAD(monitor);
        sensitive << clk.neg();
    }
};
#endif
