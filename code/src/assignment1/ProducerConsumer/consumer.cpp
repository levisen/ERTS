#include "consumer.h"
using std::setw;

void Consumer::consume(void) {
	while(1){
		cout << name() << setw(8) << in.read()->SequenceNumber << setw(8) << sc_time_stamp() << endl;
	}
}
