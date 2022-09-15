#ifndef TOP_H
#define TOP_H
#include <systemc.h>
#include "master.h"
#include "slave.h"
#include "inAdapter.h"

SC_MODULE(Top) {

    Master master;
    Slave *slave;
    InAdapter<sc_int<DATA_BITS>> inadapter;
    sc_trace_file *tracefile;

    sc_signal<sc_logic> ready;
    sc_signal<sc_logic> valid;
    sc_signal<sc_int<DATA_BITS>> data;
    sc_signal<sc_int<ERROR_BITS>> error;
    sc_signal<sc_int<CHANNEL_BITS>> channel;
    sc_clock clock;
    sc_signal<sc_logic> reset;

    SC_CTOR(Top) : clock("clock", sc_time(1, SC_MS)), inadapter("inadapter"), master("master")
    {   
    reset.write(SC_LOGIC_0);

    slave = new Slave("slave");
    slave->valid(valid);
    slave->data(data);
    slave->error(error);
    slave->channel(channel);
    slave->ready(ready);
    slave->CLK(clock);
    slave->reset(reset);

    inadapter.valid(valid);
    inadapter.data(data);
    inadapter.error(error);
    inadapter.channel(channel);
    inadapter.ready(ready);
    inadapter.CLK(clock);
    inadapter.reset(reset);

    master.out(inadapter);


	// Create tacefile
	tracefile = sc_create_vcd_trace_file("AlgoWave");
	if (!tracefile) cout << "Could not create trace file." << endl;

	// Set resolution of trace file to be in 10 US
	tracefile->set_time_unit(1, SC_NS);
	sc_trace(tracefile, clock, "clock");
	sc_trace(tracefile, ready, "ready");
	sc_trace(tracefile, valid, "valid");
	sc_trace(tracefile, data, "data");
	sc_trace(tracefile, error, "error");
	sc_trace(tracefile, channel, "channel");
    sc_trace(tracefile, reset, "reset");
    }

    ~Top()
    {
    sc_close_vcd_trace_file(tracefile);

    delete slave;

	cout << "Created AlgoWave.vcd" << endl;
    }
};
#endif
