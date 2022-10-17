#include <systemc.h>
#include <stdio.h>
#include "advios_driver.h"

#ifdef __RTL_SIMULATION__
	#include "iosc_rtl_wrapper.h"
	#define iosc iosc_rtl_wrapper
#else
	#include "advios.h"
#endif


int sc_main (int argc , char *argv[])
{
	// sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", SC_DO_NOTHING);
	// sc_report_handler::set_actions( SC_ID_LOGIC_X_TO_BOOL_, SC_LOG);
	// sc_report_handler::set_actions( SC_ID_VECTOR_CONTAINS_LOGIC_VALUE_, SC_LOG);
	// sc_report_handler::set_actions( SC_ID_OBJECT_EXISTS_, SC_LOG);

	sc_trace_file *tracefile;

	sc_signal<bool> s_reset;
	sc_signal<sc_uint<num_bits>> s_switch;
	sc_signal<sc_uint<num_bits>> s_ctrl;
	sc_signal<sc_uint<num_bits>> s_leds;
	sc_signal<bool> s_sec_pulse;

	// Create a 10ns period clock signal
	sc_clock s_clk("s_clk", 10, SC_NS);
	advios U_AdvIOs("U_iosc");
	advios_driver tb_driver("tb_driver");

	// Create tacefile
	tracefile = sc_create_vcd_trace_file("IOSC_Wave");
	if (!tracefile) cout << "Could not create trace file." << endl;

	// Set resolution of trace file to be in 10 US
	tracefile->set_time_unit(1, SC_NS);

	sc_trace(tracefile, s_clk,    "clock");

	sc_trace(tracefile, s_reset,  "reset");

	sc_trace(tracefile, s_ctrl,   "ctrl");
	sc_trace(tracefile, s_leds,   "leds");

	sc_trace(tracefile, s_switch, "switch");

	sc_trace(tracefile, U_AdvIOs.sec_pulse, "sec_pulse");
	sc_trace(tracefile, U_AdvIOs.sec_counter, "sec_counter");
	sc_trace(tracefile, U_AdvIOs.count, "count");


	// Connect the DUT
	U_AdvIOs.clk(s_clk);
	U_AdvIOs.reset(s_reset);

	U_AdvIOs.ctrl(s_ctrl);
	U_AdvIOs.outLeds(s_leds);
	U_AdvIOs.inSwitch(s_switch);

	tb_driver.clk(s_clk);
	tb_driver.reset(s_reset);
	tb_driver.inLeds(s_leds);
	tb_driver.outSwitch(s_switch);
	tb_driver.ctrl(s_ctrl);


	// Sim for 200
	int end_time = 300;
	std::cout << "INFO: Simulating" << std::endl;
	// start simulation
	sc_start(end_time, SC_NS);

	if (tb_driver.retval == 0) {
		printf("Test passed !\n");
	} else {
		printf("Test failed !!!\n");
	}

	sc_close_vcd_trace_file(tracefile);
	std::cout << "Created IOSC_Wave.vcd" << std::endl;

	return 0;
};
