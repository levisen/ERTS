#ifndef MAC_H
#define MAC_H
#include <systemc.h>
#include <iomanip>

#define num_bits 4

SC_MODULE(advios)
{
    // Ports

    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_uint<num_bits>> ctrl;
    sc_in<sc_uint<num_bits>> inSwitch;
    sc_out<sc_uint<num_bits>> outLeds;

    // Variables
    sc_uint<num_bits> switchs;
    sc_uint<num_bits> control;
    sc_uint<28> count; // Max. 268 mill.
    sc_uint<num_bits> sec_counter;
    sc_signal<bool> sec_pulse;

    // Process Declaration
    void iosThread();
    void countThread();

    // Constructor
    SC_CTOR(advios)
    {
        // Thread to handle control of LEDs
        SC_CTHREAD(iosThread, clk.pos());
        reset_signal_is(reset, true);
        // Thread to generate second pulse

        SC_CTHREAD(countThread, clk.pos());
        reset_signal_is(reset, true);
    }
};
#endif
