#ifndef MAC_H
#define MAC_H
#include <systemc.h>
SC_MODULE(Mac) {
    sc_in<int> a;
    sc_in<int> b;
    sc_in<int> c;
    sc_out<int> f;

    sc_signal<int> p;

    void add(void);
    void multiply(void);

    SC_CTOR(Mac) {
        SC_METHOD(multiply);
        sensitive << a << b;
        SC_METHOD(add);
        sensitive << p << c;
    }
};
#endif
