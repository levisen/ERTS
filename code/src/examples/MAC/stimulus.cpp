#include "stimulus.h"

void Stimulus::generate() {
	wait();
	a = 100; b = 100; c = 100;
	wait();
	a = 200; b = 100; c = -100;
	wait();
	a = 100; b = -300; c = 100;
	wait();
	sc_stop();
}