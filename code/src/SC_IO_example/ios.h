#ifndef _IOS_
#define _IOS_

#include <systemc.h>

SC_MODULE(iosc) {

	//Ports
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in<sc_uint<8> > ctrl;
	sc_in<sc_uint<8> > inSwitch;
	sc_out<sc_uint<8> > outLeds;

	//Variables
	sc_uint<8> switchs;

	//Process Declaration
	void iosThread();

	//Constructor
	SC_CTOR(iosc) {
		//Process Registration
		SC_CTHREAD(iosThread, clk.pos());
		reset_signal_is(reset,true);
	}
};

#endif
