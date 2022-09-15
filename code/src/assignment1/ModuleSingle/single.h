#ifndef MAC_H
#define MAC_H
#include <systemc.h>
#include <iomanip>

SC_MODULE(ModuleSingle) {
    sc_event e;
    sc_uint<4> ctr;

    void thread(void);
    void method(void);

    SC_CTOR(ModuleSingle) {
        SC_THREAD(thread);
        SC_METHOD(method);
        sensitive << e;
    }
};
#endif
