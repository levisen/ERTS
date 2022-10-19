#include "advios.h"


// based on inswitch and control
void advios::iosThread()
{
// Group ports into AXI4 slave slv0
	#pragma HLS resource core = AXI4LiteS metadata = "-bus_bundle slv0" variable = ctrl // What is this????

    // Initialization
    wait();

    // Process the data
    while (1)
    {
        // Wait for start
        wait();
        
        //printf("test %d\n",(uint32_t)sec_counter);
        switchs = inSwitch.read();
        control = ctrl.read();
        
        if (control == 0x0)
        {
            if (switchs == 0x8)
            {
                outLeds.write(0);
                sec_counter = 0;
            }
            else if (sec_pulse == true)
            {
                sec_counter++;
                outLeds.write(sec_counter);
            }
        }
        else
        { // ctrl 0x1-0f
            outLeds.write(control & switchs);
        }
    }
}

// Counter to increase the sec_counter. Whenever this reaches threshold set sec_pulse to true, reset and start over

void advios::countThread()
{
    wait();
    while (1)
    {
        wait();
        count++;
        
        //if (count >= 10)
        if (count >= 100000000)
        {
            sec_pulse = true;
            count = 0;
        }
        else
        {
            sec_pulse = false;
        }
    }
}
