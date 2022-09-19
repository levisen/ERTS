#include "consumer.h"
using std::setw;

void Consumer::consume(void) {
	while(1){
		auto msg = in.read();
		cout << name() << setw(8) << msg->SequenceNumber << setw(8) << sc_time_stamp() << setw(8) << msg->DestinationPort << endl;
	}
}
