#include "ios.h"

void iosc::iosThread() {
	//Group ports into AXI4 slave slv0
	#pragma HLS resource core=AXI4LiteS metadata="-bus_bundle slv0" variable=ctrl

	//Initialization
	wait();

	// Process the data
	while(true) {
		// Wait for start
		wait();

		switchs = inSwitch.read() & ctrl.read();

		outLeds.write(switchs);

	}
}
