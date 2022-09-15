#ifndef TOP_H
#define TOP_H
#include <systemc.h>
#include "master.h"
#include "slave.h"


SC_MODULE(Top) {

    Master *master;
    Slave *slave;
    sc_trace_file *tracefile;

    sc_signal<bool> ready;
    sc_signal<bool> valid;
    sc_signal<sc_int<DATA_BITS>> data;
    sc_signal<sc_int<ERROR_BITS>> error;
    sc_signal<sc_int<CHANNEL_BITS>> channel;
    sc_clock clock;
    //InAdapter Adapter;
    
    SC_CTOR(Top) : clock("clock", sc_time(1, SC_MS)) //, Adapter("Name")
    {   

    slave = new Slave("slave");
    master = new Master("master");

    slave->in_valid(valid);
    slave->in_data(data);
    slave->in_error(error);
    slave->in_channel(channel);
    slave->out_ready(ready);
    slave->CLK(clock);

    master->out_valid(valid);
    master->out_data(data);
    master->out_error(error);
    master->out_channel(channel);
    master->in_ready(ready);
    master->CLK(clock);

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
    }

    ~Top()
    {
    sc_close_vcd_trace_file(tracefile);

	cout << "Created AlgoWave.vcd" << endl;

    delete slave;
    delete master;
    }
};
#endif
