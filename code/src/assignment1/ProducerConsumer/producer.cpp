#include "producer.h"
using std::setw;

void Producer::produce(void) {
	while(1){
		wait((rand()%(10-2 + 1) + 2), SC_MS);
		package = new TCPHeader();
		package_number++;
		package->DestinationPort = rand() % 2 + 1;
		package->SequenceNumber = package_number;
		for (int i = 0; i < out.size(); i++)
		{
			out[i]->write(package);
		}
	}
}
