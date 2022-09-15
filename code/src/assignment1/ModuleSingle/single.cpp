#include "single.h"
using std::setw;

void ModuleSingle::thread(void) {
	while(1){
		wait(2, SC_MS);
		e.notify();
	}
}

void ModuleSingle::method(void) {
	ctr++;
	cout << ctr << setw(8) << sc_time_stamp() << endl;
}