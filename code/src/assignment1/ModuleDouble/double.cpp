#include "double.h"
using std::setw;

void ModuleDouble::threadA(void) {
	while(1){
		//wait(3, SC_MS);
		A.notify(3, SC_MS);
		wait(sc_time(3, SC_MS), Aack);
	}
}

void ModuleDouble::threadB(void) {
	while(1){
		//wait(2, SC_MS);
		B.notify(2, SC_MS);
		wait(sc_time(2, SC_MS), Back);
	}
}

void ModuleDouble::methodA(void) {
	if(alternating){
		Aack.notify();
		cout << "Notified Aack at time: " << setw(8) << sc_time_stamp() << endl;
		next_trigger(B);
		alternating = false;
	} else {
		Back.notify();
		cout << "Notified Back at time: " << setw(8) << sc_time_stamp() << endl;
		next_trigger(A);
		alternating = true;
	}
}