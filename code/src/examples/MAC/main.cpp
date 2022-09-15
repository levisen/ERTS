#include "top.h"

int sc_main(int argc, char* argv[]) {
	Top top("MAC");
	sc_start(1000, SC_MS);
	return 0;
}
