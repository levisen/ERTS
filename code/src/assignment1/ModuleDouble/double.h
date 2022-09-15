#ifndef MAC_H
#define MAC_H
#include <systemc.h>
#include <iomanip>

SC_MODULE(ModuleDouble) {
    sc_event A, B, Aack, Back;
    bool alternating = false;
    void threadA(void);
    void threadB(void);
    void methodA(void);

    SC_CTOR(ModuleDouble) {
        SC_THREAD(threadA);
        sensitive << Aack;
        SC_THREAD(threadB);
        sensitive << Back;
        SC_METHOD(methodA);
        sensitive << A << B;
        dont_initialize();
    }
};
#endif
