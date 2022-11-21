#ifndef _IOS_DRIVER
#define _IOS_DRIVER

#include <systemc.h>

SC_MODULE(pendulum) {

	//constants
	double const ts = 0.1; 		// Times step [s]
	double const g = 9.81; 		// Acceleration due to gravity [m/s²]
	double const L = 1.0; 		// Length of pendulum arm [m]
	double const b = 0.5; 		// Damping factor [kg/s]
	double const m = 1.0; 		// Mass of bob [kg]

	//variables
	double theta_ddot = 0.0;	// Angular acceleartion [rad/s²]
	double theta_dot = 0.0;		// Angular velocity [rad/s]
	double theta = 0.0;			// Angular displacement [rad]

	/**
	 * Mathematical model:
	 * theta_ddot + (b/m) * theta_dot + (g/L) * sin(theta) = 0 
	 */
	void pendulum_eq()
	{
		
	}


	//Constructor
	SC_CTOR(pendulum) : retval(-1) {

		//Process Registration
		SC_CTHREAD(pendulum_eq, clk.pos());
		reset_signal_is(reset, true);
		//sensitive << clk.pos();
	}
};

#endif
